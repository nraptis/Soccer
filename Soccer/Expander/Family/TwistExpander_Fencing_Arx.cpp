#include "TwistExpander_Fencing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Fencing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9BF7A20C8E5B7B37ULL + 0xDBFD65180C516E7AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEEE541D734A399B3ULL + 0xBE97A129C7411FB9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF330F1E7518482CBULL + 0xECD9E3406B59A367ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB096295D8B09C581ULL + 0xE090CB8F21E86D4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBFA04461450F141FULL + 0x93FA8FFF001A0F7AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBE3D50E00592E807ULL + 0xEE9CAD35328FBFCBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9F4E5AAA031E761DULL + 0x96A32E2457B8817BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC6F2422700E73A97ULL + 0xDB5BBD81A82FFA62ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA94BA1913B69D025ULL + 0xB5E4693D17E8FA9BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFF0A65D3F4DFFBC5ULL + 0xE11F364F76568839ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC90D9AE3E1BA094DULL + 0x9774DE99D786AC8AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE43654C845374449ULL + 0xB4C39F2D21A53DACULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x96354E56D9406FB3ULL + 0xF097C2FF03810258ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x885620F53F2A533FULL + 0xD10DFB7ECCDB830FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB0FFFE6C668FB20BULL + 0xF8FBF61BE4A30502ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDA23B4696C0DF9B9ULL + 0xAE168CB3D8D17B02ULL);
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
            aIngress = RotL64(mSource[((aIndex + 2356U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 1533U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1739U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2195U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererG + RotL64(aPrevious, 37U)) + 5906639480605353429U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 60U)) + 5293518570213287605U) + aNonceWordK;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 15383185501428521377U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 15364072512743978902U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 23U)) + 4525473357144014271U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 50U)) + 10400911938125603074U) + aNonceWordB;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 16417506293824627550U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + 2419329331753341815U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 5U)) + 14929222427923332069U) + aNonceWordM;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 27U)) + 16771573504983922586U) + aNonceWordG;
            aOrbiterB = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 1863466450051787622U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12895350137096692415U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3700979086526298327U;
            aOrbiterA = RotL64((aOrbiterA * 10279730254867618193U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1977099106211282426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6144698304096915742U;
            aOrbiterG = RotL64((aOrbiterG * 5039822990560519609U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3858895556659724975U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1283646340363435327U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 11622421841377018069U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6240532051889108891U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 757364889381634634U;
            aOrbiterH = RotL64((aOrbiterH * 943852137901972945U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5272945693977418174U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6850528198786172283U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1966383079897679953U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14431587733859573714U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 16124590257870999553U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7755796211433191143U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14912695018110241411U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11098623474413346520U;
            aOrbiterD = RotL64((aOrbiterD * 15167688959990872051U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3484847683376368686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2295388097292719800U;
            aOrbiterF = RotL64((aOrbiterF * 1240808318176106909U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 923199510066894111U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 311875852510926196U;
            aOrbiterC = RotL64((aOrbiterC * 9797881750305289335U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3543141837224843684U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12889943043568922084U;
            aOrbiterE = RotL64((aOrbiterE * 8682278766727990427U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6105656539077757510U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 5906639480605353429U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 9555916235293954383U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 36U));
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 53U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 60U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 8087U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 9025U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5479U)) & S_BLOCK1], 52U) ^ RotL64(pSnow[((aIndex + 7464U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 18087125778766689269U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 21U)) + 13710545066503235196U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 43U)) + 1701939704736254645U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 30U)) + 8064093611384019909U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 23U)) + 16623332751533885431U) + aNonceWordD;
            aOrbiterF = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 15590129153794910109U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 7413312683079107383U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 47U)) + 4186064478651458810U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 35U)) + 5501191643940735954U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 4U)) + 11064645242200570835U) + aNonceWordC;
            aOrbiterD = (aWandererI + RotL64(aIngress, 19U)) + 13825922087298055833U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5944980709887369970U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8181136916070569646U;
            aOrbiterH = RotL64((aOrbiterH * 395183021205661827U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15442336949157292482U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 11580554435240641337U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 6654637892858767739U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11240018128174598322U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2027565596050777471U;
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16425887196883725233U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16828683527588834095U;
            aOrbiterA = RotL64((aOrbiterA * 17746289103235902485U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9923829146479008804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6669171007279929454U;
            aOrbiterG = RotL64((aOrbiterG * 681823450939955099U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3902430046523165149U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6739998149289590041U;
            aOrbiterD = RotL64((aOrbiterD * 2675037435528416821U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16014401255534234075U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14741857638680634564U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8723611021403369393U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5064807861673260054U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 968747317273200299U;
            aOrbiterC = RotL64((aOrbiterC * 14122304002722582329U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5282686212362051427U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6902253563196129760U;
            aOrbiterJ = RotL64((aOrbiterJ * 7682808024658992049U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4995580401402368332U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14949762584793646470U;
            aOrbiterB = RotL64((aOrbiterB * 3539183342072953803U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2378815735788107402U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18087125778766689269U;
            aOrbiterK = RotL64((aOrbiterK * 16799380528404446281U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterG, 10U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterD, 23U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 36U));
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12789U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 14284U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14870U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14948U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 28U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 26U)) + RotL64(aCarry, 43U)) + 15383045568644941552U;
            aOrbiterG = ((((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 17452811657750910067U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererI + RotL64(aCross, 37U)) + 15660117718455155603U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 11U)) + 10396441207743665753U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 53U)) + 3708971058200841442U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 21U)) + 7000673057768598750U) + aNonceWordL;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 5U)) + 9886354469011131596U;
            aOrbiterI = (aWandererF + RotL64(aCross, 29U)) + 16018065329058043467U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 5024756166109352320U) + aNonceWordI;
            aOrbiterC = ((aWandererE + RotL64(aCross, 57U)) + 6587818720728886652U) + aNonceWordP;
            aOrbiterA = (aWandererA + RotL64(aIngress, 50U)) + 3652672354944162319U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6307315649915348048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16405347331742979258U;
            aOrbiterK = RotL64((aOrbiterK * 7183142442906743699U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5427299664054601957U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4983381733483185898U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14646556236306407673U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10182995521328377487U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8694282877540593550U;
            aOrbiterF = RotL64((aOrbiterF * 14614602561910403893U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4085927978153269932U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6176195962815240877U;
            aOrbiterE = RotL64((aOrbiterE * 16792916528959579875U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6966742100601433005U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9920952446921247521U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1879821050131820933U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11958734477518336014U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2058335903640404380U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6986170159285417789U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 77366119537297816U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12072894199692855000U;
            aOrbiterA = RotL64((aOrbiterA * 9083781120514635987U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11874297832446385377U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13715562531763053196U;
            aOrbiterH = RotL64((aOrbiterH * 12822488258322963187U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13664465415354326653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10365386643010882315U;
            aOrbiterJ = RotL64((aOrbiterJ * 3687934567254955761U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2003863843075564853U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8864134110143237364U;
            aOrbiterC = RotL64((aOrbiterC * 4586162015675320985U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8055736412403126985U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15383045568644941552U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 5175405553995854715U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 48U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererA = aWandererA + (((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 46U)) + RotL64(aCarry, 13U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 26U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16723U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19476U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 19775U)) & S_BLOCK1], 20U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 16500U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 18389U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererH + RotL64(aCross, 39U)) + 6469584119078165548U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 37U)) + 14329756366517987910U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 34U)) + 12890831797059772123U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 53U)) + 3164503807500018990U) + aNonceWordM;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 177531431387646836U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 43U)) + 3167421392893561015U) + aNonceWordO;
            aOrbiterH = ((aWandererB + RotL64(aCross, 57U)) + 2813174781844753460U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 3U)) + 10953270419153249857U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 5U)) + 16911518309710356951U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 37U)) + 6616750447844893150U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 10276741398025985982U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6206043608461213208U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12021552904553405793U;
            aOrbiterA = RotL64((aOrbiterA * 10023362889960174909U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15283586234744144846U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5923238786775948571U;
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11044014510971660078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9351141024085076044U;
            aOrbiterG = RotL64((aOrbiterG * 13316079344614432317U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17703395981862992420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10154548848376027087U;
            aOrbiterJ = RotL64((aOrbiterJ * 12324478347590509035U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8836420852291617425U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10193385413543886344U;
            aOrbiterI = RotL64((aOrbiterI * 824935982418585449U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8248580084535685190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3910083671888152974U;
            aOrbiterK = RotL64((aOrbiterK * 17825311776715895927U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12350341628569930642U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 2565977481575002842U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 18233446879833776677U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9271041067874027417U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14289254596554201861U;
            aOrbiterH = RotL64((aOrbiterH * 7985522692852251413U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5981802134118235214U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14047813418129636856U;
            aOrbiterC = RotL64((aOrbiterC * 15961435325216504877U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11808443842149398212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11380858372643695792U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 100198424024622179U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10385375464069162356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6469584119078165548U;
            aOrbiterF = RotL64((aOrbiterF * 5263876933019848989U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22036U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 23908U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25682U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24588U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24209U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24615U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 47U)) + (RotL64(aIngress, 34U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 19U)) + 6361545377408870615U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 5U)) + 2967245486744774933U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 41U)) + 3836634268482850139U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 21U)) + 7691642115360086297U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 3U)) + 16479280384178279281U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 54U)) + 2901468732552539249U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 27U)) + 2600353867755647475U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 5666596904781510956U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 16108791609267427553U) + aNonceWordO;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 8389926875737312112U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 14U)) + 1689501721163024426U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11721701506949917719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3963842745030140473U;
            aOrbiterI = RotL64((aOrbiterI * 6692473494944919373U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8510538243472109368U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18281865214102080387U;
            aOrbiterH = RotL64((aOrbiterH * 1351546966368884609U), 41U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 2259725140963665123U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11652011949557979650U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11260100762113295037U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1116085424226174473U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4725260319270802912U;
            aOrbiterG = RotL64((aOrbiterG * 4697109059565450269U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7348945429843437036U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1249234309180653260U;
            aOrbiterD = RotL64((aOrbiterD * 3136745255820405881U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12463505532573389603U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2304125977906510386U;
            aOrbiterJ = RotL64((aOrbiterJ * 9960816714791454421U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2178037443783425551U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11712110130079307683U;
            aOrbiterK = RotL64((aOrbiterK * 9797864956200779505U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10703510612147312252U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18155460326242413483U;
            aOrbiterA = RotL64((aOrbiterA * 6903953708987478723U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5753486645345036069U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2314216774606770444U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14002639533287566667U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9662599462788305323U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3805101172359199209U;
            aOrbiterC = RotL64((aOrbiterC * 10669315962181581543U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1073926575064224947U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6361545377408870615U;
            aOrbiterF = RotL64((aOrbiterF * 10685650563722188837U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 10U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 50U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererC = aWandererC + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 42U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 29351U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((aIndex + 30089U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30901U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29377U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32001U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 28447U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 26U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 3550722402315312207U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 13U)) + 16724184551669522754U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 981751330116773021U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 46U)) + 7891159229704944868U) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aCross, 3U)) + 13618396711464799841U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 43U)) + 5969291018449003648U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 21U)) + 14595540413313640042U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 37U)) + 3287990436916111762U) + aNonceWordI;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 56U)) + 12534369400200483704U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 2277312067930392274U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 41U)) + 10026320559261334353U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11258082063135659551U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1445958517675746990U;
            aOrbiterA = RotL64((aOrbiterA * 10062265337488757971U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1011298251290970844U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6487834862470043744U;
            aOrbiterK = RotL64((aOrbiterK * 15477913837027179675U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9966279022928268335U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10285993486057704393U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15965714363201157535U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16005362468813966136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 223843444699390781U;
            aOrbiterH = RotL64((aOrbiterH * 665392038954573081U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18178876294968532775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12490136112181806806U;
            aOrbiterI = RotL64((aOrbiterI * 16380841616662993709U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8775696166557913635U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 16464340319444310842U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 18111632334728200721U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6296039992673546227U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7152939277656436037U;
            aOrbiterD = RotL64((aOrbiterD * 15183918431501487319U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14066791413416223271U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5026743227399908016U;
            aOrbiterC = RotL64((aOrbiterC * 5891343232759075675U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12923870516588764609U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2509970166609982397U;
            aOrbiterE = RotL64((aOrbiterE * 10708677957633925007U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15155802288437422950U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15615656627428205711U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 6199439196177598589U), 39U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 17233751123865498186U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3550722402315312207U;
            aOrbiterB = RotL64((aOrbiterB * 2247546626523919155U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterG, 12U)) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 12U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Fencing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDC501D2A3E7996C7ULL + 0xF8C6E180D7611F7DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x88FFE954E72F643DULL + 0x84A1F3B2D664E589ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x933ACA4E18F313AFULL + 0xDED918CBB014BD1DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE506A3A439F4845DULL + 0xD2DFB506EF8B939BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD4ABC8CDFF80C51DULL + 0xFF1741F40ADBFC9EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB1B35EBAB1D36CABULL + 0xDEDB6F9DCAE26775ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFDFC20C48B240767ULL + 0xE15190929FD98C55ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA99A814415325C89ULL + 0x8FED874602AAC65EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDAB438885584AEA5ULL + 0xA2958FC68E6E983DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA25CF5DB62E280AFULL + 0xD357FED821CF9BBCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF669CFD6952C39DFULL + 0xF0EF19705AE64AF7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC33C1D1217BD7C4BULL + 0x80878226128C8E66ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBC2B8FB7F7EFAF8BULL + 0xEFBA727962A2D982ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBF502E56FA91BA59ULL + 0xB3290A30990BD3A8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xADD33A6E1B4B8FB9ULL + 0xEA74E0233C7DC465ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAA2C5B4F2A7ED52FULL + 0xFB21A9FCD3768BBFULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4605U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneB[((aIndex + 1309U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5335U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneD[((aIndex + 3730U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 60U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 18U)) + 11450949896247900941U;
            aOrbiterE = (aWandererK + RotL64(aCross, 37U)) + 3905542253538116335U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 9529740545977785305U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 47U)) + 1856876631533143492U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 23U)) + 84253466320181686U) + aNonceWordD;
            aOrbiterK = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 12577480918745432444U) + aNonceWordC;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 60U)) + 5625703170397704029U) + aNonceWordJ;
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 694608607323629282U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 3993981243536262204U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4119215953484892051U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8785040118556157146U;
            aOrbiterB = RotL64((aOrbiterB * 17113521266125471625U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16234403619456882890U) + aNonceWordP;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 10398727475672860610U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5086871400049644715U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18327987141759096769U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2645964788056875452U;
            aOrbiterH = RotL64((aOrbiterH * 8778681366114628045U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2859452497983106129U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7196557924940881076U;
            aOrbiterA = RotL64((aOrbiterA * 14415389907490256711U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 930127943984174668U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15673596916054795749U;
            aOrbiterE = RotL64((aOrbiterE * 7505660488733199479U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16673140529110941163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2258448294877833760U;
            aOrbiterG = RotL64((aOrbiterG * 1821550319748977445U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6870209259643931219U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12749790107942194104U;
            aOrbiterJ = RotL64((aOrbiterJ * 4871407285968611725U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17131374134617173866U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6426448390733751612U;
            aOrbiterF = RotL64((aOrbiterF * 12490559588384058417U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15592826434339731146U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14182944418026376183U;
            aOrbiterD = RotL64((aOrbiterD * 7218860482893476233U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 10U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 44U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterG, 24U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 22U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12836U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneB[((aIndex + 12912U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11698U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10017U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14311U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 50U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 898812731947995389U) + aNonceWordH;
            aOrbiterA = (aWandererD + RotL64(aCross, 39U)) + 8677347622525527167U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 770321564027567654U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 23U)) + 11020474858081526395U;
            aOrbiterB = ((((aWandererK + RotL64(aCross, 18U)) + RotL64(aCarry, 29U)) + 17289793580414993470U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 35U)) + 10111912559295118444U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 43U)) + 8083622125544542011U;
            aOrbiterE = ((((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 7149858558922988240U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererC + RotL64(aCross, 3U)) + 5919683821379905699U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6860902846079238714U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15083517836867542075U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14852868368708376381U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9860233289028878323U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 13418143547952204667U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 772406119079116272U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7971141501337627589U;
            aOrbiterJ = RotL64((aOrbiterJ * 10168120622976358617U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8478568022896691911U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 4826627523578901467U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17199331557841535430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7515957656979776361U;
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17138249294921502391U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16236812863923234668U;
            aOrbiterH = RotL64((aOrbiterH * 2925542836624164807U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16941524155859123682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11240343728857342866U;
            aOrbiterK = RotL64((aOrbiterK * 7281012444214294659U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15163914964139858328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6673576554415729652U;
            aOrbiterE = RotL64((aOrbiterE * 1558880328574736975U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5399050402101642989U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11806006719060024615U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15782156615926092159U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterK, 36U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 26U) + aOrbiterH) + RotL64(aOrbiterE, 46U)) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22670U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 19980U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18966U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21522U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22648U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21507U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 52U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererI + RotL64(aIngress, 60U)) + 785861751704720606U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 15968088718435606299U) + aNonceWordO;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 11U)) + 1393976526590347151U;
            aOrbiterI = (aWandererE + RotL64(aCross, 21U)) + 17240750947292745884U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 4921576136163183137U) + aNonceWordE;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 5U)) + 3334047873553153032U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 34U)) + 15086509978458408698U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 892391205397581998U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 53U)) + 2965686403183767521U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14632215393655706170U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15740589515342377322U;
            aOrbiterD = RotL64((aOrbiterD * 15677716942904794913U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11131164813943086445U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6988080581278900960U;
            aOrbiterC = RotL64((aOrbiterC * 6412189142344044255U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16021254613117657178U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6183615599897921154U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9976411093264211033U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12533992547026652747U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3104325358982904219U;
            aOrbiterF = RotL64((aOrbiterF * 14977348108778147265U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3878525937957474644U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2120435259884368445U;
            aOrbiterG = RotL64((aOrbiterG * 15964718652193073177U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14928658302694194856U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9121310461310309348U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3715693239100476493U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7336577492932262490U;
            aOrbiterA = RotL64((aOrbiterA * 11074754160002665253U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2312452827448455675U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4322756069651934618U;
            aOrbiterJ = RotL64((aOrbiterJ * 6908893297397073539U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4962079617577705818U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5072727464750706525U;
            aOrbiterB = RotL64((aOrbiterB * 4947670001221089155U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 12U)) + aOrbiterC) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterD, 24U));
            aWandererF = aWandererF + (((RotL64(aScatter, 44U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27122U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((aIndex + 28524U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 27416U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25496U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25756U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 32542U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 6318740973868639425U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 5487840061430920881U) + aNonceWordL;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 47U)) + 10258706763248072672U) + aNonceWordK;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 18U)) + 18356875269730338208U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 23U)) + 12883160282903147010U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 53U)) + 1010140474942697730U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 17733939421700898293U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 35U)) + 13693055887924981201U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 6U)) + 14574732452793385269U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10832873941223609012U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8212600587135328040U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5334613996794796145U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5312744319781971178U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3693249147883790810U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18365859989736602556U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 3348463719324104997U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10645056678337549771U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1175668356822251045U;
            aOrbiterD = RotL64((aOrbiterD * 6579675292775345579U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13556844570541823717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4790355739411849736U;
            aOrbiterB = RotL64((aOrbiterB * 4083544011788850307U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14905575502272644116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17047244574558476634U;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10161614295718414869U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13413914082651612468U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 16224039093981079491U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6072693130156927774U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4333656233793103787U;
            aOrbiterK = RotL64((aOrbiterK * 9374745547133955709U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17209776289202130250U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11752001118070361543U;
            aOrbiterG = RotL64((aOrbiterG * 4416523594812872339U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 10U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 58U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterH, 37U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 6U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Fencing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEEF649EA67DA079DULL + 0xB722956111EC716DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF232186F4F7273B5ULL + 0xD58241BF989EA16CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB50DB3C536AD151FULL + 0xD8C659FC84DE9B62ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x99AE66D7BA130BDBULL + 0xE9068757BF844BC6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB32DBBDDA85A13FDULL + 0x81E84811D894F385ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD8F21E762D33BF65ULL + 0xF834BEBD9529B5D4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA4429759E1FDD105ULL + 0xB8C1A003F6B98439ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA923E1966D501161ULL + 0xD9AE5408BBB4E94FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA9A547727FDB806DULL + 0xB690DE796DA48F56ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB6124B900AA2A82BULL + 0xFBE8D1FBD0685751ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAECFF7F3968D249BULL + 0xE42B324609776FF2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x98484E63AD1105E9ULL + 0xD654A747F971DCACULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD99946725EC38091ULL + 0x976EC79A6307A805ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF444724B1B9F5253ULL + 0xDE784AEEA523F199ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCFD1FCC2FD39E5BDULL + 0x8D60DC34A3742AB4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x87424B1D8004BE91ULL + 0xE897E8043CAB54F1ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneB, aWorkLaneC, aFireLaneA
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2537U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 4555U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 3238U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 662U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 4120U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 2168513956284366370U) + aNonceWordJ;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 10290361969974613111U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 21U)) + 15673836275828498050U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 16600540024145812236U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 46U)) + 9428052101528111892U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12763657928312763377U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10751286982008662485U;
            aOrbiterK = RotL64((aOrbiterK * 6169084301655877217U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1708230173038057979U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4011389705422783816U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11692237130784795961U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11704428328093077714U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2055336619674699284U;
            aOrbiterD = RotL64((aOrbiterD * 6374289210096410907U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1870865272102705804U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3574214263751923179U;
            aOrbiterJ = RotL64((aOrbiterJ * 13132083406834413563U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 984611970726966186U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15207945449947643672U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 9539470161576639981U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererE = aWandererE + (((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 42U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15308U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 8411U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12030U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15919U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8816U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13283U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 38U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 16124889768301047791U) + aNonceWordF;
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 11912338587186717280U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 53U)) + 8594012868813114354U) + aNonceWordG;
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 18281043566156682815U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 51U)) + 16853106130200942302U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2611212958619673086U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 18039472325066855180U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10213999643376367785U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 14495785571345122046U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4556063793412832418U;
            aOrbiterD = RotL64((aOrbiterD * 13166927543135467627U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14896419970271244358U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 880028529183500036U;
            aOrbiterF = RotL64((aOrbiterF * 14228281807461251361U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2379557167489415783U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 11854373946064529806U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 150755294320438887U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1487252775956449964U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12777924204511625545U;
            aOrbiterG = RotL64((aOrbiterG * 1366019527386994789U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 6U)) + aOrbiterD) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16419U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 21647U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20285U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17921U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19539U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22333U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 5U)) + 14686411261024919129U) + aNonceWordB;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 7514582233957632005U) + aNonceWordF;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 29U)) + 6520710480103365552U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 1983621978676188036U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 9003524602590749672U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6428568234045228995U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8656552687136446989U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 16297456077021607301U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16916248288415922490U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9740237548002535784U;
            aOrbiterB = RotL64((aOrbiterB * 7970729853948983849U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 907561000814618339U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4751108900841197631U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4545395964730641957U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 167774899400732287U) + aNonceWordA;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 11907484918310854962U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 7213139491146402985U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14910318613649863924U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14882888155751455276U;
            aOrbiterI = RotL64((aOrbiterI * 11394136445442060201U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30171U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 24893U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27164U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24595U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32102U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30444U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 30678U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 53U)) + 18180797995100240808U) + aNonceWordF;
            aOrbiterC = ((((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 6585906608223552885U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 14088708930575939855U;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 44U)) + RotL64(aCarry, 23U)) + 468974153311516044U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 3U)) + 12481951025619894110U) + aNonceWordH;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17227987923860711763U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4373962756657477139U;
            aOrbiterE = RotL64((aOrbiterE * 6069068316234356267U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2077576476565420951U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17435011300234663764U;
            aOrbiterK = RotL64((aOrbiterK * 8910133867294004711U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4118039398293246896U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13724716599855216683U;
            aOrbiterB = RotL64((aOrbiterB * 17556333902751079677U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12391461204689596339U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 9900605191533799627U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 13553565332531046301U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 972946858824366125U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17247681919694541215U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 2974639094630445643U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 46U) + RotL64(aOrbiterH, 34U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + aNonceWordG);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 19U)) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Fencing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD1FC9026B9311BFBULL + 0xBBEAB497B34E7020ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDAC519C26E9E0B99ULL + 0xE3F6DF3829D2BDCBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x87D36EAF757EF5D9ULL + 0x8E2CA706033B0426ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC8096489CCE94D81ULL + 0x8C0259D82B07D6F0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8E874147EB0C6547ULL + 0x8341724804297577ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCE108D38877F26D5ULL + 0xC2D6D89CE6CB46C6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA5AB40DE06EACB5BULL + 0xB9D71573B0778684ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA58B9661E459518BULL + 0xDE190C44C5114EA4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDF618D7B8CA65123ULL + 0xAEBC8C97329A3A83ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA7EDBC42273C7C4BULL + 0xC18542CDC5151482ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x96F4A93B3D1A9E93ULL + 0xB05B7CE17B2B9084ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD55EAEFA36532A2BULL + 0xBA92C1D6CF78694EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF1931E63EB6469BFULL + 0xA89C7B9CFBA6BFEFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBF8C394FC97EDE13ULL + 0xB6203F2161AB9838ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x94EF98EED498065BULL + 0xF35D9C7B2EB548BFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAFC54BD6CA0C71F1ULL + 0xB9169B910EDBDE89ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aOperationLaneD, aOperationLaneC, aWorkLaneB, aFireLaneD, aFireLaneB, aWorkLaneC, aFireLaneC, aOperationLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1975U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 5086U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5822U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 244U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6635U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 5891U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 20U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 7632760812370906911U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 21U)) + 6007174525479723089U) + aNonceWordM;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 51U)) + 3362829642521821048U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 18009548556107978286U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 41U)) + 17880909432272697327U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 15961567935420752568U) + aNonceWordC;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 5U)) + 10136559064656837921U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17622019364405410277U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6927494824421416306U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2686290883767829973U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7125170407794874847U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12342273503071032250U;
            aOrbiterD = RotL64((aOrbiterD * 867417849555857179U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14997696377476124836U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14874498694181230698U;
            aOrbiterH = RotL64((aOrbiterH * 4026127545746010937U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 2549397729130885686U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4217995818662767955U;
            aOrbiterC = RotL64((aOrbiterC * 5525525344485251063U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4706089044415442525U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17983900172670031015U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 541552737180932879U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1904937798143929988U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10620877287033139483U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 16711012562024287213U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15681091173163181525U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2655543246639000084U;
            aOrbiterE = RotL64((aOrbiterE * 16686375598149755947U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 12U)) + aOrbiterC) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13249U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 10249U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12243U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8713U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10755U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 11804U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererE + RotL64(aCross, 14U)) + 9914837590440975587U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 21U)) + 6706125076401958051U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 16570817772679258409U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 6843705658115186948U) + aNonceWordM;
            aOrbiterC = (aWandererG + RotL64(aCross, 43U)) + 16099930446791572351U;
            aOrbiterB = ((((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 5420550009556030459U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 3U)) + 5729549069420177477U) + aNonceWordO;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15590601126188675834U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13044027390998620029U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16845199115313444123U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11068338135659636772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6584988841809544332U;
            aOrbiterE = RotL64((aOrbiterE * 1683336180438945439U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8516813219883915404U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterG = RotL64((aOrbiterG * 15559481057047148785U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 201691689889605304U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15512161798401184003U;
            aOrbiterC = RotL64((aOrbiterC * 11473219183982564709U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3883760518944464145U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13861805129175491145U;
            aOrbiterB = RotL64((aOrbiterB * 17194438894492581181U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12019138626550801486U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2643807255422544248U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4127143302485631794U;
            aOrbiterK = RotL64((aOrbiterK * 5441038881111578487U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 52U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterB, 12U)) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23465U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 23847U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 23676U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22053U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17088U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17974U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 6243113109470883144U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 3891552123999605832U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 21U)) + 8758797898587019128U) + aNonceWordI;
            aOrbiterB = (aWandererC + RotL64(aIngress, 29U)) + 1005891374086408851U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 51U)) + 3713426782180050764U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 18358143862391573534U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 44U)) + 17504394029693712404U) + aNonceWordM;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5312729289027417014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2560873623431186029U;
            aOrbiterJ = RotL64((aOrbiterJ * 16843728573219210173U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16309322822806704211U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10195513918020652600U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14569219741824123715U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2552116263258744287U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7732784879810980089U;
            aOrbiterI = RotL64((aOrbiterI * 15041929399477790999U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16499127570665381507U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10890036715535519036U;
            aOrbiterD = RotL64((aOrbiterD * 9065115450010475187U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16288944603478791554U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 14542766121469312846U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 8435383464425875209U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5973595239494084696U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1820492719977197097U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16164917159141304405U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10489529555776381736U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6392552206958240484U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 11761477994533503307U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 10U));
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 38U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + aNonceWordA) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 28U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24834U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 28042U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24746U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24761U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31717U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24585U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 51U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererD + RotL64(aCross, 57U)) + 7960325128608297381U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aWandererB + RotL64(aIngress, 5U)) + 12773836012104052042U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 3173972621347773016U;
            aOrbiterJ = ((((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 3708401356314308171U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 950774285720019449U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 35U)) + 4170092315705438265U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 11U)) + 17000449130864980747U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8793910540062893860U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 520277969543516469U;
            aOrbiterK = RotL64((aOrbiterK * 4150613128885828229U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12762214857389827271U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2932451184340207695U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7513337346940091655U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11062179998786293839U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7919119215271524178U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1774988449597115155U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1815062051307896589U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15260373951371654483U;
            aOrbiterD = RotL64((aOrbiterD * 2208604434669491625U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12867546628945676853U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7772820973895846946U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 7581704643538761985U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14213957831821966834U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16561105721170419454U;
            aOrbiterF = RotL64((aOrbiterF * 2540533987337175367U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 26U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Fencing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE609F9ACF5F641B3ULL + 0xABA8B96C2E79879CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEFCF41F2F955E21DULL + 0xA1F927EEEA9C256CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD2B13721525F22A5ULL + 0x8079928273DECD9EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE4FBE784B96F4D11ULL + 0xF2E9BF703D25C089ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDAA739B2060FCEF9ULL + 0xF35A451C01C31980ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCBEAAAD2DCA492D9ULL + 0xE9F7E3398795687AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8901510DA156DCB1ULL + 0x81D04A4DA2FA1A63ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xACCF89F8E1577BF1ULL + 0xFFF4B683492DD217ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9658961484BF440BULL + 0xB31540E052574987ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8188186BF00BD29DULL + 0xF18784CC7A311E98ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD7506C7848DA545BULL + 0xA33CCD64CE9A9B1FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA7378AD740DF0C25ULL + 0x957020636C8ACE66ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE164D970B57B4F21ULL + 0xC4A506EA50BC615EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x869129BF9C5787B7ULL + 0x8014D670D46AD20EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCD89CFE3D3A473F5ULL + 0xDAE5D8281B123A3CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD83193279CF913FFULL + 0xF6F480894FF906C1ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aFireLaneA, aOperationLaneA, aExpandLaneB, aFireLaneC, aFireLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5988U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 1519U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 6702U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6469U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2298U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 7075U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 16451272412693907816U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 47U)) + 10099485419723255462U) + aNonceWordE;
            aOrbiterK = ((aWandererI + RotL64(aCross, 56U)) + 17668900099534923192U) + aNonceWordI;
            aOrbiterG = (aWandererE + RotL64(aScatter, 23U)) + 5497093724143181753U;
            aOrbiterF = ((((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 10354044773550071706U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 12728258851198019099U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 41U)) + 4144050505314242618U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14133805325480076530U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 308863673210602899U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2672613556981540433U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11741180130160569753U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12926863156769180448U;
            aOrbiterF = RotL64((aOrbiterF * 9726030996091054939U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 211920854786494259U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13234608842479411078U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2556747209733759467U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9164711974854618892U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6667377062281954219U;
            aOrbiterC = RotL64((aOrbiterC * 2603737166987437649U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4559040002406721850U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 1749875480850675109U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 15822640067349481089U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9555365165561936366U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 18289733999504213574U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8727162691639622461U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 291406782452963706U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 8413500075082350243U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + (((((RotL64(aCross, 20U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordK);
            aWandererF = aWandererF + (((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 60U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16224U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 15486U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 10569U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13486U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13930U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13501U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 58U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 18U)) + 16189787374324972735U) + aNonceWordF;
            aOrbiterH = (aWandererH + RotL64(aCross, 5U)) + 17563763730956242224U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 10572803498593789385U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 43U)) + 7713105232072974166U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 10760839534772718139U) + aNonceWordP;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 11U)) + 13397069448391230253U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 4569255679998375682U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9888769350817876949U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11351796060878856300U;
            aOrbiterD = RotL64((aOrbiterD * 13356749147334008399U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 18153775071965707204U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1282846411145853435U;
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16457743979262460660U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 173493260775251032U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 4935807229040883505U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3927345926316409630U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5158769729850853623U;
            aOrbiterF = RotL64((aOrbiterF * 2446452358663812945U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12331351600010165154U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3940794200348684050U;
            aOrbiterH = RotL64((aOrbiterH * 13248997263062075043U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11248514843822945425U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1391497323278226522U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8376841806072565005U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13265623528678787307U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2802033745265647317U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 3437626962562016147U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 56U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23022U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 18791U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22732U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17338U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19746U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19869U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 57U)) + 701291026547470433U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 21U)) + 17283292650462111643U) + aNonceWordM;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 23U)) + 9969124091931303406U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 889176772718046988U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 27U)) + 6054541844643748084U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 37U)) + 14703226235143028132U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 7977975878522921062U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16894322614172266274U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12160451749345900570U;
            aOrbiterG = RotL64((aOrbiterG * 18055355572903901749U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10870847008043897470U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8159920947172520247U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4833194641611011805U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2440099120969517932U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 2428396147731468007U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 9363073341539598441U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2213226274394673479U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7079731443427765333U;
            aOrbiterJ = RotL64((aOrbiterJ * 16918930776877030559U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 958896789550478970U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10788682955708075458U;
            aOrbiterH = RotL64((aOrbiterH * 913321215613559729U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2003386579317564870U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8419686358774204999U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 6547052526438697621U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6989167615157578904U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17636634003643824148U;
            aOrbiterB = RotL64((aOrbiterB * 11038576417283732937U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + aNonceWordL) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 4U)) + aOrbiterH) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27524U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 31462U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 31045U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26953U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25570U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30030U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 1210605127156905516U) + aNonceWordL;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 41U)) + 11964595428173569519U) + aNonceWordI;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 29U)) + 16277319029916258482U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 12369497463101824572U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 6201248574067068202U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 6U)) + 1727477025667206661U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 1404510627789806851U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6948213591282018925U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6688865181284421478U;
            aOrbiterG = RotL64((aOrbiterG * 12619122841662247279U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3351130769402360855U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12681032488906270823U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3680893896579741263U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3591412591193726763U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16153817571210878589U;
            aOrbiterC = RotL64((aOrbiterC * 4165137036092246349U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3808228354421006630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1427373776207504205U;
            aOrbiterJ = RotL64((aOrbiterJ * 4534374093769595531U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 1831554180932501132U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1114853085120949215U;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2080935638828366835U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16104777999646489828U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15205199362011777473U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9782806013673440791U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3721620299829386454U;
            aOrbiterD = RotL64((aOrbiterD * 6286765834910272409U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + aNonceWordG);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 27U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterE, 34U)) + aOrbiterH) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Fencing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC5061548D62CF77BULL + 0xF3D81D3C0A38E25DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x98152495B62DD113ULL + 0xAB9EF909DDC56884ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFC86E4FB44447B3FULL + 0xCD54F68BBDC20910ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE70A80FC2CAE0F6DULL + 0xC7EAF12902A2016AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBE492A44E54757E9ULL + 0x912375212C02CE3EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE8058B94B2C45165ULL + 0xE1E881084E97E3D3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD69E2C03E0811785ULL + 0x86CE22E79D55CB7FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC4C1A5AF4F86ACF9ULL + 0xA19A442CA2302A60ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD3E7304340EEE811ULL + 0xDD33B29F4CA48D3FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB7F0D52F3D582455ULL + 0x93CF2351F3A52F62ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC0B53272F1F9311DULL + 0x8BD835E46497090CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE829DABDC245AD9BULL + 0xC1507D07E9B4B652ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF268944A204A6693ULL + 0x983CC66E5EAD7B9CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEBFEBDF3CDFA15C5ULL + 0xB198C39666058DA1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB19DA07BF3A8413FULL + 0x90F58924ADB4B6E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC237A98F979068B3ULL + 0x8AE93C4000AF6A7EULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aFireLaneA, aFireLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneC, aFireLaneD, aWorkLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7686U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 4436U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 1121U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7113U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6118U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 363U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 50U)) + 10336802574069791273U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 169025388197058936U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 6541354188379168846U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 5U)) + 16223920526599306104U) + aNonceWordJ;
            aOrbiterG = (aWandererA + RotL64(aCross, 23U)) + 12756613707692514808U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 39U)) + 5082475548176484035U) + aNonceWordM;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 4907435526952698526U) + aNonceWordG;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 52U)) + 14236627073831834337U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 57U)) + 11502511046130497584U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 3U)) + 3679044835550219497U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererF + RotL64(aCross, 11U)) + 11254838916686736746U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4628253464169957835U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17664454668473204465U;
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3798386391743884889U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1379331161819246587U;
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9816600392407327227U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16781971616348376878U;
            aOrbiterG = RotL64((aOrbiterG * 12503867584828289879U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4807797577690520554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2492057261148595922U;
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7909676419643119585U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 256053568910383007U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 11965085163352053161U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16179914439220412472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3968867762761955845U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7473632378251893139U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7474832923901283742U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 596484364660389193U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13822222274464306169U;
            aOrbiterE = RotL64((aOrbiterE * 1723502278319885511U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16307920280681985443U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3505106171801702915U;
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4987142580981135150U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10336802574069791273U;
            aOrbiterC = RotL64((aOrbiterC * 2670706512498539705U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterD, 48U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 23U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 50U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10079U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 12417U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 13695U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14758U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14104U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 13293U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 50U)) + 16124889768301047791U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 11U)) + 11912338587186717280U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + 8594012868813114354U) + aNonceWordF;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 5U)) + 18281043566156682815U) + aNonceWordP;
            aOrbiterA = ((aWandererB + RotL64(aCross, 40U)) + 16853106130200942302U) + aNonceWordL;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 2611212958619673086U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 18039472325066855180U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 35U)) + 14495785571345122046U) + aNonceWordH;
            aOrbiterB = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 4556063793412832418U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 27U)) + 14896419970271244358U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 880028529183500036U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2379557167489415783U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11854373946064529806U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 150755294320438887U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1487252775956449964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12777924204511625545U;
            aOrbiterC = RotL64((aOrbiterC * 1366019527386994789U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15998631485222477969U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8864212892296191613U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 579242788050369815U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17069347835763226743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7443008171694679791U;
            aOrbiterH = RotL64((aOrbiterH * 748894368884566607U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17334256152350782002U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8986626119086556393U;
            aOrbiterA = RotL64((aOrbiterA * 2258172145924120235U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8528180968228358674U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12702290928064582589U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 15673603224146737631U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7742438100860023610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3729687240959702198U;
            aOrbiterB = RotL64((aOrbiterB * 3756794766163746783U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 426129097367382096U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16782175452274911213U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1041477289638333659U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5942016166948841079U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5260815086125551703U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1603799103692438147U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11732742583346900772U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17182924380693084401U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 14858685629471497071U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8539335803784852017U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16124889768301047791U;
            aOrbiterJ = RotL64((aOrbiterJ * 6607245691919237755U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 24U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 28U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 38U)) + aOrbiterA) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 34U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19604U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 23336U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22348U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19159U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24254U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16983U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 13U)) + 13204735390996728477U) + aNonceWordC;
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 851171359595647173U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 35U)) + 16745304202825290723U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 40U)) + RotL64(aCarry, 29U)) + 562392736584913979U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 3244267012529053918U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 53U)) + 17282536111067869133U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 14851130066471729068U) + aNonceWordM;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 5256130407952363129U) + aNonceWordD;
            aOrbiterB = (aWandererK + RotL64(aCross, 20U)) + 2904742485828362001U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 11U)) + 3723346325449225387U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 47U)) + 5344621093694027341U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12919263300833603026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17989801264160996071U;
            aOrbiterC = RotL64((aOrbiterC * 15468293047311883751U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5022175042377172157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16684822380107847758U;
            aOrbiterG = RotL64((aOrbiterG * 2834049270263837537U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2740326510600876682U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13981423865219318820U;
            aOrbiterH = RotL64((aOrbiterH * 14593082145080056441U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 231945878229848395U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14139797734944312580U;
            aOrbiterB = RotL64((aOrbiterB * 6492256080432266407U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16704102101387552373U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8506734780526852552U;
            aOrbiterD = RotL64((aOrbiterD * 4684566118627414659U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2774630043988894695U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12490034334296488127U;
            aOrbiterE = RotL64((aOrbiterE * 16765455396278233145U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 545238171291436006U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1023872898002379590U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8626333831510136515U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5065187021047872560U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10391809965648089863U;
            aOrbiterK = RotL64((aOrbiterK * 10912471108849550469U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5576919045471579002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9761904001375034639U;
            aOrbiterJ = RotL64((aOrbiterJ * 8612901811320541361U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2001472279505185946U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11576457012366242134U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 1070815118051466731U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17713147845216099336U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13204735390996728477U;
            aOrbiterI = RotL64((aOrbiterI * 10889281795183444943U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 12U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 42U)) + aOrbiterB) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 52U) + aOrbiterE) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28376U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 31332U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30776U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28131U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27268U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24946U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 24U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 24U)) + RotL64(aCarry, 53U)) + 9446153639709651566U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 43U)) + 10550762260670758167U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 39U)) + 7062634922142578383U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 21U)) + 9178499097812764515U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 3U)) + 6887103379773525538U) + aNonceWordH;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 6239750312052010257U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 5U)) + 17645022614523287959U) + aNonceWordJ;
            aOrbiterI = (aWandererK + RotL64(aScatter, 29U)) + 3639618183259408272U;
            aOrbiterF = (aWandererD + RotL64(aCross, 19U)) + 3131737117548745095U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 7253994382396406554U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 60U)) + 15217993711938379561U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12594152227603630033U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11250170200489647869U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 546800378327864723U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 12936942656624279424U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10990736056052106149U;
            aOrbiterE = RotL64((aOrbiterE * 7123916809953459187U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12787293075893090465U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17154990205620778151U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10031369940028159521U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1270827262969060301U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17337623431665013136U;
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 830330490987911853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6828309232554560547U;
            aOrbiterK = RotL64((aOrbiterK * 9742464176986145819U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11470087853413986203U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10470148870747884420U;
            aOrbiterA = RotL64((aOrbiterA * 6766079738799967443U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18315536891901859637U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12264670822285914271U;
            aOrbiterF = RotL64((aOrbiterF * 5841574505408674119U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10931842095884524879U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11134871340959676257U;
            aOrbiterB = RotL64((aOrbiterB * 11714837622285605745U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11484168476761306078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5964766416973454097U;
            aOrbiterG = RotL64((aOrbiterG * 14721123403032510803U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10646362765367117994U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8994267196877016381U;
            aOrbiterJ = RotL64((aOrbiterJ * 17386417559346134797U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16797547458402042464U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9446153639709651566U;
            aOrbiterD = RotL64((aOrbiterD * 567585472220695323U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 10U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 26U)) + aOrbiterJ) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 38U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 23U);
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

void TwistExpander_Fencing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBFA6A6B4C8E03641ULL + 0xE5DE0F5E60DCDEC0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE726144E66B66B29ULL + 0x8C755281F038D025ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF876BCDD403B1B67ULL + 0xFBB5B89D4A6FE1CAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDC0E2653B30CD0C5ULL + 0xD274C82206B2F8FAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8AF32DC1F1879F1FULL + 0x8A525926985F46B0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC6E6E7D6BD7D94F5ULL + 0xC278CC041815E683ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x807C407391D97FC1ULL + 0x8FA3B7B94675F75CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9DB964164282BFBDULL + 0xA3E7B4A35F68A730ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9CBB5FFA60E75751ULL + 0xA8137B6742010EEDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE4053D7837EA70C1ULL + 0xF0EDCC90C8AE247EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9C78769027C830A1ULL + 0xD6276DB7FBA44E56ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA80D62A240278633ULL + 0xE3E94C2CD1C5A0EFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB928CF0A93AC05BBULL + 0xA3FDBE805E5D3C55ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAA4B8CA956F26B6BULL + 0xFF438303ECC85121ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD0C67F73C658A459ULL + 0x85FE0BB123680AFCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC3920F4B636B285FULL + 0xBDE3DCEB13E77931ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneD, aFireLaneD, aExpandLaneB, aWorkLaneC, aFireLaneA, aExpandLaneC, aFireLaneC, aWorkLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7055U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 4856U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 3681U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7454U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5591U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 3144U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (((aWandererE + RotL64(aScatter, 12U)) + 13714409587461539863U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 14101156723903265839U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 7063754562895369001U) + aNonceWordC;
            aOrbiterD = (aWandererH + RotL64(aIngress, 5U)) + 12320578575245519386U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 58U)) + 11744826789631008424U) + aNonceWordP;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 39U)) + 8744816505096675597U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 53U)) + 10405435520084528645U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 43U)) + 1463157688070683543U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 12379603577919617703U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1343439118031348146U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16118850268070235540U;
            aOrbiterB = RotL64((aOrbiterB * 11184386483735388257U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14116264435819277136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5251698273012432109U;
            aOrbiterI = RotL64((aOrbiterI * 1495818611622063967U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14806408656041403829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11569345414052398227U;
            aOrbiterC = RotL64((aOrbiterC * 9913158908301414861U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17063874769147888574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9927420478679581917U;
            aOrbiterG = RotL64((aOrbiterG * 9042782809534196563U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2550285599827162167U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17801534123304996448U;
            aOrbiterF = RotL64((aOrbiterF * 2160836889363614721U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6456685241021762041U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17064208177372969289U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13726627607233302493U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18279938244131982650U) + aNonceWordN;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 8211002229712129419U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 12931373380977640645U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12795832560781931767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 286378504074349650U;
            aOrbiterK = RotL64((aOrbiterK * 85453101173293509U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5835304250436889513U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12704972686724379659U;
            aOrbiterH = RotL64((aOrbiterH * 1198789639656336053U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 28U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterH, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16019U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 11675U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8329U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15275U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15716U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8615U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 18U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 34U)) + 3550722402315312207U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 29U)) + 16724184551669522754U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 23U)) + 981751330116773021U;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 7891159229704944868U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 13618396711464799841U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 5U)) + 5969291018449003648U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 43U)) + 14595540413313640042U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 3287990436916111762U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 60U)) + 12534369400200483704U) + aNonceWordD;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2277312067930392274U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10026320559261334353U;
            aOrbiterJ = RotL64((aOrbiterJ * 11020464940995912637U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11258082063135659551U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1445958517675746990U;
            aOrbiterE = RotL64((aOrbiterE * 10062265337488757971U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1011298251290970844U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6487834862470043744U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9966279022928268335U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10285993486057704393U;
            aOrbiterC = RotL64((aOrbiterC * 15965714363201157535U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16005362468813966136U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 223843444699390781U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 665392038954573081U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18178876294968532775U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12490136112181806806U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 16380841616662993709U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8775696166557913635U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16464340319444310842U;
            aOrbiterG = RotL64((aOrbiterG * 18111632334728200721U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6296039992673546227U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7152939277656436037U;
            aOrbiterK = RotL64((aOrbiterK * 15183918431501487319U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14066791413416223271U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5026743227399908016U;
            aOrbiterB = RotL64((aOrbiterB * 5891343232759075675U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterK, 36U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17760U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 21743U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 20569U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16698U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17810U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22334U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 6U)) + 15910560457440369082U) + aNonceWordP;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 35U)) + 17953072986407436888U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 39U)) + 15446940721193538669U) + aNonceWordA;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 3020785262774422009U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 47U)) + 7001288645424994404U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 13385250665458462689U;
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 4841895644623005949U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererE + RotL64(aIngress, 60U)) + 13053476783239482065U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 27U)) + 641996979335975244U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16211238020928688299U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12715448751323279480U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 2116880429675303291U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17784406727699995290U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13940754474750138041U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9035070625716345139U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6085848172494001945U;
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1177103851507561053U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2281901691017816407U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3142197009403602497U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9040984343694325070U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13334258224023902365U;
            aOrbiterF = RotL64((aOrbiterF * 4782523727707164869U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1079824790138592518U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14024082692012948652U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3219489374333737903U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2966776524421278970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5510281854029308547U;
            aOrbiterI = RotL64((aOrbiterI * 9275402927591867297U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7126632329316720048U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1476827035602733472U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 2217671289726794033U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6470212302133184965U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4172257438373147415U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4449314239630366533U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterE, 4U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterH, 60U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28067U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 32265U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26216U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25806U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27910U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 26583U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 27U)) + 12029393034357490020U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 51U)) + 4526754731580694987U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 17060419646421271853U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 40U)) + 4128488893837059683U;
            aOrbiterF = (aWandererK + RotL64(aCross, 19U)) + 12706894827547160110U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 35U)) + 12506324593645825056U) + aNonceWordK;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 12581344490649250025U) + aNonceWordI;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 44U)) + RotL64(aCarry, 41U)) + 14357032418199130132U;
            aOrbiterK = (aWandererF + RotL64(aCross, 3U)) + 15341977701796331249U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7086602307544733241U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12398300065276832486U;
            aOrbiterE = RotL64((aOrbiterE * 18157408831225635333U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2499745046076601988U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7249361592814001829U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14597139848072319685U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3254456186337366437U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3472973415969046680U;
            aOrbiterD = RotL64((aOrbiterD * 14583566953969168353U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7905718972111691591U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15941413652144021522U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3473779492962783565U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10583964125960308762U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13659925272340853715U;
            aOrbiterK = RotL64((aOrbiterK * 16708294803316630743U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9487054537489454887U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13287757570441887517U;
            aOrbiterG = RotL64((aOrbiterG * 17351439045329892107U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15279245465808571942U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 12424999114621745879U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 2274918760256527137U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13915392738892970475U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13797668053788805126U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 13752161103680525317U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14344766585550401077U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13727554194373146727U;
            aOrbiterF = RotL64((aOrbiterF * 17164450431362670223U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 26U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + aNonceWordO);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 26U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aCross, 4U) + RotL64(aOrbiterB, 48U)) + aOrbiterH) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Fencing_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF697EDEDD05DC5F9ULL + 0x8EF0D4E7621535BCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA3EF37A40A4A5297ULL + 0xFFF0F9B300BD2104ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAA8F3453189E7279ULL + 0xBCDD411612F39ED3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD4826E4A50DDD629ULL + 0x84734D59B0A13BABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x94237ABCA60E99F5ULL + 0x857B647559FB9876ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x83C35BD5AE1C8E67ULL + 0x9A9E763D48B4F189ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF99CDD559F90A083ULL + 0xDE25D983E5D8D30CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8655D98E94B3CF9FULL + 0xB071D35FB84F68BDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCA2C4B626E4F3D87ULL + 0xB8D1C8B24A08A822ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC3498AB89949733DULL + 0xC81C3D149C3AC338ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xACC9736AC85A97F7ULL + 0xD15D6C1DC011F54AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x989759EC3A9FC0EBULL + 0xBA6935BB93B0A3EFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8D2E278BE2154327ULL + 0xA5B7E5E3CD126ED3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB66D43B75A20299FULL + 0xA7FE3221265FF36DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xABCD5058D12868B5ULL + 0x9B85EA2FAFF09CA0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC93E9D357F251B41ULL + 0xB6D7E6842423B3BAULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneD, aOperationLaneA, aExpandLaneB, aFireLaneB, aFireLaneC, aExpandLaneC, aOperationLaneC, aFireLaneA
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5586U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 5717U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2506U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6658U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6881U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3784U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 41U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 29U)) + 16922357079016918108U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 11771749797137599131U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 11U)) + 4635668433708036077U;
            aOrbiterE = (aWandererB + RotL64(aCross, 39U)) + 15827952719230577008U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 3U)) + 1495675306110023086U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 7294835466949728365U) + aNonceWordK;
            aOrbiterC = ((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 35U)) + 179122461212041978U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 545981421632236251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15338259639814630535U;
            aOrbiterH = RotL64((aOrbiterH * 14895421566334357871U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12924313840290895215U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17846785921286020610U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18309347016029917133U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5721472794107057875U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16359630793856870319U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 14186771515526698907U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10614102110239037308U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16421992251278236531U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2561232904676068089U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8668149834861244963U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12699331834360948734U;
            aOrbiterJ = RotL64((aOrbiterJ * 2249360824172616357U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4470693178142950471U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 526000656022724741U;
            aOrbiterE = RotL64((aOrbiterE * 16688501462334673493U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6880246132270094141U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7126466778855297013U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5692237926830293205U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + aNonceWordP) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 44U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12457U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 11383U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 10925U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11519U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8893U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 12928U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 17074147006464019918U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 36U)) + 10559516626129419928U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 13280363679503946221U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + 17657115422132457413U) + aNonceWordM;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 23U)) + 13325837013304973008U) + aNonceWordK;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 3059707750486106037U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 51U)) + 4529045702503050852U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10726578475550904292U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14832537837996659885U;
            aOrbiterF = RotL64((aOrbiterF * 808060368961520519U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 220094417441809246U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15343130035105342194U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7984652435043810845U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16592263353426409884U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15649290906447931918U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 8405875177836650731U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11437410545843708269U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5859769136073011444U;
            aOrbiterE = RotL64((aOrbiterE * 1065016088086441107U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15188064100307340341U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4367466521843260049U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 15916715854192820923U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8482617283860566845U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2585745804937342972U;
            aOrbiterC = RotL64((aOrbiterC * 8267269625632139809U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1687641344403425541U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13667916445979421400U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8191322670355590027U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 30U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17915U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 24192U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 23400U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20190U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20695U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 19520U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 29U)) + 10805654776556844351U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 51U)) + 582794182442795335U) + aNonceWordF;
            aOrbiterH = (aWandererC + RotL64(aCross, 43U)) + 2858343650974681068U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 8189584049022064284U) + aNonceWordE;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 1565100751996962893U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 18U)) + 8062028016947611891U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 8280504280578451745U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11326869194491655350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1671695656567777163U;
            aOrbiterH = RotL64((aOrbiterH * 7511554500524257921U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2349843105293943452U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13015545152052004254U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 1316662811685429983U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16703354404749291869U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11118401674497783533U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14857556493734710364U;
            aOrbiterF = RotL64((aOrbiterF * 3452566050389715195U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12953419670951660965U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12666121730825089017U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14049925256934142519U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11075249639473053423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9374217688244187867U;
            aOrbiterE = RotL64((aOrbiterE * 5261156325627117877U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 17608340953291367867U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13159437499327086340U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4882100944453534805U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + (((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordG) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 14U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31185U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 30661U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 29069U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29200U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31745U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 31364U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 13278949403988203974U) + aNonceWordD;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 9213599924054673756U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 24U)) + 1255746482932381798U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 11575321997144516122U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 43U)) + 15881587525529432437U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 57U)) + 9846195809864862707U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 35U)) + 12319815691858217670U) + aNonceWordM;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16322617427294439587U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16332130810525887437U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 7588076439690559343U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4920951156015336794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16767126455124552329U;
            aOrbiterK = RotL64((aOrbiterK * 4440352337076842603U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12553595911087945223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1437522202135436142U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2001992794165550905U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12313100454852227143U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3874839760378039509U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17635303588421554367U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 788212489507463763U;
            aOrbiterE = RotL64((aOrbiterE * 17896475584538528059U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5192552894670654434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6784748488807738811U;
            aOrbiterA = RotL64((aOrbiterA * 8077237651953896479U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16113417046719114943U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1096874945215225916U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17308604412622879833U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 28U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterE, 46U)) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Fencing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x875FCA6717A5037FULL + 0xADE6D882B722606FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE345E20A58837BCBULL + 0x85CCC0DDD3C5FAB9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFB4F0E6A084C9A6DULL + 0xE5F85227930E10DBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x87170F9AAD0B01DFULL + 0xE7377DF235921D60ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA8FCE7D3427A5119ULL + 0x9AC34EE97F87E9D6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCBE55675C3290E33ULL + 0x9BE3E37D74EA662EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9E3C76480918CBA7ULL + 0xE7C3A2FA342A2D22ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x83B6D1C6958D4333ULL + 0xF8E002D567E5EF1CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA321D2B54AD7FE9FULL + 0xDD00355D71C9C65BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCA128E7050EA0307ULL + 0xFFFB6CACA9FE2E48ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD40255D864753DE9ULL + 0xFBA5B44E94FDF386ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA10FA6A719FDC163ULL + 0x99981ECB345B7D56ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFF51C835D050FA2BULL + 0x998EBB49BD9DF63AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDBD67EDF557EDBDDULL + 0xFBC439231AD1B361ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC0566379B0FB36DDULL + 0xCA5BE28C052D59C8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF8FC1BC550CBC3F1ULL + 0xDC1293662E3E9806ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1080U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 306U)) & W_KEY1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1810U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 170U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 439898681482066326U) + aNonceWordA;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 28U)) + RotL64(aCarry, 3U)) + 17362083676671776094U) + aPhaseEOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 5U)) + 6418499837265155024U) + aNonceWordM;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 47U)) + 17262244253027454972U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 2382066162993139503U) + aNonceWordL;
            aOrbiterG = (aWandererF + RotL64(aCross, 41U)) + 14345808395587174135U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 35U)) + 7534743166385552851U) + aNonceWordN;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16994453324688523966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7079553728544045092U;
            aOrbiterC = RotL64((aOrbiterC * 10104892188895367489U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3562822704508440641U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13990892681975857821U;
            aOrbiterF = RotL64((aOrbiterF * 8352929306654078795U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1796728922368577238U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6605161260520067178U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8147537646591674091U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13994083795942328918U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6144523182899107711U;
            aOrbiterA = RotL64((aOrbiterA * 4153879991344611283U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12247462325297436642U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1065809332002012789U;
            aOrbiterK = RotL64((aOrbiterK * 5496601177032953251U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10147919864511540753U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17138553441127273354U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5773875596275267871U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2653924016109573974U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6254416952351699582U;
            aOrbiterI = RotL64((aOrbiterI * 12756861659704947257U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterA, 23U)) + aNonceWordB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 14U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterI, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4728U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4268U)) & W_KEY1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3182U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3767U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 12U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 29U)) + 16519040829220310189U) + aNonceWordK;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 3U)) + 6888002778416941825U) + aNonceWordP;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 1310832187746534025U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 36U)) + 5890888009051281674U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 5143864838362464857U) + aNonceWordL;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 15591534069452660003U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + 1466867671765325096U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13931443680107902488U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15400747367673245552U;
            aOrbiterJ = RotL64((aOrbiterJ * 7011651369456453127U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2836975369734495759U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2370720358274970117U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 4615571902817575375U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3470677184188006133U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7175584278499266723U;
            aOrbiterG = RotL64((aOrbiterG * 10067096593682482345U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6095078817776863055U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2176637999243513070U;
            aOrbiterC = RotL64((aOrbiterC * 12215701810843975501U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5580391239754903129U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15196125567953871184U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12686361960729564519U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12787014151503209931U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1523153207064063495U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3113907543551927561U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12973289026485937829U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9087439766232078173U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 5817029335999350327U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aNonceWordF) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterC) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 12U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7482U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 7041U)) & W_KEY1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7991U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8150U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7885U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 20U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 21U)) + 1457104756581596530U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 6127240317844622874U) + aNonceWordO;
            aOrbiterD = (aWandererB + RotL64(aScatter, 5U)) + 16492290056044189421U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 10963676850938416468U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 11U)) + 4872917367399752405U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 15218882377875616148U) + aNonceWordF;
            aOrbiterJ = (aWandererF + RotL64(aCross, 19U)) + 5934166612122118251U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14215280930872003003U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11428034799044600979U;
            aOrbiterD = RotL64((aOrbiterD * 12162528943733976177U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5453003654321728726U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 14273775120265649389U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 5139018128323795309U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 328723770018440271U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13032190719588211088U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13363368478932798315U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2386881543033598494U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1649501123340887116U;
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16462401546754210583U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1510579201823042227U;
            aOrbiterC = RotL64((aOrbiterC * 16287912400104043275U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6889066000014251983U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11324594596597724357U;
            aOrbiterB = RotL64((aOrbiterB * 15344987814648586023U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12237796033168436537U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17306069670330000343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3167451351403385259U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 4U)) + aOrbiterK) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordM) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10594U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 10197U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 9579U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10215U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8744U)) & W_KEY1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 10244U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 27U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 15920462086654025436U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 487844076858004017U) + aPhaseFOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 34U)) + 14502883786442630566U) + aNonceWordI;
            aOrbiterA = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 3787107318658233674U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 41U)) + 12548777544693755491U) + aNonceWordP;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 5U)) + 4907309444075181683U) + aNonceWordN;
            aOrbiterG = (aWandererE + RotL64(aScatter, 57U)) + 18342396700266492072U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13503051997624242670U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17845742460521374571U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1366356786138085155U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8640887211877858169U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5273913123709097537U;
            aOrbiterB = RotL64((aOrbiterB * 1661149444148461791U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17756844173695563883U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6713055830729302951U;
            aOrbiterI = RotL64((aOrbiterI * 2832836748513174311U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5106468334224035972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10228769728713526172U;
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7687649520668883142U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7757480627354711605U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 7222553727737349209U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10876291698508634557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8149278085586014186U;
            aOrbiterA = RotL64((aOrbiterA * 8577133863470695381U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 15592893988925610485U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8639028256640537165U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 48U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11745U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 11447U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11678U)) & W_KEY1], 19U) ^ RotL64(mSource[((aIndex + 11436U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12278U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12839U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 13643U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 26U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 5041131702736607991U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 13U)) + 9295010428212681446U) + aNonceWordE;
            aOrbiterD = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 6235875895358766017U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 2622227802531866918U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 56U)) + 3888894734834524972U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererA + RotL64(aCross, 19U)) + 241682012014701753U) + aNonceWordJ;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 15758000422451568079U) + aNonceWordD;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2061944548396976912U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8177144990755754531U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12702392689484397947U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 554978075608818497U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterG = RotL64((aOrbiterG * 1295379390497107727U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8700027645880997552U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10026130047465480902U;
            aOrbiterC = RotL64((aOrbiterC * 12417270861933696623U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9785843014096326696U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9998582683258411251U;
            aOrbiterJ = RotL64((aOrbiterJ * 7197956237569462269U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13817734599383455151U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6647207154174092691U;
            aOrbiterH = RotL64((aOrbiterH * 1578528131687283531U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4957715980509035719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4994885315786213197U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 5676683798126497011U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 5072908311783966503U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5535039946192891515U;
            aOrbiterB = RotL64((aOrbiterB * 2989412783482309753U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aNonceWordH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 20U)) + aOrbiterI) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13907U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 13864U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15921U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15775U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15093U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14522U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14734U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 57U)) + 12583180859826261500U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 9067093488553721468U) + aNonceWordA;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 12173106198862881754U) + aNonceWordF;
            aOrbiterD = (aWandererD + RotL64(aCross, 3U)) + 11333491014394592654U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 20U)) + 3511883526940919554U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 7416810692106273044U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 13U)) + 8341174972619784110U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2220852854836962979U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8090781422229383825U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 578293950675644397U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2338801236599102223U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12484514711848308104U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 10364216764253366067U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13684861340589131816U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12796636819991873058U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5533508014234835669U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7634198650894837690U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10240326122201201762U;
            aOrbiterF = RotL64((aOrbiterF * 8758703497719125901U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4162814763739453934U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2766504649149048469U;
            aOrbiterJ = RotL64((aOrbiterJ * 16731843453895178671U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11051393030148769655U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17687055068651386665U;
            aOrbiterD = RotL64((aOrbiterD * 1042927176246229537U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3353615315436983420U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5971640796220306310U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15804313508835034807U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterI, 56U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aNonceWordN) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16522U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadA[((aIndex + 18120U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(mSource[((aIndex + 17633U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 18719U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 19071U)) & W_KEY1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18796U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17940U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 24U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 27U)) + 7651355040951791298U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 5U)) + 13988210277931659312U;
            aOrbiterE = ((((aWandererH + RotL64(aScatter, 18U)) + RotL64(aCarry, 47U)) + 9846849412579537783U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererG + RotL64(aIngress, 57U)) + 12746719939495876158U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 11498066185182895284U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 11101058955193080232U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 37U)) + 15513734459555672046U) + aNonceWordM;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15711108675349394643U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4771231759949468556U;
            aOrbiterE = RotL64((aOrbiterE * 9806191054594333615U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11449258010811305256U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17036938391509986723U;
            aOrbiterJ = RotL64((aOrbiterJ * 7411466953205347639U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6999245666776654250U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2106819066263369528U;
            aOrbiterA = RotL64((aOrbiterA * 13005885810757743129U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12716183358903477216U) + aNonceWordJ;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 16752724547046059889U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 11475905692393034141U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17623077680983093163U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6726003022297274986U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 14709385877103232653U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2842410225096524740U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9235178377537910514U;
            aOrbiterH = RotL64((aOrbiterH * 11813751114775673845U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2619888019860844610U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6295481948199619613U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21772U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 21597U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19971U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20155U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21480U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19438U)) & W_KEY1], 50U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19414U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 21243U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 16462052553719977502U) + aNonceWordC;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 29U)) + 12337064059566619581U) + aNonceWordD;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 13U)) + 15801005007094515447U;
            aOrbiterG = ((((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 8228706742665081656U) + aPhaseGOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 3U)) + 11006723027845190869U) + aNonceWordE;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 3U)) + 18173765337829177450U) + aPhaseGOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 39U)) + 530215083653542558U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 6608611827035564511U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2246051826221626809U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 6333352641495253539U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5228575308895381421U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10999213210689606857U;
            aOrbiterE = RotL64((aOrbiterE * 5467601259546342925U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3773371037240485696U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8887985779436152504U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11150566414723818350U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8336366151003049546U;
            aOrbiterH = RotL64((aOrbiterH * 9033771197242493699U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13233968794237090787U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8172558473508478819U;
            aOrbiterA = RotL64((aOrbiterA * 17837070423649268435U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 133564480283347997U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15104810248883567064U;
            aOrbiterF = RotL64((aOrbiterF * 706802420642303533U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9138629520201127075U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13993086066341664080U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4875046427147105077U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 35U)) + aNonceWordG) + aPhaseGWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 18U)) + aOrbiterG);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 19U)) + aNonceWordP) + aPhaseGWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23854U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[((aIndex + 24085U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22773U)) & W_KEY1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23431U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22402U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24330U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23998U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 22628U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 28U)) + 2168513956284366370U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 57U)) + 10290361969974613111U) + aNonceWordN;
            aOrbiterA = (aWandererG + RotL64(aCross, 11U)) + 15673836275828498050U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 16600540024145812236U) + aNonceWordG;
            aOrbiterB = ((((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 9428052101528111892U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererF + RotL64(aCross, 51U)) + 12763657928312763377U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 10751286982008662485U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1708230173038057979U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4011389705422783816U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11692237130784795961U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11704428328093077714U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2055336619674699284U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6374289210096410907U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1870865272102705804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3574214263751923179U;
            aOrbiterB = RotL64((aOrbiterB * 13132083406834413563U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 984611970726966186U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4181398506373973169U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15222345431506025949U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 6925143692628659467U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15023513452326240962U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14965669361708810699U;
            aOrbiterC = RotL64((aOrbiterC * 587008860996713147U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7985755518735406360U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 225592097619240187U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2313509354133400439U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + aPhaseGWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 46U)) + aOrbiterC) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25394U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 25175U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25949U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26500U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25021U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26747U)) & S_BLOCK1], 52U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26632U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25236U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 1952750591494698524U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 35U)) + 4488270851303332830U) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aCross, 5U)) + 2738763375328927635U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 44U)) + 6728843649480454340U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 10490717875258865358U) + aNonceWordN;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 1429288737812910205U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 51U)) + 2761375016998907636U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1088988605204499835U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6829840407300289709U;
            aOrbiterH = RotL64((aOrbiterH * 13101432880030791787U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9267240337867690471U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8120113021183975703U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14296504593187173107U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1340980511302566784U) + aNonceWordA;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 11874452169979878835U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 8638486178860092537U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1872314794140971426U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6013952618696225751U;
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3644011378086236002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8501867691997891731U;
            aOrbiterJ = RotL64((aOrbiterJ * 7115282675461711509U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2493546555198066143U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5179240189571799179U;
            aOrbiterF = RotL64((aOrbiterF * 1267579130962756135U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11273348247858394197U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 4577476419423118925U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 8427261005061162673U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 36U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterF, 58U)) + aNonceWordI);
            aWandererK = aWandererK + (((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 53U)) + aNonceWordF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29365U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 28359U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29518U)) & W_KEY1], 47U) ^ RotL64(aFireLaneC[((aIndex + 28188U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28034U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28610U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29517U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29672U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 5173905450211892891U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 3555542451908039957U) + aPhaseHOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 41U)) + 11559884700283861559U) + aNonceWordE;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 1352524329968738673U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 47U)) + 8914206450420616349U) + aNonceWordF;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 57U)) + 2251523378498463946U) + aPhaseHOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 22U)) + 9541575923299247038U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1239854507907214595U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17698101462598498934U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2304948713665996433U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12305566971683256060U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13804545036303215569U;
            aOrbiterG = RotL64((aOrbiterG * 10359543704152744971U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10239749097704329264U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4212214906286320308U;
            aOrbiterD = RotL64((aOrbiterD * 3661436621615751071U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12192418916967430783U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4475514289326450361U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17497164630368757887U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17376102613298827459U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18129393209955439341U;
            aOrbiterE = RotL64((aOrbiterE * 6404089025014118979U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4014763724300253568U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17325007199676828814U;
            aOrbiterB = RotL64((aOrbiterB * 1420888274815627083U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 15480474849292388685U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14357924730184375449U;
            aOrbiterI = RotL64((aOrbiterI * 16723492259068034209U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 14U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordP) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32519U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[((aIndex + 30943U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30782U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30600U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31730U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30769U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 26U)) + RotL64(aCarry, 11U)) + 9023059520606551446U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 43U)) + 662441755115638133U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 13U)) + 16957253361196144712U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 19U)) + 7840955025765308605U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 346855809270395799U) + aNonceWordB;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 35U)) + 16099139781586668343U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 3706457327118322098U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12166825885547622870U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7792658665720344200U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16305542632794270697U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7128477606152986326U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11116533962780290084U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 11993485572912492297U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10443889548568288532U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4402387036946561017U;
            aOrbiterJ = RotL64((aOrbiterJ * 9032964741841833277U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13002706161178447654U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13929727277530310708U;
            aOrbiterA = RotL64((aOrbiterA * 7005639090871200285U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10949073760696935106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15405923432006783533U;
            aOrbiterE = RotL64((aOrbiterE * 17989565878445202495U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18096057968822208905U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3032155040484574973U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17462076466907467134U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15471015427013701406U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6113474000571976139U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterE, 36U));
            aWandererB = aWandererB + (((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Fencing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD87B9478C9A45A25ULL + 0x9817BEF277A51860ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB4635123D001F3EDULL + 0xB5CDC26B7C5A406AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8CDFBE70B2AAE361ULL + 0x9E7657EE5CB08D43ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE68099F458A7803DULL + 0xF45D7FE4F091FC62ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x936A083A8239C5E9ULL + 0x895EDB1B5A7A1194ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x822DB9E8B9E754D5ULL + 0xE39A7A161F361EC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF31D20D53B855A93ULL + 0xE03B3A124F32C180ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE7826C452F41C1CFULL + 0xC144955207F32F1AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA8BC48A23156EE0FULL + 0xE07A8B21F0D0879EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC3CC0F6C09910CE5ULL + 0xEF5A0089B497491BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9BF66DDF7FB1A949ULL + 0xC5BEE7128AA01EC6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFD0B65013F7C52FDULL + 0x8ACA71D6630E10C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE4DC31A60842FBB5ULL + 0xEAE2D6E3136034A4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF06BF286ECF12CBBULL + 0xB1AD71589C4627D3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB9AAD977BCDE85D5ULL + 0xED393A99E26741DEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE0DA1CEF46C0E641ULL + 0x8705B8B705A53FDDULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneB, aInvestLaneB, aFireLaneC, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3470U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 4048U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5264U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4493U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 4344U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 16424657151168221875U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 17150123681886380361U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 16041993588694572757U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 4U)) + 9871185846434828537U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 13U)) + 11227236398354430757U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 5399325217402192631U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9248828789282890454U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6733832755349139621U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9041370494203701062U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14944424084524970764U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 10283363059424655079U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5481938174456671041U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14783648629543752715U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12355573914530445723U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9863991559011968318U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8495251211794343179U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16149688605937250965U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterB = RotL64((aOrbiterB * 12199934305374582599U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 24U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + aNonceWordG) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10335U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 8370U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7062U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6230U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10059U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 4773124477323378268U) + aPhaseAOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 16848723289435796005U) + aNonceWordF;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 5U)) + 13846642134917107058U) + aNonceWordE;
            aOrbiterI = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 6472057872482789939U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 37U)) + 2747019500690707226U) + aNonceWordN;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9003965289739733880U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3013390651936257377U;
            aOrbiterB = RotL64((aOrbiterB * 11081353600889943167U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3331004709895625067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15355010435553517129U;
            aOrbiterA = RotL64((aOrbiterA * 8322759117004876831U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7709870658004280052U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13568728443963926564U;
            aOrbiterG = RotL64((aOrbiterG * 6736090830113688981U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 12409548853419307131U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 969183352023661537U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 5549220554838837145U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15370309834426476775U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3896803894396631184U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 11018830202891911603U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordB) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11252U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 14307U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 14320U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15223U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12920U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 11715U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 9774364261626083532U) + aNonceWordN;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 18059001521926116420U) + aNonceWordL;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 37U)) + 10615626210406381148U) + aPhaseAOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 48U)) + 10536484278007898620U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 13320663045139972700U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 17127001787268166583U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16742574590844166551U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17828964140627204983U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8347719720758228053U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13502468705946051986U;
            aOrbiterA = RotL64((aOrbiterA * 13822952083584784695U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3512687886188904904U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 495660316165795934U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 6724596801190194913U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5092722552034477356U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15641128019608284015U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15421873776811085458U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17978775513204574125U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18359600395119440183U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterI, 58U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 38U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19892U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((aIndex + 20405U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20877U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21002U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19652U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19214U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 47U)) + 2101601659597850213U) + aNonceWordI;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 2759794072560720121U) + aNonceWordD;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 9443562552411269339U) + aNonceWordJ;
            aOrbiterC = (((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 10801360546699857975U) + aPhaseAOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 21U)) + 8020716394829332019U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1021894212367773801U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13346855534622490176U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 12668950387932320985U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16359309548462953836U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12642446944680783519U;
            aOrbiterF = RotL64((aOrbiterF * 12197935153255283321U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8197424982767553380U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14346334610901859094U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 16982899923227935679U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14171304260534233539U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 334531601308283605U;
            aOrbiterA = RotL64((aOrbiterA * 5012968232749075075U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 10707856298471572695U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 18364775750091914766U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 15735143943129143265U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordL) + aPhaseAWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 22U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25459U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 24761U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25969U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24119U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23700U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25019U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 18U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 15904465836916519864U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 17725629806317789307U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 30U)) + 13794170125914914828U) + aNonceWordE;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 2149055907476874332U) + aNonceWordA;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 43U)) + 5342047776745074649U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8268148484060546838U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10821151364028563719U;
            aOrbiterF = RotL64((aOrbiterF * 13626634259250509711U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4294213820894407378U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10884726101307943090U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1116128870387229159U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16432210042202444824U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15196602644336228055U;
            aOrbiterE = RotL64((aOrbiterE * 12680438355124070237U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14117787670220328165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 219833877949480215U;
            aOrbiterG = RotL64((aOrbiterG * 10736293047771972173U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3326396981881473962U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14918513066311426279U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 14269763278564574663U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 40U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordL) + aPhaseAWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28656U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 27572U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27931U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27307U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32360U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 28690U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 26U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 13924571355038625040U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 58U)) + 16328300979357156658U) + aNonceWordK;
            aOrbiterI = (aWandererG + RotL64(aScatter, 5U)) + 3947771961206012461U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 15428284250569311285U) + aNonceWordG;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 5777369485254032486U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16813320300717644673U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16689933050200758251U;
            aOrbiterI = RotL64((aOrbiterI * 4832495563863469353U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 1856422419049390708U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18214498743831925517U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 10744120577560529379U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18278550878494094923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 797712062039591797U;
            aOrbiterD = RotL64((aOrbiterD * 7212998747080137625U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15854849439012341347U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 996882939768167773U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 14936703950807908575U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3005829974130671692U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8793495343509953906U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 14065479348374612031U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aNonceWordE);
            aWandererK = aWandererK + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 20U)) + aNonceWordM) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Fencing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC64D4AAD2B755F8DULL + 0xCBDE07B45E2EF955ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8B28D0E34B235531ULL + 0xAE13D6BA5588E770ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEE20C45565C4332BULL + 0xE1550EF1EF398529ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9513A745169DB049ULL + 0x98A594E9DA6599A4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9CAAAD5EC226AA13ULL + 0xF7355CFBDDE4927FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x952518F1D8CBD925ULL + 0xE547F7295D6D5280ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A343C7D6296728FULL + 0xB4F67446CDCAEC02ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA4360FBEE3449357ULL + 0xE944A35AC82D3A8EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFCAF6ECD8D9C1B8FULL + 0xAE15DEF0678207AFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9C9976611856CB15ULL + 0x8DF48881440DB6A1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA0275FF310438185ULL + 0xD3768EDECC0EECDFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBEFC7DD5EE06BFD9ULL + 0xD6A2891983A27256ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAD7C664125AE4ED7ULL + 0xF2D9594129364AB7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD4278A9A3864AE2FULL + 0xE2ADE21368E67B89ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD87300671512ACE1ULL + 0xF2982B909029202BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFE94C2C997FDAEFBULL + 0xB7110719B569E7B5ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD, aInvestLaneC, aExpandLaneB, aFireLaneD, aInvestLaneD, aFireLaneC, aWorkLaneA, aFireLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4398U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 4337U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 2936U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1829U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4865U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 742U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 2177539223979303669U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 52U)) + 3962004686551521471U) + aNonceWordM;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 8457602312617147662U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 43U)) + 18011802451816510632U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 29U)) + 9046101759168876832U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 34U)) + 11135620637431969597U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 15913029940697999701U) + aNonceWordB;
            aOrbiterA = (aWandererH + RotL64(aIngress, 23U)) + 16304193109948135982U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 13208892298820080981U) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4182377898949419225U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13970137023071326151U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8402396284835248583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8859190834060657829U;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9760005337757990392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14108277760135744897U;
            aOrbiterB = RotL64((aOrbiterB * 4474681104256093885U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 12226316121949012350U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3456392186754113960U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8704729827929941215U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5004087958637038973U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7176881295123125567U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10889800478505074438U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13728832441482547824U;
            aOrbiterH = RotL64((aOrbiterH * 17588477761978646139U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17345665880706866772U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 301139993853297566U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5812445396758354505U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2061389844760610160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13631862266139238355U;
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10767186080827509622U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4893486019456886013U;
            aOrbiterG = RotL64((aOrbiterG * 5194746459545610901U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterI) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterD, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6340U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 8097U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8920U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 5894U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6683U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5707U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8405U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 35U)) + 4476099022490972343U) + aNonceWordN;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 11U)) + 16836423700375760429U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 47U)) + 8850577488928703557U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 30U)) + 7091631824560042743U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 23U)) + 12560498899956759494U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 7797973377112012161U) + aNonceWordO;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 6173820673874805794U) + aPhaseBOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 60U)) + 10805025132310245348U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 7139216143268029968U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8241544862261635722U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4735527016563596150U;
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5166171126690294033U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11117641762075368393U;
            aOrbiterH = RotL64((aOrbiterH * 4980156869201219393U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6312932356458415421U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterI = RotL64((aOrbiterI * 90744653170922319U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10085025354842771067U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16745854428789531080U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1945983905747274355U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2497187958708890337U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16069701876646548995U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16606039730973709495U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17242004368025978091U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12334315722243232121U;
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8007042082518126895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5665686359038811484U;
            aOrbiterD = RotL64((aOrbiterD * 11289316305875751813U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3913477186958600592U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16918984318564170343U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 5128293326494417281U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10227611546502931418U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7187623463085447228U;
            aOrbiterK = RotL64((aOrbiterK * 8479839369622163181U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 22U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 24U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererE, 26U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14343U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 13720U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14243U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15908U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15992U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 20U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + 11177787645248006236U) + aNonceWordA;
            aOrbiterA = (((aWandererH + RotL64(aCross, 42U)) + RotL64(aCarry, 29U)) + 3808340254579817169U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 23U)) + 828030667598518279U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 47U)) + 16177835921238398371U) + aPhaseBOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 5U)) + 5518747735458708741U) + aNonceWordD;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 51U)) + 17346319082399995165U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 13U)) + 6397156921893030937U) + aNonceWordC;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 15559381654710713582U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + 940404446491415088U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8047166032048732645U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4688468645859470491U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14383536431614496369U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3710878044770337260U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 116343189456629220U;
            aOrbiterJ = RotL64((aOrbiterJ * 5637725064169289339U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 883908030159391659U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 18058691521694880482U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 3132200449123497619U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17521015077103586117U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3668332225435714918U;
            aOrbiterA = RotL64((aOrbiterA * 12658899101297839881U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12229480388278883300U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16206524049491531816U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11122340196620859805U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5743265849441077466U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2812293020719282236U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 8903956475200417109U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13718364781538837074U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 861529717259766236U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17019744777211266685U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4862687502126693872U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7722024283321020761U;
            aOrbiterD = RotL64((aOrbiterD * 18086944039541060829U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8205803118233399853U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15130160926615050422U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 1454552751453996765U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 24U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererH = aWandererH + (((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 19U)) + aNonceWordG) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 34U) + RotL64(aOrbiterA, 52U)) + aOrbiterC) + aNonceWordB);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + aNonceWordF) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16780U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 19995U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 17834U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19653U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((aIndex + 17578U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 34U)) + 4204560462077827182U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 6572370199668594039U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 15958999876732622825U) + aNonceWordL;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 9969349486879280377U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 15450238998293956181U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 3U)) + 9128619863683138259U) + aPhaseBOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 12U)) + 5691270563628979565U) + aNonceWordP;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 21U)) + 5901029710568933106U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 51U)) + 10442738941988588834U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3508116020325721993U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13221917083569767259U;
            aOrbiterI = RotL64((aOrbiterI * 6845108555710135357U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11627915460377128176U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17858261365514253433U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 7535577636975884641U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4294837988806295989U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11242915481585070249U;
            aOrbiterG = RotL64((aOrbiterG * 17540688242763829319U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13030663829236027109U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7451948220723185149U;
            aOrbiterE = RotL64((aOrbiterE * 5191778587712222029U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5575508866505031037U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5161096033789876794U;
            aOrbiterD = RotL64((aOrbiterD * 16843827915802461797U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3980482740649505122U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11188906150207270241U;
            aOrbiterH = RotL64((aOrbiterH * 408550837615188413U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4435504916461645189U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9970252853543702833U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5829143716916091997U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3766347619186305854U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11004616087340082895U;
            aOrbiterC = RotL64((aOrbiterC * 14469267845747063735U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17600791542296175812U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2556224430252009744U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 14469426539907112137U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterK, 58U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + aNonceWordF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 22U)) + aOrbiterF) + aNonceWordH) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 29U)) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterI) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22640U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((aIndex + 23671U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26289U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22999U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23922U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 57U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 34U)) + 1866656689936219099U) + aNonceWordE;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 11U)) + 2312314528139448289U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 3554037526469185237U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 23U)) + 405707755060974111U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 27U)) + 1862976326004007697U;
            aOrbiterB = ((((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 43U)) + 12992483065443288263U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 3793854946371595197U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 19U)) + 4244007978867369382U) + aNonceWordL;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 39U)) + 10280867500312580308U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 472563452959164242U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12041770406895816553U;
            aOrbiterJ = RotL64((aOrbiterJ * 17811798500132002631U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6118634015704900486U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13637107920449233307U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16673735670669318830U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8602681273646630496U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7683264695930369476U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9146674871199188218U;
            aOrbiterH = RotL64((aOrbiterH * 7403427067419261981U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3012935612827493084U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1259789268731661945U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2372843620327050137U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5623690455471160780U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18355567776031865462U;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7705134893833304792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4435192506444773834U;
            aOrbiterA = RotL64((aOrbiterA * 5249651218395299501U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6204683785806409075U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17886971535016484255U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6047216474762933535U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4430578901091376829U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 607557685798141547U;
            aOrbiterC = RotL64((aOrbiterC * 12342665567201483107U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 38U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aCross, 34U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 42U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aNonceWordD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterI, 46U)) + aOrbiterE) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27853U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 27955U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31327U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29596U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 29672U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 34U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 24U)) + 9751314027302668907U) + aNonceWordN;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 12175450995523107056U;
            aOrbiterI = (aWandererB + RotL64(aCross, 57U)) + 17519694958730119552U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 13U)) + 9093525527925682263U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 53U)) + 3713831321786810138U) + aNonceWordJ;
            aOrbiterA = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 10108355209191835040U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 6U)) + 12956307447311314768U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 1904298513945877359U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 47U)) + 4658049993308574460U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9826333658248851902U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12058666914724365134U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 2516574707110528099U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13335308331049750235U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5880227828760598587U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8230749255538495304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16536559486797811486U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 7097036838156464969U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12387639130570188998U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8459259798142872020U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 8001346480955847013U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16083784052002800300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1957284290736468379U;
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7349538179311335863U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16395170077006105258U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4230485452156662763U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3317652065873784068U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5517155804799120700U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9789270651974719183U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5568525912112200094U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9334250662962319598U;
            aOrbiterD = RotL64((aOrbiterD * 5034887614541768961U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5641394627075994165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13524971148931512745U;
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 60U)) + aOrbiterH) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterB, 54U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + aNonceWordE) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
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

