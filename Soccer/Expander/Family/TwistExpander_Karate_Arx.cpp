#include "TwistExpander_Karate_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Karate_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9AD1BC2BED25A33FULL + 0xD2179C64460EE831ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x83F76D65851831BDULL + 0xDAB3E61234371829ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB73942EBDA7C2F19ULL + 0xEA241DBD3E4E39A2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x841C89C9761A33BBULL + 0xFBEA2F7E982D5C5CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA3DBCC68F2C06CB3ULL + 0xE444C0C9A6082CC3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x867346073E80DB53ULL + 0xA8F6C88EA5762514ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD4F9E5B8FB7A8EB7ULL + 0x8B39752BE1B173F7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCF4A34B394988D8DULL + 0xD48FABE73EDFD342ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x92988B9E0E1EF5CFULL + 0xD0C580A06FDFB632ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDEBC0677CD4287E3ULL + 0xA22FEA9B531E143FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8B2749A302E39205ULL + 0xCC5CB8B0C015100DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9CF71928C5D30B5BULL + 0xD96AD0C5980DCCDDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDD67F424E7BC820BULL + 0xCFC0DC4A5313487EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC65FC535991CF501ULL + 0xCBDADACA8512CC4DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF45244549FF203A9ULL + 0x88CB000848067C28ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9F95552A8932EE5BULL + 0x81293E9D8BE0C269ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3599U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2730U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2968U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((aIndex + 4829U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 19U)) + 11698283336767769359U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 22U)) + 13297826354831483872U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 51U)) + 15254999058287530795U) + aNonceWordJ;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 17474166585085346567U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 57U)) + 15684783498452840289U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 43U)) + 5061229733465216486U;
            aOrbiterH = ((((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 15370981279168377944U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 17966672773619554092U;
            aOrbiterB = (aWandererA + RotL64(aCross, 5U)) + 14685092893994491068U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 12798804186209406389U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 2848444181474221574U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8551142075919636146U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8833198159158950723U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7650289040764974737U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7351473160893666232U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14204899612487622222U;
            aOrbiterJ = RotL64((aOrbiterJ * 6317485031956448029U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7008985178526543258U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13576796403863120356U;
            aOrbiterF = RotL64((aOrbiterF * 13745839827679114077U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5769784656937900699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14075925808204936705U;
            aOrbiterE = RotL64((aOrbiterE * 5844894088757604713U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17818667502858010896U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16016922065572683130U;
            aOrbiterA = RotL64((aOrbiterA * 7525645833898085373U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1582458237855075977U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10830440354527138227U;
            aOrbiterH = RotL64((aOrbiterH * 10499386926982228251U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10653964151654643772U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11218475491129483859U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 3338108067044357141U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9863649760189649255U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13790281439048354358U;
            aOrbiterC = RotL64((aOrbiterC * 4682098083538482849U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14846954923718136337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 522207783972623813U;
            aOrbiterD = RotL64((aOrbiterD * 14299798934454852811U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 426829715716262697U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7482977730216354509U;
            aOrbiterB = RotL64((aOrbiterB * 6317437989422015173U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10736099808538972990U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11698283336767769359U;
            aOrbiterK = RotL64((aOrbiterK * 17230175904095995929U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 14U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 48U)) + aOrbiterA) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6924U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6726U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6114U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 5697U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 37U)) + 4980738603982643969U;
            aOrbiterA = (aWandererI + RotL64(aCross, 51U)) + 17660278413018470020U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 3U)) + 17598114429859543466U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 40U)) + RotL64(aCarry, 37U)) + 10993929335279994739U) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 35U)) + 17967203122976322481U) + aNonceWordN;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 1872290205549034384U) + aNonceWordH;
            aOrbiterE = (aWandererF + RotL64(aScatter, 13U)) + 16607778671782810797U;
            aOrbiterD = ((((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 4895226930754394376U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 19U)) + 14960359005982301383U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 5U)) + 9921642352377700630U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 46U)) + 893281964367208693U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8232519988397858732U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4433022122758913407U;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12689609831247168353U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 404535388957472176U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 14534020545479806593U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3349108201964013155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4386449511297371730U;
            aOrbiterE = RotL64((aOrbiterE * 9596273264321140229U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14314587717949070586U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10923886625271054985U;
            aOrbiterJ = RotL64((aOrbiterJ * 7838969002623486809U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17634909585329833520U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2021301459918350372U;
            aOrbiterD = RotL64((aOrbiterD * 1388242915918642741U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5219599112498224367U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10641339455385046206U;
            aOrbiterI = RotL64((aOrbiterI * 1022283727595400719U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5003342156562330058U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10951027475628404336U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 17836928292555158461U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13040991872592235460U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11149099984302782267U;
            aOrbiterA = RotL64((aOrbiterA * 4248667283139686251U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2202253777854402763U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16679038924474862612U;
            aOrbiterB = RotL64((aOrbiterB * 2624443661523083597U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1959650241410955571U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8415989510614674816U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16340289102832732519U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2344501711730399821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4980738603982643969U;
            aOrbiterK = RotL64((aOrbiterK * 6419275275477478723U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 54U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 41U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterK, 24U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 13073U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15857U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15376U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 15100U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 56U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 29U)) + 1557680213571812384U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 5U)) + 7387349725778021121U) + aNonceWordK;
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 15379264067601586976U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 3730195724576043708U) + aNonceWordH;
            aOrbiterD = (aWandererA + RotL64(aScatter, 3U)) + 9637070085323827066U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 1170865717363676184U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 53U)) + 2750833653175252030U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 35U)) + 15118992811225568305U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 39U)) + 4974092922102988451U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 21U)) + 10625719096296719514U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 24U)) + RotL64(aCarry, 5U)) + 855167122475471865U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11322911068958340262U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4334591909425429835U;
            aOrbiterK = RotL64((aOrbiterK * 10059025861172038183U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14263701737208936392U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 678723206735649084U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 10823239851733632227U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15652053114252065230U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1705225940224061401U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3626023093533713579U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6826394665732900206U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11902946775066981141U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 18300629262162694137U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9802212958998591310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14001358545610206524U;
            aOrbiterH = RotL64((aOrbiterH * 13172645840788327099U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4299184726135884309U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7288757011999872416U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16806027820468277393U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 233801262480580205U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14208660347238680268U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 6299693448313154603U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9217797359740446104U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18165073197136050838U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11677479094709512887U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9101905235436427482U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2884224555227870272U;
            aOrbiterJ = RotL64((aOrbiterJ * 12085235281782370391U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13118509728421714433U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1385390888603164704U;
            aOrbiterC = RotL64((aOrbiterC * 6927424835779289199U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9621084561183039538U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1557680213571812384U;
            aOrbiterA = RotL64((aOrbiterA * 3202327770291862207U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 52U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aNonceWordO);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 26U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16844U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 20524U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 18802U)) & S_BLOCK1], 4U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 18925U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16465U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererB + RotL64(aScatter, 3U)) + 1888427424966603593U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 28U)) + 5436761445660415091U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 17322876217962143270U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 53U)) + 9728299982740564979U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 51U)) + 301720335271716921U) + aNonceWordM;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 39U)) + 8069685428854814396U) + aNonceWordA;
            aOrbiterI = (aWandererC + RotL64(aCross, 41U)) + 1973715500949100991U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 11U)) + 87666408799854155U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 12195436904339035245U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 4578742069143400295U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 47U)) + 7828776048774876484U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17203146364542781833U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16913369550858890466U;
            aOrbiterB = RotL64((aOrbiterB * 13534417587921978507U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9632761514552265402U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9106637671877341286U;
            aOrbiterK = RotL64((aOrbiterK * 9073709119482640391U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15423680889126750876U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6087310684583331882U;
            aOrbiterG = RotL64((aOrbiterG * 8964465129744898619U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5420955876411796789U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14166807419730848032U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 442659738632823751U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8118312450347026824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4253043584558403086U;
            aOrbiterA = RotL64((aOrbiterA * 5651748455190536467U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 8810774678371762700U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12218479555589447835U;
            aOrbiterF = RotL64((aOrbiterF * 11026364205248516355U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11389930523582876358U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16334420553471379915U;
            aOrbiterC = RotL64((aOrbiterC * 13830132212033904777U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18201289372553710279U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7196540389657785361U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13058135202554889791U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2601046573550065116U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2243003381737071984U;
            aOrbiterD = RotL64((aOrbiterD * 10518763530499878945U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6058992247656841580U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10083863011670540073U;
            aOrbiterH = RotL64((aOrbiterH * 17908394295613117155U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8505005026063156940U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1888427424966603593U;
            aOrbiterI = RotL64((aOrbiterI * 18298382581929885653U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 37U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 18U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 24U)) + aOrbiterD) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 25511U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 25944U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26758U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23427U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23023U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 26230U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 56U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 13U)) + 9654059367478508868U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 22U)) + RotL64(aCarry, 19U)) + 6473006635864677427U) + aNonceWordE;
            aOrbiterK = (aWandererE + RotL64(aIngress, 53U)) + 6944184481315853243U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 4061496421939102306U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 15791809275719085463U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 43U)) + 14050798802646323055U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 51U)) + 12072905924741758266U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 57U)) + 17639076509231343896U;
            aOrbiterH = (aWandererG + RotL64(aCross, 11U)) + 12195388285571234715U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 5U)) + 4325404419499496529U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 40U)) + 5910567888204238382U) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13092940059929942699U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13381962590820308761U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 6345904465930943295U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15622862439323440527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14027151901132249793U;
            aOrbiterG = RotL64((aOrbiterG * 2273573821630510087U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4584410023907605157U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15763755180625487157U;
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17023059745666559199U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5298529579288492971U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2483562793328357721U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2870152867331654736U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12017191100173748848U;
            aOrbiterH = RotL64((aOrbiterH * 9958191466506480519U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15899529176182436062U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16482713846343388735U;
            aOrbiterC = RotL64((aOrbiterC * 719465695044265601U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12943393531812774449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9881108254540483225U;
            aOrbiterD = RotL64((aOrbiterD * 8011108108007885059U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3532054586199716750U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7142230313294797435U;
            aOrbiterJ = RotL64((aOrbiterJ * 14154176174768868421U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 733958394016131587U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2060800099014517137U;
            aOrbiterI = RotL64((aOrbiterI * 12988885554457108631U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 2278498033811574812U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15342071118593803929U;
            aOrbiterB = RotL64((aOrbiterB * 7842196613533603835U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12987212219357101955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9654059367478508868U;
            aOrbiterF = RotL64((aOrbiterF * 11796100167917742307U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 30U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterF, 50U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31631U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 29387U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28936U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30062U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28529U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30215U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 5U)) + 9855743441035905047U;
            aOrbiterE = (aWandererK + RotL64(aCross, 37U)) + 8426286937143990276U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 30U)) + 7146752367170267002U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 35U)) + 12947210066678101726U;
            aOrbiterK = ((((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 15902163559925328965U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererC + RotL64(aIngress, 3U)) + 8506649889346449469U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 8226286036430263052U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 43U)) + 2703047093452420216U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 6769351326360139560U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 11U)) + 9857025533281333281U) + aNonceWordP;
            aOrbiterI = (aWandererF + RotL64(aCross, 24U)) + 238297452132277585U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7203572312072908931U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12497027346166575632U;
            aOrbiterJ = RotL64((aOrbiterJ * 1703586436725662307U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 473851890609048879U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4635095143004754116U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17695676150967345793U;
            aOrbiterD = RotL64((aOrbiterD * 5780416541584439301U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15628965269863402796U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9190117464399730235U;
            aOrbiterH = RotL64((aOrbiterH * 5586437438425999715U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17835918238346011086U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4398005402429282682U;
            aOrbiterG = RotL64((aOrbiterG * 14828737209913317463U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10902589938246551273U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15124274429081385923U;
            aOrbiterA = RotL64((aOrbiterA * 13524180348258805367U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8747233520702236018U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5445611443463112371U;
            aOrbiterC = RotL64((aOrbiterC * 10294109295823410447U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16296005217836151910U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6468336224317602364U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 7369779919748367133U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3827976387089403774U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7773383658122100111U;
            aOrbiterI = RotL64((aOrbiterI * 9784711300597525161U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18273794621528918389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8401424792700263455U;
            aOrbiterB = RotL64((aOrbiterB * 13003420427441089595U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11402828934846813949U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9855743441035905047U;
            aOrbiterE = RotL64((aOrbiterE * 7339549576423555273U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterK, 52U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterG, 39U));
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 50U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE53BCFB9F8D836A3ULL + 0xA8FE310C3B32D4E9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFEB3B1753D6441B3ULL + 0xDFBBDB434C56D02BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC468EC0B7F9D7661ULL + 0xC8CF0794A8E01D0EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDB1BE4227B487A09ULL + 0xFFD06E59C501BDFEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE76175364304669FULL + 0xA551E21EAA865A4DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9742DBCBDB8564CBULL + 0xB66D27017B004D25ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE84F644E3CD3DBE3ULL + 0xFC29AF7FE186BEE8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA5B9AF5409022F23ULL + 0xDC853C7DFA818F73ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB4B5EF678CF5C49DULL + 0xD8F5468B07C544D0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x89E2DFEF00D9B607ULL + 0xE9E3DD6EAA959015ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDBCADCADCF24D3CBULL + 0xE135428CB73E07A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9101AC37183B10BBULL + 0xD559B56F626D35B3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD5580B2D992C393BULL + 0x9E2D4618C8254E7CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x86796578A480F23DULL + 0x94EBABA31FBD7369ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCEE517A2EB79984FULL + 0xEF576BF74C0DB135ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF2813DAB1D2ACCD7ULL + 0xDC99A8F65E7C1A3AULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 7285U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1996U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8152U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 2500U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 26U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 6163290588946759209U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 29U)) + 7342672468560105447U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 11574563167017282321U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 51U)) + 2254820206194758964U) + aNonceWordP;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 1469783447473099498U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 14174828900676165088U;
            aOrbiterG = (aWandererH + RotL64(aCross, 23U)) + 16277954291890598132U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 14845750668693136766U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 18U)) + 150099699692047766U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1200784917165131703U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9469982764806754302U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17851969334511301943U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10956702761701710182U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17335794183733623213U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 557028996286989506U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 3993359298602424281U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1597385667771002414U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4376417959915162639U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 4626236858205178149U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 549770198518993876U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 756554555648070919U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16272320259614325355U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7298557532533152193U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3336802611342112013U;
            aOrbiterE = RotL64((aOrbiterE * 14679103452120080499U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2314938232094714365U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12215066333571149153U;
            aOrbiterH = RotL64((aOrbiterH * 10747052773052630601U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7762752719356805046U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6519429915769040078U;
            aOrbiterI = RotL64((aOrbiterI * 15548676502167938513U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7556691736109752918U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13731245903412646404U;
            aOrbiterB = RotL64((aOrbiterB * 15581965016668635409U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 54U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterI, 28U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterB, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15234U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 13053U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10861U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14735U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 12845U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 47U)) + 5173905450211892891U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 52U)) + 3555542451908039957U) + aNonceWordE;
            aOrbiterB = (aWandererE + RotL64(aIngress, 37U)) + 11559884700283861559U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + 1352524329968738673U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 8914206450420616349U) + aNonceWordK;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 2251523378498463946U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 9541575923299247038U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 29U)) + 1239854507907214595U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 56U)) + 17698101462598498934U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12305566971683256060U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13804545036303215569U;
            aOrbiterB = RotL64((aOrbiterB * 10359543704152744971U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10239749097704329264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4212214906286320308U;
            aOrbiterF = RotL64((aOrbiterF * 3661436621615751071U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12192418916967430783U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4475514289326450361U;
            aOrbiterK = RotL64((aOrbiterK * 17497164630368757887U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 17376102613298827459U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18129393209955439341U;
            aOrbiterH = RotL64((aOrbiterH * 6404089025014118979U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4014763724300253568U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17325007199676828814U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 1420888274815627083U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15480474849292388685U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14357924730184375449U;
            aOrbiterC = RotL64((aOrbiterC * 16723492259068034209U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4335731868597970070U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8296023680394303015U;
            aOrbiterD = RotL64((aOrbiterD * 14027415401430120543U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2807312426993262800U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15510369660839648501U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18207954408298333959U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12597844696606519907U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7231012798553551535U;
            aOrbiterI = RotL64((aOrbiterI * 2841306785994479299U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 46U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 48U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + (((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22084U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 17984U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23780U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19462U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21263U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 21730U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 52U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 16922357079016918108U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 6U)) + 11771749797137599131U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 4635668433708036077U;
            aOrbiterD = ((((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 15827952719230577008U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 57U)) + 1495675306110023086U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 13U)) + 7294835466949728365U) + aNonceWordA;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 37U)) + 179122461212041978U) + aNonceWordI;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 52U)) + 545981421632236251U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + 15338259639814630535U) + aNonceWordC;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12924313840290895215U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17846785921286020610U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18309347016029917133U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5721472794107057875U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16359630793856870319U;
            aOrbiterJ = RotL64((aOrbiterJ * 14186771515526698907U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10614102110239037308U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16421992251278236531U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2561232904676068089U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8668149834861244963U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12699331834360948734U;
            aOrbiterD = RotL64((aOrbiterD * 2249360824172616357U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4470693178142950471U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 526000656022724741U;
            aOrbiterA = RotL64((aOrbiterA * 16688501462334673493U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6880246132270094141U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7126466778855297013U;
            aOrbiterC = RotL64((aOrbiterC * 5692237926830293205U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6436404501390442054U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1213633065612242699U;
            aOrbiterB = RotL64((aOrbiterB * 17604454985534439259U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8186529105901185854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10607460957358250935U;
            aOrbiterI = RotL64((aOrbiterI * 17172191011625677861U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 9743278964993305169U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14007577681873418075U;
            aOrbiterK = RotL64((aOrbiterK * 4231122580398039133U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 22U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 52U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 48U)) + aOrbiterA) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26024U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((aIndex + 26771U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 28484U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31197U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30751U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 27769U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 12U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 5U)) + 8604208734152026945U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 12U)) + 1374329953253889829U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 19U)) + 5779278910548228339U;
            aOrbiterH = (aWandererA + RotL64(aCross, 47U)) + 17670451230882805140U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 8193848740764866860U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 15801168428145650104U) + aNonceWordC;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 28U)) + RotL64(aCarry, 27U)) + 2584718176087499066U) + aNonceWordH;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 53U)) + 14950366247822737997U) + aNonceWordL;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 23U)) + 9779293225265670135U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8688968319288372383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13665723186950342601U;
            aOrbiterJ = RotL64((aOrbiterJ * 292035540396910837U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9395428688359973510U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2152719218018108418U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15271961483518392671U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1350324137411377992U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8729317951386057921U;
            aOrbiterD = RotL64((aOrbiterD * 6008790836417785083U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6317310451893678411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10175620379041384281U;
            aOrbiterG = RotL64((aOrbiterG * 14079679617394330781U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1203082119358827708U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 523869107818193101U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 4629501113595689157U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4028324959540432983U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15447631947468213912U;
            aOrbiterB = RotL64((aOrbiterB * 6037306615787729185U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14225888694733041031U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11925000696281947629U;
            aOrbiterH = RotL64((aOrbiterH * 4337022940520411253U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15015531024930608745U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16752579225076943550U;
            aOrbiterC = RotL64((aOrbiterC * 15551083683579981439U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2432733494869267901U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10103430321388601485U;
            aOrbiterI = RotL64((aOrbiterI * 18372919379972432569U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterE, 18U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Karate_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC36C57C0118E72B7ULL + 0xF806BB2FBE6BE403ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF650E9CFAC3F9CDDULL + 0xB9D4C173A72CA151ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB36E3DD08075171BULL + 0xF982011ED407CDDCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAF1EC7DB1EB48357ULL + 0xF579ABABA63C400DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB9B182E39324C1C1ULL + 0xE653909179453AB1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFEE3250DD5C46033ULL + 0xDE4CB1C72AF13B8AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFA47E81EB5E22429ULL + 0x8A07A33AFAB94650ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE3CE5F3CBE8C8E45ULL + 0xB417E3F0CAD904AEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x84092F60D500A59FULL + 0xDD5D2C3E262F6ED5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8A9427ACD0D49E69ULL + 0xD506F969C4D64D60ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x875DD35C0DC34933ULL + 0xFD0D069572E6B3CCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9A42366D332FEF1DULL + 0xEF2E630B8D28D467ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA3B0CC3C16C69755ULL + 0xF0858AB8089247F9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBC111B1ED27CFC45ULL + 0x891568600AD5C407ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFD282E90908762FDULL + 0xCA03B604AD7E920BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE184D2172E1E515DULL + 0x96446E2866BA5AC8ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneD
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8039U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 7046U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5228U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6537U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 1861U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 826930775230515406U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 5137814617363250861U) + aNonceWordL;
            aOrbiterE = ((aWandererE + RotL64(aCross, 5U)) + 14761561947426681616U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 12773023438753662590U) + aNonceWordA;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 21U)) + 7331345852207096322U) + aNonceWordI;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3899381212671247460U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10072004147620068599U;
            aOrbiterE = RotL64((aOrbiterE * 5663583566047763435U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3424585039401897560U) + aNonceWordJ;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 8246760141625966321U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 11478879365443736383U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3655992860610853290U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11154618022505863898U;
            aOrbiterJ = RotL64((aOrbiterJ * 4791494171286145231U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15629361991059709973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10842068502278489664U;
            aOrbiterG = RotL64((aOrbiterG * 17223002513104960799U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5571312349016336686U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 589313823745748879U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1356685926549786027U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 10U)) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9304U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 10427U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 10307U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13804U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12941U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15885U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 50U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 5041131702736607991U) + aNonceWordM;
            aOrbiterH = (aWandererI + RotL64(aScatter, 3U)) + 9295010428212681446U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 6235875895358766017U;
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 18U)) + RotL64(aCarry, 43U)) + 2622227802531866918U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 41U)) + 3888894734834524972U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 241682012014701753U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 15758000422451568079U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 14719166949665416221U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2061944548396976912U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8177144990755754531U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12702392689484397947U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 554978075608818497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 250408260560714933U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1295379390497107727U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8700027645880997552U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 10026130047465480902U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 12417270861933696623U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9785843014096326696U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9998582683258411251U;
            aOrbiterH = RotL64((aOrbiterH * 7197956237569462269U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 20U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17291U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 19582U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23996U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18306U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21085U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 18435U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 44U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 3U)) + 8767379393098711499U) + aNonceWordG;
            aOrbiterH = ((((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 7168159491580816433U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 36U)) + RotL64(aCarry, 53U)) + 9879279829061883406U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 47U)) + 10537167136053399303U) + aNonceWordE;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 2839070018069188936U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13844278063968429732U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11278946626186474646U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6601953972456332355U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11798425216660557799U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7618446090703335192U;
            aOrbiterJ = RotL64((aOrbiterJ * 7168757300685156779U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 695423597006983660U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14344728202803488813U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5168825904902285909U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11656100506575697086U) + aNonceWordA;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 10384358779985773937U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 247494692039140973U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17585001605131977341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9964478171465522911U;
            aOrbiterD = RotL64((aOrbiterD * 13484044854790175315U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 54U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31820U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 31361U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29621U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31651U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26669U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29141U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25414U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 21U)) + 16802219662864902427U;
            aOrbiterD = ((((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 14332033461409490629U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 8781794298640286845U) + aNonceWordH;
            aOrbiterH = ((((aWandererD + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 8459933908074937264U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 13U)) + 1883580287986004426U) + aNonceWordK;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17500258188004626118U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7934811305150872870U;
            aOrbiterA = RotL64((aOrbiterA * 10039004285642030761U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6380363892361098905U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12623079132626676910U;
            aOrbiterK = RotL64((aOrbiterK * 12406671746344127399U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10455208121949202703U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8805532707916767629U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 666082374369701881U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9161544391400377699U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 3501434325829663268U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 7933545151293799637U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 651783304096081996U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 441505031509930622U;
            aOrbiterC = RotL64((aOrbiterC * 8045355432310956143U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 6U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 44U)) + aOrbiterD) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Karate_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x947230416A078845ULL + 0xEC2E16D6C83AE447ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x982CC0F7ADCE7A33ULL + 0xCFFBC6C4384E1D1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC56AF8CD1AB384FBULL + 0xEF14F660BC855CD9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF232F0929CAACC8FULL + 0xE09145B464C51309ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA5EC61C9E6AF5E85ULL + 0x972CB48459CE8D45ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x933E29CF5F46FE21ULL + 0x8786A780ABBCD650ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFB2C641B01DF862DULL + 0xD2BD8C6561BB18B1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x874D4978FE010DC9ULL + 0xEC158616B7A5F200ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCDAA54035385B43DULL + 0xC84E2181258C816AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBE9706162434D483ULL + 0x9A1BAF606E1B0D9BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x82CD3E42A2AA34B5ULL + 0xA8304BE1AF3699E4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA822A4CE11D6FC2DULL + 0xEABADBCAAE9C94C5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x891613B31C4AAB39ULL + 0xC05E9D0D514DAF47ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA62BDBA189C3ABCDULL + 0x8CE3ABE3F956BC0EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x85CFF94345EB5F65ULL + 0xDBE6EC93EC75A258ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x80067A710C5AEC47ULL + 0xFAAE6E6BDD370C76ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aFireLaneB, aFireLaneA, aWorkLaneB, aOperationLaneB, aOperationLaneD, aWorkLaneC, aOperationLaneC, aFireLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4787U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 6799U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3495U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 417U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4543U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7109U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 29U)) + 1210605127156905516U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 11964595428173569519U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 16277319029916258482U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 4U)) + 12369497463101824572U) + aNonceWordJ;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 23U)) + 6201248574067068202U;
            aOrbiterH = (aWandererK + RotL64(aCross, 35U)) + 1727477025667206661U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 1404510627789806851U) + aNonceWordE;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 6948213591282018925U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6688865181284421478U;
            aOrbiterK = RotL64((aOrbiterK * 12619122841662247279U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3351130769402360855U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12681032488906270823U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3680893896579741263U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3591412591193726763U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16153817571210878589U;
            aOrbiterH = RotL64((aOrbiterH * 4165137036092246349U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3808228354421006630U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1427373776207504205U;
            aOrbiterJ = RotL64((aOrbiterJ * 4534374093769595531U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1831554180932501132U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1114853085120949215U;
            aOrbiterC = RotL64((aOrbiterC * 4264176108298812905U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2080935638828366835U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16104777999646489828U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15205199362011777473U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9782806013673440791U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3721620299829386454U;
            aOrbiterE = RotL64((aOrbiterE * 6286765834910272409U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13628U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 15399U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10196U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10403U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14925U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 9891U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 2177539223979303669U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 27U)) + 3962004686551521471U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aWandererF + RotL64(aCross, 41U)) + 8457602312617147662U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 13U)) + 18011802451816510632U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 9046101759168876832U) + aNonceWordB;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 47U)) + 11135620637431969597U) + aNonceWordN;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 15913029940697999701U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16304193109948135982U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 13208892298820080981U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 15093751072618884859U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4182377898949419225U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13970137023071326151U;
            aOrbiterH = RotL64((aOrbiterH * 9075061559681739865U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8402396284835248583U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8859190834060657829U;
            aOrbiterJ = RotL64((aOrbiterJ * 13552418608113716117U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9760005337757990392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14108277760135744897U;
            aOrbiterB = RotL64((aOrbiterB * 4474681104256093885U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12226316121949012350U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3456392186754113960U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8704729827929941215U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5004087958637038973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10889800478505074438U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13728832441482547824U;
            aOrbiterF = RotL64((aOrbiterF * 17588477761978646139U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23162U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 22534U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 19074U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20069U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22285U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 16576U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 57U)) + 380024772508948442U) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 28U)) + 7649029098162567210U) + aNonceWordE;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 5329304598870421851U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 13U)) + 12306118665045151326U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 960751560457324256U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 37U)) + 3244070254386191876U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 15733408571609521746U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17623448932647018544U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8787759896149035829U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7092515868845497573U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14741681792348288162U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8801731213568307302U;
            aOrbiterD = RotL64((aOrbiterD * 12127126999570616489U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9872248187499779222U) + aNonceWordB;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 15407371518644528235U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4242060317152943062U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7296348796484458631U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15061417216070157797U;
            aOrbiterH = RotL64((aOrbiterH * 10349554676953256231U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3233185810644297433U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9241229457641024287U;
            aOrbiterJ = RotL64((aOrbiterJ * 2728237515724597517U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8464051359381554575U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3307872165699029375U;
            aOrbiterC = RotL64((aOrbiterC * 4859663401033023433U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 26U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 34U)) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + ((((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29961U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 31758U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26428U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32002U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32252U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 32192U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 11U)) + 9471546960258473684U) + aNonceWordL;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 18050235435948942244U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 41U)) + 3005107102671544641U) + aNonceWordA;
            aOrbiterH = (aWandererB + RotL64(aIngress, 13U)) + 17898396434573801850U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 3U)) + 15071602525497771648U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 5780119462702672108U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 21U)) + 13301326224151025687U) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18129323022260575961U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1199228670638790709U;
            aOrbiterD = RotL64((aOrbiterD * 1780426336211781025U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1839199978088021020U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4999517042246790165U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 4585813675677234577U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8788607633376516299U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 15143903839930468749U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16674732686428431869U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15908873150953195581U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11204775359756474667U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2525984309543939465U;
            aOrbiterJ = RotL64((aOrbiterJ * 3988529812023791571U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4566345170476825512U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14876612901557406267U;
            aOrbiterE = RotL64((aOrbiterE * 9047956948845135339U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14926290877038883931U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12710203178186614846U;
            aOrbiterC = RotL64((aOrbiterC * 14841163494801662515U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + aNonceWordG);
            aWandererI = aWandererI + (((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterA, 29U)) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD87E8D9EBD843977ULL + 0xBBC69975A10BBD3CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD4601073A1DA4917ULL + 0xF63D216E8542A812ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA3B959E5E60EC4F7ULL + 0xE4195C4A476A2D33ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCC56F59B3571EE7BULL + 0x91CD6ECF2EB099A6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE22845571B61D079ULL + 0xBCB0C0D3CA75C37EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8B155EDE9B667F3FULL + 0xB05B25F9C48D1C48ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9EF638D81E099021ULL + 0x98239DD8C3846E33ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9955217BE879A2FBULL + 0x9A2A79B11DD7E55BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFF14E907EA620A3FULL + 0xA0AC158F194A3B0DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA073E724768AD8CBULL + 0xD7DC1637876906B3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBB5C369C896A9837ULL + 0xA765373C0C9F4E07ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF497F35739F2B8C9ULL + 0x89E5B031AE5BF8B7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x872E4600B587A105ULL + 0xECEB393F2C43F721ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFC41CAC6BE15C58BULL + 0xA4F6E6011514920AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9FEFA27DA1016077ULL + 0xB3C090D88AB6A62BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8A16271DB3FA8A47ULL + 0x9089E9C602767A45ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aFireLaneB, aOperationLaneB, aExpandLaneB, aOperationLaneA, aFireLaneC, aExpandLaneC, aFireLaneA, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7846U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 2265U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 2219U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5855U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2574U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 3301U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 11700815697312060726U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 21U)) + 11808423452327465441U;
            aOrbiterG = (aWandererB + RotL64(aCross, 12U)) + 8670503858631730886U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 5U)) + 2400061067991988544U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 16163118178366229686U) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 37U)) + 3280178595904941068U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 3298683600817047727U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16321624053445183574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6730229877611375225U;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 10162830636713641322U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15646771327759599256U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15333053762177144775U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14841751262270544102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9545541117228834895U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11529769874752969377U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14676615635857599982U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1231768638470558855U;
            aOrbiterJ = RotL64((aOrbiterJ * 2716808508509014677U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1945905595345404833U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1406171421638586846U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 4577864352425476233U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1970292335806697198U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12309719390375013297U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16540660957923687327U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5352135521358954576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterI = RotL64((aOrbiterI * 16385761112921041387U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 60U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15041U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 14278U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13233U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9611U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8605U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 14273U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + 9080426856729228705U) + aNonceWordA;
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 7851218321653539276U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 7023344692919298036U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 9772846154227440734U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 37U)) + 12008298632429608431U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 43U)) + 12201090455849562875U) + aNonceWordF;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 9498721803411445471U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 351203764023093632U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4966360430644539250U;
            aOrbiterF = RotL64((aOrbiterF * 10138518378274592739U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9194167899071345693U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4922477697284269116U;
            aOrbiterD = RotL64((aOrbiterD * 8444814161720407881U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15742625291642356429U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7528703106518431730U;
            aOrbiterC = RotL64((aOrbiterC * 11530049278751507567U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15279053574704935317U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2425839793660355555U;
            aOrbiterB = RotL64((aOrbiterB * 11486964816849830667U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 13209849392400008898U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9041500097716231309U;
            aOrbiterA = RotL64((aOrbiterA * 340661035700748739U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7885423750878814599U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1992993999902904603U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1478629826632201617U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6120758615019314102U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8529621625846992066U;
            aOrbiterI = RotL64((aOrbiterI * 8485991471612862467U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aNonceWordH);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterD, 60U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20511U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 23034U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20028U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18050U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22049U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22478U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + 6973892330986118220U) + aNonceWordE;
            aOrbiterK = ((((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 9886813896272094864U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererI + RotL64(aIngress, 6U)) + 10996306582517553173U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 29U)) + 8490648283899856223U) + aNonceWordC;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + 105141713530704655U) + aNonceWordP;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 3114337422810562588U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 980857684690886131U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6562042345807072665U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15665371138706353619U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 8086237578564620623U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 18113013571374375028U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17405346422601997299U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5130876096426182506U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1813821672299154629U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 15478100342425611875U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15793814882743306728U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13925299440495476399U;
            aOrbiterK = RotL64((aOrbiterK * 12049601510660117401U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9924458846049579438U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7810034662781768090U;
            aOrbiterF = RotL64((aOrbiterF * 10310594595026622513U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12812586478656872854U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5709576448057435237U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9101555233909853025U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7839807649914541516U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 4717944526755429647U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 8515229146471335721U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 12U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27903U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 30990U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29546U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30346U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26790U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24730U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 20U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 21U)) + 8685374557928800912U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 3U)) + 3482312691892161229U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererI + RotL64(aCross, 11U)) + 6948130297389161165U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 5506385663788942690U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 17859982009307397161U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 51U)) + 9178488809207094043U;
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 1835479501226057169U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5368101733632614939U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9050459666576835422U;
            aOrbiterK = RotL64((aOrbiterK * 10351719549990259551U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9042186993119635078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17528342580198295025U;
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6495418332558436882U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8834495762667327342U;
            aOrbiterE = RotL64((aOrbiterE * 10783141541937645995U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4364314196965690905U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6357485231062120459U;
            aOrbiterB = RotL64((aOrbiterB * 289429584586504995U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3321488322626415347U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10817330671781848737U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15875919466358823335U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17974092279281611763U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2871472057292789157U;
            aOrbiterI = RotL64((aOrbiterI * 16104199340711015181U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15187929795092006849U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13482063681546475923U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14466266308157364963U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 39U)) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 18U)) + aOrbiterF) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 20U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Karate_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE9625C8F330B4041ULL + 0xDE11C2CCF6D2D467ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9A18E1A75501B0EFULL + 0xEF9A6C9082F91245ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8EC847F37D45B78BULL + 0xB0D3E5BD1F694E82ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC833A3636B105CB3ULL + 0xAF283ADD47FEDA63ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCCAB79D9C87EB2FBULL + 0xA062FDDAA1F65B27ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAA59815D72E8B5E1ULL + 0xCEA9A21B1FAF7E90ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xED6DC617E7A0BFCDULL + 0xCCEE7BAECC33965CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9B1102A79B54FBE7ULL + 0x958B580C631A0433ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF980424207771169ULL + 0xAB27CDDB3C497E18ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8D1C99CA7A543E8DULL + 0xB2555541260AE018ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAFD0B607DC7B5991ULL + 0xCF946E8EC2C3318BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x98707B56B3954E59ULL + 0xC73ABC7A1BCAE264ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD958989D34C3D2E7ULL + 0xC9A2629387F16F69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8C3FE17266567CFBULL + 0x9A0F1474668EACB0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x91A02D0A3D509D67ULL + 0x9A67BFAE24D46575ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x80984EC68FA03847ULL + 0xF114CDE05EC3C7B8ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneB, aOperationLaneA, aFireLaneB, aFireLaneD, aOperationLaneB, aWorkLaneD, aWorkLaneC, aOperationLaneC, aFireLaneA, aWorkLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1505U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 6619U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8112U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8101U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3586U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4298U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 56U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererC + RotL64(aPrevious, 43U)) + 7632760812370906911U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 60U)) + 6007174525479723089U;
            aOrbiterD = (aWandererF + RotL64(aCross, 57U)) + 3362829642521821048U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 21U)) + 18009548556107978286U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 27U)) + 17880909432272697327U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 15961567935420752568U) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 14U)) + 10136559064656837921U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 17622019364405410277U) + aNonceWordA;
            aOrbiterB = (aWandererI + RotL64(aIngress, 5U)) + 6927494824421416306U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 7125170407794874847U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 51U)) + 12342273503071032250U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14997696377476124836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14874498694181230698U;
            aOrbiterD = RotL64((aOrbiterD * 4026127545746010937U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2549397729130885686U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4217995818662767955U;
            aOrbiterE = RotL64((aOrbiterE * 5525525344485251063U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4706089044415442525U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17983900172670031015U;
            aOrbiterJ = RotL64((aOrbiterJ * 541552737180932879U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1904937798143929988U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10620877287033139483U;
            aOrbiterA = RotL64((aOrbiterA * 16711012562024287213U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15681091173163181525U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2655543246639000084U;
            aOrbiterI = RotL64((aOrbiterI * 16686375598149755947U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2647895110857289213U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5581609212017175954U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15330263616699031311U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13609076329627787987U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6244266279516622070U;
            aOrbiterK = RotL64((aOrbiterK * 12488345779236971095U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5289624364508923581U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16351476803965903112U;
            aOrbiterB = RotL64((aOrbiterB * 9012522724650442597U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2731198704224650506U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4177455951984414332U;
            aOrbiterC = RotL64((aOrbiterC * 2567165277406175517U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3031687737578718714U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4866790771642413883U;
            aOrbiterF = RotL64((aOrbiterF * 1139524449666360541U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12903299652398385014U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7632760812370906911U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7924544687662448385U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 46U) + aOrbiterD) + RotL64(aOrbiterJ, 44U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD + (((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordC) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aPrevious, 10U) + aOrbiterK) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 14U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15360U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 11674U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11253U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14282U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8832U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10241U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 29U)) + 16016931609704150191U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 14511433515861302636U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 11691237442613269593U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 12U)) + 16383220587320484649U) + aNonceWordN;
            aOrbiterD = (aWandererH + RotL64(aScatter, 21U)) + 14293015313458219868U;
            aOrbiterG = (aWandererF + RotL64(aCross, 37U)) + 4407695248205526670U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 23U)) + 1158323195324398372U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 13U)) + 6577683409653864555U) + aNonceWordP;
            aOrbiterE = (aWandererB + RotL64(aCross, 39U)) + 171080079472863843U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 57U)) + 5766333425872228205U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 19U)) + 16173508656917582960U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11781450063402219202U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13033139686637576694U;
            aOrbiterI = RotL64((aOrbiterI * 4331137994135472025U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4006310759400926020U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13156817947481574467U;
            aOrbiterD = RotL64((aOrbiterD * 563189239835001483U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12791290558893516411U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 989729955679243234U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8757228712495095017U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 838379839663022790U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2830743864262313606U;
            aOrbiterE = RotL64((aOrbiterE * 10173947177104802797U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2146646527331684652U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 4629168181742174906U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 9046124907945045131U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1150129989168501777U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 619659995945229440U;
            aOrbiterF = RotL64((aOrbiterF * 13734821008174603409U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8120315647582116952U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13754584116324996165U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12295486140772079747U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6084566798869999580U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5731665119233722504U;
            aOrbiterG = RotL64((aOrbiterG * 5921510209025133639U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16134513471149338456U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9841695976256666234U;
            aOrbiterH = RotL64((aOrbiterH * 7417023101762286049U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2559042046155066240U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14065288635273112125U;
            aOrbiterJ = RotL64((aOrbiterJ * 10464173719695109147U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18228257734024217020U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16016931609704150191U;
            aOrbiterC = RotL64((aOrbiterC * 2874343578276710555U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterC, 26U)) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 22U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18889U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 22990U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17031U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23337U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21411U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17210U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 28U)) + 13960289014350612206U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 3483331015269589730U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 6873299241002444518U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 13U)) + 3562094007125534229U) + aNonceWordN;
            aOrbiterC = (aWandererC + RotL64(aScatter, 51U)) + 11422367439932782705U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 37U)) + 532453428514259816U) + aNonceWordO;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 5U)) + 17810941465810193088U) + aNonceWordL;
            aOrbiterH = (aWandererJ + RotL64(aCross, 35U)) + 11869759058631106331U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 57U)) + 8837581071876177566U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 20U)) + 17185378327053837778U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 7578253375676981500U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17112646434432814442U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14949096407295697881U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 14770977858283051753U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4259590620758467836U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6534899413644542303U;
            aOrbiterI = RotL64((aOrbiterI * 7987609419215568661U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2637407498893694243U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15819295597921425711U;
            aOrbiterF = RotL64((aOrbiterF * 5202015597375051399U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6373559542002699718U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11694562937392022505U;
            aOrbiterE = RotL64((aOrbiterE * 9311557972331218597U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3308736483775453062U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12749929710650475901U;
            aOrbiterG = RotL64((aOrbiterG * 248428400724560945U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1569528215675579656U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1044077933631689572U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6443796233912755143U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8393422728124537471U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2002732612516530754U;
            aOrbiterB = RotL64((aOrbiterB * 13702146823622364279U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13469191942843147943U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7633171368709520560U;
            aOrbiterA = RotL64((aOrbiterA * 9713514012478203047U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4023206337737491091U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15990323932023596968U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4816480271959713463U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 837005729394899591U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9692088757104339973U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17971548293495807419U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18039464962413134616U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13960289014350612206U;
            aOrbiterH = RotL64((aOrbiterH * 931609478642506411U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 54U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 10U) + aOrbiterA) + RotL64(aOrbiterF, 44U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererF, 36U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25197U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 29583U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25943U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29228U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26522U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30100U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 30U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 38U)) + RotL64(aCarry, 35U)) + 3238389262925516513U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 11U)) + 12381787182611386995U;
            aOrbiterH = (aWandererE + RotL64(aCross, 27U)) + 7883885539305181549U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 43U)) + 1185413044597727092U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 15219353497204773135U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 53U)) + 7533774715626734082U) + aNonceWordB;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 23U)) + 2599930450937763464U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 16074720663961214284U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 15483613196360051221U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 34U)) + 9396557867081376268U;
            aOrbiterE = (aWandererC + RotL64(aCross, 19U)) + 9668459976852660245U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9037269914643207212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16936742640861088240U;
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16481274825758546398U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 481851372837611166U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 2225030139210599207U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13608921517203544108U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16930740723286214636U;
            aOrbiterK = RotL64((aOrbiterK * 2605108503821980865U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 902242902582149908U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1510861213079342977U;
            aOrbiterB = RotL64((aOrbiterB * 3309753895727400707U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7116243600304980310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6631412278359709602U;
            aOrbiterD = RotL64((aOrbiterD * 11452627691392637463U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9246698682265275165U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8594373032014031450U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 2550138341089957033U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15912837963877821048U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11404583513022627609U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 17715204726760125357U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17295214920690244319U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18315664494984189344U;
            aOrbiterI = RotL64((aOrbiterI * 17398893532076312945U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2474825506593695564U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4400473621592150441U;
            aOrbiterF = RotL64((aOrbiterF * 7098832854166953839U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15270166373215060119U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4331232225067306139U;
            aOrbiterG = RotL64((aOrbiterG * 2299883590703870703U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2176207815544347316U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3238389262925516513U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13104597690682251231U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 50U)) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Karate_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBD7EC9B682BFBD31ULL + 0x8F0EBCAFD942E169ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDC8162242EEA7FA7ULL + 0xC9B63BF24C27CBA2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8BE921C154E48D27ULL + 0xE6ED710E8ED065F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF77ABA582507B623ULL + 0xE4BEDF7FF41DC7EFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9AD6C769E7649245ULL + 0xE179AD812FA6E4B3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE6FFB743A700951ULL + 0xAC9E78E5B62A9674ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9DED01153D038C21ULL + 0xCFA198811A09CAAAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x83C040C6EC845851ULL + 0xA361E2CB381AA631ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE1CDFCBD79EBCD2FULL + 0xBF8C3FD9F9F0E5F2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBFD85A426C8047CBULL + 0x95E4C1DD996BA616ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x865E295D2684CA13ULL + 0xCE29A1BA748406F7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA654E98C1A49B6C5ULL + 0xCF6FD9C22B8AC338ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC6BBBD78E1A8D657ULL + 0x888898FA2B0EB863ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB070A83D3F32AC93ULL + 0xD1215799FAD37E5AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDB76DDAA15937B9DULL + 0xA73D2000C94A019DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB17ED14E66D0267BULL + 0xCB975620FF153D39ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aWorkLaneB, aFireLaneA, aExpandLaneC, aFireLaneB, aWorkLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 186U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 1431U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5832U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 736U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5198U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 2139U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 58U)) + 5576732410244514238U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 47U)) + 2833808925935929629U;
            aOrbiterF = ((((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 3670188682914544792U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 15759072378887814995U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 29U)) + 13934007231137439994U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 51U)) + 11022225696007690512U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererD + RotL64(aScatter, 23U)) + 16989177104453635790U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 12U)) + 9256930045263527091U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 17788596104417068290U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17044369456673337625U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1310908395523250343U;
            aOrbiterF = RotL64((aOrbiterF * 16305084373037705921U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12067065689034065422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15130844248737512262U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 9409499577465934107U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14532689204495587494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8198147292120244178U;
            aOrbiterD = RotL64((aOrbiterD * 1418356389507740991U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5485494458627163347U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10830008207150307611U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6526039534042499457U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17770065502486618029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6397859353395335459U;
            aOrbiterC = RotL64((aOrbiterC * 14286997752368893825U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5128700697381508319U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 7103394110057060499U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 5053680689949149633U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16024401282261796979U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12818445221897253410U;
            aOrbiterA = RotL64((aOrbiterA * 11450004517784155405U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13386978409145916350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16740821954556699503U;
            aOrbiterE = RotL64((aOrbiterE * 5376430209628515105U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 313978038530994953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1355733685461795345U;
            aOrbiterI = RotL64((aOrbiterI * 15955927322082619735U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 37U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterC, 42U)) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 30U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10271U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((aIndex + 14518U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11942U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15779U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14784U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16330U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererF + RotL64(aIngress, 13U)) + 14214886793361825363U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 18U)) + 17267959031078766320U) + aNonceWordF;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 16436067429484887644U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 23U)) + 9885951769332633820U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 57U)) + 12971711341813893304U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 199970353398450154U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 30U)) + 1237341696444162094U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 41U)) + 7991128854417613360U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 14809029847149045833U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2559509556915775947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14336829730147834160U;
            aOrbiterB = RotL64((aOrbiterB * 15103242520064900873U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8853631886733610440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13346159398673246914U;
            aOrbiterA = RotL64((aOrbiterA * 13660497151446983393U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12121095718571872976U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16239781125815589804U;
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9051377033794324106U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13805815136723461780U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 571129481747181357U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14849157800322754413U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18116651528452542634U;
            aOrbiterG = RotL64((aOrbiterG * 3638480428016835537U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4105057226952948599U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5911714320560994391U;
            aOrbiterD = RotL64((aOrbiterD * 1796514171654961389U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4439149331729987587U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10278532228230163632U;
            aOrbiterC = RotL64((aOrbiterC * 17428224919864716517U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2342456582668741750U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 2360578572554664800U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 1108428466956691925U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 12132934875391401246U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17213278726790245812U;
            aOrbiterE = RotL64((aOrbiterE * 11904899990681410419U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 14U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterG, 30U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18031U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 23058U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16683U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23190U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17428U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21664U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 10U)) + 10881271196314989997U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 37U)) + 6406461249988567558U) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 17255067918280095959U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 51U)) + 16690850682497718411U) + aNonceWordM;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 5576201059361086866U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 41U)) + 11991259685693687554U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 5U)) + 14652535244217836909U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 46U)) + RotL64(aCarry, 5U)) + 1701789037170782122U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 953429054903473833U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12064513610469714211U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7993881398822002424U;
            aOrbiterB = RotL64((aOrbiterB * 11572884842788918377U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14421313768013320050U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11112386845630998889U;
            aOrbiterC = RotL64((aOrbiterC * 11771526352030371669U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17069630896535699015U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3308240081138623373U;
            aOrbiterG = RotL64((aOrbiterG * 10449509484417835159U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17615529807112933619U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11782807146851563541U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12992075832343669221U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14401645829607611983U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6736397344219993532U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1667287547938175641U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6446974060524700550U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7840991992443308254U;
            aOrbiterI = RotL64((aOrbiterI * 6891023544882740107U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10362169906019794305U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4503700997923168911U;
            aOrbiterA = RotL64((aOrbiterA * 15066164494038852559U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13492041134973259041U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14337899277551397976U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 5966740718899290915U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13693100781608180748U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16177545026405910052U;
            aOrbiterF = RotL64((aOrbiterF * 6019231448444020563U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 22U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 56U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 40U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterC, 30U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25701U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 26321U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32266U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27294U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30621U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26497U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 50U)) + 2617613537256538553U;
            aOrbiterD = (aWandererF + RotL64(aCross, 35U)) + 16642868916835132715U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 10860291124337073254U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 21U)) + 6432511273906902472U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 7505375005848241910U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 4U)) + 11086616004678821329U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 3298830587569881951U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 57U)) + 9775143140064220979U) + aNonceWordA;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 4147601326580823120U) + aNonceWordO;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12245920269898100415U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8391940489176734499U;
            aOrbiterK = RotL64((aOrbiterK * 9119606167674098007U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17876893379544668477U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18301882058180370541U;
            aOrbiterF = RotL64((aOrbiterF * 16680384667098921309U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6869225862715140102U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15404118372589259800U;
            aOrbiterH = RotL64((aOrbiterH * 5766851935950389915U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17757381020518233814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17677969146092374455U;
            aOrbiterI = RotL64((aOrbiterI * 3469432916562405063U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15783378556632870114U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5792858258663697864U;
            aOrbiterC = RotL64((aOrbiterC * 12008981883482080427U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11737803388202260296U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 16001927091970715330U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3062030309852922061U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1749586939123286632U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6169421068855905938U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12374789910763348695U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10073586820719728062U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17744171227198661555U;
            aOrbiterD = RotL64((aOrbiterD * 10658375268803957647U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1149819647337612792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7725598665625892006U;
            aOrbiterA = RotL64((aOrbiterA * 15097586655234391559U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterA, 10U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterA, 23U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 46U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 36U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 39U)) + aNonceWordC) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
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

void TwistExpander_Karate_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x91576A4E81FD4423ULL + 0x8E29553B39760EC4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD853696F555186E7ULL + 0xD4302980C7B14CEEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC08B870CEAE91AC1ULL + 0xEBE3DACD4230C302ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC16D52B9520F1A53ULL + 0xD9FFBD82D65FA5EBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9F1CE5548D358CADULL + 0xFCBE4397C85C1D5EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8FC5FCF539734407ULL + 0xA2B366526C501DCAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDCA6686631A3BEA1ULL + 0xC3F5B79E06C88302ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF1CF031D8A9DC8E9ULL + 0xC7B3EA37B2ABD730ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCBE562BD3D759631ULL + 0xE4087089A49AD2A7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDED535B346989B97ULL + 0x82FD5929B19670ACULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA8AEE82BE71B6A2BULL + 0xCAB2D7B7D999AFD7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC6DCE965E102B5D5ULL + 0xC27044D5CC82A4AAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE756F7F303B350B5ULL + 0xCA50E27F8307AEE3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDF632BA18909181FULL + 0xC19C903C5A6FA3E2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD10FFB9F361B7B97ULL + 0xABC9B7B4D36099DEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA5E636E1EE887D4BULL + 0x848DD760052720C9ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneA, aFireLaneD, aExpandLaneB, aOperationLaneB, aFireLaneC, aExpandLaneC, aOperationLaneA, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2480U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 3356U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5563U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6125U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7524U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 19U)) + 6243113109470883144U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aScatter, 27U)) + 3891552123999605832U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 8758797898587019128U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 1005891374086408851U) + aNonceWordB;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 3713426782180050764U) + aNonceWordC;
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 18358143862391573534U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 44U)) + 17504394029693712404U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 5312729289027417014U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2560873623431186029U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 16843728573219210173U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16309322822806704211U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10195513918020652600U;
            aOrbiterE = RotL64((aOrbiterE * 14569219741824123715U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2552116263258744287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7732784879810980089U;
            aOrbiterI = RotL64((aOrbiterI * 15041929399477790999U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16499127570665381507U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10890036715535519036U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9065115450010475187U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16288944603478791554U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14542766121469312846U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 8435383464425875209U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5973595239494084696U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1820492719977197097U;
            aOrbiterF = RotL64((aOrbiterF * 16164917159141304405U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10489529555776381736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6392552206958240484U;
            aOrbiterG = RotL64((aOrbiterG * 11761477994533503307U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 12U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15608U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 16283U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 16350U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15508U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14901U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12699U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 19U)) + 13880995121909552664U) + aNonceWordB;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 29U)) + 14534942818069300546U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 17745973100886007133U;
            aOrbiterD = ((((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 2249805580771946872U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 4460116116396439410U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 46U)) + 3378683994078106878U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 3992996501048809123U) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12057768808864451929U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4115362079047921130U;
            aOrbiterE = RotL64((aOrbiterE * 12263015903331031345U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15297384955502206698U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17623548383481905636U;
            aOrbiterC = RotL64((aOrbiterC * 7487278217901483685U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3559213898000162417U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12311605719074507335U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 3982199462062847697U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14807313864347885885U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11222085523291581822U;
            aOrbiterD = RotL64((aOrbiterD * 12580941911587215653U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 916681229436292462U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2441350114032314686U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 7336079498999018067U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7361470539894653271U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12153585147213579808U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3040327545467672961U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 13566300726101613579U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14875254144748509128U;
            aOrbiterI = RotL64((aOrbiterI * 13699179902908972403U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 12U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 36U)) + aOrbiterB) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24247U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 19005U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 21670U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18574U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21111U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18047U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 18U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (((aWandererE + RotL64(aIngress, 19U)) + 2558105147674438050U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 29U)) + 15856662514774702561U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 13346869226246584582U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + 7632111846116243973U) + aNonceWordM;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 2102101361626976279U) + aNonceWordH;
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 5605968705067851563U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 37U)) + 6842483186584326681U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 5559797213819425064U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12422313931331576759U;
            aOrbiterK = RotL64((aOrbiterK * 7399849122565913401U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2751024420047872601U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11031320239359798610U;
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14366375309473793217U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11971479429768505316U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10063001532313098203U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3947595951884469542U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17882767922372770896U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 3361906348965810211U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 513871456983509223U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5951677013597794294U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 8508629569649935293U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 437626309049021931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 466674061172005705U;
            aOrbiterC = RotL64((aOrbiterC * 1310502572084891157U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12362602809233133718U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10525852878882195702U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17755022180514914325U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 40U)) + aOrbiterA) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterG, 57U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24819U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 29612U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 27722U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28784U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29375U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 30304U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 21U)) + 13442819395490639310U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 8187292523194120936U) + aNonceWordO;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 11469697159823131388U) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 37U)) + 13414083692375929653U) + aNonceWordK;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 13U)) + 11404010733687907517U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 6783212827186218247U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 58U)) + 8561131439340372614U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6252609642004429113U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12804867444200448952U;
            aOrbiterB = RotL64((aOrbiterB * 3114688959081972615U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2739648749603690781U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14808861217017399752U;
            aOrbiterE = RotL64((aOrbiterE * 373911885694012101U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17588866502571268888U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5882260142735642980U;
            aOrbiterJ = RotL64((aOrbiterJ * 7688252946143263869U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15493099088132862949U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5175647411532429582U;
            aOrbiterK = RotL64((aOrbiterK * 15226544495598541883U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14279707376173642767U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 6826363572161275158U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 5263708315440161809U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13267185753040999992U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9980987858092888720U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13210290848800728635U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 3582972937645514549U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10140409019562890804U;
            aOrbiterG = RotL64((aOrbiterG * 6944490201647678479U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 58U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEFB7AE565DAE4F7FULL + 0xCEE20050471C1592ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFD1D6C3F415FF7C9ULL + 0xC26A7FCD61433225ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEBB679AD0FDD206DULL + 0xCB047428A5AF26EFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBBFDC56B39D515F7ULL + 0x8F7B227A06388736ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD4CE37163B8E6825ULL + 0xAE37C78FF90FEF84ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF787560DDB1623B9ULL + 0xEAB3052959497C90ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFC856426E33DDB85ULL + 0xC529FF71C7830A7DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC47E88A9F9A6CF81ULL + 0x9570BC97F8D74655ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEF7C8C09E3A38731ULL + 0xB7E7A3FF81CA9A99ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEF32758F13D4D661ULL + 0xF56FBABD8BBF6A38ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB097018C6C7F3787ULL + 0xC96DA8D57F8DB2B7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDA1EF724D13BE0C1ULL + 0x8BAABA7CD818C745ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE6F0FA54A295D9EBULL + 0x8364354271A3B86CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x97E41A2EEF7E9F9FULL + 0x8B99CBD0DB9E13CEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBEA2D8A4DC73817FULL + 0xD5B8D238DA47C93AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF7DCB770B3B728DBULL + 0xE10F0919CCAEA4CBULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2349U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 1410U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2192U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 193U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 18U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererA + RotL64(aCross, 21U)) + 13296600294247799698U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 37U)) + 5818503518080877515U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 6735784238734173597U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 7368398209488856201U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 43U)) + 961734029066455638U) + aNonceWordJ;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 12U)) + 797011946660892011U) + aNonceWordH;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 12841876018396622350U) + aNonceWordI;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16213253970483895623U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15186950557113470375U;
            aOrbiterB = RotL64((aOrbiterB * 4647470430467908107U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5117930310827477341U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12265429373166094162U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 1522823535151532249U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 13920531346698601568U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14695405206998211456U;
            aOrbiterJ = RotL64((aOrbiterJ * 13950964363414164279U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7851960904825938443U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9501511171732550190U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 5614164120361489613U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5663365182245722077U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9607860124321315555U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 3461820361914280601U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18171052650586819280U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3442698321538580861U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6317525514963824829U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1491052813469258970U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3956599824067616133U;
            aOrbiterA = RotL64((aOrbiterA * 2928600779267623085U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 14U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterG, 41U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aNonceWordB) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 5U)) + aNonceWordO) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4549U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[((aIndex + 4792U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4781U)) & W_KEY1], 10U) ^ RotL64(mSource[((aIndex + 5272U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 11U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 51U)) + 701291026547470433U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 11U)) + 17283292650462111643U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 9969124091931303406U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 889176772718046988U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 29U)) + 6054541844643748084U) + aNonceWordJ;
            aOrbiterH = (((aWandererA + RotL64(aCross, 19U)) + 14703226235143028132U) + aPhaseEOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 42U)) + RotL64(aCarry, 19U)) + 7977975878522921062U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16894322614172266274U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12160451749345900570U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 18055355572903901749U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10870847008043897470U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8159920947172520247U;
            aOrbiterJ = RotL64((aOrbiterJ * 4833194641611011805U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2440099120969517932U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2428396147731468007U;
            aOrbiterC = RotL64((aOrbiterC * 9363073341539598441U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2213226274394673479U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7079731443427765333U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 16918930776877030559U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 958896789550478970U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10788682955708075458U;
            aOrbiterH = RotL64((aOrbiterH * 913321215613559729U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2003386579317564870U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8419686358774204999U;
            aOrbiterA = RotL64((aOrbiterA * 6547052526438697621U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6989167615157578904U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17636634003643824148U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 11038576417283732937U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterH, 14U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6390U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7103U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6246U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7026U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5950U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 43U)) + 15036852811491820366U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 5U)) + 305637140752898475U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 35U)) + 11948631574496129610U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 13U)) + 5321623592482991426U) + aNonceWordM;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 4075270159062690728U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 15111580500356908928U) + aNonceWordJ;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 7244150695504160363U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5131563519577488862U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5881954992088651371U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2424421828597294607U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12780935808751507998U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12599159643925470226U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 17690046932587062701U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9466589929741834066U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6093158735705189789U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7453778295800853653U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17461243886150519249U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15456408913739900718U;
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11260643903290392780U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7870342756041882616U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 2431528656086173419U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 134484990005888936U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10626896209992890407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12034131076645285597U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14031164129515132292U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1771835705730244212U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 186981668443596623U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 14U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + aNonceWordD) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + aNonceWordL) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9323U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 9184U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 8287U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8956U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9379U)) & W_KEY1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 10870U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 4U)) + RotL64(aCarry, 13U)) + 8793908991006073956U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 27U)) + 2932916283348441943U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 53U)) + 11069042087940968262U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 14369628676782894441U) + aNonceWordL;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 43U)) + 8602903272780978282U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 3827036107178568820U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 13U)) + 8905245209036772489U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13331387530760017893U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9880107580289737823U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 10302652857542703753U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10199619040626900278U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2466307560891374281U;
            aOrbiterI = RotL64((aOrbiterI * 6295342978834217571U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13973403407981259448U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2851460278409385243U;
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10365453393815690776U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5058198848163792422U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10500434740387593487U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5946747708776079787U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11289798395177667084U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14327152153231286666U;
            aOrbiterF = RotL64((aOrbiterF * 18155778059595245561U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8065137263811956313U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3865153574847924816U;
            aOrbiterJ = RotL64((aOrbiterJ * 9495741102667755161U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + aNonceWordD) + aPhaseFWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 60U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13169U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 12277U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11544U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 13507U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13642U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11836U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12302U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 3339283916456813609U;
            aOrbiterH = ((((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 11339086426180649584U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 16819191669329316585U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 21U)) + 8361916937762630725U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 3U)) + 18031328374429899857U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 51U)) + 18261756894092897276U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 14U)) + 4250319792907645666U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1492411503643460886U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17369549067879344180U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7301713524358676722U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2985193736033012535U;
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14086975808140927408U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10390516547834639800U;
            aOrbiterK = RotL64((aOrbiterK * 11441293212275890819U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 18205555540941493267U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9209505304067579944U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3522631966146762306U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3441982898533162599U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8811497120829041188U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14707301680850257294U;
            aOrbiterF = RotL64((aOrbiterF * 11383709499376464085U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10080595991787801029U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6822892187784299166U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 7417016898027778287U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14087U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15167U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16226U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15622U)) & W_KEY1], 43U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14635U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14116U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14637U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 13U)) + 15316464782468770057U) + aNonceWordO;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 6642872057476351588U) + aNonceWordG;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 29U)) + 660732654689529192U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 7235418086884000655U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 58U)) + RotL64(aCarry, 41U)) + 14784518476694580493U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 35U)) + 12222433977933449375U) + aNonceWordN;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 19U)) + 8573001207708329927U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16035256260815013172U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15767726974121910203U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 719060452537759331U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17712217935322939971U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13488963456923357159U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 16785285630840310405U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10222949131965611079U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1495561412321657209U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9706305581868526265U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16156530750584361434U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7773792489045606309U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10730624207715601393U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11544578291333360613U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3665587867634242865U;
            aOrbiterH = RotL64((aOrbiterH * 4840528190844842595U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15248434984650998090U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15487979645426567581U;
            aOrbiterI = RotL64((aOrbiterI * 10868107809356766183U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6972347795052712690U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16074994810010431338U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 1262655238856775853U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterF, 58U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aNonceWordK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16855U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 17763U)) & W_KEY1], 30U));
            aIngress ^= (RotL64(mSource[((aIndex + 17414U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 16555U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17445U)) & W_KEY1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16801U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17694U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 60U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 4634399531433127141U) + aNonceWordL;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 27U)) + 16961792729406903200U) + aNonceWordK;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 47U)) + 4105280732301137738U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 15692013501147331191U) + aPhaseGOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 3U)) + 1252216715968780587U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 60U)) + 7958289043012473752U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 6611577301818896615U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8506226754305949140U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3648813120449403353U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9521367946879238849U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5195245426245535735U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 542948051600803051U;
            aOrbiterA = RotL64((aOrbiterA * 4631106308856448475U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11974253551208964789U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10596463592332655367U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 10941161258815714641U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12015129484061440159U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8254944355710109060U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3233697992479357615U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2754858806943915419U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5007802002906662779U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 15613733948331639723U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6262190752136523216U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10528977986487821428U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 1184258264034585525U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8511097226098211854U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12091864735686692582U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6128140528141411237U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 44U)) + aOrbiterF) + aNonceWordI);
            aWandererD = aWandererD + (((((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordD) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aNonceWordE) + aPhaseGWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21452U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 19260U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20764U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 19609U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20039U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20721U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20587U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 19283U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 50U)) + RotL64(aCarry, 39U)) + 12426357877879529292U) + aNonceWordI;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 12604900366173639176U) + aNonceWordE;
            aOrbiterI = (aWandererB + RotL64(aCross, 37U)) + 13511119007338929401U;
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 9878720081166788060U) + aPhaseGOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 3U)) + 15463195409806395076U) + aNonceWordF;
            aOrbiterD = ((aWandererA + RotL64(aCross, 19U)) + 6407922778852833423U) + aPhaseGOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 7690427254160734016U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18030974031722143619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17983938038322737041U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12479365337221685413U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16605512170117753884U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 681802273302348322U;
            aOrbiterF = RotL64((aOrbiterF * 14608920184802647123U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15550312921312083819U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17824154101711884508U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 7358612830654795357U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1939207786756735430U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3132864634777826569U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13606281919426730325U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12822929773923954849U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16576106045887115660U;
            aOrbiterA = RotL64((aOrbiterA * 16370914370769903051U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2398825881649235260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13700821892926092479U;
            aOrbiterD = RotL64((aOrbiterD * 10830623703416956043U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2439833784883391606U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15870638514107637833U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3797380922767479287U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + aNonceWordO) + aPhaseGWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + aPhaseGWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 52U)) + aOrbiterJ) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 11U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23349U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 23144U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23227U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22365U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22532U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23766U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22730U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 21868U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 27U)) + 7651355040951791298U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 13988210277931659312U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + 9846849412579537783U) + aNonceWordH;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 37U)) + 12746719939495876158U) + aPhaseGOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 11498066185182895284U) + aNonceWordA;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 11101058955193080232U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 6U)) + 15513734459555672046U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15711108675349394643U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4771231759949468556U;
            aOrbiterF = RotL64((aOrbiterF * 9806191054594333615U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11449258010811305256U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17036938391509986723U;
            aOrbiterC = RotL64((aOrbiterC * 7411466953205347639U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6999245666776654250U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2106819066263369528U;
            aOrbiterH = RotL64((aOrbiterH * 13005885810757743129U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12716183358903477216U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 16752724547046059889U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11475905692393034141U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17623077680983093163U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6726003022297274986U;
            aOrbiterE = RotL64((aOrbiterE * 14709385877103232653U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2842410225096524740U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9235178377537910514U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11813751114775673845U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2619888019860844610U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6295481948199619613U;
            aOrbiterD = RotL64((aOrbiterD * 15429161806953951205U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 40U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aNonceWordG);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 30U)) + aOrbiterE) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterC) + aNonceWordD) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26673U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 26836U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25479U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 25011U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25305U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25307U)) & S_BLOCK1], 26U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26800U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27064U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 13278949403988203974U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 39U)) + 9213599924054673756U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 23U)) + 1255746482932381798U) + aNonceWordO;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 54U)) + 11575321997144516122U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 15881587525529432437U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 9846195809864862707U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 12319815691858217670U) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16322617427294439587U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16332130810525887437U;
            aOrbiterJ = RotL64((aOrbiterJ * 7588076439690559343U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4920951156015336794U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16767126455124552329U;
            aOrbiterC = RotL64((aOrbiterC * 4440352337076842603U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12553595911087945223U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1437522202135436142U;
            aOrbiterA = RotL64((aOrbiterA * 2001992794165550905U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12313100454852227143U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2761983020631055729U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 3874839760378039509U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17635303588421554367U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 788212489507463763U;
            aOrbiterG = RotL64((aOrbiterG * 17896475584538528059U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5192552894670654434U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6784748488807738811U;
            aOrbiterH = RotL64((aOrbiterH * 8077237651953896479U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16113417046719114943U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1096874945215225916U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 17308604412622879833U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + aPhaseHWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 12U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + aNonceWordP) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28148U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((aIndex + 27309U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29483U)) & W_KEY1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29157U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28056U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27907U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29703U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((aIndex + 27589U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 47U)) + 11039986441331892533U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 3U)) + 6256024955965426119U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 9857443189988995666U) + aNonceWordK;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 11900944813380998208U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 8422577734978875541U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 37U)) + 3100835100713928724U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 60U)) + 11871553509810206993U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17614749493763417027U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3638372131856199916U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 480683274898147025U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6582275259281025770U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17016882418498941958U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 4269869255230867823U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1747214688658984715U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9356088987044015278U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4056238112133473456U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16013150119949532998U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 12913648646318115315U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16076621211111834889U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9940824359571581765U;
            aOrbiterD = RotL64((aOrbiterD * 11624767861336495331U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15624084004784515753U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7630989544834680335U;
            aOrbiterB = RotL64((aOrbiterB * 12261063237156822067U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18003586430673313786U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1654118743290334161U;
            aOrbiterF = RotL64((aOrbiterF * 1153250137357176071U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterK, 54U)) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aNonceWordB) + aPhaseHWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 48U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31082U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32589U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31085U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30967U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32140U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 30339U)) & W_KEY1], 60U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 54U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererB + RotL64(aScatter, 37U)) + 8685374557928800912U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 3482312691892161229U) + aNonceWordH;
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 6948130297389161165U) + aPhaseHOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 5506385663788942690U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 29U)) + 17859982009307397161U) + aNonceWordI;
            aOrbiterI = (((aWandererE + RotL64(aCross, 60U)) + 9178488809207094043U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 1835479501226057169U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5368101733632614939U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9050459666576835422U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10351719549990259551U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9042186993119635078U) + aNonceWordJ;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 17528342580198295025U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6495418332558436882U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8834495762667327342U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 10783141541937645995U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4364314196965690905U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 6357485231062120459U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 289429584586504995U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3321488322626415347U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10817330671781848737U;
            aOrbiterE = RotL64((aOrbiterE * 15875919466358823335U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17974092279281611763U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2871472057292789157U;
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15187929795092006849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13482063681546475923U;
            aOrbiterH = RotL64((aOrbiterH * 14466266308157364963U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 20U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + aNonceWordC) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE8F5115B59F6D4D5ULL + 0xAE902AE1A743356AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC5E617891D7BA0EFULL + 0xD185529F04759478ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8B6ABD555F7A468DULL + 0xD6A8000730C85987ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xED414568EBAF19ADULL + 0xC79564DA136CC8ECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBC8767DA4EB2F06FULL + 0xBDA5878CB85972AAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x94C4D9C4833B2943ULL + 0x8FF063DE60905369ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF4842FC1E2320BF7ULL + 0xC2355FAA795DC827ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC3D7966E436493E5ULL + 0xDA9A2AD8A9CFF8D7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB27DF007155E29E5ULL + 0x91525A9F18319AE6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8776F8D7DF88B7ADULL + 0xC4D3F01CF76A3175ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD6F1D6DDDFCA115FULL + 0xAF5D0C4A61BBE7A3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDAB2A95BC1BEDF19ULL + 0xA1266FA5FAC7B6ACULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF8F5BA9FCC92790FULL + 0x84683B34727AB381ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE85BA404E5CC1C3BULL + 0xBD7BDAC33C211782ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB6D6BABAC781A5D7ULL + 0xE10875C86625C50AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA1D59F7ADEA45AFDULL + 0xCBF309533B1EB435ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4944U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 2693U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 3569U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3656U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4805U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 2786079456995203065U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 7237256119153857253U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 29U)) + 9310834010563647604U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 17361734905706517877U) + aNonceWordB;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 50U)) + 15837111231884647451U) + aNonceWordL;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 18065431964418026445U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 3029123922999952652U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 16309219658285890145U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5166926595573507837U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1918425684273807598U;
            aOrbiterG = RotL64((aOrbiterG * 16616641579714896719U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4724551751012661440U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1818014487579644390U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14904092108647864911U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6670090372241084216U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8485757110007268693U;
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4928130251509514742U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2528788422725346792U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 1855982047967756661U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 52U) + RotL64(aOrbiterD, 56U)) + aOrbiterA) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererJ = aWandererJ + (((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 11U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aNonceWordO);
            aWandererB = aWandererB + (((((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 37U)) + aNonceWordP) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9022U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 10275U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7036U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6599U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 7796U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = ((aWandererD + RotL64(aCross, 46U)) + RotL64(aCarry, 53U)) + 2558105147674438050U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 3U)) + 15856662514774702561U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 13346869226246584582U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 7632111846116243973U) + aNonceWordG;
            aOrbiterE = (aWandererI + RotL64(aIngress, 19U)) + 2102101361626976279U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 5605968705067851563U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6842483186584326681U;
            aOrbiterK = RotL64((aOrbiterK * 11344798544990575365U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5559797213819425064U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12422313931331576759U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7399849122565913401U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2751024420047872601U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11031320239359798610U;
            aOrbiterJ = RotL64((aOrbiterJ * 8607639453141148025U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14366375309473793217U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11971479429768505316U;
            aOrbiterE = RotL64((aOrbiterE * 10063001532313098203U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3947595951884469542U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17882767922372770896U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 44U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 40U)) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12135U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 13978U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12110U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13860U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11289U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 13252U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 4622023259121087483U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 10253505250223501352U) + aNonceWordC;
            aOrbiterH = ((aWandererC + RotL64(aCross, 28U)) + 17133877904420462669U) + aNonceWordP;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 6162827793741796700U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 13U)) + 9610986424765907615U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11210747154264753754U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16554205219580654546U;
            aOrbiterH = RotL64((aOrbiterH * 12754735039924859911U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10352576357413766388U) + aNonceWordF;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 3651845783283479752U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 1011289824180799641U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18145542190463500476U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5415609566767162857U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 6474184559323816389U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2033734872464201570U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3507213117125813345U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5453058336688881113U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8716253393049851856U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 695984869565941856U;
            aOrbiterF = RotL64((aOrbiterF * 8377921610764044735U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 38U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aPhaseAWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19038U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((aIndex + 17248U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20878U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19139U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18895U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20139U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 30U)) + RotL64(aCarry, 11U)) + 13583136155674166402U;
            aOrbiterB = ((((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 12830472187484919497U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererB + RotL64(aIngress, 3U)) + 18081197909484522509U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 8680634051297891550U) + aPhaseAOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 11U)) + 13939998767458656823U) + aNonceWordI;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1795730579103692594U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17369751719734069999U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 2633464694273697123U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 224769585901248068U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4133547085925268180U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2611561365156544735U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7022512056309567391U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10319484359046945495U;
            aOrbiterI = RotL64((aOrbiterI * 3400140531307001933U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10483878349412282069U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6481381149199985736U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9701719367082506253U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13721077228796934509U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9704818014314175007U;
            aOrbiterG = RotL64((aOrbiterG * 760445624027740287U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + aNonceWordP) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterB, 24U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aNonceWordC) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26893U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 25615U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22728U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23826U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24583U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26941U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 4848316479321533394U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 6919360256662636195U) + aNonceWordD;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 5U)) + 9897013582181108544U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 35U)) + 7319353809896158678U) + aNonceWordN;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 23U)) + 2848175435514849859U) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6967780718720437934U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 10143884766603388136U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 17346772745745835895U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8675965006150972051U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 16350117755560994281U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 15072308930382994425U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17976597517118423760U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1399631141355370237U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16537788276543236833U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3590613762034716792U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 5134624314245932157U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 13077589037975283371U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10082236952942943654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4015535035905433450U;
            aOrbiterC = RotL64((aOrbiterC * 4961808568701908559U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterE, 10U));
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aNonceWordG);
            aWandererB = aWandererB + (((((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 47U)) + aNonceWordA) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28826U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 31630U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 30314U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30178U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32055U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 31045U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 11700815697312060726U;
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 11808423452327465441U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 39U)) + 8670503858631730886U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 2400061067991988544U) + aNonceWordK;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 11U)) + 16163118178366229686U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3280178595904941068U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 3298683600817047727U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9865649058799255343U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 16321624053445183574U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6730229877611375225U;
            aOrbiterK = RotL64((aOrbiterK * 2022290495153519279U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10162830636713641322U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15646771327759599256U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15333053762177144775U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14841751262270544102U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9545541117228834895U;
            aOrbiterF = RotL64((aOrbiterF * 11529769874752969377U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14676615635857599982U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1231768638470558855U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterB, 60U)) + aOrbiterH) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Karate_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9995192B1318E963ULL + 0x93B3AE2B2744B913ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDD74C04C2588EB45ULL + 0x800E239C55CAEF9FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9C4BFEAC42014EFFULL + 0xC24C70AEA7A60F58ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9F6D0D22C870E73DULL + 0xD7DED81BF1E996DCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD827F1EEF450CE43ULL + 0xAA18761698BB6F80ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFD7A37D2DB039613ULL + 0xD57408C6F0218829ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9095B5FA3BD1EFBFULL + 0xB30B5DC4C3719EDFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDC42BD0EC7CEC3E3ULL + 0xE97F18A127180A37ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD4874312979DBF21ULL + 0xBCF1C7E77FD6420CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9224A9A35D27DEBFULL + 0xC7858BFB6263BEE7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF8779DE68FE724DFULL + 0xA3109E2DA3A2E671ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8534310B8BFEA4D1ULL + 0xDC7A5109561DAF56ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9E47A6341CF29579ULL + 0x86E9304008463FEFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA73051ECC57DB9E7ULL + 0x80044F01C95D3B1DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9748E32A8A9A56DFULL + 0x90FF3BF28509C995ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x99BF213ABB419585ULL + 0xCD8B59B371BC6E91ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aExpandLaneD, aFireLaneD, aInvestLaneD, aExpandLaneB, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 504U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 1821U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5281U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1719U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2614U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4560U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 6U)) + 1210605127156905516U) + aNonceWordD;
            aOrbiterF = (aWandererD + RotL64(aIngress, 41U)) + 11964595428173569519U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 16277319029916258482U;
            aOrbiterI = (aWandererF + RotL64(aCross, 27U)) + 12369497463101824572U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 51U)) + 6201248574067068202U) + aPhaseBOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 1727477025667206661U) + aNonceWordE;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 1404510627789806851U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 13U)) + 6948213591282018925U) + aNonceWordO;
            aOrbiterB = (aWandererC + RotL64(aScatter, 21U)) + 6688865181284421478U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3351130769402360855U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12681032488906270823U;
            aOrbiterC = RotL64((aOrbiterC * 3680893896579741263U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3591412591193726763U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16153817571210878589U;
            aOrbiterJ = RotL64((aOrbiterJ * 4165137036092246349U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3808228354421006630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1427373776207504205U;
            aOrbiterE = RotL64((aOrbiterE * 4534374093769595531U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 1831554180932501132U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1114853085120949215U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4264176108298812905U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2080935638828366835U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16104777999646489828U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 15205199362011777473U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9782806013673440791U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3721620299829386454U;
            aOrbiterB = RotL64((aOrbiterB * 6286765834910272409U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4013706412064296527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5751022780695158579U;
            aOrbiterI = RotL64((aOrbiterI * 13766736471646116397U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17684546333240329338U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1106947111128020920U;
            aOrbiterA = RotL64((aOrbiterA * 3158839453318658951U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11564229705849500598U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1585817314460274286U;
            aOrbiterF = RotL64((aOrbiterF * 12687162159791577431U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 42U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterH, 18U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterK, 23U)) + aPhaseBWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 4U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9979U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((aIndex + 8967U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7887U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6530U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10465U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9779U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6848U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 11U)) + 7632760812370906911U) + aNonceWordB;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 37U)) + 6007174525479723089U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 22U)) + RotL64(aCarry, 47U)) + 3362829642521821048U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 29U)) + 18009548556107978286U) + aPhaseBOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererE + RotL64(aCross, 57U)) + 17880909432272697327U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + 15961567935420752568U) + aNonceWordG;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 10136559064656837921U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 17622019364405410277U;
            aOrbiterI = (aWandererF + RotL64(aCross, 42U)) + 6927494824421416306U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7125170407794874847U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12342273503071032250U;
            aOrbiterD = RotL64((aOrbiterD * 867417849555857179U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14997696377476124836U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14874498694181230698U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4026127545746010937U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2549397729130885686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4217995818662767955U;
            aOrbiterF = RotL64((aOrbiterF * 5525525344485251063U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4706089044415442525U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17983900172670031015U;
            aOrbiterA = RotL64((aOrbiterA * 541552737180932879U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1904937798143929988U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10620877287033139483U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 16711012562024287213U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15681091173163181525U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2655543246639000084U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 16686375598149755947U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2647895110857289213U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5581609212017175954U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15330263616699031311U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13609076329627787987U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6244266279516622070U;
            aOrbiterB = RotL64((aOrbiterB * 12488345779236971095U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5289624364508923581U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16351476803965903112U;
            aOrbiterJ = RotL64((aOrbiterJ * 9012522724650442597U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 58U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 53U)) + aNonceWordK) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 24U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneB
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11653U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 12108U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12773U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13663U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 15151U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 15920462086654025436U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 58U)) + 487844076858004017U) + aNonceWordB;
            aOrbiterH = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 14502883786442630566U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 3787107318658233674U) + aPhaseBOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 39U)) + 12548777544693755491U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 43U)) + 4907309444075181683U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 19U)) + 18342396700266492072U) + aNonceWordI;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 27U)) + 13503051997624242670U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 14U)) + 17845742460521374571U) + aNonceWordP;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8640887211877858169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5273913123709097537U;
            aOrbiterH = RotL64((aOrbiterH * 1661149444148461791U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17756844173695563883U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6713055830729302951U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2832836748513174311U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5106468334224035972U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10228769728713526172U;
            aOrbiterF = RotL64((aOrbiterF * 9760310686414358435U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7687649520668883142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7757480627354711605U;
            aOrbiterD = RotL64((aOrbiterD * 7222553727737349209U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10876291698508634557U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8149278085586014186U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 8577133863470695381U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15592893988925610485U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8639028256640537165U;
            aOrbiterE = RotL64((aOrbiterE * 1880655276432963955U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 475660347892196219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1903736092401853832U;
            aOrbiterI = RotL64((aOrbiterI * 8486318978769094799U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12463250192809450953U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7253918448601703982U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3821034106528009129U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5171661020093804486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11627344933828324146U;
            aOrbiterK = RotL64((aOrbiterK * 5388047063152043277U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 40U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterD, 14U)) + aNonceWordE) + aPhaseBWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 21013U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((aIndex + 18606U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 19365U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19930U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 17177U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCross, 26U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 43U)) + 10812151398716051703U;
            aOrbiterJ = ((((aWandererK + RotL64(aScatter, 28U)) + RotL64(aCarry, 51U)) + 18202551453336003710U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 9434410809101973752U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 5U)) + 12955829998028534045U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 37U)) + 12271740641929640181U) + aNonceWordG;
            aOrbiterC = (aWandererI + RotL64(aIngress, 19U)) + 14009351527014534752U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 53U)) + 4316296955679133450U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 13U)) + 16473324966997442872U) + aNonceWordL;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 23U)) + 15735123324965019802U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17656375090484080236U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16066325053456055298U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 17912970706985130327U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12908968778503516903U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12761433987676836197U;
            aOrbiterB = RotL64((aOrbiterB * 1023329467480907925U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12737513138040664509U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14535795767570998392U;
            aOrbiterC = RotL64((aOrbiterC * 15560519667062222269U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14370908061811284364U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7001358781208669795U;
            aOrbiterD = RotL64((aOrbiterD * 11641248025734015835U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7298578161120090849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10498302152357484629U;
            aOrbiterA = RotL64((aOrbiterA * 13144110412179037175U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11447343228638006767U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 18284143620422655675U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 572862190073605651U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 5918253208127360199U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3910541329178205943U;
            aOrbiterJ = RotL64((aOrbiterJ * 4550654545328228103U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10357053096941367910U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5610891501128498748U;
            aOrbiterH = RotL64((aOrbiterH * 8676370811772047449U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9049881176058575811U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6307599924966452216U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5551444450572055895U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 4U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 42U)) + aOrbiterA) + aPhaseBWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererA, 40U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneC
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22933U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((aIndex + 23049U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26547U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24709U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22209U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 27U)) + 16462052553719977502U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 60U)) + 12337064059566619581U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 15801005007094515447U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 41U)) + 8228706742665081656U) + aPhaseBOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 19U)) + 11006723027845190869U) + aNonceWordD;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 18173765337829177450U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 35U)) + 530215083653542558U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 6608611827035564511U) + aNonceWordL;
            aOrbiterE = (aWandererG + RotL64(aCross, 14U)) + 2246051826221626809U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5228575308895381421U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10999213210689606857U;
            aOrbiterG = RotL64((aOrbiterG * 5467601259546342925U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3773371037240485696U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8887985779436152504U;
            aOrbiterF = RotL64((aOrbiterF * 698713082830739677U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11150566414723818350U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8336366151003049546U;
            aOrbiterJ = RotL64((aOrbiterJ * 9033771197242493699U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13233968794237090787U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8172558473508478819U;
            aOrbiterH = RotL64((aOrbiterH * 17837070423649268435U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 133564480283347997U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15104810248883567064U;
            aOrbiterA = RotL64((aOrbiterA * 706802420642303533U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 9138629520201127075U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13993086066341664080U;
            aOrbiterB = RotL64((aOrbiterB * 4875046427147105077U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6547273508580516932U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9838727018769865759U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 11395273371936839815U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11685694999526122626U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8945983172566303116U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17791527981004597623U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17606249889617356327U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9296903152000480008U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 18066622289408024413U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 34U)) + aOrbiterI) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterC, 14U));
            aWandererB = aWandererB + (((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 51U)) + aNonceWordI) + aPhaseBWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28277U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 27571U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29459U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29777U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28191U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 18U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 12849591986267890852U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 51U)) + 8232614804696815750U) + aNonceWordJ;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 29U)) + 12141567259210877281U) + aNonceWordF;
            aOrbiterB = (((aWandererG + RotL64(aCross, 5U)) + 2928641981037885644U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererB + RotL64(aIngress, 41U)) + 980733350554783938U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 2683985177993350746U) + aPhaseBOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 14U)) + RotL64(aCarry, 21U)) + 14532148403815527355U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 21U)) + 7736296629433884203U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 37U)) + 10428437770166310549U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18327174144859461029U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6810436935194432002U;
            aOrbiterK = RotL64((aOrbiterK * 2715987179577753597U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12606153309690753435U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17123256945895150555U;
            aOrbiterI = RotL64((aOrbiterI * 13469111258504672565U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9057777759026189541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16478485918911194442U;
            aOrbiterA = RotL64((aOrbiterA * 11054247078884894131U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18064460487552100483U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11477276762421684083U;
            aOrbiterE = RotL64((aOrbiterE * 3886501230380184395U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18318375441973295081U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13849305985380030986U;
            aOrbiterC = RotL64((aOrbiterC * 12962140243967824959U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10240409420338313641U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18360586077779529086U;
            aOrbiterB = RotL64((aOrbiterB * 18196875422391501927U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16801797158622424257U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 4950305991208513887U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 4437082499761416951U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15790878572843321918U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9808781805065559728U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 9394280083159162953U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11974996650410830731U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 4955004489435232515U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 13301966529515483085U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 40U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + aNonceWordP) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterH, 48U)) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterB, 52U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 54U);
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

void TwistExpander_Karate_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9E57ACE944133D13ULL + 0xBE17DA20680E82B3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD66D44C07A7211B9ULL + 0xDFC18B8AF1BB61D1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB344837A8818DEFFULL + 0xE640B97EBF6EAEC5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB14A0943CB392103ULL + 0xFEC2FE8B5545CC0CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF6DABFBE3FF9522DULL + 0x93263D74319C2639ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE092891AFE80B899ULL + 0x98AD2CE031A50721ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE1768D4774323453ULL + 0x9E13F57667FF14BCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF93CB378DC10A3C7ULL + 0xB990759361DA2FA0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9E85F3A890D025C1ULL + 0xF205ACD3AD44F490ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA0D1AB6500FD3D65ULL + 0xDAD066D19005A4D0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC8854233502DD077ULL + 0xAE3A368977B4AEE2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFD67C6DAFE87CE77ULL + 0xBB55A1B6F48BFC86ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD7DEEB968AB4610DULL + 0xD275120A0210AAD3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC2740E15958A1A1DULL + 0xBCAC1D60A42FF503ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCD60937CC7A2CF8BULL + 0x98E48FA17E7E9D6BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB2F8ED277A1301C3ULL + 0xC67D08ED39AC856AULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2766U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 4495U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4550U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1186U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4992U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 4688U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 47U)) + 9751314027302668907U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 27U)) + 12175450995523107056U) + aPhaseDOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 54U)) + 17519694958730119552U;
            aOrbiterG = ((((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 9093525527925682263U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 35U)) + 3713831321786810138U) + aNonceWordN;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 10108355209191835040U) + aNonceWordL;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 12956307447311314768U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1904298513945877359U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4658049993308574460U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 10482422152074338611U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9826333658248851902U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12058666914724365134U;
            aOrbiterA = RotL64((aOrbiterA * 964233873188373939U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2516574707110528099U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13335308331049750235U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8230749255538495304U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16536559486797811486U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7097036838156464969U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12387639130570188998U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8459259798142872020U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 8001346480955847013U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16083784052002800300U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1957284290736468379U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7349538179311335863U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16395170077006105258U;
            aOrbiterH = RotL64((aOrbiterH * 4230485452156662763U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U)) + aNonceWordB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8444U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 5876U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9042U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((aIndex + 7553U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6242U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5841U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9262U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 29U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 5U)) + 9446153639709651566U) + aNonceWordL;
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 10550762260670758167U) + aNonceWordD;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + 7062634922142578383U) + aNonceWordC;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 20U)) + 9178499097812764515U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 6887103379773525538U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 6239750312052010257U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 17645022614523287959U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 3639618183259408272U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3131737117548745095U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6585057380704940395U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7253994382396406554U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15217993711938379561U;
            aOrbiterH = RotL64((aOrbiterH * 17853313384747259923U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12594152227603630033U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11250170200489647869U;
            aOrbiterA = RotL64((aOrbiterA * 546800378327864723U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12936942656624279424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10990736056052106149U;
            aOrbiterD = RotL64((aOrbiterD * 7123916809953459187U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12787293075893090465U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17154990205620778151U;
            aOrbiterE = RotL64((aOrbiterE * 10031369940028159521U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1270827262969060301U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17337623431665013136U;
            aOrbiterG = RotL64((aOrbiterG * 1517262088236356107U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 830330490987911853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6828309232554560547U;
            aOrbiterB = RotL64((aOrbiterB * 9742464176986145819U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 19U)) + aNonceWordH) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 42U) + aOrbiterE) + RotL64(aOrbiterB, 48U));
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14424U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 15746U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15226U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13741U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 11988U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 12775735908960052604U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 24U)) + 11791373812080296887U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererE + RotL64(aCross, 57U)) + 5537362877706057303U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 43U)) + 2023912048504189380U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 17668828109963766893U) + aNonceWordO;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + 558908629933941224U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 1479633119685446888U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15460320397843364063U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10059749397555469054U;
            aOrbiterE = RotL64((aOrbiterE * 8671817118586065469U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9987633811929693924U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4446204415503364254U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15106063243302192717U;
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9430197906134676162U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1226048679997253363U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10611580584157624739U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3137391249289641509U;
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9327201928815412810U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterC = RotL64((aOrbiterC * 13827717178378062047U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 10675114832750356941U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8804440385852327267U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordE) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 6U)) + aOrbiterH) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 20U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 16754U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneA[((aIndex + 21630U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19867U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18983U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17768U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 4752759164691497960U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 43U)) + 12088872623537639782U) + aNonceWordE;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 3734943577379734227U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 57U)) + 8854778183012444234U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 16948373492893967275U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 37U)) + 7962415690046184385U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 28U)) + 1872682375669714454U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7776801806943853566U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16665439117257230732U;
            aOrbiterI = RotL64((aOrbiterI * 6866375628213114965U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11088186766134265676U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10850237991780969350U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7547414856143095121U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6464817712131305812U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13261563971157415841U) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2323811103717827362U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 11483723582415081925U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12338803568475493422U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2811342930111104982U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5020981755203607757U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5554497011738996057U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12712169745460598698U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 1985586486150377769U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17415058661427002973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9430421222715343818U;
            aOrbiterC = RotL64((aOrbiterC * 10321140659099470811U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 20U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aNonceWordG) + aPhaseDWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26684U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 22446U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23948U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23061U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25003U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 24U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 13U)) + 5480870806135400132U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 8034874599430768743U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 4006919843736863767U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 2988069748674633718U) + aNonceWordF;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 35U)) + 12347295651973135786U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererA + RotL64(aScatter, 3U)) + 14152683894431568192U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 60U)) + 15765143815254196598U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10473067082331244233U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 1089466925383677249U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 17334888609179149753U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13215039929873682230U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3957997712247961479U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7631186240013784703U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10023907397941685546U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14593012591254614353U;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13353797968154036726U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9259966668512102858U;
            aOrbiterH = RotL64((aOrbiterH * 8326732574268308221U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10757861831070349321U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10530223113483866178U;
            aOrbiterF = RotL64((aOrbiterF * 11269177745265396583U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7554320926405521865U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6978052067277966996U;
            aOrbiterE = RotL64((aOrbiterE * 18020134738536217801U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 1053695861967171420U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15980734683539854451U;
            aOrbiterB = RotL64((aOrbiterB * 3208466640010555357U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ) + aNonceWordB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 4U)) + aOrbiterH) + aNonceWordO) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aNonceWordK);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28281U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneA[((aIndex + 31056U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28891U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28217U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30408U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 36U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 57U)) + 1708250618750199233U) + aNonceWordO;
            aOrbiterE = (aWandererD + RotL64(aIngress, 51U)) + 12009147777553691142U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 8393982703399156592U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 3247327098356831221U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 29U)) + 3403590155376353737U) + aNonceWordN;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 44U)) + 18197244558104735044U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 3096253642040701606U) + aNonceWordG;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8012692688785412179U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17531946907545680745U;
            aOrbiterJ = RotL64((aOrbiterJ * 16510602981731506381U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17687695944270225817U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 16147773866007628769U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 16926442582711557877U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18244641303026196497U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8839160526348897457U;
            aOrbiterE = RotL64((aOrbiterE * 14268021129087663397U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10599266240854068246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterF = RotL64((aOrbiterF * 13311591601230386375U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4629354220460621284U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9505955649473204942U;
            aOrbiterB = RotL64((aOrbiterB * 17775391885312236187U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17078153810088721310U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9470436761716263000U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5431855497250357229U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3305863413630104742U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14377172434239576161U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 6880176890091033423U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 30U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + aNonceWordP) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Karate_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF2179D048E9D0507ULL + 0xF591764688393965ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE1A673B26F1F7019ULL + 0xD1F202F3EC44216AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x92FC3B1828D3431FULL + 0xB0FC3B4949AF7ED9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8DADDFFC0492C28DULL + 0xDCDC76D0ABF28A63ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9F9B562EF371869FULL + 0x871D201E540C4AB4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEA5A3E5D6816CC47ULL + 0xA504AC55B3B95FE3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB54C21F7D4C0970DULL + 0xFD2B4351BEFEDB4EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFDF51E42FC69618DULL + 0xF8825FEACCEC56F6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9A0AFF72889BD789ULL + 0xDB5854C77CA42BE5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCD7CE8BD67A864C5ULL + 0xD86BBBD1B8E7E85BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8E924BD64C3ECBE9ULL + 0xE802B81DEE5D6491ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFDCB1A12335DAFC1ULL + 0xDCFEBFF6F3930050ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBC9B6A6C03CBC8B1ULL + 0xD24FDD3A215C7357ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9A798331B23D4249ULL + 0xF371796C2B3BEF74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA247B94644BA01FBULL + 0x8DD5F3A8E21A44F0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCDC8F14A91F4A71DULL + 0x8F1821EA45C75559ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4386U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneB[((aIndex + 2477U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3328U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4519U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3037U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4574U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 27U)) + 1210605127156905516U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 11964595428173569519U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 50U)) + 16277319029916258482U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 12369497463101824572U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 11U)) + 6201248574067068202U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 21U)) + 1727477025667206661U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 53U)) + 1404510627789806851U) + aPhaseEOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 5U)) + 6948213591282018925U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + 6688865181284421478U) + aNonceWordM;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 23U)) + 3351130769402360855U) + aNonceWordL;
            aOrbiterF = (((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 12681032488906270823U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3591412591193726763U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16153817571210878589U;
            aOrbiterE = RotL64((aOrbiterE * 4165137036092246349U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3808228354421006630U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1427373776207504205U;
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1831554180932501132U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1114853085120949215U;
            aOrbiterB = RotL64((aOrbiterB * 4264176108298812905U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2080935638828366835U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16104777999646489828U;
            aOrbiterG = RotL64((aOrbiterG * 15205199362011777473U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9782806013673440791U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3721620299829386454U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6286765834910272409U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4013706412064296527U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5751022780695158579U;
            aOrbiterF = RotL64((aOrbiterF * 13766736471646116397U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17684546333240329338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1106947111128020920U;
            aOrbiterA = RotL64((aOrbiterA * 3158839453318658951U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11564229705849500598U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1585817314460274286U;
            aOrbiterI = RotL64((aOrbiterI * 12687162159791577431U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13549147977354138518U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5148731385622182707U;
            aOrbiterJ = RotL64((aOrbiterJ * 11016443961557395981U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17048442399822433365U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13772472534194030098U;
            aOrbiterC = RotL64((aOrbiterC * 13155895389652826889U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9982971300679888388U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1210605127156905516U;
            aOrbiterD = RotL64((aOrbiterD * 9183351854400012949U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 36U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 48U)) + aOrbiterE) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10470U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 7334U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10756U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7953U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8547U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9069U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6913U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 39U)) + 11700815697312060726U) + aNonceWordF;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 35U)) + 11808423452327465441U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 20U)) + 8670503858631730886U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 2400061067991988544U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 16163118178366229686U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 3U)) + 3280178595904941068U;
            aOrbiterD = (aWandererB + RotL64(aCross, 27U)) + 3298683600817047727U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 53U)) + 16321624053445183574U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 6730229877611375225U) + aNonceWordL;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 14U)) + 10162830636713641322U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 11U)) + 15646771327759599256U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14841751262270544102U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9545541117228834895U;
            aOrbiterE = RotL64((aOrbiterE * 11529769874752969377U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14676615635857599982U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1231768638470558855U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2716808508509014677U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1945905595345404833U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1406171421638586846U;
            aOrbiterJ = RotL64((aOrbiterJ * 4577864352425476233U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1970292335806697198U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12309719390375013297U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16540660957923687327U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5352135521358954576U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15465675376193501658U;
            aOrbiterG = RotL64((aOrbiterG * 16385761112921041387U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2842123638916600369U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3544764287036748668U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3360772950777850115U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6038297172906492282U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10249342332287140970U;
            aOrbiterF = RotL64((aOrbiterF * 16701083081566042277U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1662076777040529446U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1949705569959740274U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11340691546658994529U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13934194245417822360U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5720408806425535958U;
            aOrbiterD = RotL64((aOrbiterD * 15237561081637415383U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2209251362417210658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4917447930929521699U;
            aOrbiterC = RotL64((aOrbiterC * 17489570156694692569U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14817115766683623486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11700815697312060726U;
            aOrbiterI = RotL64((aOrbiterI * 16982411053956669181U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 48U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordM) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 24U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12053U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 13245U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11982U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13435U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((aIndex + 14178U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 46U)) + 3236820517816085022U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 37U)) + 741288875914097926U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 8417246926007729580U) + aNonceWordK;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 3U)) + 9715717805774537170U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 14360243844821619482U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 58U)) + 10760908100206775334U) + aNonceWordO;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 3434641779946167811U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 7885568822756234567U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 41U)) + 3041563437672051294U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 13U)) + 15761355327564963516U) + aNonceWordC;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + 1158633562785937421U) + aNonceWordH;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9338581575871970653U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9172038894262857354U;
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14653924713599790081U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3854497592598563309U;
            aOrbiterG = RotL64((aOrbiterG * 11737111068815795303U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16286980180327600557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5092583772591249756U;
            aOrbiterB = RotL64((aOrbiterB * 13955105624639442903U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4288397994175567333U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15584236478994873104U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1860480595862755379U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5557463939827483792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2659814275753280856U;
            aOrbiterC = RotL64((aOrbiterC * 17702430405693184643U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6941807963525063449U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2040598555191211307U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 14750544987531722765U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 347572666231116258U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 779304821185302523U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14180254150318109855U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10632524582873079742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9761308771280517212U;
            aOrbiterE = RotL64((aOrbiterE * 13926235411726048921U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2097439707055737964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2813977930321463948U;
            aOrbiterK = RotL64((aOrbiterK * 14983538728730662603U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6080592019313796689U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5396623654821376409U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15478858835919398677U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8460497459575045342U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3236820517816085022U;
            aOrbiterI = RotL64((aOrbiterI * 5530411244458067093U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 44U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 54U)) + aOrbiterI) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordN) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19538U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((aIndex + 20747U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 18959U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18361U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19507U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 35U)) + 3561491146322798260U;
            aOrbiterC = (aWandererF + RotL64(aCross, 53U)) + 7075025056181885339U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 3U)) + 9230910887904171613U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + 4119781172609908917U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 35U)) + 17155609083870983149U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 2423018561430181695U) + aNonceWordF;
            aOrbiterE = (aWandererH + RotL64(aScatter, 39U)) + 12957280305617615744U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 41U)) + 2461704174772065813U) + aNonceWordO;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 7907123257849391997U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 47U)) + 7257868138318960007U;
            aOrbiterD = (aWandererD + RotL64(aCross, 10U)) + 16425903703085702285U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2990822664594079467U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5654819006718953817U;
            aOrbiterG = RotL64((aOrbiterG * 4465096036756887801U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12183676471235678779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15026286960542123922U;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12169080607071830522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2906296852254787499U;
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3029858695410344584U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14406410317495954566U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11048818178401163861U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13622063920319445043U;
            aOrbiterB = RotL64((aOrbiterB * 2516025554421589857U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2642646089141233277U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12761571777929273548U;
            aOrbiterJ = RotL64((aOrbiterJ * 5518252696078700127U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7753802695131502382U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8510425459525030222U;
            aOrbiterA = RotL64((aOrbiterA * 12412361423636026483U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13522645164493316722U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1437430302489702713U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14019316635365783545U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14745189473423751499U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16968328257002103715U;
            aOrbiterK = RotL64((aOrbiterK * 17915588590593471981U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5001838243344386314U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13506188720092630563U;
            aOrbiterC = RotL64((aOrbiterC * 7010027510838271877U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16902624500530747723U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3561491146322798260U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 95761172090277669U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterE, 18U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordP) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + aNonceWordG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterH, 60U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23449U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 24610U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26925U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26423U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25948U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26053U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 19U)) + 6521330037475130256U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 21U)) + 12611880456055428940U) + aPhaseEOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 12061611078130934708U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 34U)) + 1558112410801116984U;
            aOrbiterK = ((((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 10509115227850160786U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererE + RotL64(aScatter, 13U)) + 4045915960688792066U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 23U)) + 1196541286513243082U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 35U)) + 15564991032722373702U) + aNonceWordB;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 51U)) + 4897765238703641798U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + 12327429514907752733U) + aNonceWordD;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 6189189797708711636U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6374267075282018852U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1888758503831341439U;
            aOrbiterG = RotL64((aOrbiterG * 74387714918264257U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14956857689299491800U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14879361107223331957U;
            aOrbiterK = RotL64((aOrbiterK * 9166712966729591953U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16086885494838105042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8069724185844303923U;
            aOrbiterB = RotL64((aOrbiterB * 8878470736758734353U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10854345917959911439U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7078313614360332089U;
            aOrbiterJ = RotL64((aOrbiterJ * 9864025732292844871U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15083669236062255011U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 594879695916679116U;
            aOrbiterF = RotL64((aOrbiterF * 9852515479152735283U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6721466068234534523U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 475816724162626782U;
            aOrbiterC = RotL64((aOrbiterC * 4799725182757588407U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4341655358154605899U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15477254302340298586U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13961520225881974201U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10179091913200895775U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6310490897546909571U;
            aOrbiterI = RotL64((aOrbiterI * 15080621088825477613U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13462682513035460711U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16739138858084100385U;
            aOrbiterD = RotL64((aOrbiterD * 16386371811268298031U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13608837667062268989U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12902415667552110103U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16398790854093048017U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16596211634603915761U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6521330037475130256U;
            aOrbiterH = RotL64((aOrbiterH * 631958426544321145U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 30U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aCross, 48U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererB = aWandererB + ((RotL64(aScatter, 44U) + aOrbiterK) + RotL64(aOrbiterB, 18U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32025U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 27434U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29327U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30505U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32131U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 12775735908960052604U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 29U)) + 11791373812080296887U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 5537362877706057303U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 51U)) + 2023912048504189380U;
            aOrbiterB = (aWandererI + RotL64(aCross, 43U)) + 17668828109963766893U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 54U)) + 558908629933941224U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 23U)) + 1479633119685446888U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 15460320397843364063U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 13U)) + 10059749397555469054U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 48U)) + 9987633811929693924U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 19U)) + 10087337844580228269U) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9430197906134676162U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1226048679997253363U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10611580584157624739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3137391249289641509U;
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9327201928815412810U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7890659377013147073U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10675114832750356941U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8804440385852327267U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 8520671775587260601U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12871947817782057116U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11015991745792051390U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17152451500505815031U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6320437975845673731U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 702457937087191287U;
            aOrbiterJ = RotL64((aOrbiterJ * 17491257114676739589U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16629064896250312921U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6054107387816339103U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6983767878966747219U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13274874838094190290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12211422735294360321U;
            aOrbiterD = RotL64((aOrbiterD * 5113738196151089817U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15338616110718583619U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1475787183754511373U;
            aOrbiterF = RotL64((aOrbiterF * 10904607643785840003U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15486810401396777742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12775735908960052604U;
            aOrbiterC = RotL64((aOrbiterC * 7478156942468930207U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterA, 48U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterD, 22U)) + aOrbiterE) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Karate_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC3CC8E8306724A09ULL + 0x97EC822B343B9634ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF212EDA428201377ULL + 0x8C9297124C6D1870ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x837B23323E927F73ULL + 0x9CA4FC8347AD7108ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDC305FC5C714E85FULL + 0xC4D1FF35C40038DEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBF01CBCD34FD31B5ULL + 0xCE9536A1E14EC6C2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAD68F2BFFEBAE9FFULL + 0xDB853957D6637966ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC8C6A1778EB34747ULL + 0x8E3707918A505D10ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDE5535DC2D28338DULL + 0xA0406D4429940D5FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF61417AD374906CDULL + 0xDB8FFAE06BBA6AA8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC36165FD419C72B7ULL + 0xABFC7D32CF97F88FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x927E28F101E3DD8DULL + 0xFCA24B208AE9D958ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF978EA665947D6F1ULL + 0x94729F25F7E0DE9BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB72B3C6A6E214209ULL + 0xF502B18411256C6EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x994A5F2AD06DB93FULL + 0x8EF40EF795049AF8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB02510B4EB8DA1DBULL + 0xA5EDCAE330A94177ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x96F1E3F16C3DDD6BULL + 0xA93FA387C351A9D7ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneC, aInvestLaneA, aWorkLaneC, aSnowLaneD, aInvestLaneB, aExpandLaneA, aSnowLaneB, aExpandLaneB, aWorkLaneD, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 752U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((aIndex + 3439U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 3760U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3254U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5070U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1712U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 10U)) + 14499676118633326000U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 17191273593018552288U) + aNonceWordO;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 4085176294948097737U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + 11112671474158908186U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 8745787969012266485U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 30U)) + 18074049663777707948U) + aNonceWordP;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 2543758649719164688U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + 4659584749412700523U) + aNonceWordL;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 57U)) + 974639159259871273U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9211220687971081987U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8567024626862182714U;
            aOrbiterH = RotL64((aOrbiterH * 7755874089832496393U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5803002132294840900U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11968489432878148467U;
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9470807228394903442U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1692347973120388469U;
            aOrbiterA = RotL64((aOrbiterA * 17433393164156231575U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16510815732690193145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 755159406833096510U;
            aOrbiterF = RotL64((aOrbiterF * 14091736464659561165U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1518824876475937620U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 701225390867330446U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12264618860580199927U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8425976693733003889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7182176375442410367U;
            aOrbiterD = RotL64((aOrbiterD * 8860605703761731859U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4546566785167467924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2593340999038753749U;
            aOrbiterK = RotL64((aOrbiterK * 10152461487764567563U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9756331608356622299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5511625814747641978U;
            aOrbiterJ = RotL64((aOrbiterJ * 4806076157539829529U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8694400787420160733U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12648969491371382682U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5346585704222643759U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 40U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterK, 34U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aNonceWordN) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 8373U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 6525U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6110U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10136U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10323U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10524U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9092U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + 3917730204724097072U) + aNonceWordD;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 1874642340716212824U) + aNonceWordK;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 47U)) + 6900165757434854160U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 5U)) + 12750946097023807161U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 36U)) + RotL64(aCarry, 29U)) + 6563216048479513594U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 14960240191349450795U) + aNonceWordB;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 16306180275951788289U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 11U)) + 6502066618271045547U) + aNonceWordM;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 56U)) + 6219852857850888738U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2272931312452845850U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3028929882263199463U;
            aOrbiterK = RotL64((aOrbiterK * 11005324285856805069U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6067393030073568112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10094809900437037258U;
            aOrbiterH = RotL64((aOrbiterH * 18095564940730322769U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5962414178157074575U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15755563045799129417U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 3692603590609922031U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 6321455513889880590U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1197435601998121700U;
            aOrbiterI = RotL64((aOrbiterI * 17693996266260557625U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12496949381666299968U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6357070235648527030U;
            aOrbiterD = RotL64((aOrbiterD * 2931486644220862433U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8423760160877540210U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8090246492554850768U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2949407491181921633U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11436635942985063755U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17086363141014359856U;
            aOrbiterC = RotL64((aOrbiterC * 10504127577318206801U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10734017887545474935U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 375515325165740779U;
            aOrbiterG = RotL64((aOrbiterG * 9980486695448151709U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5217148491945389821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14696058217023530058U;
            aOrbiterA = RotL64((aOrbiterA * 11026674782236654799U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterA, 30U)) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 10U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13508U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 14626U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 15074U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15801U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15474U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 43U)) + 16160838483846078448U) + aNonceWordP;
            aOrbiterC = ((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 15404960896190227946U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 16904160594024977199U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 19U)) + 17790460246821031802U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aCross, 27U)) + 16395168254086971959U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 7484373204039901786U) + aNonceWordG;
            aOrbiterF = (aWandererK + RotL64(aScatter, 39U)) + 18026814691322913510U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 6U)) + 15244817793136966450U) + aNonceWordA;
            aOrbiterH = (aWandererI + RotL64(aScatter, 23U)) + 5795491730356335666U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3163873518027801504U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2690791759507349172U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16677948635136515083U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17898067251167087906U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8028010015006604239U;
            aOrbiterD = RotL64((aOrbiterD * 5601629670521300241U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7304739457289910555U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6476837815096530043U;
            aOrbiterI = RotL64((aOrbiterI * 16380545138701113267U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14242499233467960602U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17305645693017634630U;
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9772864059444171908U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7897200728282156408U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 816306719390807411U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4890999319172950996U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8165132649356094963U;
            aOrbiterF = RotL64((aOrbiterF * 17297706071263690189U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9342923520083533265U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7213639583505088067U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1349251979649428909U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4079475132684197272U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3350998022472827283U;
            aOrbiterH = RotL64((aOrbiterH * 948841791460066265U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2479140576609216238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7703147534931674972U;
            aOrbiterC = RotL64((aOrbiterC * 11419116495223970801U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterD, 56U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH + (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 52U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aSnowLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aSnowLaneB forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20363U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneC[((aIndex + 19503U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19811U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19767U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 18116U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 18U)) ^ (RotL64(aCross, 43U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 7632760812370906911U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 6007174525479723089U) + aNonceWordO;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 3362829642521821048U) + aNonceWordC;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 28U)) + RotL64(aCarry, 53U)) + 18009548556107978286U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 37U)) + 17880909432272697327U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 43U)) + 15961567935420752568U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererH + RotL64(aCross, 51U)) + 10136559064656837921U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 10U)) + 17622019364405410277U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 57U)) + 6927494824421416306U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7125170407794874847U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12342273503071032250U;
            aOrbiterE = RotL64((aOrbiterE * 867417849555857179U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14997696377476124836U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14874498694181230698U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 4026127545746010937U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2549397729130885686U) + aNonceWordF;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 4217995818662767955U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 5525525344485251063U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4706089044415442525U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17983900172670031015U;
            aOrbiterF = RotL64((aOrbiterF * 541552737180932879U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1904937798143929988U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10620877287033139483U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16711012562024287213U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15681091173163181525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2655543246639000084U;
            aOrbiterK = RotL64((aOrbiterK * 16686375598149755947U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2647895110857289213U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5581609212017175954U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15330263616699031311U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13609076329627787987U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6244266279516622070U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12488345779236971095U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5289624364508923581U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16351476803965903112U;
            aOrbiterB = RotL64((aOrbiterB * 9012522724650442597U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterA, 10U));
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 44U)) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24291U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 26327U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23896U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22883U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((aIndex + 26089U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 12U)) + 12669015908335980355U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 41U)) + 5438715179868613192U) + aNonceWordF;
            aOrbiterA = (aWandererE + RotL64(aCross, 23U)) + 13172104448184536460U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 3U)) + 13421421503244744803U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 53U)) + 13327113302994856582U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 4671768205922454413U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 5355759962838579929U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 35U)) + 6691720614265406851U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 18U)) + RotL64(aCarry, 13U)) + 7063906424700911378U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17328616394166672263U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1542940602574207068U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 8981679306319627975U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7203866278803132454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 993485696233139264U;
            aOrbiterB = RotL64((aOrbiterB * 11609009908810366447U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15659679028507488331U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 18321361454094675842U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3966860765622641843U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9633319822696783352U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3496559332232402963U;
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1918349708324205526U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 7701088402761359134U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 9649485438465644795U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6006824348814439686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18088375375347012557U;
            aOrbiterJ = RotL64((aOrbiterJ * 12801082943086128385U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12816533373478543584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17951880253818836433U;
            aOrbiterC = RotL64((aOrbiterC * 8935839101517220201U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11311632024372748238U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9891349164779752351U;
            aOrbiterG = RotL64((aOrbiterG * 11405973752233193209U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 711130292000437038U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17818800917771709681U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10567029732245868263U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 34U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 44U)) + aOrbiterF) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 48U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererC, 20U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32596U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 32619U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 30814U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28298U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29198U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 5U)) + 4773124477323378268U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 16848723289435796005U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + 13846642134917107058U) + aNonceWordF;
            aOrbiterB = (aWandererF + RotL64(aIngress, 58U)) + 6472057872482789939U;
            aOrbiterG = (aWandererH + RotL64(aCross, 29U)) + 2747019500690707226U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 43U)) + 9003965289739733880U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 3013390651936257377U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 21U)) + 3331004709895625067U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 15355010435553517129U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7709870658004280052U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13568728443963926564U;
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12409548853419307131U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 969183352023661537U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15370309834426476775U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3896803894396631184U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11018830202891911603U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10848873633291935766U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12885336509190543440U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1487357252619221365U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8252290890093788010U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9201553615601641350U;
            aOrbiterE = RotL64((aOrbiterE * 420321130559162915U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14014209645503188472U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4015071464301844550U;
            aOrbiterA = RotL64((aOrbiterA * 17444195018239904971U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16173085647514027347U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16916627014974363360U;
            aOrbiterG = RotL64((aOrbiterG * 7699587344277490953U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1591680303404522110U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16499606051269327916U;
            aOrbiterC = RotL64((aOrbiterC * 814405848002794813U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6932673635509444619U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8745681160108707944U;
            aOrbiterB = RotL64((aOrbiterB * 14565255558668084787U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterF, 13U));
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterC, 28U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 23U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aNonceWordK) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Karate_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC71D3AF0BD7CCCAFULL + 0xE5593E195DFCB30FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF279913F64D45B9FULL + 0x8B3B9ED4838EE836ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEE859451EFD8F435ULL + 0xC016A7521FC3CA73ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C56D68F0B57B87BULL + 0xB92737F07A3D6667ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEEB11D208ED554ADULL + 0x879510681824B207ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE8122CB8946F355DULL + 0xD47843BB0A773BF2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED64F6BDFA5BC85FULL + 0xB1E066402B095BF2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCED55DB4D57C05ADULL + 0xB40C7B8B2CEFAFD7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF5252E2FD1654515ULL + 0xF12D6D1F0922994DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDEE3D0FC73821955ULL + 0x87544E3B4DD42D9BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD802F4E318BA0183ULL + 0xD6585A5C45D67D32ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF6BAAF4398D1873BULL + 0xB8C83F55C2A5E595ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFD6803B1199E1F21ULL + 0xF30A8DB43ED1090CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCB08866DEC53854BULL + 0xBFA1A6607EBAC827ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAB4F5B2C411FE0FBULL + 0xDA25848DCEA8F410ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9417B73632C6478DULL + 0x9B1478965940A97EULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneD, aSnowLaneC, aSnowLaneD, aInvestLaneA, aWorkLaneA, aFireLaneC, aFireLaneA, aWorkLaneB, aInvestLaneC, aExpandLaneA, aFireLaneB, aExpandLaneB, aFireLaneD, aExpandLaneC, aInvestLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3563U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 1099U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 2298U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2579U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1324U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 131U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 44U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 35U)) + 7825479804710770560U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 5298124167101358123U) + aNonceWordJ;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 17774541024369233726U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 7679371833537454082U) + aNonceWordL;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 5385914900748772224U) + aNonceWordK;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 12U)) + 3879781930908486531U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererD + RotL64(aIngress, 21U)) + 659110346638873236U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10749021728538539749U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3631252455767429457U;
            aOrbiterK = RotL64((aOrbiterK * 8552825360915119613U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 2271978810960685021U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5963558780692551176U;
            aOrbiterB = RotL64((aOrbiterB * 4772055335210781149U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 974909966119198104U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 9296998242911152296U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 2613629915877957661U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2245318466901521959U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13391076374843288568U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18094558036982107419U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 6184487746594236737U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1563385912137291418U;
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1744840092006498629U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2100927276837188416U;
            aOrbiterI = RotL64((aOrbiterI * 3541788262067077997U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9998911862807246338U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12239948725635220096U;
            aOrbiterH = RotL64((aOrbiterH * 7098620484129489129U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 6U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aNonceWordO) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + aPhaseHWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8801U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 7757U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6953U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6559U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6385U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7404U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9648U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 60U)) + 3561491146322798260U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 7075025056181885339U) + aPhaseHOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 35U)) + 9230910887904171613U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 4119781172609908917U) + aNonceWordH;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 17155609083870983149U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 11U)) + 2423018561430181695U) + aNonceWordE;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 23U)) + 12957280305617615744U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2461704174772065813U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7907123257849391997U;
            aOrbiterA = RotL64((aOrbiterA * 9416171962847312179U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7257868138318960007U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16425903703085702285U;
            aOrbiterH = RotL64((aOrbiterH * 7996935869077231999U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2990822664594079467U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5654819006718953817U;
            aOrbiterD = RotL64((aOrbiterD * 4465096036756887801U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12183676471235678779U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15026286960542123922U;
            aOrbiterJ = RotL64((aOrbiterJ * 17199049329995315279U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12169080607071830522U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2906296852254787499U;
            aOrbiterE = RotL64((aOrbiterE * 6754514406846040163U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 3029858695410344584U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14406410317495954566U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9663780721657983421U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11048818178401163861U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13622063920319445043U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterK, 36U)) + aNonceWordD) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15362U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 15450U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16309U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13589U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12926U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 2783898056762489197U) + aNonceWordI;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 7177192902873343053U;
            aOrbiterE = ((((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 12254703232691980774U) + aPhaseHOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aWandererK + RotL64(aScatter, 5U)) + 15446547245691219559U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 19U)) + 888475203006174856U) + aNonceWordB;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 13U)) + 3649183529366307877U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererC + RotL64(aScatter, 56U)) + 4642631047518805167U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6108329730724782250U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8334054653023816636U;
            aOrbiterE = RotL64((aOrbiterE * 9352516059501924393U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5891895375031474350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3176720746238477862U;
            aOrbiterJ = RotL64((aOrbiterJ * 1869961473768307911U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6111038696865301675U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 11914998302228682704U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 11738924766359642853U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17005063057791320948U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18333780598768130670U;
            aOrbiterH = RotL64((aOrbiterH * 5416759844884107303U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2056115016443263153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10245512728872962677U;
            aOrbiterA = RotL64((aOrbiterA * 707106795383284903U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4810366069422162351U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3051442983125942469U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 13558537578054436423U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9285068547223654308U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13067251130180968842U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 7000687697769766605U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 36U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + aNonceWordF);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 40U)) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18988U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 17584U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19437U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18116U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17782U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 13442819395490639310U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 8187292523194120936U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + 11469697159823131388U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 13414083692375929653U) + aNonceWordE;
            aOrbiterC = (aWandererA + RotL64(aIngress, 41U)) + 11404010733687907517U;
            aOrbiterF = (aWandererF + RotL64(aCross, 54U)) + 6783212827186218247U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 11U)) + 8561131439340372614U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6252609642004429113U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12804867444200448952U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 3114688959081972615U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2739648749603690781U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14808861217017399752U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 373911885694012101U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17588866502571268888U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterH = RotL64((aOrbiterH * 7688252946143263869U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15493099088132862949U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5175647411532429582U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 15226544495598541883U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 14279707376173642767U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6826363572161275158U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5263708315440161809U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13267185753040999992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9980987858092888720U;
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3582972937645514549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10140409019562890804U;
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + aPhaseHWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aNonceWordL) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22524U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 26060U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25149U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26943U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 22816U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 50U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 11U)) + 12426357877879529292U) + aNonceWordP;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 12604900366173639176U;
            aOrbiterF = (aWandererB + RotL64(aCross, 53U)) + 13511119007338929401U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 9878720081166788060U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 15463195409806395076U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 46U)) + 6407922778852833423U) + aNonceWordA;
            aOrbiterB = (((aWandererF + RotL64(aCross, 3U)) + 7690427254160734016U) + aPhaseHOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18030974031722143619U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17983938038322737041U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12479365337221685413U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16605512170117753884U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 681802273302348322U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14608920184802647123U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15550312921312083819U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17824154101711884508U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 7358612830654795357U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1939207786756735430U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3132864634777826569U;
            aOrbiterE = RotL64((aOrbiterE * 13606281919426730325U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12822929773923954849U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16576106045887115660U;
            aOrbiterH = RotL64((aOrbiterH * 16370914370769903051U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2398825881649235260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13700821892926092479U;
            aOrbiterB = RotL64((aOrbiterB * 10830623703416956043U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2439833784883391606U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15870638514107637833U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3797380922767479287U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + aNonceWordH) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterB, 34U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27390U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 28034U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29649U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28197U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 32693U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 41U)) + 4752759164691497960U) + aNonceWordK;
            aOrbiterH = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 12088872623537639782U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 3734943577379734227U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 3U)) + 8854778183012444234U) + aNonceWordH;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 35U)) + 16948373492893967275U) + aNonceWordF;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 7962415690046184385U) + aNonceWordM;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 28U)) + 1872682375669714454U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7776801806943853566U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16665439117257230732U;
            aOrbiterG = RotL64((aOrbiterG * 6866375628213114965U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11088186766134265676U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10850237991780969350U;
            aOrbiterC = RotL64((aOrbiterC * 7547414856143095121U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6464817712131305812U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 244557182884209844U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13261563971157415841U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2323811103717827362U;
            aOrbiterA = RotL64((aOrbiterA * 11483723582415081925U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12338803568475493422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2811342930111104982U;
            aOrbiterK = RotL64((aOrbiterK * 5020981755203607757U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5554497011738996057U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12712169745460598698U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1985586486150377769U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17415058661427002973U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9430421222715343818U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10321140659099470811U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 13U)) + aNonceWordO) + aPhaseHWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterA, 54U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Karate_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 68U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 904U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1848U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2387U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 47U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 6654158889644956636U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 10U)) + 9045779659363991870U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 23U)) + 3888897662136993491U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 53U)) + 6882016842864459345U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 37U)) + 15601891715956172291U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 5176811598629335350U;
            aOrbiterI = (aWandererA + RotL64(aCross, 19U)) + 12519945150889074325U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 14U)) + 4552583214397603278U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 14225482701804864688U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5485298070606280363U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11237713257388094289U;
            aOrbiterK = RotL64((aOrbiterK * 11032429223099413011U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14340345895626142788U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16275167270553643347U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7308578867128951199U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14041860597556520250U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1436068974197066343U;
            aOrbiterI = RotL64((aOrbiterI * 3938460345031496843U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11483155566419547004U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4608508534724289325U;
            aOrbiterJ = RotL64((aOrbiterJ * 13461385011638899485U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2389196334288832895U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4062682330273866602U;
            aOrbiterG = RotL64((aOrbiterG * 8787682133271101901U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5655656046585592034U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7977947821249746880U;
            aOrbiterA = RotL64((aOrbiterA * 10082104644185964787U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11653718118543974168U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5456429682072377614U;
            aOrbiterF = RotL64((aOrbiterF * 12504180638665296649U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12457179652004203574U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 445821754230182952U;
            aOrbiterC = RotL64((aOrbiterC * 16043092621697786393U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12429505513284703263U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12480745784412363537U;
            aOrbiterE = RotL64((aOrbiterE * 643617210585287593U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + aPhaseAWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 24U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterK, 3U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 19U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 48U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 10U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3079U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5018U)) & W_KEY1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4392U)) & W_KEY1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3965U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 6U)) + 13915875634607599122U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 1695770381382411673U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 3709105579778295511U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 47U)) + 7673376335333251804U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 34U)) + 8814147709738503518U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 19U)) + 13451412605350381172U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 6447870234069609538U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 13419487997946496825U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 5478309847615220345U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3635184969215610049U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12527903812035294828U;
            aOrbiterK = RotL64((aOrbiterK * 12540800512035534967U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1684685110885338814U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12860354576326835090U;
            aOrbiterE = RotL64((aOrbiterE * 12743745087733307255U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9081823570147481835U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14369321778210049109U;
            aOrbiterF = RotL64((aOrbiterF * 17865953349448767035U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11518132079084873250U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11893535026126957389U;
            aOrbiterI = RotL64((aOrbiterI * 15751374986135615095U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7084079180579206226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2999676609847603277U;
            aOrbiterH = RotL64((aOrbiterH * 14602698397511266403U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17683445810614029153U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11576460512964896969U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5243651036457051155U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13429800604736567949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14661785761747367546U;
            aOrbiterJ = RotL64((aOrbiterJ * 4765843989277333421U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12837164345582888950U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6222666313184669392U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17402483466567712319U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5358647039491079457U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12459911673401497180U;
            aOrbiterG = RotL64((aOrbiterG * 13605465035256188065U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 46U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterG, 20U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 54U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + aPhaseAWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7491U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadB[((aIndex + 7674U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6712U)) & W_KEY1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6721U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7863U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 7893287783892523139U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 10257331997383491153U;
            aOrbiterG = (aWandererI + RotL64(aCross, 58U)) + 14562226733652231753U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 19U)) + 14320342577110737851U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 29U)) + 9816717579822880756U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 47U)) + 9558926960095881953U;
            aOrbiterK = (aWandererE + RotL64(aCross, 36U)) + 9230371862654338324U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 53U)) + 6414274291252913420U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 13868546184398350849U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16940736952569949038U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2866957764814864371U;
            aOrbiterG = RotL64((aOrbiterG * 3554702178644797003U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7916721976073979724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1602444214978842275U;
            aOrbiterE = RotL64((aOrbiterE * 11072503711308122385U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9529061385251008037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8402775110887376588U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15003592180290390713U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14195681406520825751U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11455000833788877217U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3263577002367714202U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12019422062655581928U;
            aOrbiterJ = RotL64((aOrbiterJ * 5002313835338447799U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8508638054582582917U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6536618106353552880U;
            aOrbiterA = RotL64((aOrbiterA * 6233964121117511885U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9654542989321430868U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7019594782797863244U;
            aOrbiterF = RotL64((aOrbiterF * 1234877854354279981U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8256061220727519919U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9232754129467036130U;
            aOrbiterH = RotL64((aOrbiterH * 17556001874302369781U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5608829951337740378U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12632120498473345701U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6994794653605831925U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterD, 42U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 60U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8714U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 10801U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(mSource[((aIndex + 9584U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 8223U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9848U)) & W_KEY1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8668U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 28U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 35U)) + 439898681482066326U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 52U)) + 17362083676671776094U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 23U)) + 6418499837265155024U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 17262244253027454972U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 43U)) + 2382066162993139503U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 14345808395587174135U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 57U)) + 7534743166385552851U;
            aOrbiterB = (aWandererE + RotL64(aCross, 47U)) + 16994453324688523966U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 39U)) + 7079553728544045092U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3562822704508440641U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13990892681975857821U;
            aOrbiterJ = RotL64((aOrbiterJ * 8352929306654078795U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1796728922368577238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6605161260520067178U;
            aOrbiterC = RotL64((aOrbiterC * 8147537646591674091U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13994083795942328918U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6144523182899107711U;
            aOrbiterK = RotL64((aOrbiterK * 4153879991344611283U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12247462325297436642U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1065809332002012789U;
            aOrbiterA = RotL64((aOrbiterA * 5496601177032953251U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10147919864511540753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17138553441127273354U;
            aOrbiterB = RotL64((aOrbiterB * 5773875596275267871U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2653924016109573974U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6254416952351699582U;
            aOrbiterF = RotL64((aOrbiterF * 12756861659704947257U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 813046408080197079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9624466135414123483U;
            aOrbiterI = RotL64((aOrbiterI * 6960320253124395015U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 972586705850825744U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 155283774901960223U;
            aOrbiterH = RotL64((aOrbiterH * 9928051687724257041U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18200100644751360406U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1168426822045686004U;
            aOrbiterE = RotL64((aOrbiterE * 5867027156069481313U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 46U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 28U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13080U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 12934U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 10940U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 11964U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12137U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13019U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 13576U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 23U)) + 964165145848253292U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 10645976767204934746U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 13U)) + 8241612229349212650U;
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 4159196033256913347U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 18U)) + 7194795864620233507U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 29U)) + 7638928444536778384U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 35U)) + 11819105916503968109U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 18052213302858186237U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 6U)) + RotL64(aCarry, 37U)) + 8663575313970041570U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16644136720439299786U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16930316530442679864U;
            aOrbiterA = RotL64((aOrbiterA * 2650922074098320859U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16251107616988250593U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7171986193609401665U;
            aOrbiterG = RotL64((aOrbiterG * 3543709971414550087U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17885046834432626644U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7757069274715713557U;
            aOrbiterD = RotL64((aOrbiterD * 15766885299397923879U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2212805322061155615U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6368539134638838822U;
            aOrbiterE = RotL64((aOrbiterE * 13383744883433594259U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5264326094252925613U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6126345334815012938U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17180934809764905307U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13826731214018407061U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6621261811613643620U;
            aOrbiterK = RotL64((aOrbiterK * 2823596473596114171U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5964406317285863781U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2167324450276308078U;
            aOrbiterC = RotL64((aOrbiterC * 1098346374733634905U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16740710162977859724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8236083581048717923U;
            aOrbiterB = RotL64((aOrbiterB * 4364887787000704039U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13967473987446124012U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5136051802217149813U;
            aOrbiterH = RotL64((aOrbiterH * 13997246005108872883U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 36U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15060U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((aIndex + 13828U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14814U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15267U)) & W_KEY1], 18U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15768U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14076U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14048U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 9630214189402543339U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 14U)) + 4072576573737526819U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + 15994787452709618869U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 53U)) + 6403240137132259482U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 23U)) + 10229266900170507720U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 27U)) + 5025294577989748989U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 16696461238217956883U;
            aOrbiterD = (aWandererA + RotL64(aCross, 29U)) + 9878318855341719119U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + 16086635438116177346U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12295437783084203730U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7681150419912842402U;
            aOrbiterJ = RotL64((aOrbiterJ * 7289497379725191451U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2639104034287637448U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12298170009332243573U;
            aOrbiterA = RotL64((aOrbiterA * 9397919591171238575U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3485932317267669626U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16569551670038752475U;
            aOrbiterH = RotL64((aOrbiterH * 8139802826402217631U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4448490103784103954U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14510534073046885941U;
            aOrbiterB = RotL64((aOrbiterB * 7777192047386438305U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4286195398675733451U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15790355933840266463U;
            aOrbiterK = RotL64((aOrbiterK * 13342257823027075501U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6362891510370156055U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15121822034579983174U;
            aOrbiterE = RotL64((aOrbiterE * 7268045994574844937U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13817341015719915628U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14113474087906143783U;
            aOrbiterD = RotL64((aOrbiterD * 12838910141533126059U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9988301252236121106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11287477288382171758U;
            aOrbiterF = RotL64((aOrbiterF * 4979297247881426383U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9491727010910328644U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7961202721830514030U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16300364540313620767U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 10U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterD, 60U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aPhaseBWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17635U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[((aIndex + 18977U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 16911U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 17039U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18970U)) & W_KEY1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18521U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18879U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 34U)) + 1952750591494698524U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 39U)) + 4488270851303332830U;
            aOrbiterI = (aWandererA + RotL64(aCross, 13U)) + 2738763375328927635U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 19U)) + 6728843649480454340U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 10490717875258865358U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 1429288737812910205U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 46U)) + 2761375016998907636U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 1088988605204499835U) + aPhaseCOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 6829840407300289709U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9267240337867690471U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8120113021183975703U;
            aOrbiterI = RotL64((aOrbiterI * 14296504593187173107U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1340980511302566784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11874452169979878835U;
            aOrbiterC = RotL64((aOrbiterC * 8638486178860092537U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1872314794140971426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6013952618696225751U;
            aOrbiterB = RotL64((aOrbiterB * 7994863587373565715U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3644011378086236002U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8501867691997891731U;
            aOrbiterA = RotL64((aOrbiterA * 7115282675461711509U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2493546555198066143U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5179240189571799179U;
            aOrbiterK = RotL64((aOrbiterK * 1267579130962756135U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11273348247858394197U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4577476419423118925U;
            aOrbiterF = RotL64((aOrbiterF * 8427261005061162673U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6201955123046621919U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3930651302557530185U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1563512534463027965U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7571426325227856019U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11098508505512361002U;
            aOrbiterE = RotL64((aOrbiterE * 9229352429618815089U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6154830144380484305U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4282054616147137364U;
            aOrbiterH = RotL64((aOrbiterH * 14984813139796280171U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 52U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aPhaseCWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterE, 6U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 38U) + aOrbiterF) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21774U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((aIndex + 20117U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21574U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19961U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20828U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20705U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21454U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 21276U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 22U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 23U)) + 8793908991006073956U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 5U)) + 2932916283348441943U) + aPhaseCOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 11069042087940968262U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 29U)) + 14369628676782894441U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 8602903272780978282U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 36U)) + 3827036107178568820U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 5U)) + 8905245209036772489U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 53U)) + 13331387530760017893U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 9880107580289737823U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10199619040626900278U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2466307560891374281U;
            aOrbiterB = RotL64((aOrbiterB * 6295342978834217571U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13973403407981259448U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2851460278409385243U;
            aOrbiterK = RotL64((aOrbiterK * 11226902976321781743U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10365453393815690776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2382382358987358791U;
            aOrbiterD = RotL64((aOrbiterD * 481563628980705781U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5058198848163792422U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10500434740387593487U;
            aOrbiterF = RotL64((aOrbiterF * 5946747708776079787U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11289798395177667084U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14327152153231286666U;
            aOrbiterA = RotL64((aOrbiterA * 18155778059595245561U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8065137263811956313U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3865153574847924816U;
            aOrbiterI = RotL64((aOrbiterI * 9495741102667755161U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18102279969722473375U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6306428427188742325U;
            aOrbiterG = RotL64((aOrbiterG * 17826782872351406167U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16953348204663693724U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11950791817032898613U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1498946055469611133U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11980823193543752994U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17845490308799454871U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16385153013485463791U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 26U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterA, 41U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 46U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 30U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24360U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 21902U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24260U)) & W_KEY1], 22U) ^ RotL64(aFireLaneC[((aIndex + 21928U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23529U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23752U)) & S_BLOCK1], 54U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22897U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((aIndex + 22041U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 20U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 20U)) + 12122689833405846292U;
            aOrbiterK = (aWandererE + RotL64(aCross, 13U)) + 9640400270962766788U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 53U)) + 9141937998266739071U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 12899395770434090537U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 13457918115408031842U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 41U)) + 15134784483576000943U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 12540961268790055438U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 3U)) + 6306886773092764230U) + aPhaseCOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 46U)) + 13573343491337243121U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8545588657348974413U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10891410570357275120U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5399310978367842841U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2877137119767060151U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9178097682386595144U;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15528007881855616978U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11368419529245281435U;
            aOrbiterF = RotL64((aOrbiterF * 12433207037378339309U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5932738914934356645U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5551842263864055419U;
            aOrbiterH = RotL64((aOrbiterH * 16093776759971522681U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3824433359595690603U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17184628855571662441U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 691208053136187317U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8724462245014132623U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7481349499528092352U;
            aOrbiterC = RotL64((aOrbiterC * 8212182934509617583U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6908362960248294718U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5354057969992655314U;
            aOrbiterK = RotL64((aOrbiterK * 16586084885820679343U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11138301629323903147U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14164180536320940750U;
            aOrbiterB = RotL64((aOrbiterB * 9099767681053390287U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 709942920176922902U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17128241237359414945U;
            aOrbiterA = RotL64((aOrbiterA * 14063385518459963529U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 26U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 46U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 52U));
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26522U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 25912U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25202U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneB[((aIndex + 25966U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25535U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25889U)) & S_BLOCK1], 18U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27197U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 24816U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 38U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 3612110001869385068U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 29U)) + 16340824141280225936U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 39U)) + 15222338965130765231U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 47U)) + 6649270508107155041U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 13U)) + 768217258655426384U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 34U)) + RotL64(aCarry, 37U)) + 4481855259658861851U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 18318041934562434016U;
            aOrbiterC = (aWandererH + RotL64(aCross, 21U)) + 4212457153804401807U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 51U)) + 16143621095636987628U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2095664232866642086U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4339527736737366572U;
            aOrbiterA = RotL64((aOrbiterA * 17503569508822244125U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13679353177869884790U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11582168502846418236U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 135539430034462861U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10451330452898542191U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12951448817640617841U;
            aOrbiterC = RotL64((aOrbiterC * 4141870904192742091U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15389161934419370747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4754886272708253014U;
            aOrbiterD = RotL64((aOrbiterD * 16638243718191281597U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11746389873929280688U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12042680172517298768U;
            aOrbiterB = RotL64((aOrbiterB * 3814780289755857543U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2648103752465009244U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 451594673632597973U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8496763663271072425U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5696534794094099710U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14609435045257077395U;
            aOrbiterI = RotL64((aOrbiterI * 14658408563237468407U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11599395126850950133U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12699598504604446664U;
            aOrbiterG = RotL64((aOrbiterG * 14313494063098111823U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9398465148537154745U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12139736860648011256U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15257503229375247987U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterB, 4U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterK, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28836U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 28967U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29974U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((aIndex + 27813U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28579U)) & W_KEY1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27635U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27516U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 27753U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 26U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 27U)) + 15920462086654025436U;
            aOrbiterK = (aWandererI + RotL64(aCross, 53U)) + 487844076858004017U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 14502883786442630566U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 11U)) + 3787107318658233674U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 12548777544693755491U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 39U)) + 4907309444075181683U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 57U)) + 18342396700266492072U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 23U)) + 13503051997624242670U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 17845742460521374571U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8640887211877858169U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5273913123709097537U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1661149444148461791U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17756844173695563883U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6713055830729302951U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5106468334224035972U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10228769728713526172U;
            aOrbiterK = RotL64((aOrbiterK * 9760310686414358435U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7687649520668883142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7757480627354711605U;
            aOrbiterI = RotL64((aOrbiterI * 7222553727737349209U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10876291698508634557U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8149278085586014186U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8577133863470695381U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15592893988925610485U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8639028256640537165U;
            aOrbiterD = RotL64((aOrbiterD * 1880655276432963955U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 475660347892196219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1903736092401853832U;
            aOrbiterH = RotL64((aOrbiterH * 8486318978769094799U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12463250192809450953U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7253918448601703982U;
            aOrbiterJ = RotL64((aOrbiterJ * 3821034106528009129U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5171661020093804486U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11627344933828324146U;
            aOrbiterC = RotL64((aOrbiterC * 5388047063152043277U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 34U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 18U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32536U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30731U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30840U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30449U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30130U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32373U)) & W_KEY1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 10U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 15726877954695761686U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + 14187652171881943587U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 8420423151313882782U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 58U)) + 14942322692433259283U) + aPhaseDOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 7272331475919796255U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 5U)) + 154504365041805840U;
            aOrbiterB = (aWandererC + RotL64(aCross, 11U)) + 17475491222554948786U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 21U)) + 5759181483165339605U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 5U)) + 5993060214499322845U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10901786237875941844U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17135786595614068473U;
            aOrbiterI = RotL64((aOrbiterI * 15923538730142047043U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5208202073886811165U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6821452921018900631U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13119330055184115669U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13348064837402206969U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8967943922403445136U;
            aOrbiterB = RotL64((aOrbiterB * 300168481725373093U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8130283784171430891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6351113882502502876U;
            aOrbiterC = RotL64((aOrbiterC * 15960622823993072903U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6894708729226455769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12065058511247133944U;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17138279326229372741U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12987698199066890628U;
            aOrbiterA = RotL64((aOrbiterA * 12665716655177320977U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13688833537574196675U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4211971980434000618U;
            aOrbiterF = RotL64((aOrbiterF * 1374411763361518851U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10376917117582537592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4807742522197923516U;
            aOrbiterJ = RotL64((aOrbiterJ * 15257251453302090961U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18038296468177121243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6879666349379745258U;
            aOrbiterE = RotL64((aOrbiterE * 15819475269715810555U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterE, 19U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Karate_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1586U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 1031U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 4725U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3712U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2222U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 13U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 19U)) + 4204560462077827182U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 43U)) + 6572370199668594039U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 36U)) + RotL64(aCarry, 11U)) + 15958999876732622825U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 9969349486879280377U) + aPhaseEOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 29U)) + 15450238998293956181U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 11U)) + 9128619863683138259U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 5691270563628979565U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5901029710568933106U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10442738941988588834U;
            aOrbiterA = RotL64((aOrbiterA * 7386621444831603817U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3508116020325721993U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13221917083569767259U;
            aOrbiterD = RotL64((aOrbiterD * 6845108555710135357U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11627915460377128176U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17858261365514253433U;
            aOrbiterC = RotL64((aOrbiterC * 7535577636975884641U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4294837988806295989U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11242915481585070249U;
            aOrbiterI = RotL64((aOrbiterI * 17540688242763829319U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13030663829236027109U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7451948220723185149U;
            aOrbiterF = RotL64((aOrbiterF * 5191778587712222029U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5575508866505031037U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5161096033789876794U;
            aOrbiterG = RotL64((aOrbiterG * 16843827915802461797U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3980482740649505122U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11188906150207270241U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 408550837615188413U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 40U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8359U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 5968U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8293U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6655U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 8509U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 13U)) + 17074147006464019918U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aIngress, 3U)) + 10559516626129419928U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 13280363679503946221U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 17657115422132457413U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 22U)) + 13325837013304973008U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 3059707750486106037U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 4529045702503050852U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10726578475550904292U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14832537837996659885U;
            aOrbiterD = RotL64((aOrbiterD * 808060368961520519U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 220094417441809246U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15343130035105342194U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7984652435043810845U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16592263353426409884U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15649290906447931918U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8405875177836650731U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11437410545843708269U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5859769136073011444U;
            aOrbiterJ = RotL64((aOrbiterJ * 1065016088086441107U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15188064100307340341U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4367466521843260049U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15916715854192820923U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8482617283860566845U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2585745804937342972U;
            aOrbiterA = RotL64((aOrbiterA * 8267269625632139809U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1687641344403425541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13667916445979421400U;
            aOrbiterG = RotL64((aOrbiterG * 8191322670355590027U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 60U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseEWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13969U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 12389U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11276U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16068U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13069U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12799U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 24U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 39U)) + 15036852811491820366U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 13U)) + 305637140752898475U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 11948631574496129610U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 43U)) + 5321623592482991426U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 47U)) + 4075270159062690728U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 53U)) + 15111580500356908928U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 7244150695504160363U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5131563519577488862U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5881954992088651371U;
            aOrbiterI = RotL64((aOrbiterI * 2424421828597294607U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12780935808751507998U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12599159643925470226U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17690046932587062701U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9466589929741834066U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6093158735705189789U;
            aOrbiterJ = RotL64((aOrbiterJ * 7453778295800853653U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17461243886150519249U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15456408913739900718U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11260643903290392780U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7870342756041882616U;
            aOrbiterC = RotL64((aOrbiterC * 2431528656086173419U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 134484990005888936U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10626896209992890407U;
            aOrbiterB = RotL64((aOrbiterB * 12034131076645285597U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14031164129515132292U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1771835705730244212U;
            aOrbiterF = RotL64((aOrbiterF * 186981668443596623U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 36U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19147U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 21174U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21262U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20717U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17358U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16867U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 826930775230515406U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 5137814617363250861U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 53U)) + 14761561947426681616U;
            aOrbiterC = (aWandererC + RotL64(aCross, 34U)) + 12773023438753662590U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 5U)) + 7331345852207096322U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 3899381212671247460U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 21U)) + 10072004147620068599U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3424585039401897560U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8246760141625966321U;
            aOrbiterH = RotL64((aOrbiterH * 11478879365443736383U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3655992860610853290U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11154618022505863898U;
            aOrbiterJ = RotL64((aOrbiterJ * 4791494171286145231U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15629361991059709973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10842068502278489664U;
            aOrbiterI = RotL64((aOrbiterI * 17223002513104960799U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5571312349016336686U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 589313823745748879U;
            aOrbiterD = RotL64((aOrbiterD * 1356685926549786027U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13633457935771935260U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12684602052812183096U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5711307583717354204U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7181854170553728211U;
            aOrbiterC = RotL64((aOrbiterC * 9835601115561325911U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1884620014396115821U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1471516373272364262U;
            aOrbiterG = RotL64((aOrbiterG * 5126319375714848029U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + aPhaseEWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterF, 28U)) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26954U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 26779U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26377U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27011U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24595U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 23498U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 42U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aCross, 57U)) + 2571116506511057880U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 13112435411509707292U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 41U)) + 10403251762787357256U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 8461951095541400405U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 27U)) + 9890793478557463815U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 3030229465991783707U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 10U)) + RotL64(aCarry, 19U)) + 7273848154043719247U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10681774862516028276U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7105082755586853104U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12217705329504230357U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6588579345319551129U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14616333550242386092U;
            aOrbiterB = RotL64((aOrbiterB * 2934574715879306337U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15439666290229654921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3360304356760164799U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14438730801970761889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14515616787452085729U;
            aOrbiterD = RotL64((aOrbiterD * 2041601927968559821U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4167853822635132419U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8950982233003320239U;
            aOrbiterE = RotL64((aOrbiterE * 887144270884244907U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12391327853728029953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7100871010552394421U;
            aOrbiterA = RotL64((aOrbiterA * 16552349374101955967U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15381697462381887944U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6801677551341079401U;
            aOrbiterI = RotL64((aOrbiterI * 13325954438427340703U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31000U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 32598U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32113U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30208U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30094U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27574U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 11U)) + 12849591986267890852U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 8232614804696815750U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 27U)) + 12141567259210877281U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 19U)) + 2928641981037885644U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 980733350554783938U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 2683985177993350746U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 14532148403815527355U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7736296629433884203U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10428437770166310549U;
            aOrbiterD = RotL64((aOrbiterD * 326634742742373401U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18327174144859461029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6810436935194432002U;
            aOrbiterH = RotL64((aOrbiterH * 2715987179577753597U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12606153309690753435U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17123256945895150555U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9057777759026189541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16478485918911194442U;
            aOrbiterK = RotL64((aOrbiterK * 11054247078884894131U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18064460487552100483U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11477276762421684083U;
            aOrbiterA = RotL64((aOrbiterA * 3886501230380184395U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18318375441973295081U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13849305985380030986U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12962140243967824959U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10240409420338313641U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 18360586077779529086U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18196875422391501927U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 34U)) + aOrbiterF) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Karate_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneA, aInvestLaneA, aExpandLaneC, aSnowLaneB, aExpandLaneA, aWorkLaneA, aInvestLaneC, aWorkLaneB, aExpandLaneB, aWorkLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3652U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 393U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1039U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5264U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3874U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3339U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 35U)) + 6361545377408870615U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 51U)) + 2967245486744774933U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 3U)) + 3836634268482850139U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 7691642115360086297U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 23U)) + 16479280384178279281U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 2901468732552539249U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 27U)) + 2600353867755647475U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 37U)) + 5666596904781510956U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 6U)) + 16108791609267427553U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 8389926875737312112U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 11U)) + 1689501721163024426U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11721701506949917719U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3963842745030140473U;
            aOrbiterG = RotL64((aOrbiterG * 6692473494944919373U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8510538243472109368U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 18281865214102080387U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1351546966368884609U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2259725140963665123U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11652011949557979650U;
            aOrbiterJ = RotL64((aOrbiterJ * 11260100762113295037U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1116085424226174473U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4725260319270802912U;
            aOrbiterK = RotL64((aOrbiterK * 4697109059565450269U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7348945429843437036U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1249234309180653260U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3136745255820405881U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12463505532573389603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2304125977906510386U;
            aOrbiterB = RotL64((aOrbiterB * 9960816714791454421U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2178037443783425551U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11712110130079307683U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9797864956200779505U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10703510612147312252U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18155460326242413483U;
            aOrbiterE = RotL64((aOrbiterE * 6903953708987478723U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5753486645345036069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2314216774606770444U;
            aOrbiterH = RotL64((aOrbiterH * 14002639533287566667U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9662599462788305323U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3805101172359199209U;
            aOrbiterD = RotL64((aOrbiterD * 10669315962181581543U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1073926575064224947U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6361545377408870615U;
            aOrbiterA = RotL64((aOrbiterA * 10685650563722188837U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 10U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 48U));
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 36U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9900U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 9420U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9084U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 8150U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7589U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5822U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 8028U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 22U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 12027839670755583592U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 60U)) + 15380130703509859843U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 4590907433867798074U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 1754574023602519724U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 5U)) + 9832756659564903767U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 43U)) + 5035088494491470403U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 13U)) + 14199170923323644638U;
            aOrbiterA = (aWandererD + RotL64(aCross, 53U)) + 8325619421264440438U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 51U)) + 969534320779067977U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 48U)) + 270575869402913847U;
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 13344806516599578910U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15143147951139409101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14425582489214169238U;
            aOrbiterG = RotL64((aOrbiterG * 16893787086337916355U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13951127523239064584U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14177925225918293579U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13079514031864998485U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8258920744278218901U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7408161179397242453U;
            aOrbiterK = RotL64((aOrbiterK * 975737128100519169U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8581481606764773468U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10078416198417433133U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1102721083915858247U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18299772198826189580U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18304668908084397946U;
            aOrbiterD = RotL64((aOrbiterD * 10589455451200578687U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16729632621573817223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13362300981585573239U;
            aOrbiterJ = RotL64((aOrbiterJ * 9824473895535518785U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8629682832849915380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6852852009091469641U;
            aOrbiterI = RotL64((aOrbiterI * 11912646687050011915U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7433098156961745198U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10931806208899417308U;
            aOrbiterA = RotL64((aOrbiterA * 14699197041038067483U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 629604718211675247U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1487372736719237118U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 705192821277928909U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3567439893461603384U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11143068753134694333U;
            aOrbiterF = RotL64((aOrbiterF * 15529326960229305389U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14242098279913980463U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12027839670755583592U;
            aOrbiterE = RotL64((aOrbiterE * 6630014752150544153U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 18U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 40U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 56U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 39U));
            aWandererK = aWandererK + (((RotL64(aScatter, 42U) + RotL64(aOrbiterH, 10U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12106U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 12056U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12611U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11920U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((aIndex + 11348U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 38U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 39U)) + 12775735908960052604U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 11791373812080296887U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 41U)) + 5537362877706057303U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 2023912048504189380U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 17668828109963766893U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 3U)) + 558908629933941224U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 53U)) + 1479633119685446888U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 57U)) + 15460320397843364063U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 29U)) + 10059749397555469054U;
            aOrbiterK = (aWandererI + RotL64(aCross, 26U)) + 9987633811929693924U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 21U)) + 10087337844580228269U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4446204415503364254U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15106063243302192717U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10611580584157624739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3137391249289641509U;
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9327201928815412810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10675114832750356941U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8804440385852327267U;
            aOrbiterI = RotL64((aOrbiterI * 8520671775587260601U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12871947817782057116U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11015991745792051390U;
            aOrbiterA = RotL64((aOrbiterA * 17152451500505815031U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6320437975845673731U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 702457937087191287U;
            aOrbiterD = RotL64((aOrbiterD * 17491257114676739589U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16629064896250312921U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6054107387816339103U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6983767878966747219U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13274874838094190290U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12211422735294360321U;
            aOrbiterH = RotL64((aOrbiterH * 5113738196151089817U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15338616110718583619U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1475787183754511373U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10904607643785840003U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15486810401396777742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12775735908960052604U;
            aOrbiterE = RotL64((aOrbiterE * 7478156942468930207U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 52U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 60U));
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 24U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 38U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17472U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 17474U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20312U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17994U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 21042U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 3U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 12980104182836602177U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 3172622203188863995U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 13U)) + 1170974132219980203U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 43U)) + 6035201940965047490U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 11U)) + 18033907118424996722U;
            aOrbiterC = (aWandererB + RotL64(aCross, 60U)) + 14604813424800580304U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 21U)) + 13720232492851066035U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 3902659710585257448U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 8331560652661619868U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 54U)) + 4485014147538689794U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 47U)) + 168202636924512424U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16227825670092707848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4792781933944671365U;
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12636865372722601282U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18198291399585556632U;
            aOrbiterC = RotL64((aOrbiterC * 18155803890313399795U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3650053185419807206U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5897288963905408776U;
            aOrbiterF = RotL64((aOrbiterF * 3706949366974086151U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9922308113622901726U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13352279749091561510U;
            aOrbiterI = RotL64((aOrbiterI * 4025213180483632557U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14969461950939646117U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10231661776135056651U;
            aOrbiterD = RotL64((aOrbiterD * 11284575051455238501U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10621934544068320859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6029116920305246887U;
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12887482425168671195U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8351351557123783853U;
            aOrbiterK = RotL64((aOrbiterK * 3839381627914762245U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5405938210926464973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 385145802287899406U;
            aOrbiterG = RotL64((aOrbiterG * 8330751480464271445U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7907749190875916461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5138733192253468642U;
            aOrbiterA = RotL64((aOrbiterA * 17028325976353263843U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14382272868178763187U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14354777100157531233U;
            aOrbiterJ = RotL64((aOrbiterJ * 7095764230272037767U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4390647647193363824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12980104182836602177U;
            aOrbiterB = RotL64((aOrbiterB * 11124472075872147333U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 60U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 41U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterE, 6U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 53U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 27222U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 22243U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22191U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24792U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 27180U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aCross, 39U)) + 5088525177670191619U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 11U)) + 9966456257813932112U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 48U)) + RotL64(aCarry, 3U)) + 7707646574027146307U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 13U)) + 75480203757681173U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 21U)) + 384659134071835163U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 3158769775373307778U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 17360830943513941272U;
            aOrbiterD = (aWandererE + RotL64(aCross, 41U)) + 5317278822721604586U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 1371427105215954781U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 37U)) + 3162710551223553423U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 58U)) + 5332921933853550756U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10572462410297815854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10234389605554817892U;
            aOrbiterA = RotL64((aOrbiterA * 2130374833440291193U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13421365517991380605U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10186643614984034083U;
            aOrbiterE = RotL64((aOrbiterE * 8554471709467808453U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4742438973260817120U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6081590345899008846U;
            aOrbiterI = RotL64((aOrbiterI * 7069396301823124931U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15360092808493795340U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12186413069553132646U;
            aOrbiterF = RotL64((aOrbiterF * 3815981440611914267U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16756221656224451552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12232880965861373143U;
            aOrbiterD = RotL64((aOrbiterD * 14196910735715726471U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10090954323470840557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15615770271463853537U;
            aOrbiterB = RotL64((aOrbiterB * 13544181592829027283U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 556029032505658411U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13311879111583579039U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3924744868168749003U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8646360871497847336U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2064833941982069154U;
            aOrbiterH = RotL64((aOrbiterH * 10016546852137913163U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1701847261278886621U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9654208200019718374U;
            aOrbiterJ = RotL64((aOrbiterJ * 4398089490129603677U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14276143262844412074U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10738184916176200661U;
            aOrbiterK = RotL64((aOrbiterK * 8940267914440361883U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2966052720680305600U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5088525177670191619U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11621585388684456139U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 48U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 18U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 50U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29559U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 30060U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32239U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28620U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27863U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 4773124477323378268U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 16848723289435796005U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + 13846642134917107058U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 6472057872482789939U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 24U)) + 2747019500690707226U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 41U)) + 9003965289739733880U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 3013390651936257377U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 29U)) + 3331004709895625067U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 27U)) + 15355010435553517129U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 54U)) + 7709870658004280052U;
            aOrbiterK = (aWandererE + RotL64(aCross, 11U)) + 13568728443963926564U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12409548853419307131U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 969183352023661537U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15370309834426476775U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3896803894396631184U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11018830202891911603U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10848873633291935766U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12885336509190543440U;
            aOrbiterF = RotL64((aOrbiterF * 1487357252619221365U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8252290890093788010U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9201553615601641350U;
            aOrbiterB = RotL64((aOrbiterB * 420321130559162915U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14014209645503188472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4015071464301844550U;
            aOrbiterA = RotL64((aOrbiterA * 17444195018239904971U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16173085647514027347U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16916627014974363360U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7699587344277490953U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1591680303404522110U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16499606051269327916U;
            aOrbiterG = RotL64((aOrbiterG * 814405848002794813U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6932673635509444619U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8745681160108707944U;
            aOrbiterK = RotL64((aOrbiterK * 14565255558668084787U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10387263947888920455U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2553335462317280031U;
            aOrbiterH = RotL64((aOrbiterH * 7253573275397985211U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17449861295444216249U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15716408844914738774U;
            aOrbiterC = RotL64((aOrbiterC * 10132631423215542589U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16974370193820578179U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4773124477323378268U;
            aOrbiterD = RotL64((aOrbiterD * 8982190762960590543U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 30U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterK, 48U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 38U) + aOrbiterK) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererG, 52U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Karate_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aWorkLaneA, aWorkLaneB, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 314U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 786U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4120U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7318U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7086U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4780U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 56U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 58U)) + 16424657151168221875U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 17150123681886380361U) + aPhaseGOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 16041993588694572757U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 23U)) + 9871185846434828537U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 11227236398354430757U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5399325217402192631U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9248828789282890454U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6733832755349139621U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9041370494203701062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14944424084524970764U;
            aOrbiterJ = RotL64((aOrbiterJ * 10283363059424655079U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5481938174456671041U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14783648629543752715U;
            aOrbiterC = RotL64((aOrbiterC * 7260164783191886395U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12355573914530445723U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9863991559011968318U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8495251211794343179U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16149688605937250965U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 106041828692026825U;
            aOrbiterG = RotL64((aOrbiterG * 12199934305374582599U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 14U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 44U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13355U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 10552U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 15195U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13093U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15595U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11859U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 4U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 13U)) + 1866656689936219099U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 2312314528139448289U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 47U)) + 3554037526469185237U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aIngress, 34U)) + RotL64(aCarry, 51U)) + 405707755060974111U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 1862976326004007697U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12992483065443288263U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3793854946371595197U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1819119223110966487U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4244007978867369382U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10280867500312580308U;
            aOrbiterK = RotL64((aOrbiterK * 13729899124177931289U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 472563452959164242U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12041770406895816553U;
            aOrbiterC = RotL64((aOrbiterC * 17811798500132002631U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6118634015704900486U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13637107920449233307U;
            aOrbiterF = RotL64((aOrbiterF * 17712028184714868053U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16673735670669318830U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8602681273646630496U;
            aOrbiterI = RotL64((aOrbiterI * 6995213887710749241U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 38U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 6U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22460U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 17255U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 17825U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18905U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22735U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17501U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 16462052553719977502U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 60U)) + 12337064059566619581U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 11U)) + 15801005007094515447U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 8228706742665081656U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 11006723027845190869U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18173765337829177450U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 530215083653542558U;
            aOrbiterD = RotL64((aOrbiterD * 8938680024265564887U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6608611827035564511U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2246051826221626809U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6333352641495253539U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5228575308895381421U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10999213210689606857U;
            aOrbiterE = RotL64((aOrbiterE * 5467601259546342925U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3773371037240485696U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8887985779436152504U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 698713082830739677U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11150566414723818350U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8336366151003049546U;
            aOrbiterF = RotL64((aOrbiterF * 9033771197242493699U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterE, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25339U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 27465U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31907U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28861U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28295U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 28163U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 52U)) + (RotL64(aCarry, 37U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 47U)) + 18191288703716505885U) + aPhaseGOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 9824014524910417136U) + aPhaseGOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 19U)) + 11953012029254917548U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 6297568011027199089U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 43U)) + 2576999400457367975U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13176139160575558254U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9978408174563621810U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1399052522159751531U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16765834875061607142U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16534507305459121344U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8943988574248229067U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3114710944346151807U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10240517868726718592U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4645691562915606463U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10721450637990777883U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16689590768796583952U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3046344179729901637U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2427422768928450209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13495584061816457831U;
            aOrbiterH = RotL64((aOrbiterH * 6670984773768885119U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aPhaseGWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 36U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Karate_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5950U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 3370U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 6951U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6472U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 898U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4465U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 43U)) + 8975885703279267062U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 19U)) + 8664844915562660637U) + aPhaseHOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 35U)) + 12281774799736296726U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 15347461352311329726U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 12967500561828907834U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5002833859280402726U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11908257536954668983U;
            aOrbiterI = RotL64((aOrbiterI * 4384790916151202785U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17017174811949227162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16851323125613931180U;
            aOrbiterE = RotL64((aOrbiterE * 12446990992858763577U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13469326957728686706U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5228638551056105241U;
            aOrbiterB = RotL64((aOrbiterB * 13369947664646167255U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11945166198089308564U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16268645041872996022U;
            aOrbiterD = RotL64((aOrbiterD * 5391448793718370911U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14781204627695095701U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5365325354838101092U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8017284997946310807U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9406U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 9697U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 12779U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9139U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12164U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 10876U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 47U)) + 3917730204724097072U) + aPhaseHOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 39U)) + 1874642340716212824U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 6900165757434854160U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 12750946097023807161U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 6563216048479513594U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14960240191349450795U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16306180275951788289U;
            aOrbiterD = RotL64((aOrbiterD * 12077366095522790283U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6502066618271045547U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6219852857850888738U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10892297250334325283U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2272931312452845850U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3028929882263199463U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11005324285856805069U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6067393030073568112U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10094809900437037258U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18095564940730322769U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5962414178157074575U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15755563045799129417U;
            aOrbiterF = RotL64((aOrbiterF * 3692603590609922031U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterD, 38U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16680U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 19342U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 18548U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20583U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20794U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16642U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererG + RotL64(aScatter, 36U)) + RotL64(aCarry, 37U)) + 7948891781097675369U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 13U)) + 13928362874228230226U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 53U)) + 10776180542602258926U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 5735115172149470447U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 5353591822981766987U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 562301708107268570U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10467810247578364868U;
            aOrbiterE = RotL64((aOrbiterE * 10449089554007059823U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14541630141152308564U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2350076897065139429U;
            aOrbiterI = RotL64((aOrbiterI * 12222554362482034393U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17519109078651162228U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6061035173339902910U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10021905773432907835U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15654836633731000065U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13723521735153718904U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2849680038315532197U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17336102435576647923U;
            aOrbiterK = RotL64((aOrbiterK * 10984689101753586739U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 60U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + aPhaseHWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 14U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24644U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 29116U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 31797U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25531U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30091U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25206U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 3U)) + 12669015908335980355U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 5438715179868613192U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + 13172104448184536460U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 13421421503244744803U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 26U)) + RotL64(aCarry, 57U)) + 13327113302994856582U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4671768205922454413U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5355759962838579929U;
            aOrbiterJ = RotL64((aOrbiterJ * 15080379163499722187U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6691720614265406851U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7063906424700911378U;
            aOrbiterK = RotL64((aOrbiterK * 17091734375516280675U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17328616394166672263U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1542940602574207068U;
            aOrbiterD = RotL64((aOrbiterD * 8981679306319627975U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7203866278803132454U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 993485696233139264U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11609009908810366447U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15659679028507488331U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18321361454094675842U;
            aOrbiterF = RotL64((aOrbiterF * 3966860765622641843U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 52U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
