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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8B1204FE4C0D9B9FULL + 0xF45EAEC91B1B0557ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x885AFDD080531C49ULL + 0xCEB1FC47789C2701ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDFB46F47A4B60891ULL + 0x9F646720C54836FCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x980B2A19578251ABULL + 0x9B64ACAFECAD533FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD49D22D9CB556975ULL + 0xACA7BFAD2C0C8778ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x832C2CF5EB11E9DFULL + 0xDDA3C045AA389188ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9B6DEB659F97EE39ULL + 0xEDF1EE04735FD714ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC846DAEE85162C23ULL + 0x81FB4BCC4949379AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB9C2827C30CCC7F5ULL + 0x86E7344C55F2FBC5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9F97F7B191C98CF9ULL + 0xAD52C491ADEFADFEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x840AE5B61394D3DBULL + 0xD762A554E906FF17ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB8FA0FE9013F53E3ULL + 0xC26C761C9098D81BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC9D006BE9B6C5A17ULL + 0xF9793F18A09D7323ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x82234F19413210C5ULL + 0xF2A3B3F847B4C7D3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9607927CEDA7CA01ULL + 0xB323AA00122B6797ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x803E19445DC9725FULL + 0xD9314DB589F5776CULL);
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
            aIngress = RotL64(mSource[((aIndex + 132U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((aIndex + 2916U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 5270U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5189U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 57U)) + 10726035965553989335U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 50U)) + RotL64(aCarry, 27U)) + 967354339530195662U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 29U)) + 10834593005478605624U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 1012888282838656933U) + aNonceWordF;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 15283530351725183253U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 23U)) + 11724495956731703750U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 11U)) + 4288330117317505776U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 42U)) + 10894778070022873473U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 27U)) + 15563886747621617467U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 53U)) + 11182488628562891937U) + aNonceWordD;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 19U)) + 10420140066310588580U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11775138062167543111U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16545391898578161683U;
            aOrbiterD = RotL64((aOrbiterD * 14588306527161321535U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1550144656312299266U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14903504853138279883U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8003033561266164387U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 309935535526750396U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13991265868040011411U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2887531132228588441U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1755976294857114222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2259275858478396846U;
            aOrbiterK = RotL64((aOrbiterK * 7416165760067878161U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4838175912944552936U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 12307900457200936013U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 14719363144850838805U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 18025411832912225805U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 981375022769564523U;
            aOrbiterH = RotL64((aOrbiterH * 15869361544011831483U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3174014054982742562U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8119692378748963609U;
            aOrbiterJ = RotL64((aOrbiterJ * 3072354179707448489U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14502863160788675807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1207582534593709516U;
            aOrbiterE = RotL64((aOrbiterE * 3045412087535529357U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5838011917777875072U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 434594114594643600U;
            aOrbiterA = RotL64((aOrbiterA * 1591023655239709931U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15711060039063734443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8307150522686198490U;
            aOrbiterF = RotL64((aOrbiterF * 2082452039297764679U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5805686529930815226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10726035965553989335U;
            aOrbiterB = RotL64((aOrbiterB * 5563221485243331689U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 50U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 34U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 42U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 9790U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 9234U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8136U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((aIndex + 7871U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererG + RotL64(aIngress, 35U)) + 11998579547770778580U) + aNonceWordH;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 21U)) + 8409465187298704610U) + aNonceWordE;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 3470222286110333500U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 37U)) + 5704486785203069994U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 56U)) + 10334944660253279633U;
            aOrbiterG = (aWandererK + RotL64(aCross, 23U)) + 7626852700722567477U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 14631310754943209743U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 807160297237854120U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + 5624154783624196107U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 41U)) + 4971444394698940423U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 51U)) + 6340057638461027062U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9003019862787819481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13632057463595873033U;
            aOrbiterH = RotL64((aOrbiterH * 12575202147280216765U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12766104026871797746U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4062118445824915939U;
            aOrbiterI = RotL64((aOrbiterI * 13130770039048080701U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5258212525426469978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9956946981015983939U;
            aOrbiterB = RotL64((aOrbiterB * 8106382657040497669U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10837606223056473999U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13292864885504191134U;
            aOrbiterK = RotL64((aOrbiterK * 4445739587553669471U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 166087925900318658U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6786842221885441388U;
            aOrbiterA = RotL64((aOrbiterA * 4411147600413147773U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16888086378070246404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5240855484445974002U;
            aOrbiterC = RotL64((aOrbiterC * 402652898573422271U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6874866669211571608U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 732890824978127460U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3776365957702257453U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5541380495707308058U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17947326584411475765U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10920952349981652899U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 15060679340045767910U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1675974028461383576U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15127962310365242819U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 226889112033170368U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4290719734244011388U;
            aOrbiterE = RotL64((aOrbiterE * 6453598182035414143U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7712233480730639084U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11998579547770778580U;
            aOrbiterD = RotL64((aOrbiterD * 11599893373156816375U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 46U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 58U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aNonceWordI);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11502U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 13539U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14506U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15621U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 19U)) + 898812731947995389U) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 8677347622525527167U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 37U)) + 770321564027567654U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 41U)) + 11020474858081526395U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 21U)) + 17289793580414993470U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 24U)) + 10111912559295118444U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 8083622125544542011U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 5U)) + 7149858558922988240U) + aNonceWordA;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 3U)) + 5919683821379905699U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 6860902846079238714U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 43U)) + 15083517836867542075U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14852868368708376381U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9860233289028878323U;
            aOrbiterE = RotL64((aOrbiterE * 13418143547952204667U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 772406119079116272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7971141501337627589U;
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8478568022896691911U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4027604850785607101U;
            aOrbiterC = RotL64((aOrbiterC * 4826627523578901467U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17199331557841535430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17138249294921502391U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16236812863923234668U;
            aOrbiterJ = RotL64((aOrbiterJ * 2925542836624164807U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16941524155859123682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11240343728857342866U;
            aOrbiterF = RotL64((aOrbiterF * 7281012444214294659U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15163914964139858328U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6673576554415729652U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1558880328574736975U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5399050402101642989U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 11806006719060024615U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 15782156615926092159U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9812148913932011655U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4737919734590584193U;
            aOrbiterH = RotL64((aOrbiterH * 2739737604370936959U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3415477403346468057U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5922725868927615919U;
            aOrbiterI = RotL64((aOrbiterI * 12390148483052777871U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17435294951520465659U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 898812731947995389U;
            aOrbiterD = RotL64((aOrbiterD * 17248379279729365007U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aNonceWordC);
            aWandererF = aWandererF + (((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 41U));
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 20U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterB, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18786U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 20066U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17277U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17251U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 18469U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 11U)) + 6771552164800695068U) + aNonceWordA;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 60U)) + 12131763371571322040U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 23U)) + 3326182381395522013U) + aNonceWordE;
            aOrbiterD = (aWandererB + RotL64(aCross, 43U)) + 12288775097697156383U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 41U)) + 5195948373449796741U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 3U)) + 14404044002250137144U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 39U)) + 11142382920035825426U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 13U)) + 2967149520256475485U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 1470907369577818097U) + aNonceWordI;
            aOrbiterH = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 9231668148004163910U) + aNonceWordC;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 13078929163913892386U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9485274692075657877U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12216951187543631673U;
            aOrbiterC = RotL64((aOrbiterC * 6571066246507310805U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6933334652581744234U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17260276102423580920U;
            aOrbiterG = RotL64((aOrbiterG * 7796879893790990605U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 387767848169714392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8597538259308082638U;
            aOrbiterE = RotL64((aOrbiterE * 4888054690557707241U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7996708724489146033U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15357384191688149939U;
            aOrbiterD = RotL64((aOrbiterD * 9827691726832491373U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17739222908739454637U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1614322333281471170U;
            aOrbiterH = RotL64((aOrbiterH * 7063116837752240891U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4531604274893197209U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3453280714992341288U;
            aOrbiterA = RotL64((aOrbiterA * 8390029711127907805U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 116623650872661533U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6565636510115095988U;
            aOrbiterB = RotL64((aOrbiterB * 9691897067492501177U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 10303258439817808058U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10917642773040237611U;
            aOrbiterF = RotL64((aOrbiterF * 10232856828372963363U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2087058228468680821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3691125545393861889U;
            aOrbiterK = RotL64((aOrbiterK * 1768745056298937903U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9240209357066002219U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7645250700232422804U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6762116797395687607U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9859862257084218280U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6771552164800695068U;
            aOrbiterI = RotL64((aOrbiterI * 11063630807191661109U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 36U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 24U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 28U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 21993U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 23881U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25620U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22524U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25403U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 24331U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 47U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 2571116506511057880U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 18U)) + 13112435411509707292U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 27U)) + 10403251762787357256U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 11U)) + 8461951095541400405U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 3U)) + 9890793478557463815U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 57U)) + 3030229465991783707U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 51U)) + 7273848154043719247U) + aNonceWordF;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 44U)) + 10681774862516028276U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 7105082755586853104U) + aNonceWordO;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 6588579345319551129U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 35U)) + 14616333550242386092U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15439666290229654921U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3360304356760164799U;
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14438730801970761889U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14515616787452085729U;
            aOrbiterI = RotL64((aOrbiterI * 2041601927968559821U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4167853822635132419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8950982233003320239U;
            aOrbiterD = RotL64((aOrbiterD * 887144270884244907U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12391327853728029953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7100871010552394421U;
            aOrbiterG = RotL64((aOrbiterG * 16552349374101955967U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15381697462381887944U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6801677551341079401U;
            aOrbiterE = RotL64((aOrbiterE * 13325954438427340703U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 947011315719204867U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterA = RotL64((aOrbiterA * 5566721941682667419U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8910262020598577378U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8778455415977526457U;
            aOrbiterJ = RotL64((aOrbiterJ * 4092470497616637283U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5585696961453127223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9670655481681494412U;
            aOrbiterF = RotL64((aOrbiterF * 7863197168965036383U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10713004007087085729U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 4036355047492922339U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 6923922258047667173U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14580156873863533497U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7049502932205025182U;
            aOrbiterK = RotL64((aOrbiterK * 8665428649262370727U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12707521269341941677U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2571116506511057880U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2388236789245943699U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 58U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 24U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 40U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aCross, 14U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28878U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 30869U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32560U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29471U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31443U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32284U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 18319689184146942855U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 47U)) + 8041304130090501019U) + aNonceWordA;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 42U)) + 11347064191990897738U) + aNonceWordK;
            aOrbiterA = (aWandererC + RotL64(aCross, 37U)) + 15242243470024447468U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 21U)) + 10619749107163611105U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 39U)) + 14795614276221947128U) + aNonceWordP;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 29U)) + 1578095288886372393U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 5U)) + 13593906305770501684U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 44U)) + RotL64(aCarry, 43U)) + 8919815528334599172U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 17425548324720065145U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 27U)) + 11125018338392347335U) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3779189180734244399U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10958224663276134041U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 6206963519509783781U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4317305352561612995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4891139433808505355U;
            aOrbiterC = RotL64((aOrbiterC * 11507024985663120317U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5166074784835930965U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10080890270621589202U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 13170894418184288695U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4501071771615514619U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6486573807774431753U;
            aOrbiterD = RotL64((aOrbiterD * 324029625116648669U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15714881857668975753U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3506619392820235900U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5707033870161224499U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5295711072762443783U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11192836530396570648U;
            aOrbiterA = RotL64((aOrbiterA * 4361810118382207039U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7993389678399774574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12551394763541226695U;
            aOrbiterF = RotL64((aOrbiterF * 11903486656172026403U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11553674370322129668U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4459881583199320245U;
            aOrbiterH = RotL64((aOrbiterH * 2805857426321555685U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3053507713574219459U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15458441755058850309U;
            aOrbiterE = RotL64((aOrbiterE * 7296609957819165877U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17429750026356459756U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17114614857181230304U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10541235280918902739U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8958993884028672039U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18319689184146942855U;
            aOrbiterB = RotL64((aOrbiterB * 5430881344386342703U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 12U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 26U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + aNonceWordJ);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 6U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 36U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFD11A604E119984FULL + 0xE07E8642F7634057ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF11F88EC1D5672D3ULL + 0xCA3189DFDCA84BF7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAE7FB21C831E861DULL + 0xBFC7F2ABFC007221ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCFF7667E070F5607ULL + 0x99900AEC114F3AFFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8B17450C44529B3DULL + 0x8090492FA12328DDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9D87D739820492EFULL + 0x94461B90553F5F52ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD1973AAEEBFB6931ULL + 0x9DE8A8412BB08E52ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xACA3C638A4E8A969ULL + 0xDB299C1A6D35A72AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE4B9E8002122D7D9ULL + 0xFA8BACD45509D95FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD953E2880041ABD1ULL + 0xD300D88B54E25C58ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xECC0E46CA2412C29ULL + 0x95B06A31D3B41AA2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9FD13266E97E7343ULL + 0xF50732CC4BD9C493ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD85B20938D84D08FULL + 0xCA0335FEAA80D755ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x808F3A426080E809ULL + 0xE85094535D15ECC4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA8A3B49551B117F9ULL + 0xFE13565421957019ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFAFDD37B09F75153ULL + 0xE97F1DE4F04B02ACULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2770U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1987U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7114U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneD[((aIndex + 3836U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 43U)) + 15910560457440369082U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 17953072986407436888U) + aNonceWordB;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 29U)) + 15446940721193538669U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 39U)) + 3020785262774422009U) + aNonceWordN;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 48U)) + 7001288645424994404U) + aNonceWordO;
            aOrbiterH = ((aWandererG + RotL64(aCross, 13U)) + 13385250665458462689U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 4841895644623005949U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 13053476783239482065U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 18U)) + 641996979335975244U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16211238020928688299U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 12715448751323279480U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 2116880429675303291U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17784406727699995290U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16626339815786580778U;
            aOrbiterI = RotL64((aOrbiterI * 13940754474750138041U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 9035070625716345139U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6085848172494001945U;
            aOrbiterK = RotL64((aOrbiterK * 10405728912339646693U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1177103851507561053U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2281901691017816407U;
            aOrbiterC = RotL64((aOrbiterC * 3142197009403602497U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9040984343694325070U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13334258224023902365U;
            aOrbiterB = RotL64((aOrbiterB * 4782523727707164869U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1079824790138592518U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14024082692012948652U;
            aOrbiterG = RotL64((aOrbiterG * 3219489374333737903U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2966776524421278970U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5510281854029308547U;
            aOrbiterH = RotL64((aOrbiterH * 9275402927591867297U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7126632329316720048U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1476827035602733472U;
            aOrbiterA = RotL64((aOrbiterA * 2217671289726794033U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6470212302133184965U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4172257438373147415U;
            aOrbiterF = RotL64((aOrbiterF * 4449314239630366533U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 56U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterG, 28U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14409U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 8400U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9262U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12175U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneD[((aIndex + 15325U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 52U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 11274974230580265396U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 5U)) + 16658438747342741547U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 16612986966106053844U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 9329502236843231290U) + aNonceWordN;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 47U)) + 14088261356708344656U) + aNonceWordC;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 29U)) + 13692608802007789581U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 37U)) + 6824473946645682398U;
            aOrbiterH = (aWandererG + RotL64(aCross, 51U)) + 2072915876348570040U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 42U)) + 7420507753044460759U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4677557318688502593U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15081678577055628459U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 16659305295251177155U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7026792817486507482U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6807734532159292872U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9233542707022629190U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1205501586581350876U;
            aOrbiterF = RotL64((aOrbiterF * 2596053290311090589U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10878718669747466677U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8066049063548639241U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3031382633089381605U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 861295180226875235U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9134969787937288583U;
            aOrbiterH = RotL64((aOrbiterH * 7565008208670843555U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6726642007159809594U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8061661744643240470U;
            aOrbiterE = RotL64((aOrbiterE * 6703498926835391813U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13541412083111962884U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8617442758729315637U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 15471862889276160953U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16884403561131293362U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9490680911678221233U;
            aOrbiterI = RotL64((aOrbiterI * 15988763830018001033U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 30U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterH, 12U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16990U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 20305U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24297U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16702U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21989U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19298U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 8767379393098711499U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 47U)) + 7168159491580816433U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 29U)) + 9879279829061883406U) + aNonceWordD;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 23U)) + 10537167136053399303U) + aNonceWordM;
            aOrbiterJ = (aWandererK + RotL64(aCross, 3U)) + 2839070018069188936U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 13844278063968429732U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 11278946626186474646U) + aNonceWordF;
            aOrbiterE = (aWandererF + RotL64(aScatter, 11U)) + 11798425216660557799U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 42U)) + 7618446090703335192U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 695423597006983660U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14344728202803488813U;
            aOrbiterK = RotL64((aOrbiterK * 5168825904902285909U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11656100506575697086U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10384358779985773937U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 247494692039140973U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17585001605131977341U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9964478171465522911U;
            aOrbiterD = RotL64((aOrbiterD * 13484044854790175315U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2710943171829692624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17809072853457153057U;
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12814092033910687774U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1743186323268668740U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11150822630624332557U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10750472346626754704U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15925901217078035356U;
            aOrbiterH = RotL64((aOrbiterH * 9276504171291801637U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2569102106359362359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8868261301410769739U;
            aOrbiterF = RotL64((aOrbiterF * 3662495603133918101U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2143691008373582476U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10606616796243205921U;
            aOrbiterB = RotL64((aOrbiterB * 15794414817813485643U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16258070651850746855U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11720192793689633315U;
            aOrbiterE = RotL64((aOrbiterE * 14475623219460678021U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 46U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterF, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 26U) + RotL64(aOrbiterB, 56U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26074U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((aIndex + 32623U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 30611U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24994U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29140U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32340U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 22U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + 11998579547770778580U) + aNonceWordE;
            aOrbiterG = (aWandererH + RotL64(aCross, 30U)) + 8409465187298704610U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 23U)) + 3470222286110333500U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 39U)) + 5704486785203069994U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 13U)) + 10334944660253279633U) + aNonceWordN;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 7626852700722567477U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 51U)) + 14631310754943209743U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 807160297237854120U;
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 6U)) + RotL64(aCarry, 39U)) + 5624154783624196107U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4971444394698940423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6340057638461027062U;
            aOrbiterH = RotL64((aOrbiterH * 12027586111086798629U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9003019862787819481U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13632057463595873033U;
            aOrbiterJ = RotL64((aOrbiterJ * 12575202147280216765U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12766104026871797746U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 4062118445824915939U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 13130770039048080701U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5258212525426469978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9956946981015983939U;
            aOrbiterG = RotL64((aOrbiterG * 8106382657040497669U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10837606223056473999U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13292864885504191134U;
            aOrbiterE = RotL64((aOrbiterE * 4445739587553669471U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 166087925900318658U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6786842221885441388U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16888086378070246404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5240855484445974002U;
            aOrbiterK = RotL64((aOrbiterK * 402652898573422271U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6874866669211571608U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 732890824978127460U;
            aOrbiterA = RotL64((aOrbiterA * 3776365957702257453U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5541380495707308058U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17947326584411475765U;
            aOrbiterB = RotL64((aOrbiterB * 10920952349981652899U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 4U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 56U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9C8D41CE79F09133ULL + 0xD19C1BBEFE12E5FBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA150FA6F0C7FFD13ULL + 0xFD0E14352594F5E0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB39066DE0122F849ULL + 0xB2824AA6D394E742ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA81C55461EB7A5B9ULL + 0xFDAF0176B19E8861ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC6B2AEB2C5D4D96DULL + 0xF5D09416B38A71FCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF6C055FA8E13B8A7ULL + 0xED054A29A43F8267ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF7F855E9B128A8F5ULL + 0xF528392F12FD162EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF97C3CA1DD93C7E7ULL + 0xF0A1F4C72BA92FF3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x994E67A5A9896F47ULL + 0xE3966EDEF45A5748ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9E3F5182E8156DE9ULL + 0xC239145E19069C92ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA9134E519EB6CBDFULL + 0xFB61BC3CC9A7D879ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF997D9FA2453BBB1ULL + 0x9CEB549F2B0FD16DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC19676CBE1BD66ADULL + 0xB34C76834B70905DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB2284FD06BBB0AF1ULL + 0xDA7D607CB773AC82ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x87ABC9BC3F573943ULL + 0xEAD2646B5250A2D7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBD806180906D76ABULL + 0xE2B9FC933B678BAFULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3519U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((aIndex + 3910U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 315U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5811U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7685U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 40U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererK + RotL64(aScatter, 50U)) + RotL64(aCarry, 5U)) + 10404808878585437255U) + aNonceWordD;
            aOrbiterE = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 10587858736301591439U) + aNonceWordG;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 1430530909801644435U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 9090938022430118902U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 19U)) + 12936604311751121235U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1000583006020232032U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12352532088997042232U;
            aOrbiterK = RotL64((aOrbiterK * 494418029883239087U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16723410947058502564U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 16614089235313154270U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 11530998303573027827U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4245553025593349277U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 3353146318549477494U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 14246377408238318091U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5935727336135635196U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10312187090293319667U;
            aOrbiterC = RotL64((aOrbiterC * 1395964500396711899U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12192843181244744484U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2542570124502586365U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17222847847573534963U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 52U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 50U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8689U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 9262U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 9780U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13907U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12259U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11343U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 8793908991006073956U) + aNonceWordM;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 46U)) + RotL64(aCarry, 53U)) + 2932916283348441943U) + aNonceWordO;
            aOrbiterF = ((((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 11069042087940968262U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aWandererD + RotL64(aIngress, 37U)) + 14369628676782894441U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 21U)) + 8602903272780978282U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3827036107178568820U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8905245209036772489U;
            aOrbiterF = RotL64((aOrbiterF * 5744017326197157667U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13331387530760017893U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 9880107580289737823U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 10302652857542703753U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10199619040626900278U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2466307560891374281U;
            aOrbiterB = RotL64((aOrbiterB * 6295342978834217571U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 13973403407981259448U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2851460278409385243U;
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 10365453393815690776U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2382382358987358791U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterE, 34U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19304U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 16923U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 22981U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22367U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17518U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20083U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 7893287783892523139U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 5U)) + 10257331997383491153U) + aNonceWordN;
            aOrbiterF = ((((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 41U)) + 14562226733652231753U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 14320342577110737851U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 13U)) + 9816717579822880756U) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9558926960095881953U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9230371862654338324U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 8842712825810461561U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 6414274291252913420U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13868546184398350849U;
            aOrbiterK = RotL64((aOrbiterK * 1547986864837497409U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16940736952569949038U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2866957764814864371U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3554702178644797003U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7916721976073979724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1602444214978842275U;
            aOrbiterG = RotL64((aOrbiterG * 11072503711308122385U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9529061385251008037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8402775110887376588U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + aNonceWordF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 58U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32065U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 28765U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29818U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30659U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26839U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24784U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25324U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 11410829607777684449U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 7502698839700975347U) + aNonceWordA;
            aOrbiterD = (aWandererJ + RotL64(aCross, 21U)) + 13267685058252106173U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 48U)) + 238242706996630625U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 8184695499511454281U) + aNonceWordF;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 12767823220461985403U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 12293198423143850330U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5073886956792823825U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11149495229952495939U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7556992689338382800U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 18232398462716803063U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3431338808774134649U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16863099140844995099U;
            aOrbiterA = RotL64((aOrbiterA * 752376661101787919U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17872458049880677604U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16760153457252546974U;
            aOrbiterI = RotL64((aOrbiterI * 11225037229069712805U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3115544493537438408U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4359882942759752958U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 561477566995575801U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterB) + aNonceWordP);
            aWandererE = aWandererE + (((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 5U)) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterH, 34U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFB6810EFFA91B729ULL + 0xB2A3A863B69B9C6EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8CDC18120C600FCBULL + 0xB19F25B2720ADEBDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBDA00B1FEE00BCE1ULL + 0xBD6A93793D1B16BEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8904A83398F919CFULL + 0xCE0AF1C36A415842ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA69ABAF58CFC3C39ULL + 0xEB1EB263B8B4F267ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE4F706ABBC7E2675ULL + 0xBD09436D674C03E4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9688B86447751B6DULL + 0x9D251842B32B8AEDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8B15EAAFA3E21271ULL + 0xF78FF51BCB8E9B9FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCAA1059B732EE3EBULL + 0x8A6D468C138827CFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB008438D6342588FULL + 0x95B2CCCFA3ADFE8FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9771F3523095BEC1ULL + 0x8AC09726C3D1C62DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9122457DFD0F00BBULL + 0xE1777D7E5F382D21ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x886F0ADC79C01955ULL + 0xB3440E91772B063AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9B6C39C68DE3204DULL + 0x93C426B61E44C3FCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCB2E837EF0CDA9ADULL + 0x8BB9FFF79E90D120ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8B7CB1AA5399336FULL + 0x917021D368302E3CULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aFireLaneD, aWorkLaneA, aOperationLaneB, aOperationLaneD, aWorkLaneB, aFireLaneA, aOperationLaneA, aWorkLaneC, aOperationLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6883U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 6197U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7589U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6706U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 221U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 5955U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 35U)) + 13278949403988203974U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aWandererF + RotL64(aCross, 51U)) + 9213599924054673756U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 1255746482932381798U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 11575321997144516122U) + aNonceWordD;
            aOrbiterC = (aWandererH + RotL64(aCross, 3U)) + 15881587525529432437U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 9846195809864862707U) + aNonceWordC;
            aOrbiterF = (aWandererB + RotL64(aIngress, 11U)) + 12319815691858217670U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16322617427294439587U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16332130810525887437U;
            aOrbiterB = RotL64((aOrbiterB * 7588076439690559343U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 4920951156015336794U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16767126455124552329U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4440352337076842603U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12553595911087945223U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1437522202135436142U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 2001992794165550905U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12313100454852227143U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2761983020631055729U;
            aOrbiterF = RotL64((aOrbiterF * 3874839760378039509U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17635303588421554367U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 788212489507463763U;
            aOrbiterE = RotL64((aOrbiterE * 17896475584538528059U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5192552894670654434U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6784748488807738811U;
            aOrbiterK = RotL64((aOrbiterK * 8077237651953896479U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16113417046719114943U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1096874945215225916U;
            aOrbiterI = RotL64((aOrbiterI * 17308604412622879833U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + aNonceWordP) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8280U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 10576U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11376U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15992U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11461U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 15145U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 16462052553719977502U) + aNonceWordG;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 12337064059566619581U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 13U)) + 15801005007094515447U) + aNonceWordM;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 11U)) + 8228706742665081656U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 27U)) + 11006723027845190869U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 3U)) + 18173765337829177450U) + aNonceWordA;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 43U)) + 530215083653542558U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6608611827035564511U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2246051826221626809U;
            aOrbiterK = RotL64((aOrbiterK * 6333352641495253539U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5228575308895381421U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10999213210689606857U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 5467601259546342925U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3773371037240485696U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8887985779436152504U;
            aOrbiterH = RotL64((aOrbiterH * 698713082830739677U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 11150566414723818350U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8336366151003049546U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9033771197242493699U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13233968794237090787U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8172558473508478819U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 17837070423649268435U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 133564480283347997U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15104810248883567064U;
            aOrbiterB = RotL64((aOrbiterB * 706802420642303533U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9138629520201127075U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13993086066341664080U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4875046427147105077U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 5U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 39U)) + aOrbiterH) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 30U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17646U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 19683U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19860U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21716U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16589U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22011U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererA + RotL64(aScatter, 6U)) + RotL64(aCarry, 21U)) + 5576732410244514238U) + aNonceWordK;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 21U)) + 2833808925935929629U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 53U)) + 3670188682914544792U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 15759072378887814995U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 13934007231137439994U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 27U)) + 11022225696007690512U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 13U)) + 16989177104453635790U) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9256930045263527091U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17788596104417068290U;
            aOrbiterJ = RotL64((aOrbiterJ * 675554110563253305U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17044369456673337625U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1310908395523250343U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 16305084373037705921U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12067065689034065422U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15130844248737512262U;
            aOrbiterG = RotL64((aOrbiterG * 9409499577465934107U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14532689204495587494U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8198147292120244178U;
            aOrbiterC = RotL64((aOrbiterC * 1418356389507740991U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5485494458627163347U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10830008207150307611U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 6526039534042499457U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17770065502486618029U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 6397859353395335459U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 14286997752368893825U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5128700697381508319U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7103394110057060499U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 5053680689949149633U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 38U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26298U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 32062U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 27953U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25761U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29760U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 31574U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 785861751704720606U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + 15968088718435606299U) + aNonceWordJ;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 1393976526590347151U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 11U)) + 17240750947292745884U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + 4921576136163183137U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 60U)) + 3334047873553153032U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 15086509978458408698U) + aNonceWordK;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 892391205397581998U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2965686403183767521U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 709160942482770225U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14632215393655706170U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15740589515342377322U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11131164813943086445U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterE = RotL64((aOrbiterE * 6412189142344044255U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16021254613117657178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6183615599897921154U;
            aOrbiterD = RotL64((aOrbiterD * 9976411093264211033U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12533992547026652747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3104325358982904219U;
            aOrbiterA = RotL64((aOrbiterA * 14977348108778147265U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3878525937957474644U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2120435259884368445U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 15964718652193073177U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14928658302694194856U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9121310461310309348U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 17304439784647477491U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + ((RotL64(aCross, 20U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterD, 50U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCF3AD830F247936BULL + 0xCAE19E425A536B97ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x996E3F51C2965E4BULL + 0x9204891C21470B3BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAED2DF3641A3F413ULL + 0xF9D71D1BC38D003BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE420DF58DE299C0FULL + 0xC90CEF156F2EE0D3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD19B05B8405F50EFULL + 0xE19822E7999CAE44ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x830030F5D1FBA91DULL + 0x8E511FBC31F960F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFB710E9BA837EC17ULL + 0xA83E7415AB8B5D76ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFAFBCC56AF5A8D67ULL + 0x8DFC24708A2E08EAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x88C90DE81A9DA329ULL + 0xA3A29B7C5418DA99ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x87026705BD1BAAF3ULL + 0x9FC1B481A1102DC3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x812D5BDBE0201CA7ULL + 0xBC453078F4825045ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x85EAA80341D640CDULL + 0xE73D26058B71D72BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCC5F999A4999FC17ULL + 0xD32E0CDC8D709FF3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8DA7EBB3439E5229ULL + 0xF47686EF70618988ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCFDC02D4AFBFF587ULL + 0x89E45978692A853DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCBD9155B1E6E1A63ULL + 0xD735786B754DA1DAULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneC, aExpandLaneA, aFireLaneA, aFireLaneC, aExpandLaneB, aFireLaneD, aOperationLaneA, aExpandLaneC, aOperationLaneD, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6068U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 4311U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 3093U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3910U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7347U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8096U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 43U)) + 5295352595333316211U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 2341795367042042605U) + aNonceWordG;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 10122175780504033663U) + aNonceWordI;
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 10084612804696198554U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 29U)) + 16470424309851045971U) + aNonceWordJ;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 6U)) + 656016130975227994U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 13U)) + 15313268829659834317U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3795220914993923394U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14044442220988813825U;
            aOrbiterE = RotL64((aOrbiterE * 3270650852546606835U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3804224626734584802U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7980006306010255693U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13746830564584711549U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11852212099729274845U;
            aOrbiterB = RotL64((aOrbiterB * 2164880979318247855U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9083223471018084847U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13706723820703853346U;
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1713819986642275223U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1382000168233902914U;
            aOrbiterK = RotL64((aOrbiterK * 3894160765130198157U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4540474625764565485U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 1756168174375757220U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 12739160208010092017U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1409297070183609309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6082750101445444357U;
            aOrbiterD = RotL64((aOrbiterD * 17438740230251860935U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 21U)) + aOrbiterF) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 12U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11040U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 12781U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 9027U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13743U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12625U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11329U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 40U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 16016931609704150191U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 27U)) + 14511433515861302636U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 35U)) + 11691237442613269593U) + aNonceWordK;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 16383220587320484649U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 39U)) + 14293015313458219868U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 4407695248205526670U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 1158323195324398372U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6577683409653864555U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 171080079472863843U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3063978974927752653U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5766333425872228205U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16173508656917582960U;
            aOrbiterK = RotL64((aOrbiterK * 12187968015372936695U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11781450063402219202U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterE = RotL64((aOrbiterE * 4331137994135472025U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4006310759400926020U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13156817947481574467U;
            aOrbiterF = RotL64((aOrbiterF * 563189239835001483U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12791290558893516411U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 989729955679243234U;
            aOrbiterB = RotL64((aOrbiterB * 8757228712495095017U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 838379839663022790U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2830743864262313606U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 10173947177104802797U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2146646527331684652U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 4629168181742174906U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 9046124907945045131U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 58U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aCross, 12U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24499U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 19815U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21172U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17340U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21090U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 22486U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 14U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 11410829607777684449U) + aNonceWordE;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 3U)) + 7502698839700975347U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 13267685058252106173U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 238242706996630625U) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aCross, 21U)) + 8184695499511454281U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 60U)) + 12767823220461985403U) + aNonceWordA;
            aOrbiterA = (aWandererF + RotL64(aIngress, 29U)) + 12293198423143850330U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11149495229952495939U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7556992689338382800U;
            aOrbiterG = RotL64((aOrbiterG * 18232398462716803063U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3431338808774134649U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16863099140844995099U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 752376661101787919U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17872458049880677604U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16760153457252546974U;
            aOrbiterH = RotL64((aOrbiterH * 11225037229069712805U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 3115544493537438408U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 4359882942759752958U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 561477566995575801U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13387113067202396536U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12955690074544490161U;
            aOrbiterA = RotL64((aOrbiterA * 12449941770827974511U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15614054443728226807U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1939441328066616114U;
            aOrbiterI = RotL64((aOrbiterI * 4484917074808974359U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4599016263007782537U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9962305629016158048U;
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterH, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 60U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31204U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 24939U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 27502U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31027U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31633U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32451U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 3U)) + 1898718075389870739U) + aNonceWordK;
            aOrbiterF = ((((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 5631794889237247403U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 40U)) + 18219714659484524607U) + aNonceWordG;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 15419581386225732921U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 19U)) + 9125575431710198210U) + aNonceWordJ;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 12205871520544965505U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 11U)) + 7617534300497343422U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18017579105368135814U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10693882161946020042U;
            aOrbiterC = RotL64((aOrbiterC * 2326507900303932855U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11669615701700895306U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 11045110212889232165U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 5965171269273719849U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18019107802806469913U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 12315940560472528716U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 4505122470351404065U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4899009736070044310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17412253404253730364U;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4826286251927854181U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4523455921321845084U;
            aOrbiterG = RotL64((aOrbiterG * 14534103906736598099U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4132514462154182215U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7164745605985109269U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 14107325508977225261U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 6297434295807635654U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8813887638672996646U;
            aOrbiterE = RotL64((aOrbiterE * 17495632530773158201U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 48U)) + aOrbiterF) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE7DCC606797B1453ULL + 0xC9E84BE0BC397478ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9C6060E78421BE2DULL + 0xAA89D56CDFE0FC08ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF9A72B94B7E6B173ULL + 0xA919EA4369F2FC09ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF5782FA4D9F3EA83ULL + 0xDD026933A76F9F1AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA382BAECFC59FC23ULL + 0xDA1722657671390FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xABE559ABAA4E50B3ULL + 0xBA5C35866CE3E146ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8ECEC76A66E55F7BULL + 0xC27C6D3B2F910E7EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB863C0130DE7ED19ULL + 0xC846F4FA823FD896ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAD9DEF421895B107ULL + 0xD1644D7EA533432AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAEE344D6D7099B17ULL + 0xE63228C2CFAAA31DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD09E303B4E776A3DULL + 0x956DC41F6765C4C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF82E4EF9DCB7657FULL + 0x9B047CBFE68EFC97ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF678731E53AB4447ULL + 0xA3DCF964D53A9B70ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA6A03B3136258C2FULL + 0x858849BB5CF31B9EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD3BC18CB9F2EA969ULL + 0xA26AD5CA22848CF1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFE3A0A79E6CC1C19ULL + 0xE9B28D96CF1421B6ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aFireLaneA, aOperationLaneA, aWorkLaneD, aFireLaneB, aOperationLaneB, aWorkLaneB, aFireLaneD, aOperationLaneC, aWorkLaneA, aWorkLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2525U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 2505U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 118U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4159U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6273U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 3840U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 19U)) + 13499155707765393469U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 4U)) + 3740324981823726185U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 13U)) + 5470765363949735652U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 57U)) + 3446436171274452326U) + aNonceWordE;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 39U)) + 1778929412631211933U) + aNonceWordI;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 14666308799855220954U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 42U)) + 4548410236791175055U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 5829739767694190372U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 35U)) + 14319231414903675748U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 1513851750246111405U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 1685620217748986019U) + aNonceWordD;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16284162182006054402U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6271539598462003309U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 13923286694131331137U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12669312437565969473U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11894755313393001665U;
            aOrbiterG = RotL64((aOrbiterG * 12556759675372354075U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6315983824634946566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17106616474222892782U;
            aOrbiterF = RotL64((aOrbiterF * 167205520766791073U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13350266700180455548U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4608846311203767162U;
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14195866746143604365U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7917977448256795054U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10707336923305131629U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17122696159336995392U;
            aOrbiterC = RotL64((aOrbiterC * 13953518568670659191U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5182322763573586116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6503754948502556246U;
            aOrbiterH = RotL64((aOrbiterH * 14749002194140663519U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14907832047832987341U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6258064448676621346U;
            aOrbiterJ = RotL64((aOrbiterJ * 4407960312705621487U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1180234574888070795U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 801686887651085881U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 433981853631548041U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11810494591997709554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9343740505955858127U;
            aOrbiterE = RotL64((aOrbiterE * 8733378485648720323U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12816829575386720695U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13499155707765393469U;
            aOrbiterD = RotL64((aOrbiterD * 9937924703928730369U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 41U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterF, 39U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 36U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 53U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterC, 6U));
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13811U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 15848U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13357U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9050U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15863U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 15566U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 27U)) ^ (RotL64(aIngress, 58U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 37U)) + 17454559218352016650U) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 8005709669325164803U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 54U)) + 13393741948412816357U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 13U)) + 3665865624348875553U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 41U)) + 8334142570031883436U) + aNonceWordM;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 17226066128706139657U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 5U)) + 3319093033121522613U) + aNonceWordN;
            aOrbiterG = (aWandererB + RotL64(aScatter, 11U)) + 6657535603401588798U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 52U)) + 5469746182326331147U) + aNonceWordH;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 17846791786050221418U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 29U)) + 15939541003714896288U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 12076763190461077406U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3594038213596405284U;
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8301291631324464622U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8460406137668390582U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9117147929757711595U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7612394867020871200U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8525076134853103975U;
            aOrbiterB = RotL64((aOrbiterB * 5790440201072204659U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11929899088215090379U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7119509166360685726U;
            aOrbiterG = RotL64((aOrbiterG * 1662341427992528823U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5081078459225240607U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17149991983909906705U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 950223374568067343U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8817303295675241994U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7962039282652745113U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 12773588587795522121U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13596273086338032370U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8186297702278180956U;
            aOrbiterK = RotL64((aOrbiterK * 6226504769888753861U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1696277861691580263U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17360461831507082959U;
            aOrbiterC = RotL64((aOrbiterC * 1651378456022210983U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1384868996572650981U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2039624849777183290U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13148024378138271937U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14530407348595669913U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18023931565754525034U;
            aOrbiterE = RotL64((aOrbiterE * 18025122652259338105U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11245556671533878373U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17454559218352016650U;
            aOrbiterI = RotL64((aOrbiterI * 15665798947106818229U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 44U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterH, 22U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24355U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 23176U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 16750U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24492U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17780U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 19366U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 35U)) + 13714409587461539863U) + aNonceWordC;
            aOrbiterG = (aWandererJ + RotL64(aCross, 42U)) + 14101156723903265839U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 7063754562895369001U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 3U)) + 12320578575245519386U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 5U)) + 11744826789631008424U) + aNonceWordH;
            aOrbiterI = (aWandererC + RotL64(aIngress, 13U)) + 8744816505096675597U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 38U)) + RotL64(aCarry, 57U)) + 10405435520084528645U) + aNonceWordL;
            aOrbiterB = (aWandererF + RotL64(aScatter, 47U)) + 1463157688070683543U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 12379603577919617703U) + aNonceWordI;
            aOrbiterA = ((aWandererI + RotL64(aCross, 27U)) + 1343439118031348146U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 11U)) + 16118850268070235540U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14116264435819277136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5251698273012432109U;
            aOrbiterC = RotL64((aOrbiterC * 1495818611622063967U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14806408656041403829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11569345414052398227U;
            aOrbiterH = RotL64((aOrbiterH * 9913158908301414861U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17063874769147888574U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9927420478679581917U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 9042782809534196563U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2550285599827162167U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17801534123304996448U;
            aOrbiterI = RotL64((aOrbiterI * 2160836889363614721U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6456685241021762041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17064208177372969289U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13726627607233302493U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18279938244131982650U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8211002229712129419U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 12931373380977640645U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12795832560781931767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 286378504074349650U;
            aOrbiterE = RotL64((aOrbiterE * 85453101173293509U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5835304250436889513U) + aNonceWordF;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 12704972686724379659U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 1198789639656336053U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12555700587254295099U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6740149669657971715U;
            aOrbiterD = RotL64((aOrbiterD * 9376048577305482691U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1541392147096889431U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16891341703173286949U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 697452963711223355U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8811637585092392653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13714409587461539863U;
            aOrbiterF = RotL64((aOrbiterF * 2578939920876994763U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 12U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterC, 6U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27286U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 26935U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 29146U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30396U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27893U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26531U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererF + RotL64(aScatter, 53U)) + 6469584119078165548U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 60U)) + 14329756366517987910U) + aNonceWordE;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 12890831797059772123U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 51U)) + 3164503807500018990U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 41U)) + 177531431387646836U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 3167421392893561015U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 2813174781844753460U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 47U)) + 10953270419153249857U) + aNonceWordH;
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 16911518309710356951U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 6616750447844893150U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 30U)) + 10276741398025985982U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6206043608461213208U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12021552904553405793U;
            aOrbiterJ = RotL64((aOrbiterJ * 10023362889960174909U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15283586234744144846U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5923238786775948571U;
            aOrbiterE = RotL64((aOrbiterE * 8200882393521882651U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11044014510971660078U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9351141024085076044U;
            aOrbiterH = RotL64((aOrbiterH * 13316079344614432317U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17703395981862992420U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10154548848376027087U;
            aOrbiterI = RotL64((aOrbiterI * 12324478347590509035U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8836420852291617425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10193385413543886344U;
            aOrbiterK = RotL64((aOrbiterK * 824935982418585449U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8248580084535685190U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3910083671888152974U;
            aOrbiterD = RotL64((aOrbiterD * 17825311776715895927U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12350341628569930642U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2565977481575002842U;
            aOrbiterG = RotL64((aOrbiterG * 18233446879833776677U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9271041067874027417U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14289254596554201861U;
            aOrbiterA = RotL64((aOrbiterA * 7985522692852251413U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 5981802134118235214U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14047813418129636856U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 15961435325216504877U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11808443842149398212U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11380858372643695792U;
            aOrbiterC = RotL64((aOrbiterC * 100198424024622179U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10385375464069162356U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6469584119078165548U;
            aOrbiterF = RotL64((aOrbiterF * 5263876933019848989U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererC = aWandererC + (((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterF, 10U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB49C37130403F869ULL + 0xDAE816E1C5F9DFBEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC19466DB6476F023ULL + 0xF5146877164091EDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB0347496447D64EFULL + 0xBAE7D72F8ABBE6CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB2F91133BC719CA7ULL + 0xF9C9DD9C451519F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF080718AFF4F28D3ULL + 0xE3B29134A270DA5BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB97A033AFE3E614FULL + 0xED64BF9789DB80D3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB8B02C6140376137ULL + 0x8FB37B4627EA83A3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA06AF5DE72CCCC2DULL + 0x874404CC7928674FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCA4BB1017C181B0BULL + 0xA8748CFF2F87B4A7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCE998000F96A4FD3ULL + 0xBE99472CE31DBA4CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x93ED4ABB0A64BC6FULL + 0xF3AEFEACA8EF8405ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA1C1246311B2FBB5ULL + 0x9B80B594DEFD6C97ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE3648005BD939499ULL + 0x8B75701CCC603ED4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD6A20494E4123C95ULL + 0xFC9392A338B64311ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFC498BB2AF7113A1ULL + 0xD222FE413AE94BE6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD2E0081A36A21541ULL + 0xA7749CA821034029ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aFireLaneC, aFireLaneA, aExpandLaneB, aWorkLaneC, aFireLaneB, aExpandLaneC, aWorkLaneB, aFireLaneD
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6933U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 6989U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2840U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6901U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6381U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6489U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 47U)) + 17264605017518259932U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 15209184354580778643U;
            aOrbiterK = ((((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 3299527965014731384U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 39U)) + 16293096431816127821U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 23U)) + 11031983436878828337U) + aNonceWordP;
            aOrbiterB = (aWandererG + RotL64(aIngress, 41U)) + 9188018632448236358U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 13420816400363406556U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + 2485063384097917101U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 36U)) + 3089135816938128264U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10730544971770435788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10431767565618874806U;
            aOrbiterK = RotL64((aOrbiterK * 4723078464590561545U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 14883796491656899074U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13465877783538483706U;
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13322163435314643713U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12337846092069506365U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4950101626975919939U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7181706961838582889U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17961706029559914243U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10321902557977495175U;
            aOrbiterG = RotL64((aOrbiterG * 16189559888625084711U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18146616411403012772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11739172334166341121U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7936637782633487291U;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3160044627483874242U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16816384076887379704U;
            aOrbiterI = RotL64((aOrbiterI * 5052772186568301951U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8101560104988710226U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8851416379738817624U;
            aOrbiterE = RotL64((aOrbiterE * 16767420038937389027U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 6U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 34U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11110U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 10481U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13536U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9500U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11182U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10200U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 7893287783892523139U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 29U)) + 10257331997383491153U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 57U)) + 14562226733652231753U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 6U)) + 14320342577110737851U) + aNonceWordB;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 9816717579822880756U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 9558926960095881953U) + aNonceWordI;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 23U)) + 9230371862654338324U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 11U)) + 6414274291252913420U;
            aOrbiterI = (aWandererB + RotL64(aCross, 46U)) + 13868546184398350849U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16940736952569949038U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2866957764814864371U;
            aOrbiterA = RotL64((aOrbiterA * 3554702178644797003U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7916721976073979724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1602444214978842275U;
            aOrbiterE = RotL64((aOrbiterE * 11072503711308122385U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9529061385251008037U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8402775110887376588U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 13980225144628227381U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15003592180290390713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14195681406520825751U;
            aOrbiterC = RotL64((aOrbiterC * 11455000833788877217U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3263577002367714202U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12019422062655581928U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8508638054582582917U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6536618106353552880U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 6233964121117511885U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9654542989321430868U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7019594782797863244U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1234877854354279981U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8256061220727519919U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9232754129467036130U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 17556001874302369781U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5608829951337740378U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12632120498473345701U;
            aOrbiterJ = RotL64((aOrbiterJ * 6994794653605831925U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterA, 51U));
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 6U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21243U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 19816U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 20508U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18694U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21328U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 17086U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 13481227414590594621U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 26U)) + 17425964381118918026U) + aNonceWordK;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 4792004356135956581U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 13U)) + 11926849936000639098U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 37U)) + 990697329347742142U) + aNonceWordL;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + 9307721505373076588U) + aNonceWordB;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 17605732738841908719U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 5U)) + 13110764518634187439U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 17970109897810645911U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10273133817644703654U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11239046688920468137U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5197802934333553327U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8355821483275763145U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15522151127786049345U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 4844278537850520413U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5381663179722418112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9551368011768104906U;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16264476585232221270U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7721417776432288282U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 339418090653475277U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 3247926250495935511U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 16824669543765729097U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3390560045236418590U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3894024951542543635U;
            aOrbiterJ = RotL64((aOrbiterJ * 10599637790900418767U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3878539166189668154U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5617705593218220843U;
            aOrbiterA = RotL64((aOrbiterA * 82771190372750823U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12320861089148474544U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14943790251625519550U;
            aOrbiterE = RotL64((aOrbiterE * 13758322022902008313U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18119213517612562775U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1413193144229486646U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14562375280658115687U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 12U)) + aOrbiterF) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 20U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28488U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 30138U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 32501U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29817U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 31078U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24890U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 20U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 19U)) + 17454559218352016650U) + aNonceWordB;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 47U)) + 8005709669325164803U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 14U)) + 13393741948412816357U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 53U)) + 3665865624348875553U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 57U)) + 8334142570031883436U;
            aOrbiterK = ((((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 17226066128706139657U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aWandererH + RotL64(aIngress, 34U)) + 3319093033121522613U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 6657535603401588798U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 5469746182326331147U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17846791786050221418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15939541003714896288U;
            aOrbiterJ = RotL64((aOrbiterJ * 1400351482213119809U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12076763190461077406U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3594038213596405284U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 10244002692575821495U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8301291631324464622U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8460406137668390582U;
            aOrbiterG = RotL64((aOrbiterG * 9117147929757711595U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 7612394867020871200U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 8525076134853103975U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 5790440201072204659U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11929899088215090379U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7119509166360685726U;
            aOrbiterA = RotL64((aOrbiterA * 1662341427992528823U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5081078459225240607U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17149991983909906705U;
            aOrbiterB = RotL64((aOrbiterB * 950223374568067343U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8817303295675241994U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7962039282652745113U;
            aOrbiterH = RotL64((aOrbiterH * 12773588587795522121U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13596273086338032370U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8186297702278180956U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6226504769888753861U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1696277861691580263U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17360461831507082959U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 1651378456022210983U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 14U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterB) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 40U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x80CC5745A729A69DULL + 0x99EFA850D93C97A8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA8D387B126D1824FULL + 0xA840CEE1E903A5D4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDEE1A6A53C3B6DF5ULL + 0xEDB4DD0BA273E4BCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF4374D804A837603ULL + 0xFE0AE31134337813ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9EA1753E8D622157ULL + 0x8E948F65C8AE6576ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFA019808571187FDULL + 0xC5C813FCBAED325FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD90B0F7C1C5BFC27ULL + 0xC1DF31CCDBFCA6B3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x90F65014AAA6B907ULL + 0xBEA32B2DA2D9B364ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xACF4995E1D589063ULL + 0xC534BC54E7067893ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8F6160B5A3597D7FULL + 0xFD8F793D1F6C44AFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBD96D0E945083077ULL + 0xDF7420703F1ACC42ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA2D749350CC93D3FULL + 0xFBF394A94378F586ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB0BC9996DD9DDBE3ULL + 0x9C2BA089E3AF2778ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB3F58309C7438F5DULL + 0xD13F5B66649770BFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB4215A7AABD3E2D3ULL + 0xD694954855239355ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x91E32317584F31B5ULL + 0x9DB0FCAD18F08933ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aFireLaneB, aOperationLaneA, aExpandLaneB, aOperationLaneC, aFireLaneC, aExpandLaneC, aFireLaneA, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5533U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 7498U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1587U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3890U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7897U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 156U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 35U)) + 3255291173184001106U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 23U)) + 15308468160116255528U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 29U)) + 18186972408589866656U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 4439324265978331914U) + aNonceWordH;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 13U)) + 13099263173016322486U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 7041561081767500660U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 6196422612687812971U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7664260932541281413U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17802347823020441056U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2220679459017369255U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4253107484061190446U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 13799496534030645312U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 9167675060053848207U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14252892847595951926U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 5663527578664291422U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 18314294235895182465U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11148755959699137661U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17036900929333594592U;
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2403828181385259549U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17813580350434928194U;
            aOrbiterJ = RotL64((aOrbiterJ * 13666780980793857831U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5623611126885414523U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7293224381174846969U;
            aOrbiterC = RotL64((aOrbiterC * 7032561584670788117U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10602620906929686163U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18015916257203385982U;
            aOrbiterD = RotL64((aOrbiterD * 10684090189688871993U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 60U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12072U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 15606U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 15847U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11423U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10107U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13206U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 58U)) + (RotL64(aIngress, 13U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 53U)) + 9220392006207660113U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 11305018553489132882U;
            aOrbiterE = ((((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 5860373868073513684U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 12319586170883987589U) + aNonceWordC;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 35U)) + 14072333614354649021U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 60U)) + 9332158529453194608U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 5U)) + 3860569321145958686U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8119005668901240093U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13918259792880333239U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5441062406822088853U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6938856216758228704U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3960905839118710604U;
            aOrbiterD = RotL64((aOrbiterD * 16203746868670689793U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6043879193734253929U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15691425268831319195U;
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14912209933584715274U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16180183395910618923U;
            aOrbiterH = RotL64((aOrbiterH * 3942858974766467849U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4966642362507707776U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6962226782462822861U;
            aOrbiterG = RotL64((aOrbiterG * 3647802407741095419U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12409120845092026295U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2302946450253872465U;
            aOrbiterB = RotL64((aOrbiterB * 7099576330777297911U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16118304388937163838U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15968419034359049422U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11736207775827080165U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18501U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 23167U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23905U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19480U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16518U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22787U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 51U)) ^ (RotL64(aIngress, 20U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererD + RotL64(aScatter, 35U)) + 8367680518550579791U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + 11491674725611181241U) + aNonceWordI;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 41U)) + 16673861720782164214U;
            aOrbiterF = ((((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 9786610124108350855U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 5745080601557577637U) + aNonceWordN;
            aOrbiterJ = (aWandererE + RotL64(aCross, 57U)) + 1959402215131684684U;
            aOrbiterI = ((((aWandererH + RotL64(aPrevious, 6U)) + RotL64(aCarry, 11U)) + 6121650036079196522U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12016309761037342392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5986936646177049603U;
            aOrbiterH = RotL64((aOrbiterH * 3585650475703294895U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1000367700904043468U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17425288243569101032U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2174614006719048535U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4856917474950325209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16312111093223166419U;
            aOrbiterF = RotL64((aOrbiterF * 11046477664487805241U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 456110002032422270U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11393724374787795662U;
            aOrbiterI = RotL64((aOrbiterI * 1176984359123668389U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8378176867715697176U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8086186452345234815U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 8470349167474173245U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2528229938740192694U;
            aOrbiterJ = RotL64((aOrbiterJ * 8717790851266520943U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13247168811545753141U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8745293957516815264U;
            aOrbiterE = RotL64((aOrbiterE * 14270617180621072619U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 4U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 50U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27859U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 31436U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 26887U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27900U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32287U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 26200U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 22U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 53U)) + 4476099022490972343U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 16836423700375760429U) + aNonceWordM;
            aOrbiterG = (aWandererI + RotL64(aCross, 47U)) + 8850577488928703557U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 7091631824560042743U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 60U)) + 12560498899956759494U;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 7797973377112012161U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 41U)) + 6173820673874805794U) + aNonceWordI;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10805025132310245348U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7139216143268029968U;
            aOrbiterG = RotL64((aOrbiterG * 8349754682635765573U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8241544862261635722U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4735527016563596150U;
            aOrbiterC = RotL64((aOrbiterC * 6621354217673598381U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5166171126690294033U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11117641762075368393U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4980156869201219393U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6312932356458415421U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 10085025354842771067U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16745854428789531080U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1945983905747274355U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2497187958708890337U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16069701876646548995U;
            aOrbiterK = RotL64((aOrbiterK * 16606039730973709495U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17242004368025978091U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12334315722243232121U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 16528598396696346719U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 54U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + aNonceWordF);
            aWandererI = aWandererI + (((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 19U)) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterD, 46U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8838C378E14A6D0BULL + 0xA8410B56AEAF646CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9E19FF2F77D7E7FDULL + 0xC924801C8978FAD8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAD46277852E57105ULL + 0xA5D7B9BBC648E613ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDF0ADC1BC43500D7ULL + 0xAC4818849FEF288BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEC473E714AA0202BULL + 0xA911B427F3932E14ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x993BB8E72687A0A1ULL + 0xFB1F2236427FF789ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x90BF79FBCEC85FF9ULL + 0xCA0CDEED1FF4B21EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9134242AD60F49AFULL + 0xDB6243C2F1AF3480ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x83B8F5611A6BB8B3ULL + 0xB5165A32E01E1876ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9D2E97E698ACB8DDULL + 0x929FCAD9A36CAA35ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF2569C882DD106DFULL + 0xD399782B5A24FD3BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8DFD7B8B7B856681ULL + 0xD7BB48F846973878ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE9A634391D33C725ULL + 0xE553C401EAE9EB8EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB778AC137B2FC645ULL + 0xB3E364B85C7133F3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA577EE5375DA6173ULL + 0x903EF7EA1BC1BB44ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9EA14B22AFF8B97BULL + 0xDBDD6766A4C0289BULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 390U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 951U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2708U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1860U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 3U)) + 13854738573712660276U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 47U)) + 16835460633412286294U) + aPhaseEOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 13U)) + 6785859293758091931U) + aNonceWordF;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 54U)) + RotL64(aCarry, 27U)) + 126317283127992659U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 7568963536291415413U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 12294016745653004819U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 37U)) + 18269588932920281147U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5872406424994751026U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7764434758831474129U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 3772146788188420071U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4804168969415573371U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 959601763507651280U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4647396592804833217U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9257644462479293048U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14332699366894494579U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10487012596470786004U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 612729229562321440U;
            aOrbiterA = RotL64((aOrbiterA * 11380387280507726003U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7845523921295625315U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12742115479740024747U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15578543510683986421U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10294667720904610944U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14369711143154904567U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 13753005602288309379U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10918344717497681894U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 18136794828308636957U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 17899418637978002409U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 36U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + aNonceWordP) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3748U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3069U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4292U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 3686U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 51U)) + 6068543441070417854U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 27U)) + 2995980468193441856U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 57U)) + 18020277482171594003U) + aPhaseEOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererI + RotL64(aCross, 13U)) + 4293807434721230702U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aScatter, 34U)) + RotL64(aCarry, 21U)) + 7980599111583893156U) + aNonceWordE;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 8593141111851052016U) + aNonceWordM;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 5903487523900084325U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15112035513447930209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9854037263057006439U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 396276470208637283U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16759760289688823193U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12622628933030601390U;
            aOrbiterD = RotL64((aOrbiterD * 2151912984825538321U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1264668857268123425U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16302812053619101593U;
            aOrbiterE = RotL64((aOrbiterE * 18291400055836111547U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16087995784896123610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7970269262800468363U;
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5331477046030959632U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16534913204255550893U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1013433634373673565U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11042821902537871209U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8069677512345031660U;
            aOrbiterC = RotL64((aOrbiterC * 13622218526054132397U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5737130058129936372U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1076627182956662997U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14342191224014199929U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aNonceWordG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aNonceWordO) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 20U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5592U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7299U)) & W_KEY1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7886U)) & W_KEY1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6156U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7625U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 35U)) + 3917730204724097072U) + aPhaseEOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 14U)) + 1874642340716212824U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 21U)) + 6900165757434854160U) + aNonceWordN;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 12750946097023807161U) + aNonceWordJ;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 43U)) + 6563216048479513594U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 14960240191349450795U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 16306180275951788289U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 6502066618271045547U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6219852857850888738U;
            aOrbiterG = RotL64((aOrbiterG * 10892297250334325283U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2272931312452845850U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3028929882263199463U;
            aOrbiterC = RotL64((aOrbiterC * 11005324285856805069U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6067393030073568112U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10094809900437037258U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18095564940730322769U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5962414178157074575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15755563045799129417U;
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6321455513889880590U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1197435601998121700U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 17693996266260557625U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12496949381666299968U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6357070235648527030U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2931486644220862433U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8423760160877540210U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8090246492554850768U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2949407491181921633U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 20U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterG, 20U)) + aNonceWordH) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterK) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10563U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 10404U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 10537U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 8692U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9512U)) & W_KEY1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8234U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 4U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 43U)) + 3248574644570178787U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 26U)) + RotL64(aCarry, 19U)) + 4506961512959200024U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 51U)) + 8423739774540738590U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 6593975869641735337U) + aNonceWordG;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 37U)) + 16441716090557369103U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 7936601450453207914U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 5U)) + 13333752583560167065U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8013703284795432973U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2349852779887439236U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 2422888500648100783U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5318539364763284138U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11450957608502944376U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1957880366707810635U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9058992558327552687U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 632095686920230926U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12460364388358520799U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14734218428913777098U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 16344357661370784442U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2981145363531184308U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14176472085175714494U;
            aOrbiterC = RotL64((aOrbiterC * 2584623327412130939U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11198457590069700889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 952584436750426828U;
            aOrbiterJ = RotL64((aOrbiterJ * 1165713888651280355U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4311591763498985972U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16194341833989936369U;
            aOrbiterD = RotL64((aOrbiterD * 9997934560195932575U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 14U)) + aOrbiterC) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12999U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 13059U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11272U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 13464U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12870U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12390U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 11712U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 52U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 2177539223979303669U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 21U)) + 3962004686551521471U) + aNonceWordP;
            aOrbiterF = (((aWandererC + RotL64(aCross, 60U)) + 8457602312617147662U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 18011802451816510632U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 9046101759168876832U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + 11135620637431969597U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 53U)) + 15913029940697999701U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16304193109948135982U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13208892298820080981U;
            aOrbiterF = RotL64((aOrbiterF * 15093751072618884859U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 4182377898949419225U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13970137023071326151U;
            aOrbiterA = RotL64((aOrbiterA * 9075061559681739865U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8402396284835248583U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8859190834060657829U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 13552418608113716117U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9760005337757990392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14108277760135744897U;
            aOrbiterB = RotL64((aOrbiterB * 4474681104256093885U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12226316121949012350U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3456392186754113960U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8704729827929941215U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5004087958637038973U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7176881295123125567U;
            aOrbiterE = RotL64((aOrbiterE * 15272157962928021009U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 10889800478505074438U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13728832441482547824U;
            aOrbiterK = RotL64((aOrbiterK * 17588477761978646139U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterA, 60U)) + aNonceWordF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 41U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16382U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14778U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13979U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15797U)) & W_KEY1], 53U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15435U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15237U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16077U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 44U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 18U)) + 12632404972795375757U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 47U)) + 5351879979055988456U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 3597737727467443413U) + aNonceWordE;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 2830846754917852318U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 17311925960294518018U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 2083584640523695383U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + 15049343611387010158U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6443050378205811147U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6021965178697344070U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6054064448935006741U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5080289878758029976U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 576927745306972983U;
            aOrbiterB = RotL64((aOrbiterB * 16008958833683246115U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4728489691382690859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6184355840165758855U;
            aOrbiterA = RotL64((aOrbiterA * 1515043910404156423U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11220539885798595450U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11091438724966718214U;
            aOrbiterJ = RotL64((aOrbiterJ * 8225347114759391961U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17184210490020062419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2150997767099116408U;
            aOrbiterH = RotL64((aOrbiterH * 8058553821648892499U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7021953562676903717U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 17159676348343312834U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 13877284519668483549U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10367891770525239784U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11922478487264201233U;
            aOrbiterK = RotL64((aOrbiterK * 9195137452661956029U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 28U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + aNonceWordK) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18899U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 17786U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(mSource[((aIndex + 16617U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18300U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17798U)) & W_KEY1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18156U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17858U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 5U)) + 3236820517816085022U) + aNonceWordC;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 29U)) + 741288875914097926U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 21U)) + 8417246926007729580U) + aNonceWordN;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 3U)) + 9715717805774537170U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 14360243844821619482U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 10760908100206775334U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 3434641779946167811U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7885568822756234567U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3041563437672051294U;
            aOrbiterI = RotL64((aOrbiterI * 11440300917533482297U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15761355327564963516U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1158633562785937421U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15511324886867188235U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9338581575871970653U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9172038894262857354U;
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14653924713599790081U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3854497592598563309U;
            aOrbiterC = RotL64((aOrbiterC * 11737111068815795303U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 16286980180327600557U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 5092583772591249756U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 13955105624639442903U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4288397994175567333U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15584236478994873104U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1860480595862755379U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5557463939827483792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2659814275753280856U;
            aOrbiterA = RotL64((aOrbiterA * 17702430405693184643U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterA, 10U));
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 42U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aNonceWordI) + aPhaseGWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererC, 42U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19544U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 20672U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20155U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19188U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21561U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20685U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21424U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 19370U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 40U)) + 13204735390996728477U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 851171359595647173U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 16745304202825290723U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 562392736584913979U) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 23U)) + 3244267012529053918U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 11U)) + 17282536111067869133U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 14851130066471729068U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5256130407952363129U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2904742485828362001U;
            aOrbiterE = RotL64((aOrbiterE * 12941135856735075457U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3723346325449225387U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5344621093694027341U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 9044881458629673499U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12919263300833603026U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17989801264160996071U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15468293047311883751U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5022175042377172157U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16684822380107847758U;
            aOrbiterI = RotL64((aOrbiterI * 2834049270263837537U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2740326510600876682U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13981423865219318820U;
            aOrbiterF = RotL64((aOrbiterF * 14593082145080056441U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 231945878229848395U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14139797734944312580U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6492256080432266407U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16704102101387552373U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8506734780526852552U;
            aOrbiterK = RotL64((aOrbiterK * 4684566118627414659U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 42U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordA) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterH, 12U)) + aPhaseGWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22496U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[((aIndex + 22167U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24005U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22014U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24145U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23151U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24376U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 21924U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 19U)) + 4204560462077827182U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 6572370199668594039U) + aNonceWordF;
            aOrbiterF = (aWandererG + RotL64(aCross, 28U)) + 15958999876732622825U;
            aOrbiterJ = ((((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 9969349486879280377U) + aPhaseGOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 15450238998293956181U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 5U)) + 9128619863683138259U) + aNonceWordG;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 5691270563628979565U) + aNonceWordP;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5901029710568933106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10442738941988588834U;
            aOrbiterF = RotL64((aOrbiterF * 7386621444831603817U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3508116020325721993U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13221917083569767259U;
            aOrbiterA = RotL64((aOrbiterA * 6845108555710135357U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11627915460377128176U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17858261365514253433U;
            aOrbiterK = RotL64((aOrbiterK * 7535577636975884641U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4294837988806295989U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 11242915481585070249U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 17540688242763829319U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13030663829236027109U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7451948220723185149U;
            aOrbiterJ = RotL64((aOrbiterJ * 5191778587712222029U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5575508866505031037U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5161096033789876794U;
            aOrbiterI = RotL64((aOrbiterI * 16843827915802461797U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3980482740649505122U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11188906150207270241U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 408550837615188413U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + aNonceWordD);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 60U)) + aOrbiterK) + aNonceWordC) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25469U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 25104U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24787U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((aIndex + 25350U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26249U)) & W_KEY1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26977U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26290U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24834U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererI + RotL64(aCross, 3U)) + 12426357877879529292U) + aPhaseHOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 13U)) + 12604900366173639176U) + aNonceWordA;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 13511119007338929401U) + aNonceWordJ;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 9878720081166788060U) + aNonceWordN;
            aOrbiterB = (aWandererH + RotL64(aScatter, 11U)) + 15463195409806395076U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 43U)) + 6407922778852833423U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 21U)) + 7690427254160734016U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18030974031722143619U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17983938038322737041U;
            aOrbiterH = RotL64((aOrbiterH * 12479365337221685413U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16605512170117753884U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 681802273302348322U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14608920184802647123U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15550312921312083819U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17824154101711884508U;
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1939207786756735430U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3132864634777826569U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 13606281919426730325U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12822929773923954849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16576106045887115660U;
            aOrbiterA = RotL64((aOrbiterA * 16370914370769903051U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2398825881649235260U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13700821892926092479U;
            aOrbiterG = RotL64((aOrbiterG * 10830623703416956043U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2439833784883391606U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15870638514107637833U;
            aOrbiterC = RotL64((aOrbiterC * 3797380922767479287U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterG, 4U)) + aNonceWordD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordM) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterH, 53U));
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29373U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 29389U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29343U)) & W_KEY1], 29U) ^ RotL64(aFireLaneC[((aIndex + 28278U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28376U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29780U)) & S_BLOCK1], 44U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29341U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 29849U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 60U)) + 12615321415808640429U) + aNonceWordA;
            aOrbiterD = (aWandererE + RotL64(aScatter, 3U)) + 15712784676459931207U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 11U)) + 11013335427004930046U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 8298733856304768806U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 27U)) + 6207732959150824216U;
            aOrbiterI = ((((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 9769864876127544038U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 10782181918651152563U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5790454015845620939U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 15606578025386733803U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 7079287329365566355U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5522352539991175304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5993355818572869649U;
            aOrbiterJ = RotL64((aOrbiterJ * 15221467311057431139U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10864534396947622047U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12090053126235913528U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 7250801471645972261U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14191181677234981396U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2258570108233924592U;
            aOrbiterG = RotL64((aOrbiterG * 8307541155393855209U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8448114811381534603U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2702389315763499817U;
            aOrbiterD = RotL64((aOrbiterD * 6710443836432274393U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17202184076718780200U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 150549910056015002U;
            aOrbiterF = RotL64((aOrbiterF * 195034681254956335U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4910512055808124967U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4783477997418403079U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 861977492146512865U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterI, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 60U));
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31852U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 32359U)) & W_KEY1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30810U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32216U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30562U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30757U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 24U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 57U)) + 1087148170018530502U) + aPhaseHOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 4U)) + 15530846874509311414U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererG + RotL64(aCross, 21U)) + 16987358651515511212U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 12504143181007924259U) + aNonceWordG;
            aOrbiterH = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 393322117322732418U) + aNonceWordO;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 27U)) + 14325937299241887166U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 9395262907017475742U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13658510441418344769U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6410754322737005336U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 6932217611373076391U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9257290738538818434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7489828960857692286U;
            aOrbiterH = RotL64((aOrbiterH * 16519674788777989043U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4118778591214588387U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16619215231168796563U;
            aOrbiterJ = RotL64((aOrbiterJ * 14876884956536265157U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11326283811003573430U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1865401866017614604U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8378326058282460073U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 670150121105733604U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1499331510641068749U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16623742535540383107U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1116410848560838532U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2696841341036281779U;
            aOrbiterF = RotL64((aOrbiterF * 9598953298074904869U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5487352391229549881U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12008243050943342979U;
            aOrbiterC = RotL64((aOrbiterC * 9087261224804582459U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 12U) + aOrbiterJ) + RotL64(aOrbiterD, 48U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x83C159BA3EF33653ULL + 0xDCC998793CE8C121ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x93154FCF8D939F5FULL + 0xFC940AFB65F87383ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDA3D0A8EC5F815CDULL + 0xCC8D38760424FED7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA09F2830A4FAD207ULL + 0xB751699FA09A7003ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEC0C77D12824694BULL + 0xA561384CD97AA24AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE03F2DD8DA8618FFULL + 0xB92A63D40D3C7B6EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBD34A0A54D7B07A5ULL + 0xA3A796F5CBFD7CC4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC18319AC28B17D4BULL + 0xD2673550EA43C7E9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC99ACC03FF057FCFULL + 0x9BD0356BE556D78CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD98E7493410ED9E5ULL + 0xD04890F1043A105AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE66F62DBD16BFE41ULL + 0xCEC11DF143ED9CD3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF0031FF07FF94BA5ULL + 0xA60847524E591666ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF5D18983DD7E4C6BULL + 0xF09C9B9A2C5E24A6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9D5FC559CF656C5FULL + 0xC2F1B703E42F45ABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA952D2475B2F95BDULL + 0x94342F12ECEBEEDDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC61406D711F832C3ULL + 0xCBDA977E6C9ABAD1ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneB, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2124U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 5249U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2297U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3451U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 1561U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 36U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 4980738603982643969U) + aPhaseAOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererA + RotL64(aCross, 60U)) + 17660278413018470020U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 17598114429859543466U) + aNonceWordB;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 10993929335279994739U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 39U)) + 17967203122976322481U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1872290205549034384U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16607778671782810797U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 340054507611349681U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4895226930754394376U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14960359005982301383U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8546231310054433721U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9921642352377700630U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 893281964367208693U;
            aOrbiterF = RotL64((aOrbiterF * 2345509157333444217U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8232519988397858732U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4433022122758913407U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 834240393225479419U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12689609831247168353U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 404535388957472176U;
            aOrbiterE = RotL64((aOrbiterE * 14534020545479806593U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterE, 30U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 42U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 43U)) + aNonceWordL) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10242U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 7463U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 5893U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10134U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7604U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 5U)) + 18144572925667544139U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 5659758077574059728U) + aNonceWordG;
            aOrbiterE = (((aWandererC + RotL64(aCross, 26U)) + RotL64(aCarry, 27U)) + 6343330616999166392U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 17754639838410839447U) + aPhaseAOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 9451843819849581729U) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7957854457197462212U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1461994799722205010U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13431080873536691809U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18002214276252170177U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 14689869073147027164U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 12242482963989582191U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3978104368003440293U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8512135845221335386U;
            aOrbiterB = RotL64((aOrbiterB * 10506667163729414667U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1477533446382953439U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2166717790929947990U;
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8082437060686606995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4363687722464700362U;
            aOrbiterC = RotL64((aOrbiterC * 7199165810993478887U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordB) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + aNonceWordE) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 56U) + aOrbiterA) + RotL64(aOrbiterE, 26U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14050U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 13666U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14277U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15228U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11073U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13733U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 47U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 8375305456876489425U) + aNonceWordL;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 11U)) + 16193562952772453047U) + aPhaseAOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aScatter, 38U)) + RotL64(aCarry, 29U)) + 18088652458594816223U) + aNonceWordB;
            aOrbiterG = ((((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 767344788620249944U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 3U)) + 7705194930396368752U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3829736891311272834U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9881681671347640061U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14380245087931793021U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1721196560190164264U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3002652618388454213U;
            aOrbiterD = RotL64((aOrbiterD * 15289749311593032657U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9811621464004005202U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 5652598941069986530U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 4797973356708091621U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6250499348327316328U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16025054277615264530U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 16446892258704281903U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 13800298546867243172U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12256104592865905782U;
            aOrbiterF = RotL64((aOrbiterF * 16983140179497142713U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 14U)) + aNonceWordG);
            aWandererB = aWandererB + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordP) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 27U)) + aOrbiterA);
            aWandererG = aWandererG + (((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 43U)) + aNonceWordH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17679U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((aIndex + 19069U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20200U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20721U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18687U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19828U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 44U)) + RotL64(aCarry, 41U)) + 479672811032092393U) + aNonceWordM;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 11U)) + 18061121631394564425U) + aNonceWordG;
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 14237400452740566065U;
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 6723123812257706134U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 27U)) + 4247997188026499248U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1939107415066134869U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3912640123546395979U;
            aOrbiterE = RotL64((aOrbiterE * 9779626695085572877U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8295478436553964298U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3218960600711526885U;
            aOrbiterK = RotL64((aOrbiterK * 15443507655470278069U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5874096203353388890U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10294536533673023358U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15561710414949058923U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11268561953904130747U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16693201256788898423U;
            aOrbiterJ = RotL64((aOrbiterJ * 16291987237693567209U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7550969634681894654U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9501647424602245869U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 40U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + aNonceWordK) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 30U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordD) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26207U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 27028U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26067U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22320U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26116U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26781U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 8101351470141807662U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 6965474099521076705U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 35U)) + 6803828268885684784U) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aIngress, 14U)) + 13454235922950972488U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 11678091885751244777U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 5307134544628507141U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4873703518950429353U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2680442582958424915U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8542156221858586039U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3993726182905296513U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11331376012938127609U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12113047622035464386U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1944244448665721151U;
            aOrbiterI = RotL64((aOrbiterI * 7010050836758762003U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12914188029425467576U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2486762763475327024U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14580191602982245481U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12093414832400135066U;
            aOrbiterB = RotL64((aOrbiterB * 12720286833215690663U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterG, 52U)) + aNonceWordI);
            aWandererE = aWandererE + (((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 3U)) + aNonceWordA) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + aNonceWordM) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30369U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 29720U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31196U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31547U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30803U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 30952U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 47U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 12380376990224645149U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 13U)) + 18296928500297384014U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 39U)) + 3550626816361145100U) + aNonceWordL;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 57U)) + 2667792936946706027U) + aNonceWordC;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 12020969779370926953U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 737340727886903447U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1681797651799760502U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 11923920414802777451U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2956186342689489064U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1876852870402977177U;
            aOrbiterK = RotL64((aOrbiterK * 8875540081346621757U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6433205819353555071U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9065076854974222998U;
            aOrbiterH = RotL64((aOrbiterH * 5459675878087242021U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3254410578766789992U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 2005081975473815576U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 9947701153722014085U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15992999234834560419U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3458344156815120948U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1668460113964608051U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 60U)) + aOrbiterH) + aNonceWordM) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 48U) + aOrbiterB) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aNonceWordD) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC82C7B508B8AAC37ULL + 0x9229A859391F959FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB6F4C5B034761781ULL + 0xF9A26E0C56F8F9A0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8E84610237C558B7ULL + 0xCCDAB6AFE9938EB5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8B50B0A37F8E387BULL + 0xC2EA52FC8DF18287ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA70AD9892CDC10FDULL + 0xFD9B003B53D82A4EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFEFBAE0AF7349C99ULL + 0xFF54AED633F259B0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE7ECA1C293BF8585ULL + 0xE17D067C15341F16ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8DA6FC74701E6319ULL + 0xBFA0BAD6EAAD22B8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC56232DC570104B9ULL + 0x99BAAA664FECB36CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x92EA994AA375ACB7ULL + 0xCEE4516A170FAF90ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDEE9CB9BAA58716DULL + 0xBCCA13DD56C6179DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD46E2E76BC0BB315ULL + 0xF4CA746ACADAE08DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBCD713E10A211281ULL + 0xCD51B6986852A275ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE6B9FECDA214B5B3ULL + 0x90FA83B69B4D030FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB88F8F54822A46E3ULL + 0xB44F0912CA9CD034ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA6887340BB2EF9DBULL + 0xB93A77500943AF25ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aExpandLaneA, aFireLaneD, aInvestLaneD, aFireLaneC, aWorkLaneA, aExpandLaneD, aWorkLaneB, aExpandLaneB, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1521U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 587U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 4020U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 663U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4912U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 6U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererH + RotL64(aCross, 39U)) + 2101601659597850213U) + aNonceWordK;
            aOrbiterB = (aWandererD + RotL64(aScatter, 27U)) + 2759794072560720121U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 12U)) + 9443562552411269339U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 57U)) + 10801360546699857975U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 8020716394829332019U) + aNonceWordG;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 1021894212367773801U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 35U)) + 13346855534622490176U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 18U)) + RotL64(aCarry, 19U)) + 16359309548462953836U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 23U)) + 12642446944680783519U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8197424982767553380U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14346334610901859094U;
            aOrbiterA = RotL64((aOrbiterA * 16982899923227935679U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14171304260534233539U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 334531601308283605U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10707856298471572695U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18364775750091914766U;
            aOrbiterI = RotL64((aOrbiterI * 15735143943129143265U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8531394793118363836U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15352876929406908882U;
            aOrbiterH = RotL64((aOrbiterH * 475199047053777179U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 567682016232278157U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2068146551757663119U;
            aOrbiterF = RotL64((aOrbiterF * 1557877740957797555U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7776122587613256525U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16430938890724272256U;
            aOrbiterK = RotL64((aOrbiterK * 4540270493783593257U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11912000645055436094U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16800749242578741498U;
            aOrbiterG = RotL64((aOrbiterG * 17804584625034241737U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5909199180260499150U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5751089915336865588U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 15376689503142397927U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3478216857728853008U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18007567146937338241U;
            aOrbiterC = RotL64((aOrbiterC * 6620498877303917855U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 22U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aPhaseBWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterH, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6784U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 5628U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9195U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9862U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9892U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5619U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6266U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 1708250618750199233U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 58U)) + 12009147777553691142U) + aNonceWordI;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 27U)) + 8393982703399156592U;
            aOrbiterB = (aWandererB + RotL64(aCross, 51U)) + 3247327098356831221U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 35U)) + 3403590155376353737U) + aPhaseBOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 18197244558104735044U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 4U)) + RotL64(aCarry, 23U)) + 3096253642040701606U;
            aOrbiterH = (aWandererF + RotL64(aCross, 47U)) + 8012692688785412179U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 19U)) + 17531946907545680745U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17687695944270225817U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16147773866007628769U;
            aOrbiterJ = RotL64((aOrbiterJ * 16926442582711557877U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18244641303026196497U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8839160526348897457U;
            aOrbiterC = RotL64((aOrbiterC * 14268021129087663397U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10599266240854068246U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2056723540756216155U;
            aOrbiterI = RotL64((aOrbiterI * 13311591601230386375U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4629354220460621284U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9505955649473204942U;
            aOrbiterH = RotL64((aOrbiterH * 17775391885312236187U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17078153810088721310U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9470436761716263000U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 5431855497250357229U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3305863413630104742U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14377172434239576161U;
            aOrbiterF = RotL64((aOrbiterF * 6880176890091033423U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 415687827894226513U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16975319836893760993U;
            aOrbiterB = RotL64((aOrbiterB * 6597144958013976445U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12707054129431596074U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8974182792497231239U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7874658957269462717U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10826131924322955095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4168545139712703154U;
            aOrbiterA = RotL64((aOrbiterA * 10305904857550051705U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 13U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 24U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + aPhaseBWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 42U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 46U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 22U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11518U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 14474U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11929U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13106U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 12977U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 27U)) + 5173905450211892891U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 43U)) + 3555542451908039957U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 35U)) + 11559884700283861559U) + aNonceWordC;
            aOrbiterD = (aWandererF + RotL64(aScatter, 47U)) + 1352524329968738673U;
            aOrbiterH = (aWandererB + RotL64(aCross, 58U)) + 8914206450420616349U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 3U)) + 2251523378498463946U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 39U)) + 9541575923299247038U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 1239854507907214595U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 17698101462598498934U) + aNonceWordL;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12305566971683256060U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13804545036303215569U;
            aOrbiterB = RotL64((aOrbiterB * 10359543704152744971U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10239749097704329264U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4212214906286320308U;
            aOrbiterH = RotL64((aOrbiterH * 3661436621615751071U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12192418916967430783U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4475514289326450361U;
            aOrbiterC = RotL64((aOrbiterC * 17497164630368757887U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17376102613298827459U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18129393209955439341U;
            aOrbiterK = RotL64((aOrbiterK * 6404089025014118979U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4014763724300253568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17325007199676828814U;
            aOrbiterD = RotL64((aOrbiterD * 1420888274815627083U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 15480474849292388685U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14357924730184375449U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 16723492259068034209U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4335731868597970070U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8296023680394303015U;
            aOrbiterE = RotL64((aOrbiterE * 14027415401430120543U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2807312426993262800U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 15510369660839648501U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 18207954408298333959U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12597844696606519907U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7231012798553551535U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2841306785994479299U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + aNonceWordB);
            aWandererG = aWandererG + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE + ((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 48U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneD
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneD forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19446U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((aIndex + 18075U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16781U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20556U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16592U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 57U)) + 2783898056762489197U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 18U)) + 7177192902873343053U) + aNonceWordM;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 12254703232691980774U) + aPhaseBOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 15446547245691219559U) + aNonceWordO;
            aOrbiterJ = (aWandererF + RotL64(aCross, 29U)) + 888475203006174856U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 48U)) + 3649183529366307877U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 23U)) + 4642631047518805167U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 43U)) + 6108329730724782250U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 8334054653023816636U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5891895375031474350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3176720746238477862U;
            aOrbiterC = RotL64((aOrbiterC * 1869961473768307911U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6111038696865301675U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11914998302228682704U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17005063057791320948U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18333780598768130670U;
            aOrbiterD = RotL64((aOrbiterD * 5416759844884107303U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2056115016443263153U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10245512728872962677U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 707106795383284903U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4810366069422162351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3051442983125942469U;
            aOrbiterE = RotL64((aOrbiterE * 13558537578054436423U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 9285068547223654308U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13067251130180968842U;
            aOrbiterH = RotL64((aOrbiterH * 7000687697769766605U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3203670242792002165U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1770881716916463461U;
            aOrbiterB = RotL64((aOrbiterB * 13870229847371882171U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16286823712870537410U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13067191141829694202U;
            aOrbiterG = RotL64((aOrbiterG * 15629974528467350445U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3414576315085336932U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8979691827341555245U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15971594804040295757U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 30U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordD) + aPhaseBWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererK = aWandererK + ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterD, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23370U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((aIndex + 24601U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24149U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27292U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneC[((aIndex + 24754U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 19U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 16200278595895089008U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 1029614154810465897U) + aNonceWordC;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 53U)) + 7129562468705441295U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 43U)) + 14388903902433951274U) + aPhaseBOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 4U)) + 1013568949315967455U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 35U)) + 3128823373497815651U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 14525694606889470589U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 29U)) + 14443983602196782887U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 14U)) + 12244220415328641190U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10477159225338766614U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2842870123078131566U;
            aOrbiterI = RotL64((aOrbiterI * 11522265477555954071U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8621138818955849917U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5038396344400303181U;
            aOrbiterF = RotL64((aOrbiterF * 14636756322207385447U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2768613802894372496U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2848088309172056399U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15017458513904884651U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9079797279596336139U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15424866642305110811U;
            aOrbiterD = RotL64((aOrbiterD * 12912331089970158845U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13751764050290602740U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7694557131324740282U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 14980807690491467023U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3508673897305667669U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3600868397311393233U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1222655844979128996U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2257342337168905875U;
            aOrbiterJ = RotL64((aOrbiterJ * 6198995971182272119U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6290990717563682725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15308494772443447109U;
            aOrbiterE = RotL64((aOrbiterE * 1925593111157842325U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 52U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + aPhaseBWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterD, 48U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29515U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 29819U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32142U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32284U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 27317U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 37U)) + 5573188770530340913U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 51U)) + 1431772230889897111U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 4809192776429682319U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 29U)) + 5576603692574369341U;
            aOrbiterC = (aWandererI + RotL64(aCross, 14U)) + 2720143226007220386U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 17220328778565331629U) + aNonceWordP;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 57U)) + 9629485808442089423U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 3U)) + 1136998437010390983U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 19U)) + 11893390497814523841U) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1764986431917532370U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1741014798007010376U;
            aOrbiterH = RotL64((aOrbiterH * 13414914086049500731U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 12221368453236547044U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7694538641172350430U;
            aOrbiterK = RotL64((aOrbiterK * 8439120733670016501U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17472344518811560603U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3308740700728172984U;
            aOrbiterB = RotL64((aOrbiterB * 15290400462887712083U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9535358833412446771U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11192312491731312451U;
            aOrbiterG = RotL64((aOrbiterG * 17405609148475445743U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14850451970047190039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11932493299452443256U;
            aOrbiterJ = RotL64((aOrbiterJ * 7964808728820467795U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5972619895614731870U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17174497535809891690U;
            aOrbiterD = RotL64((aOrbiterD * 15471084511364572533U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17412894714378898351U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14675615208706549810U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7864845089606499769U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16116792108013658523U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9702262005960966336U;
            aOrbiterI = RotL64((aOrbiterI * 970452849653781703U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17337264966818542841U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7004462033775827275U;
            aOrbiterC = RotL64((aOrbiterC * 11943575980344402681U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 56U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterI, 3U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aCross, 23U) + RotL64(aOrbiterH, 54U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterB, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererF, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD4F17B75351669F5ULL + 0xBC941D393B28B8C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8F5DEA1CE827EA7FULL + 0xB8CA989DFC382970ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDF91A75669840E47ULL + 0xFB300B4E70648C1DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x84D2ABA9D4AB9639ULL + 0x95EBDB0FD183F287ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF9F719AAB02D6249ULL + 0xCC57C8BECD3DAB21ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC89F8370146877EDULL + 0xCC7C8D9E358D8B35ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFA617397DF452987ULL + 0x8F17711E6EA8DDCFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBF2318471A607BBBULL + 0xD7B0510B88134C46ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA0B3DD884DF8F6ABULL + 0xC1EBE447DE91931AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBC0BAF9AD9A4EC27ULL + 0x8B135BA33B6E5864ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE570582F35D5123FULL + 0x99CC99C11966A37AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFD66941F7C8DB817ULL + 0xBB25939EAB8D52FBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9275E83B3E9D54ADULL + 0xA3A6A07D18931E4DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF1E1225EBC06898FULL + 0xA8B8166826E2844AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAABDE4EDDCB33D8DULL + 0xBA9F85B06FD40868ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE5A8002841C3B603ULL + 0x85DCC02016653CD7ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 508U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 4225U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 2241U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4344U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1157U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3772U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 28U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 7825479804710770560U) + aNonceWordK;
            aOrbiterE = ((((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 41U)) + 5298124167101358123U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererG + RotL64(aIngress, 57U)) + 17774541024369233726U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 3U)) + 7679371833537454082U) + aNonceWordG;
            aOrbiterC = ((aWandererK + RotL64(aCross, 35U)) + 5385914900748772224U) + aNonceWordH;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 3879781930908486531U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 21U)) + 659110346638873236U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10749021728538539749U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3631252455767429457U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8552825360915119613U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2271978810960685021U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5963558780692551176U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4772055335210781149U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 974909966119198104U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9296998242911152296U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2613629915877957661U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2245318466901521959U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13391076374843288568U;
            aOrbiterB = RotL64((aOrbiterB * 18094558036982107419U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6184487746594236737U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1563385912137291418U;
            aOrbiterJ = RotL64((aOrbiterJ * 4805455299959232321U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1744840092006498629U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2100927276837188416U;
            aOrbiterC = RotL64((aOrbiterC * 3541788262067077997U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9998911862807246338U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12239948725635220096U;
            aOrbiterK = RotL64((aOrbiterK * 7098620484129489129U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + aNonceWordF) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 38U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + aNonceWordI) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6560U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 9115U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5466U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 10795U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10784U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7877U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 8151U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 6U)) + 5960680319644404115U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 16050752633567034185U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 8447503223226854741U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 14176813813397917591U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 35U)) + 10534915376130006644U) + aNonceWordL;
            aOrbiterG = (aWandererC + RotL64(aCross, 41U)) + 6866224454375302514U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 27U)) + 16506374165041008396U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7167814023968794098U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13870852197416596664U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17015971222069856463U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18064038854848993105U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9869630811507771691U;
            aOrbiterA = RotL64((aOrbiterA * 13723164383800461387U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 863613100452759380U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16597969741225436529U;
            aOrbiterE = RotL64((aOrbiterE * 2680793528887208903U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6575347108051310653U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17062262265485019063U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7601045488473620019U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7193399224636409133U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14146747818810433849U;
            aOrbiterC = RotL64((aOrbiterC * 5273185769989530041U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 9441449106442431427U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4303295336545399503U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8829695296836242587U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12604760768543193458U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15779327512379787715U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 14000905201441272597U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + aNonceWordD) + aPhaseDWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 44U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12763U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 11006U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11485U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12404U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 15602U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 22U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 57U)) + 17711946802293254150U) + aNonceWordG;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 19U)) + 16652362590489569378U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 13U)) + 6972810344198183097U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 13117100889782940546U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 26U)) + RotL64(aCarry, 53U)) + 13199305696782626591U) + aNonceWordH;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 47U)) + 992156184392760945U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 13791265442074543880U) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17057087245252294859U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13444195995883541046U;
            aOrbiterJ = RotL64((aOrbiterJ * 13067044288608808777U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 6723678233676059420U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7913379431208430475U;
            aOrbiterG = RotL64((aOrbiterG * 2295062944289127123U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4481887195529300665U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11892724101424384078U;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7700902083270424194U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1888001433557140271U;
            aOrbiterK = RotL64((aOrbiterK * 8975562955027025349U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14996753906788986929U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 939004845422123765U;
            aOrbiterA = RotL64((aOrbiterA * 2507090308972292313U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11922230289291941807U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 15681187459741147199U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 10124947739653819101U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9119043713532718155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8327697433992362166U;
            aOrbiterC = RotL64((aOrbiterC * 11157657162184304567U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 56U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 11U)) + aNonceWordB) + aPhaseDWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20347U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 16782U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20959U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16782U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 19654U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 24U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 13U)) + 2177539223979303669U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aCross, 43U)) + 3962004686551521471U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 6U)) + RotL64(aCarry, 37U)) + 8457602312617147662U) + aNonceWordE;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 18011802451816510632U) + aNonceWordI;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 9046101759168876832U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 37U)) + 11135620637431969597U) + aNonceWordP;
            aOrbiterG = (aWandererD + RotL64(aScatter, 27U)) + 15913029940697999701U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 16304193109948135982U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13208892298820080981U;
            aOrbiterF = RotL64((aOrbiterF * 15093751072618884859U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4182377898949419225U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13970137023071326151U;
            aOrbiterH = RotL64((aOrbiterH * 9075061559681739865U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8402396284835248583U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8859190834060657829U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9760005337757990392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14108277760135744897U;
            aOrbiterE = RotL64((aOrbiterE * 4474681104256093885U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12226316121949012350U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3456392186754113960U;
            aOrbiterI = RotL64((aOrbiterI * 8704729827929941215U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5004087958637038973U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7176881295123125567U;
            aOrbiterG = RotL64((aOrbiterG * 15272157962928021009U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10889800478505074438U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13728832441482547824U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17588477761978646139U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 28U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererI = aWandererI + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterH, 50U)) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24411U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 26171U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23388U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25977U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26187U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 13854738573712660276U) + aNonceWordP;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 16835460633412286294U) + aNonceWordN;
            aOrbiterH = ((aWandererA + RotL64(aCross, 3U)) + 6785859293758091931U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 23U)) + 126317283127992659U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 47U)) + 7568963536291415413U) + aPhaseDOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 57U)) + 12294016745653004819U) + aNonceWordH;
            aOrbiterA = (aWandererK + RotL64(aIngress, 13U)) + 18269588932920281147U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5872406424994751026U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7764434758831474129U;
            aOrbiterH = RotL64((aOrbiterH * 3772146788188420071U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4804168969415573371U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 959601763507651280U;
            aOrbiterG = RotL64((aOrbiterG * 4647396592804833217U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9257644462479293048U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 14332699366894494579U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 8829304078930625541U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10487012596470786004U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 612729229562321440U;
            aOrbiterA = RotL64((aOrbiterA * 11380387280507726003U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7845523921295625315U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12742115479740024747U;
            aOrbiterF = RotL64((aOrbiterF * 15578543510683986421U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10294667720904610944U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14369711143154904567U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13753005602288309379U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10918344717497681894U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + aPhaseDWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordD) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 54U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30819U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 29605U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30443U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27867U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 27392U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 12U)) + RotL64(aCarry, 53U)) + 16451272412693907816U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 19U)) + 10099485419723255462U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 57U)) + 17668900099534923192U) + aPhaseDOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererH + RotL64(aCross, 27U)) + 5497093724143181753U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 10354044773550071706U) + aNonceWordF;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 12728258851198019099U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 51U)) + 4144050505314242618U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14133805325480076530U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 308863673210602899U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2672613556981540433U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11741180130160569753U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12926863156769180448U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 9726030996091054939U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 211920854786494259U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13234608842479411078U;
            aOrbiterD = RotL64((aOrbiterD * 2556747209733759467U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9164711974854618892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6667377062281954219U;
            aOrbiterB = RotL64((aOrbiterB * 2603737166987437649U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4559040002406721850U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1749875480850675109U;
            aOrbiterI = RotL64((aOrbiterI * 15822640067349481089U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9555365165561936366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8727162691639622461U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 291406782452963706U;
            aOrbiterH = RotL64((aOrbiterH * 8413500075082350243U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 60U)) + aOrbiterD) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererG = aWandererG + (((RotL64(aCross, 28U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererH, 12U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB8B0E638CBA7CDC5ULL + 0xC4DAE5BEF6A017DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9C67A726DB899F59ULL + 0xAD2D30B24836FE69ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF27001D9068A89A3ULL + 0xB77AA3F6DDAB9DF0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB7E0782FB3AB1685ULL + 0xB6AF283C4BE361FAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC5C31DD6321813FULL + 0xA3E4B49F9D5F180AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB97FA8B05D265C63ULL + 0xBD9CA2DA303DE2ACULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA469B6E67EF5E3C5ULL + 0xB801DD220616276AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE474AC19B153DD47ULL + 0xFD2FF868C0656FB5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDA383B1B4F58FC29ULL + 0x8E2B73505FDBC2BEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF36FC765A833EC27ULL + 0x8428D7AF5820127BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA599E573AC3DD7D1ULL + 0x871D4B17CD077ABBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBE1BDB8140125907ULL + 0x9F5ED8780C5F04B6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBE5627DD03B6A24BULL + 0xB9BAD2E888B4D771ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC0A91A9D976EE6B7ULL + 0xD5B268A63976E633ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF70B64CD5C994A7FULL + 0xB261817606E75A45ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB0762D8734C8C443ULL + 0xED2D7D1EBA61D307ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4809U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((aIndex + 752U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5456U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 595U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 588U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1191U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 19U)) + 3561491146322798260U) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + 7075025056181885339U) + aNonceWordK;
            aOrbiterB = ((aWandererH + RotL64(aCross, 13U)) + 9230910887904171613U) + aNonceWordA;
            aOrbiterH = (aWandererB + RotL64(aIngress, 39U)) + 4119781172609908917U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 17155609083870983149U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 37U)) + 2423018561430181695U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 42U)) + 12957280305617615744U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 5U)) + 2461704174772065813U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 7907123257849391997U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 29U)) + 7257868138318960007U) + aPhaseEOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 41U)) + 16425903703085702285U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2990822664594079467U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5654819006718953817U;
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12183676471235678779U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15026286960542123922U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17199049329995315279U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12169080607071830522U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2906296852254787499U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6754514406846040163U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3029858695410344584U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14406410317495954566U;
            aOrbiterE = RotL64((aOrbiterE * 9663780721657983421U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11048818178401163861U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13622063920319445043U;
            aOrbiterJ = RotL64((aOrbiterJ * 2516025554421589857U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2642646089141233277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12761571777929273548U;
            aOrbiterI = RotL64((aOrbiterI * 5518252696078700127U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7753802695131502382U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8510425459525030222U;
            aOrbiterA = RotL64((aOrbiterA * 12412361423636026483U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13522645164493316722U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1437430302489702713U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14019316635365783545U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14745189473423751499U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16968328257002103715U;
            aOrbiterH = RotL64((aOrbiterH * 17915588590593471981U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5001838243344386314U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13506188720092630563U;
            aOrbiterC = RotL64((aOrbiterC * 7010027510838271877U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16902624500530747723U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3561491146322798260U;
            aOrbiterK = RotL64((aOrbiterK * 95761172090277669U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 28U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterG) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 24U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8930U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneC[((aIndex + 9765U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8695U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 10654U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9731U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9313U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7835U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 28U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 39U)) + 12380376990224645149U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 18296928500297384014U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 53U)) + 3550626816361145100U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 37U)) + 2667792936946706027U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 23U)) + 12020969779370926953U;
            aOrbiterD = ((((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 737340727886903447U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 19U)) + 1681797651799760502U;
            aOrbiterB = (aWandererI + RotL64(aCross, 50U)) + 2956186342689489064U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 57U)) + 1876852870402977177U;
            aOrbiterG = (aWandererF + RotL64(aCross, 27U)) + 6433205819353555071U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 3U)) + 9065076854974222998U) + aNonceWordG;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3254410578766789992U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2005081975473815576U;
            aOrbiterE = RotL64((aOrbiterE * 9947701153722014085U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15992999234834560419U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3458344156815120948U;
            aOrbiterD = RotL64((aOrbiterD * 1668460113964608051U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17069783053664877727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1260234710193913099U;
            aOrbiterB = RotL64((aOrbiterB * 4561226779897414381U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3825186451876061335U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2905344294992827535U;
            aOrbiterF = RotL64((aOrbiterF * 2469896090698580795U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18141402347899180617U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8760129857609925066U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2507999156108123047U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 594052473780678210U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13216719212966128379U;
            aOrbiterG = RotL64((aOrbiterG * 10691355329696722303U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10029948739466316169U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11912428807431992996U;
            aOrbiterJ = RotL64((aOrbiterJ * 85016510811938307U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8735634019801417287U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12785916159063273545U;
            aOrbiterH = RotL64((aOrbiterH * 1161917531260663357U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 367752057919802452U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3961036242431041564U;
            aOrbiterA = RotL64((aOrbiterA * 16352646009782597315U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3858415336170090719U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14325258358254321551U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12080431158781060059U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16872184337970977180U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12380376990224645149U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16559121155413059221U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 38U)) + aOrbiterB) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterA, 26U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16314U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 15642U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13359U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15980U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 13607U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 5U)) + 8793908991006073956U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 2932916283348441943U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 41U)) + 11069042087940968262U) + aNonceWordD;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 24U)) + 14369628676782894441U) + aNonceWordE;
            aOrbiterK = (aWandererK + RotL64(aCross, 53U)) + 8602903272780978282U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 3827036107178568820U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 21U)) + 8905245209036772489U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 36U)) + 13331387530760017893U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 9880107580289737823U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 27U)) + 10199619040626900278U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 43U)) + 2466307560891374281U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13973403407981259448U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2851460278409385243U;
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10365453393815690776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2382382358987358791U;
            aOrbiterJ = RotL64((aOrbiterJ * 481563628980705781U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5058198848163792422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10500434740387593487U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5946747708776079787U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 11289798395177667084U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14327152153231286666U;
            aOrbiterG = RotL64((aOrbiterG * 18155778059595245561U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8065137263811956313U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3865153574847924816U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9495741102667755161U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18102279969722473375U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6306428427188742325U;
            aOrbiterC = RotL64((aOrbiterC * 17826782872351406167U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16953348204663693724U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11950791817032898613U;
            aOrbiterI = RotL64((aOrbiterI * 1498946055469611133U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11980823193543752994U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17845490308799454871U;
            aOrbiterA = RotL64((aOrbiterA * 16385153013485463791U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5566398755702887071U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10308378271388889968U;
            aOrbiterE = RotL64((aOrbiterE * 142732084484961281U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6717846700455219260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8297225372883997017U;
            aOrbiterD = RotL64((aOrbiterD * 14102812043481327907U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12249337046267666603U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8793908991006073956U;
            aOrbiterF = RotL64((aOrbiterF * 5851229209188473467U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 43U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 60U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 50U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21022U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((aIndex + 17856U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19373U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19291U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17274U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererE + RotL64(aIngress, 22U)) + 12632404972795375757U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 29U)) + 5351879979055988456U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 3597737727467443413U) + aNonceWordP;
            aOrbiterF = ((aWandererD + RotL64(aCross, 51U)) + 2830846754917852318U) + aNonceWordL;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 53U)) + 17311925960294518018U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 2083584640523695383U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 15049343611387010158U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 39U)) + 6443050378205811147U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 37U)) + 6021965178697344070U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 14U)) + 5080289878758029976U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 41U)) + 576927745306972983U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4728489691382690859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6184355840165758855U;
            aOrbiterI = RotL64((aOrbiterI * 1515043910404156423U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11220539885798595450U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11091438724966718214U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8225347114759391961U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17184210490020062419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2150997767099116408U;
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7021953562676903717U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17159676348343312834U;
            aOrbiterB = RotL64((aOrbiterB * 13877284519668483549U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10367891770525239784U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11922478487264201233U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9195137452661956029U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17815162358981720634U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 9582631251085100284U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 11838992994130850483U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 872593750259572264U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17832330100262167302U;
            aOrbiterA = RotL64((aOrbiterA * 1114416841510028467U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16601139856969287418U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14931287111691324985U;
            aOrbiterG = RotL64((aOrbiterG * 16757174577841001179U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11413072442039115924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15253605470589905889U;
            aOrbiterF = RotL64((aOrbiterF * 10832817442285245673U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3653487723581514107U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14891378240114471865U;
            aOrbiterH = RotL64((aOrbiterH * 1386594204573386051U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15659724464711852035U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12632404972795375757U;
            aOrbiterJ = RotL64((aOrbiterJ * 2407347385127296647U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 36U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aNonceWordO) + aPhaseEWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 50U)) + aOrbiterI) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24725U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((aIndex + 24495U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23899U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25538U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24705U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23457U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (((aWandererH + RotL64(aIngress, 11U)) + 5171470532667965920U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 41U)) + 750549462358682403U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 20U)) + 3325689257577120525U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 18031575461559790826U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 23U)) + 13874739537012288677U) + aNonceWordJ;
            aOrbiterK = ((aWandererE + RotL64(aCross, 5U)) + 4250029868785016865U) + aNonceWordP;
            aOrbiterG = (aWandererG + RotL64(aIngress, 53U)) + 8211158803112611161U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 34U)) + 1083939790236786027U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 3446525462376962464U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 57U)) + 6973817815000417325U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 15230876489676945543U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9359727659738755880U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8775170107816327654U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6910680458261008653U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11958941755525038545U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16966819714283167348U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 16363457661846050749U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14556087985619763243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17915047508377045221U;
            aOrbiterI = RotL64((aOrbiterI * 6727635453185130109U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8578745677485367222U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7002181668717618866U;
            aOrbiterC = RotL64((aOrbiterC * 12329703532414955235U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3569939503066735457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2956247934282522184U;
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4285180013402474041U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5976239869535619811U;
            aOrbiterB = RotL64((aOrbiterB * 3458095419039067465U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2424524955161695463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6849595426583763537U;
            aOrbiterA = RotL64((aOrbiterA * 12727902040238318101U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11414890686374886716U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5668287266836153445U;
            aOrbiterF = RotL64((aOrbiterF * 8011885266143066285U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9976985606260445887U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9223940029500676834U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8508023992488499955U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4480967907876921958U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5132766654502526597U;
            aOrbiterE = RotL64((aOrbiterE * 321625389942019245U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12921555132452983464U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5171470532667965920U;
            aOrbiterG = RotL64((aOrbiterG * 9710487797420618879U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 26U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 34U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29353U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 27561U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31539U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28719U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 28616U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 37U)) + 12809562813316740345U) + aPhaseEOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 51U)) + 17084212535326321199U) + aNonceWordL;
            aOrbiterC = (((aWandererI + RotL64(aCross, 24U)) + RotL64(aCarry, 47U)) + 16074921689983846769U) + aNonceWordN;
            aOrbiterG = (aWandererB + RotL64(aScatter, 21U)) + 14027986153007120145U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 43U)) + 7633455951809250227U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 5U)) + 340989348513370174U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 5307820377645020116U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 39U)) + 5605285015771527274U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 5293500434746182790U;
            aOrbiterK = (aWandererK + RotL64(aCross, 3U)) + 7263156475892261811U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 18U)) + 10672879570907433005U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16659226780900986107U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9774892622769850665U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10728057184108279042U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5032485856947407217U;
            aOrbiterH = RotL64((aOrbiterH * 16651577903809154285U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 14642241075374862345U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8386481273395203518U;
            aOrbiterA = RotL64((aOrbiterA * 11649977733867003445U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2874153265304098104U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11519900149177261000U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2010158758971864505U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8885690878540115768U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4482143389870987714U;
            aOrbiterK = RotL64((aOrbiterK * 7105332459437434281U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17469068567801886615U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5121422018622394837U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 14823827133212643467U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3130788210672745618U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6139244627510113216U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 2640754184921507389U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10488511756324474710U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1760223670304953696U;
            aOrbiterD = RotL64((aOrbiterD * 4007062295003769311U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2232708414171096783U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17497492434939621063U;
            aOrbiterB = RotL64((aOrbiterB * 9850565931511937725U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8199114561613022892U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15432482434863050835U;
            aOrbiterI = RotL64((aOrbiterI * 14271143436318169871U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14991531324947777062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12809562813316740345U;
            aOrbiterJ = RotL64((aOrbiterJ * 4487021480964944879U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 44U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aNonceWordF) + aPhaseEWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterA, 24U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 30U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9913DD7D26695249ULL + 0xFA05171FABDBB9B3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x850C2580DE9B8C39ULL + 0xDFEBB9F236EE97DCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFA41C4282B142ABFULL + 0xBD490FF572FFA6B8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8A3B5583400FD8F5ULL + 0xC70817C529630134ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD5EC049A8FF75913ULL + 0x940B29E04B0BF622ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9CF5CA0277029175ULL + 0xFDCC16DDFDCDF3ABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x88E2DEDD90FC1655ULL + 0xE73676D62EBDBC81ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x90DCBF47CBD6E4F9ULL + 0xB64EC2E734B1C35EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x83181F053525D77DULL + 0xE1799F6E10960403ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x834B91479E35C851ULL + 0x9FFBA336D62DF762ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x849119192A428667ULL + 0x86E7B856726963C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB47E9094BFFEA9DFULL + 0x89B873AEFCE68E48ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCBF7A1E0A32D1411ULL + 0xA73D88A13D2432E8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC5A848D3532E42D1ULL + 0x814A21436480A679ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x81B86565C6822715ULL + 0x9D87AB39E8EC497FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD673D216A2D3E9EFULL + 0xDEE4E108AC81F581ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneB, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aInvestLaneA, aWorkLaneC, aSnowLaneD, aInvestLaneD, aExpandLaneA, aInvestLaneC, aExpandLaneB, aInvestLaneB, aExpandLaneC, aWorkLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 168U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 874U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 5392U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2468U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5371U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 4588U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 58U)) + 13924571355038625040U;
            aOrbiterF = ((((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 16328300979357156658U) + aPhaseFOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 3947771961206012461U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererF + RotL64(aIngress, 39U)) + 15428284250569311285U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 6U)) + 5777369485254032486U) + aNonceWordN;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 16813320300717644673U;
            aOrbiterI = (aWandererG + RotL64(aCross, 23U)) + 16689933050200758251U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 1856422419049390708U) + aNonceWordE;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 19U)) + 18214498743831925517U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18278550878494094923U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 797712062039591797U;
            aOrbiterK = RotL64((aOrbiterK * 7212998747080137625U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15854849439012341347U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 996882939768167773U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 14936703950807908575U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3005829974130671692U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8793495343509953906U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14065479348374612031U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7710453029930631112U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9511995836117707047U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 7250766204781428201U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 670902975693341744U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9045820304668279777U;
            aOrbiterD = RotL64((aOrbiterD * 18373074917532639027U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12417212387607119470U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12816983560669985622U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8406003970221889847U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17245432086377688540U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6806521945548502014U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 11335859481858640857U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8947500746292365294U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4468060468522895852U;
            aOrbiterI = RotL64((aOrbiterI * 7022481284816599797U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9892975931958803992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3042599331526937836U;
            aOrbiterG = RotL64((aOrbiterG * 3308512896171443645U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 50U)) + aOrbiterA) + aNonceWordK) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 27U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 35U)) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 54U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9648U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 8211U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8906U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((aIndex + 7819U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6848U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7488U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6331U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 58U)) + 4980738603982643969U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 27U)) + 17660278413018470020U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 39U)) + 17598114429859543466U) + aNonceWordI;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 10993929335279994739U;
            aOrbiterA = ((((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 17967203122976322481U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aWandererH + RotL64(aScatter, 43U)) + 1872290205549034384U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 16607778671782810797U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 3U)) + 4895226930754394376U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 54U)) + 14960359005982301383U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9921642352377700630U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 893281964367208693U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 2345509157333444217U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8232519988397858732U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4433022122758913407U;
            aOrbiterB = RotL64((aOrbiterB * 834240393225479419U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12689609831247168353U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 404535388957472176U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3349108201964013155U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4386449511297371730U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9596273264321140229U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14314587717949070586U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10923886625271054985U;
            aOrbiterF = RotL64((aOrbiterF * 7838969002623486809U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17634909585329833520U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2021301459918350372U;
            aOrbiterE = RotL64((aOrbiterE * 1388242915918642741U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5219599112498224367U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10641339455385046206U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 1022283727595400719U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5003342156562330058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10951027475628404336U;
            aOrbiterG = RotL64((aOrbiterG * 17836928292555158461U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13040991872592235460U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11149099984302782267U;
            aOrbiterA = RotL64((aOrbiterA * 4248667283139686251U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 22U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + aNonceWordG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterA, 46U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aCross, 24U) + RotL64(aOrbiterJ, 36U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11072U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 13933U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 13092U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15971U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15792U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 10812151398716051703U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 12U)) + RotL64(aCarry, 41U)) + 18202551453336003710U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 21U)) + 9434410809101973752U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 12955829998028534045U) + aNonceWordJ;
            aOrbiterC = ((aWandererA + RotL64(aCross, 5U)) + 12271740641929640181U) + aNonceWordF;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 53U)) + 14009351527014534752U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 26U)) + 4316296955679133450U) + aNonceWordN;
            aOrbiterG = (aWandererE + RotL64(aScatter, 41U)) + 16473324966997442872U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 47U)) + 15735123324965019802U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17656375090484080236U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16066325053456055298U;
            aOrbiterD = RotL64((aOrbiterD * 17912970706985130327U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12908968778503516903U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12761433987676836197U;
            aOrbiterK = RotL64((aOrbiterK * 1023329467480907925U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12737513138040664509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14535795767570998392U;
            aOrbiterH = RotL64((aOrbiterH * 15560519667062222269U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14370908061811284364U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7001358781208669795U;
            aOrbiterE = RotL64((aOrbiterE * 11641248025734015835U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7298578161120090849U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10498302152357484629U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13144110412179037175U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11447343228638006767U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18284143620422655675U;
            aOrbiterF = RotL64((aOrbiterF * 572862190073605651U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5918253208127360199U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3910541329178205943U;
            aOrbiterG = RotL64((aOrbiterG * 4550654545328228103U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10357053096941367910U) + aNonceWordC;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 5610891501128498748U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 8676370811772047449U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9049881176058575811U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6307599924966452216U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 5551444450572055895U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterK, 48U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 34U)) + aOrbiterC) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21809U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((aIndex + 21601U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 20886U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19303U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 19997U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 34U)) + 9041099828460168106U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 12883711604096848454U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 47U)) + 17420968786226443079U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 3448213891716125104U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 51U)) + 11866455977445336560U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + 4119356835384495905U) + aNonceWordL;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 2186212599698637068U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 6506144898969301620U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 18U)) + 12556800923644051626U) + aNonceWordM;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4075551535185182945U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17877694808492008749U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 901315308379887473U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5553428900598223316U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14362304852277160675U;
            aOrbiterF = RotL64((aOrbiterF * 11415103199856419303U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9174200302876075831U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16110739511917638547U;
            aOrbiterD = RotL64((aOrbiterD * 7004356839428657949U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10189881974519849402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2128076632642616677U;
            aOrbiterE = RotL64((aOrbiterE * 8860453653433114929U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18133523799074400083U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9916472958834153766U;
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10274457562795569227U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14134814273275356425U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15912501063665343159U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6394306369514735480U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4825761192736485643U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12534544147331805643U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5672807934779206275U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3881953574159390421U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7448770570912161095U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12012232712634303203U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14176392925893052596U;
            aOrbiterJ = RotL64((aOrbiterJ * 11288668529893084583U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterI, 23U));
            aWandererI = aWandererI + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aNonceWordF) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterH, 44U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27041U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneD[((aIndex + 23798U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27244U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23838U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneC[((aIndex + 25561U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 10U)) + 11410829607777684449U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 7502698839700975347U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 57U)) + 13267685058252106173U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 5U)) + 238242706996630625U;
            aOrbiterK = (aWandererD + RotL64(aCross, 35U)) + 8184695499511454281U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 18U)) + RotL64(aCarry, 39U)) + 12767823220461985403U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 12293198423143850330U) + aNonceWordN;
            aOrbiterI = (aWandererG + RotL64(aIngress, 47U)) + 11149495229952495939U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 53U)) + 7556992689338382800U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3431338808774134649U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16863099140844995099U;
            aOrbiterJ = RotL64((aOrbiterJ * 752376661101787919U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 17872458049880677604U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16760153457252546974U;
            aOrbiterK = RotL64((aOrbiterK * 11225037229069712805U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3115544493537438408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4359882942759752958U;
            aOrbiterA = RotL64((aOrbiterA * 561477566995575801U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13387113067202396536U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12955690074544490161U;
            aOrbiterE = RotL64((aOrbiterE * 12449941770827974511U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15614054443728226807U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1939441328066616114U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 4484917074808974359U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4599016263007782537U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9962305629016158048U;
            aOrbiterH = RotL64((aOrbiterH * 1496184427500037279U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8428467674122750557U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3938884087806393439U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12810531094050481761U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6018636830758044658U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1510372000641305416U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9002834928626918247U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17592782466215337843U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8119921507606870360U;
            aOrbiterI = RotL64((aOrbiterI * 1299795061644535485U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 38U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterE, 46U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterB, 50U));
            aWandererA = aWandererA + (((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28686U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 27919U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30844U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29240U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((aIndex + 29089U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 19U)) + (RotL64(aCarry, 36U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 39U)) + 3448371607470865612U) + aNonceWordF;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 3743742913651580573U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 11U)) + 13069491287948807280U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 58U)) + 16872779275586545632U) + aNonceWordH;
            aOrbiterD = (aWandererA + RotL64(aScatter, 53U)) + 17945792656755062795U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 18199747196793731853U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 43U)) + 15953311878379809513U) + aNonceWordN;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 941268763494588338U) + aNonceWordG;
            aOrbiterA = (aWandererD + RotL64(aCross, 24U)) + 10090221530365796809U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8335698093307607001U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6147498804734306100U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6904444049941211327U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5980246079567570090U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4152167624425912978U;
            aOrbiterD = RotL64((aOrbiterD * 10019421651535123573U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14990418790239735916U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3418668387496597219U;
            aOrbiterK = RotL64((aOrbiterK * 12814077238529863119U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4206650904177199425U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3905470780938996069U;
            aOrbiterH = RotL64((aOrbiterH * 16030122739273137005U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9968672788233080924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 602258075661864866U;
            aOrbiterC = RotL64((aOrbiterC * 2615726693066300065U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17751667243048041383U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2414054413585296027U;
            aOrbiterF = RotL64((aOrbiterF * 1049512574773201893U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6523322402744047752U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6729901917767398779U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 8039939871405367139U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11460169185076814539U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7559640379553110573U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9864654321914036135U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 17271150091827475028U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3541809324556914646U;
            aOrbiterA = RotL64((aOrbiterA * 12655168871428868639U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterA, 10U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aNonceWordD);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aNonceWordL) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 14U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB0484ABB7859838BULL + 0xC37D2AAA3686FC25ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB3CC4B089B4E2BCDULL + 0xB8ADAF5DAD4F7832ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x906B468EA8A29C57ULL + 0xEBBB68030BA6B446ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC49B5123122B20BFULL + 0x9A281CC566E9E25FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8892C12DEFDABACDULL + 0x97DD13B6B75ECC9AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x953EADE987010297ULL + 0xE15B5AD090D8B77EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE6E86249B490128BULL + 0xB75CB5412555C308ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF1B337161E66C525ULL + 0xF0CD27E0AF108161ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF4315C16E23A3769ULL + 0xBB81C97E80384B94ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x933B605C4563D8EBULL + 0xF12A50BF90F3161BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA6B7353E11990CCDULL + 0xFD699C638D2F2660ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBC8B89B347320CD9ULL + 0x8B1D498C51B38592ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD45D06966FBEFAA5ULL + 0xC7FE98333263F4CAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA988EDE5569EA5E7ULL + 0xC7E0CA047B31C070ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF4FC00878B8AED8DULL + 0x8AB6F7FD3901836BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDA4D6B2B2A881B07ULL + 0x8B545EAD06CF6180ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneC, aSnowLaneC, aSnowLaneD, aInvestLaneD, aWorkLaneA, aInvestLaneB, aFireLaneC, aWorkLaneB, aFireLaneB, aExpandLaneA, aInvestLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2332U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((aIndex + 321U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1862U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3743U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3323U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 5154U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 60U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 13960289014350612206U) + aNonceWordI;
            aOrbiterF = (aWandererG + RotL64(aScatter, 35U)) + 3483331015269589730U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 53U)) + 6873299241002444518U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 60U)) + 3562094007125534229U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 11422367439932782705U) + aNonceWordL;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 532453428514259816U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 5U)) + 17810941465810193088U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11869759058631106331U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8837581071876177566U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15329827515970522213U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17185378327053837778U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7578253375676981500U;
            aOrbiterC = RotL64((aOrbiterC * 13371647568758721729U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17112646434432814442U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14949096407295697881U;
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4259590620758467836U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6534899413644542303U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 7987609419215568661U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2637407498893694243U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15819295597921425711U;
            aOrbiterE = RotL64((aOrbiterE * 5202015597375051399U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6373559542002699718U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3308736483775453062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12749929710650475901U;
            aOrbiterA = RotL64((aOrbiterA * 248428400724560945U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 42U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aNonceWordP) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 58U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7282U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneC[((aIndex + 10639U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6767U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 8879U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7826U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6183U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 10879U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 28U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 57U)) + 17019646486641172469U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 28U)) + 12276141179299971572U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 3617241694029841555U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 6967963401259371737U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 11U)) + 6340709284279891017U) + aNonceWordA;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 456065368903896482U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 35U)) + 17686765719908116203U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1322045955429785736U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 5163772703302372887U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 3193272189179082313U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13268431135020363252U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6538789950366849332U;
            aOrbiterB = RotL64((aOrbiterB * 5352960308459065837U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10390344544314544893U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5087084271300584267U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 15149302947570776165U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13423071121590981727U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18324443012024134729U;
            aOrbiterC = RotL64((aOrbiterC * 15814349432207734533U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4129091815978464507U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17024797553831962245U;
            aOrbiterJ = RotL64((aOrbiterJ * 3137753479364378175U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6501545108779991661U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11930037791867597447U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4904739567549702851U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4667298703308315851U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6315980380900062127U;
            aOrbiterG = RotL64((aOrbiterG * 12080555704907924637U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterI, 4U));
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12633U)) & S_BLOCK1], 34U) ^ RotL64(aSnowLaneA[((aIndex + 14337U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11457U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14625U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneC[((aIndex + 11046U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 21U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 48U)) + 4204560462077827182U) + aPhaseHOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 6572370199668594039U) + aNonceWordG;
            aOrbiterC = (aWandererI + RotL64(aIngress, 29U)) + 15958999876732622825U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 9969349486879280377U) + aPhaseHOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 15450238998293956181U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 13U)) + 9128619863683138259U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 19U)) + 5691270563628979565U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5901029710568933106U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10442738941988588834U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7386621444831603817U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3508116020325721993U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13221917083569767259U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6845108555710135357U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11627915460377128176U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17858261365514253433U;
            aOrbiterJ = RotL64((aOrbiterJ * 7535577636975884641U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 4294837988806295989U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11242915481585070249U;
            aOrbiterH = RotL64((aOrbiterH * 17540688242763829319U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13030663829236027109U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7451948220723185149U;
            aOrbiterF = RotL64((aOrbiterF * 5191778587712222029U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5575508866505031037U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5161096033789876794U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 16843827915802461797U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3980482740649505122U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11188906150207270241U;
            aOrbiterI = RotL64((aOrbiterI * 408550837615188413U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordH) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 12U)) + aOrbiterI) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17368U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 17860U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 17333U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20183U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneD[((aIndex + 17834U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 53U)) + 16200278595895089008U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 39U)) + 1029614154810465897U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 7129562468705441295U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 47U)) + 14388903902433951274U) + aPhaseHOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 11U)) + 1013568949315967455U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 27U)) + 3128823373497815651U) + aNonceWordB;
            aOrbiterG = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 14525694606889470589U) + aNonceWordO;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14443983602196782887U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12244220415328641190U;
            aOrbiterD = RotL64((aOrbiterD * 15052949098014803181U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10477159225338766614U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2842870123078131566U;
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8621138818955849917U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5038396344400303181U;
            aOrbiterG = RotL64((aOrbiterG * 14636756322207385447U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2768613802894372496U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2027754864051410015U;
            aOrbiterB = RotL64((aOrbiterB * 2461322540050569287U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2848088309172056399U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterE = RotL64((aOrbiterE * 9926904679902843055U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 9079797279596336139U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 15424866642305110811U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 12912331089970158845U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13751764050290602740U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7694557131324740282U;
            aOrbiterF = RotL64((aOrbiterF * 14980807690491467023U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterF, 26U)) + aNonceWordC) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aNonceWordK) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23216U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 23999U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 26135U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23540U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26939U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 34U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 6771552164800695068U) + aPhaseHOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 23U)) + 12131763371571322040U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 60U)) + 3326182381395522013U;
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 12288775097697156383U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 5195948373449796741U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + 14404044002250137144U) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aCross, 51U)) + 11142382920035825426U) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2967149520256475485U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1470907369577818097U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9398653295177725883U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9231668148004163910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13078929163913892386U;
            aOrbiterE = RotL64((aOrbiterE * 7509829068700523627U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 9485274692075657877U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12216951187543631673U;
            aOrbiterI = RotL64((aOrbiterI * 6571066246507310805U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6933334652581744234U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17260276102423580920U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 7796879893790990605U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 387767848169714392U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8597538259308082638U;
            aOrbiterC = RotL64((aOrbiterC * 4888054690557707241U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7996708724489146033U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15357384191688149939U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9827691726832491373U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17739222908739454637U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1614322333281471170U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7063116837752240891U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 60U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + aNonceWordE) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterA, 53U));
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 41U)) + aOrbiterK) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28097U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 29118U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28830U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30047U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 28079U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 13880995121909552664U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 11U)) + 14534942818069300546U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 17745973100886007133U) + aNonceWordA;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 2249805580771946872U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 4460116116396439410U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 20U)) + 3378683994078106878U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 53U)) + 3992996501048809123U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12057768808864451929U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 4115362079047921130U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 12263015903331031345U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15297384955502206698U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17623548383481905636U;
            aOrbiterG = RotL64((aOrbiterG * 7487278217901483685U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3559213898000162417U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 12311605719074507335U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3982199462062847697U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14807313864347885885U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11222085523291581822U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12580941911587215653U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 916681229436292462U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2441350114032314686U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7336079498999018067U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7361470539894653271U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12153585147213579808U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 3040327545467672961U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13566300726101613579U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14875254144748509128U;
            aOrbiterE = RotL64((aOrbiterE * 13699179902908972403U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 44U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordC) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aIngress, 48U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 60U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1748U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 1196U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 740U)) & W_KEY1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1903U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 2558105147674438050U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 15856662514774702561U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 47U)) + 13346869226246584582U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 35U)) + 7632111846116243973U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 54U)) + 2102101361626976279U;
            aOrbiterK = (aWandererB + RotL64(aCross, 13U)) + 5605968705067851563U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 6842483186584326681U) + aPhaseAOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 23U)) + 5559797213819425064U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 60U)) + 12422313931331576759U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2751024420047872601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11031320239359798610U;
            aOrbiterD = RotL64((aOrbiterD * 8607639453141148025U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14366375309473793217U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11971479429768505316U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3947595951884469542U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17882767922372770896U;
            aOrbiterE = RotL64((aOrbiterE * 3361906348965810211U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 513871456983509223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5951677013597794294U;
            aOrbiterB = RotL64((aOrbiterB * 8508629569649935293U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 437626309049021931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 466674061172005705U;
            aOrbiterJ = RotL64((aOrbiterJ * 1310502572084891157U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12362602809233133718U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10525852878882195702U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17755022180514914325U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17927000184308583095U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 566723721423470052U;
            aOrbiterI = RotL64((aOrbiterI * 17710534355278632573U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9504585484034413577U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4614306037721859929U;
            aOrbiterG = RotL64((aOrbiterG * 170807293799483539U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1463218357720031588U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4036696102163560633U;
            aOrbiterA = RotL64((aOrbiterA * 15389914226155130065U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 18U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 14U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3511U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5223U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3790U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 3621U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 10U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 35U)) + 14823268998003220191U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 35U)) + 15295237288788213847U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 39U)) + 16434853402001133899U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 13U)) + 7555911304407871631U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 29U)) + 14977248264994834620U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 47U)) + 9707764144919392380U) + aPhaseAOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 1277304385464681529U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 3089786220465849395U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 22U)) + 3700503853358695085U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3240054112993517371U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16897532076915366859U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4120874717534309035U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18167359289798364307U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8870819278575769863U;
            aOrbiterC = RotL64((aOrbiterC * 9334066154398059075U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15363069206212330251U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14858164441499725158U;
            aOrbiterF = RotL64((aOrbiterF * 14931933411393847915U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5357144808788707522U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2910681277417754860U;
            aOrbiterK = RotL64((aOrbiterK * 13170868582159347059U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9824408699018165151U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 368370224788793300U;
            aOrbiterI = RotL64((aOrbiterI * 14358982366258729959U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7095398304588825115U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11418879758164313554U;
            aOrbiterD = RotL64((aOrbiterD * 5983520332639771791U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2171599720681913272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17593730219647495033U;
            aOrbiterG = RotL64((aOrbiterG * 12926053208918563087U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17755947635188715523U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14565740605227022106U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15866418354612945335U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14538017880915584414U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6174566474851449123U;
            aOrbiterJ = RotL64((aOrbiterJ * 179569008593475683U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 58U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 56U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterF, 5U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7976U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadB[((aIndex + 7170U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5776U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5589U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7718U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 34U)) + 5721224134332887360U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 3U)) + 6892749729775049095U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 19U)) + 3884839462099556836U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 4365431706830216193U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 53U)) + 15501528746571578773U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 48U)) + 4505911326320650606U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 1865129050927879580U) + aPhaseAOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 27U)) + 2011737665969640369U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 611672935827062688U) + aPhaseAOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 663547038310431047U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5468932264754299556U;
            aOrbiterI = RotL64((aOrbiterI * 11968657455484578525U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17920294117231191705U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 486058453837528110U;
            aOrbiterF = RotL64((aOrbiterF * 8851102552244026737U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2789178451938129313U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 420772587981211184U;
            aOrbiterC = RotL64((aOrbiterC * 17402987842294006667U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16196774774442181825U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16264169656793713547U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6900221986041638783U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10207659833859860796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8593749091183323678U;
            aOrbiterD = RotL64((aOrbiterD * 10696776033512404927U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7224922076047787384U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15366267474865172373U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10134187073321814217U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4235342515820080294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5239480080426950612U;
            aOrbiterB = RotL64((aOrbiterB * 12077621553561927079U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10891752830598395582U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7797358829694471108U;
            aOrbiterG = RotL64((aOrbiterG * 7621206775460997431U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3755715857903753416U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3172069024987421726U;
            aOrbiterA = RotL64((aOrbiterA * 16048490837178650865U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 36U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterJ, 52U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9256U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 8867U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 10101U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9119U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8204U)) & W_KEY1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8195U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 58U)) + 3448371607470865612U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 3743742913651580573U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 13U)) + 13069491287948807280U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 16872779275586545632U) + aPhaseBOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 53U)) + 17945792656755062795U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 39U)) + 18199747196793731853U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 19U)) + 15953311878379809513U;
            aOrbiterE = (aWandererE + RotL64(aCross, 24U)) + 941268763494588338U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 10090221530365796809U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8335698093307607001U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6147498804734306100U;
            aOrbiterF = RotL64((aOrbiterF * 6904444049941211327U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5980246079567570090U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4152167624425912978U;
            aOrbiterC = RotL64((aOrbiterC * 10019421651535123573U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14990418790239735916U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3418668387496597219U;
            aOrbiterA = RotL64((aOrbiterA * 12814077238529863119U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4206650904177199425U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3905470780938996069U;
            aOrbiterG = RotL64((aOrbiterG * 16030122739273137005U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9968672788233080924U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 602258075661864866U;
            aOrbiterD = RotL64((aOrbiterD * 2615726693066300065U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17751667243048041383U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2414054413585296027U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1049512574773201893U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6523322402744047752U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6729901917767398779U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8039939871405367139U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11460169185076814539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7559640379553110573U;
            aOrbiterK = RotL64((aOrbiterK * 9864654321914036135U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17271150091827475028U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3541809324556914646U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12655168871428868639U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 6U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 18U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + aPhaseBWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aPhaseBWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 34U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13156U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 13256U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11276U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 12195U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13407U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12851U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12361U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 21U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 29U)) + 15910560457440369082U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 18U)) + 17953072986407436888U) + aPhaseBOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 5U)) + 15446940721193538669U;
            aOrbiterF = (aWandererK + RotL64(aCross, 39U)) + 3020785262774422009U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 7001288645424994404U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 13385250665458462689U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 12U)) + RotL64(aCarry, 19U)) + 4841895644623005949U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 13053476783239482065U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 47U)) + 641996979335975244U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16211238020928688299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12715448751323279480U;
            aOrbiterB = RotL64((aOrbiterB * 2116880429675303291U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17784406727699995290U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16626339815786580778U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13940754474750138041U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9035070625716345139U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6085848172494001945U;
            aOrbiterG = RotL64((aOrbiterG * 10405728912339646693U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1177103851507561053U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2281901691017816407U;
            aOrbiterA = RotL64((aOrbiterA * 3142197009403602497U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9040984343694325070U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13334258224023902365U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4782523727707164869U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1079824790138592518U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14024082692012948652U;
            aOrbiterE = RotL64((aOrbiterE * 3219489374333737903U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2966776524421278970U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5510281854029308547U;
            aOrbiterF = RotL64((aOrbiterF * 9275402927591867297U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7126632329316720048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1476827035602733472U;
            aOrbiterK = RotL64((aOrbiterK * 2217671289726794033U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6470212302133184965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4172257438373147415U;
            aOrbiterH = RotL64((aOrbiterH * 4449314239630366533U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererH = aWandererH + ((RotL64(aCross, 54U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 58U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterE, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 46U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16257U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 15119U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16059U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16000U)) & W_KEY1], 39U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15624U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16380U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14992U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 56U)) + 10336802574069791273U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 169025388197058936U;
            aOrbiterG = (aWandererD + RotL64(aCross, 23U)) + 6541354188379168846U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 16223920526599306104U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 12756613707692514808U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 27U)) + 5082475548176484035U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 60U)) + 4907435526952698526U) + aPhaseBOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 41U)) + 14236627073831834337U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 11502511046130497584U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3679044835550219497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11254838916686736746U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10582608424233200966U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4628253464169957835U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17664454668473204465U;
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3798386391743884889U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1379331161819246587U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9816600392407327227U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16781971616348376878U;
            aOrbiterD = RotL64((aOrbiterD * 12503867584828289879U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4807797577690520554U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2492057261148595922U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9453302540675483005U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7909676419643119585U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 256053568910383007U;
            aOrbiterI = RotL64((aOrbiterI * 11965085163352053161U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16179914439220412472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3968867762761955845U;
            aOrbiterF = RotL64((aOrbiterF * 7473632378251893139U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7474832923901283742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 6U)) + aOrbiterA) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17929U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 17586U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(mSource[((aIndex + 18001U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 17395U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18781U)) & W_KEY1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16556U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17046U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 46U)) + 8866844335448071821U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 15159698739856430085U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 39U)) + 9582805772989594633U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 1438538239931588373U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 10862044156620436139U;
            aOrbiterB = (aWandererC + RotL64(aCross, 23U)) + 13682173320058164615U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 10U)) + 8351013291045977592U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 35U)) + 15777857431516633916U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 16178966745333885377U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9031889187993001617U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6308472367425865347U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17118710301967158153U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 642109145903321046U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9186268569255318035U;
            aOrbiterB = RotL64((aOrbiterB * 10714674348507516749U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6091345356803675860U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13218507921880873749U;
            aOrbiterD = RotL64((aOrbiterD * 15415157927185637717U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4266652275234474616U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4391422098164506195U;
            aOrbiterJ = RotL64((aOrbiterJ * 17634679403195085867U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5160682323243635577U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10351728852161347404U;
            aOrbiterK = RotL64((aOrbiterK * 11105410036471745951U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3950932176454814023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9536466386833427441U;
            aOrbiterE = RotL64((aOrbiterE * 18064984243491293435U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9927425919978776529U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6819384090527481081U;
            aOrbiterA = RotL64((aOrbiterA * 18032965969184368561U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1646274931424218507U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16166524473976135097U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11672192658072663849U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11252501968059485262U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16847854447987609067U;
            aOrbiterH = RotL64((aOrbiterH * 6326299154627028295U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 36U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterA, 58U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 34U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21186U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 21164U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19826U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 20097U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20972U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21736U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21720U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20936U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 4U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 39U)) + 8793908991006073956U) + aPhaseCOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 29U)) + 2932916283348441943U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 14U)) + 11069042087940968262U;
            aOrbiterD = (aWandererA + RotL64(aCross, 3U)) + 14369628676782894441U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 8602903272780978282U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 3827036107178568820U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 24U)) + 8905245209036772489U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 13331387530760017893U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 9880107580289737823U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10199619040626900278U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2466307560891374281U;
            aOrbiterB = RotL64((aOrbiterB * 6295342978834217571U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13973403407981259448U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2851460278409385243U;
            aOrbiterG = RotL64((aOrbiterG * 11226902976321781743U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10365453393815690776U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2382382358987358791U;
            aOrbiterH = RotL64((aOrbiterH * 481563628980705781U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5058198848163792422U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10500434740387593487U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5946747708776079787U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11289798395177667084U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14327152153231286666U;
            aOrbiterK = RotL64((aOrbiterK * 18155778059595245561U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8065137263811956313U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3865153574847924816U;
            aOrbiterC = RotL64((aOrbiterC * 9495741102667755161U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18102279969722473375U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6306428427188742325U;
            aOrbiterI = RotL64((aOrbiterI * 17826782872351406167U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16953348204663693724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11950791817032898613U;
            aOrbiterE = RotL64((aOrbiterE * 1498946055469611133U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11980823193543752994U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17845490308799454871U;
            aOrbiterD = RotL64((aOrbiterD * 16385153013485463791U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 24U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 48U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterI, 6U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 24U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23864U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadA[((aIndex + 22602U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24464U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((aIndex + 22269U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22160U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22348U)) & S_BLOCK1], 40U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24279U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((aIndex + 22132U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 3U)) + 14624277139785904404U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 6966977309498165611U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 205536824352530761U) + aPhaseCOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 16629575265808255692U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 28U)) + 596881340147972746U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 11944412799107412650U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 4615021315668210206U;
            aOrbiterD = (aWandererI + RotL64(aCross, 37U)) + 8497630055977606216U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 46U)) + 11131601107309336885U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5935883479805510099U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15629346719765798174U;
            aOrbiterH = RotL64((aOrbiterH * 8535523790685945275U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5279128339113651273U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16778365912440331821U;
            aOrbiterC = RotL64((aOrbiterC * 705421028266789241U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16003052937645491524U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6723226158737614764U;
            aOrbiterD = RotL64((aOrbiterD * 16690657664909260573U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9785784358981219543U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10055457337292292710U;
            aOrbiterE = RotL64((aOrbiterE * 17919129940751761111U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11779163108592974175U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1177999477942202687U;
            aOrbiterJ = RotL64((aOrbiterJ * 13475069421684114643U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9190694445141492214U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15605342360346353457U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14547769706392595647U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14877565450677523492U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1074095623308025684U;
            aOrbiterA = RotL64((aOrbiterA * 7884068939436891093U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12803174154216941583U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8813356463693637033U;
            aOrbiterK = RotL64((aOrbiterK * 4898237214617563167U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6063909634038581414U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15112191502834052566U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6780741782103553485U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 42U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 36U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 14U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 60U));
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26115U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[((aIndex + 27002U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24959U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26100U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26363U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26472U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24576U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24857U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 57U)) + 1866656689936219099U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 3U)) + 2312314528139448289U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 47U)) + 3554037526469185237U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 39U)) + 405707755060974111U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 14U)) + RotL64(aCarry, 53U)) + 1862976326004007697U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 53U)) + 12992483065443288263U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 3793854946371595197U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 4244007978867369382U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 30U)) + 10280867500312580308U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 472563452959164242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12041770406895816553U;
            aOrbiterK = RotL64((aOrbiterK * 17811798500132002631U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6118634015704900486U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13637107920449233307U;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16673735670669318830U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8602681273646630496U;
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7683264695930369476U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9146674871199188218U;
            aOrbiterA = RotL64((aOrbiterA * 7403427067419261981U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3012935612827493084U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1259789268731661945U;
            aOrbiterC = RotL64((aOrbiterC * 2372843620327050137U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5623690455471160780U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18355567776031865462U;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7705134893833304792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4435192506444773834U;
            aOrbiterG = RotL64((aOrbiterG * 5249651218395299501U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6204683785806409075U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17886971535016484255U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6047216474762933535U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4430578901091376829U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 607557685798141547U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12342665567201483107U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 48U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterB, 53U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29561U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 28833U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29191U)) & W_KEY1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28335U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28079U)) & W_KEY1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28982U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29234U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29105U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 40U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 35U)) + 7632760812370906911U;
            aOrbiterD = (aWandererE + RotL64(aCross, 47U)) + 6007174525479723089U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 3362829642521821048U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 18009548556107978286U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 22U)) + RotL64(aCarry, 43U)) + 17880909432272697327U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 27U)) + 15961567935420752568U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 39U)) + 10136559064656837921U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 11U)) + 17622019364405410277U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 52U)) + 6927494824421416306U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7125170407794874847U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12342273503071032250U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 867417849555857179U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14997696377476124836U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14874498694181230698U;
            aOrbiterD = RotL64((aOrbiterD * 4026127545746010937U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2549397729130885686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4217995818662767955U;
            aOrbiterK = RotL64((aOrbiterK * 5525525344485251063U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4706089044415442525U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17983900172670031015U;
            aOrbiterJ = RotL64((aOrbiterJ * 541552737180932879U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1904937798143929988U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10620877287033139483U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16711012562024287213U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15681091173163181525U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2655543246639000084U;
            aOrbiterB = RotL64((aOrbiterB * 16686375598149755947U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2647895110857289213U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5581609212017175954U;
            aOrbiterH = RotL64((aOrbiterH * 15330263616699031311U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13609076329627787987U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6244266279516622070U;
            aOrbiterA = RotL64((aOrbiterA * 12488345779236971095U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5289624364508923581U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16351476803965903112U;
            aOrbiterF = RotL64((aOrbiterF * 9012522724650442597U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 58U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 48U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aPhaseDWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30477U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[((aIndex + 31828U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30474U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30513U)) & S_BLOCK1], 38U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31492U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 31864U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererF + RotL64(aIngress, 21U)) + 4773124477323378268U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 16848723289435796005U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 11U)) + 13846642134917107058U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 6472057872482789939U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 35U)) + 2747019500690707226U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 47U)) + 9003965289739733880U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 39U)) + 3013390651936257377U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 43U)) + 3331004709895625067U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 51U)) + 15355010435553517129U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7709870658004280052U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13568728443963926564U;
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12409548853419307131U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 969183352023661537U;
            aOrbiterA = RotL64((aOrbiterA * 5549220554838837145U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15370309834426476775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3896803894396631184U;
            aOrbiterK = RotL64((aOrbiterK * 11018830202891911603U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10848873633291935766U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12885336509190543440U;
            aOrbiterE = RotL64((aOrbiterE * 1487357252619221365U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8252290890093788010U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9201553615601641350U;
            aOrbiterI = RotL64((aOrbiterI * 420321130559162915U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14014209645503188472U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4015071464301844550U;
            aOrbiterB = RotL64((aOrbiterB * 17444195018239904971U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16173085647514027347U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16916627014974363360U;
            aOrbiterH = RotL64((aOrbiterH * 7699587344277490953U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1591680303404522110U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16499606051269327916U;
            aOrbiterG = RotL64((aOrbiterG * 814405848002794813U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6932673635509444619U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8745681160108707944U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14565255558668084787U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterG, 34U));
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterF, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 816U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 2123U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1324U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3277U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 5046U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 29U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 41U)) + 10404808878585437255U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 47U)) + 10587858736301591439U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 1430530909801644435U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 9090938022430118902U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 27U)) + 12936604311751121235U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 1000583006020232032U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 54U)) + RotL64(aCarry, 13U)) + 12352532088997042232U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16723410947058502564U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16614089235313154270U;
            aOrbiterB = RotL64((aOrbiterB * 11530998303573027827U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4245553025593349277U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3353146318549477494U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14246377408238318091U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5935727336135635196U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10312187090293319667U;
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12192843181244744484U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3315472769469002444U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17512858811783071174U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9070400454074283765U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16633218007427888082U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2502077714838858460U;
            aOrbiterA = RotL64((aOrbiterA * 970762420815997725U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14792910273226469214U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15739513291150783151U;
            aOrbiterK = RotL64((aOrbiterK * 11896279674116906915U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 4U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9146U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 8083U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 8119U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5612U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 8794U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 5U)) + 4980738603982643969U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 51U)) + 17660278413018470020U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 17598114429859543466U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 10993929335279994739U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 29U)) + 17967203122976322481U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 19U)) + 1872290205549034384U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 41U)) + 16607778671782810797U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4895226930754394376U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14960359005982301383U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8546231310054433721U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9921642352377700630U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 893281964367208693U;
            aOrbiterI = RotL64((aOrbiterI * 2345509157333444217U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8232519988397858732U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4433022122758913407U;
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12689609831247168353U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 404535388957472176U;
            aOrbiterK = RotL64((aOrbiterK * 14534020545479806593U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3349108201964013155U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4386449511297371730U;
            aOrbiterC = RotL64((aOrbiterC * 9596273264321140229U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14314587717949070586U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10923886625271054985U;
            aOrbiterG = RotL64((aOrbiterG * 7838969002623486809U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17634909585329833520U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2021301459918350372U;
            aOrbiterH = RotL64((aOrbiterH * 1388242915918642741U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 56U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 16256U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 12172U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13877U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13734U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16343U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15216U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 60U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 5U)) + 5960680319644404115U;
            aOrbiterI = (aWandererI + RotL64(aCross, 46U)) + 16050752633567034185U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 8447503223226854741U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 14176813813397917591U) + aPhaseEOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 21U)) + 10534915376130006644U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 11U)) + 6866224454375302514U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 16506374165041008396U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7167814023968794098U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13870852197416596664U;
            aOrbiterA = RotL64((aOrbiterA * 17015971222069856463U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18064038854848993105U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9869630811507771691U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13723164383800461387U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 863613100452759380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16597969741225436529U;
            aOrbiterE = RotL64((aOrbiterE * 2680793528887208903U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6575347108051310653U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17062262265485019063U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7601045488473620019U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7193399224636409133U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14146747818810433849U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5273185769989530041U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9441449106442431427U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4303295336545399503U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8829695296836242587U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12604760768543193458U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15779327512379787715U;
            aOrbiterI = RotL64((aOrbiterI * 14000905201441272597U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 40U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + aPhaseEWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20511U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 20238U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20796U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19990U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20554U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17201U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 41U)) + 12222235191147985484U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 16367317014523328414U) + aPhaseEOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 39U)) + 3511378091284703789U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 15247492830966725949U;
            aOrbiterE = (aWandererB + RotL64(aCross, 3U)) + 7745995913390407897U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 29U)) + 6463593307540108810U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 11U)) + 1101669311005268630U) + aPhaseEOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12988052764067518580U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17717179747434679772U;
            aOrbiterC = RotL64((aOrbiterC * 10820310705487638793U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11662190906682400416U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6563014073547628748U;
            aOrbiterE = RotL64((aOrbiterE * 16967910471722117761U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13099094932059419219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16342730862261868847U;
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16855346813127524624U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6570063128502306944U;
            aOrbiterD = RotL64((aOrbiterD * 4571570049463124831U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11328352033809240501U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11640986648833160901U;
            aOrbiterG = RotL64((aOrbiterG * 2895830492089678919U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2675226158571501666U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17700531248266458165U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2231403813970188657U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7729597396731910874U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15172374484412053756U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 149009041406406517U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24458U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 24378U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24304U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24619U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23158U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 26499U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 6U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 9914837590440975587U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 6706125076401958051U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 44U)) + RotL64(aCarry, 27U)) + 16570817772679258409U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 11U)) + 6843705658115186948U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 27U)) + 16099930446791572351U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 3U)) + 5420550009556030459U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + 5729549069420177477U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15590601126188675834U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13044027390998620029U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16845199115313444123U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11068338135659636772U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6584988841809544332U;
            aOrbiterF = RotL64((aOrbiterF * 1683336180438945439U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8516813219883915404U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10647314042912492785U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15559481057047148785U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 201691689889605304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15512161798401184003U;
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3883760518944464145U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13861805129175491145U;
            aOrbiterJ = RotL64((aOrbiterJ * 17194438894492581181U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12019138626550801486U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13030350224959652248U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2643807255422544248U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4127143302485631794U;
            aOrbiterI = RotL64((aOrbiterI * 5441038881111578487U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterH, 48U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 41U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29965U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 29677U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31766U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30905U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31086U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 32185U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 29U)) + 16451272412693907816U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 3U)) + 10099485419723255462U) + aPhaseEOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 13U)) + 17668900099534923192U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 5497093724143181753U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 10354044773550071706U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 60U)) + 12728258851198019099U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 4144050505314242618U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14133805325480076530U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 308863673210602899U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2672613556981540433U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11741180130160569753U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12926863156769180448U;
            aOrbiterB = RotL64((aOrbiterB * 9726030996091054939U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 211920854786494259U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13234608842479411078U;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9164711974854618892U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6667377062281954219U;
            aOrbiterJ = RotL64((aOrbiterJ * 2603737166987437649U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4559040002406721850U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1749875480850675109U;
            aOrbiterI = RotL64((aOrbiterI * 15822640067349481089U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9555365165561936366U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18289733999504213574U;
            aOrbiterH = RotL64((aOrbiterH * 14156217554673229429U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8727162691639622461U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 291406782452963706U;
            aOrbiterD = RotL64((aOrbiterD * 8413500075082350243U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD, aSnowLaneA, aInvestLaneD, aInvestLaneC, aSnowLaneB, aExpandLaneA, aWorkLaneA, aInvestLaneB, aWorkLaneB, aExpandLaneC, aWorkLaneC, aExpandLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 433U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 2331U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2860U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1080U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3706U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 3653U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 39U)) + 3236820517816085022U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 19U)) + 741288875914097926U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 29U)) + 8417246926007729580U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 26U)) + 9715717805774537170U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 14360243844821619482U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 51U)) + 10760908100206775334U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 3434641779946167811U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 57U)) + 7885568822756234567U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 47U)) + 3041563437672051294U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 15761355327564963516U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 34U)) + 1158633562785937421U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9338581575871970653U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9172038894262857354U;
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14653924713599790081U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3854497592598563309U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11737111068815795303U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16286980180327600557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5092583772591249756U;
            aOrbiterJ = RotL64((aOrbiterJ * 13955105624639442903U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4288397994175567333U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15584236478994873104U;
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5557463939827483792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2659814275753280856U;
            aOrbiterE = RotL64((aOrbiterE * 17702430405693184643U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6941807963525063449U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2040598555191211307U;
            aOrbiterI = RotL64((aOrbiterI * 14750544987531722765U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 347572666231116258U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 779304821185302523U;
            aOrbiterA = RotL64((aOrbiterA * 14180254150318109855U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10632524582873079742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9761308771280517212U;
            aOrbiterB = RotL64((aOrbiterB * 13926235411726048921U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2097439707055737964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2813977930321463948U;
            aOrbiterG = RotL64((aOrbiterG * 14983538728730662603U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6080592019313796689U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5396623654821376409U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15478858835919398677U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8460497459575045342U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3236820517816085022U;
            aOrbiterK = RotL64((aOrbiterK * 5530411244458067093U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 38U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterC, 44U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9071U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((aIndex + 8505U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9445U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneD[((aIndex + 8098U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10342U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8238U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 6965U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 21U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 27U)) + 5960680319644404115U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 53U)) + 16050752633567034185U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 21U)) + 8447503223226854741U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 43U)) + 14176813813397917591U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + 10534915376130006644U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 36U)) + RotL64(aCarry, 43U)) + 6866224454375302514U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 41U)) + 16506374165041008396U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 7167814023968794098U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 13870852197416596664U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 46U)) + 18064038854848993105U;
            aOrbiterI = (aWandererD + RotL64(aCross, 11U)) + 9869630811507771691U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 863613100452759380U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16597969741225436529U;
            aOrbiterA = RotL64((aOrbiterA * 2680793528887208903U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6575347108051310653U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17062262265485019063U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7601045488473620019U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7193399224636409133U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14146747818810433849U;
            aOrbiterK = RotL64((aOrbiterK * 5273185769989530041U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9441449106442431427U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4303295336545399503U;
            aOrbiterG = RotL64((aOrbiterG * 8829695296836242587U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12604760768543193458U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15779327512379787715U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14000905201441272597U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15553000781122708728U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17162740616060079717U;
            aOrbiterB = RotL64((aOrbiterB * 9458662233556750239U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1032374679817715156U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16413393156165548232U;
            aOrbiterI = RotL64((aOrbiterI * 549659738811935015U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14056855000013992045U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7399202019042538829U;
            aOrbiterE = RotL64((aOrbiterE * 6103508549612077695U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2218389473339103389U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4679497280975967770U;
            aOrbiterF = RotL64((aOrbiterF * 9228353578259815023U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7620538119914173747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3118355627808424159U;
            aOrbiterH = RotL64((aOrbiterH * 12481319980496032783U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16787092219237931175U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5960680319644404115U;
            aOrbiterC = RotL64((aOrbiterC * 10727217147056112401U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 50U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 14U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterI, 50U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16266U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 11172U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 13904U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11726U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16343U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 13U)) + 14179205183062705133U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 26U)) + 210032324058740920U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 57U)) + 7387115089142500152U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 3U)) + 17583362781238061430U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 29U)) + 4991442849150005943U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 43U)) + 2891376254689854555U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 10523274382407446239U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 3861893764676218667U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 41U)) + 3366674459852093746U;
            aOrbiterF = (aWandererB + RotL64(aCross, 37U)) + 5898492634386601145U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 5U)) + 7047353571244768721U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14374108805453186316U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8763667021501226510U;
            aOrbiterD = RotL64((aOrbiterD * 7694695426430267863U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18261523829316379575U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 650477532238860965U;
            aOrbiterI = RotL64((aOrbiterI * 8291758490821819851U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2162326554604894042U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5776546692501825278U;
            aOrbiterJ = RotL64((aOrbiterJ * 14911545784585246537U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3501863793638415049U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14853789267425352958U;
            aOrbiterA = RotL64((aOrbiterA * 10590325397179928739U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15399673014671329743U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12253428583438990426U;
            aOrbiterG = RotL64((aOrbiterG * 12052855472196447849U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13202953937621953839U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7547616636832698398U;
            aOrbiterE = RotL64((aOrbiterE * 9533399972562428073U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15709801946594868318U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12458677982746610971U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6662570874316418993U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6957370791367530127U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10511379961344950861U;
            aOrbiterC = RotL64((aOrbiterC * 15551333099264031337U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16489828646914719181U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6827290294344770680U;
            aOrbiterK = RotL64((aOrbiterK * 6408864925398536651U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3308531598034561099U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10336568208337990458U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5606941634846696657U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14116471880098183908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14179205183062705133U;
            aOrbiterH = RotL64((aOrbiterH * 8824119255416045191U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 30U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 48U));
            aWandererD = aWandererD + (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterD, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 54U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20920U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneA[((aIndex + 19034U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20598U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20625U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19649U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 40U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 23U)) + 12222235191147985484U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 16367317014523328414U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 58U)) + 3511378091284703789U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 41U)) + 15247492830966725949U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 7745995913390407897U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 53U)) + 6463593307540108810U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 11U)) + 1101669311005268630U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 47U)) + 12988052764067518580U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 17717179747434679772U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 34U)) + 11662190906682400416U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 19U)) + 6563014073547628748U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13099094932059419219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16342730862261868847U;
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16855346813127524624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6570063128502306944U;
            aOrbiterC = RotL64((aOrbiterC * 4571570049463124831U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11328352033809240501U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11640986648833160901U;
            aOrbiterH = RotL64((aOrbiterH * 2895830492089678919U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2675226158571501666U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17700531248266458165U;
            aOrbiterI = RotL64((aOrbiterI * 2231403813970188657U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7729597396731910874U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15172374484412053756U;
            aOrbiterF = RotL64((aOrbiterF * 149009041406406517U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9178769489257842683U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9020154972097834926U;
            aOrbiterJ = RotL64((aOrbiterJ * 8910504667566521429U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1317403761217790562U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17151528554929201571U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3735945655450625203U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11621882033959669977U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10289504450815075623U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13365982786836243195U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16178772981106335703U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16896130772325866910U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6993524735412868965U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9573223644675562575U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17552463713786507189U;
            aOrbiterE = RotL64((aOrbiterE * 16103431656424881779U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4801852246698369631U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12222235191147985484U;
            aOrbiterD = RotL64((aOrbiterD * 2835204872125428065U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterD, 24U));
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 60U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 27053U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 23305U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 24769U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22499U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22372U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 35U)) + 7825479804710770560U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 19U)) + 5298124167101358123U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 46U)) + 17774541024369233726U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 7679371833537454082U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 43U)) + 5385914900748772224U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 39U)) + 3879781930908486531U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 13U)) + 659110346638873236U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 10749021728538539749U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 53U)) + 3631252455767429457U;
            aOrbiterD = (aWandererG + RotL64(aCross, 5U)) + 2271978810960685021U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 57U)) + 5963558780692551176U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 974909966119198104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9296998242911152296U;
            aOrbiterI = RotL64((aOrbiterI * 2613629915877957661U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2245318466901521959U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13391076374843288568U;
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6184487746594236737U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1563385912137291418U;
            aOrbiterA = RotL64((aOrbiterA * 4805455299959232321U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1744840092006498629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2100927276837188416U;
            aOrbiterD = RotL64((aOrbiterD * 3541788262067077997U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9998911862807246338U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12239948725635220096U;
            aOrbiterJ = RotL64((aOrbiterJ * 7098620484129489129U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3307447094994950246U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12746613971448298932U;
            aOrbiterK = RotL64((aOrbiterK * 9463975886346934681U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11577488293733790649U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 191108997585598809U;
            aOrbiterE = RotL64((aOrbiterE * 9574978681405356871U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18096145693841273722U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10026281133603934071U;
            aOrbiterF = RotL64((aOrbiterF * 17261343107314203471U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2346682418062064668U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2996178204018644206U;
            aOrbiterG = RotL64((aOrbiterG * 2552965800703390909U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15085425896818988223U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1589593231782852588U;
            aOrbiterC = RotL64((aOrbiterC * 1535556765195388675U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17170695588248383518U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7825479804710770560U;
            aOrbiterB = RotL64((aOrbiterB * 7434218282170150533U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 54U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 10U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterF, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 6U));
            aWandererA = aWandererA + ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30648U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 27562U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27670U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31004U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 31194U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 23U)) + 8767379393098711499U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 27U)) + 7168159491580816433U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 51U)) + 9879279829061883406U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 10537167136053399303U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 21U)) + 2839070018069188936U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 13844278063968429732U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 18U)) + 11278946626186474646U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 3U)) + 11798425216660557799U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 27U)) + 7618446090703335192U;
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 695423597006983660U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 53U)) + 14344728202803488813U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11656100506575697086U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10384358779985773937U;
            aOrbiterH = RotL64((aOrbiterH * 247494692039140973U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17585001605131977341U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9964478171465522911U;
            aOrbiterB = RotL64((aOrbiterB * 13484044854790175315U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2710943171829692624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17809072853457153057U;
            aOrbiterJ = RotL64((aOrbiterJ * 16341884203303271365U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12814092033910687774U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1743186323268668740U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11150822630624332557U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10750472346626754704U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15925901217078035356U;
            aOrbiterD = RotL64((aOrbiterD * 9276504171291801637U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2569102106359362359U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8868261301410769739U;
            aOrbiterK = RotL64((aOrbiterK * 3662495603133918101U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2143691008373582476U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10606616796243205921U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15794414817813485643U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16258070651850746855U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11720192793689633315U;
            aOrbiterI = RotL64((aOrbiterI * 14475623219460678021U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8230871037292355675U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16898650748046368353U;
            aOrbiterC = RotL64((aOrbiterC * 7368697435476300255U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9071122174426904737U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4506737259011736474U;
            aOrbiterE = RotL64((aOrbiterE * 11903039808814842447U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4545409671845718259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8767379393098711499U;
            aOrbiterA = RotL64((aOrbiterA * 1210632171306946669U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 38U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7133U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 347U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 4459U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4335U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2000U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 3691U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 1297415699043177788U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 17583786534509260153U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 52U)) + 643197858925708798U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 5062653766915694874U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 7034273638367180511U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2026909726972916996U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2785690475553211646U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6612792037861160393U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2910341716302991892U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2834181605200829791U;
            aOrbiterH = RotL64((aOrbiterH * 1510617068750957651U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13323052600571281928U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10434901530315760460U;
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 247903955625194782U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5196515747387257163U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7196305682377987476U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14777739876892587484U;
            aOrbiterF = RotL64((aOrbiterF * 95220583948241581U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterG, 44U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14235U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 11049U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 14929U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13359U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9431U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 12119U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 12849591986267890852U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 20U)) + RotL64(aCarry, 5U)) + 8232614804696815750U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 12141567259210877281U) + aPhaseGOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 57U)) + 2928641981037885644U) + aPhaseGOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 980733350554783938U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2683985177993350746U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14532148403815527355U;
            aOrbiterG = RotL64((aOrbiterG * 15985362037094864225U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7736296629433884203U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10428437770166310549U;
            aOrbiterF = RotL64((aOrbiterF * 326634742742373401U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 18327174144859461029U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6810436935194432002U;
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12606153309690753435U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17123256945895150555U;
            aOrbiterJ = RotL64((aOrbiterJ * 13469111258504672565U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9057777759026189541U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16478485918911194442U;
            aOrbiterE = RotL64((aOrbiterE * 11054247078884894131U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterG, 44U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + aPhaseGWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24535U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 23851U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 19556U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22256U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17457U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 23021U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 23U)) + 1042610313571524121U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 3505725321008825582U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 12584654563843782991U) + aPhaseGOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aIngress, 54U)) + RotL64(aCarry, 19U)) + 6645399144515770935U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 39U)) + 3608978423753715584U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8089198857670370983U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15207251813516399879U;
            aOrbiterF = RotL64((aOrbiterF * 7596841660069752069U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9579268660105824516U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16055044469473802812U;
            aOrbiterG = RotL64((aOrbiterG * 2269649280637188723U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 583811872609805949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7027491967970873942U;
            aOrbiterI = RotL64((aOrbiterI * 12686754713465826139U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 18256061823189677508U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12708429127816136937U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12593886633108075321U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12169216645156306078U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12694325407567795065U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3711789483877261899U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 26U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 50U)) + aOrbiterF) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29766U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 31289U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 27194U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32540U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26386U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28938U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 14U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 50U)) + RotL64(aCarry, 57U)) + 5573188770530340913U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 29U)) + 1431772230889897111U;
            aOrbiterG = (aWandererF + RotL64(aCross, 3U)) + 4809192776429682319U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 5576603692574369341U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 2720143226007220386U) + aPhaseGOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17220328778565331629U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9629485808442089423U;
            aOrbiterG = RotL64((aOrbiterG * 18349580416082045015U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1136998437010390983U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11893390497814523841U;
            aOrbiterF = RotL64((aOrbiterF * 5329621622743089531U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1764986431917532370U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1741014798007010376U;
            aOrbiterD = RotL64((aOrbiterD * 13414914086049500731U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12221368453236547044U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7694538641172350430U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8439120733670016501U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17472344518811560603U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3308740700728172984U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15290400462887712083U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + aPhaseGWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterF, 44U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 889U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 5275U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2222U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7357U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6788U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 7551U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 52U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 964165145848253292U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 10645976767204934746U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 8241612229349212650U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 3U)) + 4159196033256913347U) + aPhaseHOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 19U)) + 7194795864620233507U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7638928444536778384U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11819105916503968109U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9052440449038441625U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18052213302858186237U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8663575313970041570U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14131073322476609161U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16644136720439299786U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16930316530442679864U;
            aOrbiterB = RotL64((aOrbiterB * 2650922074098320859U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16251107616988250593U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7171986193609401665U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3543709971414550087U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17885046834432626644U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7757069274715713557U;
            aOrbiterK = RotL64((aOrbiterK * 15766885299397923879U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 56U));
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14335U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 9610U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 12623U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12296U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12457U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14892U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 57U)) + 18302975933754610273U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 16736972646771456082U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 17389406266488137442U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 48U)) + RotL64(aCarry, 21U)) + 5252511566486165539U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 27U)) + 5730715427422747640U) + aPhaseHOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6412695646456045825U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9539701605708994494U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6511935168278632407U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18355107116412945722U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11735742491750132942U;
            aOrbiterI = RotL64((aOrbiterI * 18129835093627763685U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12363819388562658842U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5861430292304371543U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12989055611235382695U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15027487084595017708U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7012850020745791926U;
            aOrbiterD = RotL64((aOrbiterD * 15952928839355613939U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11904871669287886120U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11199760114477343208U;
            aOrbiterF = RotL64((aOrbiterF * 7156374911847525867U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 14U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterJ, 4U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererI, 20U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16714U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 21209U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 24216U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24461U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20317U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21736U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 17074147006464019918U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 35U)) + 10559516626129419928U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 47U)) + 13280363679503946221U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 51U)) + 17657115422132457413U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 13325837013304973008U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3059707750486106037U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4529045702503050852U;
            aOrbiterI = RotL64((aOrbiterI * 12889277842182219673U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10726578475550904292U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14832537837996659885U;
            aOrbiterA = RotL64((aOrbiterA * 808060368961520519U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 220094417441809246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15343130035105342194U;
            aOrbiterF = RotL64((aOrbiterF * 7984652435043810845U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16592263353426409884U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15649290906447931918U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8405875177836650731U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11437410545843708269U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5859769136073011444U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1065016088086441107U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 52U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27608U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 25161U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 26703U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25693U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26128U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25243U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 52U)) + 1708250618750199233U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 37U)) + 12009147777553691142U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 8393982703399156592U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 3247327098356831221U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 3403590155376353737U) + aPhaseHOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18197244558104735044U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3096253642040701606U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6656168712438620783U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8012692688785412179U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17531946907545680745U;
            aOrbiterF = RotL64((aOrbiterF * 16510602981731506381U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17687695944270225817U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16147773866007628769U;
            aOrbiterK = RotL64((aOrbiterK * 16926442582711557877U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 18244641303026196497U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8839160526348897457U;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10599266240854068246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterH = RotL64((aOrbiterH * 13311591601230386375U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 50U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
