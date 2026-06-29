#include "TwistExpander_Soccer_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Soccer_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC43BF932E7C3258FULL + 0xBA041A01BD4B9089ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB8553E11BD91667FULL + 0xFF6DAC4A312D2437ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFFA591F4D374BE1FULL + 0x9127BA14A0D6265CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB79FFDC57554CC07ULL + 0x89B1E298D7886B27ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFB640E72D958C069ULL + 0x8C9AD380D3166F9CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD20B5124F346A82BULL + 0xCD551F8D0238CAEFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB74CDD1453F5C66FULL + 0xA4948AF55CB20E6FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x84467ACDB6376AA5ULL + 0x8998AF8E259465E8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA470630DA7DC0845ULL + 0xCE3949D738D63875ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB83DA3C5FB270131ULL + 0x871EA7F079116338ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBD0988DD9C85BE4FULL + 0x8CA577B879F1186FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8BE789D1ACE29145ULL + 0xCD0CA2CB4197D3ADULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC12A4A369A2AA623ULL + 0xAC9C5C1EB77A3168ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC4E3ADD087AD349DULL + 0x903DBFF7958CC80AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB00DA11F7C829DD3ULL + 0xBB4A6487DC3FFACEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA37EE1F0687630E9ULL + 0xF6CFEA21EFEC770DULL);
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
            aIngress = RotL64(mSource[((aIndex + 329U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2909U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2356U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 1504U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 60U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 11U)) + 9914837590440975587U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 6706125076401958051U) + aNonceWordP;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 39U)) + 16570817772679258409U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 47U)) + 6843705658115186948U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 30U)) + 16099930446791572351U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 37U)) + 5420550009556030459U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 5729549069420177477U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 5U)) + 15590601126188675834U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 13U)) + 13044027390998620029U) + aNonceWordM;
            aOrbiterF = (aWandererE + RotL64(aScatter, 21U)) + 11068338135659636772U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 6584988841809544332U) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8516813219883915404U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10647314042912492785U;
            aOrbiterA = RotL64((aOrbiterA * 15559481057047148785U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 201691689889605304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3883760518944464145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterH = RotL64((aOrbiterH * 17194438894492581181U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12019138626550801486U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11724200983306280107U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2643807255422544248U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4127143302485631794U;
            aOrbiterB = RotL64((aOrbiterB * 5441038881111578487U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14602951930809633069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4555737199162278494U;
            aOrbiterE = RotL64((aOrbiterE * 12415825635220991865U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6343143902997169834U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10404783711336491985U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6235474458879439079U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7406959231434835393U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6684368109277850196U;
            aOrbiterC = RotL64((aOrbiterC * 8760360417572331159U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4835889355927954728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7917682889852676712U;
            aOrbiterF = RotL64((aOrbiterF * 9045350756570117327U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10268055422944417055U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5563744562922937643U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 12442484191329795173U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17244672945880141679U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9914837590440975587U;
            aOrbiterG = RotL64((aOrbiterG * 12269340309792850489U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 47U));
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterC, 50U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + aNonceWordO);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 42U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 52U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterB, 5U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 7117U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 5915U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7452U)) & S_BLOCK1], 47U) ^ RotL64(pSnow[((aIndex + 7159U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 11U)) + 11210042748013785976U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 47U)) + 4584747303233477454U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererK + RotL64(aCross, 27U)) + 8878765929792969517U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 2172232330280041122U;
            aOrbiterG = (aWandererE + RotL64(aCross, 36U)) + 8378937026022264016U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 57U)) + 8683007464695824208U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 29U)) + 9564352997357118134U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 13U)) + 11713878436769887528U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 38U)) + RotL64(aCarry, 39U)) + 8052917623074021077U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 7720597162792145185U;
            aOrbiterK = (aWandererG + RotL64(aCross, 41U)) + 2602847785328475621U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17813669222300509724U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8724263063156573013U;
            aOrbiterA = RotL64((aOrbiterA * 3632927017737834359U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6882429835961613492U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13213313479525717359U;
            aOrbiterI = RotL64((aOrbiterI * 2411431247725974895U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2401526093648669573U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3616448566579979749U;
            aOrbiterG = RotL64((aOrbiterG * 13323155103752121393U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18268262471839710401U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5116424918948694752U;
            aOrbiterB = RotL64((aOrbiterB * 7641143782996332069U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11405305689555640431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12427591396711015574U;
            aOrbiterF = RotL64((aOrbiterF * 8112834135715541223U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16960781161508084626U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12382604781005282628U;
            aOrbiterE = RotL64((aOrbiterE * 17196168631120103115U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10054839091354729292U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4167641616532985407U;
            aOrbiterJ = RotL64((aOrbiterJ * 919291747187787625U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14383737233143309039U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16258779988369405932U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8348773195366160215U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4777263172049970723U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12498046021142146499U;
            aOrbiterC = RotL64((aOrbiterC * 5941015011162130901U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7435001955334177144U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4100235545173125433U;
            aOrbiterH = RotL64((aOrbiterH * 5046572784117638909U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1981704568071298614U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11210042748013785976U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17889749044418386565U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 60U)) + aOrbiterG) + aNonceWordM);
            aWandererD = aWandererD + ((((RotL64(aScatter, 46U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterA, 30U));
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterK, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 10924U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14086U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14963U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12859U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 51U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 10915618884692072446U) + aNonceWordL;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + 12634922308499254909U) + aNonceWordN;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 23U)) + 6533934734564499389U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 6744203303756105181U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 46U)) + 13086782386652045658U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 57U)) + 5693840533331397822U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 13U)) + 1803663542535024611U;
            aOrbiterI = (aWandererE + RotL64(aCross, 27U)) + 3597219300593287708U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 43U)) + 1429753448204448904U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 5U)) + 17229017825587322715U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 47U)) + 1137574712801062932U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2401991077004083378U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1332473247826139292U;
            aOrbiterB = RotL64((aOrbiterB * 15029831858261506447U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11730946340796899885U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15319163439700390962U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1349242001887975499U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4744141870145159917U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6067132201862688684U;
            aOrbiterI = RotL64((aOrbiterI * 6046100687757836027U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 14991509179286371800U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4342608825699398682U;
            aOrbiterF = RotL64((aOrbiterF * 10240526103933275875U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3727521409410742075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3302027219498304367U;
            aOrbiterD = RotL64((aOrbiterD * 12153634588200479559U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6039539483340398858U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2902581519976937051U;
            aOrbiterG = RotL64((aOrbiterG * 2057584328877854239U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12332784713738947242U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13761272577223712786U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 14930145045480030821U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2947946397617043735U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11107014023853644521U;
            aOrbiterJ = RotL64((aOrbiterJ * 15030903626191481831U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6212403196992771516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16107261731677426470U;
            aOrbiterA = RotL64((aOrbiterA * 13764822942405295129U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8414111492161335472U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3625937496991123221U;
            aOrbiterE = RotL64((aOrbiterE * 1736741235159600739U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5466667339391480293U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10915618884692072446U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 14719282928172086707U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterK, 60U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 42U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 57U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 34U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterF) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 19490U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16902U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 18255U)) & S_BLOCK1], 38U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20273U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18363U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 3U)) + 3684295017013759987U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 48U)) + 6740408842457292881U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 4563975890702399441U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 35U)) + 797804144825287940U;
            aOrbiterI = ((((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 2763779540450101303U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 13211846164102089685U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 58U)) + 15214578447281401982U) + aNonceWordN;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + 13745208628754232427U) + aNonceWordJ;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 5U)) + 17358621225969190747U) + aNonceWordP;
            aOrbiterB = (aWandererF + RotL64(aCross, 37U)) + 779739369960480023U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 13U)) + 4370963533701407813U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6061333005507739975U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3589705340762734456U;
            aOrbiterG = RotL64((aOrbiterG * 16499293983611196967U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10607697666369230567U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9356757995305239271U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10945513661439954731U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10093033335903048138U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11037328061699834100U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11189760551792389605U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 558431161176115540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17795680919453449358U;
            aOrbiterD = RotL64((aOrbiterD * 3910117359996283803U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6096779391116214109U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17594243286880690775U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 12655610181937429915U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 15414704802398002423U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18040588240488602196U;
            aOrbiterI = RotL64((aOrbiterI * 16344249573086571225U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14636298592697156931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9677305688594936561U;
            aOrbiterC = RotL64((aOrbiterC * 8354776999961642997U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16408025751875050713U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10018342878801454965U;
            aOrbiterK = RotL64((aOrbiterK * 10349132962708124117U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1841090936357114866U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16142637455878447020U;
            aOrbiterE = RotL64((aOrbiterE * 10565394571714418033U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4089676582910615502U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8749600984499831109U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3421055105090316521U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11408932421005107097U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3684295017013759987U;
            aOrbiterA = RotL64((aOrbiterA * 7037953759624065417U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 4U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterE, 48U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 26385U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 21935U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25584U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26687U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24585U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 25086U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 11U)) + 826930775230515406U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + 5137814617363250861U) + aNonceWordB;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 19U)) + 14761561947426681616U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 12773023438753662590U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 60U)) + 7331345852207096322U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 3899381212671247460U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 10072004147620068599U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 21U)) + 3424585039401897560U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 13U)) + 8246760141625966321U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aWandererK + RotL64(aScatter, 58U)) + 3655992860610853290U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 47U)) + 11154618022505863898U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15629361991059709973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10842068502278489664U;
            aOrbiterJ = RotL64((aOrbiterJ * 17223002513104960799U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5571312349016336686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 589313823745748879U;
            aOrbiterH = RotL64((aOrbiterH * 1356685926549786027U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13633457935771935260U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12684602052812183096U;
            aOrbiterC = RotL64((aOrbiterC * 4689206269919806711U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5711307583717354204U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7181854170553728211U;
            aOrbiterK = RotL64((aOrbiterK * 9835601115561325911U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1884620014396115821U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1471516373272364262U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5126319375714848029U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 742739371092077733U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8075893317715227838U;
            aOrbiterG = RotL64((aOrbiterG * 11208274111743259795U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8179547722249281263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15305282712174742323U;
            aOrbiterB = RotL64((aOrbiterB * 7951986906055462929U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1430543231751281079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14585341768267283387U;
            aOrbiterA = RotL64((aOrbiterA * 313213844964269133U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8123889986027932297U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2081696191347150910U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 4869653441012615053U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10166788886199265936U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15927074835525735601U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 6747650218540675523U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6997764816848988590U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 826930775230515406U;
            aOrbiterE = RotL64((aOrbiterE * 9943232461538279601U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 58U)) + aOrbiterD) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 54U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 27634U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 32088U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30036U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31554U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29025U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30607U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 13U)) + 1457104756581596530U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 29U)) + 6127240317844622874U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 13U)) + 16492290056044189421U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 11U)) + 10963676850938416468U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 23U)) + 4872917367399752405U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 19U)) + 15218882377875616148U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 58U)) + 5934166612122118251U;
            aOrbiterK = (aWandererE + RotL64(aCross, 27U)) + 14215280930872003003U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 11428034799044600979U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 5453003654321728726U) + aNonceWordB;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 39U)) + 14273775120265649389U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 328723770018440271U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13032190719588211088U;
            aOrbiterI = RotL64((aOrbiterI * 13363368478932798315U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2386881543033598494U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1649501123340887116U;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16462401546754210583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1510579201823042227U;
            aOrbiterK = RotL64((aOrbiterK * 16287912400104043275U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 6889066000014251983U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11324594596597724357U;
            aOrbiterA = RotL64((aOrbiterA * 15344987814648586023U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12237796033168436537U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17306069670330000343U;
            aOrbiterE = RotL64((aOrbiterE * 3167451351403385259U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14197284538008811658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4754134852883071927U;
            aOrbiterC = RotL64((aOrbiterC * 3484427259538998699U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17201907781639753736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8318419319239859855U;
            aOrbiterG = RotL64((aOrbiterG * 10320390501983802091U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16012488623961565780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15583721012865354925U;
            aOrbiterJ = RotL64((aOrbiterJ * 10656414363201743961U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14680351201973315018U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14483973292275372321U;
            aOrbiterD = RotL64((aOrbiterD * 9279222721410811027U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16324317860030681248U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7038506963317910910U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2960451734542956767U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12767672960346001218U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1457104756581596530U;
            aOrbiterB = RotL64((aOrbiterB * 1560375242310194691U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 50U)) + aOrbiterE) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 30U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Soccer_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB86402F2890CBF85ULL + 0xC0EEDB168469F047ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCBA40F64F0C7DBFDULL + 0xCD072C7DF5C6437CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA736407D20B4F8B7ULL + 0xA68AF13CFD4FE8CBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCD609D1F52FC4435ULL + 0xA4325180AFC43D4CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFCEBECB215494383ULL + 0xAB3026C936D35724ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE450AA0005AFEA59ULL + 0x8EBE085B8CB08330ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE4F9EBCDF99678F1ULL + 0xD1E41FE06C5F13E2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x80F442B0CFF3B1E5ULL + 0xE48FF4A7B8D91BC6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9B7693BDFEE15211ULL + 0xCB454CBBB5DA4425ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9779A0EC0EC4C0E7ULL + 0x890F5DD97C22BB19ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF5D09DA31E2103B7ULL + 0x834C2278C02BE60EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9EA6D3B233C5C99DULL + 0x9008007CF87C744EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x85F5F71F34FF8403ULL + 0xBAF17C339F359D2CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8C6422FE287A745FULL + 0xD06F2FAFC26C3CE4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC5F3C4EA14E8D4C1ULL + 0xE7F3E613DFAD9F40ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEA11CEAB10CCF67FULL + 0x9FAB11872F2F2C55ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4805U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneB[((aIndex + 5816U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2184U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneD[((aIndex + 6764U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 36U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 13854738573712660276U;
            aOrbiterD = (aWandererG + RotL64(aCross, 60U)) + 16835460633412286294U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 5U)) + 6785859293758091931U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 126317283127992659U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 27U)) + 7568963536291415413U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 42U)) + RotL64(aCarry, 27U)) + 12294016745653004819U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 35U)) + 18269588932920281147U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 11U)) + 5872406424994751026U) + aNonceWordL;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 47U)) + 7764434758831474129U) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4804168969415573371U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 959601763507651280U;
            aOrbiterC = RotL64((aOrbiterC * 4647396592804833217U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9257644462479293048U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14332699366894494579U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10487012596470786004U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 612729229562321440U;
            aOrbiterF = RotL64((aOrbiterF * 11380387280507726003U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7845523921295625315U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12742115479740024747U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15578543510683986421U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10294667720904610944U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14369711143154904567U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13753005602288309379U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10918344717497681894U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14378638206724886404U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7077588188450008059U;
            aOrbiterA = RotL64((aOrbiterA * 485375960462924335U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8941870012851971932U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 15242087859620352399U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 4963002810455992839U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10395280254030875387U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6826595516076975980U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 6198886240333178001U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 56U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9278U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 14601U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9141U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15018U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15446U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 56U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 11U)) + 9855743441035905047U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 5U)) + 8426286937143990276U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aIngress, 57U)) + 7146752367170267002U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 12947210066678101726U) + aNonceWordG;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 43U)) + 15902163559925328965U) + aNonceWordJ;
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 8506649889346449469U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 39U)) + 8226286036430263052U) + aNonceWordI;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 2703047093452420216U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 18U)) + 6769351326360139560U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9857025533281333281U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 238297452132277585U;
            aOrbiterE = RotL64((aOrbiterE * 12974709749856065985U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7203572312072908931U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12497027346166575632U;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 473851890609048879U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1664484956453886047U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8566500756326590209U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4635095143004754116U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17695676150967345793U;
            aOrbiterF = RotL64((aOrbiterF * 5780416541584439301U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15628965269863402796U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9190117464399730235U;
            aOrbiterC = RotL64((aOrbiterC * 5586437438425999715U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17835918238346011086U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4398005402429282682U;
            aOrbiterJ = RotL64((aOrbiterJ * 14828737209913317463U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10902589938246551273U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15124274429081385923U;
            aOrbiterK = RotL64((aOrbiterK * 13524180348258805367U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8747233520702236018U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5445611443463112371U;
            aOrbiterB = RotL64((aOrbiterB * 10294109295823410447U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16296005217836151910U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6468336224317602364U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 7369779919748367133U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 30U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 46U) + aOrbiterK) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterF, 56U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 43U)) + aOrbiterF) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19567U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((aIndex + 24366U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24266U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20275U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22231U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21825U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCross, 43U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + 6771552164800695068U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 23U)) + 12131763371571322040U) + aNonceWordH;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 52U)) + 3326182381395522013U) + aNonceWordC;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 41U)) + 12288775097697156383U) + aNonceWordL;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 35U)) + 5195948373449796741U) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 14404044002250137144U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 11142382920035825426U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 56U)) + RotL64(aCarry, 21U)) + 2967149520256475485U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + 1470907369577818097U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9231668148004163910U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13078929163913892386U;
            aOrbiterK = RotL64((aOrbiterK * 7509829068700523627U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9485274692075657877U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12216951187543631673U;
            aOrbiterC = RotL64((aOrbiterC * 6571066246507310805U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6933334652581744234U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 17260276102423580920U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 7796879893790990605U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 387767848169714392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8597538259308082638U;
            aOrbiterB = RotL64((aOrbiterB * 4888054690557707241U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7996708724489146033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15357384191688149939U;
            aOrbiterI = RotL64((aOrbiterI * 9827691726832491373U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17739222908739454637U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1614322333281471170U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7063116837752240891U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4531604274893197209U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3453280714992341288U;
            aOrbiterF = RotL64((aOrbiterF * 8390029711127907805U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 116623650872661533U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6565636510115095988U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 9691897067492501177U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10303258439817808058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10917642773040237611U;
            aOrbiterG = RotL64((aOrbiterG * 10232856828372963363U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 50U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterF, 18U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 58U)) + aOrbiterF) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32006U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneC[((aIndex + 30237U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27275U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28779U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31483U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28790U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 58U)) + 3621877681473089725U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 51U)) + 4451752751536414717U) + aNonceWordP;
            aOrbiterF = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 11371625415377772117U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 6046792758881150619U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 47U)) + 8213166120394461682U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 11U)) + 4343156661140422645U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 47U)) + 11105271483234947905U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 37U)) + 348904609985341372U) + aNonceWordC;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 41U)) + 12924652822526858767U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7461211697358520287U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16551553555297890558U;
            aOrbiterF = RotL64((aOrbiterF * 16432952324635746293U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 11908056404140782995U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9147367258259948715U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8876461054692728610U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10546855952702525404U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10071104785895309677U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4748636139110443794U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 783046909529525098U;
            aOrbiterC = RotL64((aOrbiterC * 8969157702460927215U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16683965945838696665U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12385412690177109575U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 10795062772707143187U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8210546822184469023U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13146493623236979963U;
            aOrbiterG = RotL64((aOrbiterG * 13199947810161148155U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13857628148804187115U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7241297989337473475U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 16223448508809614229U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 773904571213804946U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7660676598236419707U;
            aOrbiterA = RotL64((aOrbiterA * 14467390638468925567U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16822672435156055469U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6514707119190640433U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7097496727567460535U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 34U));
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterD) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 30U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 28U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Soccer_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB8C683087C81A04FULL + 0xDF942A952D736C8CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC3BFC472A5C5223BULL + 0xFDD08194BB2EBF0CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEED4F0035B744857ULL + 0xAD97D7D8B841B33FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA9E3E9B7953D49AFULL + 0xFFF6E74910F9B564ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB802EDF7D6B6840DULL + 0x9A3848B692FCAD17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9CA4027BAEC53C19ULL + 0x825577211BCBFD5BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA9A0D52A7AF6B923ULL + 0xA6D27DD40F0F295DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x96D7B81821321A5DULL + 0xB8195F47EBA69894ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF31791AE8B202441ULL + 0xF3D451CC8FCABF19ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF5C322C293E004ADULL + 0xF6C3C6AC86658860ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x869B6445D84CBDC1ULL + 0xBDB2CA3B24D6E0C0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8B38120DC550106DULL + 0x96FDE1E90400F97BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x85F016C57B7BE0FFULL + 0xF6DDA41D619A1660ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8CFD6C76F1C63D15ULL + 0xA7973B11AAE594B8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8A2683369D8F3A55ULL + 0xC0EF9BB323A159B5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA68C00AD1455326DULL + 0xA8977EEE8A8576BDULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2750U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 1176U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6908U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3421U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4453U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 4739486756133131180U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aCross, 58U)) + 16089707555501328184U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 35U)) + 15310047330238536453U) + aNonceWordN;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 7901411596386834955U) + aNonceWordD;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 4357555491060982163U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15667085602825720102U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8520635334382269253U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7348648918661047791U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1772509779231068315U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15336170957886025677U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10996880551392077399U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8628770833489469980U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15469234024247246228U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8905266995119987947U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 10796430900884288328U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10660110397012853289U;
            aOrbiterD = RotL64((aOrbiterD * 9140007610912037461U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11202284258711214794U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17509491802893182994U;
            aOrbiterH = RotL64((aOrbiterH * 9329107599972703671U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 42U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 53U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + aNonceWordA);
            aWandererG = aWandererG + (((((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 43U)) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 40U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15296U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((aIndex + 11306U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9905U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10805U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13641U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 11072U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 39U)) + 13174219512651137892U) + aNonceWordL;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 39U)) + 2715455762789269341U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 1338018183235594313U;
            aOrbiterG = ((((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 16566866551729552930U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 27U)) + 6901845297307236726U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2476078302049201718U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15531109473927052260U;
            aOrbiterA = RotL64((aOrbiterA * 1078804000420970559U), 39U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 4087849380858572351U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5167830630098599644U;
            aOrbiterH = RotL64((aOrbiterH * 1982835131228146099U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7275995452428627217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14794340370010024117U;
            aOrbiterE = RotL64((aOrbiterE * 8779497557416568379U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8509217403041662849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2321522025240806996U;
            aOrbiterG = RotL64((aOrbiterG * 113568101672878697U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5676672952755594051U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 2304681269233504384U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterE, 6U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aNonceWordB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20831U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 22668U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22606U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20653U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17785U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16500U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 36U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 57U)) + 3448371607470865612U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 19U)) + 3743742913651580573U) + aNonceWordP;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 46U)) + RotL64(aCarry, 13U)) + 13069491287948807280U) + aNonceWordB;
            aOrbiterC = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 16872779275586545632U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 17945792656755062795U) + aNonceWordN;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 18199747196793731853U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15953311878379809513U;
            aOrbiterG = RotL64((aOrbiterG * 5476802169152352897U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 941268763494588338U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10090221530365796809U;
            aOrbiterB = RotL64((aOrbiterB * 14035236086292997613U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8335698093307607001U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6147498804734306100U;
            aOrbiterF = RotL64((aOrbiterF * 6904444049941211327U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5980246079567570090U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 4152167624425912978U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 10019421651535123573U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 14990418790239735916U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3418668387496597219U;
            aOrbiterC = RotL64((aOrbiterC * 12814077238529863119U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 54U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererI = aWandererI + (((((RotL64(aScatter, 52U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 5U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aNonceWordA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26495U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 27695U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25477U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28153U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25400U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25068U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25308U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 1087148170018530502U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 42U)) + RotL64(aCarry, 5U)) + 15530846874509311414U) + aNonceWordN;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 16987358651515511212U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 13U)) + 12504143181007924259U) + aNonceWordE;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 23U)) + 393322117322732418U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14325937299241887166U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 9395262907017475742U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 3442643798173589117U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13658510441418344769U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6410754322737005336U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6932217611373076391U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9257290738538818434U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7489828960857692286U;
            aOrbiterD = RotL64((aOrbiterD * 16519674788777989043U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 4118778591214588387U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16619215231168796563U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14876884956536265157U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11326283811003573430U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1865401866017614604U;
            aOrbiterJ = RotL64((aOrbiterJ * 8378326058282460073U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 52U) + aOrbiterG) + RotL64(aOrbiterA, 26U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Soccer_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE705FE130F31C94DULL + 0xB5ACA2171F83B4B2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC12683DD779156C1ULL + 0x858609A9614C59E6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC042BC2D43575873ULL + 0xAF080FAD8620F509ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCE0C4AEA7612A14BULL + 0xA2CB73727EC1DED7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC8B163189007117FULL + 0xFE210F927E7DFC8EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF94F1B50997ECC2FULL + 0x994BA37E537C84ABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x94FDCE3DCDF46A13ULL + 0x81EE05B07C212502ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB5C4EAE6C7575C31ULL + 0xB66CCD6AD1A6E8DAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCEEFAF13B1400723ULL + 0xE788723F6FE62230ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC9CE949496E0AFD5ULL + 0xCCB26C835797E7CAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8237876EF056792BULL + 0xD058EB25FA766577ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA32F320E012D26D5ULL + 0xCE74F3D9CC413F97ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF480B8D39FAD5301ULL + 0xCF6F9AFEC117B45AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF370D4E5C8CE8845ULL + 0xDFBBB2AE2EDFF381ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9948AB7DA4E2373FULL + 0xEC6F77623A95B9BFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD8C7080F594A981DULL + 0x8D09A428C160C3A2ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneA, aExpandLaneC, aExpandLaneD, aOperationLaneB, aWorkLaneA, aFireLaneA, aFireLaneD, aWorkLaneB, aOperationLaneC, aFireLaneB, aWorkLaneC, aFireLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1796U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 3981U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 1318U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3346U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4390U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 3921U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 52U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 9220392006207660113U) + aNonceWordG;
            aOrbiterE = ((aWandererB + RotL64(aCross, 37U)) + 11305018553489132882U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aScatter, 21U)) + 5860373868073513684U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 53U)) + 12319586170883987589U) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 14072333614354649021U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 9332158529453194608U) + aNonceWordC;
            aOrbiterG = (aWandererA + RotL64(aIngress, 29U)) + 3860569321145958686U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8119005668901240093U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13918259792880333239U;
            aOrbiterI = RotL64((aOrbiterI * 5441062406822088853U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6938856216758228704U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3960905839118710604U;
            aOrbiterC = RotL64((aOrbiterC * 16203746868670689793U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6043879193734253929U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15691425268831319195U;
            aOrbiterG = RotL64((aOrbiterG * 7189195135654636271U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14912209933584715274U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16180183395910618923U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3942858974766467849U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4966642362507707776U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6962226782462822861U;
            aOrbiterJ = RotL64((aOrbiterJ * 3647802407741095419U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12409120845092026295U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2302946450253872465U;
            aOrbiterE = RotL64((aOrbiterE * 7099576330777297911U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16118304388937163838U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 15968419034359049422U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 11736207775827080165U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 44U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 42U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9553U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 12770U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 8953U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8467U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15195U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15138U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 57U)) + (RotL64(aCross, 44U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererI + RotL64(aCross, 11U)) + 3199575576585871314U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererD + RotL64(aScatter, 21U)) + 2533378188975571824U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 6819782112558312658U) + aNonceWordN;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 47U)) + 12690060987724798497U) + aNonceWordK;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 7088375139715629606U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 17785618677423695666U) + aNonceWordA;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 5U)) + 1714999280296491277U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17611338506932491624U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6475727359297421201U;
            aOrbiterF = RotL64((aOrbiterF * 15133348244242438069U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2347744591204119530U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2739317903351401068U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15435029315209475631U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8663535261373274338U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8205245127823536479U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 13857005110466856439U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8916510616749754516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3944805940148512932U;
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14094751253118853302U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14094299829196076311U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6370012560657108493U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3940673811518673802U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3015106523254484839U;
            aOrbiterJ = RotL64((aOrbiterJ * 9655401190755573379U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15404103131982599922U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1828655763233900875U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13024358077740310049U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 58U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20131U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 16922U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22845U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17744U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17338U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 18795U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 53U)) + 17264605017518259932U) + aNonceWordP;
            aOrbiterK = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 15209184354580778643U;
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 36U)) + RotL64(aCarry, 43U)) + 3299527965014731384U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererI + RotL64(aIngress, 13U)) + 16293096431816127821U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 11031983436878828337U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 23U)) + 9188018632448236358U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 47U)) + 13420816400363406556U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2485063384097917101U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3089135816938128264U;
            aOrbiterB = RotL64((aOrbiterB * 8813152992957361153U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10730544971770435788U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10431767565618874806U;
            aOrbiterA = RotL64((aOrbiterA * 4723078464590561545U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14883796491656899074U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13465877783538483706U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 14311686051108108503U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13322163435314643713U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3307316600284371955U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 4950101626975919939U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18146616411403012772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8414050129421955787U;
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 12U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 27U));
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 21U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29835U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 28710U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27131U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32480U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27020U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 27489U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 51U)) + 8020711767807230555U) + aNonceWordG;
            aOrbiterF = (aWandererG + RotL64(aIngress, 5U)) + 15368693777246341570U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 43U)) + 5117523734225562401U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 13155269151097507808U) + aNonceWordE;
            aOrbiterG = ((((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 9879303753623578272U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 1165799257173794826U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 13U)) + 930641942062732091U) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11330571332221123153U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2862963158282518899U;
            aOrbiterK = RotL64((aOrbiterK * 13782195862525974199U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6019186399361476659U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1924419843785161958U;
            aOrbiterC = RotL64((aOrbiterC * 9485557122500346869U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 12618629043591380461U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9334176504266512405U;
            aOrbiterG = RotL64((aOrbiterG * 18239109235362925739U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16829692481030013551U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5604784396927022709U;
            aOrbiterE = RotL64((aOrbiterE * 2833893610883508353U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16124030106598549644U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16571659812830230677U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 4668250364992383549U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15171089673591843703U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2826755560293849328U;
            aOrbiterH = RotL64((aOrbiterH * 9397017963457655287U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9976785768283589291U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11845100564714691809U;
            aOrbiterF = RotL64((aOrbiterF * 4935139932585319251U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aNonceWordI);
            aWandererA = aWandererA + (((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 29U)) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 60U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 53U);
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

void TwistExpander_Soccer_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA7BA78D8A92E0B05ULL + 0xBBDCB9EF552224F9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x949328D60A3FA5D7ULL + 0xBC7DB0C174F31EFBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9D98441FABE40CB1ULL + 0xC81614696A6E2FCBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x863B70B91556A1E1ULL + 0xFC25441664AE6106ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF29F725018A7E2CDULL + 0xB9980E539E67F6B1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC6168FAC6C41FE0FULL + 0xCD2061901B15AADEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCABA2A5FF50BFE33ULL + 0xD1AC074EBB84EF93ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD64648AB9197B073ULL + 0xFB9F4F5FCA57C5B7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE7B01C7AA0312963ULL + 0xE6B7595666BB29DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFD90999D3A31072FULL + 0xFED445BE868D5A00ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB06E85CF708ADB33ULL + 0xD230364DDCB89475ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD5124BEE0E1CF8C5ULL + 0x82B68655007C31CAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9AB5D60FC6C7F7EFULL + 0xBC870C946B9B5029ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBDC96AECB98E2F31ULL + 0xAE8D50D90030D706ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCAD8C794E8E18049ULL + 0xDF58430D3D4ECADFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA7A60E22C6F143DBULL + 0xD01E787C8137F2DAULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneD, aFireLaneD, aExpandLaneB, aOperationLaneB, aOperationLaneC, aExpandLaneC, aOperationLaneA, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4511U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 2220U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3907U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7557U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 656U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3540U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 43U)) + 17081642665820489793U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 5U)) + 14468854040067229623U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aWandererA + RotL64(aCross, 35U)) + 2249450222593057429U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 14964389079511378664U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 17003491054252360650U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 22U)) + 12710882240582032588U) + aNonceWordP;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 9887078182156755359U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7665284531810584704U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7304284015511876717U;
            aOrbiterH = RotL64((aOrbiterH * 6193179739025093929U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 5517927023543751734U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17704756310857362759U;
            aOrbiterG = RotL64((aOrbiterG * 15826832172923213591U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11347400363019508578U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11696395232760991243U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9725231749679442003U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10875780291242873583U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7808740614343437672U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8889516201913716283U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3145390996141902032U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16080636485642732615U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7445756373012217305U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3929263288176983844U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18210228766683996806U;
            aOrbiterE = RotL64((aOrbiterE * 13178080076505449091U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13948962323541421431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3037683309790156893U;
            aOrbiterF = RotL64((aOrbiterF * 13406672352222636739U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 50U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9531U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 9017U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12587U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8588U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10641U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11937U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 8866844335448071821U) + aNonceWordH;
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 15159698739856430085U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 9582805772989594633U) + aNonceWordI;
            aOrbiterK = ((aWandererB + RotL64(aCross, 35U)) + 1438538239931588373U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 18U)) + 10862044156620436139U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 27U)) + 13682173320058164615U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 8351013291045977592U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15777857431516633916U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16178966745333885377U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 7545129923202147703U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9031889187993001617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6308472367425865347U;
            aOrbiterB = RotL64((aOrbiterB * 17118710301967158153U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 642109145903321046U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6091345356803675860U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13218507921880873749U;
            aOrbiterG = RotL64((aOrbiterG * 15415157927185637717U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4266652275234474616U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4391422098164506195U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17634679403195085867U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5160682323243635577U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10351728852161347404U;
            aOrbiterD = RotL64((aOrbiterD * 11105410036471745951U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3950932176454814023U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9536466386833427441U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18064984243491293435U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 39U)) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19364U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 16616U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19678U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23981U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21177U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24452U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 6U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 11177787645248006236U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 57U)) + 3808340254579817169U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererG + RotL64(aCross, 23U)) + 828030667598518279U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 3U)) + 16177835921238398371U) + aNonceWordD;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 13U)) + 5518747735458708741U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 17346319082399995165U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 29U)) + 6397156921893030937U) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15559381654710713582U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 940404446491415088U;
            aOrbiterD = RotL64((aOrbiterD * 16401260971303026881U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8047166032048732645U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4688468645859470491U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14383536431614496369U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3710878044770337260U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 116343189456629220U;
            aOrbiterC = RotL64((aOrbiterC * 5637725064169289339U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 883908030159391659U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 18058691521694880482U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3132200449123497619U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17521015077103586117U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3668332225435714918U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12658899101297839881U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12229480388278883300U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16206524049491531816U;
            aOrbiterB = RotL64((aOrbiterB * 11122340196620859805U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 5743265849441077466U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2812293020719282236U;
            aOrbiterK = RotL64((aOrbiterK * 8903956475200417109U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 30U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26705U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 25883U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 31273U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29415U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30212U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 28599U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 9914837590440975587U) + aNonceWordH;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 35U)) + 6706125076401958051U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 13U)) + 16570817772679258409U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 50U)) + RotL64(aCarry, 41U)) + 6843705658115186948U) + aNonceWordG;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 16099930446791572351U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 3U)) + 5420550009556030459U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 29U)) + 5729549069420177477U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15590601126188675834U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 13044027390998620029U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 16845199115313444123U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11068338135659636772U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6584988841809544332U;
            aOrbiterA = RotL64((aOrbiterA * 1683336180438945439U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8516813219883915404U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10647314042912492785U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15559481057047148785U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 201691689889605304U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3883760518944464145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13861805129175491145U;
            aOrbiterC = RotL64((aOrbiterC * 17194438894492581181U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12019138626550801486U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13030350224959652248U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 11724200983306280107U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2643807255422544248U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4127143302485631794U;
            aOrbiterB = RotL64((aOrbiterB * 5441038881111578487U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aNonceWordP);
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 58U)) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
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

void TwistExpander_Soccer_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA200DA0424EEA9F1ULL + 0xE54A64DF73DD61BBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9D30E248C9EE8B8FULL + 0xE1911AC10C90518FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x864F7E396059AA5DULL + 0xC8FF80E73B2A689CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDE8BDAE3E8F23661ULL + 0xC9DA60649C1C68F5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDD7CED4CD8FDED23ULL + 0xF4A459379A94B8C5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9DF4C0841EE9FD4DULL + 0xF32F660C5BAD74BDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9CBD858595352563ULL + 0xC0B98598D4C675EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEF5648CA1F033AB5ULL + 0xFFACA287ABA86E11ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF792EF75F8F40EA3ULL + 0xFEE2F7CB99FF2008ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCE8F8D748EDD589FULL + 0x8B9A3AC99C92805BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFDCEF4B691461617ULL + 0xA5B0A17254725638ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE1EE8FC224CAF621ULL + 0xFA7382A94DE09B97ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFFDC2178BE342939ULL + 0x99C0A2B0C9F19EBDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x99A2C34A5626932DULL + 0xD462B86CDEB16D70ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEB932C6A53543E53ULL + 0xB4A8032B96006611ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCB75027C5504E5A1ULL + 0xF8A656C48A3B8E86ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneD, aOperationLaneA, aFireLaneA, aFireLaneB, aOperationLaneB, aFireLaneD, aWorkLaneB, aOperationLaneC, aWorkLaneA, aWorkLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5132U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 8158U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 1850U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5305U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4877U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 7200U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 46U)) + 18191288703716505885U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 9824014524910417136U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 11U)) + 11953012029254917548U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 6297568011027199089U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 5U)) + 2576999400457367975U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 58U)) + 13176139160575558254U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 27U)) + 9978408174563621810U) + aNonceWordF;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 16765834875061607142U) + aNonceWordG;
            aOrbiterK = (aWandererG + RotL64(aCross, 23U)) + 16534507305459121344U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 21U)) + 3114710944346151807U) + aNonceWordI;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 29U)) + 10240517868726718592U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10721450637990777883U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3046344179729901637U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2427422768928450209U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6670984773768885119U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7058636403765106682U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9897341853944713767U;
            aOrbiterC = RotL64((aOrbiterC * 14286816859999869231U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17749559755733386064U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12515645083926326659U;
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2625692458813609962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10596240255026143019U;
            aOrbiterA = RotL64((aOrbiterA * 11605800195771080135U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12374290338067865540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1507386663796330249U;
            aOrbiterJ = RotL64((aOrbiterJ * 1210241080424446087U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9288099549484146726U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15159312464747000702U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 500055502081347757U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14998608679505446229U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17625038109437732009U;
            aOrbiterE = RotL64((aOrbiterE * 14785862243019841689U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10543192232885637211U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10330547522729618042U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 7635903835474874057U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5753298214283941201U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15943436872588208065U;
            aOrbiterG = RotL64((aOrbiterG * 17704547766822075741U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5757218926946874970U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18191288703716505885U;
            aOrbiterK = RotL64((aOrbiterK * 2644970408001409575U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 40U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 22U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 20U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11702U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 8323U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 9073U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15806U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15198U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 11655U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 10U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 37U)) + 17912271996338180948U;
            aOrbiterC = (aWandererA + RotL64(aCross, 39U)) + 13259276608841847058U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 5U)) + 16225936008657276089U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 57U)) + 2243058962151834071U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 23U)) + 10637439274127347861U) + aNonceWordF;
            aOrbiterD = (aWandererF + RotL64(aScatter, 3U)) + 15312219216405992627U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 48U)) + 2393933972129878613U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 4327069337247976513U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 8307656353434167837U) + aNonceWordP;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 53U)) + 17299145556933889336U) + aNonceWordO;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 14458100581172798164U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6410095654927998067U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6168964796264687686U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16218071040190475953U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3667999465041020730U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16021552859323602007U;
            aOrbiterD = RotL64((aOrbiterD * 6427266472526362663U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12941668202330045095U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4222032891850449934U;
            aOrbiterB = RotL64((aOrbiterB * 17292856787431308097U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1346342592002730785U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16860611785008118820U;
            aOrbiterE = RotL64((aOrbiterE * 384963420804756607U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3193572711804730241U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5866881282680588589U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 9226331800853634597U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17180332731328479126U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10222097519535882241U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 9422887302872778795U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8863502179821584859U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14872318155712512999U;
            aOrbiterH = RotL64((aOrbiterH * 11830641277356873233U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16478790641892781150U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8414944141232294781U;
            aOrbiterF = RotL64((aOrbiterF * 17443775794621154023U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13204056527590476037U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15084952142545813228U;
            aOrbiterA = RotL64((aOrbiterA * 17183888602469193015U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13051035678904490854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17565188004293304987U;
            aOrbiterI = RotL64((aOrbiterI * 12785271107667631897U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 814245676602237400U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17912271996338180948U;
            aOrbiterK = RotL64((aOrbiterK * 14557769257469623169U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 10U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aNonceWordN);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterK, 60U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererG, 36U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22947U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 18022U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 18960U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21130U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22940U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18352U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 7790166497945719700U;
            aOrbiterH = (aWandererA + RotL64(aCross, 3U)) + 7136208896846119188U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 47U)) + 12123156943355100886U) + aNonceWordM;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + 5095546037880875199U) + aNonceWordE;
            aOrbiterE = (aWandererD + RotL64(aCross, 13U)) + 17642705393916765992U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 51U)) + 9918479837334416990U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 11U)) + 4890009823843176466U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 17652590786213674124U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 37U)) + 870002527644696135U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 6U)) + 12545429703552643682U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 5310272867406182581U) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3264719049050179440U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1967241238180278937U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 13004319774269457957U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 773883832927040736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12766817190261232485U;
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 260069382395598265U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15462103891287350123U;
            aOrbiterD = RotL64((aOrbiterD * 5029268763635635753U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4072032867513289827U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17153061419083897076U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 11934532169271718913U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6207264270332656966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18048064697837314947U;
            aOrbiterK = RotL64((aOrbiterK * 13632594619404208489U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14484617445340272026U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16160443600497652026U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1988599349457831597U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5873314228291583482U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16418290052752166515U;
            aOrbiterC = RotL64((aOrbiterC * 18270363452003213317U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9158414409987627714U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8205937960146492168U;
            aOrbiterG = RotL64((aOrbiterG * 14008398661393344261U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16386126219854809263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12418021156683187869U;
            aOrbiterB = RotL64((aOrbiterB * 13897930566207284517U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5427232681451476584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18237670074497382745U;
            aOrbiterJ = RotL64((aOrbiterJ * 15528665160297906195U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8330262458028468513U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7790166497945719700U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6001280767763971107U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterA, 4U));
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 46U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24850U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 31865U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28960U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27889U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31024U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27436U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 23U)) + 13333509828310369865U) + aNonceWordE;
            aOrbiterE = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 7645352517103840797U) + aNonceWordA;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 53U)) + 5310766306660062655U) + aNonceWordG;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 5165635069832352932U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 5U)) + 15684141764734281849U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 39U)) + 3327963374225061738U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 8625811794878848871U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 30U)) + 7598657468430485291U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 19U)) + 2881171216276746485U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 10237691227222918101U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 6419254255884834497U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4238455444646479956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14936613353493061492U;
            aOrbiterI = RotL64((aOrbiterI * 3544216916806292273U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15324699725208372627U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9506640480601832011U;
            aOrbiterG = RotL64((aOrbiterG * 12819564111348390227U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3709149613660215641U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1724290199312754307U;
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13191172833570139194U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3686087945377837886U;
            aOrbiterK = RotL64((aOrbiterK * 10883609557429936283U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10418330386245397022U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5383531313632347245U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7414716553072652212U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11301761123966206201U;
            aOrbiterH = RotL64((aOrbiterH * 1546727321088592187U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8570229732236388847U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8773754460060264773U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 3251360788932563495U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13636929800504199371U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5486599841558573720U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2867914211589815153U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13277541451512422776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10409779509190185921U;
            aOrbiterD = RotL64((aOrbiterD * 1926650154570961573U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7268295836403414306U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13815969853235433830U;
            aOrbiterJ = RotL64((aOrbiterJ * 11603750346752441535U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 9353249174240162324U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13333509828310369865U;
            aOrbiterA = RotL64((aOrbiterA * 10381405217943841655U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 14U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 11U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 48U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Soccer_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x88E61386EFA168F5ULL + 0xCCE2EFD5499E1077ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xABBF149B0E6A4171ULL + 0xB6280C7AE214E75CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC9FDB5613D2E9B77ULL + 0xE266694DB7E286B5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8CB0912E4D16B2D7ULL + 0xAA8FFDA1E60E52B1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDFB54CB7819D3D57ULL + 0x99B18C41DC6AD458ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA57DB61F60D0981DULL + 0x8DEBD93B89A333B6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEF8A02258FB314B7ULL + 0xD54ED139A3628042ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x84A442848A495B41ULL + 0xEC75413BEEE2D219ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEE88E6E9BB896907ULL + 0xC60140ED8625994BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC28A33A76390946DULL + 0x9CE9CF27CA6AF784ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8E2A76AE57CE90F3ULL + 0xB9226D2602F0D68AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8DCDB50F7108C57BULL + 0xCBB03DF174A20879ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE0DF317E80E054A3ULL + 0xAEBD7D8573CFCD2CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEB22BE6C9D7E1D27ULL + 0xDD30E4235E86BBDFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD72EC576F74AD7EDULL + 0xDE55FF6A0F6B9824ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBAB85DB33C033FFBULL + 0xCE700FF8A42AB831ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA, aExpandLaneA, aFireLaneD, aWorkLaneA, aExpandLaneB, aFireLaneB, aWorkLaneC, aExpandLaneC, aWorkLaneB, aWorkLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 976U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 4507U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7685U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5847U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6288U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 1160U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 36U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 29U)) + 16922357079016918108U) + aNonceWordI;
            aOrbiterK = (aWandererD + RotL64(aIngress, 13U)) + 11771749797137599131U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 4635668433708036077U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 15827952719230577008U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 3U)) + 1495675306110023086U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 53U)) + 7294835466949728365U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 29U)) + 179122461212041978U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 43U)) + 545981421632236251U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 34U)) + 15338259639814630535U) + aNonceWordB;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12924313840290895215U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17846785921286020610U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18309347016029917133U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5721472794107057875U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16359630793856870319U;
            aOrbiterA = RotL64((aOrbiterA * 14186771515526698907U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10614102110239037308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16421992251278236531U;
            aOrbiterK = RotL64((aOrbiterK * 2561232904676068089U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8668149834861244963U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12699331834360948734U;
            aOrbiterE = RotL64((aOrbiterE * 2249360824172616357U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4470693178142950471U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 526000656022724741U;
            aOrbiterJ = RotL64((aOrbiterJ * 16688501462334673493U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6880246132270094141U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 7126466778855297013U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 5692237926830293205U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6436404501390442054U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1213633065612242699U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17604454985534439259U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8186529105901185854U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10607460957358250935U;
            aOrbiterC = RotL64((aOrbiterC * 17172191011625677861U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9743278964993305169U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14007577681873418075U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 4231122580398039133U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 10U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 14U)) + aOrbiterE) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12102U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 9912U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 9262U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14012U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12778U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15052U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 13442819395490639310U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + 8187292523194120936U) + aNonceWordN;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 34U)) + 11469697159823131388U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 13414083692375929653U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 51U)) + 11404010733687907517U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 47U)) + 6783212827186218247U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 21U)) + 8561131439340372614U;
            aOrbiterF = (aWandererA + RotL64(aCross, 41U)) + 6252609642004429113U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 53U)) + 12804867444200448952U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2739648749603690781U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14808861217017399752U;
            aOrbiterG = RotL64((aOrbiterG * 373911885694012101U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 17588866502571268888U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5882260142735642980U;
            aOrbiterK = RotL64((aOrbiterK * 7688252946143263869U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15493099088132862949U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5175647411532429582U;
            aOrbiterB = RotL64((aOrbiterB * 15226544495598541883U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 14279707376173642767U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6826363572161275158U;
            aOrbiterJ = RotL64((aOrbiterJ * 5263708315440161809U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13267185753040999992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9980987858092888720U;
            aOrbiterI = RotL64((aOrbiterI * 13210290848800728635U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3582972937645514549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10140409019562890804U;
            aOrbiterC = RotL64((aOrbiterC * 6944490201647678479U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6160444117287330557U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16344602960561293113U;
            aOrbiterF = RotL64((aOrbiterF * 2319964919335633293U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3497141036108337171U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 91269118352540308U;
            aOrbiterE = RotL64((aOrbiterE * 5160060720189045505U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12739932748793144857U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12820180915064791197U;
            aOrbiterD = RotL64((aOrbiterD * 5843849637411948699U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 48U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterB, 54U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19991U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((aIndex + 22207U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 16710U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21248U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17221U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 24214U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 48U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 28U)) + 8975885703279267062U;
            aOrbiterH = ((((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 8664844915562660637U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 12281774799736296726U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 35U)) + 15347461352311329726U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 58U)) + 12967500561828907834U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 5U)) + 5002833859280402726U) + aNonceWordL;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 11908257536954668983U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 51U)) + 17017174811949227162U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 23U)) + 16851323125613931180U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13469326957728686706U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5228638551056105241U;
            aOrbiterB = RotL64((aOrbiterB * 13369947664646167255U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11945166198089308564U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16268645041872996022U;
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14781204627695095701U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5365325354838101092U;
            aOrbiterC = RotL64((aOrbiterC * 8017284997946310807U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 563147416025715953U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14660867395395625851U;
            aOrbiterE = RotL64((aOrbiterE * 4769458126865307103U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3168989056355712105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16179131669773665579U;
            aOrbiterJ = RotL64((aOrbiterJ * 5641461617066671723U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4160220074225527179U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8597134686962559111U;
            aOrbiterG = RotL64((aOrbiterG * 639572585431474015U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16811551552456811661U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5827323970423386301U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9328247349730652021U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15583234353262170227U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2950816254621717748U;
            aOrbiterA = RotL64((aOrbiterA * 1102417597476170143U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4426165025104306337U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11871220132164971152U;
            aOrbiterI = RotL64((aOrbiterI * 2366168050042802207U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 18U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterG, 50U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28211U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 26176U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 28977U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26695U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25187U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 28734U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 60U)) + 13960289014350612206U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 51U)) + 3483331015269589730U;
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 6873299241002444518U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererD + RotL64(aIngress, 35U)) + 3562094007125534229U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 10U)) + 11422367439932782705U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 532453428514259816U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 17810941465810193088U) + aNonceWordK;
            aOrbiterJ = (aWandererE + RotL64(aCross, 23U)) + 11869759058631106331U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 27U)) + 8837581071876177566U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17185378327053837778U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7578253375676981500U;
            aOrbiterC = RotL64((aOrbiterC * 13371647568758721729U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17112646434432814442U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 14949096407295697881U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4259590620758467836U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6534899413644542303U;
            aOrbiterA = RotL64((aOrbiterA * 7987609419215568661U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2637407498893694243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15819295597921425711U;
            aOrbiterD = RotL64((aOrbiterD * 5202015597375051399U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6373559542002699718U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11694562937392022505U;
            aOrbiterE = RotL64((aOrbiterE * 9311557972331218597U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3308736483775453062U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12749929710650475901U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1569528215675579656U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1044077933631689572U;
            aOrbiterJ = RotL64((aOrbiterJ * 6443796233912755143U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8393422728124537471U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2002732612516530754U;
            aOrbiterK = RotL64((aOrbiterK * 13702146823622364279U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13469191942843147943U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7633171368709520560U;
            aOrbiterI = RotL64((aOrbiterI * 9713514012478203047U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 12U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 34U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Soccer_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB80CD9ACB33EF403ULL + 0xBAA42F61A318B56AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAD1AE554388857FBULL + 0xBFEB02D6D1A94782ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAA9B5548B5F4AF8BULL + 0x98FCC3548CB7DFF5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA8C3BA7AE009F005ULL + 0x8A30F8EF1EF31918ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE76A0583BEE906B3ULL + 0x93F75E4E531C4B4FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9C257EA960428C7BULL + 0xCB74D17858D1D817ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA20E6C888288FD4DULL + 0xCE321D7A905EDB5BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA6BE0FFDB2E9466DULL + 0xAAB2D51D42D24D8EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB87E5DBCF2E2F7FBULL + 0x8CD6EA3C2D829922ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD9D700D578B72EDBULL + 0xD883AB02CA54A8F9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x86F24F98043E2EA1ULL + 0xEA3B0927FAFBF021ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE93A23F096EEDDD3ULL + 0xFED6E74A34134032ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA430D59EECAFF1B3ULL + 0xE9953DF4E0B8451BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEFCEEF1FA957A145ULL + 0x8EF1413A77D5D727ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC35CBE8E3950B995ULL + 0xEF8B3F97BE700447ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8B26AAE0C12A9197ULL + 0x8BE06C106D9F7A4EULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aOperationLaneC, aOperationLaneA, aExpandLaneB, aFireLaneC, aFireLaneA, aExpandLaneC, aOperationLaneB, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7900U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 4052U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 5696U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6812U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4539U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7217U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 41U)) + 6318740973868639425U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 58U)) + 5487840061430920881U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 13U)) + 10258706763248072672U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 18356875269730338208U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 12883160282903147010U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 51U)) + 1010140474942697730U) + aNonceWordD;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 17733939421700898293U) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13693055887924981201U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14574732452793385269U;
            aOrbiterB = RotL64((aOrbiterB * 9373765929885750185U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10832873941223609012U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8212600587135328040U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5334613996794796145U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5312744319781971178U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12854414066390848249U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3693249147883790810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18365859989736602556U;
            aOrbiterF = RotL64((aOrbiterF * 3348463719324104997U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10645056678337549771U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1175668356822251045U;
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13556844570541823717U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4790355739411849736U;
            aOrbiterK = RotL64((aOrbiterK * 4083544011788850307U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14905575502272644116U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17047244574558476634U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 20U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterF, 40U)) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12028U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 9855U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15792U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12498U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13994U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14336U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = ((((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 13915875634607599122U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + 1695770381382411673U) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aCross, 56U)) + 3709105579778295511U) + aNonceWordJ;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 5U)) + 7673376335333251804U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 8814147709738503518U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 13451412605350381172U) + aNonceWordI;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 29U)) + 6447870234069609538U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13419487997946496825U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5478309847615220345U;
            aOrbiterK = RotL64((aOrbiterK * 12953043149543448765U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 3635184969215610049U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12527903812035294828U;
            aOrbiterD = RotL64((aOrbiterD * 12540800512035534967U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1684685110885338814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12860354576326835090U;
            aOrbiterI = RotL64((aOrbiterI * 12743745087733307255U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9081823570147481835U) + aNonceWordP;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 14369321778210049109U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 17865953349448767035U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11518132079084873250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11893535026126957389U;
            aOrbiterF = RotL64((aOrbiterF * 15751374986135615095U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7084079180579206226U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2999676609847603277U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14602698397511266403U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17683445810614029153U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11576460512964896969U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 5243651036457051155U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC + (((((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 60U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aNonceWordC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20341U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 23186U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19867U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23918U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19804U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17489U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 3448371607470865612U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 3743742913651580573U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + 13069491287948807280U) + aNonceWordF;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 58U)) + 16872779275586545632U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererG + RotL64(aCross, 41U)) + 17945792656755062795U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 18199747196793731853U) + aNonceWordI;
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 15953311878379809513U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 941268763494588338U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10090221530365796809U;
            aOrbiterC = RotL64((aOrbiterC * 14035236086292997613U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8335698093307607001U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6147498804734306100U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 6904444049941211327U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5980246079567570090U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4152167624425912978U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10019421651535123573U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 14990418790239735916U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3418668387496597219U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 12814077238529863119U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4206650904177199425U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3905470780938996069U;
            aOrbiterB = RotL64((aOrbiterB * 16030122739273137005U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9968672788233080924U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 602258075661864866U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2615726693066300065U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17751667243048041383U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2414054413585296027U;
            aOrbiterE = RotL64((aOrbiterE * 1049512574773201893U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterC, 5U)) + aNonceWordB) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 58U)) + aOrbiterD) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28723U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 30335U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 27364U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25888U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27376U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 28086U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + 14249093584376402677U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 8756965951816492264U) + aNonceWordC;
            aOrbiterH = ((aWandererA + RotL64(aCross, 29U)) + 11221139480258176330U) + aNonceWordD;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 17218894445564194851U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 8064642692524949490U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 3U)) + 5822093203710704646U) + aNonceWordN;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 56U)) + 3217799620158102238U) + aNonceWordB;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2613757677892120843U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13647481499551657237U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 5517563514031899891U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3545714196663685016U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9735422670576621521U;
            aOrbiterB = RotL64((aOrbiterB * 7276207208162697249U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3911046580637583767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9315984027042049203U;
            aOrbiterE = RotL64((aOrbiterE * 12568550776487242469U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8926367674641729058U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11035347490524961446U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10948288997163592463U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10748158733051120339U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2467801787989056455U;
            aOrbiterJ = RotL64((aOrbiterJ * 12621934274702358977U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9244415080474351390U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8517784887959492079U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17022899813765884147U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8409307332803038455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11043806021873232950U;
            aOrbiterG = RotL64((aOrbiterG * 8294888329708842989U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aNonceWordE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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

void TwistExpander_Soccer_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE507A580A15CD33DULL + 0xE0C7847C4BFDB3B1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF50FDEF3C34D4F6FULL + 0xB9FB916657B6A413ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE48955BF20EE0ACFULL + 0xB07FF228BBD4AEB6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC6033697A5478C73ULL + 0x833EB94EFAB1DC14ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF97A9748C7BB4295ULL + 0xF8BDEC3764D9671EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x87E0EA8D30FEA71FULL + 0xA74F938C47F96257ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA73C744E318FD25ULL + 0xD24701BFF0503C1AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA4F6FDA299C2EC1FULL + 0xF20C370AB913B131ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCE0358518BF9D65FULL + 0xFA91C9E677259A45ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC083F1B8871C89CDULL + 0xFD2941F00016577CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBB94FD200112D02FULL + 0x87309D66F675EA96ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA1CECD18644CC6EBULL + 0xC11FF11732251DBFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9C6E1D953D71F1F7ULL + 0xDE97530FC53B4DF2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEBF3839A3FA55EDBULL + 0xFA54596F20CD5484ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF2AF39BA83A31619ULL + 0xCDA86273CA18413EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE261D2AC275519E3ULL + 0xA415199047C9CE67ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2129U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 1911U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1607U)) & W_KEY1], 56U) ^ RotL64(mSource[((aIndex + 1529U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 13U)) + 4259993311776766595U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 2857813330021126753U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 37U)) + 1345396841329442896U) + aPhaseEOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 320992148982301024U) + aNonceWordD;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 5619109532065293074U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 19U)) + 10380157329426706345U) + aNonceWordF;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 29U)) + 12449831150625409695U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7847096607042268396U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11707184096803214678U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 1959476948106553973U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9893643746186827088U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 333687403830908774U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17911256836121454271U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13837360705077441580U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4367119682175710689U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10295744669174603401U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1193493435041306784U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15062951612027370606U;
            aOrbiterC = RotL64((aOrbiterC * 2509383510565136549U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16000173839235429105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15294482444605409961U;
            aOrbiterJ = RotL64((aOrbiterJ * 1031800997944302665U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5720749055549773527U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17248674962996093668U;
            aOrbiterK = RotL64((aOrbiterK * 15730637462755795591U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16956840483882091059U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9637715107943515594U;
            aOrbiterA = RotL64((aOrbiterA * 8878362378343603463U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + aNonceWordC) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 2783U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4191U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2869U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 4672U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 14008824488073394623U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 13U)) + 13317978415866411468U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 27U)) + 13209180141897453900U) + aNonceWordM;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 3U)) + 11870521586865233578U) + aNonceWordB;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 43U)) + 8052156380448047385U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 23U)) + 12158131176743680605U;
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 14674467487607719347U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18055496790566231147U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3838105585041578784U;
            aOrbiterD = RotL64((aOrbiterD * 1075709247574580091U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2839568255183054418U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11933612922864258179U;
            aOrbiterB = RotL64((aOrbiterB * 7571964469321160347U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6289849094151630580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2640344350528492271U;
            aOrbiterK = RotL64((aOrbiterK * 16197726750829369365U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16306175266267657791U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3339898380394883600U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 7105436590182982373U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15017076663742800002U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 8973064296077602496U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 9309462227233615761U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17580319233338139859U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14063208878807603874U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16601475239075164585U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13326130855721009942U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12843186026737544416U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 4975848122837321619U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + aNonceWordL) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 50U)) + aOrbiterK) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7596U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6839U)) & W_KEY1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5934U)) & W_KEY1], 44U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6311U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6279U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 10U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererA + RotL64(aCross, 5U)) + 5576732410244514238U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 2833808925935929629U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 3670188682914544792U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 15759072378887814995U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 36U)) + 13934007231137439994U) + aNonceWordB;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 19U)) + 11022225696007690512U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 57U)) + 16989177104453635790U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9256930045263527091U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17788596104417068290U;
            aOrbiterK = RotL64((aOrbiterK * 675554110563253305U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17044369456673337625U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 1310908395523250343U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 16305084373037705921U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12067065689034065422U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15130844248737512262U;
            aOrbiterH = RotL64((aOrbiterH * 9409499577465934107U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14532689204495587494U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8198147292120244178U;
            aOrbiterJ = RotL64((aOrbiterJ * 1418356389507740991U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5485494458627163347U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10830008207150307611U;
            aOrbiterI = RotL64((aOrbiterI * 6526039534042499457U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17770065502486618029U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6397859353395335459U;
            aOrbiterE = RotL64((aOrbiterE * 14286997752368893825U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5128700697381508319U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7103394110057060499U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5053680689949149633U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aNonceWordF);
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9462U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 9536U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 9100U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8301U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9063U)) & W_KEY1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8313U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 6U)) + 13296600294247799698U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 13U)) + 5818503518080877515U) + aNonceWordI;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 6735784238734173597U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 7368398209488856201U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 961734029066455638U) + aNonceWordB;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 35U)) + 797011946660892011U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + 12841876018396622350U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16213253970483895623U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15186950557113470375U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4647470430467908107U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5117930310827477341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12265429373166094162U;
            aOrbiterD = RotL64((aOrbiterD * 1522823535151532249U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13920531346698601568U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14695405206998211456U;
            aOrbiterE = RotL64((aOrbiterE * 13950964363414164279U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7851960904825938443U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9501511171732550190U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5663365182245722077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9607860124321315555U;
            aOrbiterH = RotL64((aOrbiterH * 3461820361914280601U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 18171052650586819280U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3442698321538580861U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6317525514963824829U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1491052813469258970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3956599824067616133U;
            aOrbiterB = RotL64((aOrbiterB * 2928600779267623085U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ) + aNonceWordC) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 27U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 38U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 29U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12811U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 12829U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11437U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 11786U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12059U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12208U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12853U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 42U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 53U)) + 8375305456876489425U) + aNonceWordI;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 41U)) + 16193562952772453047U) + aPhaseFOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 18088652458594816223U) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 767344788620249944U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 60U)) + 7705194930396368752U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 3829736891311272834U) + aNonceWordB;
            aOrbiterH = (aWandererI + RotL64(aScatter, 5U)) + 9881681671347640061U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1721196560190164264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3002652618388454213U;
            aOrbiterG = RotL64((aOrbiterG * 15289749311593032657U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9811621464004005202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5652598941069986530U;
            aOrbiterD = RotL64((aOrbiterD * 4797973356708091621U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6250499348327316328U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16025054277615264530U;
            aOrbiterC = RotL64((aOrbiterC * 16446892258704281903U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13800298546867243172U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12256104592865905782U;
            aOrbiterH = RotL64((aOrbiterH * 16983140179497142713U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17817225416918329229U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17738671327352776217U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 393488251327705063U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6816031224188400541U) + aNonceWordA;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 16989563985059237014U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 8677884225771717797U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16891524847268207549U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 1833508573940405571U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 9709196587703979539U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 30U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 40U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 11U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15176U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13946U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16153U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14182U)) & W_KEY1], 43U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14799U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15505U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14637U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 43U)) + 14157904117287696136U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 7369512677371640676U) + aNonceWordK;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 8411250745902073798U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 5002041814539710275U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 23U)) + 9538041410816283124U) + aNonceWordC;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + 5210700103927513061U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 60U)) + 7600709399101287982U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 2366369466696580499U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5544575244203019109U;
            aOrbiterH = RotL64((aOrbiterH * 16231219246786333057U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8710073749110329779U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15998211310115361630U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15275657696897688955U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15354357553877376422U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10657523549259276169U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 13695239532898311073U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10405750198355464768U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3465819693133515142U;
            aOrbiterJ = RotL64((aOrbiterJ * 14678343718277562799U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16724189641701408630U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3484340153620198872U;
            aOrbiterI = RotL64((aOrbiterI * 17247547677520703125U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7420442404884871126U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11138445997256757636U;
            aOrbiterK = RotL64((aOrbiterK * 11167543379937571127U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1428191560884663125U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16950093140800653985U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 4423012306984814805U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 36U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordF) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 12U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + aNonceWordI) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17233U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[((aIndex + 16799U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 18456U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 17645U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18852U)) & W_KEY1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16974U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17984U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 5U)) + 14179205183062705133U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 210032324058740920U) + aPhaseGOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererG + RotL64(aScatter, 23U)) + 7387115089142500152U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 17583362781238061430U) + aNonceWordI;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 4991442849150005943U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 13U)) + 2891376254689854555U;
            aOrbiterB = (aWandererH + RotL64(aCross, 30U)) + 10523274382407446239U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3861893764676218667U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3366674459852093746U;
            aOrbiterD = RotL64((aOrbiterD * 14005994095369483813U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5898492634386601145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7047353571244768721U;
            aOrbiterG = RotL64((aOrbiterG * 2257518291062508467U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14374108805453186316U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8763667021501226510U;
            aOrbiterF = RotL64((aOrbiterF * 7694695426430267863U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18261523829316379575U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 650477532238860965U;
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 2162326554604894042U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5776546692501825278U;
            aOrbiterB = RotL64((aOrbiterB * 14911545784585246537U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 3501863793638415049U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14853789267425352958U;
            aOrbiterJ = RotL64((aOrbiterJ * 10590325397179928739U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15399673014671329743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12253428583438990426U;
            aOrbiterH = RotL64((aOrbiterH * 12052855472196447849U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 10U)) + aOrbiterG) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aNonceWordH) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21030U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 21095U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20732U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21552U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21040U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21679U)) & W_KEY1], 56U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19552U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 19755U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererC + RotL64(aCross, 6U)) + 6024062041314952357U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 18340757093658015585U) + aNonceWordC;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 11911120493880346751U) + aPhaseGOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 27U)) + 17428074353884654439U) + aNonceWordL;
            aOrbiterF = (aWandererG + RotL64(aIngress, 21U)) + 12790849760814795936U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 12633397052172117800U) + aNonceWordO;
            aOrbiterI = (aWandererB + RotL64(aCross, 39U)) + 11946150433665237945U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16842157900909419285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14186235783224155962U;
            aOrbiterD = RotL64((aOrbiterD * 10521157787073684417U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13284904542579767591U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11609181965078844357U;
            aOrbiterF = RotL64((aOrbiterF * 5455780554452453513U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9628562297095374984U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7850281529011259759U;
            aOrbiterJ = RotL64((aOrbiterJ * 17611485102925470357U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 257458718073794527U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10693404545773519306U;
            aOrbiterI = RotL64((aOrbiterI * 14821443722828498323U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 3430519236533871460U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6183054506953198055U;
            aOrbiterG = RotL64((aOrbiterG * 6121082743789970911U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2905610989884221654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16870142883133769663U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1403692060594816451U;
            aOrbiterC = RotL64((aOrbiterC * 9740854430251597879U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterD, 23U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 52U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aNonceWordB) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterI, 5U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aNonceWordM);
            aWandererB = aWandererB + (((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 53U)) + aNonceWordD) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24328U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 21933U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22022U)) & W_KEY1], 23U) ^ RotL64(aFireLaneC[((aIndex + 21890U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23270U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22554U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23455U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 23397U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 24U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 13U)) + 4980738603982643969U) + aPhaseGOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 51U)) + 17660278413018470020U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 27U)) + 17598114429859543466U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 10993929335279994739U) + aNonceWordH;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 17967203122976322481U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 6U)) + RotL64(aCarry, 11U)) + 1872290205549034384U) + aNonceWordO;
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 16607778671782810797U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4895226930754394376U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14960359005982301383U;
            aOrbiterE = RotL64((aOrbiterE * 8546231310054433721U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9921642352377700630U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 893281964367208693U;
            aOrbiterI = RotL64((aOrbiterI * 2345509157333444217U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8232519988397858732U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4433022122758913407U;
            aOrbiterD = RotL64((aOrbiterD * 834240393225479419U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12689609831247168353U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 404535388957472176U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3349108201964013155U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4386449511297371730U;
            aOrbiterG = RotL64((aOrbiterG * 9596273264321140229U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14314587717949070586U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10923886625271054985U;
            aOrbiterC = RotL64((aOrbiterC * 7838969002623486809U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17634909585329833520U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2021301459918350372U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1388242915918642741U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aNonceWordM) + aPhaseGWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 58U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24929U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[((aIndex + 24722U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26757U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 26866U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25857U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26100U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25804U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 26207U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 11U)) + (RotL64(aIngress, 50U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 1393781663398437180U) + aNonceWordA;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 27U)) + 17414594746688585273U) + aNonceWordN;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 2823888497053071250U) + aNonceWordJ;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 12U)) + 17032631958617884859U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 41U)) + 15222697630461125019U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 15737414920751551780U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 53U)) + 1357196111055783001U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5315122321649251691U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7893744655508595974U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17863000246694319149U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16721939414324611738U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 3444375866323610848U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 10874157227815775661U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1825716513674511632U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15582066843912467318U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12765146555943757373U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15673590949193923915U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13887365046280406413U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 3169061375011420121U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12730414371734709356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4819112390640821927U;
            aOrbiterF = RotL64((aOrbiterF * 8782547948627685451U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3089925954422937464U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7180179304678622530U;
            aOrbiterD = RotL64((aOrbiterD * 16118051565147747413U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17030269962085008657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6675917351883004046U;
            aOrbiterJ = RotL64((aOrbiterJ * 14134335325316949687U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + (((((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27749U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 29258U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29315U)) & W_KEY1], 43U) ^ RotL64(aFireLaneC[((aIndex + 29527U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28303U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29630U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28694U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 28425U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 5U)) + 9888431329297626900U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 2937735167534624403U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 17626022970343789617U) + aNonceWordH;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 5665660859333693743U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 26U)) + 1060537034632076669U) + aNonceWordB;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 11U)) + 743777763907175800U) + aNonceWordC;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 41U)) + 5744905970181808845U) + aPhaseHOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3545351394494002180U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4877547088414106007U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5416792889338547109U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11669378338379598445U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2961072441706158212U;
            aOrbiterJ = RotL64((aOrbiterJ * 2677988507090705371U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13984945589234919765U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 1433097875470903205U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 451996840039906781U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 716415411025451152U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8542286150858297810U;
            aOrbiterI = RotL64((aOrbiterI * 9139015340823332449U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12932391786479661299U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14005503313299177013U;
            aOrbiterB = RotL64((aOrbiterB * 802663466907819743U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9382792812676318046U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5138554251079724724U;
            aOrbiterH = RotL64((aOrbiterH * 6386016499265056247U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8522380066269546172U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11825536408101906458U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 17042837108792016849U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 34U)) + aOrbiterB);
            aWandererD = aWandererD + (((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 5U)) + aNonceWordI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aPhaseHWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31226U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32298U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30184U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32097U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30342U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30532U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 4U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererI + RotL64(aCross, 28U)) + 6318740973868639425U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 5487840061430920881U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 57U)) + 10258706763248072672U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 19U)) + 18356875269730338208U) + aNonceWordN;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 12883160282903147010U) + aNonceWordG;
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 1010140474942697730U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 17733939421700898293U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13693055887924981201U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14574732452793385269U;
            aOrbiterD = RotL64((aOrbiterD * 9373765929885750185U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10832873941223609012U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8212600587135328040U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5334613996794796145U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5312744319781971178U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 6173741211706546923U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 12854414066390848249U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3693249147883790810U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18365859989736602556U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3348463719324104997U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10645056678337549771U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1175668356822251045U;
            aOrbiterJ = RotL64((aOrbiterJ * 6579675292775345579U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13556844570541823717U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4790355739411849736U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4083544011788850307U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14905575502272644116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17047244574558476634U;
            aOrbiterH = RotL64((aOrbiterH * 2356386971503880047U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 44U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + aNonceWordK);
            aWandererH = aWandererH + (((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Soccer_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9F599290D514C949ULL + 0x97721EB6450DBC4AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFA39D3EB67ADFCBBULL + 0x83B6517E68800509ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCA48B5DF75483389ULL + 0xB7C068A16CA5BD52ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDCA40CAECE151EB5ULL + 0xB8C4212270648E8FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC9B7222A20CCDF71ULL + 0x9691B4C37114D59FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB77570D7511B4029ULL + 0xD72A2C6BD1B61D04ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEDE29B1040415A63ULL + 0xE544CD228D08F1E9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9EEF78892E4B4869ULL + 0xB1B64F3937181E08ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x945DE2F1C093017DULL + 0xD4099DA67EB4852DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD66CB46D4965AE3DULL + 0xDD01E54B21DFFF90ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB01ECDC6789AAA8BULL + 0xA2BE316EC934F54FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDA69BB1EBC36B2E5ULL + 0xB52F78F4A56B3AE9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBF72630FF784D441ULL + 0x85539F441057ED57ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAC3346696719B365ULL + 0x91365C0ACECE7FF6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBD265BF7AA22AC69ULL + 0x9460A5A94524BFC3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF4804A49EF49597BULL + 0xD9E1BDFFF1298A09ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2254U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 4317U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 2569U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 777U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 486U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 36U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 44U)) + RotL64(aCarry, 19U)) + 12029393034357490020U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 3U)) + 4526754731580694987U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 17060419646421271853U) + aNonceWordB;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 4128488893837059683U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 53U)) + 12706894827547160110U) + aNonceWordP;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 12506324593645825056U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12581344490649250025U;
            aOrbiterE = RotL64((aOrbiterE * 16311882267466003291U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14357032418199130132U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15341977701796331249U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6332369248718076031U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7086602307544733241U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12398300065276832486U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18157408831225635333U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2499745046076601988U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7249361592814001829U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 14597139848072319685U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3254456186337366437U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3472973415969046680U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14583566953969168353U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 48U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + aNonceWordI) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6986U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 8077U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8102U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10749U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10355U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 38U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 23U)) + 5173905450211892891U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 47U)) + 3555542451908039957U) + aNonceWordA;
            aOrbiterK = ((((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 11559884700283861559U) + aPhaseAOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 1352524329968738673U) + aNonceWordH;
            aOrbiterH = (((aWandererD + RotL64(aCross, 34U)) + RotL64(aCarry, 5U)) + 8914206450420616349U) + aNonceWordP;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2251523378498463946U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9541575923299247038U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1066487482799638689U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1239854507907214595U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17698101462598498934U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 2304948713665996433U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 12305566971683256060U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13804545036303215569U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 10359543704152744971U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10239749097704329264U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4212214906286320308U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3661436621615751071U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12192418916967430783U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4475514289326450361U;
            aOrbiterJ = RotL64((aOrbiterJ * 17497164630368757887U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterE, 30U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11160U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((aIndex + 15239U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14630U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14165U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11323U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14715U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 38U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 27U)) + 17264605017518259932U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 15209184354580778643U) + aNonceWordJ;
            aOrbiterK = ((((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 3299527965014731384U) + aPhaseAOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 21U)) + 16293096431816127821U) + aNonceWordB;
            aOrbiterA = (aWandererG + RotL64(aIngress, 43U)) + 11031983436878828337U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9188018632448236358U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13420816400363406556U;
            aOrbiterK = RotL64((aOrbiterK * 10958221259662190519U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 2485063384097917101U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3089135816938128264U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8813152992957361153U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 10730544971770435788U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10431767565618874806U;
            aOrbiterG = RotL64((aOrbiterG * 4723078464590561545U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14883796491656899074U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13322163435314643713U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterA, 60U)) + aNonceWordA) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aNonceWordD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19450U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 20140U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 16540U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19067U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21649U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20658U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 50U)) + RotL64(aCarry, 27U)) + 15652862298542575895U;
            aOrbiterK = ((((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 16925323928418184554U) + aPhaseAOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 37U)) + 4413861484961668394U) + aNonceWordG;
            aOrbiterA = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 2215946422098155969U) + aNonceWordE;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 11U)) + 14975185533513111110U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9711613814905834552U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13154957291850149471U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 17049677190793844477U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5058313016418534840U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15011423472941211620U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6125316151731105673U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2030053257469580168U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 150530795186791193U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 11106050063717096073U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10878237472104183427U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11724672539469573109U;
            aOrbiterA = RotL64((aOrbiterA * 16158741837357985395U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9589700906445846956U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1367381624958248949U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8459515089081211977U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordM) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aNonceWordI) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 30U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27164U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 24643U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23427U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22398U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23950U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 24129U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 19U)) + 6342299552323486695U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 12692748514781367538U;
            aOrbiterI = ((((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 8202639945493229155U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 42U)) + 4439975701793231639U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 16774235182859553759U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8764155413335405667U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7167848811974967685U;
            aOrbiterI = RotL64((aOrbiterI * 1052856924757654735U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16768278912125334220U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9090838954826296201U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5459329624017272077U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7644075729758006298U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 17326182797908071215U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 2408330168749256075U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16158809721888137555U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8029938783858263694U;
            aOrbiterD = RotL64((aOrbiterD * 12628072435324195483U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 8716553521415553404U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7012599977009208840U;
            aOrbiterE = RotL64((aOrbiterE * 8775355876188948851U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 40U) + RotL64(aOrbiterA, 43U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 58U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + aPhaseAWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 38U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27720U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 30982U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29976U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31818U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27513U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32152U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 12U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 1457104756581596530U;
            aOrbiterC = ((((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 6127240317844622874U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 3U)) + 16492290056044189421U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 27U)) + 10963676850938416468U) + aNonceWordK;
            aOrbiterB = (aWandererE + RotL64(aScatter, 11U)) + 4872917367399752405U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15218882377875616148U) + aNonceWordA;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 5934166612122118251U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 10365045124180379919U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14215280930872003003U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11428034799044600979U;
            aOrbiterE = RotL64((aOrbiterE * 12162528943733976177U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5453003654321728726U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14273775120265649389U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5139018128323795309U), 21U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 328723770018440271U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13032190719588211088U;
            aOrbiterA = RotL64((aOrbiterA * 13363368478932798315U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2386881543033598494U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1649501123340887116U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 11148976582360499033U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterC, 38U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + aNonceWordG) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Soccer_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD75E2C970E275119ULL + 0xAA7894AAA12AFC4EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB9377ABB41EA12F5ULL + 0xE1693074EF94B6BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE61F5E8C4C11442FULL + 0x954DF5477280AB1EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E6C41DE5E61B2DDULL + 0xB9D4331C2C315FAFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB1E18250B2846263ULL + 0xC9B2F8A9F5ECE806ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8E802CEE39AF836BULL + 0x9F9D6DE0718E108CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEC4D2D18D75F2D3FULL + 0x8002B42E5CEF1711ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x93B5A4CAA94D3257ULL + 0x8A6CB6D621468431ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD4E540191CBEC53BULL + 0xC65B38D1CA3C1BE3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC5A9B653FA1F293DULL + 0xB7F7135A9D0E9410ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x872B443F0C602601ULL + 0x884F6A2FC170CF74ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEC7E15F5C5811407ULL + 0xC28A0FADADD87FB2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x81AAD433C24E9471ULL + 0x8A54C4BC4B936B2CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAB0DE52A186F0EC7ULL + 0xA2E6217AB66D895BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB06FA2583A85CC59ULL + 0xC6AE4CD96E1185F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x96B02E60C214434DULL + 0x89CA3C1E572636BAULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aExpandLaneD, aFireLaneD, aInvestLaneD, aFireLaneC, aWorkLaneA, aFireLaneB, aWorkLaneB, aExpandLaneC, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2871U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((aIndex + 5016U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2289U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1001U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5006U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 2644U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 53U)) + 14499676118633326000U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 36U)) + RotL64(aCarry, 27U)) + 17191273593018552288U) + aNonceWordI;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 57U)) + 4085176294948097737U;
            aOrbiterG = (aWandererD + RotL64(aCross, 19U)) + 11112671474158908186U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 23U)) + 8745787969012266485U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 3U)) + 18074049663777707948U) + aNonceWordK;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 27U)) + 2543758649719164688U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 4659584749412700523U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 41U)) + 974639159259871273U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9211220687971081987U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8567024626862182714U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7755874089832496393U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5803002132294840900U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 11968489432878148467U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 4501441062617123165U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9470807228394903442U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1692347973120388469U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17433393164156231575U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16510815732690193145U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 755159406833096510U;
            aOrbiterB = RotL64((aOrbiterB * 14091736464659561165U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1518824876475937620U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 701225390867330446U;
            aOrbiterA = RotL64((aOrbiterA * 12264618860580199927U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8425976693733003889U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7182176375442410367U;
            aOrbiterF = RotL64((aOrbiterF * 8860605703761731859U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4546566785167467924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2593340999038753749U;
            aOrbiterI = RotL64((aOrbiterI * 10152461487764567563U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9756331608356622299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5511625814747641978U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 4806076157539829529U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8694400787420160733U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12648969491371382682U;
            aOrbiterG = RotL64((aOrbiterG * 5346585704222643759U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 14U)) + aOrbiterE) + aNonceWordP) + aPhaseBWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 10U)) + aOrbiterA) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8642U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 8630U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6371U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8759U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9743U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6374U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7551U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 12U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 56U)) + 18144572925667544139U) + aNonceWordO;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + 5659758077574059728U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 19U)) + 6343330616999166392U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 17754639838410839447U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 9451843819849581729U) + aNonceWordF;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 5U)) + 7957854457197462212U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 29U)) + 1461994799722205010U) + aNonceWordP;
            aOrbiterC = ((aWandererC + RotL64(aCross, 23U)) + 18002214276252170177U) + aPhaseBOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 46U)) + RotL64(aCarry, 13U)) + 14689869073147027164U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3978104368003440293U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8512135845221335386U;
            aOrbiterD = RotL64((aOrbiterD * 10506667163729414667U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1477533446382953439U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 2166717790929947990U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 6538884492418324461U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8082437060686606995U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4363687722464700362U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7199165810993478887U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15782763348014924206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12248271773316742521U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9602078627638561949U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1860631869877427405U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17244849374768558859U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1030743048280579012U;
            aOrbiterI = RotL64((aOrbiterI * 10858949914285817051U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17722342363541914280U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15667504059789880034U;
            aOrbiterC = RotL64((aOrbiterC * 15872269872168533709U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12645332941998550794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9938135244509986497U;
            aOrbiterG = RotL64((aOrbiterG * 16548185968987392957U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4024609904162105979U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6732064218696157303U;
            aOrbiterA = RotL64((aOrbiterA * 3815409766145891393U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 40U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 48U)) + aOrbiterC) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + aPhaseBWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 12U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterB, 41U));
            aWandererD = aWandererD + (((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14027U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 12960U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16338U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14283U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 11778U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 26U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 6163290588946759209U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 23U)) + 7342672468560105447U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 52U)) + 11574563167017282321U) + aNonceWordJ;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 2254820206194758964U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 39U)) + 1469783447473099498U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 35U)) + 14174828900676165088U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 47U)) + 16277954291890598132U) + aNonceWordK;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 13U)) + 14845750668693136766U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 43U)) + 150099699692047766U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1200784917165131703U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 9469982764806754302U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 17851969334511301943U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10956702761701710182U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17335794183733623213U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 557028996286989506U;
            aOrbiterH = RotL64((aOrbiterH * 3993359298602424281U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1597385667771002414U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4376417959915162639U;
            aOrbiterB = RotL64((aOrbiterB * 4626236858205178149U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 549770198518993876U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 756554555648070919U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16272320259614325355U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7298557532533152193U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3336802611342112013U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 14679103452120080499U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2314938232094714365U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12215066333571149153U;
            aOrbiterK = RotL64((aOrbiterK * 10747052773052630601U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7762752719356805046U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6519429915769040078U;
            aOrbiterC = RotL64((aOrbiterC * 15548676502167938513U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7556691736109752918U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13731245903412646404U;
            aOrbiterI = RotL64((aOrbiterI * 15581965016668635409U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 22U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 56U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 18U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20775U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 21170U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17896U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16685U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21314U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 4U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 27U)) + 9133751643283278896U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 53U)) + 8971581804375380408U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 57U)) + 12559650383714566592U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 18U)) + 15753206088872859163U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 43U)) + 7640756270450762350U) + aNonceWordI;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 7340073357551376125U;
            aOrbiterE = (aWandererE + RotL64(aCross, 37U)) + 5270256573644196046U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 3567367996479995928U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 53U)) + 11939634537492733738U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7051817732424527120U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1730487669951837941U;
            aOrbiterK = RotL64((aOrbiterK * 15191634337956285841U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18009252467909454817U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2361024272031696442U;
            aOrbiterG = RotL64((aOrbiterG * 15215151562500226027U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15902755877642960397U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12243517544704116184U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2576071074148141447U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16846181962302186187U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 636121425116506681U;
            aOrbiterB = RotL64((aOrbiterB * 17075030673338779993U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6887385655828217318U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3705834550934775862U;
            aOrbiterI = RotL64((aOrbiterI * 11275428284929594435U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11165142437077969438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6426659930331618269U;
            aOrbiterC = RotL64((aOrbiterC * 17170640810530893705U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12629082390899315789U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4277510580069574724U;
            aOrbiterD = RotL64((aOrbiterD * 9829125163412708305U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13814834144170469978U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3698381854100295826U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5126359230872258015U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 11623170635983579937U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7247413650388803796U;
            aOrbiterH = RotL64((aOrbiterH * 3403219499465560059U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 52U)) + aOrbiterH) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + aNonceWordB) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterD, 28U)) + aPhaseBWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26614U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((aIndex + 24947U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 22307U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24757U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25493U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 10U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererF + RotL64(aPrevious, 43U)) + 12029393034357490020U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 29U)) + 4526754731580694987U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 56U)) + RotL64(aCarry, 53U)) + 17060419646421271853U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 39U)) + 4128488893837059683U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 5U)) + 12706894827547160110U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + 12506324593645825056U) + aPhaseBOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 19U)) + 12581344490649250025U;
            aOrbiterI = ((((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 14357032418199130132U) + aPhaseBOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 52U)) + RotL64(aCarry, 37U)) + 15341977701796331249U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7086602307544733241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12398300065276832486U;
            aOrbiterB = RotL64((aOrbiterB * 18157408831225635333U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2499745046076601988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7249361592814001829U;
            aOrbiterD = RotL64((aOrbiterD * 14597139848072319685U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3254456186337366437U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3472973415969046680U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 14583566953969168353U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7905718972111691591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15941413652144021522U;
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 10583964125960308762U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 13659925272340853715U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 16708294803316630743U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9487054537489454887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13287757570441887517U;
            aOrbiterH = RotL64((aOrbiterH * 17351439045329892107U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15279245465808571942U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12424999114621745879U;
            aOrbiterF = RotL64((aOrbiterF * 2274918760256527137U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13915392738892970475U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13797668053788805126U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13752161103680525317U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14344766585550401077U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13727554194373146727U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 17164450431362670223U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterA, 50U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 38U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + aNonceWordD) + aPhaseBWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 4U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30772U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 29402U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30977U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31417U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28779U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 50U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 53U)) + 2330952702412094686U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 7820188225935060799U) + aNonceWordI;
            aOrbiterD = ((aWandererB + RotL64(aCross, 46U)) + 9347644591709839145U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 19U)) + 2288624878446846870U) + aNonceWordN;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 37U)) + 9358977729492824128U) + aPhaseBOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 1858511275052455039U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 13715478509322292552U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 16413396625604260455U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 24U)) + 17714322215518432705U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16188315436202861122U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5564445841368207813U;
            aOrbiterD = RotL64((aOrbiterD * 14125834616162835983U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13717068949900594673U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterB = RotL64((aOrbiterB * 17281441046722262917U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5729546141908425670U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4297827922736712074U;
            aOrbiterE = RotL64((aOrbiterE * 13631630436759768885U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 829520109395163673U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11547160328525174295U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2907177944512117206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11100346409065275671U;
            aOrbiterC = RotL64((aOrbiterC * 17927994356809011637U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1344592529249949068U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6470438516791143572U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13339390828725370475U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5217751823741520847U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5371275223586938039U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12318403075523724125U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14218103150268532919U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1367628876596800571U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13777531272321533137U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2372041991018455610U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9870744274890595581U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12093443117747395585U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 54U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 42U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterD, 58U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordC) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Soccer_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDC4775863A8E48C9ULL + 0xC82986D916556B7DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCA1AF2ADA1A3E653ULL + 0xA71B7447D8EA21FAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFBD66CC0E3292AEBULL + 0x9EF047FA0841DB79ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x90B91D2A1FF38A13ULL + 0xAD44828446625932ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB4B56990E047D3FFULL + 0x9DAF8C0B89F0FBADULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC75AF218770441FDULL + 0xD11C613E8177A4B4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xABED2AC44CE0C6E7ULL + 0xA40B8BF2D7FD4942ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF6789D61F1726005ULL + 0xFD3A475BB74030F9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA877A73EC08577FDULL + 0xD6AAAB8E8AC7DA59ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA398C0F54E213139ULL + 0xD157A379C94F04D1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8A726AD5FDD2D133ULL + 0xD12733FFC3CB1254ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBF6E3E9626818F3FULL + 0xCAEB2CAF1C98CFA7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFDFDD718F7F2C0F9ULL + 0x883CF177A961995DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF09D8EB24C0B9F87ULL + 0xD65CCDC2D6E047FCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD4B98D7B10E1DCE3ULL + 0xBDACCD8C11B7973FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB13877FA464E869FULL + 0xFDF41C1E8957DBABULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1029U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 4094U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 5195U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1680U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3384U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 411U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 47U)) + 5721224134332887360U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 6892749729775049095U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 30U)) + 3884839462099556836U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 57U)) + 4365431706830216193U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 15501528746571578773U) + aNonceWordL;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 39U)) + 4505911326320650606U) + aPhaseDOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 1865129050927879580U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2011737665969640369U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 611672935827062688U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12873671551304596619U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 663547038310431047U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5468932264754299556U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11968657455484578525U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17920294117231191705U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 486058453837528110U;
            aOrbiterF = RotL64((aOrbiterF * 8851102552244026737U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2789178451938129313U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 420772587981211184U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17402987842294006667U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16196774774442181825U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16264169656793713547U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 6900221986041638783U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10207659833859860796U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8593749091183323678U;
            aOrbiterG = RotL64((aOrbiterG * 10696776033512404927U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7224922076047787384U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15366267474865172373U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 10134187073321814217U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 37U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 48U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5608U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 8423U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8806U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 8571U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9451U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10532U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9464U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 5576732410244514238U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 5U)) + 2833808925935929629U;
            aOrbiterH = ((((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 47U)) + 3670188682914544792U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererK + RotL64(aCross, 57U)) + 15759072378887814995U) + aNonceWordL;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + 13934007231137439994U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 43U)) + 11022225696007690512U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 16989177104453635790U) + aNonceWordH;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9256930045263527091U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17788596104417068290U;
            aOrbiterH = RotL64((aOrbiterH * 675554110563253305U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17044369456673337625U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1310908395523250343U;
            aOrbiterA = RotL64((aOrbiterA * 16305084373037705921U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12067065689034065422U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15130844248737512262U;
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14532689204495587494U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8198147292120244178U;
            aOrbiterG = RotL64((aOrbiterG * 1418356389507740991U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 5485494458627163347U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10830008207150307611U;
            aOrbiterF = RotL64((aOrbiterF * 6526039534042499457U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17770065502486618029U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6397859353395335459U;
            aOrbiterJ = RotL64((aOrbiterJ * 14286997752368893825U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5128700697381508319U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7103394110057060499U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5053680689949149633U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 35U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14668U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 14668U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13774U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12002U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 12023U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 19U)) + 13583136155674166402U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 12830472187484919497U;
            aOrbiterD = (aWandererH + RotL64(aCross, 37U)) + 18081197909484522509U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 8680634051297891550U) + aNonceWordK;
            aOrbiterC = (((aWandererG + RotL64(aCross, 5U)) + 13939998767458656823U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 60U)) + 1795730579103692594U) + aNonceWordG;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 17369751719734069999U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 224769585901248068U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4133547085925268180U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2611561365156544735U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 7022512056309567391U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10319484359046945495U;
            aOrbiterI = RotL64((aOrbiterI * 3400140531307001933U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10483878349412282069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6481381149199985736U;
            aOrbiterB = RotL64((aOrbiterB * 9701719367082506253U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13721077228796934509U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 9704818014314175007U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 760445624027740287U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6253040047758584339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16890211690273641226U;
            aOrbiterG = RotL64((aOrbiterG * 5622534399866057841U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6216227831265032436U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2023609047004658739U;
            aOrbiterH = RotL64((aOrbiterH * 3252332895698310147U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 9201669637050388263U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5106927540934338576U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 6368134569042291431U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 40U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18873U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((aIndex + 20401U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20206U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19256U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18744U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 41U)) + 898812731947995389U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + 8677347622525527167U) + aNonceWordK;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 770321564027567654U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 35U)) + 11020474858081526395U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 29U)) + 17289793580414993470U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 29U)) + 10111912559295118444U;
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 8083622125544542011U) + aPhaseDOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7149858558922988240U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5919683821379905699U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16705119888884231567U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6860902846079238714U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 15083517836867542075U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 4686657139237578325U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14852868368708376381U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9860233289028878323U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 13418143547952204667U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 772406119079116272U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 7971141501337627589U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 10168120622976358617U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8478568022896691911U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4027604850785607101U;
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17199331557841535430U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7515957656979776361U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17138249294921502391U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16236812863923234668U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2925542836624164807U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterK) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 48U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aNonceWordA) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23647U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneB[((aIndex + 26365U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21882U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25913U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((aIndex + 22437U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 5906639480605353429U) + aNonceWordF;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 35U)) + 5293518570213287605U) + aNonceWordI;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 15383185501428521377U) + aNonceWordE;
            aOrbiterC = (((aWandererD + RotL64(aCross, 41U)) + 15364072512743978902U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 28U)) + 4525473357144014271U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 10400911938125603074U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 3U)) + 16417506293824627550U) + aPhaseDOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2419329331753341815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14929222427923332069U;
            aOrbiterD = RotL64((aOrbiterD * 11596261802662514979U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16771573504983922586U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1863466450051787622U;
            aOrbiterJ = RotL64((aOrbiterJ * 2585626547126027053U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12895350137096692415U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 3700979086526298327U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 10279730254867618193U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1977099106211282426U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6144698304096915742U;
            aOrbiterC = RotL64((aOrbiterC * 5039822990560519609U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3858895556659724975U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1283646340363435327U;
            aOrbiterF = RotL64((aOrbiterF * 11622421841377018069U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6240532051889108891U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 757364889381634634U;
            aOrbiterE = RotL64((aOrbiterE * 943852137901972945U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5272945693977418174U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6850528198786172283U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 1966383079897679953U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterB, 28U)) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31858U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((aIndex + 31937U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28951U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31245U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29451U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 12262991801139086177U) + aNonceWordD;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 51U)) + 7963038771924890197U) + aNonceWordJ;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 15540520327933568896U) + aNonceWordC;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 8745565892055020722U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 27U)) + 16619329199683755286U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 58U)) + 10865705026433867260U) + aNonceWordB;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 3U)) + 2743368697984518059U) + aPhaseDOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 5556006271515473135U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5355833281353498588U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4190140212757841511U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8313616108963479829U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16657121016801866434U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16532226425013000833U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5800465874932467232U;
            aOrbiterD = RotL64((aOrbiterD * 5966395771690704577U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17882948163883121328U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15029375310296563175U;
            aOrbiterJ = RotL64((aOrbiterJ * 17021415832288477713U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10170682648007918739U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11829089574189398773U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15755874363488568849U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1746524867389196322U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 10217423427886742775U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 9166162099575333519U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1338457710729082656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1319981417675542556U;
            aOrbiterG = RotL64((aOrbiterG * 9518448254565489715U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + aNonceWordE) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 12U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterH, 40U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 21U);
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

void TwistExpander_Soccer_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF60E6324A7541D6FULL + 0x9F5E900330766BE3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEC9D6DA81BA28987ULL + 0xE19E65856D15FA37ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x91C155FBBC596FB5ULL + 0x9D1B94B05EFF10D8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF12A9602B92A346FULL + 0xE60E6D5DED4AF7A9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA7879EBC811CCD6DULL + 0xB25861ED43F4FA65ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFBAFE541534A6FEDULL + 0xA84A348758258485ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB4B98A87971F37E7ULL + 0xA5E2A42A193A054BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8615C94AB4CDDA21ULL + 0xDBDB38B1CC62D2FEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x953A72D107587B35ULL + 0x9C04F0AF8E32DCDCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF54E52681E59D28DULL + 0x87D70D9880755A96ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDC0B7258F1E3791DULL + 0xB7FD02DC03D2B34AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x87259354DDD212D1ULL + 0x8EC3BE94B666A216ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEC20FC359589CB91ULL + 0x8AD26230F1B64B9DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x93301FE0CB628227ULL + 0xBFE65574C03E130BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEE49DF6929CCDC75ULL + 0xF8400FC1067A96A7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFDB525412A7C0E8BULL + 0xC884AD54540C702CULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4384U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((aIndex + 2672U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3877U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2601U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3172U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4524U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 38U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 29U)) + 13583136155674166402U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 13U)) + 12830472187484919497U) + aNonceWordK;
            aOrbiterI = (aWandererF + RotL64(aScatter, 5U)) + 18081197909484522509U;
            aOrbiterH = (aWandererG + RotL64(aCross, 60U)) + 8680634051297891550U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 13939998767458656823U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 39U)) + 1795730579103692594U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 53U)) + 17369751719734069999U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 224769585901248068U) + aNonceWordC;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 56U)) + 4133547085925268180U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 41U)) + 7022512056309567391U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 10319484359046945495U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10483878349412282069U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6481381149199985736U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 13721077228796934509U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9704818014314175007U;
            aOrbiterG = RotL64((aOrbiterG * 760445624027740287U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6253040047758584339U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16890211690273641226U;
            aOrbiterH = RotL64((aOrbiterH * 5622534399866057841U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6216227831265032436U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2023609047004658739U;
            aOrbiterJ = RotL64((aOrbiterJ * 3252332895698310147U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9201669637050388263U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5106927540934338576U;
            aOrbiterE = RotL64((aOrbiterE * 6368134569042291431U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10080368957861445998U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10784789383436485808U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3794918350254445939U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15426339824951793026U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17637144549368340331U;
            aOrbiterK = RotL64((aOrbiterK * 10971293914614704441U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9941300382181962134U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8118046374121322097U;
            aOrbiterC = RotL64((aOrbiterC * 8481945819050983127U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5138086185042567633U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7279942739248982986U;
            aOrbiterD = RotL64((aOrbiterD * 12911998308338410917U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12135610639038562853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12945353426409788798U;
            aOrbiterB = RotL64((aOrbiterB * 7434977715954413699U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7534876598022096222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13583136155674166402U;
            aOrbiterA = RotL64((aOrbiterA * 8194058098043157015U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterH) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterH, 48U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + aNonceWordM) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 22U)) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5856U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 8277U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10327U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 8714U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8627U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6853U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7641U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + 13296600294247799698U) + aNonceWordM;
            aOrbiterI = (aWandererE + RotL64(aIngress, 23U)) + 5818503518080877515U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 6735784238734173597U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 43U)) + 7368398209488856201U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 11U)) + 961734029066455638U) + aNonceWordA;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + 797011946660892011U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 13U)) + 12841876018396622350U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 37U)) + 16213253970483895623U) + aNonceWordH;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + 15186950557113470375U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 5117930310827477341U) + aNonceWordO;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 58U)) + 12265429373166094162U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13920531346698601568U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14695405206998211456U;
            aOrbiterG = RotL64((aOrbiterG * 13950964363414164279U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7851960904825938443U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9501511171732550190U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5614164120361489613U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5663365182245722077U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9607860124321315555U;
            aOrbiterE = RotL64((aOrbiterE * 3461820361914280601U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18171052650586819280U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3442698321538580861U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6317525514963824829U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1491052813469258970U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3956599824067616133U;
            aOrbiterC = RotL64((aOrbiterC * 2928600779267623085U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10963841237346073453U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2303020125591252534U;
            aOrbiterA = RotL64((aOrbiterA * 9969099842343321981U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14503856057958162356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11147548150090597694U;
            aOrbiterK = RotL64((aOrbiterK * 11856382308792700441U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9191681438318311481U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13556072770381999852U;
            aOrbiterF = RotL64((aOrbiterF * 18316231099054203683U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10103207278550444685U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10415809965217261104U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 16562732599511350217U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17435033201864058457U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5540494424887364682U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 18230910315317249045U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 18020151683897013854U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13296600294247799698U;
            aOrbiterH = RotL64((aOrbiterH * 10000194329456668845U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererI = aWandererI + (((((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 11U)) + aNonceWordD) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterC, 14U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13630U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 12667U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 11726U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13718U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 10945U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 6U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererG + RotL64(aCross, 41U)) + 7632760812370906911U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 36U)) + 6007174525479723089U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 53U)) + 3362829642521821048U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 39U)) + 18009548556107978286U;
            aOrbiterD = (aWandererA + RotL64(aCross, 43U)) + 17880909432272697327U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 15961567935420752568U) + aNonceWordG;
            aOrbiterK = ((((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 10136559064656837921U) + aPhaseEOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 22U)) + 17622019364405410277U;
            aOrbiterG = (aWandererB + RotL64(aCross, 27U)) + 6927494824421416306U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 7125170407794874847U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 13U)) + 12342273503071032250U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14997696377476124836U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14874498694181230698U;
            aOrbiterE = RotL64((aOrbiterE * 4026127545746010937U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2549397729130885686U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4217995818662767955U;
            aOrbiterD = RotL64((aOrbiterD * 5525525344485251063U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4706089044415442525U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17983900172670031015U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 541552737180932879U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1904937798143929988U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10620877287033139483U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16711012562024287213U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15681091173163181525U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2655543246639000084U;
            aOrbiterI = RotL64((aOrbiterI * 16686375598149755947U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2647895110857289213U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5581609212017175954U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 15330263616699031311U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13609076329627787987U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6244266279516622070U;
            aOrbiterC = RotL64((aOrbiterC * 12488345779236971095U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5289624364508923581U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16351476803965903112U;
            aOrbiterJ = RotL64((aOrbiterJ * 9012522724650442597U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2731198704224650506U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4177455951984414332U;
            aOrbiterG = RotL64((aOrbiterG * 2567165277406175517U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3031687737578718714U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4866790771642413883U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1139524449666360541U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12903299652398385014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7632760812370906911U;
            aOrbiterB = RotL64((aOrbiterB * 7924544687662448385U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterK, 48U));
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 26U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20322U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((aIndex + 20834U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16955U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21396U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21414U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 18302975933754610273U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 16736972646771456082U) + aNonceWordE;
            aOrbiterI = (aWandererA + RotL64(aScatter, 41U)) + 17389406266488137442U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 47U)) + 5252511566486165539U;
            aOrbiterH = (aWandererD + RotL64(aCross, 21U)) + 5730715427422747640U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 6412695646456045825U) + aNonceWordK;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 30U)) + 9539701605708994494U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 3U)) + 18355107116412945722U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 51U)) + 11735742491750132942U) + aNonceWordO;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 5U)) + 12363819388562658842U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aWandererF + RotL64(aScatter, 34U)) + 5861430292304371543U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15027487084595017708U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7012850020745791926U;
            aOrbiterI = RotL64((aOrbiterI * 15952928839355613939U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11904871669287886120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3856004502263742700U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3705931243173921893U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12305785390539209389U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18057980996551978823U;
            aOrbiterG = RotL64((aOrbiterG * 4850564181113470859U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3229431819292153014U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2994716629242460094U;
            aOrbiterA = RotL64((aOrbiterA * 1029427328395257917U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9796307843453735512U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2957260393651252432U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7261055869794739609U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4060469664218866340U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17462081697889685330U;
            aOrbiterK = RotL64((aOrbiterK * 7712009170974461225U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13638660073917821172U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15202349592659062565U;
            aOrbiterE = RotL64((aOrbiterE * 4514326257446024301U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12071949111168967041U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11930843273199806728U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 16229663295689525137U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11294220104731500296U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 440743185210586759U;
            aOrbiterF = RotL64((aOrbiterF * 14810195235168807229U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8514240764798061804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 18302975933754610273U;
            aOrbiterB = RotL64((aOrbiterB * 1972439346780950873U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 22U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterG, 46U)) + aNonceWordL) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterI, 28U));
            aWandererK = aWandererK + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererH, 48U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21975U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 25439U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26081U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24954U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24330U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 23380U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 10U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (((aWandererG + RotL64(aScatter, 21U)) + 3448371607470865612U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererC + RotL64(aCross, 19U)) + 3743742913651580573U) + aNonceWordJ;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 29U)) + 13069491287948807280U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 46U)) + 16872779275586545632U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 17945792656755062795U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 18199747196793731853U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 5U)) + 15953311878379809513U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 941268763494588338U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 51U)) + 10090221530365796809U) + aNonceWordO;
            aOrbiterK = ((aWandererF + RotL64(aCross, 41U)) + 8335698093307607001U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 10U)) + 6147498804734306100U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5980246079567570090U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4152167624425912978U;
            aOrbiterE = RotL64((aOrbiterE * 10019421651535123573U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14990418790239735916U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3418668387496597219U;
            aOrbiterH = RotL64((aOrbiterH * 12814077238529863119U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4206650904177199425U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3905470780938996069U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 16030122739273137005U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9968672788233080924U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 602258075661864866U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2615726693066300065U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17751667243048041383U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2414054413585296027U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 1049512574773201893U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6523322402744047752U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6729901917767398779U;
            aOrbiterJ = RotL64((aOrbiterJ * 8039939871405367139U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11460169185076814539U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7559640379553110573U;
            aOrbiterA = RotL64((aOrbiterA * 9864654321914036135U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17271150091827475028U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3541809324556914646U;
            aOrbiterC = RotL64((aOrbiterC * 12655168871428868639U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10332471447306597185U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12580133010006951091U;
            aOrbiterK = RotL64((aOrbiterK * 1159183486084705865U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17333553613777910945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14179392055698682109U;
            aOrbiterB = RotL64((aOrbiterB * 17675559451285279251U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3996830751779338356U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3448371607470865612U;
            aOrbiterG = RotL64((aOrbiterG * 5375529914102609947U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 38U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 30U)) + aOrbiterC) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27941U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 31694U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28650U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28608U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneB[((aIndex + 29587U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 36U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 53U)) + 13499155707765393469U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 29U)) + 3740324981823726185U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 50U)) + RotL64(aCarry, 3U)) + 5470765363949735652U) + aNonceWordN;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 3446436171274452326U) + aNonceWordC;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 1778929412631211933U) + aNonceWordD;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 21U)) + 14666308799855220954U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 34U)) + 4548410236791175055U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 11U)) + 5829739767694190372U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 39U)) + 14319231414903675748U) + aNonceWordP;
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 1513851750246111405U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 27U)) + 1685620217748986019U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16284162182006054402U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6271539598462003309U;
            aOrbiterG = RotL64((aOrbiterG * 13923286694131331137U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12669312437565969473U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 11894755313393001665U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6315983824634946566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17106616474222892782U;
            aOrbiterF = RotL64((aOrbiterF * 167205520766791073U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13350266700180455548U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4608846311203767162U;
            aOrbiterD = RotL64((aOrbiterD * 2504857468837437365U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14195866746143604365U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7917977448256795054U;
            aOrbiterH = RotL64((aOrbiterH * 5927771378657284557U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10707336923305131629U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17122696159336995392U;
            aOrbiterK = RotL64((aOrbiterK * 13953518568670659191U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5182322763573586116U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6503754948502556246U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14749002194140663519U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14907832047832987341U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6258064448676621346U;
            aOrbiterC = RotL64((aOrbiterC * 4407960312705621487U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1180234574888070795U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 801686887651085881U;
            aOrbiterI = RotL64((aOrbiterI * 433981853631548041U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11810494591997709554U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9343740505955858127U;
            aOrbiterB = RotL64((aOrbiterB * 8733378485648720323U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12816829575386720695U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13499155707765393469U;
            aOrbiterE = RotL64((aOrbiterE * 9937924703928730369U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 56U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 42U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 60U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Soccer_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD4AF4F2A528F85C3ULL + 0x89585379B4AB3800ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD1469F9D122EB8B5ULL + 0xB721B7D0C2AFB3A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9FE0DC89FD55A411ULL + 0xA15E8A4A2037DAABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x97048271796BB23FULL + 0xA1D73D59F1C21FBCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA0C468612AE1D1FFULL + 0xCC9ADB6F8ADE2395ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF6330934E8C3522BULL + 0xB96A050132A6C9C0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC12AA9A106831E4FULL + 0xB30E47BC7855A98BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB00B4222DD710351ULL + 0x8D2B047460EAC404ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFE8C540A66338C09ULL + 0xCAE19B3E7D63D35DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA07FD62573DF3943ULL + 0xAA811AE28F8565D8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xADF1F8D54B5CBBD9ULL + 0xB7BC5F0F2154E048ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8CB04F3E0FFA5F1DULL + 0x98D73B84B5D22F75ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x84CE0410C92D3BB1ULL + 0x834CE58951C92E5DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9A9A63D67554A823ULL + 0xA76309D173D30F90ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA2581A9EA420D2DFULL + 0xFAA634D5F223BA60ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8F117A54FDF04AA5ULL + 0xCDF2AE18EC767B87ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneC, aInvestLaneA, aWorkLaneC, aSnowLaneD, aInvestLaneC, aExpandLaneA, aSnowLaneA, aExpandLaneB, aInvestLaneD, aExpandLaneC, aSnowLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4060U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 3583U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 278U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4598U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5348U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3156U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 27U)) + 4773124477323378268U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 53U)) + 16848723289435796005U) + aNonceWordI;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 39U)) + 13846642134917107058U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 43U)) + 6472057872482789939U) + aNonceWordM;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 47U)) + 2747019500690707226U;
            aOrbiterA = (aWandererC + RotL64(aCross, 57U)) + 9003965289739733880U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 3013390651936257377U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 22U)) + RotL64(aCarry, 5U)) + 3331004709895625067U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 43U)) + 15355010435553517129U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7709870658004280052U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13568728443963926564U;
            aOrbiterE = RotL64((aOrbiterE * 6736090830113688981U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 12409548853419307131U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 969183352023661537U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5549220554838837145U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15370309834426476775U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3896803894396631184U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 11018830202891911603U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10848873633291935766U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12885336509190543440U;
            aOrbiterD = RotL64((aOrbiterD * 1487357252619221365U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8252290890093788010U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9201553615601641350U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 420321130559162915U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14014209645503188472U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4015071464301844550U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17444195018239904971U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16173085647514027347U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16916627014974363360U;
            aOrbiterH = RotL64((aOrbiterH * 7699587344277490953U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1591680303404522110U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16499606051269327916U;
            aOrbiterK = RotL64((aOrbiterK * 814405848002794813U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6932673635509444619U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8745681160108707944U;
            aOrbiterF = RotL64((aOrbiterF * 14565255558668084787U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + aNonceWordP) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 52U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 54U)) + aOrbiterC) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6343U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 8315U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8531U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 9729U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10329U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6024U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 6436U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 42U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 43U)) + 6318740973868639425U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 5U)) + 5487840061430920881U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 18U)) + RotL64(aCarry, 13U)) + 10258706763248072672U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 23U)) + 18356875269730338208U) + aNonceWordK;
            aOrbiterC = (aWandererK + RotL64(aCross, 47U)) + 12883160282903147010U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 1010140474942697730U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 27U)) + 17733939421700898293U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 60U)) + 13693055887924981201U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 14574732452793385269U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 10832873941223609012U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8212600587135328040U;
            aOrbiterK = RotL64((aOrbiterK * 5334613996794796145U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5312744319781971178U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6173741211706546923U;
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3693249147883790810U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18365859989736602556U;
            aOrbiterH = RotL64((aOrbiterH * 3348463719324104997U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10645056678337549771U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1175668356822251045U;
            aOrbiterA = RotL64((aOrbiterA * 6579675292775345579U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13556844570541823717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4790355739411849736U;
            aOrbiterB = RotL64((aOrbiterB * 4083544011788850307U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14905575502272644116U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17047244574558476634U;
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10161614295718414869U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13413914082651612468U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16224039093981079491U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6072693130156927774U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4333656233793103787U;
            aOrbiterI = RotL64((aOrbiterI * 9374745547133955709U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17209776289202130250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11752001118070361543U;
            aOrbiterG = RotL64((aOrbiterG * 4416523594812872339U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 4U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordA) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 20U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 56U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12630U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 10971U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 11955U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12859U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 12038U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 38U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 44U)) + 15726877954695761686U) + aNonceWordK;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 57U)) + 14187652171881943587U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 51U)) + 8420423151313882782U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 14942322692433259283U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 10U)) + 7272331475919796255U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 154504365041805840U) + aNonceWordM;
            aOrbiterH = ((aWandererA + RotL64(aCross, 5U)) + 17475491222554948786U) + aNonceWordO;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 5759181483165339605U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 29U)) + 5993060214499322845U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10901786237875941844U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17135786595614068473U;
            aOrbiterB = RotL64((aOrbiterB * 15923538730142047043U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5208202073886811165U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6821452921018900631U;
            aOrbiterK = RotL64((aOrbiterK * 13119330055184115669U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13348064837402206969U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 8967943922403445136U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 300168481725373093U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8130283784171430891U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6351113882502502876U;
            aOrbiterF = RotL64((aOrbiterF * 15960622823993072903U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 6894708729226455769U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12065058511247133944U;
            aOrbiterA = RotL64((aOrbiterA * 5432601727436935831U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17138279326229372741U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12987698199066890628U;
            aOrbiterG = RotL64((aOrbiterG * 12665716655177320977U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13688833537574196675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4211971980434000618U;
            aOrbiterJ = RotL64((aOrbiterJ * 1374411763361518851U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10376917117582537592U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4807742522197923516U;
            aOrbiterC = RotL64((aOrbiterC * 15257251453302090961U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18038296468177121243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6879666349379745258U;
            aOrbiterH = RotL64((aOrbiterH * 15819475269715810555U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 48U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterH, 18U)) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 12U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + aNonceWordP) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20841U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneC[((aIndex + 21532U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 20448U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21764U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((aIndex + 20327U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 41U)) + 13442819395490639310U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 36U)) + 8187292523194120936U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 47U)) + 11469697159823131388U;
            aOrbiterC = (aWandererE + RotL64(aCross, 5U)) + 13414083692375929653U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 11404010733687907517U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 13U)) + 6783212827186218247U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 8561131439340372614U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 23U)) + 6252609642004429113U) + aNonceWordG;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 19U)) + 12804867444200448952U) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2739648749603690781U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14808861217017399752U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 373911885694012101U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17588866502571268888U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5882260142735642980U;
            aOrbiterG = RotL64((aOrbiterG * 7688252946143263869U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 15493099088132862949U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5175647411532429582U;
            aOrbiterH = RotL64((aOrbiterH * 15226544495598541883U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14279707376173642767U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6826363572161275158U;
            aOrbiterJ = RotL64((aOrbiterJ * 5263708315440161809U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13267185753040999992U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9980987858092888720U;
            aOrbiterE = RotL64((aOrbiterE * 13210290848800728635U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3582972937645514549U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10140409019562890804U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 6944490201647678479U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6160444117287330557U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16344602960561293113U;
            aOrbiterK = RotL64((aOrbiterK * 2319964919335633293U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3497141036108337171U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 91269118352540308U;
            aOrbiterF = RotL64((aOrbiterF * 5160060720189045505U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12739932748793144857U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12820180915064791197U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5843849637411948699U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 52U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 24U)) + aOrbiterE) + aNonceWordE) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26157U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneD[((aIndex + 26441U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 22351U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26081U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 23639U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 5U)) + 8988572360732005217U) + aNonceWordN;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 17889613225105985335U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 19U)) + 15563478320513948626U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 24U)) + 3441351228410524816U) + aNonceWordF;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 4425592689451435346U) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aCross, 57U)) + 12733160231627305928U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 35U)) + 3574152157304607854U) + aNonceWordM;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 15167631896729808783U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 10U)) + 15822667973915417055U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17181685481076577637U) + aNonceWordA;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 9979204751408873468U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1334240485667164762U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9190066751460137016U;
            aOrbiterK = RotL64((aOrbiterK * 14585141844653660363U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15465215829109246336U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2305208282453624419U;
            aOrbiterD = RotL64((aOrbiterD * 10257861974108363283U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16951510027310993926U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11117938943423526901U;
            aOrbiterH = RotL64((aOrbiterH * 7805486716716924787U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12461379120662979432U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11719697049048823897U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 14880996802304818757U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6843357278142933570U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12727898578324702374U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9786435451654365097U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18127999660067652233U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11754709060558683082U;
            aOrbiterI = RotL64((aOrbiterI * 12798744012150745847U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16940151146420516184U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12924950783056761895U;
            aOrbiterB = RotL64((aOrbiterB * 8898170377271926745U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14829713915929878471U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 840466047621042565U;
            aOrbiterG = RotL64((aOrbiterG * 10748511630509529489U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterK, 54U));
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 39U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 48U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aSnowLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29078U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 31627U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 30832U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28524U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 27401U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 11U)) + 12206125048349568300U) + aNonceWordJ;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 19U)) + 5843520589343188818U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 12195046124287121687U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 39U)) + 16769779119214020640U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 5U)) + 5257603646260695833U) + aNonceWordL;
            aOrbiterK = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 8523523946234886745U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 41U)) + 7316024684200084096U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 51U)) + 11996978575084115207U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 56U)) + 15491711479085513628U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6036648530996821484U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 926323222234121863U;
            aOrbiterB = RotL64((aOrbiterB * 6639661141258803779U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2700323841295743492U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 5852273765810284935U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 16665696735016345215U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11697397483133538067U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17777142964957007194U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 6338967222543284999U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10892176201151170298U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11759700374509499684U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 14247697264744736081U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11343756773329590643U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15785048929757652350U;
            aOrbiterD = RotL64((aOrbiterD * 17208103574389502597U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7508839228498497238U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13088508510402094665U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15730279447009669103U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16259236641717377699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11228995722951003980U;
            aOrbiterJ = RotL64((aOrbiterJ * 4870092259515181323U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13775851561528617086U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3023564646900497080U;
            aOrbiterF = RotL64((aOrbiterF * 9936548213275464131U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 154952467284609583U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14239675888632174461U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1370550680736926425U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 36U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Soccer_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC4206D2891B87243ULL + 0x8C968BD3CF62F72CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD2AAB15731666099ULL + 0xB1304C14E0EDACF7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAC98197E3FBDD695ULL + 0xAEE2F951F0AE70AFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDC33AF4A79CB35E5ULL + 0x867F5AFA0A185109ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEF6BF00E6FAB12C3ULL + 0x881D65A8C7F1C3C4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE69E717A2FFF1A6FULL + 0xD992163DB998E9BBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x92D17004CD1F5411ULL + 0xEDBE8EB7ACD872E7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC578E8B7F077BB29ULL + 0xF4E84912730A14CAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8E66AF0F040F6C09ULL + 0xD468B4E854E92569ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF1A087FE9950C2FFULL + 0xCFF850D1DED028E5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCAEE8F5936098033ULL + 0xE81AF86BF1FFE87EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDC11CDC401E686ABULL + 0xD68C23AB2EC7D3DDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9F035849D09D0A3DULL + 0xC662CFDF1E6F4112ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB7D94DC5FD2E0349ULL + 0x9F182DA2C8CA2EC9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9F00519795361FDDULL + 0xDA296C4404180FB7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD4CD5905372C633FULL + 0xB3F42DBFD03FF191ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aFireLaneA, aWorkLaneA, aFireLaneB, aInvestLaneC, aWorkLaneB, aInvestLaneD, aExpandLaneA, aInvestLaneA, aExpandLaneB, aInvestLaneB, aExpandLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4521U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneB[((aIndex + 1604U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4660U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 4209U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 559U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 2714U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 4U)) + 12122689833405846292U) + aPhaseHOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 9640400270962766788U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 35U)) + 9141937998266739071U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 12899395770434090537U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 13457918115408031842U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 47U)) + 15134784483576000943U) + aNonceWordH;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 41U)) + 12540961268790055438U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6306886773092764230U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13573343491337243121U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 15893457012357368707U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 8545588657348974413U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10891410570357275120U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5399310978367842841U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2877137119767060151U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9178097682386595144U;
            aOrbiterI = RotL64((aOrbiterI * 3524486002084427513U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15528007881855616978U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11368419529245281435U;
            aOrbiterA = RotL64((aOrbiterA * 12433207037378339309U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5932738914934356645U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5551842263864055419U;
            aOrbiterE = RotL64((aOrbiterE * 16093776759971522681U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 3824433359595690603U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17184628855571662441U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 691208053136187317U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8724462245014132623U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7481349499528092352U;
            aOrbiterK = RotL64((aOrbiterK * 8212182934509617583U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aScatter, 22U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 6U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6959U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 7854U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9734U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 8218U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6986U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8948U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 8005U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 29U)) + 7790166497945719700U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 7136208896846119188U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 12123156943355100886U) + aNonceWordC;
            aOrbiterG = (aWandererI + RotL64(aIngress, 41U)) + 5095546037880875199U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 19U)) + 17642705393916765992U) + aNonceWordI;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 58U)) + 9918479837334416990U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 4890009823843176466U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17652590786213674124U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 870002527644696135U;
            aOrbiterI = RotL64((aOrbiterI * 915408393979165539U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12545429703552643682U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5310272867406182581U;
            aOrbiterK = RotL64((aOrbiterK * 10420003334833925011U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3264719049050179440U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1967241238180278937U;
            aOrbiterF = RotL64((aOrbiterF * 13004319774269457957U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 773883832927040736U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12766817190261232485U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7448864556802318431U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 260069382395598265U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15462103891287350123U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5029268763635635753U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4072032867513289827U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17153061419083897076U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 11934532169271718913U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6207264270332656966U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18048064697837314947U;
            aOrbiterA = RotL64((aOrbiterA * 13632594619404208489U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 40U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + aNonceWordK) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 10943U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 14255U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16299U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13045U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15223U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 29U)) + 16802219662864902427U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 58U)) + 14332033461409490629U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 23U)) + 8781794298640286845U;
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 8459933908074937264U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 1883580287986004426U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 17500258188004626118U) + aNonceWordM;
            aOrbiterA = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 7934811305150872870U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 6380363892361098905U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12623079132626676910U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 12406671746344127399U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 10455208121949202703U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8805532707916767629U;
            aOrbiterG = RotL64((aOrbiterG * 666082374369701881U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9161544391400377699U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3501434325829663268U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7933545151293799637U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 651783304096081996U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 441505031509930622U;
            aOrbiterH = RotL64((aOrbiterH * 8045355432310956143U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1771159983581326424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15227946417377695989U;
            aOrbiterB = RotL64((aOrbiterB * 1563141188972797601U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4153717524193279095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4404521756523902829U;
            aOrbiterA = RotL64((aOrbiterA * 1410342912973206203U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6231945075461813285U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3864780227164426690U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18031353247480673617U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 34U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + aNonceWordE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17649U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 17097U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21081U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18262U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((aIndex + 20717U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 12775735908960052604U;
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 11791373812080296887U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererF + RotL64(aCross, 57U)) + 5537362877706057303U) + aNonceWordO;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 43U)) + 2023912048504189380U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 17668828109963766893U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 36U)) + 558908629933941224U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 21U)) + 1479633119685446888U) + aNonceWordP;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15460320397843364063U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10059749397555469054U;
            aOrbiterB = RotL64((aOrbiterB * 8671817118586065469U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 9987633811929693924U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4446204415503364254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 9430197906134676162U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1226048679997253363U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 14247538885252664127U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10611580584157624739U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 3137391249289641509U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9327201928815412810U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7890659377013147073U;
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10675114832750356941U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8804440385852327267U;
            aOrbiterF = RotL64((aOrbiterF * 8520671775587260601U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 26U)) + aOrbiterB) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22744U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 22089U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 22889U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27120U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24479U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 13U)) + 785861751704720606U;
            aOrbiterA = ((((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 15968088718435606299U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererK + RotL64(aCross, 35U)) + 1393976526590347151U) + aNonceWordA;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 17240750947292745884U) + aNonceWordL;
            aOrbiterE = (aWandererH + RotL64(aCross, 27U)) + 4921576136163183137U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 51U)) + 3334047873553153032U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 21U)) + 15086509978458408698U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 892391205397581998U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2965686403183767521U;
            aOrbiterH = RotL64((aOrbiterH * 709160942482770225U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14632215393655706170U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15740589515342377322U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15677716942904794913U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11131164813943086445U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6988080581278900960U;
            aOrbiterI = RotL64((aOrbiterI * 6412189142344044255U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16021254613117657178U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6183615599897921154U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 9976411093264211033U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12533992547026652747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3104325358982904219U;
            aOrbiterD = RotL64((aOrbiterD * 14977348108778147265U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3878525937957474644U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2120435259884368445U;
            aOrbiterK = RotL64((aOrbiterK * 15964718652193073177U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 14928658302694194856U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9121310461310309348U;
            aOrbiterA = RotL64((aOrbiterA * 17304439784647477491U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 42U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + aNonceWordN) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 60U)) + aOrbiterE) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 54U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30332U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 30839U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31165U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31561U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30168U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 57U)) + 10336802574069791273U) + aPhaseHOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 21U)) + 169025388197058936U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 43U)) + 6541354188379168846U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 16223920526599306104U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 12756613707692514808U) + aNonceWordK;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 37U)) + 5082475548176484035U;
            aOrbiterG = ((((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 27U)) + 4907435526952698526U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14236627073831834337U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11502511046130497584U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3460330807286625917U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3679044835550219497U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11254838916686736746U;
            aOrbiterD = RotL64((aOrbiterD * 8631695922983532915U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10582608424233200966U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10449735026385340313U;
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4628253464169957835U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17664454668473204465U;
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3798386391743884889U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1379331161819246587U;
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9816600392407327227U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 12U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 23U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + aPhaseHWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Soccer_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2457U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1198U)) & W_KEY1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 373U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2361U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 3U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 8375305456876489425U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 11U)) + 16193562952772453047U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 37U)) + 18088652458594816223U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 42U)) + 767344788620249944U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 7705194930396368752U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 3829736891311272834U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 3U)) + 9881681671347640061U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 30U)) + 1721196560190164264U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 3002652618388454213U) + aPhaseAOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9811621464004005202U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5652598941069986530U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4797973356708091621U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6250499348327316328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16025054277615264530U;
            aOrbiterB = RotL64((aOrbiterB * 16446892258704281903U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13800298546867243172U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12256104592865905782U;
            aOrbiterC = RotL64((aOrbiterC * 16983140179497142713U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17817225416918329229U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17738671327352776217U;
            aOrbiterE = RotL64((aOrbiterE * 393488251327705063U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6816031224188400541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16989563985059237014U;
            aOrbiterA = RotL64((aOrbiterA * 8677884225771717797U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16891524847268207549U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1833508573940405571U;
            aOrbiterJ = RotL64((aOrbiterJ * 9709196587703979539U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12729999421507068973U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6839758643521968957U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16350557395881283975U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8524167125469267428U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14741523560290472617U;
            aOrbiterK = RotL64((aOrbiterK * 4367850822282205897U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10983798459868424892U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5649250846622078964U;
            aOrbiterG = RotL64((aOrbiterG * 7149612714806023987U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + ((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterC, 34U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 39U)) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3371U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 5356U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4511U)) & W_KEY1], 24U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3415U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 39U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + 7270044678408187242U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 10192278965379756766U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 43U)) + 17568666746676060748U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 14312927531124963037U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 39U)) + 9825825726152087706U) + aPhaseAOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 11U)) + 9696778570255265896U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 17657841352013417228U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 24U)) + 16207815085909628439U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 51U)) + 1752979206374514227U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10456310689643905854U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16127830548663742550U;
            aOrbiterE = RotL64((aOrbiterE * 4355938404839045417U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2940917376003930842U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7353596864777649953U;
            aOrbiterJ = RotL64((aOrbiterJ * 7499468723171042005U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12725092740446150705U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5791296650856037010U;
            aOrbiterH = RotL64((aOrbiterH * 760379251950502133U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1200130368046206150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16689604428598558547U;
            aOrbiterC = RotL64((aOrbiterC * 13815324235939996623U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14359561591103730856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3975025843599045263U;
            aOrbiterK = RotL64((aOrbiterK * 5025047888533298617U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14017901732955607601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10431526786489555196U;
            aOrbiterG = RotL64((aOrbiterG * 10181915874476132407U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7320527073559849223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15333411223710709907U;
            aOrbiterB = RotL64((aOrbiterB * 3488684905528068775U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14302474063321663801U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2104154521019935187U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12944382959742278055U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5167600586916325228U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4566823109447208716U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9997799807454267443U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 22U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 56U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterI, 60U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7979U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 5667U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6506U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7644U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6728U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 52U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 8402620908307642697U;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 11347672014525086047U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 42U)) + 2816462912503401876U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 6940159795470696093U;
            aOrbiterI = (aWandererK + RotL64(aCross, 19U)) + 9134692490095883851U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 11U)) + 4999455497008026526U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 29U)) + 5992451460350651332U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 47U)) + 3417087346651371924U) + aPhaseAOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aScatter, 38U)) + RotL64(aCarry, 43U)) + 3612773820086198270U) + aPhaseAOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 463398077083428570U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11249391303705089012U;
            aOrbiterJ = RotL64((aOrbiterJ * 7106735772303292983U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17027535139825739501U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 568131384979596481U;
            aOrbiterI = RotL64((aOrbiterI * 5683451044852895957U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4793712537158004047U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10415170179135963622U;
            aOrbiterB = RotL64((aOrbiterB * 13729564030210361415U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2391473979460065630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4240058362680064261U;
            aOrbiterD = RotL64((aOrbiterD * 12375884373396400889U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9963957011090031698U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3325305624067445525U;
            aOrbiterE = RotL64((aOrbiterE * 3128542681461806309U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2094945647665114693U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10703615640774042674U;
            aOrbiterA = RotL64((aOrbiterA * 12641986098450423751U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3768738815518590289U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15021301790376706827U;
            aOrbiterF = RotL64((aOrbiterF * 14445850924223550339U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10571246886181608316U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5130325144599151793U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3185251943547657467U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8617523421720966373U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16574597770835250074U;
            aOrbiterK = RotL64((aOrbiterK * 1759209403428937799U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + aPhaseAWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 39U)) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 4U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 12U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8322U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 9020U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 9336U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 10046U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8441U)) & W_KEY1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9034U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 36U)) + RotL64(aCarry, 57U)) + 5173905450211892891U;
            aOrbiterD = (aWandererG + RotL64(aCross, 27U)) + 3555542451908039957U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 11559884700283861559U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 11U)) + 1352524329968738673U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + 8914206450420616349U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 57U)) + 2251523378498463946U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 23U)) + 9541575923299247038U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 1239854507907214595U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 48U)) + 17698101462598498934U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12305566971683256060U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13804545036303215569U;
            aOrbiterE = RotL64((aOrbiterE * 10359543704152744971U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10239749097704329264U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4212214906286320308U;
            aOrbiterG = RotL64((aOrbiterG * 3661436621615751071U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12192418916967430783U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4475514289326450361U;
            aOrbiterI = RotL64((aOrbiterI * 17497164630368757887U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17376102613298827459U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 18129393209955439341U;
            aOrbiterB = RotL64((aOrbiterB * 6404089025014118979U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4014763724300253568U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17325007199676828814U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1420888274815627083U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15480474849292388685U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14357924730184375449U;
            aOrbiterK = RotL64((aOrbiterK * 16723492259068034209U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4335731868597970070U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8296023680394303015U;
            aOrbiterA = RotL64((aOrbiterA * 14027415401430120543U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2807312426993262800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15510369660839648501U;
            aOrbiterH = RotL64((aOrbiterH * 18207954408298333959U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12597844696606519907U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7231012798553551535U;
            aOrbiterJ = RotL64((aOrbiterJ * 2841306785994479299U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 54U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterI, 14U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 22U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 58U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 36U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12485U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 11201U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11429U)) & W_KEY1], 28U) ^ RotL64(mSource[((aIndex + 12668U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11293U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12055U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12976U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 57U)) + 1888427424966603593U) + aPhaseBOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 29U)) + 5436761445660415091U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 17322876217962143270U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 39U)) + 9728299982740564979U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 301720335271716921U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 47U)) + 8069685428854814396U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 1973715500949100991U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 42U)) + 87666408799854155U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 12195436904339035245U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4578742069143400295U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7828776048774876484U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4047964518501081039U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17203146364542781833U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16913369550858890466U;
            aOrbiterF = RotL64((aOrbiterF * 13534417587921978507U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9632761514552265402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9106637671877341286U;
            aOrbiterA = RotL64((aOrbiterA * 9073709119482640391U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15423680889126750876U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6087310684583331882U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8964465129744898619U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5420955876411796789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14166807419730848032U;
            aOrbiterB = RotL64((aOrbiterB * 442659738632823751U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8118312450347026824U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4253043584558403086U;
            aOrbiterH = RotL64((aOrbiterH * 5651748455190536467U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8810774678371762700U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12218479555589447835U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11026364205248516355U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11389930523582876358U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16334420553471379915U;
            aOrbiterG = RotL64((aOrbiterG * 13830132212033904777U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18201289372553710279U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7196540389657785361U;
            aOrbiterC = RotL64((aOrbiterC * 13058135202554889791U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 30U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 14U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16329U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14876U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16099U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14207U)) & W_KEY1], 58U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14903U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15362U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13708U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 56U)) + RotL64(aCarry, 3U)) + 11210042748013785976U) + aPhaseBOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 19U)) + 4584747303233477454U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 8878765929792969517U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 2172232330280041122U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 27U)) + 8378937026022264016U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 13U)) + 8683007464695824208U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 9564352997357118134U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 51U)) + 11713878436769887528U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 39U)) + 8052917623074021077U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7720597162792145185U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2602847785328475621U;
            aOrbiterF = RotL64((aOrbiterF * 14065077077207224525U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17813669222300509724U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8724263063156573013U;
            aOrbiterC = RotL64((aOrbiterC * 3632927017737834359U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6882429835961613492U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13213313479525717359U;
            aOrbiterE = RotL64((aOrbiterE * 2411431247725974895U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2401526093648669573U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3616448566579979749U;
            aOrbiterH = RotL64((aOrbiterH * 13323155103752121393U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18268262471839710401U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5116424918948694752U;
            aOrbiterG = RotL64((aOrbiterG * 7641143782996332069U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11405305689555640431U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12427591396711015574U;
            aOrbiterJ = RotL64((aOrbiterJ * 8112834135715541223U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16960781161508084626U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12382604781005282628U;
            aOrbiterB = RotL64((aOrbiterB * 17196168631120103115U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10054839091354729292U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4167641616532985407U;
            aOrbiterK = RotL64((aOrbiterK * 919291747187787625U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14383737233143309039U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16258779988369405932U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8348773195366160215U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 12U));
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterH, 22U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17049U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 16564U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 18376U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17525U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17700U)) & W_KEY1], 57U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18277U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17958U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 20U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 5041131702736607991U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 18U)) + 9295010428212681446U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 43U)) + 6235875895358766017U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 39U)) + 2622227802531866918U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 3888894734834524972U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 51U)) + 241682012014701753U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 29U)) + 15758000422451568079U;
            aOrbiterG = (aWandererG + RotL64(aCross, 47U)) + 2061944548396976912U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 24U)) + RotL64(aCarry, 37U)) + 8177144990755754531U) + aPhaseCOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 554978075608818497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 250408260560714933U;
            aOrbiterJ = RotL64((aOrbiterJ * 1295379390497107727U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8700027645880997552U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10026130047465480902U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12417270861933696623U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9785843014096326696U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9998582683258411251U;
            aOrbiterE = RotL64((aOrbiterE * 7197956237569462269U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13817734599383455151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6647207154174092691U;
            aOrbiterH = RotL64((aOrbiterH * 1578528131687283531U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4957715980509035719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4994885315786213197U;
            aOrbiterB = RotL64((aOrbiterB * 5676683798126497011U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5072908311783966503U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5535039946192891515U;
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6594577050344146271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8750154123258714856U;
            aOrbiterI = RotL64((aOrbiterI * 6942158167127532003U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3514769314840874873U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8626045200273524281U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4315441782689789689U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8524870284841706517U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1841819423572964209U;
            aOrbiterG = RotL64((aOrbiterG * 9802481758007234681U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 48U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 12U));
            aWandererF = aWandererF + ((((RotL64(aCross, 12U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 20U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19265U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((aIndex + 20387U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21296U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20120U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19174U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21194U)) & W_KEY1], 11U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19937U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 20566U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 4773124477323378268U) + aPhaseCOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 16848723289435796005U;
            aOrbiterH = (aWandererC + RotL64(aCross, 12U)) + 13846642134917107058U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 35U)) + 6472057872482789939U;
            aOrbiterD = (aWandererF + RotL64(aCross, 51U)) + 2747019500690707226U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 19U)) + 9003965289739733880U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 23U)) + 3013390651936257377U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 47U)) + 3331004709895625067U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 51U)) + 15355010435553517129U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7709870658004280052U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13568728443963926564U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6736090830113688981U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12409548853419307131U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 969183352023661537U;
            aOrbiterA = RotL64((aOrbiterA * 5549220554838837145U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15370309834426476775U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3896803894396631184U;
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10848873633291935766U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12885336509190543440U;
            aOrbiterD = RotL64((aOrbiterD * 1487357252619221365U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8252290890093788010U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9201553615601641350U;
            aOrbiterB = RotL64((aOrbiterB * 420321130559162915U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14014209645503188472U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4015071464301844550U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17444195018239904971U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16173085647514027347U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16916627014974363360U;
            aOrbiterJ = RotL64((aOrbiterJ * 7699587344277490953U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1591680303404522110U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16499606051269327916U;
            aOrbiterG = RotL64((aOrbiterG * 814405848002794813U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6932673635509444619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8745681160108707944U;
            aOrbiterI = RotL64((aOrbiterI * 14565255558668084787U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + ((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + aPhaseCWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterF, 56U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterB, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22492U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 22237U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23150U)) & W_KEY1], 54U) ^ RotL64(aFireLaneC[((aIndex + 21846U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22631U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23752U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23331U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneB[((aIndex + 23181U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 53U)) + 4970414922752555648U;
            aOrbiterI = (aWandererG + RotL64(aCross, 21U)) + 9462756592787669327U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 3948790686662213095U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 58U)) + 14542857212241578311U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 47U)) + 3387479009827029547U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 37U)) + 1411421370057797877U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 16894451466895681236U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 28U)) + RotL64(aCarry, 19U)) + 12727136462290223542U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 13U)) + 4625389198191960525U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3471881403786164913U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6433115856048534831U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9363233870194144053U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9825592965466157982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1553125767261293088U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 411535191177308781U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9951616357109647617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11231080382787286889U;
            aOrbiterH = RotL64((aOrbiterH * 14024961994986659187U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13419663264017317947U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4835055642466215566U;
            aOrbiterI = RotL64((aOrbiterI * 17898065852351759171U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14558747666410946768U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13120938960926874504U;
            aOrbiterJ = RotL64((aOrbiterJ * 5681766019285559739U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11910501376797343986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15074100100781785300U;
            aOrbiterF = RotL64((aOrbiterF * 228976960937473851U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12415377930578091821U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14882039078390681802U;
            aOrbiterD = RotL64((aOrbiterD * 13855446647753150713U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8094338361713756895U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5478280604704108822U;
            aOrbiterK = RotL64((aOrbiterK * 18062931724700600993U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6977017654546871841U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4131602217285988962U;
            aOrbiterE = RotL64((aOrbiterE * 11865422227883712419U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterE, 56U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD + ((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 28U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26097U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 25482U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25809U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25673U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24869U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26565U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25689U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24951U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 4U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 11U)) + 10812151398716051703U) + aPhaseDOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 18202551453336003710U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 42U)) + RotL64(aCarry, 57U)) + 9434410809101973752U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 12955829998028534045U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 51U)) + 12271740641929640181U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 29U)) + 14009351527014534752U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 23U)) + 4316296955679133450U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 46U)) + 16473324966997442872U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 15735123324965019802U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17656375090484080236U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16066325053456055298U;
            aOrbiterD = RotL64((aOrbiterD * 17912970706985130327U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12908968778503516903U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12761433987676836197U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1023329467480907925U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12737513138040664509U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14535795767570998392U;
            aOrbiterK = RotL64((aOrbiterK * 15560519667062222269U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14370908061811284364U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7001358781208669795U;
            aOrbiterC = RotL64((aOrbiterC * 11641248025734015835U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7298578161120090849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10498302152357484629U;
            aOrbiterH = RotL64((aOrbiterH * 13144110412179037175U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11447343228638006767U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18284143620422655675U;
            aOrbiterF = RotL64((aOrbiterF * 572862190073605651U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5918253208127360199U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3910541329178205943U;
            aOrbiterG = RotL64((aOrbiterG * 4550654545328228103U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10357053096941367910U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5610891501128498748U;
            aOrbiterE = RotL64((aOrbiterE * 8676370811772047449U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9049881176058575811U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6307599924966452216U;
            aOrbiterJ = RotL64((aOrbiterJ * 5551444450572055895U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterK, 46U)) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 42U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterF, 4U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27340U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneD[((aIndex + 27658U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29171U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28155U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28891U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28072U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29039U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29776U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 39U)) + 17264605017518259932U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 15209184354580778643U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 3299527965014731384U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 56U)) + 16293096431816127821U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 11031983436878828337U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 21U)) + 9188018632448236358U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 13420816400363406556U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 28U)) + 2485063384097917101U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 3089135816938128264U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10730544971770435788U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10431767565618874806U;
            aOrbiterA = RotL64((aOrbiterA * 4723078464590561545U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14883796491656899074U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13465877783538483706U;
            aOrbiterD = RotL64((aOrbiterD * 14311686051108108503U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13322163435314643713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3307316600284371955U;
            aOrbiterB = RotL64((aOrbiterB * 12337846092069506365U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4950101626975919939U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2596253994220103666U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7181706961838582889U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17961706029559914243U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10321902557977495175U;
            aOrbiterJ = RotL64((aOrbiterJ * 16189559888625084711U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18146616411403012772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11739172334166341121U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7936637782633487291U;
            aOrbiterI = RotL64((aOrbiterI * 14940929920543800413U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3160044627483874242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16816384076887379704U;
            aOrbiterC = RotL64((aOrbiterC * 5052772186568301951U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8101560104988710226U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8851416379738817624U;
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterD, 26U));
            aWandererI = aWandererI + ((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31289U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31709U)) & W_KEY1], 18U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32742U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31449U)) & S_BLOCK1], 10U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31248U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 30506U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 4U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 36U)) + 439898681482066326U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 17362083676671776094U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 6418499837265155024U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 17262244253027454972U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 23U)) + 2382066162993139503U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 6U)) + 14345808395587174135U;
            aOrbiterC = (aWandererG + RotL64(aCross, 11U)) + 7534743166385552851U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 57U)) + 16994453324688523966U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 47U)) + 7079553728544045092U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3562822704508440641U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13990892681975857821U;
            aOrbiterJ = RotL64((aOrbiterJ * 8352929306654078795U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1796728922368577238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6605161260520067178U;
            aOrbiterD = RotL64((aOrbiterD * 8147537646591674091U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13994083795942328918U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6144523182899107711U;
            aOrbiterC = RotL64((aOrbiterC * 4153879991344611283U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12247462325297436642U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1065809332002012789U;
            aOrbiterH = RotL64((aOrbiterH * 5496601177032953251U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10147919864511540753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17138553441127273354U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5773875596275267871U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2653924016109573974U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6254416952351699582U;
            aOrbiterF = RotL64((aOrbiterF * 12756861659704947257U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 813046408080197079U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9624466135414123483U;
            aOrbiterA = RotL64((aOrbiterA * 6960320253124395015U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 972586705850825744U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 155283774901960223U;
            aOrbiterI = RotL64((aOrbiterI * 9928051687724257041U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18200100644751360406U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1168426822045686004U;
            aOrbiterE = RotL64((aOrbiterE * 5867027156069481313U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 52U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterK, 34U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Soccer_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1625U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 2052U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 690U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 929U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5101U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 13053031069776604052U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 51U)) + 1331396630251085122U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 3U)) + 15879286043343942393U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 57U)) + 13590365633321406830U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 37U)) + 14569235423040242618U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 11397370636618371560U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 43U)) + 3455933494593971847U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1307153376443784593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10688618762584786871U;
            aOrbiterF = RotL64((aOrbiterF * 9503823896874842411U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17746248451153600096U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8512568600755410158U;
            aOrbiterG = RotL64((aOrbiterG * 16648320170768234063U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8950230550112591092U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterK = RotL64((aOrbiterK * 5104988920132008913U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12583323865381967534U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11243927099685293887U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12867003042486433971U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9690268715525781389U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7466066217365074653U;
            aOrbiterJ = RotL64((aOrbiterJ * 17565696765505320889U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3673528673209875118U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14079103852360952255U;
            aOrbiterE = RotL64((aOrbiterE * 17449228863409999629U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6747836856132250630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5027692924422297153U;
            aOrbiterA = RotL64((aOrbiterA * 2492421273167124437U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 56U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 28U) + aOrbiterA) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5475U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 6041U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 8760U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9696U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7300U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 18U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 19U)) + 12029393034357490020U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 60U)) + 4526754731580694987U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 17060419646421271853U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 4128488893837059683U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 12706894827547160110U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 53U)) + 12506324593645825056U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 13U)) + 12581344490649250025U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14357032418199130132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15341977701796331249U;
            aOrbiterH = RotL64((aOrbiterH * 6332369248718076031U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7086602307544733241U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12398300065276832486U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18157408831225635333U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2499745046076601988U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7249361592814001829U;
            aOrbiterC = RotL64((aOrbiterC * 14597139848072319685U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3254456186337366437U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3472973415969046680U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14583566953969168353U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7905718972111691591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15941413652144021522U;
            aOrbiterJ = RotL64((aOrbiterJ * 3473779492962783565U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10583964125960308762U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13659925272340853715U;
            aOrbiterK = RotL64((aOrbiterK * 16708294803316630743U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9487054537489454887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13287757570441887517U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17351439045329892107U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 36U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterC, 38U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK + ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 47U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 10968U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 12824U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 14146U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11659U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12001U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15123U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 3U)) + 701291026547470433U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 47U)) + 17283292650462111643U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 9969124091931303406U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 40U)) + RotL64(aCarry, 37U)) + 889176772718046988U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 6054541844643748084U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 19U)) + 14703226235143028132U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 53U)) + 7977975878522921062U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16894322614172266274U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12160451749345900570U;
            aOrbiterE = RotL64((aOrbiterE * 18055355572903901749U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10870847008043897470U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8159920947172520247U;
            aOrbiterD = RotL64((aOrbiterD * 4833194641611011805U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2440099120969517932U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2428396147731468007U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2213226274394673479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7079731443427765333U;
            aOrbiterI = RotL64((aOrbiterI * 16918930776877030559U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 958896789550478970U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10788682955708075458U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 913321215613559729U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2003386579317564870U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8419686358774204999U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6547052526438697621U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6989167615157578904U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17636634003643824148U;
            aOrbiterH = RotL64((aOrbiterH * 11038576417283732937U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 28U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterE, 54U));
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aPhaseEWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19800U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 20008U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 19981U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19579U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17328U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17441U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 11U)) + 16189787374324972735U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 17563763730956242224U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 47U)) + 10572803498593789385U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 7713105232072974166U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 10760839534772718139U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 41U)) + 13397069448391230253U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 21U)) + 4569255679998375682U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9888769350817876949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11351796060878856300U;
            aOrbiterJ = RotL64((aOrbiterJ * 13356749147334008399U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18153775071965707204U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1282846411145853435U;
            aOrbiterG = RotL64((aOrbiterG * 12294455920906257823U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16457743979262460660U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 173493260775251032U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4935807229040883505U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3927345926316409630U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5158769729850853623U;
            aOrbiterK = RotL64((aOrbiterK * 2446452358663812945U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12331351600010165154U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3940794200348684050U;
            aOrbiterC = RotL64((aOrbiterC * 13248997263062075043U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11248514843822945425U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1391497323278226522U;
            aOrbiterF = RotL64((aOrbiterF * 8376841806072565005U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13265623528678787307U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2802033745265647317U;
            aOrbiterD = RotL64((aOrbiterD * 3437626962562016147U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 4U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterB, 21U));
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23524U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 25774U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26180U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24833U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25484U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 25578U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 42U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 4622023259121087483U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 10253505250223501352U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 41U)) + 17133877904420462669U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 47U)) + 6162827793741796700U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 3U)) + 9610986424765907615U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 10U)) + 11210747154264753754U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 16554205219580654546U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10352576357413766388U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3651845783283479752U;
            aOrbiterC = RotL64((aOrbiterC * 1011289824180799641U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18145542190463500476U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5415609566767162857U;
            aOrbiterH = RotL64((aOrbiterH * 6474184559323816389U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2033734872464201570U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3507213117125813345U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5453058336688881113U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8716253393049851856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 695984869565941856U;
            aOrbiterK = RotL64((aOrbiterK * 8377921610764044735U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7661578828878284931U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 906654265099155956U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8117625377607536949U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6050049984731254612U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17882717590338190821U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10807367411402733215U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4996521991532815957U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4246460672800604436U;
            aOrbiterE = RotL64((aOrbiterE * 12047466401960824903U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 12U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 20U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 41U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30709U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 27438U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28719U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29835U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28492U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30296U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 9888431329297626900U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 2937735167534624403U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 17626022970343789617U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 51U)) + 5665660859333693743U;
            aOrbiterE = (aWandererB + RotL64(aCross, 5U)) + 1060537034632076669U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 35U)) + 743777763907175800U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 5744905970181808845U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3545351394494002180U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4877547088414106007U;
            aOrbiterD = RotL64((aOrbiterD * 5416792889338547109U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11669378338379598445U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2961072441706158212U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2677988507090705371U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13984945589234919765U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1433097875470903205U;
            aOrbiterE = RotL64((aOrbiterE * 451996840039906781U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 716415411025451152U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8542286150858297810U;
            aOrbiterB = RotL64((aOrbiterB * 9139015340823332449U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12932391786479661299U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14005503313299177013U;
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9382792812676318046U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5138554251079724724U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6386016499265056247U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8522380066269546172U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11825536408101906458U;
            aOrbiterF = RotL64((aOrbiterF * 17042837108792016849U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 20U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Soccer_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aExpandLaneB, aExpandLaneD, aSnowLaneB, aInvestLaneB, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 827U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 5141U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 3462U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4542U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3773U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2580U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 23U)) + 5171470532667965920U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 750549462358682403U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 3325689257577120525U;
            aOrbiterF = (aWandererI + RotL64(aCross, 41U)) + 18031575461559790826U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 27U)) + 13874739537012288677U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 51U)) + 4250029868785016865U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 8211158803112611161U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 6U)) + 1083939790236786027U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 43U)) + 3446525462376962464U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 39U)) + 6973817815000417325U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 29U)) + 15230876489676945543U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9359727659738755880U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8775170107816327654U;
            aOrbiterD = RotL64((aOrbiterD * 6910680458261008653U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11958941755525038545U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16966819714283167348U;
            aOrbiterG = RotL64((aOrbiterG * 16363457661846050749U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14556087985619763243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17915047508377045221U;
            aOrbiterI = RotL64((aOrbiterI * 6727635453185130109U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8578745677485367222U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7002181668717618866U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12329703532414955235U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3569939503066735457U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2956247934282522184U;
            aOrbiterA = RotL64((aOrbiterA * 9946650822131152531U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4285180013402474041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5976239869535619811U;
            aOrbiterE = RotL64((aOrbiterE * 3458095419039067465U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2424524955161695463U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6849595426583763537U;
            aOrbiterK = RotL64((aOrbiterK * 12727902040238318101U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11414890686374886716U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5668287266836153445U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8011885266143066285U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9976985606260445887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9223940029500676834U;
            aOrbiterH = RotL64((aOrbiterH * 8508023992488499955U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4480967907876921958U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5132766654502526597U;
            aOrbiterJ = RotL64((aOrbiterJ * 321625389942019245U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12921555132452983464U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5171470532667965920U;
            aOrbiterC = RotL64((aOrbiterC * 9710487797420618879U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 34U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterH, 26U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 46U)) + aPhaseFWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5665U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 6558U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8657U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10031U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10183U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7183U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5836U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 53U)) + 12669015908335980355U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 5438715179868613192U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 39U)) + 13172104448184536460U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 4U)) + 13421421503244744803U;
            aOrbiterG = (aWandererG + RotL64(aCross, 35U)) + 13327113302994856582U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 4671768205922454413U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 29U)) + 5355759962838579929U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 47U)) + 6691720614265406851U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 14U)) + 7063906424700911378U) + aPhaseFOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 27U)) + 17328616394166672263U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 1542940602574207068U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7203866278803132454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 993485696233139264U;
            aOrbiterB = RotL64((aOrbiterB * 11609009908810366447U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15659679028507488331U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 18321361454094675842U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3966860765622641843U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9633319822696783352U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3496559332232402963U;
            aOrbiterJ = RotL64((aOrbiterJ * 7772060229838162977U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1918349708324205526U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7701088402761359134U;
            aOrbiterH = RotL64((aOrbiterH * 9649485438465644795U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6006824348814439686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18088375375347012557U;
            aOrbiterC = RotL64((aOrbiterC * 12801082943086128385U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12816533373478543584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17951880253818836433U;
            aOrbiterA = RotL64((aOrbiterA * 8935839101517220201U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11311632024372748238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9891349164779752351U;
            aOrbiterI = RotL64((aOrbiterI * 11405973752233193209U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 711130292000437038U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17818800917771709681U;
            aOrbiterF = RotL64((aOrbiterF * 10567029732245868263U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10188714200240109442U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9745615081760948652U;
            aOrbiterK = RotL64((aOrbiterK * 9321909462220134035U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6508703788527163965U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7536038073603467381U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12015514242701199813U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2793951597846756844U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12669015908335980355U;
            aOrbiterE = RotL64((aOrbiterE * 7355285540199760689U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 28U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 54U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterE, 46U)) + aPhaseFWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 43U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 18U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterD, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneB
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15003U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 13919U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 15967U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12578U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 10979U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 50U)) + 380024772508948442U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 7649029098162567210U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 19U)) + 5329304598870421851U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 37U)) + 12306118665045151326U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 58U)) + 960751560457324256U;
            aOrbiterI = (aWandererG + RotL64(aCross, 5U)) + 3244070254386191876U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 15733408571609521746U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 17623448932647018544U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 27U)) + 8787759896149035829U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 13U)) + 14741681792348288162U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 35U)) + 8801731213568307302U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9872248187499779222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15407371518644528235U;
            aOrbiterG = RotL64((aOrbiterG * 1245102406469471673U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4242060317152943062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9942784962409917541U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7296348796484458631U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15061417216070157797U;
            aOrbiterA = RotL64((aOrbiterA * 10349554676953256231U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3233185810644297433U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9241229457641024287U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2728237515724597517U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8464051359381554575U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3307872165699029375U;
            aOrbiterC = RotL64((aOrbiterC * 4859663401033023433U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5482617843966711997U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4442149210462943872U;
            aOrbiterJ = RotL64((aOrbiterJ * 8979352218576515647U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10591636597580147381U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14925122230279312217U;
            aOrbiterF = RotL64((aOrbiterF * 15038171961638724013U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9772367878232735350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15800661165607190092U;
            aOrbiterK = RotL64((aOrbiterK * 10493976952980533589U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1571665862499272194U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3162847040693387901U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2747235335326991399U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4868791925868749848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13134549226315884613U;
            aOrbiterH = RotL64((aOrbiterH * 3551955270718495869U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7830447320021657240U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 380024772508948442U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5143324968958616357U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 20U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 34U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 42U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 26U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17847U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneA[((aIndex + 17123U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 18275U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18015U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17588U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 19U)) + 14249093584376402677U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 8756965951816492264U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 14U)) + 11221139480258176330U;
            aOrbiterD = (aWandererE + RotL64(aCross, 21U)) + 17218894445564194851U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 11U)) + 8064642692524949490U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 5822093203710704646U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 5U)) + 3217799620158102238U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 2613757677892120843U;
            aOrbiterE = (aWandererD + RotL64(aCross, 56U)) + 13647481499551657237U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 53U)) + 3545714196663685016U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 35U)) + 9735422670576621521U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3911046580637583767U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9315984027042049203U;
            aOrbiterF = RotL64((aOrbiterF * 12568550776487242469U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8926367674641729058U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11035347490524961446U;
            aOrbiterB = RotL64((aOrbiterB * 10948288997163592463U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10748158733051120339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2467801787989056455U;
            aOrbiterK = RotL64((aOrbiterK * 12621934274702358977U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9244415080474351390U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8517784887959492079U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17022899813765884147U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8409307332803038455U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11043806021873232950U;
            aOrbiterG = RotL64((aOrbiterG * 8294888329708842989U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17512395828450251457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16849067939795823992U;
            aOrbiterI = RotL64((aOrbiterI * 9361991804481514337U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17541946638063238056U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11430501673960586718U;
            aOrbiterD = RotL64((aOrbiterD * 15074409630605450091U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 78307505705383302U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4834528975263832983U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17245673681686752861U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9647985402149698269U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6610247710757518931U;
            aOrbiterH = RotL64((aOrbiterH * 8672486173272686859U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2706696306041774372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9519896513600816252U;
            aOrbiterA = RotL64((aOrbiterA * 7468605169665549731U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14647351223431646222U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14249093584376402677U;
            aOrbiterC = RotL64((aOrbiterC * 8296105266618697281U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 10U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterI, 50U));
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25764U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneB[((aIndex + 22153U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25242U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26664U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 25177U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 4068921616130916949U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 37U)) + 12077715273915151726U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 27U)) + 16047546802670596833U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 14U)) + 9690277462716999763U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 5U)) + 14484814700447992628U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 17089267243053958210U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 47U)) + 9138746214446211147U;
            aOrbiterG = (aWandererF + RotL64(aCross, 21U)) + 10181001536979097045U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 23U)) + 6657458969093373191U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 43U)) + 7515983477876590988U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 40U)) + RotL64(aCarry, 57U)) + 3039935555863947600U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16209389224740851136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 725253312098083182U;
            aOrbiterE = RotL64((aOrbiterE * 17535989492095522597U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13307041115748941383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7159572004825238263U;
            aOrbiterJ = RotL64((aOrbiterJ * 4855009895002398449U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12027236743251643820U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8717826175991286553U;
            aOrbiterB = RotL64((aOrbiterB * 1175614802543098451U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4769096034227659937U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11201226563992939616U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15595355978388159931U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17295978531215563256U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11850923890626719833U;
            aOrbiterD = RotL64((aOrbiterD * 3854851059897397075U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14139441565288097706U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 988684899382304485U;
            aOrbiterG = RotL64((aOrbiterG * 11929090869999700891U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6159251276942253175U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4849529993914550651U;
            aOrbiterA = RotL64((aOrbiterA * 18240712676783671317U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6679745455842119497U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15838404437552215214U;
            aOrbiterC = RotL64((aOrbiterC * 17357853511591350887U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15853153471104458948U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12542164757451566994U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12163611303899312043U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14304233464055838869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4037999346933039765U;
            aOrbiterI = RotL64((aOrbiterI * 564236202758328407U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3582312827630995454U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4068921616130916949U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1527829107415867363U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterC, 54U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterI, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 14U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31831U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 28631U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32563U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30403U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30606U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 23U)) + 2617613537256538553U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 3U)) + 16642868916835132715U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 41U)) + 10860291124337073254U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 3U)) + 6432511273906902472U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 29U)) + 7505375005848241910U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 11086616004678821329U;
            aOrbiterG = (aWandererI + RotL64(aCross, 19U)) + 3298830587569881951U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 10U)) + 9775143140064220979U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 4147601326580823120U) + aPhaseFOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 5U)) + 12245920269898100415U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 43U)) + 8391940489176734499U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17876893379544668477U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18301882058180370541U;
            aOrbiterE = RotL64((aOrbiterE * 16680384667098921309U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6869225862715140102U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15404118372589259800U;
            aOrbiterJ = RotL64((aOrbiterJ * 5766851935950389915U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17757381020518233814U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17677969146092374455U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3469432916562405063U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15783378556632870114U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5792858258663697864U;
            aOrbiterI = RotL64((aOrbiterI * 12008981883482080427U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11737803388202260296U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16001927091970715330U;
            aOrbiterK = RotL64((aOrbiterK * 3062030309852922061U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1749586939123286632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6169421068855905938U;
            aOrbiterB = RotL64((aOrbiterB * 12374789910763348695U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10073586820719728062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17744171227198661555U;
            aOrbiterH = RotL64((aOrbiterH * 10658375268803957647U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1149819647337612792U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7725598665625892006U;
            aOrbiterA = RotL64((aOrbiterA * 15097586655234391559U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13930096050550704122U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3632241034947389647U;
            aOrbiterC = RotL64((aOrbiterC * 8442222389196610427U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17933893495867517142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7888594392078082482U;
            aOrbiterF = RotL64((aOrbiterF * 9809847720610861237U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10805303827043372168U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2617613537256538553U;
            aOrbiterG = RotL64((aOrbiterG * 3940471942234248791U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterG, 26U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 19U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterA, 34U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Soccer_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 316U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 4700U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2789U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7530U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 57U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 6305U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 15652862298542575895U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 35U)) + 16925323928418184554U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 4413861484961668394U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 3U)) + 2215946422098155969U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 14975185533513111110U) + aPhaseGOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9711613814905834552U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13154957291850149471U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17049677190793844477U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5058313016418534840U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15011423472941211620U;
            aOrbiterD = RotL64((aOrbiterD * 6125316151731105673U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2030053257469580168U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 150530795186791193U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11106050063717096073U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10878237472104183427U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11724672539469573109U;
            aOrbiterG = RotL64((aOrbiterG * 16158741837357985395U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9589700906445846956U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1367381624958248949U;
            aOrbiterK = RotL64((aOrbiterK * 8459515089081211977U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 4U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 21U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 48U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12258U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 14920U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12982U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8578U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8478U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9342U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 47U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 15036852811491820366U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 60U)) + 305637140752898475U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 11948631574496129610U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 5321623592482991426U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 37U)) + 4075270159062690728U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15111580500356908928U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7244150695504160363U;
            aOrbiterG = RotL64((aOrbiterG * 2445733898697939969U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5131563519577488862U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5881954992088651371U;
            aOrbiterE = RotL64((aOrbiterE * 2424421828597294607U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12780935808751507998U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12599159643925470226U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17690046932587062701U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9466589929741834066U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6093158735705189789U;
            aOrbiterA = RotL64((aOrbiterA * 7453778295800853653U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17461243886150519249U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15456408913739900718U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 10U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 12U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24140U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 22110U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 17609U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24085U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23086U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21218U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 60U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 39U)) + 13296600294247799698U) + aPhaseGOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 4U)) + RotL64(aCarry, 23U)) + 5818503518080877515U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 6735784238734173597U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 7368398209488856201U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 13U)) + 961734029066455638U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 797011946660892011U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12841876018396622350U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14056540056414153277U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16213253970483895623U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15186950557113470375U;
            aOrbiterB = RotL64((aOrbiterB * 4647470430467908107U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5117930310827477341U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12265429373166094162U;
            aOrbiterF = RotL64((aOrbiterF * 1522823535151532249U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13920531346698601568U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14695405206998211456U;
            aOrbiterH = RotL64((aOrbiterH * 13950964363414164279U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7851960904825938443U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9501511171732550190U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5614164120361489613U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 46U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24609U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 26746U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 25766U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30100U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27140U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 32688U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 3255291173184001106U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 15308468160116255528U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 18186972408589866656U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 56U)) + 4439324265978331914U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 43U)) + 13099263173016322486U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7041561081767500660U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6196422612687812971U;
            aOrbiterB = RotL64((aOrbiterB * 13359900204297781063U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7664260932541281413U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17802347823020441056U;
            aOrbiterI = RotL64((aOrbiterI * 2220679459017369255U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4253107484061190446U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13799496534030645312U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9167675060053848207U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14252892847595951926U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5663527578664291422U;
            aOrbiterH = RotL64((aOrbiterH * 18314294235895182465U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11148755959699137661U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17036900929333594592U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16041243617369003291U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 40U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 24U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Soccer_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2857U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 3844U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5813U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2759U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7719U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1369U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 24U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 54U)) + 1297415699043177788U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 17583786534509260153U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 643197858925708798U) + aPhaseHOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 5062653766915694874U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 37U)) + 7034273638367180511U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2026909726972916996U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2785690475553211646U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6612792037861160393U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2910341716302991892U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2834181605200829791U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1510617068750957651U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13323052600571281928U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10434901530315760460U;
            aOrbiterE = RotL64((aOrbiterE * 2042210188346767033U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 247903955625194782U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5196515747387257163U;
            aOrbiterJ = RotL64((aOrbiterJ * 1799024689023272275U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7196305682377987476U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14777739876892587484U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 95220583948241581U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 26U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13604U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 11399U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 8649U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15683U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9258U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15174U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 19U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 5295352595333316211U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 51U)) + 2341795367042042605U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 28U)) + 10122175780504033663U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 10084612804696198554U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 16470424309851045971U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 656016130975227994U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15313268829659834317U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3553315008401417123U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3795220914993923394U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14044442220988813825U;
            aOrbiterJ = RotL64((aOrbiterJ * 3270650852546606835U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3804224626734584802U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7980006306010255693U;
            aOrbiterH = RotL64((aOrbiterH * 13958505239726088561U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13746830564584711549U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11852212099729274845U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2164880979318247855U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9083223471018084847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13706723820703853346U;
            aOrbiterD = RotL64((aOrbiterD * 11361854103656219887U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19411U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 22798U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 19653U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22331U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22101U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19601U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 43U)) + 16183871922837164759U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aCross, 12U)) + RotL64(aCarry, 3U)) + 7002058258090219055U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 21U)) + 5650868611888303705U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 11899839660943876690U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 15349649504488111111U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14060149569086744970U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12920917574225030112U;
            aOrbiterE = RotL64((aOrbiterE * 6552626684290469367U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2831994965175330135U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18312543585028439192U;
            aOrbiterB = RotL64((aOrbiterB * 11618182708195744321U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11657562205118394239U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10850792819281246052U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10663100544207879337U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17810371216216125323U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7963413941144223128U;
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5498715358793875584U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9256727548911651373U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10498848323914000989U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 28U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterE) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32520U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 28992U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26059U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25407U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30001U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 26533U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 7790166497945719700U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 42U)) + RotL64(aCarry, 5U)) + 7136208896846119188U;
            aOrbiterB = (aWandererA + RotL64(aCross, 51U)) + 12123156943355100886U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 5095546037880875199U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 19U)) + 17642705393916765992U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9918479837334416990U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4890009823843176466U;
            aOrbiterB = RotL64((aOrbiterB * 16898633181256061239U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17652590786213674124U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 870002527644696135U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 915408393979165539U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12545429703552643682U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5310272867406182581U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10420003334833925011U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3264719049050179440U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1967241238180278937U;
            aOrbiterI = RotL64((aOrbiterI * 13004319774269457957U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 773883832927040736U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12766817190261232485U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7448864556802318431U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 54U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 38U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterB, 10U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 52U);
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
