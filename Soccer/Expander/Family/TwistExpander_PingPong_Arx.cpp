#include "TwistExpander_PingPong_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_PingPong_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9190D67C850E2FEBULL + 0xA3B5575A8036E42FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x93E48C6EBD4FEAE3ULL + 0xF82F27A736BC6872ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE6760B2B1C41B6D7ULL + 0xF751493AD36BA08DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA511EF7C754885F7ULL + 0xDE7D23ED8EE1CAC3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAED640A008E3B73DULL + 0x8A2C44CE0FD6C453ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE92BFA42E9F9AE21ULL + 0xF85AA38E1AC2F873ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE5BA40D723943D4DULL + 0xB77B952BC06BF5F9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC037BCC367C2B73BULL + 0xEE2362276A145F8BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEE7B79DEFCA55CE3ULL + 0xF3FBA7B0D0D06B6DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE4A956E2BF0FFE09ULL + 0xD372A8F4CA3E93F2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9F1A19693EDF1EF3ULL + 0x9BE8E0AC3777469CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDEFCDC49F341DD6DULL + 0xC38923B1B5167DAEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8D00796628DD04F9ULL + 0xBABEF38D7C7E7CF4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA4838AF575430687ULL + 0x910F092B4F7361DAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDFBCC30E26A3526BULL + 0xF5EE71656EDDD423ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xACBDBA7043FFBCD7ULL + 0x916D7D4EFA19152FULL);
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
            aIngress = RotL64(mSource[((aIndex + 3139U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 828U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1168U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 3007U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 36U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 3U)) + 13442819395490639310U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 8187292523194120936U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 41U)) + 11469697159823131388U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 53U)) + 13414083692375929653U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 43U)) + 11404010733687907517U) + aNonceWordF;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 6783212827186218247U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 28U)) + 8561131439340372614U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 23U)) + 6252609642004429113U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 5U)) + 12804867444200448952U) + aNonceWordJ;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 47U)) + 2739648749603690781U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 35U)) + 14808861217017399752U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17588866502571268888U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5882260142735642980U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7688252946143263869U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15493099088132862949U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5175647411532429582U;
            aOrbiterA = RotL64((aOrbiterA * 15226544495598541883U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14279707376173642767U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6826363572161275158U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13267185753040999992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9980987858092888720U;
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3582972937645514549U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10140409019562890804U;
            aOrbiterH = RotL64((aOrbiterH * 6944490201647678479U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6160444117287330557U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16344602960561293113U;
            aOrbiterB = RotL64((aOrbiterB * 2319964919335633293U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3497141036108337171U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 91269118352540308U;
            aOrbiterI = RotL64((aOrbiterI * 5160060720189045505U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12739932748793144857U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12820180915064791197U;
            aOrbiterE = RotL64((aOrbiterE * 5843849637411948699U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17572075652083359962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10684041099654982701U;
            aOrbiterD = RotL64((aOrbiterD * 7121293375756263771U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10739534650885677354U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9731206787727954809U;
            aOrbiterJ = RotL64((aOrbiterJ * 3730875775588585547U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 9655432616347117764U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13442819395490639310U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3650859301708619119U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 42U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 6U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterG, 40U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererB, 4U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 7328U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8477U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7033U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 6288U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 13U)) + 16124889768301047791U) + aNonceWordG;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 11912338587186717280U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 37U)) + 8594012868813114354U) + aNonceWordB;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 18U)) + 18281043566156682815U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 16853106130200942302U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 2611212958619673086U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 41U)) + 18039472325066855180U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 43U)) + 14495785571345122046U) + aNonceWordI;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 34U)) + 4556063793412832418U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 3U)) + 14896419970271244358U;
            aOrbiterC = (aWandererB + RotL64(aCross, 53U)) + 880028529183500036U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2379557167489415783U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11854373946064529806U;
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1487252775956449964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12777924204511625545U;
            aOrbiterH = RotL64((aOrbiterH * 1366019527386994789U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15998631485222477969U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 8864212892296191613U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 579242788050369815U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17069347835763226743U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7443008171694679791U;
            aOrbiterB = RotL64((aOrbiterB * 748894368884566607U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17334256152350782002U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8986626119086556393U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 2258172145924120235U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8528180968228358674U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12702290928064582589U;
            aOrbiterJ = RotL64((aOrbiterJ * 15673603224146737631U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7742438100860023610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3729687240959702198U;
            aOrbiterA = RotL64((aOrbiterA * 3756794766163746783U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 426129097367382096U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 16782175452274911213U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 1041477289638333659U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5942016166948841079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5260815086125551703U;
            aOrbiterE = RotL64((aOrbiterE * 1603799103692438147U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11732742583346900772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17182924380693084401U;
            aOrbiterC = RotL64((aOrbiterC * 14858685629471497071U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8539335803784852017U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16124889768301047791U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6607245691919237755U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 24U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 50U)) + aOrbiterA) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 44U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterK, 27U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 14429U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 12507U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15195U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 14319U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 24U)) + 6068543441070417854U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 39U)) + 2995980468193441856U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 5U)) + 18020277482171594003U) + aNonceWordN;
            aOrbiterA = (aWandererA + RotL64(aScatter, 41U)) + 4293807434721230702U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 7980599111583893156U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 20U)) + 8593141111851052016U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 11U)) + 5903487523900084325U;
            aOrbiterK = ((((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 15112035513447930209U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererH + RotL64(aScatter, 3U)) + 9854037263057006439U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 16759760289688823193U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + 12622628933030601390U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1264668857268123425U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16302812053619101593U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16087995784896123610U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7970269262800468363U;
            aOrbiterG = RotL64((aOrbiterG * 14924752223305807461U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5331477046030959632U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16534913204255550893U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11042821902537871209U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8069677512345031660U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 13622218526054132397U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5737130058129936372U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1076627182956662997U;
            aOrbiterJ = RotL64((aOrbiterJ * 14342191224014199929U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13911061091801078190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15397603151098990373U;
            aOrbiterK = RotL64((aOrbiterK * 1802890451633592245U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15137326716738637972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11248737008959896786U;
            aOrbiterB = RotL64((aOrbiterB * 90789374131547005U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1847847987633923657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10560748778679145431U;
            aOrbiterE = RotL64((aOrbiterE * 2919333327817231099U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2703726238610290251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12950671360471467310U;
            aOrbiterA = RotL64((aOrbiterA * 7490327691501537047U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10331504168520449467U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1541527607705280906U;
            aOrbiterI = RotL64((aOrbiterI * 14197400812600186171U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9135056476214341809U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6068543441070417854U;
            aOrbiterF = RotL64((aOrbiterF * 14102524444094948875U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 42U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 6U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterI, 18U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterC, 23U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 42U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 14U)) + aOrbiterF) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 17798U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 19418U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16964U)) & S_BLOCK1], 22U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17155U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 17417U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 3U)) + 11698283336767769359U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 5U)) + 13297826354831483872U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 15254999058287530795U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 19U)) + 17474166585085346567U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 30U)) + 15684783498452840289U) + aNonceWordP;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 53U)) + 5061229733465216486U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 43U)) + 15370981279168377944U) + aNonceWordE;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 13U)) + 17966672773619554092U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 14685092893994491068U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 28U)) + RotL64(aCarry, 47U)) + 12798804186209406389U) + aNonceWordF;
            aOrbiterF = (aWandererB + RotL64(aCross, 51U)) + 2848444181474221574U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8551142075919636146U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8833198159158950723U;
            aOrbiterD = RotL64((aOrbiterD * 7650289040764974737U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7351473160893666232U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterK = RotL64((aOrbiterK * 6317485031956448029U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7008985178526543258U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13576796403863120356U;
            aOrbiterH = RotL64((aOrbiterH * 13745839827679114077U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5769784656937900699U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14075925808204936705U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 5844894088757604713U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17818667502858010896U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16016922065572683130U;
            aOrbiterB = RotL64((aOrbiterB * 7525645833898085373U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1582458237855075977U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10830440354527138227U;
            aOrbiterI = RotL64((aOrbiterI * 10499386926982228251U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10653964151654643772U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11218475491129483859U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3338108067044357141U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9863649760189649255U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13790281439048354358U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 4682098083538482849U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14846954923718136337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 522207783972623813U;
            aOrbiterJ = RotL64((aOrbiterJ * 14299798934454852811U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 426829715716262697U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7482977730216354509U;
            aOrbiterC = RotL64((aOrbiterC * 6317437989422015173U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10736099808538972990U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11698283336767769359U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 17230175904095995929U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 6U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 28U)) + aOrbiterJ) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23717U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 22851U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22432U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 23275U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26884U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 22704U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 5U)) + 1210605127156905516U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 53U)) + 11964595428173569519U) + aNonceWordC;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 24U)) + 16277319029916258482U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 19U)) + 12369497463101824572U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 6201248574067068202U) + aNonceWordM;
            aOrbiterH = ((aWandererB + RotL64(aCross, 51U)) + 1727477025667206661U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 1404510627789806851U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 21U)) + 6948213591282018925U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 47U)) + 6688865181284421478U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 40U)) + RotL64(aCarry, 19U)) + 3351130769402360855U) + aNonceWordF;
            aOrbiterA = (aWandererE + RotL64(aScatter, 29U)) + 12681032488906270823U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3591412591193726763U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16153817571210878589U;
            aOrbiterD = RotL64((aOrbiterD * 4165137036092246349U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3808228354421006630U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 1427373776207504205U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 4534374093769595531U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1831554180932501132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1114853085120949215U;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2080935638828366835U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16104777999646489828U;
            aOrbiterJ = RotL64((aOrbiterJ * 15205199362011777473U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9782806013673440791U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3721620299829386454U;
            aOrbiterB = RotL64((aOrbiterB * 6286765834910272409U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4013706412064296527U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5751022780695158579U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 13766736471646116397U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17684546333240329338U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1106947111128020920U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 3158839453318658951U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11564229705849500598U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1585817314460274286U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12687162159791577431U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13549147977354138518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5148731385622182707U;
            aOrbiterH = RotL64((aOrbiterH * 11016443961557395981U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17048442399822433365U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13772472534194030098U;
            aOrbiterC = RotL64((aOrbiterC * 13155895389652826889U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9982971300679888388U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1210605127156905516U;
            aOrbiterA = RotL64((aOrbiterA * 9183351854400012949U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 26U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + ((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 18U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 29550U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((aIndex + 28925U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31641U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29260U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29401U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28801U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 60U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 15045917390223766480U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 10763054007033668758U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 57U)) + 13190170142593666607U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 60U)) + 9657025731441167065U) + aNonceWordN;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 51U)) + 11433367178975954211U) + aNonceWordC;
            aOrbiterD = (aWandererC + RotL64(aScatter, 19U)) + 17904920143996810366U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 41U)) + 3244383020512113283U) + aNonceWordM;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 26U)) + 6538815775171139091U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 23U)) + 7195368312757976343U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 18134430713910279374U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + 6571776588427107976U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11830778129647517758U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9793702760907767365U;
            aOrbiterC = RotL64((aOrbiterC * 4096246227968677179U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2287235876793192036U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8951959188326141794U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7583061790273240157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3571364625022806085U;
            aOrbiterA = RotL64((aOrbiterA * 6238360922735480669U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13869345563551689212U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 277480328952975002U;
            aOrbiterI = RotL64((aOrbiterI * 1057564597096163085U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4983735092494677578U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9490022869381030928U;
            aOrbiterG = RotL64((aOrbiterG * 12926352917961703123U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7928039573014765566U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6504190875809407084U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14648214826494826711U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2787985600176307413U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16308785053443116826U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 17867565986311256691U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12788128335006767824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1187040019537798339U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10834905007658184183U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10771230162770496645U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6542421559654716320U;
            aOrbiterB = RotL64((aOrbiterB * 16829492790597069373U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 702458690970201679U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2806140783487813070U;
            aOrbiterJ = RotL64((aOrbiterJ * 7415398198842270381U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 950611302199732036U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15045917390223766480U;
            aOrbiterK = RotL64((aOrbiterK * 9358017420417979347U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 44U));
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 50U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 51U);
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

void TwistExpander_PingPong_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x87C5ADE44724303BULL + 0x974D0E9ED1BD545BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD3A1ECF6AF4682FBULL + 0xF3EB8C62905D46BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE9610E9DABFD97E1ULL + 0xD972B3925E4CD848ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDEB4FCDF61B51CCFULL + 0x8E2871B7F7948552ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFB85B97955416389ULL + 0xE6D6CCF02586E0B7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF053AE3E24200AE7ULL + 0xDBC7C31907151950ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC43F6E07E1973519ULL + 0xF0C36A0B77BB0A13ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF10A6DF710082655ULL + 0xB9C2542E86BB2672ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBF6584BC78462869ULL + 0xF1A9682424EE0FEEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDFABE8B59C42A42FULL + 0x96FA4091515377C5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x91E07CBCE7330E5FULL + 0xEE71861F1B8AE1AAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDA5475C8D6EC7491ULL + 0xC9935970CF2D1528ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x910C6ED94DA9792DULL + 0xD6D08C08DD5E1A2AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xACEC8BB47A363819ULL + 0x9D1281F39F613005ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF5C36D04905B7457ULL + 0x8C9869E1EBBD8ADFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD4B5E86B6F56BC2BULL + 0xF91AD2513970C9DAULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3978U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6025U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 864U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6829U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 4739486756133131180U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 5U)) + 16089707555501328184U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 42U)) + 15310047330238536453U) + aNonceWordE;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + 7901411596386834955U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 4357555491060982163U) + aNonceWordL;
            aOrbiterC = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 15667085602825720102U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 60U)) + 8520635334382269253U) + aNonceWordC;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 47U)) + 1772509779231068315U) + aNonceWordN;
            aOrbiterG = (aWandererG + RotL64(aCross, 23U)) + 15336170957886025677U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8628770833489469980U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15469234024247246228U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 8905266995119987947U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10796430900884288328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10660110397012853289U;
            aOrbiterI = RotL64((aOrbiterI * 9140007610912037461U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11202284258711214794U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17509491802893182994U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 9329107599972703671U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16212572740740103554U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2190030203761579226U;
            aOrbiterC = RotL64((aOrbiterC * 3101886685668871045U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12014337082293041909U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3733531010807001506U;
            aOrbiterK = RotL64((aOrbiterK * 5797362244066062299U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7100994963061975529U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17837541162838600258U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8745987361678166553U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3311518938023146951U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7709505172646831553U;
            aOrbiterF = RotL64((aOrbiterF * 7121143171245765213U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4979968094554018443U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16822214821463034107U;
            aOrbiterG = RotL64((aOrbiterG * 8618262120451291765U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8376124175020587079U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11084586282092424876U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5835632742522563537U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 46U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 22U)) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterG, 18U)) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14866U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((aIndex + 15587U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11129U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8407U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10471U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 50U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererD + RotL64(aScatter, 19U)) + 11450949896247900941U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 29U)) + 3905542253538116335U) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 35U)) + 9529740545977785305U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 39U)) + 1856876631533143492U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 23U)) + 84253466320181686U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 12577480918745432444U) + aNonceWordE;
            aOrbiterA = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 5625703170397704029U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 53U)) + 694608607323629282U) + aNonceWordP;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 10U)) + 3993981243536262204U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4119215953484892051U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8785040118556157146U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17113521266125471625U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16234403619456882890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10398727475672860610U;
            aOrbiterG = RotL64((aOrbiterG * 5086871400049644715U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18327987141759096769U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2645964788056875452U;
            aOrbiterH = RotL64((aOrbiterH * 8778681366114628045U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 2859452497983106129U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7196557924940881076U;
            aOrbiterA = RotL64((aOrbiterA * 14415389907490256711U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 930127943984174668U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15673596916054795749U;
            aOrbiterE = RotL64((aOrbiterE * 7505660488733199479U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16673140529110941163U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2258448294877833760U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1821550319748977445U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6870209259643931219U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12749790107942194104U;
            aOrbiterC = RotL64((aOrbiterC * 4871407285968611725U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17131374134617173866U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6426448390733751612U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 12490559588384058417U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15592826434339731146U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14182944418026376183U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7218860482893476233U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 22U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterA, 4U)) + RotL64(aCarry, 27U)) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterC, 34U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 10U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20405U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneD[((aIndex + 17311U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 24168U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20396U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16462U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17486U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 53U)) + 12380376990224645149U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 5U)) + 18296928500297384014U;
            aOrbiterD = (aWandererI + RotL64(aCross, 58U)) + 3550626816361145100U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 2667792936946706027U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 47U)) + 12020969779370926953U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 737340727886903447U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 12U)) + 1681797651799760502U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (((aWandererB + RotL64(aCross, 19U)) + 2956186342689489064U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 1876852870402977177U) + aNonceWordF;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 6433205819353555071U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9065076854974222998U;
            aOrbiterD = RotL64((aOrbiterD * 5459675878087242021U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 3254410578766789992U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2005081975473815576U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 9947701153722014085U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15992999234834560419U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3458344156815120948U;
            aOrbiterA = RotL64((aOrbiterA * 1668460113964608051U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17069783053664877727U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1260234710193913099U;
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3825186451876061335U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2905344294992827535U;
            aOrbiterF = RotL64((aOrbiterF * 2469896090698580795U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18141402347899180617U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8760129857609925066U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2507999156108123047U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 594052473780678210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13216719212966128379U;
            aOrbiterK = RotL64((aOrbiterK * 10691355329696722303U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10029948739466316169U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11912428807431992996U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 85016510811938307U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8735634019801417287U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12785916159063273545U;
            aOrbiterC = RotL64((aOrbiterC * 1161917531260663357U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterB, 10U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 4U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aIngress, 42U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27491U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 29443U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31031U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28440U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27926U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 29462U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 35U)) + 12690502671561165478U) + aNonceWordD;
            aOrbiterD = ((aWandererF + RotL64(aCross, 18U)) + RotL64(aCarry, 47U)) + 17519943923428102801U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 47U)) + 10705515807975331385U;
            aOrbiterK = ((((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 16586447272278538179U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 8006560996840971798U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 53U)) + 12928600185788857701U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 40U)) + 14240723153798267172U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 23U)) + 8636219177994872072U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 11U)) + 7586790235186467512U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1103807034179512424U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7547526530239498693U;
            aOrbiterG = RotL64((aOrbiterG * 3360295583636013509U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8380239679344786397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5690809173787433519U;
            aOrbiterI = RotL64((aOrbiterI * 5354724308093372953U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8390902801141804609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6190745292098482871U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8065418693975056902U;
            aOrbiterE = RotL64((aOrbiterE * 6414621418430102589U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12111755051718111803U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7605877769709909297U;
            aOrbiterD = RotL64((aOrbiterD * 17525248694315944599U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 5969794501112646237U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5127559299360591476U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4521563633438853069U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10593847754747739786U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4401750688524310121U;
            aOrbiterB = RotL64((aOrbiterB * 14265829318976633707U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6927893132508779499U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4874009978647014479U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13340466017023540755U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13146693487138744677U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3298472134223595298U;
            aOrbiterA = RotL64((aOrbiterA * 2145005258008477281U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 48U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterA, 41U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 12U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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

void TwistExpander_PingPong_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8B82197D9AE0D607ULL + 0xFB45004DFC62ACE9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8AAB6CDEBD401E5BULL + 0x9858B6FF37C84E7EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC96BEDDF1C4A3F13ULL + 0xAF40609895FFAEB5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA284359CF1769C43ULL + 0x952CC031D8A77410ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF9AD00E8A1C79FF3ULL + 0x9F832ED676D625C5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB8150CFE6878E06FULL + 0xD0D3D61DC29CA1CDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC748D09B36D7345DULL + 0xB25445864DABE45BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9804FB669D404C6DULL + 0xD81E2CDC8CF53641ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x99052DAC73921585ULL + 0xC3F2F23E8CC22C9EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEBC6B03C297EE4C5ULL + 0x8346D99BC652D2DCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF670BFE931049A1DULL + 0xE113949D472EDD65ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCD0C7E1E34781EEBULL + 0xF718F8AEB50C5661ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x892E6F5ADA906727ULL + 0xCC1142DD9C107B13ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB8FE3AF555F274FDULL + 0xE0AAB788F7DE3C9CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9F44C07A8F7D93B3ULL + 0xA6F1D5290982E2CFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA1544F9B0A7346F3ULL + 0x8C43B703AD33CE15ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5064U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 7324U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5645U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2995U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3890U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 19U)) + 16016931609704150191U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aWandererB + RotL64(aIngress, 5U)) + 14511433515861302636U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 53U)) + 11691237442613269593U;
            aOrbiterE = ((((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 16383220587320484649U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 14293015313458219868U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 4407695248205526670U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1158323195324398372U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 7489061637031434357U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6577683409653864555U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 171080079472863843U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3063978974927752653U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5766333425872228205U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16173508656917582960U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12187968015372936695U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11781450063402219202U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13033139686637576694U;
            aOrbiterE = RotL64((aOrbiterE * 4331137994135472025U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4006310759400926020U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13156817947481574467U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 6U)) + aOrbiterF) + aNonceWordO);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererH = aWandererH + (((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 5U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13191U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 13638U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 10338U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8651U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12155U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16010U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 21U)) + 12583180859826261500U) + aNonceWordF;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 29U)) + 9067093488553721468U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 12173106198862881754U;
            aOrbiterH = ((((aWandererK + RotL64(aPrevious, 10U)) + RotL64(aCarry, 57U)) + 11333491014394592654U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 3511883526940919554U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7416810692106273044U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8341174972619784110U;
            aOrbiterF = RotL64((aOrbiterF * 17722163445765437279U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2220852854836962979U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 8090781422229383825U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 578293950675644397U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2338801236599102223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12484514711848308104U;
            aOrbiterH = RotL64((aOrbiterH * 10364216764253366067U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13684861340589131816U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12796636819991873058U;
            aOrbiterB = RotL64((aOrbiterB * 5533508014234835669U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7634198650894837690U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10240326122201201762U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 8758703497719125901U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 26U)) + aOrbiterI) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18937U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 19851U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 24529U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23933U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20444U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 21762U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererK + RotL64(aScatter, 48U)) + RotL64(aCarry, 27U)) + 7075016829833562104U) + aNonceWordG;
            aOrbiterE = ((aWandererG + RotL64(aCross, 11U)) + 8783765886115517036U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 19U)) + 2996723892384565829U) + aNonceWordH;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 9494134707342189476U) + aNonceWordF;
            aOrbiterJ = ((((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 5052642981395679904U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8766787055127962238U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4467211954388738079U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 8599295330343804047U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8030255604633658608U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16962408063455702251U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11171737929747471631U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3768222186567699076U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14930990410207899871U;
            aOrbiterE = RotL64((aOrbiterE * 10930005786146268241U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14179761938395502502U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1879084742719898108U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16783034788172670121U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5535012408925981515U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 12792553516710295939U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 8577530993755159329U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 12U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 10U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26955U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 29541U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29145U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31075U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28623U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25497U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31943U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (((aWandererK + RotL64(aScatter, 13U)) + 5295352595333316211U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 2341795367042042605U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 30U)) + 10122175780504033663U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 10084612804696198554U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 16470424309851045971U) + aNonceWordB;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 656016130975227994U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15313268829659834317U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3553315008401417123U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3795220914993923394U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14044442220988813825U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3270650852546606835U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3804224626734584802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7980006306010255693U;
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13746830564584711549U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11852212099729274845U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2164880979318247855U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9083223471018084847U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13706723820703853346U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11361854103656219887U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 48U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_PingPong_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC11386FFA9D642DFULL + 0xC96D4B5BFC571759ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBC97A772904DA399ULL + 0xAEAD828840FDEFEFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFBB3883A69D425B7ULL + 0xD5230DEBC94A0893ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB196E94EA6DBE1F7ULL + 0xEFD7DFCB4EE076D8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8EC90357BF5505CBULL + 0xE6CF1B7DD564ABB6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC538BAD75A18E26BULL + 0xD5BF38F35F9B75F1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB4BA54AABEFD5905ULL + 0x9B5680C58E35969BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFA5114B69F1B964FULL + 0xE6911BA47BFDF574ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x93080DEAC0125F23ULL + 0xCEF618BC40CF4407ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD925A72B08FFEED1ULL + 0xEB59B0B539F62D90ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAEAD6934DC21BCE5ULL + 0x810B4DFF6D36381FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCA1400D1F891B397ULL + 0xD639F194B8429BF3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x98E64AA24C7B3A4DULL + 0xA115E034796F7264ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA6F9C02732775743ULL + 0x9983D76E81713A74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x97690A2849A07031ULL + 0xC8CD20FFCE702626ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x837FBFB04B3FAB3DULL + 0x809455E480C0787CULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneC, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aOperationLaneD, aFireLaneB, aWorkLaneB, aFireLaneC, aFireLaneA, aWorkLaneC, aOperationLaneB, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1518U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 5644U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1096U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5305U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3492U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 891U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 4U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererA + RotL64(aScatter, 29U)) + 1042610313571524121U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 51U)) + 3505725321008825582U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 41U)) + 12584654563843782991U) + aNonceWordF;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 11U)) + 6645399144515770935U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 3608978423753715584U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 8089198857670370983U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 3U)) + 15207251813516399879U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9579268660105824516U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16055044469473802812U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 2269649280637188723U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 583811872609805949U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7027491967970873942U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 12686754713465826139U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18256061823189677508U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12708429127816136937U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12593886633108075321U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12169216645156306078U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12694325407567795065U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 3711789483877261899U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16109994660203297503U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4234704064165718913U;
            aOrbiterB = RotL64((aOrbiterB * 730085881474787681U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14119541943554602878U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8777769004811352951U;
            aOrbiterD = RotL64((aOrbiterD * 2556957257736134223U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15642663488392549609U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11594468530833278624U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6639306656361601143U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 34U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15387U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 10568U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10002U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9843U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11450U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 14417U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 54U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 5576732410244514238U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 2833808925935929629U) + aNonceWordD;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 3U)) + 3670188682914544792U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 21U)) + 15759072378887814995U) + aNonceWordP;
            aOrbiterG = (aWandererJ + RotL64(aCross, 34U)) + 13934007231137439994U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 27U)) + 11022225696007690512U) + aNonceWordG;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 16989177104453635790U) + aNonceWordL;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9256930045263527091U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17788596104417068290U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 675554110563253305U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17044369456673337625U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1310908395523250343U;
            aOrbiterG = RotL64((aOrbiterG * 16305084373037705921U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12067065689034065422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15130844248737512262U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9409499577465934107U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14532689204495587494U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8198147292120244178U;
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5485494458627163347U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10830008207150307611U;
            aOrbiterI = RotL64((aOrbiterI * 6526039534042499457U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17770065502486618029U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6397859353395335459U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 14286997752368893825U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5128700697381508319U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7103394110057060499U;
            aOrbiterA = RotL64((aOrbiterA * 5053680689949149633U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 14U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 40U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21994U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 22582U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22823U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23082U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18464U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24495U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + 12426357877879529292U) + aNonceWordF;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 12604900366173639176U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 13511119007338929401U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aCross, 57U)) + 9878720081166788060U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 37U)) + 15463195409806395076U) + aNonceWordO;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 29U)) + 6407922778852833423U) + aNonceWordJ;
            aOrbiterG = ((aWandererA + RotL64(aCross, 12U)) + RotL64(aCarry, 11U)) + 7690427254160734016U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 18030974031722143619U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17983938038322737041U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12479365337221685413U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16605512170117753884U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 681802273302348322U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 14608920184802647123U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15550312921312083819U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17824154101711884508U;
            aOrbiterC = RotL64((aOrbiterC * 7358612830654795357U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1939207786756735430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3132864634777826569U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12822929773923954849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16576106045887115660U;
            aOrbiterE = RotL64((aOrbiterE * 16370914370769903051U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2398825881649235260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13700821892926092479U;
            aOrbiterH = RotL64((aOrbiterH * 10830623703416956043U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2439833784883391606U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15870638514107637833U;
            aOrbiterG = RotL64((aOrbiterG * 3797380922767479287U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK + (((((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 5U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterG) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterE, 4U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28087U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 24671U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 26206U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31603U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31397U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28931U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (aWandererD + RotL64(aIngress, 21U)) + 1708250618750199233U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 12009147777553691142U) + aNonceWordD;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 8393982703399156592U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 3247327098356831221U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 4U)) + 3403590155376353737U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 27U)) + 18197244558104735044U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 57U)) + 3096253642040701606U) + aNonceWordF;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8012692688785412179U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17531946907545680745U;
            aOrbiterD = RotL64((aOrbiterD * 16510602981731506381U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17687695944270225817U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16147773866007628769U;
            aOrbiterI = RotL64((aOrbiterI * 16926442582711557877U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18244641303026196497U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8839160526348897457U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14268021129087663397U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10599266240854068246U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4629354220460621284U) + aNonceWordA;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 9505955649473204942U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 17775391885312236187U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17078153810088721310U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 9470436761716263000U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 5431855497250357229U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3305863413630104742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14377172434239576161U;
            aOrbiterC = RotL64((aOrbiterC * 6880176890091033423U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 58U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_PingPong_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBB1FA31B2DE2C68BULL + 0xC95ABA91DAC9D2FCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF33FB9FD261F4E89ULL + 0xDDBAA4CF066CA838ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCF6DB1A8F2D01CABULL + 0x9D11881A9B63234DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9144E02F390A3629ULL + 0xD5C80131268A3E8FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDEEE1D844D7D644BULL + 0x9006D20C691A1CB2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x95FE34C6BEB6A235ULL + 0xC91464EA961FD72DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCBE425CCD169E7D5ULL + 0x8FAAC3E02B360AD4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF68770E1497A065FULL + 0x9FB6331B471B295DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFCA4A7B370BF9937ULL + 0xD1AF0500ED0F79C5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC0BE4407888073C9ULL + 0xE2358AF3ED6DB218ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD059DB95B9A70CE7ULL + 0x8339674F31C57859ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE542BC47106BB9F1ULL + 0xDDF2B5D9FC523BFDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF1AB094E27773761ULL + 0xA919BFEB23CE6C70ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA7F3CB4D66D6390FULL + 0xCD55D7D03232CF87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF42CA8D7A93A7E45ULL + 0x84CC2B6AAEE6DD2DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8B2266923DE170FDULL + 0xC5109956439076C7ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aFireLaneA, aFireLaneC, aExpandLaneB, aFireLaneD, aOperationLaneB, aExpandLaneC, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4352U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 6287U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 256U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4237U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4417U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4510U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 24U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 37U)) + 2974056819475622600U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 7345051759236356098U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 27U)) + 12738468816846628882U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 5U)) + 7694520596043297922U) + aNonceWordK;
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 5530753590015084774U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 3U)) + 3776309161718383105U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 784780304358106404U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8999942326995036509U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5194986506064092779U;
            aOrbiterE = RotL64((aOrbiterE * 15070787038006135963U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7920040007459652762U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11311997270710107937U;
            aOrbiterD = RotL64((aOrbiterD * 6227571709361790209U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5365231114813547251U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 2358235238039571072U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18059414891616491807U;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14526050556461782864U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6937282036603272474U;
            aOrbiterB = RotL64((aOrbiterB * 14954512365270028029U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10105832250694931310U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3884223553012098137U;
            aOrbiterI = RotL64((aOrbiterI * 16340956813003906195U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10385284339549648087U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1257633893341505930U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2669950791270500977U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 44U)) + aOrbiterC) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12373U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 14833U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14594U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16342U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16024U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 16074U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 18U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 12692813903177772178U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 21U)) + 7112496446691277899U;
            aOrbiterG = ((((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 2112247138290568813U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 5U)) + 3699421080882855947U) + aNonceWordD;
            aOrbiterE = (aWandererK + RotL64(aCross, 39U)) + 13761832028354380922U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 9243822514887600214U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 13U)) + 6863833516853046129U) + aNonceWordA;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8863897995943098018U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13346785686701467520U;
            aOrbiterG = RotL64((aOrbiterG * 18074843497158380703U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15309543066305531619U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 17515530938817919111U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 16625193986319048245U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 760493237816424254U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7282586354117620860U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2327153408185290635U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4129706068526969105U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7020175432730888755U;
            aOrbiterE = RotL64((aOrbiterE * 10095158356907592239U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9102258982216515596U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10822031305361453690U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2036205056490578491U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12571477440964330246U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8436347026653095199U;
            aOrbiterH = RotL64((aOrbiterH * 17930734781213681573U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14214789872073941940U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12915911919403385001U;
            aOrbiterJ = RotL64((aOrbiterJ * 13161681603528031511U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterG, 46U)) + aOrbiterD);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16868U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 18872U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 22273U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23157U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23513U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 19011U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 50U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 5480870806135400132U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 8034874599430768743U) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 4006919843736863767U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 39U)) + 2988069748674633718U) + aNonceWordM;
            aOrbiterB = (((aWandererH + RotL64(aCross, 13U)) + 12347295651973135786U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 19U)) + 14152683894431568192U) + aNonceWordC;
            aOrbiterI = (aWandererD + RotL64(aIngress, 6U)) + 15765143815254196598U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10473067082331244233U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1089466925383677249U;
            aOrbiterE = RotL64((aOrbiterE * 17334888609179149753U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13215039929873682230U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3957997712247961479U;
            aOrbiterG = RotL64((aOrbiterG * 7631186240013784703U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10023907397941685546U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14593012591254614353U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 17111300092082154687U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13353797968154036726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9259966668512102858U;
            aOrbiterF = RotL64((aOrbiterF * 8326732574268308221U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 10757861831070349321U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10530223113483866178U;
            aOrbiterI = RotL64((aOrbiterI * 11269177745265396583U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7554320926405521865U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6978052067277966996U;
            aOrbiterD = RotL64((aOrbiterD * 18020134738536217801U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1053695861967171420U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15980734683539854451U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3208466640010555357U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterI, 44U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32438U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 28882U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 26289U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25935U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32651U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 30259U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 5088525177670191619U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 35U)) + 9966456257813932112U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 7707646574027146307U;
            aOrbiterK = ((((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 75480203757681173U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 19U)) + 384659134071835163U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 3158769775373307778U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 41U)) + 17360830943513941272U) + aNonceWordH;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5317278822721604586U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1371427105215954781U;
            aOrbiterI = RotL64((aOrbiterI * 10956603063464438611U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 3162710551223553423U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 5332921933853550756U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 11709546145149357887U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10572462410297815854U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10234389605554817892U;
            aOrbiterF = RotL64((aOrbiterF * 2130374833440291193U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13421365517991380605U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10186643614984034083U;
            aOrbiterK = RotL64((aOrbiterK * 8554471709467808453U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4742438973260817120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6081590345899008846U;
            aOrbiterD = RotL64((aOrbiterD * 7069396301823124931U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15360092808493795340U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12186413069553132646U;
            aOrbiterG = RotL64((aOrbiterG * 3815981440611914267U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16756221656224451552U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12232880965861373143U;
            aOrbiterB = RotL64((aOrbiterB * 14196910735715726471U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterF, 58U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_PingPong_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCB427AEB763369F9ULL + 0xEB359F1A52B1B03BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8205DD91D1A635ABULL + 0xBC7ECB6CC15B9C1CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF29430B2CF1E9FBBULL + 0x9C760164B17AD92DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE643A527A97D138BULL + 0xEC0835CBEF693DFEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC0BE448294292AC9ULL + 0x9F576E2315241367ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBABFF9707A21F2BDULL + 0xDFB4BED30A757E91ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD388333E96DE3431ULL + 0xA6CEA18A5D972BBEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCD1EA3139250584DULL + 0xAEB0D79FF57CAFBBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9DE1561396E5B47DULL + 0xE05346BF82D22E2DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF23C8EBB209AAAA7ULL + 0xEBB0E29045A3E48FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC174FD242B11757BULL + 0xCB26167D4612D434ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x96DF3CE763821353ULL + 0x966BB03141EDB9EFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB52066CE8F3E86E9ULL + 0xC428A1B96C052E1CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFDEC5367CC767EDDULL + 0xDC7450B239B819A0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEB6E82011FCFBA2FULL + 0xD62F1F7E81C46913ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF1974FAD95782FE3ULL + 0xC3C04FD70761B300ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneA, aExpandLaneC, aExpandLaneD, aWorkLaneB, aOperationLaneA, aWorkLaneC, aFireLaneB, aOperationLaneB, aWorkLaneD, aFireLaneD, aOperationLaneC, aFireLaneA, aFireLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5207U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 2252U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4321U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3304U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4088U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4663U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererC + RotL64(aScatter, 48U)) + 8988572360732005217U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 17889613225105985335U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 19U)) + 15563478320513948626U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 37U)) + 3441351228410524816U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 4425592689451435346U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 12733160231627305928U) + aNonceWordJ;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + 3574152157304607854U) + aNonceWordI;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 54U)) + 15167631896729808783U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 35U)) + 15822667973915417055U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 17181685481076577637U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 39U)) + 9979204751408873468U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1334240485667164762U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9190066751460137016U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15465215829109246336U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2305208282453624419U;
            aOrbiterE = RotL64((aOrbiterE * 10257861974108363283U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16951510027310993926U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11117938943423526901U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12461379120662979432U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11719697049048823897U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14880996802304818757U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6843357278142933570U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12727898578324702374U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 9786435451654365097U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18127999660067652233U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11754709060558683082U;
            aOrbiterK = RotL64((aOrbiterK * 12798744012150745847U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16940151146420516184U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12924950783056761895U;
            aOrbiterH = RotL64((aOrbiterH * 8898170377271926745U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 14829713915929878471U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 840466047621042565U;
            aOrbiterB = RotL64((aOrbiterB * 10748511630509529489U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11469637840333471085U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5561780312837795893U;
            aOrbiterG = RotL64((aOrbiterG * 11935079844970978957U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1059834104159730610U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10122108814456766430U;
            aOrbiterA = RotL64((aOrbiterA * 2184693583782179921U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14857099570072635006U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8988572360732005217U;
            aOrbiterJ = RotL64((aOrbiterJ * 14409836741925393077U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 60U));
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterC, 56U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11960U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 9913U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8291U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9251U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14967U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11771U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 43U)) ^ (RotL64(aIngress, 12U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (aWandererG + RotL64(aIngress, 5U)) + 6068543441070417854U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 13U)) + 2995980468193441856U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 18020277482171594003U;
            aOrbiterD = (aWandererH + RotL64(aCross, 51U)) + 4293807434721230702U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 30U)) + 7980599111583893156U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 27U)) + 8593141111851052016U) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 5903487523900084325U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 41U)) + 15112035513447930209U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 9854037263057006439U) + aNonceWordO;
            aOrbiterG = (((aWandererK + RotL64(aCross, 46U)) + 16759760289688823193U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 11U)) + 12622628933030601390U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1264668857268123425U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16302812053619101593U;
            aOrbiterF = RotL64((aOrbiterF * 18291400055836111547U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16087995784896123610U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7970269262800468363U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14924752223305807461U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5331477046030959632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11042821902537871209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8069677512345031660U;
            aOrbiterH = RotL64((aOrbiterH * 13622218526054132397U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5737130058129936372U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1076627182956662997U;
            aOrbiterK = RotL64((aOrbiterK * 14342191224014199929U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13911061091801078190U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15397603151098990373U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1802890451633592245U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15137326716738637972U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11248737008959896786U;
            aOrbiterJ = RotL64((aOrbiterJ * 90789374131547005U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1847847987633923657U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10560748778679145431U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2919333327817231099U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2703726238610290251U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12950671360471467310U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 7490327691501537047U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10331504168520449467U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1541527607705280906U;
            aOrbiterB = RotL64((aOrbiterB * 14197400812600186171U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9135056476214341809U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6068543441070417854U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 14102524444094948875U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 26U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 56U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21775U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 24135U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23613U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20366U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24121U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 22421U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 21U)) + 16183871922837164759U) + aNonceWordF;
            aOrbiterB = (aWandererE + RotL64(aScatter, 37U)) + 7002058258090219055U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 5650868611888303705U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 51U)) + 11899839660943876690U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererG + RotL64(aCross, 13U)) + 15349649504488111111U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 46U)) + RotL64(aCarry, 53U)) + 14060149569086744970U) + aNonceWordI;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 39U)) + 12920917574225030112U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 43U)) + 2831994965175330135U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + 18312543585028439192U) + aNonceWordP;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 10U)) + 11657562205118394239U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 10850792819281246052U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17810371216216125323U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 534217972450595401U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5498715358793875584U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9256727548911651373U;
            aOrbiterE = RotL64((aOrbiterE * 10498848323914000989U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17246360111302191699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterJ = RotL64((aOrbiterJ * 18267472694666221077U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3100998994319502921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8129301860291235970U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 17847033539279176187U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1889641029473279114U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16538494307002917945U;
            aOrbiterD = RotL64((aOrbiterD * 8081488217920885783U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5432230549146849322U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2634437941396090817U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7612999214758935211U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16940172599174185058U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13151669140593952203U;
            aOrbiterF = RotL64((aOrbiterF * 16225319638131723487U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3995064294869931681U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 913081077665768816U;
            aOrbiterI = RotL64((aOrbiterI * 9299514648768060453U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2469001696075411481U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2167390955194185443U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11805065572289005223U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1574066406534010796U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8736976961589874013U;
            aOrbiterK = RotL64((aOrbiterK * 5980070607180321955U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4233621443153132083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16183871922837164759U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 4030569514959370895U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 20U)) + aOrbiterF) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 34U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31363U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 32264U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32341U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31608U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31240U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 32010U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 22U)) + 16200278595895089008U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 47U)) + 1029614154810465897U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 27U)) + 7129562468705441295U) + aNonceWordP;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 14388903902433951274U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 1013568949315967455U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 11U)) + 3128823373497815651U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererI + RotL64(aCross, 6U)) + RotL64(aCarry, 3U)) + 14525694606889470589U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 14443983602196782887U) + aNonceWordI;
            aOrbiterD = ((aWandererD + RotL64(aCross, 3U)) + 12244220415328641190U) + aNonceWordH;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 41U)) + 10477159225338766614U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 35U)) + 2842870123078131566U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8621138818955849917U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5038396344400303181U;
            aOrbiterJ = RotL64((aOrbiterJ * 14636756322207385447U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2768613802894372496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2027754864051410015U;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2848088309172056399U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15017458513904884651U;
            aOrbiterC = RotL64((aOrbiterC * 9926904679902843055U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9079797279596336139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15424866642305110811U;
            aOrbiterB = RotL64((aOrbiterB * 12912331089970158845U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13751764050290602740U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7694557131324740282U;
            aOrbiterA = RotL64((aOrbiterA * 14980807690491467023U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 3508673897305667669U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3600868397311393233U;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1222655844979128996U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2257342337168905875U;
            aOrbiterH = RotL64((aOrbiterH * 6198995971182272119U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6290990717563682725U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15308494772443447109U;
            aOrbiterF = RotL64((aOrbiterF * 1925593111157842325U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4065385272074155855U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17216369169581934516U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16172589962950781777U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15683161334290612079U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4197626901960576264U;
            aOrbiterE = RotL64((aOrbiterE * 2822547214684481747U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4400047838649306704U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16200278595895089008U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6603195071605635697U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 36U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 24U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 26U));
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aNonceWordM);
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
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

void TwistExpander_PingPong_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9585896EEFED063FULL + 0xBE05DAA958462848ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCD6DB7BEF3D6893BULL + 0xB6433D9778584246ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x915FCAD9938AACBDULL + 0x99C6FD14029ABC33ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFFBD3C388ABDE8A9ULL + 0xD1DD865AA52EC8DBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDD244D439909DC8FULL + 0x93DE6C60F70E9328ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBD07F115C49FD4F5ULL + 0xCD59152A1F1EF483ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB16C5733156C06A9ULL + 0x96FD83AC1C7DE6D3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCFD0859920B2593DULL + 0xF4264DA11D74C86AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDB5E06ADCE033405ULL + 0xF4848FF1ADD71FCBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x88F26C463DFBFD23ULL + 0xC0C95E31FC91CB99ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x873564538E1BAA59ULL + 0x9E3750D0302F74CCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEC07FBD514539D57ULL + 0xB1ABACBD68C596ABULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC438E88560C2EA0FULL + 0xC8C08812DCBD14A4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC7B7EEA6D112E7D5ULL + 0xA49AC4531304A1FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC64FD03A04AFB1D3ULL + 0xD5B0CB59616E99DBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB2C0026155130D7DULL + 0x9FB58F54C08EF0D2ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aFireLaneC, aWorkLaneA, aExpandLaneB, aFireLaneB, aWorkLaneD, aExpandLaneC, aWorkLaneB, aWorkLaneC
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4134U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 4501U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6274U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 439U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1411U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4190U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) ^ (RotL64(aIngress, 36U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererG + RotL64(aScatter, 35U)) + 1557680213571812384U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 13U)) + 7387349725778021121U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 20U)) + RotL64(aCarry, 29U)) + 15379264067601586976U;
            aOrbiterC = ((((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 3730195724576043708U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererE + RotL64(aCross, 57U)) + 9637070085323827066U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 39U)) + 1170865717363676184U) + aNonceWordB;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 2750833653175252030U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 53U)) + 15118992811225568305U) + aNonceWordM;
            aOrbiterB = (aWandererK + RotL64(aIngress, 24U)) + 4974092922102988451U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10625719096296719514U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 855167122475471865U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7441090331293158773U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11322911068958340262U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 4334591909425429835U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10059025861172038183U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14263701737208936392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 678723206735649084U;
            aOrbiterF = RotL64((aOrbiterF * 10823239851733632227U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15652053114252065230U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1705225940224061401U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 3626023093533713579U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6826394665732900206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11902946775066981141U;
            aOrbiterC = RotL64((aOrbiterC * 18300629262162694137U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9802212958998591310U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14001358545610206524U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 13172645840788327099U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4299184726135884309U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7288757011999872416U;
            aOrbiterE = RotL64((aOrbiterE * 16806027820468277393U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 233801262480580205U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14208660347238680268U;
            aOrbiterB = RotL64((aOrbiterB * 6299693448313154603U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9217797359740446104U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 18165073197136050838U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11677479094709512887U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 44U) + aOrbiterB) + RotL64(aOrbiterI, 30U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterC, 10U));
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10642U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((aIndex + 11509U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16384U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11059U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14816U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 10230U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 56U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 53U)) + 16519040829220310189U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 5U)) + 6888002778416941825U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 28U)) + 1310832187746534025U) + aNonceWordB;
            aOrbiterA = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 5890888009051281674U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 43U)) + 5143864838362464857U) + aNonceWordD;
            aOrbiterB = (aWandererC + RotL64(aCross, 57U)) + 15591534069452660003U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 1466867671765325096U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 48U)) + RotL64(aCarry, 43U)) + 13931443680107902488U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 21U)) + 15400747367673245552U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2836975369734495759U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2370720358274970117U;
            aOrbiterF = RotL64((aOrbiterF * 4615571902817575375U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3470677184188006133U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7175584278499266723U;
            aOrbiterD = RotL64((aOrbiterD * 10067096593682482345U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6095078817776863055U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2176637999243513070U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12215701810843975501U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5580391239754903129U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15196125567953871184U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 12686361960729564519U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12787014151503209931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1523153207064063495U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3113907543551927561U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12973289026485937829U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9087439766232078173U;
            aOrbiterG = RotL64((aOrbiterG * 5817029335999350327U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16318022893068674015U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11089160685103562409U;
            aOrbiterB = RotL64((aOrbiterB * 17087834321385147603U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8680037953925067235U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3112588943274158119U;
            aOrbiterA = RotL64((aOrbiterA * 9214011370307670371U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16749015684369649821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9419550535891334966U;
            aOrbiterJ = RotL64((aOrbiterJ * 5421312787569114811U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 36U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterB, 20U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterF, 43U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18907U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 19148U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21630U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20127U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19669U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19343U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 40U)) + 16160838483846078448U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 57U)) + 15404960896190227946U) + aNonceWordF;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 51U)) + 16904160594024977199U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 17790460246821031802U) + aNonceWordG;
            aOrbiterK = ((((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 16395168254086971959U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 24U)) + 7484373204039901786U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererI + RotL64(aIngress, 19U)) + 18026814691322913510U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 15244817793136966450U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 29U)) + 5795491730356335666U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3163873518027801504U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2690791759507349172U;
            aOrbiterB = RotL64((aOrbiterB * 16677948635136515083U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17898067251167087906U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8028010015006604239U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 5601629670521300241U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7304739457289910555U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6476837815096530043U;
            aOrbiterA = RotL64((aOrbiterA * 16380545138701113267U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14242499233467960602U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 17305645693017634630U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 14442976693206929569U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9772864059444171908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7897200728282156408U;
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4890999319172950996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8165132649356094963U;
            aOrbiterG = RotL64((aOrbiterG * 17297706071263690189U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9342923520083533265U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7213639583505088067U;
            aOrbiterF = RotL64((aOrbiterF * 1349251979649428909U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4079475132684197272U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3350998022472827283U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 948841791460066265U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2479140576609216238U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7703147534931674972U;
            aOrbiterE = RotL64((aOrbiterE * 11419116495223970801U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 52U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterF, 60U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31250U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 31690U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 29807U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25809U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26413U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 32352U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 23U)) + 6318740973868639425U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 46U)) + 5487840061430920881U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 10258706763248072672U;
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 18356875269730338208U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 51U)) + 12883160282903147010U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 1010140474942697730U) + aNonceWordL;
            aOrbiterB = (((aWandererC + RotL64(aCross, 12U)) + RotL64(aCarry, 3U)) + 17733939421700898293U) + aNonceWordC;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 5U)) + 13693055887924981201U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 27U)) + 14574732452793385269U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10832873941223609012U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8212600587135328040U;
            aOrbiterG = RotL64((aOrbiterG * 5334613996794796145U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5312744319781971178U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6173741211706546923U;
            aOrbiterJ = RotL64((aOrbiterJ * 12854414066390848249U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3693249147883790810U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18365859989736602556U;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10645056678337549771U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1175668356822251045U;
            aOrbiterE = RotL64((aOrbiterE * 6579675292775345579U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13556844570541823717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4790355739411849736U;
            aOrbiterH = RotL64((aOrbiterH * 4083544011788850307U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14905575502272644116U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17047244574558476634U;
            aOrbiterI = RotL64((aOrbiterI * 2356386971503880047U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10161614295718414869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13413914082651612468U;
            aOrbiterC = RotL64((aOrbiterC * 16224039093981079491U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6072693130156927774U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4333656233793103787U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 9374745547133955709U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17209776289202130250U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11752001118070361543U;
            aOrbiterA = RotL64((aOrbiterA * 4416523594812872339U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 28U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_PingPong_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8611F519CAC86D59ULL + 0x89138839B28DCD62ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA50BEEB0543BF307ULL + 0xF5D29013C1364A39ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8FB5F6855CB30DE3ULL + 0xC86633A5799AF3FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8EB9AC22C311E9EDULL + 0xBA46395B41EECF0AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC084CE1E47E58E81ULL + 0xBF6FE271195E475BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x889CAF3523BBDEABULL + 0xF6B38D047E4399B9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA2932A117FCDD945ULL + 0xF569DA8EC7E7A525ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA18B81AC34B700D5ULL + 0xCC2C3595917841BBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBAC1175CB35503FFULL + 0xAE7CA7121E630B54ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8AB6973B746CFA6FULL + 0xE8A41020FCE8D1F4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x83AC1450EFAAF973ULL + 0xA2AA5F6199A18434ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8BA8BDFE6FE0E44BULL + 0x99F93F8A98CEE364ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8216D0FF6BAD389BULL + 0x81B9DDBCF7DB6D7BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBF6942B5DFCB5169ULL + 0xEA0841DDA9DA359EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x88CF6D1CFDAFAC49ULL + 0xA0664C53F67A6F59ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x855B7313E92BBF67ULL + 0xC78782EDB1117F64ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneD, aFireLaneA, aExpandLaneB, aOperationLaneC, aFireLaneC, aExpandLaneC, aFireLaneB, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2521U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 7964U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 2420U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 710U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7662U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1952U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + 8767379393098711499U) + aNonceWordM;
            aOrbiterD = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 7168159491580816433U) + aNonceWordP;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 9879279829061883406U;
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 10537167136053399303U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 35U)) + 2839070018069188936U) + aNonceWordD;
            aOrbiterA = (aWandererB + RotL64(aCross, 41U)) + 13844278063968429732U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 58U)) + 11278946626186474646U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11798425216660557799U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 7618446090703335192U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 7168757300685156779U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 695423597006983660U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14344728202803488813U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 5168825904902285909U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11656100506575697086U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10384358779985773937U;
            aOrbiterF = RotL64((aOrbiterF * 247494692039140973U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17585001605131977341U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 9964478171465522911U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 13484044854790175315U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2710943171829692624U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17809072853457153057U;
            aOrbiterK = RotL64((aOrbiterK * 16341884203303271365U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12814092033910687774U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1743186323268668740U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11150822630624332557U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10750472346626754704U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15925901217078035356U;
            aOrbiterI = RotL64((aOrbiterI * 9276504171291801637U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8710U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 9618U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 13679U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14172U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8307U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15725U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 12583180859826261500U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 9067093488553721468U) + aNonceWordI;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 12173106198862881754U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 11U)) + 11333491014394592654U) + aNonceWordB;
            aOrbiterA = (aWandererA + RotL64(aIngress, 23U)) + 3511883526940919554U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 57U)) + 7416810692106273044U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 46U)) + 8341174972619784110U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2220852854836962979U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8090781422229383825U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 578293950675644397U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2338801236599102223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12484514711848308104U;
            aOrbiterF = RotL64((aOrbiterF * 10364216764253366067U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13684861340589131816U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12796636819991873058U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5533508014234835669U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7634198650894837690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10240326122201201762U;
            aOrbiterI = RotL64((aOrbiterI * 8758703497719125901U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4162814763739453934U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2766504649149048469U;
            aOrbiterC = RotL64((aOrbiterC * 16731843453895178671U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11051393030148769655U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17687055068651386665U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 1042927176246229537U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3353615315436983420U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5971640796220306310U;
            aOrbiterG = RotL64((aOrbiterG * 15804313508835034807U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererE = aWandererE + (((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 35U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 30U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + aNonceWordN);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20730U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 19407U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23116U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21095U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24243U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22581U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 11450949896247900941U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 3905542253538116335U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 9529740545977785305U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 1856876631533143492U;
            aOrbiterE = (aWandererC + RotL64(aCross, 39U)) + 84253466320181686U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 4U)) + 12577480918745432444U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 57U)) + 5625703170397704029U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 694608607323629282U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3993981243536262204U;
            aOrbiterK = RotL64((aOrbiterK * 2502835860198146381U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4119215953484892051U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8785040118556157146U;
            aOrbiterG = RotL64((aOrbiterG * 17113521266125471625U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16234403619456882890U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10398727475672860610U;
            aOrbiterA = RotL64((aOrbiterA * 5086871400049644715U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18327987141759096769U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2645964788056875452U;
            aOrbiterE = RotL64((aOrbiterE * 8778681366114628045U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2859452497983106129U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7196557924940881076U;
            aOrbiterF = RotL64((aOrbiterF * 14415389907490256711U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 930127943984174668U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15673596916054795749U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7505660488733199479U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16673140529110941163U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 2258448294877833760U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 1821550319748977445U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 36U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 54U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27362U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 31479U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27302U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26133U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28865U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31036U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 15316464782468770057U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 43U)) + 6642872057476351588U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 21U)) + 660732654689529192U) + aNonceWordE;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 27U)) + 7235418086884000655U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 57U)) + 14784518476694580493U) + aNonceWordI;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 6U)) + RotL64(aCarry, 51U)) + 12222433977933449375U) + aNonceWordG;
            aOrbiterB = ((((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 8573001207708329927U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16035256260815013172U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15767726974121910203U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 719060452537759331U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17712217935322939971U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13488963456923357159U;
            aOrbiterH = RotL64((aOrbiterH * 16785285630840310405U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10222949131965611079U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1495561412321657209U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 9706305581868526265U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16156530750584361434U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7773792489045606309U;
            aOrbiterK = RotL64((aOrbiterK * 10730624207715601393U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11544578291333360613U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3665587867634242865U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4840528190844842595U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15248434984650998090U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15487979645426567581U;
            aOrbiterD = RotL64((aOrbiterD * 10868107809356766183U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6972347795052712690U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16074994810010431338U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 1262655238856775853U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 20U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 58U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 51U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_PingPong_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF60ED63438007A73ULL + 0xCB69AFF1E1BACB24ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF30EF15B1705E7FDULL + 0xC5D68CD2F585A54EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x963D71D6C9F8CB0BULL + 0xFBAD17B4BB58CD0CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF49440D29342E297ULL + 0x9DAE70CBF62FC81AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE5440BB2AB549C47ULL + 0xB3F89036C2BDED0CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEC00DDED2F11FC73ULL + 0xC0BF28B3AB2A2AA5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCCE30F830CFC2F13ULL + 0xBCFAAEE3D5B71425ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8FAA069FACCEC55DULL + 0x9E3F15EACF7565A2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA8452994A9CB2B3BULL + 0xE7083E6E864B2540ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB4F6236251D50ABBULL + 0xB38FADCFA6240101ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x96AFB9F6772904D5ULL + 0x85B7262D400F0841ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9B82B49EB3150E31ULL + 0x848D8E74270D9CF1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC23D94293DC8AE6BULL + 0x9DD2823DDFC9A59CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFB171252CBA36ED7ULL + 0xDADCCC55D7A93024ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEA3981C24D999841ULL + 0xC7ABD57C8B2A6A12ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF4350233C73E326FULL + 0xFEA4A2AA4ACE526AULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2004U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2256U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 605U)) & W_KEY1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2030U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 4752759164691497960U) + aNonceWordL;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 12088872623537639782U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 47U)) + 3734943577379734227U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 8854778183012444234U) + aNonceWordE;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 16948373492893967275U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 34U)) + 7962415690046184385U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 3U)) + 1872682375669714454U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7776801806943853566U) + aNonceWordJ;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 16665439117257230732U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 6866375628213114965U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11088186766134265676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10850237991780969350U;
            aOrbiterK = RotL64((aOrbiterK * 7547414856143095121U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6464817712131305812U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 244557182884209844U;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13261563971157415841U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2323811103717827362U;
            aOrbiterA = RotL64((aOrbiterA * 11483723582415081925U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12338803568475493422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2811342930111104982U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5020981755203607757U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5554497011738996057U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12712169745460598698U;
            aOrbiterC = RotL64((aOrbiterC * 1985586486150377769U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 17415058661427002973U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9430421222715343818U;
            aOrbiterH = RotL64((aOrbiterH * 10321140659099470811U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + aNonceWordA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aNonceWordB) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4675U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4560U)) & W_KEY1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5227U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 5014U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 5U)) + 5576732410244514238U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 2833808925935929629U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 41U)) + 3670188682914544792U) + aNonceWordO;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 11U)) + 15759072378887814995U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 13934007231137439994U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 28U)) + RotL64(aCarry, 51U)) + 11022225696007690512U) + aNonceWordP;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 21U)) + 16989177104453635790U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9256930045263527091U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 17788596104417068290U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 675554110563253305U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17044369456673337625U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1310908395523250343U;
            aOrbiterD = RotL64((aOrbiterD * 16305084373037705921U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12067065689034065422U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15130844248737512262U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9409499577465934107U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14532689204495587494U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8198147292120244178U;
            aOrbiterI = RotL64((aOrbiterI * 1418356389507740991U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5485494458627163347U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10830008207150307611U;
            aOrbiterC = RotL64((aOrbiterC * 6526039534042499457U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17770065502486618029U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6397859353395335459U;
            aOrbiterB = RotL64((aOrbiterB * 14286997752368893825U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5128700697381508319U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7103394110057060499U;
            aOrbiterJ = RotL64((aOrbiterJ * 5053680689949149633U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 52U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6381U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadB[((aIndex + 6708U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8146U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6442U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6131U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 54U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 41U)) + 13481227414590594621U) + aNonceWordK;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 17425964381118918026U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 4792004356135956581U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 47U)) + 11926849936000639098U) + aNonceWordB;
            aOrbiterB = ((aWandererD + RotL64(aCross, 4U)) + 990697329347742142U) + aNonceWordG;
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 9307721505373076588U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 17605732738841908719U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13110764518634187439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17970109897810645911U;
            aOrbiterI = RotL64((aOrbiterI * 10395095143998920213U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10273133817644703654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11239046688920468137U;
            aOrbiterB = RotL64((aOrbiterB * 5197802934333553327U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8355821483275763145U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15522151127786049345U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4844278537850520413U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5381663179722418112U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9551368011768104906U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14202470972121732997U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 16264476585232221270U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7721417776432288282U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10267770327791051869U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 339418090653475277U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3247926250495935511U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16824669543765729097U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3390560045236418590U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3894024951542543635U;
            aOrbiterJ = RotL64((aOrbiterJ * 10599637790900418767U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + aNonceWordO) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9924U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 10318U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 10013U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9988U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8713U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 10585U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 6068543441070417854U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 2995980468193441856U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 18020277482171594003U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 4293807434721230702U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + 7980599111583893156U) + aNonceWordN;
            aOrbiterH = (aWandererH + RotL64(aCross, 4U)) + 8593141111851052016U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 19U)) + 5903487523900084325U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15112035513447930209U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9854037263057006439U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 396276470208637283U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16759760289688823193U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12622628933030601390U;
            aOrbiterH = RotL64((aOrbiterH * 2151912984825538321U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1264668857268123425U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16302812053619101593U;
            aOrbiterB = RotL64((aOrbiterB * 18291400055836111547U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16087995784896123610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7970269262800468363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14924752223305807461U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5331477046030959632U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16534913204255550893U;
            aOrbiterF = RotL64((aOrbiterF * 1013433634373673565U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11042821902537871209U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8069677512345031660U;
            aOrbiterG = RotL64((aOrbiterG * 13622218526054132397U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5737130058129936372U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1076627182956662997U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 14342191224014199929U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aIngress, 26U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + aNonceWordG) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + aNonceWordH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12628U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 11204U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12244U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 13287U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12596U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11384U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11853U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 36U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 13714409587461539863U) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 27U)) + 14101156723903265839U) + aNonceWordN;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 53U)) + 7063754562895369001U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererK + RotL64(aCross, 20U)) + RotL64(aCarry, 39U)) + 12320578575245519386U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 11744826789631008424U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 41U)) + 8744816505096675597U) + aNonceWordL;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 13U)) + 10405435520084528645U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1463157688070683543U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12379603577919617703U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14858901470015109311U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1343439118031348146U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 16118850268070235540U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 11184386483735388257U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14116264435819277136U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5251698273012432109U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 1495818611622063967U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14806408656041403829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11569345414052398227U;
            aOrbiterC = RotL64((aOrbiterC * 9913158908301414861U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17063874769147888574U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9927420478679581917U;
            aOrbiterK = RotL64((aOrbiterK * 9042782809534196563U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2550285599827162167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17801534123304996448U;
            aOrbiterH = RotL64((aOrbiterH * 2160836889363614721U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6456685241021762041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17064208177372969289U;
            aOrbiterG = RotL64((aOrbiterG * 13726627607233302493U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 14U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14836U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 14106U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15955U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15258U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15524U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15588U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15835U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 5U)) + 14214886793361825363U) + aNonceWordE;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 17267959031078766320U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 29U)) + 16436067429484887644U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 38U)) + RotL64(aCarry, 35U)) + 9885951769332633820U) + aNonceWordO;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 13U)) + 12971711341813893304U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 199970353398450154U) + aNonceWordG;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 51U)) + 1237341696444162094U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7991128854417613360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14809029847149045833U;
            aOrbiterI = RotL64((aOrbiterI * 5940857360838299105U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2559509556915775947U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14336829730147834160U;
            aOrbiterK = RotL64((aOrbiterK * 15103242520064900873U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8853631886733610440U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13346159398673246914U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13660497151446983393U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 12121095718571872976U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16239781125815589804U;
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9051377033794324106U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13805815136723461780U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14849157800322754413U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18116651528452542634U;
            aOrbiterB = RotL64((aOrbiterB * 3638480428016835537U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4105057226952948599U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5911714320560994391U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1796514171654961389U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 56U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18806U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 16523U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 18700U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 17490U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17577U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17061U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17104U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aPrevious, 13U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 16651241552253078315U) + aNonceWordE;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 4558144676982478003U) + aNonceWordH;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 3U)) + 8814884320080367550U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 16011579668555672117U;
            aOrbiterB = (aWandererB + RotL64(aCross, 60U)) + 4738918668759862438U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 37U)) + 12526083125540985108U) + aNonceWordL;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 11U)) + 8048723561746000552U) + aPhaseGOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1082218464034639039U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8432043246965946816U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7801965585991025451U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9982080524048636852U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6720069955755215919U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1025046364205332059U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1019035028070247757U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7360619079463870467U;
            aOrbiterJ = RotL64((aOrbiterJ * 6623074813047915863U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10893918488381348474U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1390297670907738019U;
            aOrbiterF = RotL64((aOrbiterF * 11909657437658597735U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12512200589031203480U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14741471280748399540U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3012135242889901095U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8543897248359826770U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8545972622733791272U;
            aOrbiterI = RotL64((aOrbiterI * 11793879362775346821U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7049384618581928664U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14730773807906925408U;
            aOrbiterC = RotL64((aOrbiterC * 10711566871536755073U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 4U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + aNonceWordO) + aPhaseGWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + aNonceWordG);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 58U)) + aOrbiterI) + aPhaseGWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19463U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 21172U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21126U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 20955U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20667U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20412U)) & W_KEY1], 54U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20042U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 21034U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 24U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererH + RotL64(aCross, 10U)) + RotL64(aCarry, 29U)) + 7790166497945719700U) + aNonceWordC;
            aOrbiterE = ((((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 7136208896846119188U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 12123156943355100886U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 3U)) + 5095546037880875199U) + aNonceWordE;
            aOrbiterB = (aWandererE + RotL64(aIngress, 29U)) + 17642705393916765992U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 37U)) + 9918479837334416990U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 23U)) + 4890009823843176466U) + aPhaseGOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17652590786213674124U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 870002527644696135U;
            aOrbiterH = RotL64((aOrbiterH * 915408393979165539U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12545429703552643682U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 5310272867406182581U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 10420003334833925011U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3264719049050179440U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1967241238180278937U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13004319774269457957U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 773883832927040736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12766817190261232485U;
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 260069382395598265U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 15462103891287350123U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 5029268763635635753U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4072032867513289827U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17153061419083897076U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11934532169271718913U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6207264270332656966U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 18048064697837314947U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 13632594619404208489U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 4U)) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterK, 53U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23899U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 23122U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22879U)) & W_KEY1], 36U) ^ RotL64(aFireLaneC[((aIndex + 22510U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24123U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23407U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24506U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22080U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 13U)) + 12426357877879529292U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 3U)) + 12604900366173639176U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 23U)) + 13511119007338929401U) + aPhaseGOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 35U)) + 9878720081166788060U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 15463195409806395076U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 6407922778852833423U) + aNonceWordB;
            aOrbiterD = (aWandererA + RotL64(aScatter, 43U)) + 7690427254160734016U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18030974031722143619U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17983938038322737041U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 12479365337221685413U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16605512170117753884U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 681802273302348322U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14608920184802647123U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15550312921312083819U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17824154101711884508U;
            aOrbiterB = RotL64((aOrbiterB * 7358612830654795357U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1939207786756735430U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3132864634777826569U;
            aOrbiterD = RotL64((aOrbiterD * 13606281919426730325U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12822929773923954849U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16576106045887115660U;
            aOrbiterE = RotL64((aOrbiterE * 16370914370769903051U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2398825881649235260U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13700821892926092479U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10830623703416956043U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2439833784883391606U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15870638514107637833U;
            aOrbiterC = RotL64((aOrbiterC * 3797380922767479287U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterH, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aNonceWordA);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aNonceWordI) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26456U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 24847U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27048U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((aIndex + 26137U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26180U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26892U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25822U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 26820U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 9080426856729228705U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 7851218321653539276U;
            aOrbiterB = (aWandererC + RotL64(aCross, 13U)) + 7023344692919298036U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 22U)) + 9772846154227440734U) + aNonceWordE;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 29U)) + 12008298632429608431U) + aPhaseHOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 39U)) + 12201090455849562875U) + aNonceWordA;
            aOrbiterD = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 9498721803411445471U) + aNonceWordN;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 351203764023093632U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4966360430644539250U;
            aOrbiterB = RotL64((aOrbiterB * 10138518378274592739U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9194167899071345693U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4922477697284269116U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8444814161720407881U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15742625291642356429U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7528703106518431730U;
            aOrbiterF = RotL64((aOrbiterF * 11530049278751507567U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15279053574704935317U) + aNonceWordO;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 2425839793660355555U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 11486964816849830667U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13209849392400008898U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9041500097716231309U;
            aOrbiterG = RotL64((aOrbiterG * 340661035700748739U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7885423750878814599U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1992993999902904603U;
            aOrbiterC = RotL64((aOrbiterC * 1478629826632201617U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6120758615019314102U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8529621625846992066U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8485991471612862467U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterK, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aNonceWordK) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterG, 48U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aNonceWordJ) + aPhaseHWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27963U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneD[((aIndex + 28510U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28071U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28023U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27506U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28495U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28040U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 28379U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 19U)) + 3255291173184001106U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 15308468160116255528U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 4U)) + 18186972408589866656U) + aNonceWordH;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 4439324265978331914U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 13099263173016322486U) + aNonceWordM;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 37U)) + 7041561081767500660U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (((aWandererA + RotL64(aCross, 43U)) + 6196422612687812971U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7664260932541281413U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17802347823020441056U;
            aOrbiterE = RotL64((aOrbiterE * 2220679459017369255U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4253107484061190446U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 13799496534030645312U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 9167675060053848207U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14252892847595951926U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5663527578664291422U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18314294235895182465U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11148755959699137661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17036900929333594592U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2403828181385259549U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17813580350434928194U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13666780980793857831U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5623611126885414523U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7293224381174846969U;
            aOrbiterI = RotL64((aOrbiterI * 7032561584670788117U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10602620906929686163U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 18015916257203385982U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 10684090189688871993U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 60U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aPhaseHWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31706U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31545U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30097U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31500U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31635U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 30869U)) & W_KEY1], 14U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 10404808878585437255U) + aNonceWordB;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 3U)) + 10587858736301591439U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 1430530909801644435U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 29U)) + 9090938022430118902U) + aNonceWordL;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 10U)) + 12936604311751121235U) + aNonceWordN;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 51U)) + 1000583006020232032U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 12352532088997042232U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16723410947058502564U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16614089235313154270U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 11530998303573027827U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4245553025593349277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3353146318549477494U;
            aOrbiterK = RotL64((aOrbiterK * 14246377408238318091U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5935727336135635196U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10312187090293319667U;
            aOrbiterF = RotL64((aOrbiterF * 1395964500396711899U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12192843181244744484U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2542570124502586365U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17222847847573534963U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3315472769469002444U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17512858811783071174U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9070400454074283765U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16633218007427888082U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2502077714838858460U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 970762420815997725U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14792910273226469214U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15739513291150783151U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11896279674116906915U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 22U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aNonceWordK);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 4U)) + aOrbiterI) + aNonceWordI) + aPhaseHWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aCross, 48U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_PingPong_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCF53AC0649760975ULL + 0xF6F0D4FA84DC231DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9FA95D3694CA47D7ULL + 0xE2DD2B6E9FDAE041ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87ACF4D2200943D3ULL + 0xC968BB4741B0C408ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC2630F14FC440E4DULL + 0xF337BA108D52F5CDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF214337210AFAB49ULL + 0xDB000818204E0DF4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x86C154AA5ADBC65FULL + 0x9B54E7080A980058ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x849223FE918279FFULL + 0xF9D0A40C31114F56ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8829AE600FC2C035ULL + 0xAEE6E5E4F09EC82DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC765124382B09459ULL + 0xAA0A2726C90C448FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD44E002491F41C3FULL + 0xC81E62C9D2CBE028ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA35E3E632970195ULL + 0xFD25D5D6BF7E9FA5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAFD2D8D23E15E609ULL + 0x9B4FCB3D9D840C13ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x926E38208489D6D9ULL + 0x85EAC269D57B80D8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x99E966BF1A6F1187ULL + 0xCDC398D0E5865D20ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC1FCB2F13EB2D667ULL + 0xF0C9669B25D89CA7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEBCA516355350825ULL + 0x8B57A046142CF6E3ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2582U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 1378U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 406U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4955U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 569U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 26U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 12311607308490066301U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 30U)) + RotL64(aCarry, 27U)) + 13100864684740679846U) + aNonceWordL;
            aOrbiterA = (aWandererC + RotL64(aCross, 3U)) + 13697304189274329704U;
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 9047976902871216732U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 21U)) + 2147897579538537888U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2072444829390996142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2129307836981020908U;
            aOrbiterA = RotL64((aOrbiterA * 8065769537670939667U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10663145333751112064U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15019844390503785459U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 7442321463110790449U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5460865577557928142U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15806522559993224197U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 8722932687972240099U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6361113778657833389U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8306013884615042570U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8234258702656728667U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4038420580499706912U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11908091484457158973U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3964111175645156719U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 28U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterA, 21U)) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 12U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8154U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 7635U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 6892U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6129U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 10490U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 12535417189990029950U) + aNonceWordK;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 36U)) + 6204401443676390273U) + aPhaseAOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 869613505613154672U) + aNonceWordC;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 15053590879563855802U) + aPhaseAOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 11U)) + 13338989605204591428U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18306470022403825392U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1150696349434090218U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1099447646821052165U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13549541786420596437U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14302878430259588461U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16813606782134305513U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4660437084477165225U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 1653628537860912069U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 2624835201155303123U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5594199757006711631U) + aNonceWordO;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 11008472193138708891U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 13645764762027798301U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3668516817279364310U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 128159531749679984U;
            aOrbiterK = RotL64((aOrbiterK * 4523246859249826987U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aNonceWordG) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 10U)) + aOrbiterC) + aNonceWordI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11588U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 15972U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 13441U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14347U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11253U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11982U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 28U)) + RotL64(aCarry, 29U)) + 17454559218352016650U) + aNonceWordH;
            aOrbiterB = ((((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 8005709669325164803U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 13393741948412816357U) + aNonceWordC;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 13U)) + 3665865624348875553U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 39U)) + 8334142570031883436U) + aNonceWordM;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 17226066128706139657U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3319093033121522613U;
            aOrbiterK = RotL64((aOrbiterK * 17961784341097933029U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6657535603401588798U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5469746182326331147U;
            aOrbiterJ = RotL64((aOrbiterJ * 11315450342347794329U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17846791786050221418U) + aNonceWordD;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 15939541003714896288U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 1400351482213119809U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12076763190461077406U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3594038213596405284U;
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8301291631324464622U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8460406137668390582U;
            aOrbiterA = RotL64((aOrbiterA * 9117147929757711595U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 12U)) + aOrbiterK) + aNonceWordL) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aNonceWordN) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19387U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 21408U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21651U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21029U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17171U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21499U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 35U)) + 17225673071833726819U) + aNonceWordH;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 27U)) + 10301458382103627331U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 3960233050857362414U) + aNonceWordE;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 39U)) + 17768665685046605837U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 14471018461213959767U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 10730597892721340453U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 14863394003122760542U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 17731557030589257169U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9948587274816688296U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3573569431435100993U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2303922230056523077U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8153670675740450590U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16438856577722561424U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4689247488336908827U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15765587867581925041U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1082039522061775213U;
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4202521649260798876U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15877659681260461141U;
            aOrbiterK = RotL64((aOrbiterK * 11369910758551088173U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 54U)) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aNonceWordP) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 38U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + aNonceWordK) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22874U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 23572U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22311U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26954U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22272U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 26873U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 3U)) + 898812731947995389U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + 8677347622525527167U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 770321564027567654U) + aNonceWordO;
            aOrbiterI = ((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 23U)) + 11020474858081526395U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 17289793580414993470U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10111912559295118444U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8083622125544542011U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3610772128071340341U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7149858558922988240U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5919683821379905699U;
            aOrbiterK = RotL64((aOrbiterK * 16705119888884231567U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6860902846079238714U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15083517836867542075U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14852868368708376381U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 9860233289028878323U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 772406119079116272U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7971141501337627589U;
            aOrbiterH = RotL64((aOrbiterH * 10168120622976358617U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + aNonceWordB);
            aWandererH = aWandererH + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 20U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordM) + aPhaseAWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aNonceWordA) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28723U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 31101U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29765U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28967U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29212U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27571U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 43U)) + 4634399531433127141U;
            aOrbiterE = ((((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 16961792729406903200U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 11U)) + 4105280732301137738U) + aNonceWordO;
            aOrbiterK = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 15692013501147331191U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 1252216715968780587U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 7958289043012473752U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6611577301818896615U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2757493607265637973U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 8506226754305949140U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3648813120449403353U;
            aOrbiterK = RotL64((aOrbiterK * 9521367946879238849U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5195245426245535735U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 542948051600803051U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4631106308856448475U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11974253551208964789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10596463592332655367U;
            aOrbiterB = RotL64((aOrbiterB * 10941161258815714641U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12015129484061440159U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8254944355710109060U;
            aOrbiterE = RotL64((aOrbiterE * 3233697992479357615U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 22U) + RotL64(aOrbiterK, 60U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_PingPong_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBF73BBD02B0D0277ULL + 0xF6BD16552C6B157BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAEEC90A749C3BB7FULL + 0xEA333B7498F3944BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFB492D235CCC6DBFULL + 0xD7442B57CF47F67DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9BD3FD28A6DA4AB7ULL + 0x9094B1F7BEB3584DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x99222C1599925BE9ULL + 0xE379B30F77B4C961ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9E704D831764D3F1ULL + 0xA8584610202A167CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x89B0376ECAD7ABF1ULL + 0x854F6520227EAB86ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8D72D8B58025E65FULL + 0xD816221DBCBD45A4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9750BAE7C94AC6CFULL + 0xCBA55C4157FD55ADULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC9AC5E190A0C52F9ULL + 0xE2D8FF5056A27CEFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEF7B8B0B98D6C735ULL + 0xB067C92106133D92ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB78C881013BEA705ULL + 0xF886DEF7976794DAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD9F6C95DDF5C4413ULL + 0x9C2EF8029D7EE9F4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x982AEAACFB415BBFULL + 0x93CDE1CF0A60ED55ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA9E7A092FDB3C24BULL + 0xE7BCEF15B8962A6FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE6690CC9ABC71225ULL + 0x8D4DFE1F75131663ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD, aInvestLaneC, aExpandLaneB, aFireLaneB, aInvestLaneD, aFireLaneA, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneD, aWorkLaneC, aExpandLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2340U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 2670U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 2452U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4569U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 691U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (aWandererH + RotL64(aIngress, 60U)) + 18180797995100240808U;
            aOrbiterH = (aWandererK + RotL64(aCross, 47U)) + 6585906608223552885U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 13U)) + 14088708930575939855U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 468974153311516044U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 51U)) + 12481951025619894110U) + aNonceWordH;
            aOrbiterF = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 17227987923860711763U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 3U)) + 4373962756657477139U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 18U)) + 2077576476565420951U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 17435011300234663764U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4118039398293246896U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13724716599855216683U;
            aOrbiterB = RotL64((aOrbiterB * 17556333902751079677U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12391461204689596339U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9900605191533799627U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13553565332531046301U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 972946858824366125U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17247681919694541215U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 2974639094630445643U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15442851427306771601U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7303586227288294037U;
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12650358753454105119U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1483710933373510492U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6531763256577221891U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18065810162229740788U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11311677121338794007U;
            aOrbiterA = RotL64((aOrbiterA * 15116367961682119467U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2355285311890287611U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1287783821903407734U;
            aOrbiterK = RotL64((aOrbiterK * 8054011680932255985U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9282654686791135654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15488608017745542551U;
            aOrbiterG = RotL64((aOrbiterG * 7858866274035085123U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13296835576073421802U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7127700236018338741U;
            aOrbiterI = RotL64((aOrbiterI * 11246173563106014149U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 28U)) + aPhaseBWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterG, 3U));
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 37U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + RotL64(aOrbiterH, 41U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterK, 52U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10741U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 6071U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7661U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6148U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6457U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6308U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 9731U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 40U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 39U)) + 4970414922752555648U) + aNonceWordG;
            aOrbiterF = (aWandererG + RotL64(aCross, 11U)) + 9462756592787669327U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 3948790686662213095U;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 14542857212241578311U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererC + RotL64(aCross, 20U)) + RotL64(aCarry, 53U)) + 3387479009827029547U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + 1411421370057797877U) + aNonceWordA;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 16894451466895681236U) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 57U)) + 12727136462290223542U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 24U)) + 4625389198191960525U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3471881403786164913U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6433115856048534831U;
            aOrbiterA = RotL64((aOrbiterA * 9363233870194144053U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9825592965466157982U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1553125767261293088U;
            aOrbiterI = RotL64((aOrbiterI * 411535191177308781U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9951616357109647617U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11231080382787286889U;
            aOrbiterC = RotL64((aOrbiterC * 14024961994986659187U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13419663264017317947U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4835055642466215566U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17898065852351759171U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14558747666410946768U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13120938960926874504U;
            aOrbiterH = RotL64((aOrbiterH * 5681766019285559739U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11910501376797343986U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15074100100781785300U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 228976960937473851U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12415377930578091821U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14882039078390681802U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 13855446647753150713U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8094338361713756895U) + aNonceWordC;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 5478280604704108822U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 18062931724700600993U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6977017654546871841U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4131602217285988962U;
            aOrbiterD = RotL64((aOrbiterD * 11865422227883712419U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 58U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 30U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterA, 12U)) + aNonceWordP) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterF, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11740U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 13349U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12079U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11579U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13047U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 13U)) + 785861751704720606U) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 47U)) + 15968088718435606299U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + 1393976526590347151U) + aNonceWordP;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 58U)) + 17240750947292745884U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 4921576136163183137U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 3334047873553153032U) + aNonceWordH;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 23U)) + 15086509978458408698U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 36U)) + RotL64(aCarry, 47U)) + 892391205397581998U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 51U)) + 2965686403183767521U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14632215393655706170U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15740589515342377322U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 15677716942904794913U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11131164813943086445U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6988080581278900960U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 6412189142344044255U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16021254613117657178U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6183615599897921154U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12533992547026652747U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3104325358982904219U;
            aOrbiterF = RotL64((aOrbiterF * 14977348108778147265U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3878525937957474644U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2120435259884368445U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15964718652193073177U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14928658302694194856U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9121310461310309348U;
            aOrbiterA = RotL64((aOrbiterA * 17304439784647477491U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3715693239100476493U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7336577492932262490U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11074754160002665253U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2312452827448455675U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4322756069651934618U;
            aOrbiterB = RotL64((aOrbiterB * 6908893297397073539U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4962079617577705818U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5072727464750706525U;
            aOrbiterG = RotL64((aOrbiterG * 4947670001221089155U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 38U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterA, 10U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aCross, 18U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 34U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17573U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 20044U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16748U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21532U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19480U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 35U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 5U)) + 5480870806135400132U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 19U)) + 8034874599430768743U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 36U)) + 4006919843736863767U) + aNonceWordD;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 27U)) + 2988069748674633718U) + aNonceWordH;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 47U)) + 12347295651973135786U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 14152683894431568192U;
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 37U)) + 15765143815254196598U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 11U)) + 10473067082331244233U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 1089466925383677249U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13215039929873682230U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3957997712247961479U;
            aOrbiterI = RotL64((aOrbiterI * 7631186240013784703U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10023907397941685546U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14593012591254614353U;
            aOrbiterA = RotL64((aOrbiterA * 17111300092082154687U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13353797968154036726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9259966668512102858U;
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10757861831070349321U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10530223113483866178U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 11269177745265396583U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7554320926405521865U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6978052067277966996U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 18020134738536217801U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1053695861967171420U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15980734683539854451U;
            aOrbiterC = RotL64((aOrbiterC * 3208466640010555357U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17041258393808061556U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12846551858751995530U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9303891433380993639U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 14617434286683320666U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3999309956180741302U;
            aOrbiterD = RotL64((aOrbiterD * 15037707937050015205U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13452627760403094126U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2633241575260427158U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2638570213290747581U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 52U)) + aOrbiterC) + aNonceWordL) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 46U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 48U)) + aOrbiterK) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26211U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((aIndex + 27241U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 24424U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26593U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((aIndex + 26701U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 10336802574069791273U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aWandererK + RotL64(aScatter, 53U)) + 169025388197058936U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 3U)) + 6541354188379168846U) + aNonceWordP;
            aOrbiterA = (aWandererI + RotL64(aIngress, 39U)) + 16223920526599306104U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 30U)) + 12756613707692514808U) + aNonceWordO;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 5082475548176484035U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 43U)) + 4907435526952698526U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 19U)) + 14236627073831834337U) + aNonceWordL;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 37U)) + 11502511046130497584U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3679044835550219497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11254838916686736746U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10582608424233200966U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10449735026385340313U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4628253464169957835U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17664454668473204465U;
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3798386391743884889U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1379331161819246587U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13086160171095077295U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9816600392407327227U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16781971616348376878U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7909676419643119585U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 256053568910383007U;
            aOrbiterD = RotL64((aOrbiterD * 11965085163352053161U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16179914439220412472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3968867762761955845U;
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7474832923901283742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4736994731050735779U;
            aOrbiterK = RotL64((aOrbiterK * 9839654409121414047U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterB, 56U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aCross, 28U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 24U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 4U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31783U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 27538U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 28965U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30033U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 28204U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 9107326720193244489U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 53U)) + 10868585484401664145U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 13637736741437846622U;
            aOrbiterJ = ((((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 6130725216183918844U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 58U)) + 2063834478521338187U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 8564870627911949158U) + aNonceWordP;
            aOrbiterA = ((aWandererB + RotL64(aCross, 43U)) + 6524015751064086390U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 35U)) + 9874937766875388236U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 22U)) + 14723718409522680894U) + aNonceWordO;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13767059954741528279U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6387608251033722169U;
            aOrbiterF = RotL64((aOrbiterF * 6601902195707980693U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5391425980008431000U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11524218415655093779U;
            aOrbiterC = RotL64((aOrbiterC * 12508457981779189389U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 155510463350385905U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10554591788433641311U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5412084824127934293U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8662160162966241542U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5092555636369853727U;
            aOrbiterJ = RotL64((aOrbiterJ * 433807340167635499U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7163345798448796101U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 695089002178413267U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17302689458565434475U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5409173939213468972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15349690077393827541U;
            aOrbiterE = RotL64((aOrbiterE * 10984681254001609841U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12376011890751302027U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7809614158898158383U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 13845113198736843629U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13031938699536449576U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3983178190194056516U;
            aOrbiterG = RotL64((aOrbiterG * 1341678482929213405U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5567935037909671790U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17137042627663349797U;
            aOrbiterD = RotL64((aOrbiterD * 13535586899620672373U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 12U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 60U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterE, 56U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_PingPong_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEBC838C70154F68FULL + 0xB7C4AB35A703A7D3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCF281A9C499E4363ULL + 0xE565AE25AF633C48ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD0217EB649B133EDULL + 0x9E8C7DDA2F9A209EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFD8956F05C66EFDBULL + 0xCABBAD675FDD187FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8CC2BE1EDAB4F9E9ULL + 0xA5A32E87AA70EB6FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDCF03B6388D6BAC7ULL + 0xB3B9377E301C9893ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBBB6677CB63A8C4FULL + 0x924B2A5F446B0DB3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEF094BD4E8B261D9ULL + 0xD9C642EA5B7D80C2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF9CDC0E1CC916ACDULL + 0xAA00463BB7F22502ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xABC0FAE373D2FC43ULL + 0xE39F4E54BD6EDB19ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE6C4376C889D2965ULL + 0xB0EE2BC122EC5085ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFC6A266A8D560573ULL + 0x89B8D4F3AE743D4DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8718F10AA8AF4057ULL + 0xE085EACDE2934CF9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBEE66B26C14E2949ULL + 0xE6F73A1750DDD5F5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA2B36F8CE29FCDB3ULL + 0xFF1C5B473A0BE45CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xADF299121698FDFDULL + 0x8E3B183B66C5C6C3ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1322U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 2411U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2147U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3418U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2990U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 1047U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 36U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 14686411261024919129U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 47U)) + 7514582233957632005U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 6520710480103365552U) + aNonceWordK;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 1983621978676188036U) + aNonceWordN;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 29U)) + 9003524602590749672U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + 6428568234045228995U) + aNonceWordA;
            aOrbiterE = ((aWandererC + RotL64(aCross, 21U)) + 8656552687136446989U) + aNonceWordO;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16916248288415922490U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9740237548002535784U;
            aOrbiterB = RotL64((aOrbiterB * 7970729853948983849U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 907561000814618339U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4751108900841197631U;
            aOrbiterD = RotL64((aOrbiterD * 4545395964730641957U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 167774899400732287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11907484918310854962U;
            aOrbiterG = RotL64((aOrbiterG * 7213139491146402985U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14910318613649863924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14882888155751455276U;
            aOrbiterK = RotL64((aOrbiterK * 11394136445442060201U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16175942562693781908U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11022373758481651102U;
            aOrbiterF = RotL64((aOrbiterF * 6836331461393816027U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12548405399045031548U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10850926364556828443U;
            aOrbiterJ = RotL64((aOrbiterJ * 16231561687709867431U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13391684887911141790U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14648937281264822988U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6533299316940026059U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 29U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 6U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9779U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 5563U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9361U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 9987U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9743U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8761U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8467U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 12U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + 4970414922752555648U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 50U)) + RotL64(aCarry, 37U)) + 9462756592787669327U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 3948790686662213095U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 14542857212241578311U) + aNonceWordE;
            aOrbiterI = ((aWandererE + RotL64(aCross, 37U)) + 3387479009827029547U) + aNonceWordB;
            aOrbiterH = (aWandererK + RotL64(aScatter, 29U)) + 1411421370057797877U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 19U)) + 16894451466895681236U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12727136462290223542U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4625389198191960525U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 5726474430977810191U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3471881403786164913U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6433115856048534831U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 9363233870194144053U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9825592965466157982U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1553125767261293088U;
            aOrbiterA = RotL64((aOrbiterA * 411535191177308781U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9951616357109647617U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11231080382787286889U;
            aOrbiterH = RotL64((aOrbiterH * 14024961994986659187U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13419663264017317947U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4835055642466215566U;
            aOrbiterC = RotL64((aOrbiterC * 17898065852351759171U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14558747666410946768U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13120938960926874504U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5681766019285559739U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11910501376797343986U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15074100100781785300U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 228976960937473851U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordH) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + aNonceWordL) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 60U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11797U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 16278U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12034U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11665U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15016U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 43U)) + 4476099022490972343U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 16836423700375760429U) + aNonceWordI;
            aOrbiterB = ((aWandererB + RotL64(aCross, 21U)) + 8850577488928703557U) + aNonceWordN;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 28U)) + 7091631824560042743U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 3U)) + 12560498899956759494U) + aNonceWordD;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 7797973377112012161U;
            aOrbiterE = ((((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 6173820673874805794U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10805025132310245348U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7139216143268029968U;
            aOrbiterB = RotL64((aOrbiterB * 8349754682635765573U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8241544862261635722U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4735527016563596150U;
            aOrbiterK = RotL64((aOrbiterK * 6621354217673598381U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5166171126690294033U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11117641762075368393U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4980156869201219393U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6312932356458415421U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1304139291184508668U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 90744653170922319U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10085025354842771067U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16745854428789531080U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 1945983905747274355U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2497187958708890337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16069701876646548995U;
            aOrbiterD = RotL64((aOrbiterD * 16606039730973709495U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17242004368025978091U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12334315722243232121U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16528598396696346719U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aCross, 58U) + RotL64(aOrbiterE, 4U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + aNonceWordL) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21270U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 16815U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17525U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16934U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19652U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 41U)) + 7825479804710770560U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 5298124167101358123U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + 17774541024369233726U) + aNonceWordL;
            aOrbiterC = (aWandererF + RotL64(aCross, 54U)) + 7679371833537454082U;
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 5385914900748772224U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 3879781930908486531U) + aNonceWordI;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 47U)) + 659110346638873236U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10749021728538539749U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3631252455767429457U;
            aOrbiterB = RotL64((aOrbiterB * 8552825360915119613U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2271978810960685021U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5963558780692551176U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 4772055335210781149U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 974909966119198104U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9296998242911152296U;
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 2245318466901521959U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13391076374843288568U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 18094558036982107419U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6184487746594236737U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1563385912137291418U;
            aOrbiterH = RotL64((aOrbiterH * 4805455299959232321U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1744840092006498629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2100927276837188416U;
            aOrbiterD = RotL64((aOrbiterD * 3541788262067077997U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9998911862807246338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12239948725635220096U;
            aOrbiterI = RotL64((aOrbiterI * 7098620484129489129U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + aNonceWordE) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 27U)) + aNonceWordB) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24274U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((aIndex + 22189U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25272U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26519U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23141U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 10881271196314989997U) + aNonceWordB;
            aOrbiterH = (aWandererF + RotL64(aCross, 21U)) + 6406461249988567558U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 53U)) + 17255067918280095959U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 3U)) + 16690850682497718411U) + aNonceWordF;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 47U)) + 5576201059361086866U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 11991259685693687554U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 38U)) + RotL64(aCarry, 3U)) + 14652535244217836909U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1701789037170782122U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 953429054903473833U;
            aOrbiterC = RotL64((aOrbiterC * 13482379459700651427U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12064513610469714211U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7993881398822002424U;
            aOrbiterD = RotL64((aOrbiterD * 11572884842788918377U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14421313768013320050U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11112386845630998889U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 11771526352030371669U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17069630896535699015U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3308240081138623373U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 10449509484417835159U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17615529807112933619U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11782807146851563541U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12992075832343669221U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14401645829607611983U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6736397344219993532U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1667287547938175641U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6446974060524700550U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7840991992443308254U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6891023544882740107U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 60U)) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aNonceWordA) + aPhaseDWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32658U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneA[((aIndex + 29694U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29775U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29530U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 28976U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 18U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 34U)) + 15549114274303128055U) + aNonceWordC;
            aOrbiterD = (aWandererK + RotL64(aScatter, 47U)) + 16466750056388063241U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 12209449840836787142U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 14551496099734294336U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 57U)) + 6266576428679808622U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 5U)) + 16892841575635668152U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 7375966221423362125U) + aNonceWordL;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11926105302821753530U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16219253791550461124U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 2117550758226173419U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 7299056065319248160U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15234001484933728439U;
            aOrbiterJ = RotL64((aOrbiterJ * 8182244796017018911U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6615802589932632120U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5481176858895819247U;
            aOrbiterE = RotL64((aOrbiterE * 3604590158551984877U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17220507586542139380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14137921473739415340U;
            aOrbiterI = RotL64((aOrbiterI * 10634645686035907603U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16981960446540932787U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10897565927079518588U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 418843936329303571U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2746889569299593263U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4894117146736361379U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 2656750612042673191U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18294823016957137777U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 86828501068883383U;
            aOrbiterD = RotL64((aOrbiterD * 11432686669235402365U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterC, 41U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 14U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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

void TwistExpander_PingPong_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEC1A9572B80B9637ULL + 0x8C0D61501B3D322CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE7BAD3CEE8623559ULL + 0xEC48705A484479F2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA71C0A210AFDD203ULL + 0xE3C66FDF849032C3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB3AEC2E6693023A5ULL + 0xAB0CA9549370396DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x946F2C5CF85BBFB3ULL + 0xBF3A190F57F54011ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFDEC308186FEE6A3ULL + 0xF7B7E590376F64E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF8333E765D88A6CBULL + 0xD182C2CA63F37B6FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF0E7343D92685D79ULL + 0x8E7EF74B7AD68C8AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB96EF5FA4B0B2251ULL + 0xCAE8AF5B58E099EDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCAEC8D7881914567ULL + 0xC155EF6024401BEEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB64D4A862F3EA35FULL + 0x9E833492B1FC191BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8B8BF095B24440F1ULL + 0xADC20D8DDC87392AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE8998D9950FD6CD5ULL + 0xA3D0D2A789837EEAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBEC3F2A3E365FC87ULL + 0xA00E38D857B73B87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF260FAD4DAA61CCBULL + 0xCFF78D2D3E4EF9B5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA4F3A31187BC4407ULL + 0xE22AEF7D457871D7ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2047U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((aIndex + 4928U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1612U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2000U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3078U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4158U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (aWandererH + RotL64(aCross, 43U)) + 2786079456995203065U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 7237256119153857253U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 58U)) + 9310834010563647604U) + aNonceWordO;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 17361734905706517877U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 15837111231884647451U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 53U)) + 18065431964418026445U) + aNonceWordH;
            aOrbiterC = (aWandererF + RotL64(aScatter, 5U)) + 3029123922999952652U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 46U)) + 5166926595573507837U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 29U)) + 1918425684273807598U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 37U)) + 4724551751012661440U) + aNonceWordA;
            aOrbiterF = ((aWandererI + RotL64(aCross, 11U)) + 1818014487579644390U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6670090372241084216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8485757110007268693U;
            aOrbiterJ = RotL64((aOrbiterJ * 11876760095108618363U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4928130251509514742U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2528788422725346792U;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2860387120895147503U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12927802338151379368U;
            aOrbiterD = RotL64((aOrbiterD * 8876144125458603029U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18029699867733207083U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13361836994951253312U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5349767426256597073U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11957294454794128079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3755417922063414648U;
            aOrbiterE = RotL64((aOrbiterE * 13896364063651241401U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18001157153447913032U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16214145724690286854U;
            aOrbiterC = RotL64((aOrbiterC * 5874139687703360515U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3860958772090975562U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12395621524459640173U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 722817135977510161U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3402035664910754484U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2139099117325745602U;
            aOrbiterB = RotL64((aOrbiterB * 14008983756425796029U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7769274487425053026U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6492669707749367728U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 5149771861620757839U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14963366447884375043U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11398874662567519691U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8221521452475029835U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7168445485232814860U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2786079456995203065U;
            aOrbiterH = RotL64((aOrbiterH * 14258367164534307955U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 56U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterE, 21U)) + aNonceWordP) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterC, 38U)) + aOrbiterK) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9192U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneC[((aIndex + 10670U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 5923U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 6691U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5992U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6737U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 5983U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererK + RotL64(aCross, 21U)) + 13687218104610230596U) + aNonceWordO;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 6841550124960692709U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 17418968668458764131U) + aNonceWordJ;
            aOrbiterC = (aWandererI + RotL64(aIngress, 52U)) + 8303537912696948204U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + 12376614417285936537U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 27U)) + 14215749063579232654U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 3U)) + 4111736931433665347U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 11250375934571631522U) + aPhaseEOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 37U)) + 5367367837773331275U;
            aOrbiterD = (aWandererG + RotL64(aCross, 42U)) + 15514089192382674434U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 35U)) + 1475991716685034960U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5531622777788629748U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8363822215908303335U;
            aOrbiterB = RotL64((aOrbiterB * 17850203366840994883U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3741256932685720414U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11634667238062155772U;
            aOrbiterF = RotL64((aOrbiterF * 15925089729784547403U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18180546911210417155U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5123234656838556335U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15362857462853398025U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11215734271189250284U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16863747802158398092U;
            aOrbiterG = RotL64((aOrbiterG * 1828035970246160023U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9859050606636646323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9331300036643654675U;
            aOrbiterJ = RotL64((aOrbiterJ * 2502263410556166281U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15028845665427209759U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8916444839488901676U;
            aOrbiterD = RotL64((aOrbiterD * 6646561894156038791U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8024631140949068570U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1116378858490660031U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4247798531910227367U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5066486214537899212U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9346312092322423057U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 13443190089768875191U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11651011617027950122U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11308862427412671711U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 12167147966934334703U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3850136281462840708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13461307727665667424U;
            aOrbiterA = RotL64((aOrbiterA * 10788040812090673421U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17824744996404571928U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13687218104610230596U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 325803029547254631U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 4U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 4U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aScatter, 36U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + aNonceWordB);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 14U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15815U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 16348U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14518U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13348U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 12460U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 3U)) + 6916817163240024692U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 14554930751292077817U) + aNonceWordI;
            aOrbiterF = (aWandererG + RotL64(aScatter, 39U)) + 1098305064484336101U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 21U)) + 12192821172420471527U) + aNonceWordA;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 34U)) + RotL64(aCarry, 43U)) + 2435134991707318845U;
            aOrbiterE = (aWandererC + RotL64(aCross, 13U)) + 1896745368738512624U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 19U)) + 1114996424222923873U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 9839135798371512656U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 11U)) + 8037967239603177043U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 53U)) + 15185468738487237432U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 28U)) + 4912098316394854543U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13142688607850380888U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4507379759608945839U;
            aOrbiterF = RotL64((aOrbiterF * 2989332387754215967U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7299006009652289342U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5390655277207053627U;
            aOrbiterE = RotL64((aOrbiterE * 10973744708856143715U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6744737023577785725U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15539737698867067285U;
            aOrbiterH = RotL64((aOrbiterH * 4686092035261336911U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13329866734681377952U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13284937458969166257U;
            aOrbiterG = RotL64((aOrbiterG * 3965985432462699445U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8695002088915702168U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3858059421620839286U;
            aOrbiterA = RotL64((aOrbiterA * 9559783727301092937U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6609163873243179836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9416165620556710540U;
            aOrbiterB = RotL64((aOrbiterB * 240385043740268229U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 1578449067529000433U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14309000104419489303U;
            aOrbiterC = RotL64((aOrbiterC * 7599078306153684729U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15785180680737461320U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10099222679918382021U;
            aOrbiterI = RotL64((aOrbiterI * 2012232597046182581U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10666287769220108179U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13648647399222807034U;
            aOrbiterD = RotL64((aOrbiterD * 10772381733103127201U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9292207828896796810U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9155130791347443553U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 16838229790655977057U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11334395119119245556U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6916817163240024692U;
            aOrbiterJ = RotL64((aOrbiterJ * 9640906826978028183U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 24U)) + aOrbiterC) + aNonceWordB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterE, 19U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 13U)) + aNonceWordH) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aScatter, 20U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20294U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneA[((aIndex + 17786U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 18956U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21159U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneD[((aIndex + 21329U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 19U)) + 15383045568644941552U) + aNonceWordM;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 11U)) + 17452811657750910067U) + aNonceWordJ;
            aOrbiterD = (aWandererK + RotL64(aIngress, 53U)) + 15660117718455155603U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 10396441207743665753U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 21U)) + 3708971058200841442U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererA + RotL64(aCross, 37U)) + 7000673057768598750U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 9886354469011131596U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 48U)) + 16018065329058043467U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 41U)) + 5024756166109352320U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 51U)) + 6587818720728886652U;
            aOrbiterK = (aWandererI + RotL64(aCross, 57U)) + 3652672354944162319U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6307315649915348048U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16405347331742979258U;
            aOrbiterD = RotL64((aOrbiterD * 7183142442906743699U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5427299664054601957U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4983381733483185898U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14646556236306407673U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10182995521328377487U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8694282877540593550U;
            aOrbiterF = RotL64((aOrbiterF * 14614602561910403893U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4085927978153269932U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6176195962815240877U;
            aOrbiterC = RotL64((aOrbiterC * 16792916528959579875U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6966742100601433005U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9920952446921247521U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 1879821050131820933U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11958734477518336014U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2058335903640404380U;
            aOrbiterG = RotL64((aOrbiterG * 6986170159285417789U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 77366119537297816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12072894199692855000U;
            aOrbiterH = RotL64((aOrbiterH * 9083781120514635987U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11874297832446385377U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13715562531763053196U;
            aOrbiterK = RotL64((aOrbiterK * 12822488258322963187U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13664465415354326653U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10365386643010882315U;
            aOrbiterE = RotL64((aOrbiterE * 3687934567254955761U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2003863843075564853U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8864134110143237364U;
            aOrbiterB = RotL64((aOrbiterB * 4586162015675320985U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8055736412403126985U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15383045568644941552U;
            aOrbiterA = RotL64((aOrbiterA * 5175405553995854715U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterG, 40U));
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 20U)) + aOrbiterG) + aNonceWordA) + aPhaseEWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25806U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneB[((aIndex + 24019U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25736U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22372U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24132U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 24453U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + 2915859148137000694U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 210680583721444425U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 37U)) + 6668118118775650387U;
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 15794200818099010989U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 58U)) + 6565076707062828369U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 16323164497808856719U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 19U)) + 7965435318816716560U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererH + RotL64(aCross, 21U)) + 7390281030573369017U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 44U)) + 2269738866911824875U) + aNonceWordJ;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 9664014216039993873U) + aNonceWordM;
            aOrbiterG = (aWandererA + RotL64(aIngress, 41U)) + 18284857398028357633U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 367667619795303009U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7935945060956274197U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5481786693511955209U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16683666162337789540U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10655658270998102390U;
            aOrbiterE = RotL64((aOrbiterE * 15231596813382239841U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8307037916581540297U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3247742749860703524U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 15052136713218656641U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10446792483683818139U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16374602929344972364U;
            aOrbiterF = RotL64((aOrbiterF * 12599903932725787599U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2411334498322777183U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1093701164116833765U;
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17018480952982840635U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17348395690080029814U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6212591395713433257U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16111252311283623152U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12776492920397785951U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6136009241593081821U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12214538600808144816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10043377462096783363U;
            aOrbiterB = RotL64((aOrbiterB * 14639467375095185877U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5101561512438055661U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3683207847147603335U;
            aOrbiterD = RotL64((aOrbiterD * 14355438383379198639U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14446947359104987749U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7596096688268335354U;
            aOrbiterJ = RotL64((aOrbiterJ * 13522935803383107145U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14015424109468938015U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2915859148137000694U;
            aOrbiterG = RotL64((aOrbiterG * 3653144205211106817U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterC, 24U)) + aOrbiterH) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterB, 6U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27497U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 28337U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28107U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31899U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28538U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 27U)) + 2571116506511057880U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererH + RotL64(aIngress, 4U)) + 13112435411509707292U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 37U)) + 10403251762787357256U) + aNonceWordO;
            aOrbiterA = (aWandererE + RotL64(aCross, 23U)) + 8461951095541400405U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 9890793478557463815U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 3030229465991783707U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 7273848154043719247U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 10681774862516028276U) + aNonceWordP;
            aOrbiterD = (aWandererC + RotL64(aCross, 39U)) + 7105082755586853104U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 19U)) + 6588579345319551129U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 54U)) + 14616333550242386092U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15439666290229654921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3360304356760164799U;
            aOrbiterF = RotL64((aOrbiterF * 5164191920584106237U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14438730801970761889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14515616787452085729U;
            aOrbiterC = RotL64((aOrbiterC * 2041601927968559821U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4167853822635132419U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8950982233003320239U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12391327853728029953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7100871010552394421U;
            aOrbiterD = RotL64((aOrbiterD * 16552349374101955967U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15381697462381887944U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6801677551341079401U;
            aOrbiterI = RotL64((aOrbiterI * 13325954438427340703U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 947011315719204867U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterK = RotL64((aOrbiterK * 5566721941682667419U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8910262020598577378U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8778455415977526457U;
            aOrbiterJ = RotL64((aOrbiterJ * 4092470497616637283U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5585696961453127223U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9670655481681494412U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 7863197168965036383U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10713004007087085729U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4036355047492922339U;
            aOrbiterA = RotL64((aOrbiterA * 6923922258047667173U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 14580156873863533497U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7049502932205025182U;
            aOrbiterB = RotL64((aOrbiterB * 8665428649262370727U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12707521269341941677U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2571116506511057880U;
            aOrbiterE = RotL64((aOrbiterE * 2388236789245943699U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterF, 46U));
            aWandererG = aWandererG + ((((RotL64(aCross, 46U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aNonceWordK) + aPhaseEWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_PingPong_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x970BA4D5A0145579ULL + 0x91D4FF688BC3DD2BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAB765A5354B59B9BULL + 0xEF3EBF40B66C23CCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8E00F0879B387481ULL + 0x95F12A20498FFBA2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD528E3AC9CB3D0C9ULL + 0x8C7ACA9748B076FFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE8415F0545FE67AFULL + 0x9C93AB8B3AEB2BFBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x93E3712D8102DDD1ULL + 0x8FA15B72481CFCD8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xABD3630B521F18F3ULL + 0xDEE925E7B3A3F407ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFC6081078FD0C623ULL + 0xBD63F531F3EB42BBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD67C720732F0127FULL + 0x85708054C553532BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x94BFD8038D3363AFULL + 0xE0AD7CE80E22AC2AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA4FEB56E8BF64723ULL + 0x8366060ED107A620ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB5DF1288BBA3AFBDULL + 0xF1E822FE22063C2BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8B1908849B108CB5ULL + 0xB2D2BFCE812E0AE5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAA401F74DC9681EBULL + 0x99A5D55524D64B3DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD81CE9C916867F65ULL + 0x93AC9F5FBDA1B4A9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD49CF219A70034F3ULL + 0xD11252CAE45E007AULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneB, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneC, aWorkLaneD, aInvestLaneB, aSnowLaneD, aWorkLaneC, aExpandLaneA, aInvestLaneA, aExpandLaneB, aSnowLaneA, aExpandLaneC, aInvestLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3414U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 512U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 58U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 63U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1969U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2668U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 20U)) + 1457104756581596530U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 6127240317844622874U;
            aOrbiterC = (aWandererI + RotL64(aCross, 29U)) + 16492290056044189421U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 47U)) + 10963676850938416468U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 58U)) + 4872917367399752405U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 15218882377875616148U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 11U)) + 5934166612122118251U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 14215280930872003003U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 3U)) + 11428034799044600979U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5453003654321728726U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14273775120265649389U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5139018128323795309U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 328723770018440271U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13032190719588211088U;
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2386881543033598494U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1649501123340887116U;
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16462401546754210583U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1510579201823042227U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6889066000014251983U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11324594596597724357U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15344987814648586023U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12237796033168436537U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17306069670330000343U;
            aOrbiterG = RotL64((aOrbiterG * 3167451351403385259U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14197284538008811658U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4754134852883071927U;
            aOrbiterB = RotL64((aOrbiterB * 3484427259538998699U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17201907781639753736U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8318419319239859855U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 10320390501983802091U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16012488623961565780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15583721012865354925U;
            aOrbiterJ = RotL64((aOrbiterJ * 10656414363201743961U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 6U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + aNonceWordK) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 10152U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 7509U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5785U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6177U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7054U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10685U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 6861U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 36U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 39U)) + 2783898056762489197U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 7177192902873343053U) + aNonceWordM;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 21U)) + 12254703232691980774U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 27U)) + 15446547245691219559U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 19U)) + 888475203006174856U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 3U)) + 3649183529366307877U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aWandererB + RotL64(aCross, 52U)) + 4642631047518805167U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 43U)) + 6108329730724782250U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 8334054653023816636U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5891895375031474350U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3176720746238477862U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1869961473768307911U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6111038696865301675U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11914998302228682704U;
            aOrbiterA = RotL64((aOrbiterA * 11738924766359642853U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17005063057791320948U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18333780598768130670U;
            aOrbiterE = RotL64((aOrbiterE * 5416759844884107303U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2056115016443263153U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10245512728872962677U;
            aOrbiterF = RotL64((aOrbiterF * 707106795383284903U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4810366069422162351U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3051442983125942469U;
            aOrbiterB = RotL64((aOrbiterB * 13558537578054436423U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9285068547223654308U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 13067251130180968842U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 7000687697769766605U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 3203670242792002165U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1770881716916463461U;
            aOrbiterD = RotL64((aOrbiterD * 13870229847371882171U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16286823712870537410U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13067191141829694202U;
            aOrbiterI = RotL64((aOrbiterI * 15629974528467350445U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3414576315085336932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8979691827341555245U;
            aOrbiterH = RotL64((aOrbiterH * 15971594804040295757U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 44U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterE, 14U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 53U)) + aOrbiterF) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 34U) + RotL64(aOrbiterH, 42U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererE, 40U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13819U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 16346U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12593U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11383U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13306U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 60U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 60U)) + 15910560457440369082U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 23U)) + 17953072986407436888U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 35U)) + 15446940721193538669U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 3020785262774422009U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 54U)) + 7001288645424994404U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererK + RotL64(aCross, 19U)) + 13385250665458462689U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 47U)) + 4841895644623005949U) + aNonceWordE;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 13053476783239482065U) + aNonceWordJ;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 641996979335975244U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16211238020928688299U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12715448751323279480U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 2116880429675303291U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17784406727699995290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16626339815786580778U;
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9035070625716345139U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6085848172494001945U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 10405728912339646693U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1177103851507561053U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2281901691017816407U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3142197009403602497U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9040984343694325070U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13334258224023902365U;
            aOrbiterG = RotL64((aOrbiterG * 4782523727707164869U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1079824790138592518U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14024082692012948652U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3219489374333737903U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2966776524421278970U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5510281854029308547U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9275402927591867297U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7126632329316720048U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1476827035602733472U;
            aOrbiterC = RotL64((aOrbiterC * 2217671289726794033U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6470212302133184965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4172257438373147415U;
            aOrbiterI = RotL64((aOrbiterI * 4449314239630366533U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 6U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterK) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18413U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneC[((aIndex + 16501U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 19149U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21369U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 19455U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererB + RotL64(aScatter, 60U)) + 8020711767807230555U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 15368693777246341570U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 23U)) + 5117523734225562401U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 27U)) + 13155269151097507808U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 34U)) + 9879303753623578272U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 1165799257173794826U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 47U)) + 930641942062732091U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 11330571332221123153U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 2862963158282518899U) + aNonceWordM;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6019186399361476659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1924419843785161958U;
            aOrbiterJ = RotL64((aOrbiterJ * 9485557122500346869U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12618629043591380461U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9334176504266512405U;
            aOrbiterD = RotL64((aOrbiterD * 18239109235362925739U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16829692481030013551U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5604784396927022709U;
            aOrbiterF = RotL64((aOrbiterF * 2833893610883508353U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16124030106598549644U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16571659812830230677U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4668250364992383549U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 15171089673591843703U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2826755560293849328U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9397017963457655287U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9976785768283589291U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11845100564714691809U;
            aOrbiterA = RotL64((aOrbiterA * 4935139932585319251U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7318560453127859950U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3039196878830506712U;
            aOrbiterG = RotL64((aOrbiterG * 3140508261330698717U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8850992055588337843U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4219373528176869146U;
            aOrbiterC = RotL64((aOrbiterC * 1310964742529956743U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1341474458715938799U) + aNonceWordG;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 15937557372891732898U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 11437307017920192915U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 38U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 28U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterF, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererE, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aSnowLaneA
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aSnowLaneA forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22659U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 23190U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 24017U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25019U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((aIndex + 23754U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 57U)) + 2974056819475622600U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 34U)) + RotL64(aCarry, 11U)) + 7345051759236356098U;
            aOrbiterD = ((((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 12738468816846628882U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 19U)) + 7694520596043297922U) + aNonceWordC;
            aOrbiterK = (aWandererE + RotL64(aIngress, 29U)) + 5530753590015084774U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 43U)) + 3776309161718383105U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 51U)) + 784780304358106404U;
            aOrbiterG = (aWandererB + RotL64(aCross, 47U)) + 8999942326995036509U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 41U)) + 5194986506064092779U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7920040007459652762U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11311997270710107937U;
            aOrbiterD = RotL64((aOrbiterD * 6227571709361790209U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5365231114813547251U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8630110234623825263U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 2735881715888325759U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2358235238039571072U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterC = RotL64((aOrbiterC * 17150786106857185467U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14526050556461782864U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6937282036603272474U;
            aOrbiterA = RotL64((aOrbiterA * 14954512365270028029U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 10105832250694931310U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3884223553012098137U;
            aOrbiterE = RotL64((aOrbiterE * 16340956813003906195U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10385284339549648087U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1257633893341505930U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2669950791270500977U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5528890519572824318U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15664241747527713256U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 16670884497088220497U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14264122979415331887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17985061405540198036U;
            aOrbiterH = RotL64((aOrbiterH * 2729487440173395133U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1663986734997903415U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3706166884286400587U;
            aOrbiterG = RotL64((aOrbiterG * 10549736618301955745U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + aNonceWordF) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 10U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 58U)) + aOrbiterE) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32680U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 27518U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 27417U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31462U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31503U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 16200278595895089008U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 43U)) + 1029614154810465897U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 7129562468705441295U) + aNonceWordJ;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 14388903902433951274U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 51U)) + 1013568949315967455U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 47U)) + 3128823373497815651U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererC + RotL64(aIngress, 3U)) + 14525694606889470589U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 14443983602196782887U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 14U)) + 12244220415328641190U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10477159225338766614U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2842870123078131566U;
            aOrbiterC = RotL64((aOrbiterC * 11522265477555954071U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8621138818955849917U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5038396344400303181U;
            aOrbiterE = RotL64((aOrbiterE * 14636756322207385447U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2768613802894372496U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2027754864051410015U;
            aOrbiterA = RotL64((aOrbiterA * 2461322540050569287U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2848088309172056399U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15017458513904884651U;
            aOrbiterI = RotL64((aOrbiterI * 9926904679902843055U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9079797279596336139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15424866642305110811U;
            aOrbiterB = RotL64((aOrbiterB * 12912331089970158845U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13751764050290602740U) + aNonceWordG;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 7694557131324740282U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 14980807690491467023U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3508673897305667669U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3600868397311393233U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1222655844979128996U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2257342337168905875U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6198995971182272119U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6290990717563682725U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15308494772443447109U;
            aOrbiterD = RotL64((aOrbiterD * 1925593111157842325U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 60U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + aNonceWordM) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererC = aWandererC + (((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 57U);
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

void TwistExpander_PingPong_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE30524E13C54B307ULL + 0xDCAF20B3D282EBF3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE62F31915543DD91ULL + 0xBA6A45823538162EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBDAC380115EFAFF1ULL + 0x9AC2CB40129667CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBE88BD4CA443BAC1ULL + 0xAF123BA5BEE2F249ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD458AF65E362A959ULL + 0x99389BC454BD9A17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCEB4BADFCBAB04C1ULL + 0x89ED935B4FADBABAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF4FE48EC774794D3ULL + 0xCFB702A777CE46A7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC97A689BE2B344AFULL + 0xC2ECC770A0DA81B0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x874D4CDE929EC60DULL + 0x8FC1E074FBD17139ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9D71CBEDC89B4635ULL + 0x95A19F3B66D08FCDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEF95071A85881E51ULL + 0x960DBE06EEE1B7C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB8D7477D35E0A39BULL + 0xFF3EC19D86656B65ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9D9FF80AA11B2087ULL + 0xD7196417BD0EEC2BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA65424D0A4C3C6D1ULL + 0xE631B7700139C333ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFA96FB08E4B5DF8FULL + 0xBB08AA7A227096DBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB44DF96B55DAC455ULL + 0xFDE3A6A22DF0D953ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD, aWorkLaneA, aFireLaneB, aFireLaneC, aWorkLaneB, aInvestLaneC, aExpandLaneA, aInvestLaneB, aExpandLaneB, aFireLaneA, aExpandLaneC, aFireLaneD
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 797U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 3663U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5313U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3883U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2228U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 5073U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 42U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 12535417189990029950U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 11U)) + 6204401443676390273U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 869613505613154672U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 41U)) + 15053590879563855802U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 22U)) + 13338989605204591428U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 51U)) + 18306470022403825392U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 1150696349434090218U) + aNonceWordJ;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13549541786420596437U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14302878430259588461U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16813606782134305513U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4660437084477165225U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1653628537860912069U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2624835201155303123U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5594199757006711631U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11008472193138708891U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13645764762027798301U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3668516817279364310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 128159531749679984U;
            aOrbiterA = RotL64((aOrbiterA * 4523246859249826987U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6378674346113979108U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11438762460659123362U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 2733309638158283953U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10624263004446482910U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12546839706919241411U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 11468326687628079347U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8466639576503293921U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5828694979857951504U;
            aOrbiterJ = RotL64((aOrbiterJ * 7835487310289634515U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + aNonceWordG);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aNonceWordO) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8252U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 8682U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6570U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7266U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9272U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8052U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 9081U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 58U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 18087125778766689269U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 47U)) + 13710545066503235196U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 29U)) + 1701939704736254645U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 8064093611384019909U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 21U)) + 16623332751533885431U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 15590129153794910109U) + aNonceWordM;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 54U)) + 7413312683079107383U) + aNonceWordA;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 4186064478651458810U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5501191643940735954U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14254804649177125269U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11064645242200570835U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13825922087298055833U;
            aOrbiterJ = RotL64((aOrbiterJ * 7529317892716108867U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5944980709887369970U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8181136916070569646U;
            aOrbiterA = RotL64((aOrbiterA * 395183021205661827U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15442336949157292482U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11580554435240641337U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 6654637892858767739U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11240018128174598322U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2027565596050777471U;
            aOrbiterK = RotL64((aOrbiterK * 18048186560314431815U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16425887196883725233U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16828683527588834095U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17746289103235902485U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9923829146479008804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6669171007279929454U;
            aOrbiterF = RotL64((aOrbiterF * 681823450939955099U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 24U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aNonceWordF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12218U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((aIndex + 15879U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 14081U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11334U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15949U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 3U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 13U)) + 5041131702736607991U) + aNonceWordJ;
            aOrbiterF = (((aWandererG + RotL64(aCross, 39U)) + 9295010428212681446U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 6235875895358766017U;
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 2622227802531866918U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 3888894734834524972U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 6U)) + RotL64(aCarry, 5U)) + 241682012014701753U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 53U)) + 15758000422451568079U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2061944548396976912U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8177144990755754531U;
            aOrbiterH = RotL64((aOrbiterH * 12702392689484397947U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 554978075608818497U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 250408260560714933U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 1295379390497107727U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8700027645880997552U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10026130047465480902U;
            aOrbiterI = RotL64((aOrbiterI * 12417270861933696623U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9785843014096326696U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9998582683258411251U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13817734599383455151U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6647207154174092691U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1578528131687283531U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4957715980509035719U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4994885315786213197U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 5676683798126497011U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5072908311783966503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5535039946192891515U;
            aOrbiterJ = RotL64((aOrbiterJ * 2989412783482309753U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aNonceWordA) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterF, 36U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18108U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 20364U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 21661U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17711U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18452U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 23U)) + 5576732410244514238U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 30U)) + RotL64(aCarry, 35U)) + 2833808925935929629U) + aNonceWordK;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 3670188682914544792U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 37U)) + 15759072378887814995U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 43U)) + 13934007231137439994U) + aNonceWordA;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 11022225696007690512U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 5U)) + 16989177104453635790U) + aNonceWordF;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9256930045263527091U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17788596104417068290U;
            aOrbiterD = RotL64((aOrbiterD * 675554110563253305U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17044369456673337625U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1310908395523250343U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 16305084373037705921U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12067065689034065422U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15130844248737512262U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9409499577465934107U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14532689204495587494U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8198147292120244178U;
            aOrbiterF = RotL64((aOrbiterF * 1418356389507740991U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5485494458627163347U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10830008207150307611U;
            aOrbiterC = RotL64((aOrbiterC * 6526039534042499457U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 17770065502486618029U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6397859353395335459U;
            aOrbiterJ = RotL64((aOrbiterJ * 14286997752368893825U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5128700697381508319U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7103394110057060499U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5053680689949149633U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aNonceWordL) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26558U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 26653U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 26059U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25709U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22034U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 36U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 6163290588946759209U) + aPhaseHOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 7342672468560105447U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 29U)) + 11574563167017282321U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 60U)) + 2254820206194758964U) + aNonceWordP;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 13U)) + 1469783447473099498U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 47U)) + 14174828900676165088U) + aNonceWordC;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 16277954291890598132U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 14845750668693136766U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 150099699692047766U;
            aOrbiterG = RotL64((aOrbiterG * 7644895634421086357U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1200784917165131703U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9469982764806754302U;
            aOrbiterC = RotL64((aOrbiterC * 17851969334511301943U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10956702761701710182U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17335794183733623213U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 557028996286989506U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1597385667771002414U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4376417959915162639U;
            aOrbiterH = RotL64((aOrbiterH * 4626236858205178149U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 549770198518993876U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 756554555648070919U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 16272320259614325355U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7298557532533152193U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 3336802611342112013U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 14679103452120080499U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 28U)) + aOrbiterC) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 53U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32352U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 29628U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28064U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30674U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 27738U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 11U)) + 6318740973868639425U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 35U)) + 5487840061430920881U) + aNonceWordE;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 10258706763248072672U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 18356875269730338208U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + 12883160282903147010U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aIngress, 50U)) + RotL64(aCarry, 53U)) + 1010140474942697730U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 17733939421700898293U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13693055887924981201U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14574732452793385269U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 9373765929885750185U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10832873941223609012U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8212600587135328040U;
            aOrbiterB = RotL64((aOrbiterB * 5334613996794796145U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 5312744319781971178U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 6173741211706546923U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3693249147883790810U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 18365859989736602556U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3348463719324104997U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10645056678337549771U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1175668356822251045U;
            aOrbiterD = RotL64((aOrbiterD * 6579675292775345579U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13556844570541823717U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4790355739411849736U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 4083544011788850307U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14905575502272644116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17047244574558476634U;
            aOrbiterK = RotL64((aOrbiterK * 2356386971503880047U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 6U));
            aWandererE = aWandererE + (((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aNonceWordO) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterG, 41U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_PingPong_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 506U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1092U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 329U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 935U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 13U)) + 5960680319644404115U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 35U)) + 16050752633567034185U) + aPhaseAOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 3U)) + 8447503223226854741U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 52U)) + RotL64(aCarry, 35U)) + 14176813813397917591U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 10534915376130006644U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 47U)) + 6866224454375302514U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 16506374165041008396U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 27U)) + 7167814023968794098U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 40U)) + 13870852197416596664U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18064038854848993105U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9869630811507771691U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13723164383800461387U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 863613100452759380U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16597969741225436529U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2680793528887208903U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6575347108051310653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17062262265485019063U;
            aOrbiterF = RotL64((aOrbiterF * 7601045488473620019U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7193399224636409133U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14146747818810433849U;
            aOrbiterJ = RotL64((aOrbiterJ * 5273185769989530041U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9441449106442431427U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4303295336545399503U;
            aOrbiterD = RotL64((aOrbiterD * 8829695296836242587U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12604760768543193458U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15779327512379787715U;
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15553000781122708728U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17162740616060079717U;
            aOrbiterK = RotL64((aOrbiterK * 9458662233556750239U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1032374679817715156U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16413393156165548232U;
            aOrbiterE = RotL64((aOrbiterE * 549659738811935015U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14056855000013992045U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7399202019042538829U;
            aOrbiterC = RotL64((aOrbiterC * 6103508549612077695U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterF, 26U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterD, 5U));
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterD, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3629U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4082U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4038U)) & W_KEY1], 54U) ^ RotL64(mSource[((aIndex + 4195U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 20U)) + RotL64(aCarry, 29U)) + 8101351470141807662U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 6965474099521076705U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 6803828268885684784U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 35U)) + 13454235922950972488U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 57U)) + 11678091885751244777U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 53U)) + 5307134544628507141U;
            aOrbiterE = (aWandererF + RotL64(aCross, 11U)) + 4873703518950429353U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 8542156221858586039U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 24U)) + 3993726182905296513U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12113047622035464386U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1944244448665721151U;
            aOrbiterG = RotL64((aOrbiterG * 7010050836758762003U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12914188029425467576U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2486762763475327024U;
            aOrbiterF = RotL64((aOrbiterF * 12319769994433811617U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14580191602982245481U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12093414832400135066U;
            aOrbiterJ = RotL64((aOrbiterJ * 12720286833215690663U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13623906997320021065U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9977356009806428696U;
            aOrbiterA = RotL64((aOrbiterA * 2005536391712733499U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3694954095397810851U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11453812627797091638U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 542311345544726351U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3024285045990499484U;
            aOrbiterI = RotL64((aOrbiterI * 5153745952148205645U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15397664082460849530U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10716856680110815056U;
            aOrbiterD = RotL64((aOrbiterD * 13947203772929252823U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 833342121331428547U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1111339940097269219U;
            aOrbiterE = RotL64((aOrbiterE * 17991642769781175473U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9312963978841402871U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8225496710723213204U;
            aOrbiterK = RotL64((aOrbiterK * 894499195498817065U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aPhaseAWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterD, 20U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK + (((RotL64(aScatter, 12U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 34U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5587U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6507U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7191U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7069U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7454U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aIngress, 35U)) + 1297415699043177788U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 57U)) + 17583786534509260153U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 643197858925708798U;
            aOrbiterA = (aWandererE + RotL64(aCross, 18U)) + 5062653766915694874U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 13U)) + 7034273638367180511U;
            aOrbiterB = (aWandererG + RotL64(aCross, 39U)) + 2026909726972916996U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 2785690475553211646U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 4U)) + 2910341716302991892U) + aPhaseAOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 2834181605200829791U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13323052600571281928U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10434901530315760460U;
            aOrbiterI = RotL64((aOrbiterI * 2042210188346767033U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 247903955625194782U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5196515747387257163U;
            aOrbiterG = RotL64((aOrbiterG * 1799024689023272275U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7196305682377987476U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14777739876892587484U;
            aOrbiterF = RotL64((aOrbiterF * 95220583948241581U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10609060796540136671U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8386027207212484155U;
            aOrbiterE = RotL64((aOrbiterE * 4855610536246556893U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 729659744301903424U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2350564261412606157U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16713856782349084977U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16611987556673864177U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1525195188708550503U;
            aOrbiterK = RotL64((aOrbiterK * 10045858602151004553U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4654808490980989596U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8189569777087686263U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17278657566389299577U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10932857495004451792U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1833880112534916813U;
            aOrbiterH = RotL64((aOrbiterH * 8004341577533825681U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13100236350175516423U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2773759534195186313U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3194954066097323161U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 42U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterK, 60U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aPhaseAWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 42U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10616U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 9552U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 8844U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 10288U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9879U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 10384U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 13U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + 10881271196314989997U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 51U)) + 6406461249988567558U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 17255067918280095959U;
            aOrbiterC = (aWandererI + RotL64(aCross, 11U)) + 16690850682497718411U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 43U)) + 5576201059361086866U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 35U)) + 11991259685693687554U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 24U)) + 14652535244217836909U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 1701789037170782122U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 953429054903473833U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12064513610469714211U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7993881398822002424U;
            aOrbiterI = RotL64((aOrbiterI * 11572884842788918377U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14421313768013320050U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11112386845630998889U;
            aOrbiterB = RotL64((aOrbiterB * 11771526352030371669U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17069630896535699015U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3308240081138623373U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10449509484417835159U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17615529807112933619U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11782807146851563541U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12992075832343669221U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14401645829607611983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6736397344219993532U;
            aOrbiterH = RotL64((aOrbiterH * 1667287547938175641U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6446974060524700550U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7840991992443308254U;
            aOrbiterF = RotL64((aOrbiterF * 6891023544882740107U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10362169906019794305U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4503700997923168911U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15066164494038852559U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13492041134973259041U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14337899277551397976U;
            aOrbiterC = RotL64((aOrbiterC * 5966740718899290915U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13693100781608180748U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16177545026405910052U;
            aOrbiterG = RotL64((aOrbiterG * 6019231448444020563U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterH, 58U)) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 34U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11115U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 11863U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13006U)) & W_KEY1], 58U) ^ RotL64(mSource[((aIndex + 10957U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12772U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13623U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13483U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 12U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 60U)) + 4622023259121087483U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 3U)) + 10253505250223501352U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 51U)) + 17133877904420462669U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 6162827793741796700U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 9610986424765907615U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 41U)) + 11210747154264753754U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 56U)) + 16554205219580654546U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 13U)) + 10352576357413766388U) + aPhaseBOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 3651845783283479752U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18145542190463500476U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5415609566767162857U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6474184559323816389U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2033734872464201570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3507213117125813345U;
            aOrbiterC = RotL64((aOrbiterC * 5453058336688881113U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8716253393049851856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 695984869565941856U;
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7661578828878284931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 906654265099155956U;
            aOrbiterJ = RotL64((aOrbiterJ * 8117625377607536949U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6050049984731254612U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17882717590338190821U;
            aOrbiterA = RotL64((aOrbiterA * 10807367411402733215U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4996521991532815957U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4246460672800604436U;
            aOrbiterB = RotL64((aOrbiterB * 12047466401960824903U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8700148116452518842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10039050281847466206U;
            aOrbiterK = RotL64((aOrbiterK * 11884791271239660157U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4513844680425845372U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3037563127442815153U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18363509277992292407U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1005237931570968724U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1373258132025712065U;
            aOrbiterD = RotL64((aOrbiterD * 10458020799382532395U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 24U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 20U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 28U) + aOrbiterB) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15993U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneA[((aIndex + 13896U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15928U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15056U)) & W_KEY1], 37U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15287U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16015U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14703U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aCross, 27U)) + 3255291173184001106U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 34U)) + 15308468160116255528U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + 18186972408589866656U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 23U)) + 4439324265978331914U) + aPhaseBOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 39U)) + 13099263173016322486U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 7041561081767500660U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 39U)) + 6196422612687812971U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 7664260932541281413U;
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 17802347823020441056U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4253107484061190446U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13799496534030645312U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9167675060053848207U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14252892847595951926U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5663527578664291422U;
            aOrbiterG = RotL64((aOrbiterG * 18314294235895182465U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11148755959699137661U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17036900929333594592U;
            aOrbiterI = RotL64((aOrbiterI * 16041243617369003291U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2403828181385259549U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17813580350434928194U;
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5623611126885414523U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7293224381174846969U;
            aOrbiterJ = RotL64((aOrbiterJ * 7032561584670788117U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10602620906929686163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 18015916257203385982U;
            aOrbiterC = RotL64((aOrbiterC * 10684090189688871993U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13592915735376305773U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13995866908043417505U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3802175869395887331U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8200465989447697618U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9866671660800629464U;
            aOrbiterD = RotL64((aOrbiterD * 2138851839905326265U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11557528777230608777U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 131060617338185060U;
            aOrbiterA = RotL64((aOrbiterA * 11068705423012265209U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 42U)) + aOrbiterD) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 34U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18352U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 17563U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(mSource[((aIndex + 16988U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17317U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18065U)) & W_KEY1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18534U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16836U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 57U)) + 6771552164800695068U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 6U)) + RotL64(aCarry, 13U)) + 12131763371571322040U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 3326182381395522013U) + aPhaseCOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 12288775097697156383U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 35U)) + 5195948373449796741U) + aPhaseCOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 43U)) + 14404044002250137144U;
            aOrbiterC = (aWandererB + RotL64(aCross, 24U)) + 11142382920035825426U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 39U)) + 2967149520256475485U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 19U)) + 1470907369577818097U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9231668148004163910U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13078929163913892386U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7509829068700523627U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9485274692075657877U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12216951187543631673U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6571066246507310805U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6933334652581744234U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17260276102423580920U;
            aOrbiterG = RotL64((aOrbiterG * 7796879893790990605U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 387767848169714392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8597538259308082638U;
            aOrbiterD = RotL64((aOrbiterD * 4888054690557707241U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7996708724489146033U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15357384191688149939U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9827691726832491373U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17739222908739454637U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1614322333281471170U;
            aOrbiterC = RotL64((aOrbiterC * 7063116837752240891U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4531604274893197209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3453280714992341288U;
            aOrbiterB = RotL64((aOrbiterB * 8390029711127907805U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 116623650872661533U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6565636510115095988U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9691897067492501177U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10303258439817808058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10917642773040237611U;
            aOrbiterI = RotL64((aOrbiterI * 10232856828372963363U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 46U);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 40U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + aPhaseCWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterG, 21U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 46U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aPhaseCWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19427U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 19402U)) & S_BLOCK1], 24U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20098U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 21809U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20226U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19672U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20332U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19513U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 5906639480605353429U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 10U)) + 5293518570213287605U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 15383185501428521377U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 43U)) + 15364072512743978902U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 27U)) + 4525473357144014271U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 10400911938125603074U;
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 16417506293824627550U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 3U)) + 2419329331753341815U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 23U)) + 14929222427923332069U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16771573504983922586U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1863466450051787622U;
            aOrbiterG = RotL64((aOrbiterG * 2585626547126027053U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12895350137096692415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3700979086526298327U;
            aOrbiterJ = RotL64((aOrbiterJ * 10279730254867618193U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1977099106211282426U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6144698304096915742U;
            aOrbiterE = RotL64((aOrbiterE * 5039822990560519609U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3858895556659724975U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1283646340363435327U;
            aOrbiterC = RotL64((aOrbiterC * 11622421841377018069U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6240532051889108891U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 757364889381634634U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 943852137901972945U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5272945693977418174U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6850528198786172283U;
            aOrbiterK = RotL64((aOrbiterK * 1966383079897679953U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14431587733859573714U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16124590257870999553U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7755796211433191143U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14912695018110241411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11098623474413346520U;
            aOrbiterD = RotL64((aOrbiterD * 15167688959990872051U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3484847683376368686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2295388097292719800U;
            aOrbiterH = RotL64((aOrbiterH * 1240808318176106909U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 36U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererH = aWandererH + ((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 26U)) + aPhaseCWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23489U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 23313U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22797U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((aIndex + 23206U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22130U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24155U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24058U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 23664U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 29U)) + 8866844335448071821U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 39U)) + 15159698739856430085U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 19U)) + 9582805772989594633U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 5U)) + 1438538239931588373U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 43U)) + 10862044156620436139U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 13682173320058164615U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 8351013291045977592U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 52U)) + 15777857431516633916U) + aPhaseCOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 23U)) + 16178966745333885377U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9031889187993001617U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6308472367425865347U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17118710301967158153U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 642109145903321046U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9186268569255318035U;
            aOrbiterC = RotL64((aOrbiterC * 10714674348507516749U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6091345356803675860U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13218507921880873749U;
            aOrbiterI = RotL64((aOrbiterI * 15415157927185637717U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4266652275234474616U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4391422098164506195U;
            aOrbiterK = RotL64((aOrbiterK * 17634679403195085867U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5160682323243635577U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10351728852161347404U;
            aOrbiterD = RotL64((aOrbiterD * 11105410036471745951U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3950932176454814023U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9536466386833427441U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18064984243491293435U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9927425919978776529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6819384090527481081U;
            aOrbiterB = RotL64((aOrbiterB * 18032965969184368561U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1646274931424218507U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16166524473976135097U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11672192658072663849U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11252501968059485262U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16847854447987609067U;
            aOrbiterF = RotL64((aOrbiterF * 6326299154627028295U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 50U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 4U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + aPhaseCWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25235U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[((aIndex + 27048U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25929U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25950U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26046U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24626U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26788U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25161U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aIngress, 51U)) + 4739486756133131180U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 18U)) + 16089707555501328184U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 57U)) + 15310047330238536453U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 7901411596386834955U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 47U)) + 4357555491060982163U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 15667085602825720102U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 23U)) + 8520635334382269253U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 6U)) + RotL64(aCarry, 53U)) + 1772509779231068315U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 15336170957886025677U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8628770833489469980U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15469234024247246228U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8905266995119987947U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10796430900884288328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10660110397012853289U;
            aOrbiterA = RotL64((aOrbiterA * 9140007610912037461U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11202284258711214794U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17509491802893182994U;
            aOrbiterI = RotL64((aOrbiterI * 9329107599972703671U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16212572740740103554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2190030203761579226U;
            aOrbiterE = RotL64((aOrbiterE * 3101886685668871045U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12014337082293041909U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3733531010807001506U;
            aOrbiterG = RotL64((aOrbiterG * 5797362244066062299U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7100994963061975529U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17837541162838600258U;
            aOrbiterK = RotL64((aOrbiterK * 8745987361678166553U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3311518938023146951U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7709505172646831553U;
            aOrbiterH = RotL64((aOrbiterH * 7121143171245765213U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4979968094554018443U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16822214821463034107U;
            aOrbiterJ = RotL64((aOrbiterJ * 8618262120451291765U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8376124175020587079U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11084586282092424876U;
            aOrbiterD = RotL64((aOrbiterD * 5835632742522563537U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 48U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 10U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aPhaseDWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 46U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28230U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneD[((aIndex + 29760U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29246U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((aIndex + 28376U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28045U)) & W_KEY1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29485U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27361U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 29907U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 4U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aIngress, 23U)) + 6916817163240024692U;
            aOrbiterG = (aWandererE + RotL64(aCross, 42U)) + 14554930751292077817U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 11U)) + 1098305064484336101U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 12192821172420471527U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 2435134991707318845U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 46U)) + 1896745368738512624U;
            aOrbiterE = (aWandererH + RotL64(aCross, 57U)) + 1114996424222923873U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 9839135798371512656U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 5U)) + 8037967239603177043U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15185468738487237432U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4912098316394854543U;
            aOrbiterJ = RotL64((aOrbiterJ * 3072785550384399929U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13142688607850380888U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4507379759608945839U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7299006009652289342U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5390655277207053627U;
            aOrbiterD = RotL64((aOrbiterD * 10973744708856143715U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6744737023577785725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15539737698867067285U;
            aOrbiterE = RotL64((aOrbiterE * 4686092035261336911U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13329866734681377952U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13284937458969166257U;
            aOrbiterG = RotL64((aOrbiterG * 3965985432462699445U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8695002088915702168U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3858059421620839286U;
            aOrbiterI = RotL64((aOrbiterI * 9559783727301092937U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6609163873243179836U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9416165620556710540U;
            aOrbiterK = RotL64((aOrbiterK * 240385043740268229U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1578449067529000433U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14309000104419489303U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7599078306153684729U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15785180680737461320U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10099222679918382021U;
            aOrbiterF = RotL64((aOrbiterF * 2012232597046182581U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterE, 6U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterD, 40U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30121U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 32433U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30614U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31293U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31773U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 30454U)) & W_KEY1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 39U)) + 15920462086654025436U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 57U)) + 487844076858004017U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 46U)) + RotL64(aCarry, 3U)) + 14502883786442630566U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 5U)) + 3787107318658233674U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 11U)) + 12548777544693755491U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 51U)) + 4907309444075181683U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 18342396700266492072U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 19U)) + 13503051997624242670U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 34U)) + RotL64(aCarry, 57U)) + 17845742460521374571U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8640887211877858169U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5273913123709097537U;
            aOrbiterG = RotL64((aOrbiterG * 1661149444148461791U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17756844173695563883U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6713055830729302951U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2832836748513174311U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5106468334224035972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10228769728713526172U;
            aOrbiterC = RotL64((aOrbiterC * 9760310686414358435U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7687649520668883142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7757480627354711605U;
            aOrbiterD = RotL64((aOrbiterD * 7222553727737349209U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10876291698508634557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8149278085586014186U;
            aOrbiterJ = RotL64((aOrbiterJ * 8577133863470695381U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15592893988925610485U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8639028256640537165U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1880655276432963955U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 475660347892196219U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1903736092401853832U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8486318978769094799U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12463250192809450953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7253918448601703982U;
            aOrbiterI = RotL64((aOrbiterI * 3821034106528009129U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5171661020093804486U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11627344933828324146U;
            aOrbiterB = RotL64((aOrbiterB * 5388047063152043277U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 10U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 60U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 12U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_PingPong_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    // GTwistRunTwist_B twist_loop_b (start)
    {
        // GTwistRunTwist_B twist_loop_b lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneB, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 366U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 1806U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1801U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 862U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 324U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 6U)) + 15036852811491820366U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 305637140752898475U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 13U)) + 11948631574496129610U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 21U)) + 5321623592482991426U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 4075270159062690728U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 15111580500356908928U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 43U)) + 7244150695504160363U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5131563519577488862U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5881954992088651371U;
            aOrbiterH = RotL64((aOrbiterH * 2424421828597294607U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12780935808751507998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12599159643925470226U;
            aOrbiterD = RotL64((aOrbiterD * 17690046932587062701U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9466589929741834066U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6093158735705189789U;
            aOrbiterB = RotL64((aOrbiterB * 7453778295800853653U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17461243886150519249U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15456408913739900718U;
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11260643903290392780U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7870342756041882616U;
            aOrbiterC = RotL64((aOrbiterC * 2431528656086173419U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 134484990005888936U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10626896209992890407U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12034131076645285597U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14031164129515132292U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1771835705730244212U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 186981668443596623U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 6U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 40U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5955U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 5524U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 9503U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5795U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9614U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 14U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 8767379393098711499U;
            aOrbiterA = (aWandererA + RotL64(aCross, 3U)) + 7168159491580816433U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 37U)) + 9879279829061883406U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 10537167136053399303U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 57U)) + 2839070018069188936U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 44U)) + 13844278063968429732U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 11278946626186474646U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11798425216660557799U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7618446090703335192U;
            aOrbiterG = RotL64((aOrbiterG * 7168757300685156779U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 695423597006983660U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14344728202803488813U;
            aOrbiterA = RotL64((aOrbiterA * 5168825904902285909U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11656100506575697086U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10384358779985773937U;
            aOrbiterC = RotL64((aOrbiterC * 247494692039140973U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17585001605131977341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9964478171465522911U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13484044854790175315U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2710943171829692624U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17809072853457153057U;
            aOrbiterH = RotL64((aOrbiterH * 16341884203303271365U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12814092033910687774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1743186323268668740U;
            aOrbiterF = RotL64((aOrbiterF * 11150822630624332557U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10750472346626754704U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15925901217078035356U;
            aOrbiterI = RotL64((aOrbiterI * 9276504171291801637U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 18U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterB, 29U));
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12502U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 15698U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11433U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11989U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15075U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15605U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 36U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 6318740973868639425U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 27U)) + 5487840061430920881U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 10258706763248072672U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 18356875269730338208U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 14U)) + 12883160282903147010U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + 1010140474942697730U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 17733939421700898293U) + aPhaseEOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13693055887924981201U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14574732452793385269U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9373765929885750185U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10832873941223609012U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8212600587135328040U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5334613996794796145U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5312744319781971178U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6173741211706546923U;
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3693249147883790810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18365859989736602556U;
            aOrbiterI = RotL64((aOrbiterI * 3348463719324104997U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10645056678337549771U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1175668356822251045U;
            aOrbiterD = RotL64((aOrbiterD * 6579675292775345579U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13556844570541823717U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4790355739411849736U;
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14905575502272644116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17047244574558476634U;
            aOrbiterB = RotL64((aOrbiterB * 2356386971503880047U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterF, 12U));
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18243U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneC[((aIndex + 16936U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 20685U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19738U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18131U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21163U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 12027839670755583592U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 3U)) + 15380130703509859843U;
            aOrbiterB = (aWandererG + RotL64(aCross, 47U)) + 4590907433867798074U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 27U)) + 1754574023602519724U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 35U)) + 9832756659564903767U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 20U)) + RotL64(aCarry, 11U)) + 5035088494491470403U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 14199170923323644638U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8325619421264440438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 969534320779067977U;
            aOrbiterB = RotL64((aOrbiterB * 17767548306355264705U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 270575869402913847U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13344806516599578910U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10193544126281901579U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15143147951139409101U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14425582489214169238U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16893787086337916355U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13951127523239064584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14177925225918293579U;
            aOrbiterF = RotL64((aOrbiterF * 13079514031864998485U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8258920744278218901U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7408161179397242453U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 975737128100519169U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8581481606764773468U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10078416198417433133U;
            aOrbiterA = RotL64((aOrbiterA * 1102721083915858247U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 18299772198826189580U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 18304668908084397946U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10589455451200578687U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 4U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 20U) + aOrbiterG) + RotL64(aOrbiterB, 12U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26934U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 27204U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22525U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24021U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26876U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 26227U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 20U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 36U)) + 13583136155674166402U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 12830472187484919497U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 43U)) + 18081197909484522509U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 8680634051297891550U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 13939998767458656823U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 27U)) + 1795730579103692594U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 57U)) + 17369751719734069999U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 224769585901248068U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4133547085925268180U;
            aOrbiterD = RotL64((aOrbiterD * 2611561365156544735U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7022512056309567391U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10319484359046945495U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3400140531307001933U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10483878349412282069U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6481381149199985736U;
            aOrbiterH = RotL64((aOrbiterH * 9701719367082506253U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13721077228796934509U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9704818014314175007U;
            aOrbiterG = RotL64((aOrbiterG * 760445624027740287U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6253040047758584339U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16890211690273641226U;
            aOrbiterC = RotL64((aOrbiterC * 5622534399866057841U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6216227831265032436U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2023609047004658739U;
            aOrbiterA = RotL64((aOrbiterA * 3252332895698310147U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9201669637050388263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5106927540934338576U;
            aOrbiterF = RotL64((aOrbiterF * 6368134569042291431U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterH, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29243U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 29820U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27730U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28669U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29316U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27360U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 29U)) + 8988572360732005217U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 17889613225105985335U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 43U)) + 15563478320513948626U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 3441351228410524816U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 4425592689451435346U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 23U)) + 12733160231627305928U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 37U)) + 3574152157304607854U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15167631896729808783U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 15822667973915417055U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5155661648455308057U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17181685481076577637U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9979204751408873468U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8244434774754786565U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1334240485667164762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9190066751460137016U;
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15465215829109246336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2305208282453624419U;
            aOrbiterG = RotL64((aOrbiterG * 10257861974108363283U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16951510027310993926U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11117938943423526901U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12461379120662979432U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11719697049048823897U;
            aOrbiterK = RotL64((aOrbiterK * 14880996802304818757U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6843357278142933570U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12727898578324702374U;
            aOrbiterJ = RotL64((aOrbiterJ * 9786435451654365097U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 56U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 22U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 27U);
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

void TwistExpander_PingPong_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB, aSnowLaneA, aExpandLaneD, aExpandLaneA, aSnowLaneB, aInvestLaneA, aWorkLaneA, aInvestLaneB, aWorkLaneB, aInvestLaneD, aWorkLaneC, aExpandLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5231U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 3175U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 2925U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1442U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4872U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 3191U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 18U)) + 11480359716598965890U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 15431182525482873419U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 11360504974812776707U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 9292576416573382769U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 47U)) + 1549257414531028975U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 30U)) + 5347769463033129317U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 57U)) + 17019199177478377234U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 35U)) + 16558106007323125094U;
            aOrbiterK = (aWandererB + RotL64(aCross, 27U)) + 3976182233825939422U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 43U)) + 2889047161195954395U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 41U)) + 2241831345026962605U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12850802412140579294U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13541744735436450160U;
            aOrbiterG = RotL64((aOrbiterG * 906089290000537439U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2085863085516538212U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2969034221711544086U;
            aOrbiterB = RotL64((aOrbiterB * 7768528124408400403U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6482666944512391472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16969153556875844613U;
            aOrbiterH = RotL64((aOrbiterH * 9483462388353216219U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5161314086757363678U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7150282484670673211U;
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5465304381272305847U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2344610773390354017U;
            aOrbiterE = RotL64((aOrbiterE * 17010258514288089191U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8335906578006588582U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13668796013474193793U;
            aOrbiterC = RotL64((aOrbiterC * 8228000547141147777U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9663362594301419686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3683773739120343413U;
            aOrbiterJ = RotL64((aOrbiterJ * 8319320803406104749U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2538583190438044942U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4454069062219406996U;
            aOrbiterI = RotL64((aOrbiterI * 16329554225309389599U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17177136683616247897U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3680497519697457252U;
            aOrbiterD = RotL64((aOrbiterD * 6479357366957384599U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16812938441063719463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4545693142067578891U;
            aOrbiterA = RotL64((aOrbiterA * 17479957806084346527U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9232311730019478327U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11480359716598965890U;
            aOrbiterF = RotL64((aOrbiterF * 6678546065399772697U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 18U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterK, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 48U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterF, 44U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8432U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 10907U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7592U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6770U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8124U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7634U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9228U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 56U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 41U)) + 13915875634607599122U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 26U)) + 1695770381382411673U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 3709105579778295511U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 47U)) + 7673376335333251804U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + 8814147709738503518U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 37U)) + 13451412605350381172U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 6447870234069609538U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 53U)) + 13419487997946496825U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 5478309847615220345U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 57U)) + 3635184969215610049U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 18U)) + 12527903812035294828U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1684685110885338814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12860354576326835090U;
            aOrbiterI = RotL64((aOrbiterI * 12743745087733307255U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9081823570147481835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14369321778210049109U;
            aOrbiterC = RotL64((aOrbiterC * 17865953349448767035U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11518132079084873250U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11893535026126957389U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15751374986135615095U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7084079180579206226U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2999676609847603277U;
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17683445810614029153U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11576460512964896969U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5243651036457051155U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13429800604736567949U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14661785761747367546U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4765843989277333421U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12837164345582888950U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6222666313184669392U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17402483466567712319U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5358647039491079457U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12459911673401497180U;
            aOrbiterJ = RotL64((aOrbiterJ * 13605465035256188065U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3333017644772803587U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15501587702102554928U;
            aOrbiterH = RotL64((aOrbiterH * 4921693371641768339U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8492287653837766613U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3432736785678875404U;
            aOrbiterD = RotL64((aOrbiterD * 7326419883291516513U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2841486107704281869U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13915875634607599122U;
            aOrbiterK = RotL64((aOrbiterK * 707861617246345083U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 58U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 26U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15829U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 15481U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 15988U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10967U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12063U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 11U)) + 3561491146322798260U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 43U)) + 7075025056181885339U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 9230910887904171613U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 13U)) + 4119781172609908917U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 26U)) + 17155609083870983149U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 21U)) + 2423018561430181695U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 12957280305617615744U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 51U)) + 2461704174772065813U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 7907123257849391997U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 19U)) + 7257868138318960007U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 38U)) + RotL64(aCarry, 19U)) + 16425903703085702285U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2990822664594079467U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5654819006718953817U;
            aOrbiterJ = RotL64((aOrbiterJ * 4465096036756887801U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12183676471235678779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15026286960542123922U;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12169080607071830522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2906296852254787499U;
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3029858695410344584U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14406410317495954566U;
            aOrbiterG = RotL64((aOrbiterG * 9663780721657983421U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11048818178401163861U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13622063920319445043U;
            aOrbiterK = RotL64((aOrbiterK * 2516025554421589857U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2642646089141233277U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12761571777929273548U;
            aOrbiterE = RotL64((aOrbiterE * 5518252696078700127U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7753802695131502382U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8510425459525030222U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12412361423636026483U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13522645164493316722U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1437430302489702713U;
            aOrbiterB = RotL64((aOrbiterB * 14019316635365783545U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14745189473423751499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16968328257002103715U;
            aOrbiterA = RotL64((aOrbiterA * 17915588590593471981U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5001838243344386314U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13506188720092630563U;
            aOrbiterC = RotL64((aOrbiterC * 7010027510838271877U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16902624500530747723U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3561491146322798260U;
            aOrbiterH = RotL64((aOrbiterH * 95761172090277669U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterA, 24U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 6U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19040U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneA[((aIndex + 19174U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 16429U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18235U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16967U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aPrevious, 19U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 50U)) + 18180797995100240808U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 6585906608223552885U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 57U)) + 14088708930575939855U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 53U)) + 468974153311516044U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 46U)) + 12481951025619894110U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 17227987923860711763U;
            aOrbiterH = (aWandererA + RotL64(aCross, 29U)) + 4373962756657477139U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 2077576476565420951U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 5U)) + 17435011300234663764U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 35U)) + 4118039398293246896U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 41U)) + 13724716599855216683U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12391461204689596339U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9900605191533799627U;
            aOrbiterF = RotL64((aOrbiterF * 13553565332531046301U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 972946858824366125U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17247681919694541215U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2974639094630445643U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15442851427306771601U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7303586227288294037U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12650358753454105119U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1483710933373510492U;
            aOrbiterB = RotL64((aOrbiterB * 6531763256577221891U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18065810162229740788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11311677121338794007U;
            aOrbiterE = RotL64((aOrbiterE * 15116367961682119467U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2355285311890287611U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1287783821903407734U;
            aOrbiterG = RotL64((aOrbiterG * 8054011680932255985U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9282654686791135654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15488608017745542551U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7858866274035085123U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13296835576073421802U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7127700236018338741U;
            aOrbiterD = RotL64((aOrbiterD * 11246173563106014149U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1365928843264598789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7777790578813003657U;
            aOrbiterA = RotL64((aOrbiterA * 10121688100505628161U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2104270617375082523U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13363764449819651164U;
            aOrbiterC = RotL64((aOrbiterC * 2685452132715528975U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2008038686059197988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18180797995100240808U;
            aOrbiterH = RotL64((aOrbiterH * 8978998151475372047U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterK, 38U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 60U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 44U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22038U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneB[((aIndex + 24341U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24140U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25024U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25072U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 11U)) + 10812151398716051703U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 18202551453336003710U;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 9434410809101973752U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 12955829998028534045U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 51U)) + 12271740641929640181U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 18U)) + 14009351527014534752U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 41U)) + 4316296955679133450U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 5U)) + 16473324966997442872U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 29U)) + 15735123324965019802U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 57U)) + 17656375090484080236U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 44U)) + RotL64(aCarry, 47U)) + 16066325053456055298U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12908968778503516903U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12761433987676836197U;
            aOrbiterB = RotL64((aOrbiterB * 1023329467480907925U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12737513138040664509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14535795767570998392U;
            aOrbiterH = RotL64((aOrbiterH * 15560519667062222269U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14370908061811284364U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7001358781208669795U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11641248025734015835U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7298578161120090849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10498302152357484629U;
            aOrbiterK = RotL64((aOrbiterK * 13144110412179037175U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11447343228638006767U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 18284143620422655675U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 572862190073605651U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5918253208127360199U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3910541329178205943U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4550654545328228103U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10357053096941367910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5610891501128498748U;
            aOrbiterA = RotL64((aOrbiterA * 8676370811772047449U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9049881176058575811U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6307599924966452216U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5551444450572055895U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17109966783467892046U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11563095828344462249U;
            aOrbiterE = RotL64((aOrbiterE * 15463753739272001875U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3739147427725509014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5324449517615050698U;
            aOrbiterC = RotL64((aOrbiterC * 5926079615575226853U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5706251076252597592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10812151398716051703U;
            aOrbiterJ = RotL64((aOrbiterJ * 5666491216813197045U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 40U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 44U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 42U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30081U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 32342U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 28175U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28852U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 29290U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 22U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 57U)) + 15188686795415908074U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 44U)) + 17310049041983079779U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 21U)) + 8246925977992441471U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 27U)) + 8644260919918112781U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 5U)) + 13401663736874819483U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 7940358935238314973U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 23U)) + 13278990328548007839U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 29U)) + 11346868298353840706U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 2374077904806833579U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 5U)) + 6978903378645019166U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 13U)) + 11951633297870965212U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17398460995357409673U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1215437945597836770U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9322970054123481621U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1878751468043972239U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5343002808239712390U;
            aOrbiterK = RotL64((aOrbiterK * 11878640995447558811U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9884918450053276861U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15894599082080422550U;
            aOrbiterJ = RotL64((aOrbiterJ * 8359936745539546131U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13917339232771145459U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 18101134009493720683U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15835859435306756387U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3830086372356903769U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15894394599564584010U;
            aOrbiterF = RotL64((aOrbiterF * 9513921913446609263U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5127590955274245812U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9410946933309720054U;
            aOrbiterI = RotL64((aOrbiterI * 14507476989423060561U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15544384157294987085U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 998801294460434123U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5946968142746472745U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16442095194965452163U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14294936349037516932U;
            aOrbiterB = RotL64((aOrbiterB * 14655345374740882581U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16680659892463349201U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10921918150041635666U;
            aOrbiterG = RotL64((aOrbiterG * 2908474941036821745U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15350264522133299871U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16413848767507968239U;
            aOrbiterC = RotL64((aOrbiterC * 10226942289998651355U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11963105565077056299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15188686795415908074U;
            aOrbiterE = RotL64((aOrbiterE * 13002484121826831091U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterI, 51U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterB, 60U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 36U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_PingPong_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterG = 0;
    std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7272U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 8015U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 6752U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7597U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5382U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 7219U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 57U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 29U)) + 12615321415808640429U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 47U)) + 15712784676459931207U) + aPhaseGOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 11013335427004930046U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 8298733856304768806U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 11U)) + 6207732959150824216U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9769864876127544038U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10782181918651152563U;
            aOrbiterD = RotL64((aOrbiterD * 16814396040248716483U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5790454015845620939U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15606578025386733803U;
            aOrbiterJ = RotL64((aOrbiterJ * 7079287329365566355U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5522352539991175304U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5993355818572869649U;
            aOrbiterH = RotL64((aOrbiterH * 15221467311057431139U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10864534396947622047U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12090053126235913528U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7250801471645972261U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14191181677234981396U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2258570108233924592U;
            aOrbiterK = RotL64((aOrbiterK * 8307541155393855209U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterJ, 58U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11726U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 10387U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 11734U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15272U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9982U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15939U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 38U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 14008824488073394623U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 22U)) + 13317978415866411468U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 35U)) + 13209180141897453900U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 11870521586865233578U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 8052156380448047385U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12158131176743680605U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14674467487607719347U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18372548574199176503U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18055496790566231147U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3838105585041578784U;
            aOrbiterI = RotL64((aOrbiterI * 1075709247574580091U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2839568255183054418U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11933612922864258179U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7571964469321160347U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6289849094151630580U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2640344350528492271U;
            aOrbiterD = RotL64((aOrbiterD * 16197726750829369365U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16306175266267657791U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3339898380394883600U;
            aOrbiterB = RotL64((aOrbiterB * 7105436590182982373U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterB, 40U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20108U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 21934U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22936U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22266U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22735U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21969U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 3U)) + 5960680319644404115U) + aPhaseGOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 16050752633567034185U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 8447503223226854741U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 11U)) + 14176813813397917591U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 50U)) + RotL64(aCarry, 57U)) + 10534915376130006644U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6866224454375302514U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16506374165041008396U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1326855300197233833U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7167814023968794098U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13870852197416596664U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17015971222069856463U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 18064038854848993105U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9869630811507771691U;
            aOrbiterD = RotL64((aOrbiterD * 13723164383800461387U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 863613100452759380U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16597969741225436529U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2680793528887208903U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6575347108051310653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17062262265485019063U;
            aOrbiterJ = RotL64((aOrbiterJ * 7601045488473620019U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 36U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aPhaseGWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 52U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28930U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 28038U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31728U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29784U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29455U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26087U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 42U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 13U)) + 7825479804710770560U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 5298124167101358123U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 42U)) + RotL64(aCarry, 13U)) + 17774541024369233726U;
            aOrbiterD = (aWandererE + RotL64(aCross, 3U)) + 7679371833537454082U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 5385914900748772224U) + aPhaseGOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3879781930908486531U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 659110346638873236U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17439162088869824407U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10749021728538539749U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3631252455767429457U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8552825360915119613U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2271978810960685021U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5963558780692551176U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4772055335210781149U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 974909966119198104U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9296998242911152296U;
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2245318466901521959U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13391076374843288568U;
            aOrbiterK = RotL64((aOrbiterK * 18094558036982107419U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_PingPong_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 340U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 2738U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6198U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7013U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6169U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 1650U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 18U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 6916817163240024692U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 11U)) + 14554930751292077817U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 43U)) + 1098305064484336101U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 12192821172420471527U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 3U)) + 2435134991707318845U) + aPhaseHOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1896745368738512624U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1114996424222923873U;
            aOrbiterK = RotL64((aOrbiterK * 6248754732325773087U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9839135798371512656U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8037967239603177043U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7848951103759663025U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15185468738487237432U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4912098316394854543U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3072785550384399929U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13142688607850380888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4507379759608945839U;
            aOrbiterB = RotL64((aOrbiterB * 2989332387754215967U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7299006009652289342U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5390655277207053627U;
            aOrbiterH = RotL64((aOrbiterH * 10973744708856143715U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterD, 48U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13102U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 9482U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 9501U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9751U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11088U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11479U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 30U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 23U)) + 5295352595333316211U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 2341795367042042605U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 47U)) + 10122175780504033663U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 10084612804696198554U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 16470424309851045971U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 656016130975227994U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15313268829659834317U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3553315008401417123U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3795220914993923394U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14044442220988813825U;
            aOrbiterB = RotL64((aOrbiterB * 3270650852546606835U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3804224626734584802U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7980006306010255693U;
            aOrbiterE = RotL64((aOrbiterE * 13958505239726088561U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13746830564584711549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11852212099729274845U;
            aOrbiterD = RotL64((aOrbiterD * 2164880979318247855U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9083223471018084847U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13706723820703853346U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11361854103656219887U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 38U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18880U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 21098U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 19784U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17138U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21414U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 22637U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 14U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 16200278595895089008U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 1029614154810465897U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 58U)) + 7129562468705441295U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 23U)) + 14388903902433951274U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 1013568949315967455U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3128823373497815651U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14525694606889470589U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12053226114431679195U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14443983602196782887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12244220415328641190U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15052949098014803181U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10477159225338766614U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2842870123078131566U;
            aOrbiterJ = RotL64((aOrbiterJ * 11522265477555954071U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8621138818955849917U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5038396344400303181U;
            aOrbiterF = RotL64((aOrbiterF * 14636756322207385447U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2768613802894372496U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2027754864051410015U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 42U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31239U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 30469U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32690U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30175U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26681U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27073U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 47U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 2101601659597850213U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 35U)) + 2759794072560720121U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 6U)) + RotL64(aCarry, 39U)) + 9443562552411269339U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 10801360546699857975U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 27U)) + 8020716394829332019U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1021894212367773801U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13346855534622490176U;
            aOrbiterD = RotL64((aOrbiterD * 12668950387932320985U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16359309548462953836U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12642446944680783519U;
            aOrbiterC = RotL64((aOrbiterC * 12197935153255283321U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8197424982767553380U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14346334610901859094U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16982899923227935679U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14171304260534233539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 334531601308283605U;
            aOrbiterK = RotL64((aOrbiterK * 5012968232749075075U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10707856298471572695U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18364775750091914766U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15735143943129143265U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 48U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 5U);
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