void TwistExpander_Fencing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFE78961517A3CEBFULL + 0x8DDAF7FF7092B3B5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDF3A7A884F0B9909ULL + 0xF4028CA8D4405BBAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x905E88DEAF1C803BULL + 0xFECE5993B668F7B4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9AC6011394303B9DULL + 0xB0C7B4141FD9A4AFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC4744157F3531B03ULL + 0xE85C42DB4A96EC82ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFC595EE456459A1DULL + 0xA9B9188419618BC8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAB47530B872DF941ULL + 0xFE91FCB924F8ED83ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAD258F15D14898B7ULL + 0xDA725A1AD921897FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9EA78F517EBCBFBBULL + 0xCC227C1655B24D05ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFB3A470432080E4DULL + 0x9121DC97C07C4910ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB74BF8DE565F1869ULL + 0xBCF7CB637491E1F1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAD7D417D41A4C64FULL + 0xD376FF9F5F16F256ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF72F5CB9877026F3ULL + 0x867CE4E77CA634ACULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF7BD0B08F76B49EFULL + 0xC1F5AD5EF5046948ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x83BBB5070CF88623ULL + 0x99261D3031ABF8E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCC21FBB18DA2EF45ULL + 0xB3664C67250CF571ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1647U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 1945U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 1671U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2570U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4120U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 3008U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 41U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererD + RotL64(aScatter, 39U)) + 13960289014350612206U) + aPhaseDOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 5U)) + 3483331015269589730U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 6873299241002444518U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 3U)) + 3562094007125534229U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 51U)) + 11422367439932782705U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 29U)) + 532453428514259816U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 17810941465810193088U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11869759058631106331U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8837581071876177566U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15329827515970522213U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17185378327053837778U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7578253375676981500U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13371647568758721729U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17112646434432814442U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14949096407295697881U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4259590620758467836U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6534899413644542303U;
            aOrbiterI = RotL64((aOrbiterI * 7987609419215568661U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 2637407498893694243U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15819295597921425711U;
            aOrbiterJ = RotL64((aOrbiterJ * 5202015597375051399U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6373559542002699718U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3308736483775453062U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12749929710650475901U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 248428400724560945U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aNonceWordF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 47U)) + aNonceWordG) + aPhaseDWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 22U) + aOrbiterB) + RotL64(aOrbiterI, 27U)) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 46U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 51U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8187U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 5950U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7217U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9593U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6590U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7356U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 6215U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 17454559218352016650U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 11U)) + 8005709669325164803U) + aNonceWordL;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 13393741948412816357U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 29U)) + 3665865624348875553U) + aNonceWordE;
            aOrbiterD = (aWandererF + RotL64(aIngress, 23U)) + 8334142570031883436U;
            aOrbiterE = ((((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 17226066128706139657U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 48U)) + 3319093033121522613U) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6657535603401588798U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5469746182326331147U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11315450342347794329U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17846791786050221418U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15939541003714896288U;
            aOrbiterD = RotL64((aOrbiterD * 1400351482213119809U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12076763190461077406U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3594038213596405284U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10244002692575821495U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8301291631324464622U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8460406137668390582U;
            aOrbiterH = RotL64((aOrbiterH * 9117147929757711595U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7612394867020871200U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 8525076134853103975U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 5790440201072204659U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11929899088215090379U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7119509166360685726U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 1662341427992528823U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5081078459225240607U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17149991983909906705U;
            aOrbiterE = RotL64((aOrbiterE * 950223374568067343U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aNonceWordH) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 58U)) + aOrbiterG) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15019U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 11657U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12171U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15986U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11273U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 27U)) + 16651241552253078315U) + aNonceWordC;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 50U)) + 4558144676982478003U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 41U)) + 8814884320080367550U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 16011579668555672117U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 35U)) + 4738918668759862438U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 12526083125540985108U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 8048723561746000552U) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1082218464034639039U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8432043246965946816U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7801965585991025451U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9982080524048636852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6720069955755215919U;
            aOrbiterA = RotL64((aOrbiterA * 1025046364205332059U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1019035028070247757U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7360619079463870467U;
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10893918488381348474U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1390297670907738019U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 11909657437658597735U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12512200589031203480U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14741471280748399540U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 3012135242889901095U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8543897248359826770U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8545972622733791272U;
            aOrbiterK = RotL64((aOrbiterK * 11793879362775346821U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 7049384618581928664U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14730773807906925408U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10711566871536755073U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 42U)) + aOrbiterF) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 28U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 19U)) + aNonceWordL) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18827U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneA[((aIndex + 17109U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18016U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20032U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17173U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 4U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 23U)) + 7651355040951791298U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 47U)) + 13988210277931659312U) + aNonceWordE;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 12U)) + RotL64(aCarry, 51U)) + 9846849412579537783U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 53U)) + 12746719939495876158U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 11498066185182895284U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 11101058955193080232U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 29U)) + 15513734459555672046U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15711108675349394643U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4771231759949468556U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 9806191054594333615U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11449258010811305256U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17036938391509986723U;
            aOrbiterJ = RotL64((aOrbiterJ * 7411466953205347639U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 6999245666776654250U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2106819066263369528U;
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12716183358903477216U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16752724547046059889U;
            aOrbiterK = RotL64((aOrbiterK * 11475905692393034141U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17623077680983093163U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6726003022297274986U;
            aOrbiterA = RotL64((aOrbiterA * 14709385877103232653U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2842410225096524740U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9235178377537910514U;
            aOrbiterE = RotL64((aOrbiterE * 11813751114775673845U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2619888019860844610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6295481948199619613U;
            aOrbiterI = RotL64((aOrbiterI * 15429161806953951205U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterF, 42U)) + aNonceWordO) + aPhaseDWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 37U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 27261U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneB[((aIndex + 24275U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22610U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23355U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22675U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 17225673071833726819U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 5U)) + 10301458382103627331U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 42U)) + RotL64(aCarry, 11U)) + 3960233050857362414U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 17768665685046605837U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 11U)) + 14471018461213959767U) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aCross, 23U)) + 10730597892721340453U) + aNonceWordM;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 57U)) + 14863394003122760542U) + aPhaseDOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9948587274816688296U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3573569431435100993U;
            aOrbiterE = RotL64((aOrbiterE * 2303922230056523077U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8153670675740450590U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16438856577722561424U;
            aOrbiterC = RotL64((aOrbiterC * 4689247488336908827U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15765587867581925041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1082039522061775213U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4202521649260798876U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15877659681260461141U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11369910758551088173U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2551560426129646123U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3005102326163906320U;
            aOrbiterI = RotL64((aOrbiterI * 4241583192662435107U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1675501058857208089U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12774812270956702043U;
            aOrbiterB = RotL64((aOrbiterB * 5488437008504905105U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 1044886020922563597U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4857445127457225171U;
            aOrbiterK = RotL64((aOrbiterK * 13223560654459705259U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aNonceWordB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterK) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27762U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((aIndex + 29396U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30359U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28716U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 29669U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 9630214189402543339U) + aNonceWordN;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 29U)) + 4072576573737526819U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 15994787452709618869U) + aNonceWordP;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 6403240137132259482U) + aNonceWordF;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 19U)) + 10229266900170507720U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 5025294577989748989U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 38U)) + 16696461238217956883U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9878318855341719119U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16086635438116177346U;
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12295437783084203730U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7681150419912842402U;
            aOrbiterI = RotL64((aOrbiterI * 7289497379725191451U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 2639104034287637448U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12298170009332243573U;
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3485932317267669626U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16569551670038752475U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4448490103784103954U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14510534073046885941U;
            aOrbiterK = RotL64((aOrbiterK * 7777192047386438305U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4286195398675733451U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15790355933840266463U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13342257823027075501U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6362891510370156055U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15121822034579983174U;
            aOrbiterG = RotL64((aOrbiterG * 7268045994574844937U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 10U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 12U) + RotL64(aOrbiterG, 37U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Fencing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF8D1C8C2AFA460DFULL + 0xEBADA19E1CE964D5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE6BA8B44DFE6E815ULL + 0x9917FF1372A6A563ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAF3EAB686FAF802BULL + 0xF5663D968A12027FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDC7C690A6B604C83ULL + 0xD090CE1B540DF813ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC809B33F44735447ULL + 0xE604794F62B2B97CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEB8025CD6B98FF6DULL + 0xE74569A3128E23C3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDF59EAF6FAA2158FULL + 0xC8DC2DD277CC7782ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF093FDA2ACD4CDD7ULL + 0xDEE31CC0928BCA4AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB212C719AA48A15BULL + 0x96AEDD5C4F1C758CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFDF09BF21928EC2DULL + 0xDB5CFF00FAC2621CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE925248903CEC15DULL + 0xB57BFC8C5684DE63ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x979FFD965AE04BFFULL + 0x9C12C49A61655EFBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFC0AA439C01206DBULL + 0x8A467E929909AD24ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xECBB83A543B4617DULL + 0xC6D6490B622E9EEBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8D9B75763BCB9869ULL + 0xDF279900E0C1C51DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF15F9288F1037DDBULL + 0x9AFDC9A31E059530ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5086U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((aIndex + 1743U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4407U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4863U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2981U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2050U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 58U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 7825479804710770560U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 51U)) + 5298124167101358123U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 17774541024369233726U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 48U)) + 7679371833537454082U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 57U)) + 5385914900748772224U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aCross, 41U)) + 3879781930908486531U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 659110346638873236U) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 43U)) + 10749021728538539749U) + aNonceWordK;
            aOrbiterB = (aWandererC + RotL64(aCross, 34U)) + 3631252455767429457U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 11U)) + 2271978810960685021U) + aNonceWordL;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 21U)) + 5963558780692551176U) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 974909966119198104U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9296998242911152296U;
            aOrbiterF = RotL64((aOrbiterF * 2613629915877957661U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2245318466901521959U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13391076374843288568U;
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6184487746594236737U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1563385912137291418U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4805455299959232321U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1744840092006498629U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2100927276837188416U;
            aOrbiterG = RotL64((aOrbiterG * 3541788262067077997U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9998911862807246338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12239948725635220096U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7098620484129489129U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3307447094994950246U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12746613971448298932U;
            aOrbiterB = RotL64((aOrbiterB * 9463975886346934681U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11577488293733790649U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 191108997585598809U;
            aOrbiterA = RotL64((aOrbiterA * 9574978681405356871U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18096145693841273722U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10026281133603934071U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17261343107314203471U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2346682418062064668U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2996178204018644206U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2552965800703390909U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15085425896818988223U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1589593231782852588U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 1535556765195388675U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17170695588248383518U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7825479804710770560U;
            aOrbiterC = RotL64((aOrbiterC * 7434218282170150533U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 36U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 18U)) + aOrbiterF) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 24U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9136U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 7653U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7828U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6921U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10776U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6160U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 8402U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (((aWandererC + RotL64(aIngress, 43U)) + 16124889768301047791U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aWandererB + RotL64(aCross, 21U)) + 11912338587186717280U) + aNonceWordP;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 39U)) + 8594012868813114354U) + aNonceWordB;
            aOrbiterE = (aWandererG + RotL64(aScatter, 19U)) + 18281043566156682815U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 16853106130200942302U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 12U)) + 2611212958619673086U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 18039472325066855180U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 14495785571345122046U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 23U)) + 4556063793412832418U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 5U)) + 14896419970271244358U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 56U)) + 880028529183500036U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2379557167489415783U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11854373946064529806U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1487252775956449964U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 12777924204511625545U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1366019527386994789U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15998631485222477969U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8864212892296191613U;
            aOrbiterJ = RotL64((aOrbiterJ * 579242788050369815U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17069347835763226743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7443008171694679791U;
            aOrbiterH = RotL64((aOrbiterH * 748894368884566607U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17334256152350782002U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8986626119086556393U;
            aOrbiterB = RotL64((aOrbiterB * 2258172145924120235U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8528180968228358674U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12702290928064582589U;
            aOrbiterI = RotL64((aOrbiterI * 15673603224146737631U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7742438100860023610U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3729687240959702198U;
            aOrbiterG = RotL64((aOrbiterG * 3756794766163746783U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 426129097367382096U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16782175452274911213U;
            aOrbiterK = RotL64((aOrbiterK * 1041477289638333659U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5942016166948841079U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5260815086125551703U;
            aOrbiterE = RotL64((aOrbiterE * 1603799103692438147U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11732742583346900772U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17182924380693084401U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14858685629471497071U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8539335803784852017U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16124889768301047791U;
            aOrbiterD = RotL64((aOrbiterD * 6607245691919237755U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterE, 6U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 50U)) + aOrbiterH);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 51U)) + aNonceWordC) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 37U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 27U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15624U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((aIndex + 14549U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12107U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11215U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11894U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 27U)) + 6467297102954816305U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 4U)) + RotL64(aCarry, 11U)) + 7921154109831114952U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 5701131763215638919U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 10022999076719002684U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 47U)) + 4367135243038982316U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 19U)) + 14445846824810383592U) + aNonceWordE;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 37U)) + 7683697954545773253U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 43U)) + 17517006750428030899U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 10U)) + 2052484792684025476U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 21U)) + 6279463052085808926U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 23U)) + 679280153651813684U) + aNonceWordP;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2939516520188460569U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1960616434964712325U;
            aOrbiterG = RotL64((aOrbiterG * 15145998415466343039U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12273819390719947361U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5685033154709449397U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 9845666295874714959U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9314494172199500653U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15757631834636427621U;
            aOrbiterH = RotL64((aOrbiterH * 15483543888965744529U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10878078046389399574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3583495913766365232U;
            aOrbiterE = RotL64((aOrbiterE * 2913540984990155225U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7385544065754622301U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16839599460207922881U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 240651605910592561U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13038163804940349251U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2587538594933924000U;
            aOrbiterF = RotL64((aOrbiterF * 3091149760401278671U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13109518583364738004U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2447689055742474261U;
            aOrbiterK = RotL64((aOrbiterK * 12100180201235703193U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5752044906692668618U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6637725371036522120U;
            aOrbiterA = RotL64((aOrbiterA * 6021986525167161115U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16549229877442298618U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12825651879441561108U;
            aOrbiterI = RotL64((aOrbiterI * 9079931351967033993U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16088338999978085987U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12584648360998154782U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2109996837220975261U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7526256599938771686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6467297102954816305U;
            aOrbiterB = RotL64((aOrbiterB * 9289442676936248653U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 22U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 4U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererD = aWandererD + ((((RotL64(aCross, 26U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 34U)) + aOrbiterK) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19699U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((aIndex + 20984U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18385U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21572U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((aIndex + 18294U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 19U)) + 9220392006207660113U) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 11305018553489132882U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 6U)) + 5860373868073513684U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 53U)) + 12319586170883987589U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 14072333614354649021U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 57U)) + 9332158529453194608U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 3860569321145958686U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 35U)) + 8119005668901240093U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 13918259792880333239U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 22U)) + 6938856216758228704U) + aNonceWordL;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 37U)) + 3960905839118710604U) + aNonceWordM;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6043879193734253929U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15691425268831319195U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14912209933584715274U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16180183395910618923U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3942858974766467849U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4966642362507707776U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6962226782462822861U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3647802407741095419U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12409120845092026295U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2302946450253872465U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 7099576330777297911U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16118304388937163838U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15968419034359049422U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 11736207775827080165U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17098982091525008231U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10298979200690822062U;
            aOrbiterC = RotL64((aOrbiterC * 12620028874653521945U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 552826643694256437U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11786560990790695378U;
            aOrbiterI = RotL64((aOrbiterI * 11190309640069208311U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13730399230389329793U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17614226859252305432U;
            aOrbiterK = RotL64((aOrbiterK * 2640019643570222977U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1062738267846296283U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13959480457644980835U;
            aOrbiterF = RotL64((aOrbiterF * 1194145909157002977U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4635071137794189167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13374502212707796180U;
            aOrbiterH = RotL64((aOrbiterH * 129680788767298945U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11479902881487238033U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9220392006207660113U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 1437457810224888809U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 34U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 38U)) + aOrbiterG) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26512U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 23131U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23867U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23178U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23260U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 26547U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 38U)) + 1708250618750199233U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aIngress, 51U)) + 12009147777553691142U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 41U)) + 8393982703399156592U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 35U)) + 3247327098356831221U) + aNonceWordJ;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 3403590155376353737U;
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 18197244558104735044U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 3096253642040701606U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 5U)) + 8012692688785412179U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 21U)) + 17531946907545680745U) + aNonceWordI;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 47U)) + 17687695944270225817U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 56U)) + 16147773866007628769U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18244641303026196497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8839160526348897457U;
            aOrbiterI = RotL64((aOrbiterI * 14268021129087663397U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10599266240854068246U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2056723540756216155U;
            aOrbiterB = RotL64((aOrbiterB * 13311591601230386375U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4629354220460621284U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9505955649473204942U;
            aOrbiterK = RotL64((aOrbiterK * 17775391885312236187U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17078153810088721310U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9470436761716263000U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 5431855497250357229U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3305863413630104742U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14377172434239576161U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 6880176890091033423U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 415687827894226513U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16975319836893760993U;
            aOrbiterH = RotL64((aOrbiterH * 6597144958013976445U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12707054129431596074U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8974182792497231239U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7874658957269462717U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10826131924322955095U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4168545139712703154U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10305904857550051705U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4539070253658625193U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3737870219498561326U;
            aOrbiterE = RotL64((aOrbiterE * 13130847633918921393U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11563084648810555040U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7410695535361901473U;
            aOrbiterA = RotL64((aOrbiterA * 7540855656023807389U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6687453696858775037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1708250618750199233U;
            aOrbiterF = RotL64((aOrbiterF * 13104250803527718135U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 52U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterD, 39U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterG, 52U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 22U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterH, 54U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32160U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 29756U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31653U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27544U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28389U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 11U)) + 8975885703279267062U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 37U)) + 8664844915562660637U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 26U)) + RotL64(aCarry, 37U)) + 12281774799736296726U) + aNonceWordF;
            aOrbiterA = (aWandererD + RotL64(aCross, 47U)) + 15347461352311329726U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 12967500561828907834U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 43U)) + 5002833859280402726U) + aNonceWordP;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 43U)) + 11908257536954668983U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 5U)) + 17017174811949227162U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 57U)) + 16851323125613931180U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 21U)) + 13469326957728686706U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 41U)) + 5228638551056105241U) + aNonceWordK;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11945166198089308564U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16268645041872996022U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5391448793718370911U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14781204627695095701U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5365325354838101092U;
            aOrbiterB = RotL64((aOrbiterB * 8017284997946310807U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 563147416025715953U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14660867395395625851U;
            aOrbiterK = RotL64((aOrbiterK * 4769458126865307103U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3168989056355712105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16179131669773665579U;
            aOrbiterH = RotL64((aOrbiterH * 5641461617066671723U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4160220074225527179U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8597134686962559111U;
            aOrbiterE = RotL64((aOrbiterE * 639572585431474015U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16811551552456811661U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5827323970423386301U;
            aOrbiterD = RotL64((aOrbiterD * 9328247349730652021U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15583234353262170227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2950816254621717748U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1102417597476170143U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4426165025104306337U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11871220132164971152U;
            aOrbiterG = RotL64((aOrbiterG * 2366168050042802207U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3832424136113939717U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17673885217916768611U;
            aOrbiterI = RotL64((aOrbiterI * 10887063696370811871U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3479289844909914390U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9498461576098567546U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8734492074299676555U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10645314291190544864U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8975885703279267062U;
            aOrbiterA = RotL64((aOrbiterA * 16584086014947250551U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterG, 60U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aCross, 30U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterC, 30U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Fencing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBC2C4BBAE860670BULL + 0xC007C3DA2E58626FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8493A6C71B9AF74BULL + 0xC3C82DA78FE828A9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9D68494C74728391ULL + 0x8D52048D5C2BA995ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF717E9A7108AE589ULL + 0xBB3E16B58233F182ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA7FB084D3ACDED43ULL + 0xE9620DE9B6BE9045ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEBC3884A2D74837FULL + 0xCF72FB9F1ABFB61AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xABC4FB1BEF44B2C9ULL + 0xD59C26B885FDA575ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB8F5976DF0650269ULL + 0xCE4B348378B7CD87ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8E41B1B9FEA51179ULL + 0xE31F96F61E7FC257ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB630A442AD7B04B1ULL + 0x9E2A4403E4442884ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x88312004EBA46CF5ULL + 0xB7E91685F704BFC3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xACEECF202496604FULL + 0x955FBA3E7D39B853ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA1EAE81CB1EB08EBULL + 0xD0B808A5E6F3BDCBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD2E78E42E6B7A2A5ULL + 0xB73814C28784E437ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEB69249F29A03209ULL + 0xEA13637CD052FE65ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDD2CDD2FBC5AFFD5ULL + 0xBEA84B5A500F6A0AULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneD, aSnowLaneC, aInvestLaneB, aWorkLaneC, aSnowLaneD, aInvestLaneD, aExpandLaneA, aSnowLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 770U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 5030U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 5226U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 843U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2936U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3598U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 42U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 23U)) + 12692813903177772178U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 47U)) + 7112496446691277899U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 2112247138290568813U) + aNonceWordN;
            aOrbiterH = ((aWandererB + RotL64(aCross, 18U)) + 3699421080882855947U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 13761832028354380922U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 13U)) + 9243822514887600214U) + aNonceWordO;
            aOrbiterF = (aWandererA + RotL64(aIngress, 43U)) + 6863833516853046129U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 23U)) + 8863897995943098018U;
            aOrbiterD = (aWandererE + RotL64(aCross, 29U)) + 13346785686701467520U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15309543066305531619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17515530938817919111U;
            aOrbiterC = RotL64((aOrbiterC * 16625193986319048245U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 760493237816424254U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7282586354117620860U;
            aOrbiterB = RotL64((aOrbiterB * 2327153408185290635U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4129706068526969105U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7020175432730888755U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 10095158356907592239U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9102258982216515596U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10822031305361453690U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2036205056490578491U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12571477440964330246U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8436347026653095199U;
            aOrbiterA = RotL64((aOrbiterA * 17930734781213681573U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14214789872073941940U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12915911919403385001U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13161681603528031511U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15443240166233851298U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7311369180113240915U;
            aOrbiterJ = RotL64((aOrbiterJ * 13339195007946889423U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12976516224995960015U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7823308381434556721U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 502385172763861451U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4829417661664149137U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16306394751966719700U;
            aOrbiterF = RotL64((aOrbiterF * 5294376579588592157U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 10U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordD) + aPhaseFWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9383U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 6348U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8413U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9760U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8170U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5954U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 10724U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 58U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 23U)) + 9630214189402543339U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 14U)) + 4072576573737526819U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 57U)) + 15994787452709618869U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 6403240137132259482U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + 10229266900170507720U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 5025294577989748989U) + aNonceWordC;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 52U)) + RotL64(aCarry, 5U)) + 16696461238217956883U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + 9878318855341719119U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 37U)) + 16086635438116177346U) + aNonceWordH;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12295437783084203730U) + aNonceWordA;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 7681150419912842402U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 7289497379725191451U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2639104034287637448U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12298170009332243573U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 9397919591171238575U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3485932317267669626U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16569551670038752475U;
            aOrbiterC = RotL64((aOrbiterC * 8139802826402217631U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4448490103784103954U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14510534073046885941U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7777192047386438305U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4286195398675733451U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15790355933840266463U;
            aOrbiterA = RotL64((aOrbiterA * 13342257823027075501U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6362891510370156055U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15121822034579983174U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7268045994574844937U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13817341015719915628U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14113474087906143783U;
            aOrbiterK = RotL64((aOrbiterK * 12838910141533126059U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9988301252236121106U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11287477288382171758U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 4979297247881426383U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9491727010910328644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7961202721830514030U;
            aOrbiterI = RotL64((aOrbiterI * 16300364540313620767U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 10U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterA, 40U)) + aOrbiterD) + aNonceWordO) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 48U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 34U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aNonceWordM) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13249U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 15358U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 11085U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14394U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 15129U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 40U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 18191288703716505885U;
            aOrbiterD = ((((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 19U)) + 9824014524910417136U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 11953012029254917548U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 27U)) + 6297568011027199089U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 19U)) + 2576999400457367975U) + aNonceWordB;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 56U)) + RotL64(aCarry, 35U)) + 13176139160575558254U) + aNonceWordD;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + 9978408174563621810U) + aNonceWordC;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 23U)) + 16765834875061607142U;
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 16534507305459121344U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3114710944346151807U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10240517868726718592U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10721450637990777883U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16689590768796583952U;
            aOrbiterD = RotL64((aOrbiterD * 3046344179729901637U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2427422768928450209U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13495584061816457831U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6670984773768885119U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7058636403765106682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9897341853944713767U;
            aOrbiterK = RotL64((aOrbiterK * 14286816859999869231U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17749559755733386064U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12515645083926326659U;
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2625692458813609962U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10596240255026143019U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11605800195771080135U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12374290338067865540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1507386663796330249U;
            aOrbiterI = RotL64((aOrbiterI * 1210241080424446087U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9288099549484146726U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15159312464747000702U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 500055502081347757U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14998608679505446229U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17625038109437732009U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 14785862243019841689U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 37U)) + aNonceWordI) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterH, 30U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18773U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((aIndex + 18835U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16723U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18281U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19097U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 35U)) + 6342299552323486695U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 27U)) + 12692748514781367538U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 8202639945493229155U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 47U)) + 4439975701793231639U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 53U)) + 16774235182859553759U) + aNonceWordC;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 8764155413335405667U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 18U)) + RotL64(aCarry, 57U)) + 7167848811974967685U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 23U)) + 16768278912125334220U) + aNonceWordP;
            aOrbiterG = (aWandererB + RotL64(aScatter, 43U)) + 9090838954826296201U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7644075729758006298U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17326182797908071215U;
            aOrbiterD = RotL64((aOrbiterD * 2408330168749256075U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16158809721888137555U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8029938783858263694U;
            aOrbiterF = RotL64((aOrbiterF * 12628072435324195483U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8716553521415553404U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7012599977009208840U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13250558696578541499U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13705957059101025396U;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2796775206291902461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13741676263512390669U;
            aOrbiterE = RotL64((aOrbiterE * 10455782033465595947U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1691908360612389252U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4114939415206031540U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2797401802892718297U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2374911514440738727U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12377616933668803091U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2505164835116651215U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 681094033415259645U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13841322124900463362U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4210414203856902329U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18082983557580381338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15731122225678626778U;
            aOrbiterI = RotL64((aOrbiterI * 7785999919955613789U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 36U)) + aOrbiterE) + aNonceWordG);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + aNonceWordD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 35U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26386U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneD[((aIndex + 25267U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 23926U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24797U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 24214U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 47U)) + 12029393034357490020U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 4526754731580694987U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 11U)) + 17060419646421271853U;
            aOrbiterE = (aWandererC + RotL64(aCross, 51U)) + 4128488893837059683U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 21U)) + 12706894827547160110U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 12506324593645825056U) + aNonceWordP;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 12581344490649250025U) + aNonceWordO;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 30U)) + 14357032418199130132U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 41U)) + 15341977701796331249U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7086602307544733241U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12398300065276832486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18157408831225635333U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2499745046076601988U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7249361592814001829U;
            aOrbiterC = RotL64((aOrbiterC * 14597139848072319685U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3254456186337366437U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3472973415969046680U;
            aOrbiterA = RotL64((aOrbiterA * 14583566953969168353U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7905718972111691591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15941413652144021522U;
            aOrbiterD = RotL64((aOrbiterD * 3473779492962783565U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10583964125960308762U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13659925272340853715U;
            aOrbiterI = RotL64((aOrbiterI * 16708294803316630743U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9487054537489454887U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13287757570441887517U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17351439045329892107U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15279245465808571942U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12424999114621745879U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2274918760256527137U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13915392738892970475U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13797668053788805126U;
            aOrbiterE = RotL64((aOrbiterE * 13752161103680525317U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14344766585550401077U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 13727554194373146727U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17164450431362670223U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 52U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29139U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 32492U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 30831U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30308U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29522U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 42U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 3561491146322798260U;
            aOrbiterB = (aWandererB + RotL64(aCross, 10U)) + 7075025056181885339U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 9230910887904171613U) + aNonceWordL;
            aOrbiterK = (aWandererK + RotL64(aScatter, 3U)) + 4119781172609908917U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + 17155609083870983149U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 2423018561430181695U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 35U)) + 12957280305617615744U) + aNonceWordI;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 2461704174772065813U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 14U)) + 7907123257849391997U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7257868138318960007U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16425903703085702285U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7996935869077231999U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2990822664594079467U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5654819006718953817U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12183676471235678779U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15026286960542123922U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17199049329995315279U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12169080607071830522U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2906296852254787499U;
            aOrbiterK = RotL64((aOrbiterK * 6754514406846040163U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3029858695410344584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14406410317495954566U;
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11048818178401163861U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13622063920319445043U;
            aOrbiterJ = RotL64((aOrbiterJ * 2516025554421589857U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2642646089141233277U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12761571777929273548U;
            aOrbiterA = RotL64((aOrbiterA * 5518252696078700127U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7753802695131502382U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8510425459525030222U;
            aOrbiterC = RotL64((aOrbiterC * 12412361423636026483U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13522645164493316722U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1437430302489702713U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14019316635365783545U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 20U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + aNonceWordE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 6U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 28U)) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Fencing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC8ED0397BEFEA3BULL + 0xAB30C8DFC0C7D5D7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDE7B37DDD94E450BULL + 0xBA9A42AEE747A4C2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBC0D720A7C04ECDFULL + 0x883C156BF58E4967ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCCDA31117E11231DULL + 0xBA6F88E1B06E3E3DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDBD8F03E480AFB13ULL + 0xCD6E92A308BD9589ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9BBAEED6313F5101ULL + 0xDABA51E6494D7473ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB50073A3C6636E5DULL + 0xFE7C13FA681DE1F3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFA968B4F28F70223ULL + 0xE057130C1C9743CFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF63B36350F5B7C75ULL + 0x99D6589C0B16837DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBB220BE9B1A67BD1ULL + 0xECF265492143D7B3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF4B2AB1BDCE1F64FULL + 0xD090D3C20CCAD024ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF204AE8B70A53951ULL + 0x9050C5FBB927AEF4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x863683371FB7B8D3ULL + 0x8F1D4706900B08F9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA58422D85B0AC761ULL + 0xE96F00BFDFD4B2CAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9DE6B9338A42D8F7ULL + 0x917F992E9EFBCE7CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD58F615DEF558657ULL + 0xB08F2DD75433B01CULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneB, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aFireLaneB, aInvestLaneC, aWorkLaneB, aFireLaneC, aExpandLaneA, aFireLaneA, aExpandLaneB, aInvestLaneA, aExpandLaneC, aInvestLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 82U)) & S_BLOCK1], 34U) ^ RotL64(aSnowLaneB[((aIndex + 2842U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 658U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2577U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 953U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 4729U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 28U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 10726035965553989335U) + aNonceWordB;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 50U)) + 967354339530195662U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 3U)) + 10834593005478605624U) + aNonceWordC;
            aOrbiterF = (aWandererJ + RotL64(aCross, 11U)) + 1012888282838656933U;
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 15283530351725183253U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 11724495956731703750U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 29U)) + 4288330117317505776U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10894778070022873473U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15563886747621617467U;
            aOrbiterJ = RotL64((aOrbiterJ * 17884709931569040065U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11182488628562891937U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 10420140066310588580U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 13898299782819948719U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11775138062167543111U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16545391898578161683U;
            aOrbiterD = RotL64((aOrbiterD * 14588306527161321535U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1550144656312299266U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14903504853138279883U;
            aOrbiterF = RotL64((aOrbiterF * 8003033561266164387U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 309935535526750396U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13991265868040011411U;
            aOrbiterC = RotL64((aOrbiterC * 2887531132228588441U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1755976294857114222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2259275858478396846U;
            aOrbiterH = RotL64((aOrbiterH * 7416165760067878161U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4838175912944552936U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12307900457200936013U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 14719363144850838805U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 12U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordN) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterD, 21U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 54U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + aPhaseHWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6774U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((aIndex + 9585U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8722U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneB[((aIndex + 7027U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9163U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7262U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 5515U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 7960325128608297381U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 51U)) + 12773836012104052042U) + aNonceWordK;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 43U)) + 3173972621347773016U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 21U)) + 3708401356314308171U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 950774285720019449U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 29U)) + 4170092315705438265U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 17000449130864980747U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8793910540062893860U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 520277969543516469U;
            aOrbiterG = RotL64((aOrbiterG * 4150613128885828229U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 12762214857389827271U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2932451184340207695U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7513337346940091655U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11062179998786293839U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7919119215271524178U;
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1774988449597115155U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3799792889466518953U;
            aOrbiterC = RotL64((aOrbiterC * 17512791286490623455U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1815062051307896589U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15260373951371654483U;
            aOrbiterH = RotL64((aOrbiterH * 2208604434669491625U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12867546628945676853U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 7772820973895846946U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 7581704643538761985U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14213957831821966834U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16561105721170419454U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 2540533987337175367U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 52U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 11U)) + aNonceWordF) + aPhaseHWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14479U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 14217U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14230U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11267U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11067U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 1866656689936219099U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 41U)) + 2312314528139448289U) + aPhaseHOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (((aWandererH + RotL64(aCross, 11U)) + 3554037526469185237U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 405707755060974111U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 20U)) + 1862976326004007697U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 12992483065443288263U) + aNonceWordG;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 29U)) + 3793854946371595197U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4244007978867369382U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10280867500312580308U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 13729899124177931289U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 472563452959164242U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12041770406895816553U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 17811798500132002631U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6118634015704900486U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13637107920449233307U;
            aOrbiterK = RotL64((aOrbiterK * 17712028184714868053U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16673735670669318830U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8602681273646630496U;
            aOrbiterE = RotL64((aOrbiterE * 6995213887710749241U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7683264695930369476U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9146674871199188218U;
            aOrbiterG = RotL64((aOrbiterG * 7403427067419261981U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3012935612827493084U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1259789268731661945U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2372843620327050137U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5623690455471160780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18355567776031865462U;
            aOrbiterJ = RotL64((aOrbiterJ * 9553862670107886679U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aNonceWordI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + aNonceWordO) + aPhaseHWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterB, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17904U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 21324U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16401U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16950U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((aIndex + 20455U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 52U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 12426357877879529292U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 53U)) + 12604900366173639176U) + aPhaseHOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 57U)) + 13511119007338929401U) + aNonceWordF;
            aOrbiterC = (aWandererC + RotL64(aIngress, 27U)) + 9878720081166788060U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 15463195409806395076U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 6407922778852833423U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 3U)) + 7690427254160734016U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18030974031722143619U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 17983938038322737041U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 12479365337221685413U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16605512170117753884U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 681802273302348322U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 14608920184802647123U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15550312921312083819U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17824154101711884508U;
            aOrbiterC = RotL64((aOrbiterC * 7358612830654795357U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1939207786756735430U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3132864634777826569U;
            aOrbiterD = RotL64((aOrbiterD * 13606281919426730325U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12822929773923954849U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16576106045887115660U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 16370914370769903051U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2398825881649235260U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13700821892926092479U;
            aOrbiterE = RotL64((aOrbiterE * 10830623703416956043U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2439833784883391606U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15870638514107637833U;
            aOrbiterH = RotL64((aOrbiterH * 3797380922767479287U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 46U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aNonceWordN) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aIngress, 50U) + RotL64(aOrbiterH, 14U)) + aOrbiterI) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26937U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 25276U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 26762U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25166U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 26627U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 26U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 12849591986267890852U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 8232614804696815750U) + aNonceWordE;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 5U)) + 12141567259210877281U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 2928641981037885644U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 44U)) + 980733350554783938U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 23U)) + 2683985177993350746U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 13U)) + 14532148403815527355U) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7736296629433884203U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10428437770166310549U;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 18327174144859461029U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6810436935194432002U;
            aOrbiterK = RotL64((aOrbiterK * 2715987179577753597U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12606153309690753435U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17123256945895150555U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13469111258504672565U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9057777759026189541U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16478485918911194442U;
            aOrbiterI = RotL64((aOrbiterI * 11054247078884894131U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 18064460487552100483U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11477276762421684083U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18318375441973295081U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13849305985380030986U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12962140243967824959U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10240409420338313641U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 18360586077779529086U;
            aOrbiterA = RotL64((aOrbiterA * 18196875422391501927U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 42U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 53U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 60U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32508U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 28070U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30291U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30927U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 29909U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (aWandererA + RotL64(aPrevious, 35U)) + 5573188770530340913U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 1431772230889897111U) + aNonceWordN;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + 4809192776429682319U) + aNonceWordK;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 3U)) + 5576603692574369341U) + aNonceWordC;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 21U)) + 2720143226007220386U;
            aOrbiterD = ((((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 17220328778565331629U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 9629485808442089423U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1136998437010390983U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11893390497814523841U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5329621622743089531U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1764986431917532370U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1741014798007010376U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 13414914086049500731U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12221368453236547044U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7694538641172350430U;
            aOrbiterI = RotL64((aOrbiterI * 8439120733670016501U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17472344518811560603U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3308740700728172984U;
            aOrbiterD = RotL64((aOrbiterD * 15290400462887712083U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9535358833412446771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11192312491731312451U;
            aOrbiterK = RotL64((aOrbiterK * 17405609148475445743U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14850451970047190039U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11932493299452443256U;
            aOrbiterE = RotL64((aOrbiterE * 7964808728820467795U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5972619895614731870U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17174497535809891690U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aNonceWordE);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterH, 44U)) + aNonceWordO) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Fencing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 497U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 108U)) & W_KEY1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2067U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 2225397913940961213U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 5U)) + 8342544893601343643U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 11U)) + 162922186381417187U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 19U)) + 11660218373710972210U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 23U)) + 14909034764605802354U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 57U)) + 16776955237009701511U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 5834487809188925253U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 14U)) + 1498492772767040320U) + aPhaseAOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 27U)) + 4161765458781579617U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10511923076962447765U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8575954471692620021U;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6536325446331340573U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1790628986900286346U;
            aOrbiterB = RotL64((aOrbiterB * 5262997114200816715U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2623814807619278590U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11676970995834706612U;
            aOrbiterA = RotL64((aOrbiterA * 10057461115132434901U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13836786354224256591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6293096163612129260U;
            aOrbiterI = RotL64((aOrbiterI * 8977954126326217153U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4271144764978661248U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15938494256992560202U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10004841288382726739U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11038155227307702976U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12408749795071243930U;
            aOrbiterH = RotL64((aOrbiterH * 5527720475032868855U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1673665849053496882U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12866353361497103629U;
            aOrbiterJ = RotL64((aOrbiterJ * 6041125499398924871U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10673935802381580966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8946776538955520352U;
            aOrbiterC = RotL64((aOrbiterC * 12293084177712710021U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16294935203370452805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4697759331563852212U;
            aOrbiterF = RotL64((aOrbiterF * 14407806317275373043U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterG) + aPhaseAWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 18U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4297U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5381U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4801U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 5263U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 54U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 47U)) + 6381335981879993247U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 19U)) + 15595429101600023172U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 5449234297249826461U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 37U)) + 11213734849329731168U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 23U)) + 16438473952464514248U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 7357872882115186976U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 4U)) + 394402075160738643U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 27U)) + 11112941985410283532U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 43U)) + 14955125011182736212U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14770727009821304070U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11286366598129204910U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15884310771003021989U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7358400908565425780U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15635109923749114761U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12415152149408700329U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13826842523738623579U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1072811298828325231U;
            aOrbiterB = RotL64((aOrbiterB * 9662800288646215083U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4017334196009350776U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8812213572751410831U;
            aOrbiterG = RotL64((aOrbiterG * 12744171921566782795U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6723457786170634403U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9785583533999417673U;
            aOrbiterJ = RotL64((aOrbiterJ * 7776915427605471097U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10265132640322153964U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8435670887514808087U;
            aOrbiterF = RotL64((aOrbiterF * 2706263045620662131U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4303823386961718326U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4214384238167491037U;
            aOrbiterA = RotL64((aOrbiterA * 8490707334221154005U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8740835037840799136U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5988815405391206280U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17838555472135715929U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15539461383052981747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3743772525784217714U;
            aOrbiterE = RotL64((aOrbiterE * 6352086797545969187U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterA, 10U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 28U) + aOrbiterF) + RotL64(aOrbiterJ, 42U));
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7268U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 6598U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5699U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5879U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7561U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 29U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 4U)) + 11177787645248006236U;
            aOrbiterG = (aWandererI + RotL64(aCross, 39U)) + 3808340254579817169U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 828030667598518279U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 53U)) + 16177835921238398371U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 22U)) + 5518747735458708741U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 17346319082399995165U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 29U)) + 6397156921893030937U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 35U)) + 15559381654710713582U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 940404446491415088U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8047166032048732645U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4688468645859470491U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14383536431614496369U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3710878044770337260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 116343189456629220U;
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 883908030159391659U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18058691521694880482U;
            aOrbiterH = RotL64((aOrbiterH * 3132200449123497619U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17521015077103586117U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3668332225435714918U;
            aOrbiterJ = RotL64((aOrbiterJ * 12658899101297839881U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12229480388278883300U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16206524049491531816U;
            aOrbiterG = RotL64((aOrbiterG * 11122340196620859805U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5743265849441077466U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2812293020719282236U;
            aOrbiterE = RotL64((aOrbiterE * 8903956475200417109U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13718364781538837074U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 861529717259766236U;
            aOrbiterA = RotL64((aOrbiterA * 17019744777211266685U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4862687502126693872U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7722024283321020761U;
            aOrbiterF = RotL64((aOrbiterF * 18086944039541060829U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8205803118233399853U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15130160926615050422U;
            aOrbiterC = RotL64((aOrbiterC * 1454552751453996765U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterB, 6U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 14U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8922U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 9804U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 10105U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8996U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8738U)) & W_KEY1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 9080U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 29U)) + 18255347001097480328U) + aPhaseBOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 13679246790311505735U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 38U)) + 10565839529765027116U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 11U)) + 14327172566224769901U;
            aOrbiterH = (aWandererK + RotL64(aCross, 51U)) + 16239024612038195174U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 5U)) + 13800012174212131890U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 18U)) + 13900288860157577583U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 4144386119777112740U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 3154558262670631372U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7456728543137614001U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11709519851158935384U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7016689518570071587U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15607438907832240304U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9276575329661725624U;
            aOrbiterI = RotL64((aOrbiterI * 8879744070762412745U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6459435969129449226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6442382118416542275U;
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12117432107282150865U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6831279293184793243U;
            aOrbiterC = RotL64((aOrbiterC * 2435360641135249073U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9520022957804572889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8322178689474588679U;
            aOrbiterG = RotL64((aOrbiterG * 1627707191467537115U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4162401591586869316U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8994015844714895961U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15421910378057951895U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10038095909727959633U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17756404450592957616U;
            aOrbiterF = RotL64((aOrbiterF * 14255952184627347295U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3379089265413427719U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11341713098678108441U;
            aOrbiterE = RotL64((aOrbiterE * 2500587373161411961U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4030296130743454165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6332387792111212064U;
            aOrbiterA = RotL64((aOrbiterA * 16490982218150897861U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 28U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 56U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterG, 60U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 56U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11432U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 12014U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12329U)) & W_KEY1], 24U) ^ RotL64(mSource[((aIndex + 12979U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10956U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12710U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 11996U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 34U)) + 9446153639709651566U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 10550762260670758167U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 7062634922142578383U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 5U)) + 9178499097812764515U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 51U)) + 6887103379773525538U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 39U)) + 6239750312052010257U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 47U)) + 17645022614523287959U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 43U)) + 3639618183259408272U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 47U)) + 3131737117548745095U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7253994382396406554U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15217993711938379561U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17853313384747259923U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12594152227603630033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11250170200489647869U;
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12936942656624279424U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10990736056052106149U;
            aOrbiterG = RotL64((aOrbiterG * 7123916809953459187U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12787293075893090465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17154990205620778151U;
            aOrbiterI = RotL64((aOrbiterI * 10031369940028159521U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1270827262969060301U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17337623431665013136U;
            aOrbiterH = RotL64((aOrbiterH * 1517262088236356107U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 830330490987911853U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6828309232554560547U;
            aOrbiterB = RotL64((aOrbiterB * 9742464176986145819U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11470087853413986203U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10470148870747884420U;
            aOrbiterD = RotL64((aOrbiterD * 6766079738799967443U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18315536891901859637U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12264670822285914271U;
            aOrbiterE = RotL64((aOrbiterE * 5841574505408674119U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10931842095884524879U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11134871340959676257U;
            aOrbiterC = RotL64((aOrbiterC * 11714837622285605745U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + aPhaseBWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 44U)) + aOrbiterB) + aPhaseBWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 20U) + aOrbiterI) + RotL64(aOrbiterH, 40U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14732U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneA[((aIndex + 15265U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15176U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15344U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14499U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14712U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 13887U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 6243113109470883144U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 19U)) + 3891552123999605832U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 8758797898587019128U;
            aOrbiterC = (aWandererE + RotL64(aCross, 27U)) + 1005891374086408851U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 23U)) + 3713426782180050764U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 5U)) + 18358143862391573534U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 17504394029693712404U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 47U)) + 5312729289027417014U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 12U)) + 2560873623431186029U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16309322822806704211U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10195513918020652600U;
            aOrbiterD = RotL64((aOrbiterD * 14569219741824123715U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2552116263258744287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7732784879810980089U;
            aOrbiterI = RotL64((aOrbiterI * 15041929399477790999U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16499127570665381507U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10890036715535519036U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9065115450010475187U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16288944603478791554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14542766121469312846U;
            aOrbiterG = RotL64((aOrbiterG * 8435383464425875209U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5973595239494084696U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1820492719977197097U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16164917159141304405U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10489529555776381736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6392552206958240484U;
            aOrbiterJ = RotL64((aOrbiterJ * 11761477994533503307U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10163241948999404556U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16054678853554707148U;
            aOrbiterH = RotL64((aOrbiterH * 10570418210789350091U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3606021702108590330U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16920568417324295852U;
            aOrbiterK = RotL64((aOrbiterK * 5222656554577625385U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13889995689147406315U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7908387312354285092U;
            aOrbiterC = RotL64((aOrbiterC * 7995682580514280949U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterB, 14U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 30U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18694U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 17680U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 18988U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19108U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17033U)) & W_KEY1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18644U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17240U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 43U)) + 13278949403988203974U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 12U)) + RotL64(aCarry, 5U)) + 9213599924054673756U) + aPhaseCOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 1255746482932381798U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 11575321997144516122U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 3U)) + 15881587525529432437U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 53U)) + 9846195809864862707U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 47U)) + 12319815691858217670U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 37U)) + 16322617427294439587U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 28U)) + 16332130810525887437U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4920951156015336794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16767126455124552329U;
            aOrbiterA = RotL64((aOrbiterA * 4440352337076842603U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12553595911087945223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1437522202135436142U;
            aOrbiterE = RotL64((aOrbiterE * 2001992794165550905U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12313100454852227143U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2761983020631055729U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3874839760378039509U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17635303588421554367U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 788212489507463763U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17896475584538528059U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5192552894670654434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6784748488807738811U;
            aOrbiterH = RotL64((aOrbiterH * 8077237651953896479U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16113417046719114943U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1096874945215225916U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17308604412622879833U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7610274704570171595U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10466070212284342550U;
            aOrbiterI = RotL64((aOrbiterI * 6449728258497920613U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6777845928873855221U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5251515022021984126U;
            aOrbiterF = RotL64((aOrbiterF * 9018277343404261611U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13849343158824111498U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7977711210181714021U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4182053966171053577U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 30U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 14U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21609U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 21278U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20565U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 20094U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20218U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19640U)) & W_KEY1], 27U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19983U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19577U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 41U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 12380376990224645149U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 18296928500297384014U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 30U)) + RotL64(aCarry, 19U)) + 3550626816361145100U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 3U)) + 2667792936946706027U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 13U)) + 12020969779370926953U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 737340727886903447U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 53U)) + 1681797651799760502U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 47U)) + 2956186342689489064U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 34U)) + 1876852870402977177U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6433205819353555071U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9065076854974222998U;
            aOrbiterC = RotL64((aOrbiterC * 5459675878087242021U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3254410578766789992U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2005081975473815576U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9947701153722014085U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15992999234834560419U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3458344156815120948U;
            aOrbiterF = RotL64((aOrbiterF * 1668460113964608051U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17069783053664877727U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1260234710193913099U;
            aOrbiterK = RotL64((aOrbiterK * 4561226779897414381U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3825186451876061335U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2905344294992827535U;
            aOrbiterB = RotL64((aOrbiterB * 2469896090698580795U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18141402347899180617U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8760129857609925066U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2507999156108123047U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 594052473780678210U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13216719212966128379U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10691355329696722303U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10029948739466316169U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11912428807431992996U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 85016510811938307U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8735634019801417287U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12785916159063273545U;
            aOrbiterE = RotL64((aOrbiterE * 1161917531260663357U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 58U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + aPhaseCWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterF, 10U));
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 38U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 21967U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[((aIndex + 22850U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22967U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24318U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23011U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22566U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22491U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21878U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 12849591986267890852U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 8232614804696815750U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 12141567259210877281U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 43U)) + 2928641981037885644U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 27U)) + 980733350554783938U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + 2683985177993350746U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + 14532148403815527355U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 51U)) + 7736296629433884203U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 18U)) + RotL64(aCarry, 13U)) + 10428437770166310549U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18327174144859461029U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6810436935194432002U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2715987179577753597U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12606153309690753435U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17123256945895150555U;
            aOrbiterJ = RotL64((aOrbiterJ * 13469111258504672565U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9057777759026189541U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16478485918911194442U;
            aOrbiterC = RotL64((aOrbiterC * 11054247078884894131U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18064460487552100483U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11477276762421684083U;
            aOrbiterI = RotL64((aOrbiterI * 3886501230380184395U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18318375441973295081U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13849305985380030986U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12962140243967824959U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10240409420338313641U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18360586077779529086U;
            aOrbiterD = RotL64((aOrbiterD * 18196875422391501927U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16801797158622424257U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4950305991208513887U;
            aOrbiterG = RotL64((aOrbiterG * 4437082499761416951U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15790878572843321918U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9808781805065559728U;
            aOrbiterB = RotL64((aOrbiterB * 9394280083159162953U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11974996650410830731U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4955004489435232515U;
            aOrbiterA = RotL64((aOrbiterA * 13301966529515483085U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 24U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterH, 48U)) + aPhaseCWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aPhaseCWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 6U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25541U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 26311U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26726U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 25422U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27168U)) & W_KEY1], 54U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25057U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26404U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((aIndex + 26846U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 38U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 37U)) + 4773124477323378268U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 43U)) + 16848723289435796005U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 29U)) + 13846642134917107058U) + aPhaseDOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 39U)) + 6472057872482789939U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 2747019500690707226U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 5U)) + 9003965289739733880U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 21U)) + 3013390651936257377U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 3331004709895625067U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 52U)) + 15355010435553517129U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7709870658004280052U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13568728443963926564U;
            aOrbiterC = RotL64((aOrbiterC * 6736090830113688981U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12409548853419307131U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 969183352023661537U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15370309834426476775U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3896803894396631184U;
            aOrbiterH = RotL64((aOrbiterH * 11018830202891911603U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10848873633291935766U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12885336509190543440U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1487357252619221365U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8252290890093788010U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9201553615601641350U;
            aOrbiterB = RotL64((aOrbiterB * 420321130559162915U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14014209645503188472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4015071464301844550U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17444195018239904971U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16173085647514027347U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16916627014974363360U;
            aOrbiterK = RotL64((aOrbiterK * 7699587344277490953U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1591680303404522110U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16499606051269327916U;
            aOrbiterG = RotL64((aOrbiterG * 814405848002794813U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6932673635509444619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8745681160108707944U;
            aOrbiterA = RotL64((aOrbiterA * 14565255558668084787U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 42U) + RotL64(aOrbiterI, 39U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterF, 24U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 30U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 36U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28323U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 27874U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27980U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((aIndex + 28123U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28620U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27671U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28065U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((aIndex + 28344U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 35U)) + 1557680213571812384U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 47U)) + 7387349725778021121U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 4U)) + 15379264067601586976U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 21U)) + 3730195724576043708U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 51U)) + 9637070085323827066U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 1170865717363676184U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 2750833653175252030U;
            aOrbiterD = (aWandererD + RotL64(aCross, 27U)) + 15118992811225568305U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 39U)) + 4974092922102988451U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10625719096296719514U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 855167122475471865U;
            aOrbiterI = RotL64((aOrbiterI * 7441090331293158773U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11322911068958340262U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4334591909425429835U;
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14263701737208936392U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 678723206735649084U;
            aOrbiterD = RotL64((aOrbiterD * 10823239851733632227U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15652053114252065230U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1705225940224061401U;
            aOrbiterA = RotL64((aOrbiterA * 3626023093533713579U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6826394665732900206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11902946775066981141U;
            aOrbiterK = RotL64((aOrbiterK * 18300629262162694137U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9802212958998591310U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14001358545610206524U;
            aOrbiterJ = RotL64((aOrbiterJ * 13172645840788327099U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4299184726135884309U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7288757011999872416U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16806027820468277393U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 233801262480580205U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14208660347238680268U;
            aOrbiterH = RotL64((aOrbiterH * 6299693448313154603U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9217797359740446104U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18165073197136050838U;
            aOrbiterF = RotL64((aOrbiterF * 11677479094709512887U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aPhaseDWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterH, 53U));
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32450U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32693U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31239U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32761U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31358U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32282U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 38U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 12980104182836602177U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 29U)) + 3172622203188863995U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 6U)) + RotL64(aCarry, 21U)) + 1170974132219980203U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 6035201940965047490U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 53U)) + 18033907118424996722U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 13U)) + 14604813424800580304U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 18U)) + 13720232492851066035U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 3902659710585257448U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 37U)) + 8331560652661619868U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4485014147538689794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 168202636924512424U;
            aOrbiterA = RotL64((aOrbiterA * 13711020666131492091U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16227825670092707848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4792781933944671365U;
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12636865372722601282U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18198291399585556632U;
            aOrbiterD = RotL64((aOrbiterD * 18155803890313399795U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3650053185419807206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5897288963905408776U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3706949366974086151U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9922308113622901726U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13352279749091561510U;
            aOrbiterC = RotL64((aOrbiterC * 4025213180483632557U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14969461950939646117U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10231661776135056651U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11284575051455238501U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10621934544068320859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6029116920305246887U;
            aOrbiterI = RotL64((aOrbiterI * 6087523725059376905U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12887482425168671195U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8351351557123783853U;
            aOrbiterB = RotL64((aOrbiterB * 3839381627914762245U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5405938210926464973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 385145802287899406U;
            aOrbiterG = RotL64((aOrbiterG * 8330751480464271445U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 18U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + aPhaseDWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 24U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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

void TwistExpander_Fencing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneB, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2020U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 1447U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 4105U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1115U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1069U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 5U)) + 3199575576585871314U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 2533378188975571824U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 51U)) + 6819782112558312658U;
            aOrbiterC = (aWandererE + RotL64(aCross, 60U)) + 12690060987724798497U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 7088375139715629606U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 17785618677423695666U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 27U)) + 1714999280296491277U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17611338506932491624U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6475727359297421201U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15133348244242438069U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2347744591204119530U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2739317903351401068U;
            aOrbiterA = RotL64((aOrbiterA * 15435029315209475631U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8663535261373274338U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8205245127823536479U;
            aOrbiterF = RotL64((aOrbiterF * 13857005110466856439U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8916510616749754516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3944805940148512932U;
            aOrbiterJ = RotL64((aOrbiterJ * 18082271583211389701U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14094751253118853302U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14094299829196076311U;
            aOrbiterC = RotL64((aOrbiterC * 6370012560657108493U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3940673811518673802U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3015106523254484839U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9655401190755573379U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15404103131982599922U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1828655763233900875U;
            aOrbiterK = RotL64((aOrbiterK * 13024358077740310049U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 50U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8251U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 7836U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 8969U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6541U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 8672U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 17081642665820489793U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 22U)) + 14468854040067229623U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 5U)) + 2249450222593057429U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 13U)) + 14964389079511378664U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 17003491054252360650U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 47U)) + 12710882240582032588U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 9887078182156755359U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7665284531810584704U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7304284015511876717U;
            aOrbiterG = RotL64((aOrbiterG * 6193179739025093929U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5517927023543751734U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17704756310857362759U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15826832172923213591U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11347400363019508578U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11696395232760991243U;
            aOrbiterA = RotL64((aOrbiterA * 9725231749679442003U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10875780291242873583U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7808740614343437672U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8889516201913716283U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3145390996141902032U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16080636485642732615U;
            aOrbiterH = RotL64((aOrbiterH * 7445756373012217305U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3929263288176983844U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 18210228766683996806U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13178080076505449091U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13948962323541421431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3037683309790156893U;
            aOrbiterF = RotL64((aOrbiterF * 13406672352222636739U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 44U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14033U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 14864U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 14842U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12932U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13408U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11131U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 36U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 29U)) + 16124889768301047791U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 35U)) + 11912338587186717280U;
            aOrbiterG = (aWandererI + RotL64(aCross, 51U)) + 8594012868813114354U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 18281043566156682815U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 16853106130200942302U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 18U)) + 2611212958619673086U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 18039472325066855180U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14495785571345122046U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4556063793412832418U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13166927543135467627U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14896419970271244358U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 880028529183500036U;
            aOrbiterC = RotL64((aOrbiterC * 14228281807461251361U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2379557167489415783U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11854373946064529806U;
            aOrbiterA = RotL64((aOrbiterA * 150755294320438887U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1487252775956449964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12777924204511625545U;
            aOrbiterD = RotL64((aOrbiterD * 1366019527386994789U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15998631485222477969U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8864212892296191613U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 579242788050369815U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17069347835763226743U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7443008171694679791U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 748894368884566607U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17334256152350782002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8986626119086556393U;
            aOrbiterE = RotL64((aOrbiterE * 2258172145924120235U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 28U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterA, 14U));
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17077U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 21042U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16995U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19990U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18985U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19579U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 28U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 10U)) + 17668251151213543491U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 16101602509895104517U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 9083915270773304935U) + aPhaseEOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 29U)) + 12810720730318214811U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 3U)) + 18113428002071925621U;
            aOrbiterC = (aWandererB + RotL64(aCross, 37U)) + 1582208899354109878U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 4180688104819188154U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8954598189262820611U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15360094153175355879U;
            aOrbiterF = RotL64((aOrbiterF * 8177798855402983685U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8383954114668216260U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15626783326234049197U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15058420415480073793U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10609978564404958066U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17656516608997517984U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4590620354119899777U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 760077259110786536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3597338735888033063U;
            aOrbiterI = RotL64((aOrbiterI * 6548831472863517621U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4431777844935985157U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10710423172154671296U;
            aOrbiterC = RotL64((aOrbiterC * 16267496318491473315U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10240882795242085185U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7826053487019825891U;
            aOrbiterG = RotL64((aOrbiterG * 15053729937684375907U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9418883403715727353U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11507423614799075545U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16189463984557044693U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 47U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22461U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 22662U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26326U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24871U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23690U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24500U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 36U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aIngress, 51U)) + 3621877681473089725U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 3U)) + 4451752751536414717U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 11371625415377772117U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 24U)) + RotL64(aCarry, 53U)) + 6046792758881150619U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 35U)) + 8213166120394461682U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 4343156661140422645U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 11105271483234947905U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 348904609985341372U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12924652822526858767U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2801892489296408735U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7461211697358520287U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16551553555297890558U;
            aOrbiterK = RotL64((aOrbiterK * 16432952324635746293U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11908056404140782995U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9147367258259948715U;
            aOrbiterH = RotL64((aOrbiterH * 10777628928376261667U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8876461054692728610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10546855952702525404U;
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4748636139110443794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 783046909529525098U;
            aOrbiterD = RotL64((aOrbiterD * 8969157702460927215U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16683965945838696665U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12385412690177109575U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10795062772707143187U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8210546822184469023U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13146493623236979963U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13199947810161148155U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 12U));
            aWandererE = aWandererE + ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 27U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30482U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 29857U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29354U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30603U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27769U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32239U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 3561491146322798260U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 7075025056181885339U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 9230910887904171613U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 4119781172609908917U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 51U)) + 17155609083870983149U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 35U)) + 2423018561430181695U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 60U)) + 12957280305617615744U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2461704174772065813U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7907123257849391997U;
            aOrbiterB = RotL64((aOrbiterB * 9416171962847312179U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7257868138318960007U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16425903703085702285U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7996935869077231999U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2990822664594079467U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5654819006718953817U;
            aOrbiterJ = RotL64((aOrbiterJ * 4465096036756887801U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12183676471235678779U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15026286960542123922U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12169080607071830522U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2906296852254787499U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3029858695410344584U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14406410317495954566U;
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11048818178401163861U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13622063920319445043U;
            aOrbiterC = RotL64((aOrbiterC * 2516025554421589857U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 14U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Fencing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aInvestLaneA, aExpandLaneB, aSnowLaneB, aExpandLaneA, aWorkLaneA, aExpandLaneD, aWorkLaneB, aExpandLaneC, aWorkLaneC, aInvestLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1662U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 2726U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 290U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2473U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2027U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 3543U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 18U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 5568146815535263910U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 47U)) + 7736084960873834666U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 54U)) + 1336413621817562093U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 5218462026934984692U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 7048890985969555935U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 35U)) + 13415955213864702118U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 3U)) + 5657023257021528548U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 11U)) + 14338310943137497116U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 28U)) + 12305161641833950473U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 57U)) + 14514226578370459131U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 51U)) + 12692904083266024340U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11012959130001327964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterC = RotL64((aOrbiterC * 515626559384817223U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3718101961355280891U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13364192077222322664U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6720867800318913440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14497243926965866546U;
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5789056168233262435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14438482587495779937U;
            aOrbiterB = RotL64((aOrbiterB * 10593535547917767263U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 313917798940179945U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15241845511889502917U;
            aOrbiterF = RotL64((aOrbiterF * 16483477103771326107U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3591957424821693032U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1559050939014453558U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17933346117866604725U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15340590914441451383U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5538037287390050110U;
            aOrbiterK = RotL64((aOrbiterK * 4082576643144951473U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4151270491894969214U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 263593701314144898U;
            aOrbiterA = RotL64((aOrbiterA * 10372046955804512457U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9025145270653080646U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6867950904094870056U;
            aOrbiterI = RotL64((aOrbiterI * 9975247022340627751U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3183454301841252109U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3054904157641290615U;
            aOrbiterE = RotL64((aOrbiterE * 4092317552439599475U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1768555574434776135U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5568146815535263910U;
            aOrbiterJ = RotL64((aOrbiterJ * 12466957001078663927U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 30U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 4U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6983U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 6803U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9260U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 6239U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8688U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7492U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10668U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 6342299552323486695U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 40U)) + 12692748514781367538U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 3U)) + 8202639945493229155U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 35U)) + 4439975701793231639U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 53U)) + 16774235182859553759U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 58U)) + 8764155413335405667U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 47U)) + 7167848811974967685U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 16768278912125334220U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 9090838954826296201U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 37U)) + 7644075729758006298U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 19U)) + 17326182797908071215U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16158809721888137555U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8029938783858263694U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12628072435324195483U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8716553521415553404U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7012599977009208840U;
            aOrbiterH = RotL64((aOrbiterH * 8775355876188948851U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13250558696578541499U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13705957059101025396U;
            aOrbiterB = RotL64((aOrbiterB * 16889495686487056367U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2796775206291902461U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13741676263512390669U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10455782033465595947U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1691908360612389252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4114939415206031540U;
            aOrbiterJ = RotL64((aOrbiterJ * 2797401802892718297U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2374911514440738727U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12377616933668803091U;
            aOrbiterK = RotL64((aOrbiterK * 2505164835116651215U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 681094033415259645U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13841322124900463362U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4210414203856902329U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18082983557580381338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15731122225678626778U;
            aOrbiterE = RotL64((aOrbiterE * 7785999919955613789U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2084336993254383330U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3600882019682875370U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2977569829649654329U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11436602278656592334U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5775886971784627864U;
            aOrbiterD = RotL64((aOrbiterD * 6765942246225582787U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17120308925134658794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6342299552323486695U;
            aOrbiterG = RotL64((aOrbiterG * 5788669985396507227U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 24U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14230U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 12663U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 14069U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11308U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16325U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 51U)) + 13296600294247799698U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 57U)) + 5818503518080877515U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 6735784238734173597U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 5U)) + 7368398209488856201U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 27U)) + 961734029066455638U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 23U)) + 797011946660892011U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + 12841876018396622350U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 23U)) + 16213253970483895623U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 13U)) + 15186950557113470375U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 41U)) + 5117930310827477341U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 18U)) + RotL64(aCarry, 27U)) + 12265429373166094162U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13920531346698601568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14695405206998211456U;
            aOrbiterC = RotL64((aOrbiterC * 13950964363414164279U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7851960904825938443U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterD = RotL64((aOrbiterD * 5614164120361489613U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5663365182245722077U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9607860124321315555U;
            aOrbiterA = RotL64((aOrbiterA * 3461820361914280601U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18171052650586819280U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3442698321538580861U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6317525514963824829U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1491052813469258970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3956599824067616133U;
            aOrbiterG = RotL64((aOrbiterG * 2928600779267623085U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10963841237346073453U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2303020125591252534U;
            aOrbiterE = RotL64((aOrbiterE * 9969099842343321981U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14503856057958162356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11147548150090597694U;
            aOrbiterK = RotL64((aOrbiterK * 11856382308792700441U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9191681438318311481U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13556072770381999852U;
            aOrbiterF = RotL64((aOrbiterF * 18316231099054203683U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10103207278550444685U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10415809965217261104U;
            aOrbiterJ = RotL64((aOrbiterJ * 16562732599511350217U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17435033201864058457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5540494424887364682U;
            aOrbiterI = RotL64((aOrbiterI * 18230910315317249045U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18020151683897013854U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13296600294247799698U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10000194329456668845U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 22U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 34U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 56U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererG, 40U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16622U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 17328U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 21571U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16447U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17728U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 53U)) + 6163290588946759209U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 39U)) + 7342672468560105447U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 37U)) + 11574563167017282321U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 14U)) + 2254820206194758964U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 1469783447473099498U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 3U)) + 14174828900676165088U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 16277954291890598132U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 57U)) + 14845750668693136766U;
            aOrbiterA = (aWandererE + RotL64(aCross, 30U)) + 150099699692047766U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 1200784917165131703U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 41U)) + 9469982764806754302U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10956702761701710182U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7915506894975487807U;
            aOrbiterC = RotL64((aOrbiterC * 8874108311712727983U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17335794183733623213U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 557028996286989506U;
            aOrbiterJ = RotL64((aOrbiterJ * 3993359298602424281U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1597385667771002414U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4376417959915162639U;
            aOrbiterE = RotL64((aOrbiterE * 4626236858205178149U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 549770198518993876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 756554555648070919U;
            aOrbiterB = RotL64((aOrbiterB * 16272320259614325355U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7298557532533152193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3336802611342112013U;
            aOrbiterK = RotL64((aOrbiterK * 14679103452120080499U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2314938232094714365U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12215066333571149153U;
            aOrbiterD = RotL64((aOrbiterD * 10747052773052630601U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7762752719356805046U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6519429915769040078U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15548676502167938513U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7556691736109752918U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13731245903412646404U;
            aOrbiterI = RotL64((aOrbiterI * 15581965016668635409U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5910925625723735162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16037704866415841869U;
            aOrbiterG = RotL64((aOrbiterG * 11628217027073824759U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12605882248192797360U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9579778913978981884U;
            aOrbiterF = RotL64((aOrbiterF * 5372577227818787957U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6063171520266734946U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6163290588946759209U;
            aOrbiterA = RotL64((aOrbiterA * 291843698316138251U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 42U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterG, 58U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererF = aWandererF + ((RotL64(aIngress, 56U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterK, 48U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23927U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneB[((aIndex + 24908U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 26021U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24372U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25172U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 14U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 19U)) + 11210042748013785976U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 4584747303233477454U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 8878765929792969517U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 23U)) + 2172232330280041122U;
            aOrbiterH = (aWandererA + RotL64(aCross, 41U)) + 8378937026022264016U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 57U)) + 8683007464695824208U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 35U)) + 9564352997357118134U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 44U)) + 11713878436769887528U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 13U)) + 8052917623074021077U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 23U)) + 7720597162792145185U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 53U)) + 2602847785328475621U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17813669222300509724U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8724263063156573013U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3632927017737834359U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6882429835961613492U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13213313479525717359U;
            aOrbiterH = RotL64((aOrbiterH * 2411431247725974895U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2401526093648669573U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3616448566579979749U;
            aOrbiterE = RotL64((aOrbiterE * 13323155103752121393U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 18268262471839710401U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5116424918948694752U;
            aOrbiterF = RotL64((aOrbiterF * 7641143782996332069U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11405305689555640431U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12427591396711015574U;
            aOrbiterG = RotL64((aOrbiterG * 8112834135715541223U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16960781161508084626U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12382604781005282628U;
            aOrbiterJ = RotL64((aOrbiterJ * 17196168631120103115U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10054839091354729292U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4167641616532985407U;
            aOrbiterA = RotL64((aOrbiterA * 919291747187787625U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14383737233143309039U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16258779988369405932U;
            aOrbiterI = RotL64((aOrbiterI * 8348773195366160215U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4777263172049970723U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12498046021142146499U;
            aOrbiterB = RotL64((aOrbiterB * 5941015011162130901U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7435001955334177144U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4100235545173125433U;
            aOrbiterK = RotL64((aOrbiterK * 5046572784117638909U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1981704568071298614U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11210042748013785976U;
            aOrbiterD = RotL64((aOrbiterD * 17889749044418386565U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 12U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 58U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 22U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 4U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31160U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 31559U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 27584U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31612U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29997U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 37U)) + 5171470532667965920U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 13U)) + 750549462358682403U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 3U)) + 3325689257577120525U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 41U)) + 18031575461559790826U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 39U)) + 13874739537012288677U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 53U)) + 4250029868785016865U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 8211158803112611161U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 57U)) + 1083939790236786027U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 37U)) + 3446525462376962464U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 6973817815000417325U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 46U)) + RotL64(aCarry, 41U)) + 15230876489676945543U) + aPhaseFOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9359727659738755880U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8775170107816327654U;
            aOrbiterC = RotL64((aOrbiterC * 6910680458261008653U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11958941755525038545U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16966819714283167348U;
            aOrbiterK = RotL64((aOrbiterK * 16363457661846050749U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14556087985619763243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17915047508377045221U;
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8578745677485367222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7002181668717618866U;
            aOrbiterJ = RotL64((aOrbiterJ * 12329703532414955235U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3569939503066735457U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2956247934282522184U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9946650822131152531U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4285180013402474041U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5976239869535619811U;
            aOrbiterH = RotL64((aOrbiterH * 3458095419039067465U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2424524955161695463U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6849595426583763537U;
            aOrbiterB = RotL64((aOrbiterB * 12727902040238318101U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11414890686374886716U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5668287266836153445U;
            aOrbiterG = RotL64((aOrbiterG * 8011885266143066285U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9976985606260445887U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9223940029500676834U;
            aOrbiterE = RotL64((aOrbiterE * 8508023992488499955U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4480967907876921958U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5132766654502526597U;
            aOrbiterI = RotL64((aOrbiterI * 321625389942019245U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12921555132452983464U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5171470532667965920U;
            aOrbiterA = RotL64((aOrbiterA * 9710487797420618879U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterB, 48U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterA, 46U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Fencing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5767U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 6708U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 4941U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6264U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2864U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 6908U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 14U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 9630214189402543339U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 43U)) + 4072576573737526819U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 15994787452709618869U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 6403240137132259482U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 35U)) + 10229266900170507720U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5025294577989748989U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16696461238217956883U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15993828976234917577U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9878318855341719119U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16086635438116177346U;
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12295437783084203730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7681150419912842402U;
            aOrbiterD = RotL64((aOrbiterD * 7289497379725191451U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2639104034287637448U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12298170009332243573U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3485932317267669626U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16569551670038752475U;
            aOrbiterK = RotL64((aOrbiterK * 8139802826402217631U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 56U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10581U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 10165U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9960U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14004U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8985U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8318U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 35U)) + 15045917390223766480U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 10763054007033668758U;
            aOrbiterG = (aWandererD + RotL64(aCross, 13U)) + 13190170142593666607U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 9657025731441167065U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 5U)) + 11433367178975954211U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17904920143996810366U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3244383020512113283U;
            aOrbiterG = RotL64((aOrbiterG * 552521443123433353U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6538815775171139091U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7195368312757976343U;
            aOrbiterH = RotL64((aOrbiterH * 10515679176134176565U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18134430713910279374U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6571776588427107976U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11916502085252589161U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11830778129647517758U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9793702760907767365U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4096246227968677179U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2287235876793192036U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8951959188326141794U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9968356718110753845U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 26U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 52U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24095U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 17106U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 22737U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20177U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16763U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18238U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 2558105147674438050U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 38U)) + RotL64(aCarry, 27U)) + 15856662514774702561U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 13346869226246584582U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 3U)) + 7632111846116243973U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 53U)) + 2102101361626976279U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5605968705067851563U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6842483186584326681U;
            aOrbiterH = RotL64((aOrbiterH * 11344798544990575365U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5559797213819425064U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12422313931331576759U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7399849122565913401U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2751024420047872601U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11031320239359798610U;
            aOrbiterF = RotL64((aOrbiterF * 8607639453141148025U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14366375309473793217U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11971479429768505316U;
            aOrbiterG = RotL64((aOrbiterG * 10063001532313098203U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3947595951884469542U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17882767922372770896U;
            aOrbiterE = RotL64((aOrbiterE * 3361906348965810211U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterG, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 26U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26491U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 28630U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 29307U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25596U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30363U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 29700U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 11521331427196538632U) + aPhaseGOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 16653824187682957632U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 5U)) + 11654676587350088289U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 37U)) + 8010313317412193584U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 3U)) + 1108775560502907471U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 243952321439823521U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2324945800401240403U;
            aOrbiterD = RotL64((aOrbiterD * 9471328582043504473U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9257554497543369657U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16701314607244592540U;
            aOrbiterH = RotL64((aOrbiterH * 8790054741039817107U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3900445848034341782U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7652316487347103658U;
            aOrbiterA = RotL64((aOrbiterA * 11480123491361589799U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14980368605272070578U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2001165460948764796U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8110980921827107649U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1911044015666991050U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11366207111147818339U;
            aOrbiterB = RotL64((aOrbiterB * 17234439040652553865U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterD, 40U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 13U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Fencing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7027U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 3728U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 7428U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 276U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3393U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 3741U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 28U)) + 11450949896247900941U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 3905542253538116335U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 9529740545977785305U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 1856876631533143492U) + aPhaseHOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 53U)) + 84253466320181686U) + aPhaseHOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12577480918745432444U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5625703170397704029U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13583960724598036659U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 694608607323629282U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3993981243536262204U;
            aOrbiterF = RotL64((aOrbiterF * 2502835860198146381U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4119215953484892051U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8785040118556157146U;
            aOrbiterC = RotL64((aOrbiterC * 17113521266125471625U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16234403619456882890U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10398727475672860610U;
            aOrbiterD = RotL64((aOrbiterD * 5086871400049644715U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18327987141759096769U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2645964788056875452U;
            aOrbiterB = RotL64((aOrbiterB * 8778681366114628045U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 52U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 60U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15518U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 14496U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 15134U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11804U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15140U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 11713U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 5041131702736607991U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 22U)) + 9295010428212681446U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 6235875895358766017U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 2622227802531866918U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 35U)) + 3888894734834524972U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 241682012014701753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15758000422451568079U;
            aOrbiterI = RotL64((aOrbiterI * 14719166949665416221U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2061944548396976912U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8177144990755754531U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12702392689484397947U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 554978075608818497U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 250408260560714933U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1295379390497107727U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8700027645880997552U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10026130047465480902U;
            aOrbiterA = RotL64((aOrbiterA * 12417270861933696623U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9785843014096326696U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9998582683258411251U;
            aOrbiterE = RotL64((aOrbiterE * 7197956237569462269U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 60U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aPhaseHWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19158U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 24496U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19936U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18126U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23158U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17822U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 43U)) + 9630214189402543339U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 4072576573737526819U) + aPhaseHOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 15994787452709618869U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 35U)) + 6403240137132259482U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 21U)) + 10229266900170507720U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5025294577989748989U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16696461238217956883U;
            aOrbiterK = RotL64((aOrbiterK * 15993828976234917577U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9878318855341719119U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16086635438116177346U;
            aOrbiterE = RotL64((aOrbiterE * 5585682357395705671U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12295437783084203730U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7681150419912842402U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7289497379725191451U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2639104034287637448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12298170009332243573U;
            aOrbiterC = RotL64((aOrbiterC * 9397919591171238575U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3485932317267669626U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16569551670038752475U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8139802826402217631U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 10U)) + aOrbiterE) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 60U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 20U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26071U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 27362U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25318U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30094U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31198U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27596U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 40U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 53U)) + 479672811032092393U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 18061121631394564425U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 35U)) + 14237400452740566065U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 6723123812257706134U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + 4247997188026499248U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1939107415066134869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3912640123546395979U;
            aOrbiterC = RotL64((aOrbiterC * 9779626695085572877U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8295478436553964298U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3218960600711526885U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15443507655470278069U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5874096203353388890U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10294536533673023358U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15561710414949058923U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11268561953904130747U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16693201256788898423U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16291987237693567209U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7550969634681894654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9501647424602245869U;
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 18U)) + aOrbiterA) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
