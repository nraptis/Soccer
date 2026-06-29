#include "TwistExpander_BaseBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BaseBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x844CE6F9C62A70A3ULL + 0xB7EDC1D8AE86F1DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x801A294F27D23DEBULL + 0xCAA93CC03F30D594ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAFEFC204CC075B2DULL + 0xBBC3833513393A83ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD877270471547561ULL + 0xFBD32749507EC64FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD871C043148D4B1BULL + 0xCDD98F16D2EA0AD1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x942E3BD7FC6B4ADFULL + 0x9E2CD7EF081AA335ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA55F6A9A7FD15A39ULL + 0xCD628D9EF63C7465ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB1A3D8D0B96122B3ULL + 0x994C5C18A23DD902ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF85B874CF00C5031ULL + 0x8784CA1507AE96BCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8718755459DB0F9BULL + 0xD922552F8F678B0DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9E7D9609C0B7CCE1ULL + 0xC48F0D7A7DD744DAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xADCBCC8768B55025ULL + 0xDA3DD4B4A1E2D276ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDE815FEC54BD5609ULL + 0xC30E5EC395489861ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDAA05122B97CDE15ULL + 0x8EE020AEC7FDD239ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8919FEBD2A3C4FCFULL + 0x8B8143757E9DA33DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCD51FF278F63CCBBULL + 0xFA319C68195F0222ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3055U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 4830U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1151U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 4129U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererK + RotL64(aIngress, 11U)) + 12122689833405846292U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + 9640400270962766788U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 9141937998266739071U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 12899395770434090537U) + aNonceWordG;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 37U)) + 13457918115408031842U) + aNonceWordK;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 3U)) + 15134784483576000943U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 56U)) + 12540961268790055438U;
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 6306886773092764230U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererC + RotL64(aScatter, 47U)) + 13573343491337243121U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 29U)) + 8545588657348974413U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 54U)) + 10891410570357275120U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2877137119767060151U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9178097682386595144U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15528007881855616978U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11368419529245281435U;
            aOrbiterA = RotL64((aOrbiterA * 12433207037378339309U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 5932738914934356645U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5551842263864055419U;
            aOrbiterH = RotL64((aOrbiterH * 16093776759971522681U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3824433359595690603U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17184628855571662441U;
            aOrbiterF = RotL64((aOrbiterF * 691208053136187317U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8724462245014132623U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7481349499528092352U;
            aOrbiterG = RotL64((aOrbiterG * 8212182934509617583U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6908362960248294718U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5354057969992655314U;
            aOrbiterE = RotL64((aOrbiterE * 16586084885820679343U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11138301629323903147U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14164180536320940750U;
            aOrbiterC = RotL64((aOrbiterC * 9099767681053390287U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 709942920176922902U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17128241237359414945U;
            aOrbiterK = RotL64((aOrbiterK * 14063385518459963529U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6760410778228957309U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15333948259759012363U;
            aOrbiterB = RotL64((aOrbiterB * 3685416414008280787U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6929136132517755104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13833415487953533365U;
            aOrbiterI = RotL64((aOrbiterI * 14860437994758579635U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16143046377679975216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12122689833405846292U;
            aOrbiterJ = RotL64((aOrbiterJ * 227699085983424155U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 34U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 44U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10588U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 10909U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9738U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 8781U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 51U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 27U)) + 16200278595895089008U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 1029614154810465897U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 7129562468705441295U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 14388903902433951274U) + aNonceWordA;
            aOrbiterG = (aWandererK + RotL64(aCross, 24U)) + 1013568949315967455U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 51U)) + 3128823373497815651U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 14525694606889470589U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 39U)) + 14443983602196782887U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 35U)) + 12244220415328641190U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 48U)) + 10477159225338766614U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 11U)) + 2842870123078131566U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8621138818955849917U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5038396344400303181U;
            aOrbiterE = RotL64((aOrbiterE * 14636756322207385447U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2768613802894372496U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2027754864051410015U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2461322540050569287U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2848088309172056399U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15017458513904884651U;
            aOrbiterA = RotL64((aOrbiterA * 9926904679902843055U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9079797279596336139U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15424866642305110811U;
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13751764050290602740U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7694557131324740282U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 14980807690491467023U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3508673897305667669U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3600868397311393233U;
            aOrbiterK = RotL64((aOrbiterK * 5165032044164139165U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1222655844979128996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2257342337168905875U;
            aOrbiterB = RotL64((aOrbiterB * 6198995971182272119U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6290990717563682725U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15308494772443447109U;
            aOrbiterJ = RotL64((aOrbiterJ * 1925593111157842325U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4065385272074155855U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17216369169581934516U;
            aOrbiterD = RotL64((aOrbiterD * 16172589962950781777U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15683161334290612079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4197626901960576264U;
            aOrbiterF = RotL64((aOrbiterF * 2822547214684481747U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4400047838649306704U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16200278595895089008U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6603195071605635697U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 28U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 53U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 50U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 26U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11054U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13977U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 13588U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10966U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + 5160910997561396461U) + aNonceWordB;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 11U)) + 14920764751058512062U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 6080952401749660022U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 4U)) + 17667234330526298627U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 41U)) + 760630072638686756U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 29U)) + 3504157162816997476U) + aNonceWordM;
            aOrbiterE = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 9489022223422585882U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 35U)) + 1149898536879968964U) + aNonceWordE;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 18U)) + 10492284328940025310U) + aNonceWordI;
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + 13213275606286399312U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 10557118912847180413U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15618980209023994776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5268600749854045564U;
            aOrbiterC = RotL64((aOrbiterC * 3849660559223919613U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8011552687609649990U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3148133096349525066U;
            aOrbiterD = RotL64((aOrbiterD * 5245156554959620007U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12032847944237867285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14999005703490824673U;
            aOrbiterA = RotL64((aOrbiterA * 6631584955208646049U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5426735969392906710U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3593177531650386729U;
            aOrbiterE = RotL64((aOrbiterE * 12997284886192717043U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1701444719333347373U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15928731228196894960U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1919318226904213433U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5960179456039157036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5716434224061596483U;
            aOrbiterF = RotL64((aOrbiterF * 3731976564761202801U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2136841536293340279U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12969550408652728526U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 7612191387451455137U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3641997570461447114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4677572491523684525U;
            aOrbiterI = RotL64((aOrbiterI * 2730358077882211651U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2741372094325164504U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4998631511811832690U;
            aOrbiterG = RotL64((aOrbiterG * 10619395395977372695U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6260464862798783617U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16489087874167346533U;
            aOrbiterH = RotL64((aOrbiterH * 11278053967185244867U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7043760915859224327U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5160910997561396461U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 15260149870590431675U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 52U));
            aWandererK = aWandererK + ((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterE, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20347U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 21579U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 19038U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20025U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19879U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 4U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 6U)) + 12669015908335980355U;
            aOrbiterC = (aWandererI + RotL64(aCross, 51U)) + 5438715179868613192U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 13172104448184536460U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 19U)) + 13421421503244744803U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 13327113302994856582U) + aNonceWordF;
            aOrbiterA = (aWandererF + RotL64(aCross, 35U)) + 4671768205922454413U;
            aOrbiterH = ((((aWandererB + RotL64(aPrevious, 28U)) + RotL64(aCarry, 27U)) + 5355759962838579929U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 21U)) + 6691720614265406851U) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + 7063906424700911378U) + aNonceWordK;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 17328616394166672263U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 13U)) + 1542940602574207068U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7203866278803132454U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 993485696233139264U;
            aOrbiterE = RotL64((aOrbiterE * 11609009908810366447U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15659679028507488331U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 18321361454094675842U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3966860765622641843U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9633319822696783352U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3496559332232402963U;
            aOrbiterB = RotL64((aOrbiterB * 7772060229838162977U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1918349708324205526U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7701088402761359134U;
            aOrbiterH = RotL64((aOrbiterH * 9649485438465644795U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6006824348814439686U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 18088375375347012557U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12801082943086128385U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12816533373478543584U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterG = RotL64((aOrbiterG * 8935839101517220201U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11311632024372748238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9891349164779752351U;
            aOrbiterK = RotL64((aOrbiterK * 11405973752233193209U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 711130292000437038U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17818800917771709681U;
            aOrbiterF = RotL64((aOrbiterF * 10567029732245868263U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10188714200240109442U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9745615081760948652U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 9321909462220134035U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6508703788527163965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7536038073603467381U;
            aOrbiterC = RotL64((aOrbiterC * 12015514242701199813U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2793951597846756844U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 12669015908335980355U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 7355285540199760689U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 52U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 18U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 54U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterC, 4U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23619U)) & S_BLOCK1], 10U) ^ RotL64(mSource[((aIndex + 27002U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24499U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 25741U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23087U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 26013U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 44U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 57U)) + 15045917390223766480U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 10763054007033668758U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 43U)) + 13190170142593666607U) + aNonceWordE;
            aOrbiterD = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 9657025731441167065U) + aNonceWordM;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 11433367178975954211U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 51U)) + 17904920143996810366U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 27U)) + 3244383020512113283U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 53U)) + 6538815775171139091U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 35U)) + 7195368312757976343U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 30U)) + 18134430713910279374U;
            aOrbiterF = (aWandererK + RotL64(aCross, 41U)) + 6571776588427107976U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11830778129647517758U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9793702760907767365U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4096246227968677179U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2287235876793192036U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8951959188326141794U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 9968356718110753845U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7583061790273240157U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3571364625022806085U;
            aOrbiterA = RotL64((aOrbiterA * 6238360922735480669U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13869345563551689212U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 277480328952975002U;
            aOrbiterI = RotL64((aOrbiterI * 1057564597096163085U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4983735092494677578U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9490022869381030928U;
            aOrbiterE = RotL64((aOrbiterE * 12926352917961703123U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7928039573014765566U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6504190875809407084U;
            aOrbiterG = RotL64((aOrbiterG * 14648214826494826711U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2787985600176307413U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16308785053443116826U;
            aOrbiterD = RotL64((aOrbiterD * 17867565986311256691U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12788128335006767824U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1187040019537798339U;
            aOrbiterF = RotL64((aOrbiterF * 10834905007658184183U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 10771230162770496645U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6542421559654716320U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16829492790597069373U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 702458690970201679U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2806140783487813070U;
            aOrbiterC = RotL64((aOrbiterC * 7415398198842270381U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 950611302199732036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15045917390223766480U;
            aOrbiterB = RotL64((aOrbiterB * 9358017420417979347U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 58U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC + ((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterC, 26U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31805U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((aIndex + 30275U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32611U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31921U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32056U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30315U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 39U)) + 12632404972795375757U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 18U)) + 5351879979055988456U) + aNonceWordB;
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 3597737727467443413U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 11U)) + 2830846754917852318U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 17311925960294518018U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 34U)) + RotL64(aCarry, 11U)) + 2083584640523695383U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 15049343611387010158U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 13U)) + 6443050378205811147U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + 6021965178697344070U) + aNonceWordJ;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 53U)) + 5080289878758029976U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 576927745306972983U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4728489691382690859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6184355840165758855U;
            aOrbiterI = RotL64((aOrbiterI * 1515043910404156423U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11220539885798595450U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11091438724966718214U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 8225347114759391961U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17184210490020062419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2150997767099116408U;
            aOrbiterH = RotL64((aOrbiterH * 8058553821648892499U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7021953562676903717U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17159676348343312834U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13877284519668483549U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10367891770525239784U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11922478487264201233U;
            aOrbiterG = RotL64((aOrbiterG * 9195137452661956029U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17815162358981720634U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9582631251085100284U;
            aOrbiterA = RotL64((aOrbiterA * 11838992994130850483U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 872593750259572264U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17832330100262167302U;
            aOrbiterK = RotL64((aOrbiterK * 1114416841510028467U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16601139856969287418U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14931287111691324985U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 16757174577841001179U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11413072442039115924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15253605470589905889U;
            aOrbiterF = RotL64((aOrbiterF * 10832817442285245673U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3653487723581514107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14891378240114471865U;
            aOrbiterB = RotL64((aOrbiterB * 1386594204573386051U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15659724464711852035U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12632404972795375757U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2407347385127296647U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 28U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterG) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererE = aWandererE + (((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 24U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 19U);
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

void TwistExpander_BaseBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF730286243F30C7DULL + 0xCD085CDD87EB448CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x809DD8EFF6AF50D9ULL + 0xC7EC13D9573316DFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBB256A895F9A4F59ULL + 0xDE9A174B3AA81723ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF51C4D47D7080945ULL + 0x8FEDAF788899C8BCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE6299CA19D37A4E3ULL + 0xE8CF8B4BA1A218FAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD31E6256D569228DULL + 0xE7FBDFCC1E3B239DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD72103B67CD59449ULL + 0x834BC5092D48408BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE1FE6B16921C0A9BULL + 0xE87A804E5C62A9CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF869D836E57D5EB3ULL + 0xBE74A75492D73EC2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDD4CC9922EFCF4D9ULL + 0xA75A202FED09195DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE29A194E5D9EB139ULL + 0x977EA27B9AC7141EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEB4D4E891AD1080BULL + 0xF4356F4D623A6404ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9CD4F7D502069ED9ULL + 0xD9261629ECDD9962ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC89AB422C990EDF7ULL + 0xF8424C65FC82EA21ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD54975A50F58A40BULL + 0xA5D909BD8C74186EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x89CBF3125C376CDDULL + 0xCD38ABDBEA806561ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 1687U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6048U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4060U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3938U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 12809562813316740345U) + aNonceWordC;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 4U)) + 17084212535326321199U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 27U)) + 16074921689983846769U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aCross, 39U)) + 14027986153007120145U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 53U)) + 7633455951809250227U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 340989348513370174U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 57U)) + 5307820377645020116U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 13U)) + 5605285015771527274U) + aNonceWordF;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 18U)) + RotL64(aCarry, 19U)) + 5293500434746182790U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7263156475892261811U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10672879570907433005U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2506338667179450741U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16659226780900986107U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9774892622769850665U;
            aOrbiterJ = RotL64((aOrbiterJ * 7487477727543183211U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10728057184108279042U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5032485856947407217U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 16651577903809154285U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14642241075374862345U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8386481273395203518U;
            aOrbiterF = RotL64((aOrbiterF * 11649977733867003445U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2874153265304098104U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11519900149177261000U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2010158758971864505U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8885690878540115768U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4482143389870987714U;
            aOrbiterB = RotL64((aOrbiterB * 7105332459437434281U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17469068567801886615U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5121422018622394837U;
            aOrbiterE = RotL64((aOrbiterE * 14823827133212643467U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3130788210672745618U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6139244627510113216U;
            aOrbiterI = RotL64((aOrbiterI * 2640754184921507389U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 10488511756324474710U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1760223670304953696U;
            aOrbiterK = RotL64((aOrbiterK * 4007062295003769311U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 46U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 22U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 24U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15559U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 8345U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14388U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10890U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13564U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 39U)) + 10726035965553989335U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 967354339530195662U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 47U)) + 10834593005478605624U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 23U)) + 1012888282838656933U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 15283530351725183253U) + aNonceWordO;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 57U)) + 11724495956731703750U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 3U)) + 4288330117317505776U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 11U)) + 10894778070022873473U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 40U)) + 15563886747621617467U) + aNonceWordF;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11182488628562891937U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10420140066310588580U;
            aOrbiterA = RotL64((aOrbiterA * 13898299782819948719U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11775138062167543111U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16545391898578161683U;
            aOrbiterF = RotL64((aOrbiterF * 14588306527161321535U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1550144656312299266U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14903504853138279883U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 8003033561266164387U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 309935535526750396U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13991265868040011411U;
            aOrbiterI = RotL64((aOrbiterI * 2887531132228588441U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1755976294857114222U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2259275858478396846U;
            aOrbiterH = RotL64((aOrbiterH * 7416165760067878161U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4838175912944552936U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12307900457200936013U;
            aOrbiterE = RotL64((aOrbiterE * 14719363144850838805U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18025411832912225805U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 981375022769564523U;
            aOrbiterB = RotL64((aOrbiterB * 15869361544011831483U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3174014054982742562U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8119692378748963609U;
            aOrbiterG = RotL64((aOrbiterG * 3072354179707448489U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14502863160788675807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1207582534593709516U;
            aOrbiterJ = RotL64((aOrbiterJ * 3045412087535529357U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 14U)) + aOrbiterI);
            aWandererD = aWandererD + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterE, 58U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24522U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneD[((aIndex + 23343U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19940U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18401U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21366U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23528U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 53U)) + 9471546960258473684U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 18050235435948942244U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 3005107102671544641U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + 17898396434573801850U) + aNonceWordB;
            aOrbiterD = (aWandererH + RotL64(aScatter, 40U)) + 15071602525497771648U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 47U)) + 5780119462702672108U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 13301326224151025687U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 57U)) + 18129323022260575961U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 34U)) + 1199228670638790709U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1839199978088021020U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4999517042246790165U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4585813675677234577U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8788607633376516299U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15143903839930468749U;
            aOrbiterD = RotL64((aOrbiterD * 12735914889325422675U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16674732686428431869U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15908873150953195581U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18049755517524334107U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11204775359756474667U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2525984309543939465U;
            aOrbiterI = RotL64((aOrbiterI * 3988529812023791571U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4566345170476825512U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14876612901557406267U;
            aOrbiterA = RotL64((aOrbiterA * 9047956948845135339U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14926290877038883931U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 12710203178186614846U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 14841163494801662515U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7315094513967387996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11050116830482816766U;
            aOrbiterG = RotL64((aOrbiterG * 3702999495721152019U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4505368486032503953U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17905748055257551092U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 14775870175093453197U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5728886950801376350U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17998141690182325170U;
            aOrbiterE = RotL64((aOrbiterE * 16008599930125391379U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 50U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + aOrbiterJ) + RotL64(aOrbiterA, 28U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 52U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 40U)) + aOrbiterK) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26126U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 32326U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31033U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26330U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28079U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28883U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 30U)) + 13499155707765393469U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 47U)) + 3740324981823726185U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 5470765363949735652U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 51U)) + 3446436171274452326U) + aNonceWordC;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 37U)) + 1778929412631211933U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 19U)) + 14666308799855220954U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 6U)) + RotL64(aCarry, 11U)) + 4548410236791175055U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 57U)) + 5829739767694190372U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 14319231414903675748U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1513851750246111405U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1685620217748986019U;
            aOrbiterJ = RotL64((aOrbiterJ * 9286548037413609445U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16284162182006054402U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6271539598462003309U;
            aOrbiterG = RotL64((aOrbiterG * 13923286694131331137U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12669312437565969473U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11894755313393001665U;
            aOrbiterA = RotL64((aOrbiterA * 12556759675372354075U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6315983824634946566U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17106616474222892782U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 167205520766791073U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13350266700180455548U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4608846311203767162U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2504857468837437365U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14195866746143604365U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7917977448256795054U;
            aOrbiterH = RotL64((aOrbiterH * 5927771378657284557U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10707336923305131629U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17122696159336995392U;
            aOrbiterI = RotL64((aOrbiterI * 13953518568670659191U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5182322763573586116U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6503754948502556246U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14749002194140663519U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14907832047832987341U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6258064448676621346U;
            aOrbiterD = RotL64((aOrbiterD * 4407960312705621487U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterD, 40U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 28U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_BaseBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA1A31B083AC47BEFULL + 0xA3D2712A04811381ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA27A88AA06158D87ULL + 0xE6FB43D8538A0DB7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEFA3C2E8CB69E54BULL + 0xDC776BD5F3524CC6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD2671B0D24178AABULL + 0x9F134DF623F4FD19ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFA2812D0785C5943ULL + 0x8F3E1DCDFACC0504ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF823A76D0CC3DD41ULL + 0xE36B48B73B4AE503ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF3136497CF7F5C79ULL + 0x8AAA953EFD0D9DE3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB1E309DA22054955ULL + 0xA7C5C50691A1EE09ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xED419B289F5129A5ULL + 0xCCBEEF93515FB2CCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9E31EDB9EB399251ULL + 0xACAF747178C219A9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAA3A43ACDE90A84DULL + 0x89C0751FE8FC5838ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDE26537E37C9B87DULL + 0xB19D42AFB3E130A9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE8655B02F2DCB399ULL + 0xE562181B37BE97FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFED7227458EC4271ULL + 0xFEB3B00766A59892ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC57EA7E738D1DA51ULL + 0x98F3C0C2590ECAFCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDD2DE97B601D6031ULL + 0xEAC2E72BC516422FULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1071U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 3123U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 8053U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3222U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 1131U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 26U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 5U)) + 439898681482066326U) + aNonceWordB;
            aOrbiterG = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 17362083676671776094U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 48U)) + RotL64(aCarry, 27U)) + 6418499837265155024U) + aNonceWordA;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 17262244253027454972U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 39U)) + 2382066162993139503U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14345808395587174135U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7534743166385552851U;
            aOrbiterB = RotL64((aOrbiterB * 9475127126941982125U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16994453324688523966U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7079553728544045092U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10104892188895367489U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 3562822704508440641U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13990892681975857821U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8352929306654078795U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1796728922368577238U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6605161260520067178U;
            aOrbiterD = RotL64((aOrbiterD * 8147537646591674091U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13994083795942328918U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6144523182899107711U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 4153879991344611283U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 39U)) + aOrbiterI) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterE, 12U)) + aOrbiterI) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8338U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 15081U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14522U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13026U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9559U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12280U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 3U)) + 1297415699043177788U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 17583786534509260153U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 643197858925708798U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 23U)) + 5062653766915694874U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 50U)) + RotL64(aCarry, 23U)) + 7034273638367180511U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2026909726972916996U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2785690475553211646U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 6612792037861160393U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2910341716302991892U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2834181605200829791U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1510617068750957651U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13323052600571281928U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10434901530315760460U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2042210188346767033U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 247903955625194782U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5196515747387257163U;
            aOrbiterJ = RotL64((aOrbiterJ * 1799024689023272275U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7196305682377987476U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14777739876892587484U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 95220583948241581U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 56U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 22U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 40U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18096U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 22864U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22951U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17276U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18216U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20337U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + 7651355040951791298U) + aNonceWordB;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 3U)) + 13988210277931659312U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 44U)) + RotL64(aCarry, 3U)) + 9846849412579537783U) + aNonceWordL;
            aOrbiterK = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 12746719939495876158U) + aNonceWordI;
            aOrbiterE = ((((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 11498066185182895284U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11101058955193080232U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15513734459555672046U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6974281215677538561U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15711108675349394643U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4771231759949468556U;
            aOrbiterE = RotL64((aOrbiterE * 9806191054594333615U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11449258010811305256U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17036938391509986723U;
            aOrbiterK = RotL64((aOrbiterK * 7411466953205347639U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6999245666776654250U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2106819066263369528U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12716183358903477216U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16752724547046059889U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11475905692393034141U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 40U)) + aOrbiterE) + aNonceWordD);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 19U)) + aNonceWordJ) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32142U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 30810U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 28256U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26530U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29442U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26531U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28827U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 12U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 14U)) + 13499155707765393469U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 3740324981823726185U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 5470765363949735652U) + aNonceWordJ;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 3446436171274452326U) + aNonceWordD;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 3U)) + 1778929412631211933U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14666308799855220954U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 4548410236791175055U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 6822908616815218501U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5829739767694190372U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14319231414903675748U;
            aOrbiterG = RotL64((aOrbiterG * 4966501102515775601U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1513851750246111405U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1685620217748986019U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9286548037413609445U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16284162182006054402U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6271539598462003309U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12669312437565969473U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11894755313393001665U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 12556759675372354075U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 51U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 22U)) + aOrbiterE) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_BaseBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDA12DAA4A9174C07ULL + 0xEE2CDF5882FAB43CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDD7ADA85FAAACFBDULL + 0xE3675AE2C7D68585ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDDEB2A90FD96123FULL + 0xB23CFF823E0E55A6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB3FBAD6F460087EDULL + 0xDDBBBB7AAF2EC645ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA6860892B13EB391ULL + 0xC1CA1211E58A6F4CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9B1927C4E2D49B2BULL + 0xC8545B3576A3F914ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xED9978002C76B5D5ULL + 0xD998E0EEA4C04068ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF5BFD3EE66F4C99BULL + 0xF5FEB506DEF3E837ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDC28BA749A4B8E53ULL + 0xE11EB9BCE65BF3DFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEB22B3C0C3DE625DULL + 0xB520B417BAA9C9E0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD9739719EA13D4B7ULL + 0xAA51A0A7466ADE55ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD683C899104D1C81ULL + 0xD8120FBA80834881ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8F6CFD1BB03E9165ULL + 0xB69B0E7C9E506070ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDDDAA111B292FB43ULL + 0xA950409466FE9AEBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAF055BCA05060317ULL + 0xCA7960268B118C29ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF3DC419C8E3E6493ULL + 0xB6505ED302AF894BULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aOperationLaneC, aWorkLaneA, aOperationLaneD, aFireLaneA, aWorkLaneB, aFireLaneB, aFireLaneC, aWorkLaneC, aOperationLaneA, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3212U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 6223U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 7559U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6657U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1726U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7754U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 20U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 41U)) + 5573188770530340913U) + aNonceWordH;
            aOrbiterH = (((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 3U)) + 1431772230889897111U) + aNonceWordD;
            aOrbiterB = (aWandererI + RotL64(aScatter, 57U)) + 4809192776429682319U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + 5576603692574369341U) + aNonceWordG;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 2720143226007220386U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 35U)) + 17220328778565331629U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 9629485808442089423U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1136998437010390983U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11893390497814523841U;
            aOrbiterB = RotL64((aOrbiterB * 5329621622743089531U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1764986431917532370U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1741014798007010376U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 13414914086049500731U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12221368453236547044U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7694538641172350430U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8439120733670016501U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17472344518811560603U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 3308740700728172984U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 15290400462887712083U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9535358833412446771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11192312491731312451U;
            aOrbiterA = RotL64((aOrbiterA * 17405609148475445743U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14850451970047190039U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11932493299452443256U;
            aOrbiterK = RotL64((aOrbiterK * 7964808728820467795U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5972619895614731870U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17174497535809891690U;
            aOrbiterH = RotL64((aOrbiterH * 15471084511364572533U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 50U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterK, 44U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 12U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16251U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 10828U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9146U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15504U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11601U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 11137U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererD + RotL64(aIngress, 52U)) + RotL64(aCarry, 37U)) + 6069475454765660321U) + aNonceWordF;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 11483704742497268068U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 11055697447388986418U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 10897095046039997004U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 11U)) + 4731637118230457840U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 27U)) + 13855839187084986751U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererF + RotL64(aIngress, 41U)) + 5328208115460188239U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12479538544291412985U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10740165998792608231U;
            aOrbiterC = RotL64((aOrbiterC * 14046827922294477379U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6492798157284955373U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13056825957483891921U;
            aOrbiterG = RotL64((aOrbiterG * 14882112110627751751U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2068184064919194657U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5656302738780746294U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16493021179127646345U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11193756120230763294U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17306750816837208999U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12952818800389361804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15380412293642628312U;
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7706090204767242996U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14598802276412649570U;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 17819762117328075515U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6481384240915075101U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterA, 12U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19522U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 18255U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19707U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23777U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22608U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19434U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererF + RotL64(aIngress, 41U)) + 3973833383430652211U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 57U)) + 5760227042747169187U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 4923009065139227286U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 11U)) + 1477807307009107590U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 5707194514329007301U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 39U)) + 5340439728375269724U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 51U)) + 17080457898946572387U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 281559150259472813U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16160633048230910560U;
            aOrbiterB = RotL64((aOrbiterB * 16883442583309073785U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9003989610509592121U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10579322462808454333U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 100832431598087235U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15059383289528723069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10417647757852880956U;
            aOrbiterE = RotL64((aOrbiterE * 1457919230286043137U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14484665027393813330U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12344463053485837974U;
            aOrbiterA = RotL64((aOrbiterA * 5762654194001525041U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5826453246659297805U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12547902286376986223U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 2982850000322672789U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 9637855144278126174U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2132744427444501938U;
            aOrbiterF = RotL64((aOrbiterF * 5911587798564836199U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9248933938130311231U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13274297928717090383U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2901398809555237563U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 56U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 30U)) + aOrbiterA) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26865U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 26148U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 31502U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29776U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31294U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 26140U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 26U)) + 4752759164691497960U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 12088872623537639782U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 3734943577379734227U) + aNonceWordM;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 19U)) + 8854778183012444234U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 35U)) + 16948373492893967275U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 7962415690046184385U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 57U)) + 1872682375669714454U) + aNonceWordH;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7776801806943853566U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16665439117257230732U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6866375628213114965U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11088186766134265676U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10850237991780969350U;
            aOrbiterK = RotL64((aOrbiterK * 7547414856143095121U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6464817712131305812U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 244557182884209844U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13261563971157415841U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2323811103717827362U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 11483723582415081925U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12338803568475493422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2811342930111104982U;
            aOrbiterJ = RotL64((aOrbiterJ * 5020981755203607757U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5554497011738996057U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12712169745460598698U;
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17415058661427002973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9430421222715343818U;
            aOrbiterD = RotL64((aOrbiterD * 10321140659099470811U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 28U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererI, 28U);
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

void TwistExpander_BaseBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDF6D7D969D1B5865ULL + 0xE0200923AAFC3F8DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB7B84978F4B6B6F9ULL + 0xB1C0CE74AB6A5535ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xACF2E5159127C213ULL + 0xF5B28D8CA572FA54ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x86CD20ED18646225ULL + 0xF14F54E4C5027763ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA066F364119B8A1DULL + 0xD170BE665493096BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA521A6F7C4C24441ULL + 0x9B77FD7E7C963F80ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB25E1F007C4F27D5ULL + 0xB334C4B00368262FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC0EF08C1F47F87B3ULL + 0xF829958098E40ABAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBDE5485B66694A1FULL + 0xCA143EE377C498E7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBB4A799956390415ULL + 0xC17F690638FB5E59ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9D55A71304771663ULL + 0xA5A9AD086309AEFAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE245BB211B2D8D35ULL + 0xB8CD7E9C2B2D13D0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD81A7D4BAE17F5DFULL + 0x9CB69AF8067C3F80ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x85EBB76DB398A741ULL + 0x95F4D7152B895001ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFA32043A93FC872BULL + 0xB2565773FDD438A2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB049E8CA196BD8FDULL + 0xE4946608E0BE84B9ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aOperationLaneA, aOperationLaneD, aExpandLaneB, aOperationLaneB, aFireLaneC, aExpandLaneC, aFireLaneD, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1905U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 6621U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3203U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6016U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3708U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 3092U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 21U)) + 4634399531433127141U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 16961792729406903200U) + aNonceWordN;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 57U)) + 4105280732301137738U) + aNonceWordO;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 15692013501147331191U;
            aOrbiterK = ((((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 1252216715968780587U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 38U)) + 7958289043012473752U) + aNonceWordB;
            aOrbiterB = (aWandererI + RotL64(aCross, 11U)) + 6611577301818896615U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8506226754305949140U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3648813120449403353U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9521367946879238849U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5195245426245535735U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 542948051600803051U;
            aOrbiterK = RotL64((aOrbiterK * 4631106308856448475U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11974253551208964789U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10596463592332655367U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 10941161258815714641U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12015129484061440159U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8254944355710109060U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3233697992479357615U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2754858806943915419U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5007802002906662779U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15613733948331639723U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6262190752136523216U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10528977986487821428U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1184258264034585525U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8511097226098211854U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12091864735686692582U;
            aOrbiterI = RotL64((aOrbiterI * 6128140528141411237U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterK, 60U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 35U)) + aNonceWordH) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12413U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 11546U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 12518U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10589U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13697U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 16324U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 30U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + 9435962834163239322U) + aNonceWordO;
            aOrbiterB = (aWandererE + RotL64(aScatter, 19U)) + 10524704356081318973U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 13U)) + 7403401305665208680U;
            aOrbiterA = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 7525414805023556493U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 34U)) + RotL64(aCarry, 13U)) + 1116686470029070951U) + aNonceWordM;
            aOrbiterK = (((aWandererH + RotL64(aCross, 51U)) + 13257612299137802420U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 9181543003986598283U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9739384852307501107U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11308402900229016057U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 12690186771773188967U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14935167593705272337U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7171824007631943535U;
            aOrbiterG = RotL64((aOrbiterG * 4839974427616194289U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8068411284829563567U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12350207458513447578U;
            aOrbiterK = RotL64((aOrbiterK * 813973258659041895U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17039236343991574134U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18291683592714999632U;
            aOrbiterB = RotL64((aOrbiterB * 7771718817924840713U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6239616841884430968U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10604527977569876774U;
            aOrbiterA = RotL64((aOrbiterA * 6972820410084939637U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1707724300671717658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3802268808625297647U;
            aOrbiterJ = RotL64((aOrbiterJ * 11296811630387191563U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9423064323799920219U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 242153923313096551U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 12117679073775630197U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 36U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterC, 4U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19951U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 21300U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24259U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24268U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21946U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21665U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 3917730204724097072U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 1874642340716212824U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 51U)) + 6900165757434854160U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 12U)) + 12750946097023807161U) + aNonceWordC;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 43U)) + 6563216048479513594U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 21U)) + 14960240191349450795U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 16306180275951788289U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6502066618271045547U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6219852857850888738U;
            aOrbiterI = RotL64((aOrbiterI * 10892297250334325283U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2272931312452845850U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3028929882263199463U;
            aOrbiterH = RotL64((aOrbiterH * 11005324285856805069U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6067393030073568112U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10094809900437037258U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18095564940730322769U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5962414178157074575U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15755563045799129417U;
            aOrbiterK = RotL64((aOrbiterK * 3692603590609922031U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6321455513889880590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1197435601998121700U;
            aOrbiterG = RotL64((aOrbiterG * 17693996266260557625U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12496949381666299968U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6357070235648527030U;
            aOrbiterB = RotL64((aOrbiterB * 2931486644220862433U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 8423760160877540210U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8090246492554850768U;
            aOrbiterF = RotL64((aOrbiterF * 2949407491181921633U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 4U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30111U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 28754U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30498U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29500U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27840U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 25808U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 6342299552323486695U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 5U)) + 12692748514781367538U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 8202639945493229155U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 4439975701793231639U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 11U)) + 16774235182859553759U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererH + RotL64(aCross, 41U)) + 8764155413335405667U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 23U)) + 7167848811974967685U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16768278912125334220U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9090838954826296201U;
            aOrbiterH = RotL64((aOrbiterH * 5459329624017272077U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7644075729758006298U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17326182797908071215U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16158809721888137555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8029938783858263694U;
            aOrbiterK = RotL64((aOrbiterK * 12628072435324195483U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8716553521415553404U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7012599977009208840U;
            aOrbiterJ = RotL64((aOrbiterJ * 8775355876188948851U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13250558696578541499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13705957059101025396U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 16889495686487056367U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2796775206291902461U) + aNonceWordH;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 13741676263512390669U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 10455782033465595947U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1691908360612389252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4114939415206031540U;
            aOrbiterG = RotL64((aOrbiterG * 2797401802892718297U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + aNonceWordD);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 34U)) + aOrbiterH) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 20U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BaseBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8E232D713D219E87ULL + 0xA8BAE21625F8B57CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEE1E47CF64C867C1ULL + 0x92AEB8FC4E9B6BB5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x920F40EA8DD8DFADULL + 0xC073B48F3EF9DEA6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9032A416EFA2187BULL + 0xB3A13EEDF9F533EBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEB301ACB276B70F3ULL + 0xB796604B2369C7BFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDECD1B277B4F3F79ULL + 0x9D05E9D368E919E9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC86575618785A195ULL + 0x9E788B7A13FFB9AEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEA43755B037E3993ULL + 0xC45B61D2F0A22BB1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEB5FB961A17EFCBDULL + 0xAFCD54B609A6B740ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFECFF07080828941ULL + 0xAF91A3343CD78A3CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8A01D759D232CFF5ULL + 0x8714C62781BEC4AAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFB856C42D90E9E6FULL + 0xEB1B50509ADCFC67ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA2DE7CA4A69110F1ULL + 0xECC6BA21F9E9A432ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCCE6A66D39E7EA11ULL + 0x846A3A8D7EBB7E34ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x852B13B759D5D247ULL + 0xC8FB5F2D4389133BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFCCD6A184628B39BULL + 0x83B11F2CDF4171C8ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aWorkLaneB, aOperationLaneA, aFireLaneD, aFireLaneC, aOperationLaneB, aWorkLaneD, aWorkLaneA, aOperationLaneC, aWorkLaneC, aFireLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1239U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 6482U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5183U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5510U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2350U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 1803U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 3105313968748067810U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 23U)) + 9977249451119627064U;
            aOrbiterA = (aWandererC + RotL64(aCross, 56U)) + 17941392803495349366U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 5U)) + 4279533326705471133U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 43U)) + 13983828966811580039U) + aNonceWordH;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 3983490984234810378U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 308786542215259956U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 26U)) + 8443607695364427037U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 19U)) + 14939626441464340668U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 9350693577306121110U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 51U)) + 1717071159396961752U) + aNonceWordC;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15911765265202100610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14898546272333182767U;
            aOrbiterA = RotL64((aOrbiterA * 2674900543810733067U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3560903518513465868U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5367062725726860234U;
            aOrbiterH = RotL64((aOrbiterH * 8521908836601319553U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15233321480618877327U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9288449812290126074U;
            aOrbiterJ = RotL64((aOrbiterJ * 6815298520404038519U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5504840529511585676U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6825598386801620046U;
            aOrbiterI = RotL64((aOrbiterI * 11666542445846250077U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6433024450721339470U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 97934156644929458U;
            aOrbiterG = RotL64((aOrbiterG * 8630530773006923215U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3260053604798744515U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16539416623243059076U;
            aOrbiterC = RotL64((aOrbiterC * 12199577351166064503U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 9814290051339038920U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 13280156404507444041U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 15269010043398910061U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11853942590993546833U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13207869904312989977U;
            aOrbiterE = RotL64((aOrbiterE * 15503461937625795969U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14536032167989376750U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3693282775047432356U;
            aOrbiterK = RotL64((aOrbiterK * 5290349323647887877U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5803176485246280271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16702526675475954730U;
            aOrbiterF = RotL64((aOrbiterF * 13695676754973145769U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16454171963808313625U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3105313968748067810U;
            aOrbiterB = RotL64((aOrbiterB * 16572687178789102843U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 42U)) + aOrbiterK) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterF, 38U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9171U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 12007U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11951U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13866U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12874U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14626U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 58U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (aWandererG + RotL64(aCross, 53U)) + 11998579547770778580U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 23U)) + 8409465187298704610U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 56U)) + 3470222286110333500U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 5704486785203069994U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 10334944660253279633U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 11U)) + 7626852700722567477U) + aNonceWordK;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 47U)) + 14631310754943209743U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 27U)) + 807160297237854120U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 13U)) + 5624154783624196107U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 58U)) + 4971444394698940423U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 6340057638461027062U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9003019862787819481U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13632057463595873033U;
            aOrbiterB = RotL64((aOrbiterB * 12575202147280216765U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12766104026871797746U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4062118445824915939U;
            aOrbiterG = RotL64((aOrbiterG * 13130770039048080701U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5258212525426469978U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9956946981015983939U;
            aOrbiterC = RotL64((aOrbiterC * 8106382657040497669U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10837606223056473999U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13292864885504191134U;
            aOrbiterH = RotL64((aOrbiterH * 4445739587553669471U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 166087925900318658U) + aNonceWordE;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 6786842221885441388U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 4411147600413147773U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16888086378070246404U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5240855484445974002U;
            aOrbiterD = RotL64((aOrbiterD * 402652898573422271U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6874866669211571608U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 732890824978127460U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3776365957702257453U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5541380495707308058U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17947326584411475765U;
            aOrbiterJ = RotL64((aOrbiterJ * 10920952349981652899U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15060679340045767910U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1675974028461383576U;
            aOrbiterI = RotL64((aOrbiterI * 15127962310365242819U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 226889112033170368U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4290719734244011388U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6453598182035414143U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7712233480730639084U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11998579547770778580U;
            aOrbiterF = RotL64((aOrbiterF * 11599893373156816375U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 36U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 52U)) + aOrbiterJ) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterE, 21U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 22U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21315U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 22190U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20757U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18563U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16539U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16962U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (((aWandererA + RotL64(aIngress, 37U)) + 8866844335448071821U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererH + RotL64(aCross, 21U)) + 15159698739856430085U) + aNonceWordL;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 58U)) + 9582805772989594633U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 23U)) + 1438538239931588373U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 3U)) + 10862044156620436139U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + 13682173320058164615U) + aNonceWordG;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 8351013291045977592U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 15777857431516633916U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 47U)) + 16178966745333885377U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 43U)) + 9031889187993001617U) + aNonceWordE;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + 6308472367425865347U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 642109145903321046U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10714674348507516749U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6091345356803675860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13218507921880873749U;
            aOrbiterE = RotL64((aOrbiterE * 15415157927185637717U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4266652275234474616U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4391422098164506195U;
            aOrbiterB = RotL64((aOrbiterB * 17634679403195085867U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5160682323243635577U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10351728852161347404U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11105410036471745951U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3950932176454814023U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9536466386833427441U;
            aOrbiterD = RotL64((aOrbiterD * 18064984243491293435U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9927425919978776529U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6819384090527481081U;
            aOrbiterH = RotL64((aOrbiterH * 18032965969184368561U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1646274931424218507U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16166524473976135097U;
            aOrbiterG = RotL64((aOrbiterG * 11672192658072663849U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11252501968059485262U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16847854447987609067U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6326299154627028295U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16723218285355036446U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13870211254243048975U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 10203222183774624097U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11401147367366049493U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4266628469244269926U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2409934496621365221U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11578385782347296942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8866844335448071821U;
            aOrbiterC = RotL64((aOrbiterC * 6456956795450036515U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 36U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterI, 40U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aNonceWordM);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterB, 42U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 46U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27989U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 25463U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27201U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29705U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26270U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32421U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 2786079456995203065U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 58U)) + 7237256119153857253U) + aNonceWordL;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 3U)) + 9310834010563647604U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 17361734905706517877U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 15837111231884647451U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 5U)) + 18065431964418026445U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 13U)) + 3029123922999952652U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 5166926595573507837U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 54U)) + 1918425684273807598U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 11U)) + 4724551751012661440U) + aNonceWordM;
            aOrbiterD = (aWandererC + RotL64(aScatter, 37U)) + 1818014487579644390U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6670090372241084216U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8485757110007268693U;
            aOrbiterH = RotL64((aOrbiterH * 11876760095108618363U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4928130251509514742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2528788422725346792U;
            aOrbiterI = RotL64((aOrbiterI * 1855982047967756661U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2860387120895147503U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12927802338151379368U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8876144125458603029U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18029699867733207083U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13361836994951253312U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5349767426256597073U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11957294454794128079U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3755417922063414648U;
            aOrbiterA = RotL64((aOrbiterA * 13896364063651241401U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18001157153447913032U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16214145724690286854U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5874139687703360515U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3860958772090975562U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12395621524459640173U;
            aOrbiterG = RotL64((aOrbiterG * 722817135977510161U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3402035664910754484U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2139099117325745602U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 14008983756425796029U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7769274487425053026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6492669707749367728U;
            aOrbiterB = RotL64((aOrbiterB * 5149771861620757839U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14963366447884375043U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11398874662567519691U;
            aOrbiterC = RotL64((aOrbiterC * 8221521452475029835U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7168445485232814860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2786079456995203065U;
            aOrbiterE = RotL64((aOrbiterE * 14258367164534307955U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 50U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 28U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 42U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 22U);
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

void TwistExpander_BaseBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x86CE525D8C99BCBFULL + 0xD93B3572D995D0B3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEB0FA13CE0CB97EFULL + 0xA89F2753A5FF220CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEDF40DDB6214034DULL + 0xDE468320DFB1527DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE33618F32C0BF1F7ULL + 0xEAB9735852F83241ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x89944C072BB14755ULL + 0xFC433F6407255FB7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE1E6E3CA59B04AF5ULL + 0xB8022B2BC150321AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE86BD70DCDED3C75ULL + 0xDC296CCA232F856DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA8CC2E2EFF29E019ULL + 0xA738272DD71116C9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF640931FA4BEE013ULL + 0xFDBB3CCB10FFFC58ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA7F0C2D079763D8FULL + 0x9BBB562C00D15413ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD095F8ACFADAB2F5ULL + 0xCB07C247159CFC8AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB5D4257D7F8665C9ULL + 0xF84BF400CB80334DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBEB75B6169EC8845ULL + 0x92DADD5A53F597FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC8CA67FC821B8C71ULL + 0x9E422EF6237B25EBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCC34E9A8FA0988F3ULL + 0x9CF157FE847CF7B8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC51A666C3CCAA751ULL + 0xA73E2C76AE964763ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aWorkLaneD, aWorkLaneB, aExpandLaneB, aWorkLaneA, aFireLaneC, aExpandLaneC, aFireLaneA, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8004U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 3709U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 5755U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3296U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3491U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2130U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 34U)) + 16651241552253078315U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 4558144676982478003U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 8814884320080367550U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 16011579668555672117U) + aNonceWordO;
            aOrbiterG = (aWandererA + RotL64(aCross, 23U)) + 4738918668759862438U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 46U)) + 12526083125540985108U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 8048723561746000552U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 39U)) + 1082218464034639039U) + aNonceWordB;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 8432043246965946816U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9982080524048636852U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6720069955755215919U;
            aOrbiterC = RotL64((aOrbiterC * 1025046364205332059U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1019035028070247757U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7360619079463870467U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10893918488381348474U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1390297670907738019U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11909657437658597735U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12512200589031203480U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14741471280748399540U;
            aOrbiterG = RotL64((aOrbiterG * 3012135242889901095U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8543897248359826770U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8545972622733791272U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 11793879362775346821U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7049384618581928664U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14730773807906925408U;
            aOrbiterH = RotL64((aOrbiterH * 10711566871536755073U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11480717275652449986U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1135397594974536859U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 6347492892938856497U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6897207625849516702U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10920630712550287148U;
            aOrbiterB = RotL64((aOrbiterB * 4140705091806993359U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1094056478999931332U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6784487144549717207U;
            aOrbiterE = RotL64((aOrbiterE * 6295177724167067891U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 46U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterH) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 6U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15473U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 11356U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15764U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12417U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12392U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 14851U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 30U) + RotL64(aPrevious, 43U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererE + RotL64(aScatter, 22U)) + 13204735390996728477U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 47U)) + 851171359595647173U) + aNonceWordJ;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 5U)) + 16745304202825290723U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 562392736584913979U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 3244267012529053918U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 43U)) + 17282536111067869133U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 14851130066471729068U) + aNonceWordP;
            aOrbiterB = (aWandererB + RotL64(aCross, 57U)) + 5256130407952363129U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 18U)) + 2904742485828362001U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3723346325449225387U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5344621093694027341U;
            aOrbiterG = RotL64((aOrbiterG * 9044881458629673499U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12919263300833603026U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17989801264160996071U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 15468293047311883751U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5022175042377172157U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16684822380107847758U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2834049270263837537U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2740326510600876682U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13981423865219318820U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14593082145080056441U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 231945878229848395U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14139797734944312580U;
            aOrbiterK = RotL64((aOrbiterK * 6492256080432266407U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16704102101387552373U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8506734780526852552U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 4684566118627414659U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2774630043988894695U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12490034334296488127U;
            aOrbiterC = RotL64((aOrbiterC * 16765455396278233145U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 545238171291436006U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1023872898002379590U;
            aOrbiterB = RotL64((aOrbiterB * 8626333831510136515U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5065187021047872560U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10391809965648089863U;
            aOrbiterI = RotL64((aOrbiterI * 10912471108849550469U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 30U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 48U)) + aOrbiterJ) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21598U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 22137U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19444U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20178U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18681U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 16780U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 18U)) + 1393781663398437180U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 17414594746688585273U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aCross, 11U)) + 2823888497053071250U) + aNonceWordM;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 39U)) + 17032631958617884859U;
            aOrbiterA = ((((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 15222697630461125019U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 30U)) + 15737414920751551780U) + aNonceWordC;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 23U)) + 1357196111055783001U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 5315122321649251691U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 57U)) + 7893744655508595974U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16721939414324611738U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3444375866323610848U;
            aOrbiterB = RotL64((aOrbiterB * 10874157227815775661U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1825716513674511632U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15582066843912467318U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12765146555943757373U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15673590949193923915U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13887365046280406413U;
            aOrbiterA = RotL64((aOrbiterA * 3169061375011420121U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12730414371734709356U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4819112390640821927U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 8782547948627685451U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3089925954422937464U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7180179304678622530U;
            aOrbiterI = RotL64((aOrbiterI * 16118051565147747413U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17030269962085008657U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6675917351883004046U;
            aOrbiterK = RotL64((aOrbiterK * 14134335325316949687U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12572022803491077491U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2801421744689267375U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 315045745990934023U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4335148696780313055U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12526298573395110141U;
            aOrbiterE = RotL64((aOrbiterE * 11276803410698178607U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6984239833558496091U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12195433952105336808U;
            aOrbiterJ = RotL64((aOrbiterJ * 8642600547427664495U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 60U)) + aOrbiterK) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 20U) + aOrbiterD) + RotL64(aOrbiterA, 52U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28531U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 24919U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32191U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32557U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25152U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24601U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 50U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererE + RotL64(aIngress, 29U)) + 1557680213571812384U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 19U)) + 7387349725778021121U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 15379264067601586976U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 5U)) + 3730195724576043708U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 11U)) + 9637070085323827066U) + aNonceWordP;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 47U)) + 1170865717363676184U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 2750833653175252030U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 15118992811225568305U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 13U)) + 4974092922102988451U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10625719096296719514U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 855167122475471865U;
            aOrbiterJ = RotL64((aOrbiterJ * 7441090331293158773U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11322911068958340262U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4334591909425429835U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14263701737208936392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 678723206735649084U;
            aOrbiterH = RotL64((aOrbiterH * 10823239851733632227U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15652053114252065230U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1705225940224061401U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 3626023093533713579U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6826394665732900206U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11902946775066981141U;
            aOrbiterK = RotL64((aOrbiterK * 18300629262162694137U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9802212958998591310U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14001358545610206524U;
            aOrbiterG = RotL64((aOrbiterG * 13172645840788327099U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4299184726135884309U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7288757011999872416U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16806027820468277393U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 233801262480580205U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14208660347238680268U;
            aOrbiterF = RotL64((aOrbiterF * 6299693448313154603U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9217797359740446104U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18165073197136050838U;
            aOrbiterI = RotL64((aOrbiterI * 11677479094709512887U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 52U) + aOrbiterA) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 48U)) + aOrbiterH) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 54U)) + aOrbiterJ) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_BaseBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x83333DDE7EABD935ULL + 0xEB60D12FF8C0C94DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD06812A8D46C910BULL + 0x950DB60D91F9A228ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD0B56C0A9F472C1BULL + 0x8501852B705F4815ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCAD8043BBCD743C1ULL + 0xFEA5C14324A47218ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA933CF5A84B1E241ULL + 0x8AED87E589F5A6F9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE33408CB45037BA3ULL + 0xC65A8BF18444C618ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8A273E5BF98CE329ULL + 0x90B72CBFEB030E01ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDAE2F30CE1314D99ULL + 0xF375B018616214CFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF8C7EA1A270249BBULL + 0x9DA509914DFC76BFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAEB074A94D85B535ULL + 0x8E53CA5F8F7824BFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC9BF74EAAD53592DULL + 0x8062347622052D24ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC989432D467C6D2BULL + 0x914A462A947F0DF1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDE57AB20D62CFE3DULL + 0xA8798E8836A7ED7EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAFB2347318145D9BULL + 0xE2B7423935F194E7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xED25CCFA19CBF12DULL + 0xB62E20810D4FA00CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE62B27E99208CBF5ULL + 0x92AD02CCF5F594D4ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneB, aFireLaneD, aExpandLaneB, aOperationLaneD, aOperationLaneC, aExpandLaneC, aOperationLaneA, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2502U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 4470U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 587U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6181U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 649U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5185U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 24U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 58U)) + 16183871922837164759U) + aNonceWordN;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 7002058258090219055U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 35U)) + 5650868611888303705U) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 11899839660943876690U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 15349649504488111111U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aScatter, 21U)) + 14060149569086744970U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aWandererI + RotL64(aIngress, 41U)) + 12920917574225030112U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 2831994965175330135U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18312543585028439192U;
            aOrbiterC = RotL64((aOrbiterC * 11618182708195744321U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11657562205118394239U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10850792819281246052U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10663100544207879337U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17810371216216125323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7963413941144223128U;
            aOrbiterJ = RotL64((aOrbiterJ * 534217972450595401U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5498715358793875584U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9256727548911651373U;
            aOrbiterF = RotL64((aOrbiterF * 10498848323914000989U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17246360111302191699U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18309978718113983369U;
            aOrbiterH = RotL64((aOrbiterH * 18267472694666221077U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3100998994319502921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8129301860291235970U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17847033539279176187U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1889641029473279114U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16538494307002917945U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8081488217920885783U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 10U)) + aOrbiterF) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13765U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 15220U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 8867U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14944U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15172U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15994U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererD + RotL64(aIngress, 11U)) + 8506388683755208267U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 2179323259055019735U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 37U)) + 3345902531140983016U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 17456139311481306584U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 23U)) + 14587864088462311164U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 41U)) + 13178947246650647057U) + aNonceWordK;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 5U)) + 12866578138946916962U) + aNonceWordJ;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 13098524333655118173U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15451329483787541982U;
            aOrbiterJ = RotL64((aOrbiterJ * 13580376920467431451U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9494299579678389385U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15581954810375490643U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 13670002280188424825U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4487042505730624892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2774455928791636186U;
            aOrbiterK = RotL64((aOrbiterK * 15847933919136777451U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12435319582397755819U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10077180055177766823U;
            aOrbiterD = RotL64((aOrbiterD * 3924363471701748703U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10391963896910956455U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6149237416725301794U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 10115917698918612823U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15673402771629639978U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14729117178956592426U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 9070464269215820531U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14492001279368870240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6278248084483259952U;
            aOrbiterF = RotL64((aOrbiterF * 16731228350971263873U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 36U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19841U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 24004U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 16525U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22836U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20850U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22484U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 51U)) + 6469584119078165548U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 14329756366517987910U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 12890831797059772123U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 41U)) + 3164503807500018990U) + aNonceWordL;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 21U)) + 177531431387646836U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 57U)) + 3167421392893561015U) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 43U)) + 2813174781844753460U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10953270419153249857U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16911518309710356951U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13162785997686570445U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6616750447844893150U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10276741398025985982U;
            aOrbiterH = RotL64((aOrbiterH * 6824712685896987133U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6206043608461213208U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12021552904553405793U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10023362889960174909U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15283586234744144846U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5923238786775948571U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 8200882393521882651U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11044014510971660078U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9351141024085076044U;
            aOrbiterB = RotL64((aOrbiterB * 13316079344614432317U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17703395981862992420U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10154548848376027087U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 12324478347590509035U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8836420852291617425U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10193385413543886344U;
            aOrbiterC = RotL64((aOrbiterC * 824935982418585449U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 21U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 14U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + aNonceWordJ) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25613U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 28777U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 29193U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28459U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31013U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 30019U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 60U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 1042610313571524121U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 3505725321008825582U) + aNonceWordA;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 35U)) + 12584654563843782991U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 5U)) + 6645399144515770935U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 41U)) + 3608978423753715584U) + aNonceWordK;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 53U)) + 8089198857670370983U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 27U)) + 15207251813516399879U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9579268660105824516U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16055044469473802812U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2269649280637188723U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 583811872609805949U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 7027491967970873942U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 12686754713465826139U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18256061823189677508U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12708429127816136937U;
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12169216645156306078U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12694325407567795065U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3711789483877261899U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16109994660203297503U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4234704064165718913U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 730085881474787681U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14119541943554602878U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8777769004811352951U;
            aOrbiterF = RotL64((aOrbiterF * 2556957257736134223U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15642663488392549609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11594468530833278624U;
            aOrbiterJ = RotL64((aOrbiterJ * 6639306656361601143U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 56U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aCross, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_BaseBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFD435B0780225593ULL + 0x8EAB3CE2667DEF4BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8CBA6B682A6A77D7ULL + 0xCA51F8E4E0CA7647ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x89F793FB9DEFC957ULL + 0xF9F1433B011A314EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C5F140C3B04665BULL + 0xDC4AA3328F4CB367ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE1C1576D4378F109ULL + 0x80A397F93067C82FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE3E550F15D8F6F7BULL + 0xC797A3A4D207D71FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEA66ED286B6C3351ULL + 0x8CB1225FED99993DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA5D2A4CE6DEB4579ULL + 0x9C320423FEF8ED08ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFAFA90904D8B2067ULL + 0x825BBE78D03FF950ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA910DDF8B17512B1ULL + 0xB5B44405F53909FDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA77BD859900F6EE1ULL + 0x9BF3B38AED3952DEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD5FFFB0E3834F241ULL + 0xFE435CD6C76E08BAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC39D17E3B55E97A3ULL + 0xE822642300A10286ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB310F8BCDF06E229ULL + 0xAA67289B299712A4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC1658A8443D1DE29ULL + 0xFBBEE5F3F25866CEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC57DA8CC2FFDF9C5ULL + 0x887B886FA4B9C4C7ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2070U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 67U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 818U)) & W_KEY1], 60U) ^ RotL64(mSource[((aIndex + 2073U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 43U)) + 6361545377408870615U) + aNonceWordM;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 12U)) + RotL64(aCarry, 51U)) + 2967245486744774933U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 3836634268482850139U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 7691642115360086297U) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 29U)) + 16479280384178279281U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 5U)) + 2901468732552539249U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 21U)) + 2600353867755647475U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5666596904781510956U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16108791609267427553U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 8904649663479834199U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8389926875737312112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1689501721163024426U;
            aOrbiterD = RotL64((aOrbiterD * 6517194895779049139U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11721701506949917719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3963842745030140473U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6692473494944919373U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8510538243472109368U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18281865214102080387U;
            aOrbiterG = RotL64((aOrbiterG * 1351546966368884609U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2259725140963665123U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11652011949557979650U;
            aOrbiterA = RotL64((aOrbiterA * 11260100762113295037U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1116085424226174473U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4725260319270802912U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4697109059565450269U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7348945429843437036U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1249234309180653260U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3136745255820405881U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterG, 6U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + aNonceWordO) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3287U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 5377U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3683U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5136U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 6342299552323486695U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + 12692748514781367538U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 8202639945493229155U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 58U)) + 4439975701793231639U) + aNonceWordC;
            aOrbiterC = ((aWandererD + RotL64(aCross, 19U)) + 16774235182859553759U) + aNonceWordI;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 8764155413335405667U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + 7167848811974967685U) + aNonceWordA;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16768278912125334220U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9090838954826296201U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 5459329624017272077U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 7644075729758006298U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17326182797908071215U;
            aOrbiterC = RotL64((aOrbiterC * 2408330168749256075U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16158809721888137555U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8029938783858263694U;
            aOrbiterD = RotL64((aOrbiterD * 12628072435324195483U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8716553521415553404U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7012599977009208840U;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13250558696578541499U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13705957059101025396U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 16889495686487056367U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2796775206291902461U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13741676263512390669U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 10455782033465595947U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1691908360612389252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4114939415206031540U;
            aOrbiterJ = RotL64((aOrbiterJ * 2797401802892718297U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 52U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aNonceWordF) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 50U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordK) + aPhaseEWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7974U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 7010U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8141U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7604U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 8009U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 826930775230515406U) + aNonceWordC;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 5137814617363250861U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 37U)) + 14761561947426681616U) + aPhaseEOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 18U)) + 12773023438753662590U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 57U)) + 7331345852207096322U) + aNonceWordO;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 3899381212671247460U) + aNonceWordK;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + 10072004147620068599U) + aNonceWordA;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3424585039401897560U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8246760141625966321U;
            aOrbiterI = RotL64((aOrbiterI * 11478879365443736383U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3655992860610853290U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11154618022505863898U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4791494171286145231U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15629361991059709973U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10842068502278489664U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 17223002513104960799U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5571312349016336686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 589313823745748879U;
            aOrbiterH = RotL64((aOrbiterH * 1356685926549786027U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13633457935771935260U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12684602052812183096U;
            aOrbiterE = RotL64((aOrbiterE * 4689206269919806711U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5711307583717354204U) + aNonceWordE;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 7181854170553728211U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 9835601115561325911U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1884620014396115821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1471516373272364262U;
            aOrbiterC = RotL64((aOrbiterC * 5126319375714848029U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + aNonceWordN) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9584U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 9655U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 8317U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9283U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8273U)) & W_KEY1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 10362U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 2571116506511057880U) + aNonceWordH;
            aOrbiterK = (aWandererI + RotL64(aCross, 51U)) + 13112435411509707292U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 41U)) + 10403251762787357256U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 11U)) + 8461951095541400405U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 9890793478557463815U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 4U)) + 3030229465991783707U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 7273848154043719247U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10681774862516028276U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7105082755586853104U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12217705329504230357U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6588579345319551129U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14616333550242386092U;
            aOrbiterB = RotL64((aOrbiterB * 2934574715879306337U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15439666290229654921U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3360304356760164799U;
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14438730801970761889U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14515616787452085729U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 2041601927968559821U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4167853822635132419U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8950982233003320239U;
            aOrbiterA = RotL64((aOrbiterA * 887144270884244907U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12391327853728029953U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7100871010552394421U;
            aOrbiterJ = RotL64((aOrbiterJ * 16552349374101955967U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15381697462381887944U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6801677551341079401U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13325954438427340703U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11654U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 13022U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11573U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 11293U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11247U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11459U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 12953U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 1393781663398437180U) + aNonceWordG;
            aOrbiterH = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 17414594746688585273U) + aNonceWordM;
            aOrbiterK = (aWandererI + RotL64(aScatter, 23U)) + 2823888497053071250U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 36U)) + 17032631958617884859U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 57U)) + 15222697630461125019U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 43U)) + 15737414920751551780U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 1357196111055783001U) + aNonceWordP;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5315122321649251691U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7893744655508595974U;
            aOrbiterK = RotL64((aOrbiterK * 17863000246694319149U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16721939414324611738U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3444375866323610848U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 10874157227815775661U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1825716513674511632U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15582066843912467318U;
            aOrbiterA = RotL64((aOrbiterA * 12765146555943757373U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 15673590949193923915U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13887365046280406413U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 3169061375011420121U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12730414371734709356U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4819112390640821927U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8782547948627685451U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3089925954422937464U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7180179304678622530U;
            aOrbiterD = RotL64((aOrbiterD * 16118051565147747413U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17030269962085008657U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6675917351883004046U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 14134335325316949687U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 20U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + aNonceWordN) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16135U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14082U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15067U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15345U)) & W_KEY1], 35U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15711U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15119U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14566U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 20U)) + RotL64(aCarry, 57U)) + 11039986441331892533U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 53U)) + 6256024955965426119U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 9857443189988995666U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 47U)) + 11900944813380998208U) + aNonceWordK;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 5U)) + 8422577734978875541U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 3100835100713928724U) + aNonceWordL;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 35U)) + 11871553509810206993U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17614749493763417027U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3638372131856199916U;
            aOrbiterG = RotL64((aOrbiterG * 480683274898147025U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6582275259281025770U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17016882418498941958U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4269869255230867823U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1747214688658984715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9356088987044015278U;
            aOrbiterB = RotL64((aOrbiterB * 16221733545319753695U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4056238112133473456U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16013150119949532998U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16076621211111834889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9940824359571581765U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 11624767861336495331U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15624084004784515753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7630989544834680335U;
            aOrbiterI = RotL64((aOrbiterI * 12261063237156822067U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 18003586430673313786U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1654118743290334161U;
            aOrbiterH = RotL64((aOrbiterH * 1153250137357176071U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aNonceWordN);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 58U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 48U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16650U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 18379U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(mSource[((aIndex + 17840U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16774U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18323U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18020U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16985U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererI + RotL64(aCross, 34U)) + RotL64(aCarry, 43U)) + 8793908991006073956U) + aNonceWordL;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 2932916283348441943U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 47U)) + 11069042087940968262U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 14369628676782894441U) + aNonceWordH;
            aOrbiterB = (aWandererB + RotL64(aCross, 11U)) + 8602903272780978282U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 5U)) + 3827036107178568820U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 41U)) + 8905245209036772489U) + aPhaseGOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13331387530760017893U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9880107580289737823U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10302652857542703753U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10199619040626900278U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2466307560891374281U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6295342978834217571U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13973403407981259448U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2851460278409385243U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11226902976321781743U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10365453393815690776U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2382382358987358791U;
            aOrbiterJ = RotL64((aOrbiterJ * 481563628980705781U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5058198848163792422U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10500434740387593487U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5946747708776079787U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11289798395177667084U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14327152153231286666U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 18155778059595245561U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8065137263811956313U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3865153574847924816U;
            aOrbiterD = RotL64((aOrbiterD * 9495741102667755161U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 50U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterB, 60U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 57U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19622U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 21618U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20349U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 19730U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21377U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21546U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21003U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 19608U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 11U)) + 2915859148137000694U) + aPhaseGOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 21U)) + 210680583721444425U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 6668118118775650387U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 47U)) + 15794200818099010989U) + aNonceWordI;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 56U)) + RotL64(aCarry, 53U)) + 6565076707062828369U) + aNonceWordK;
            aOrbiterA = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 16323164497808856719U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 41U)) + 7965435318816716560U) + aNonceWordJ;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7390281030573369017U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2269738866911824875U;
            aOrbiterF = RotL64((aOrbiterF * 1198697877998135567U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9664014216039993873U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18284857398028357633U;
            aOrbiterD = RotL64((aOrbiterD * 8402008251343393737U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 367667619795303009U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7935945060956274197U;
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16683666162337789540U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10655658270998102390U;
            aOrbiterC = RotL64((aOrbiterC * 15231596813382239841U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8307037916581540297U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3247742749860703524U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10446792483683818139U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16374602929344972364U;
            aOrbiterE = RotL64((aOrbiterE * 12599903932725787599U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2411334498322777183U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1093701164116833765U;
            aOrbiterJ = RotL64((aOrbiterJ * 13129220206835381729U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aNonceWordA) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordC) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 42U) + aOrbiterA) + RotL64(aOrbiterJ, 42U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23601U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 24059U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21855U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22716U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23664U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22949U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22468U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 23680U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 21U)) + 13481227414590594621U) + aNonceWordI;
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 17425964381118918026U) + aPhaseGOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 60U)) + 4792004356135956581U) + aNonceWordG;
            aOrbiterG = (aWandererD + RotL64(aCross, 29U)) + 11926849936000639098U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + 990697329347742142U) + aNonceWordM;
            aOrbiterI = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 9307721505373076588U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 17605732738841908719U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13110764518634187439U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17970109897810645911U;
            aOrbiterK = RotL64((aOrbiterK * 10395095143998920213U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10273133817644703654U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11239046688920468137U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5197802934333553327U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8355821483275763145U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15522151127786049345U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4844278537850520413U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 5381663179722418112U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9551368011768104906U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14202470972121732997U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16264476585232221270U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7721417776432288282U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 10267770327791051869U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 339418090653475277U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3247926250495935511U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3390560045236418590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3894024951542543635U;
            aOrbiterA = RotL64((aOrbiterA * 10599637790900418767U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 60U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + aNonceWordO) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26751U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[((aIndex + 26795U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25597U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26024U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25841U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26331U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25862U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 26446U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 12690502671561165478U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 17519943923428102801U) + aNonceWordE;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 35U)) + 10705515807975331385U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 56U)) + RotL64(aCarry, 51U)) + 16586447272278538179U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 43U)) + 8006560996840971798U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 13U)) + 12928600185788857701U;
            aOrbiterA = (aWandererC + RotL64(aCross, 5U)) + 14240723153798267172U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8636219177994872072U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7586790235186467512U;
            aOrbiterB = RotL64((aOrbiterB * 15052686382507614169U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1103807034179512424U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7547526530239498693U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 3360295583636013509U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8380239679344786397U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5690809173787433519U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5354724308093372953U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8390902801141804609U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3507306189192059486U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18336280496510253103U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6190745292098482871U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8065418693975056902U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 6414621418430102589U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12111755051718111803U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7605877769709909297U;
            aOrbiterG = RotL64((aOrbiterG * 17525248694315944599U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5969794501112646237U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5127559299360591476U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4521563633438853069U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aPhaseHWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aCross, 4U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordH) + aPhaseHWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterH, 12U));
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28151U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 28321U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28297U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29197U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29118U)) & W_KEY1], 10U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28217U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29125U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 27994U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererE + RotL64(aScatter, 21U)) + 4622023259121087483U) + aPhaseHOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 10253505250223501352U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 43U)) + 17133877904420462669U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 11U)) + 6162827793741796700U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 9610986424765907615U) + aNonceWordK;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 4U)) + RotL64(aCarry, 19U)) + 11210747154264753754U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 37U)) + 16554205219580654546U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10352576357413766388U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3651845783283479752U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 1011289824180799641U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 18145542190463500476U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5415609566767162857U;
            aOrbiterF = RotL64((aOrbiterF * 6474184559323816389U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2033734872464201570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3507213117125813345U;
            aOrbiterC = RotL64((aOrbiterC * 5453058336688881113U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8716253393049851856U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 695984869565941856U;
            aOrbiterH = RotL64((aOrbiterH * 8377921610764044735U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 7661578828878284931U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 906654265099155956U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 8117625377607536949U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6050049984731254612U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17882717590338190821U;
            aOrbiterK = RotL64((aOrbiterK * 10807367411402733215U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4996521991532815957U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4246460672800604436U;
            aOrbiterG = RotL64((aOrbiterG * 12047466401960824903U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 19U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + aNonceWordD) + aPhaseHWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31686U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadA[((aIndex + 31514U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32180U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32321U)) & S_BLOCK1], 50U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32693U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31979U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 60U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 51U)) + 13687218104610230596U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 12U)) + 6841550124960692709U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 17418968668458764131U) + aPhaseHOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 27U)) + 8303537912696948204U) + aNonceWordH;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 35U)) + 12376614417285936537U) + aPhaseHOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 14215749063579232654U) + aNonceWordK;
            aOrbiterF = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 4111736931433665347U) + aNonceWordD;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11250375934571631522U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5367367837773331275U;
            aOrbiterE = RotL64((aOrbiterE * 7262723007545807179U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15514089192382674434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1475991716685034960U;
            aOrbiterH = RotL64((aOrbiterH * 17720681295551650891U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5531622777788629748U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8363822215908303335U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 17850203366840994883U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3741256932685720414U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11634667238062155772U;
            aOrbiterB = RotL64((aOrbiterB * 15925089729784547403U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18180546911210417155U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 5123234656838556335U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 15362857462853398025U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11215734271189250284U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16863747802158398092U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1828035970246160023U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9859050606636646323U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9331300036643654675U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 2502263410556166281U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 44U)) + aOrbiterK) + aNonceWordL) + aPhaseHWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_BaseBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x853BEF57A0104B3FULL + 0x88470D9264440298ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC8FAFEB4A069E449ULL + 0xB6E99CB78E73692CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD75EE296A3353E57ULL + 0x8458B600575BF8A9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8D948FBE26C81E97ULL + 0x9D3629A260371127ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD73A2174CFDC8A77ULL + 0x874FDCC7EFC08B4CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEF2DAA02FF0F913DULL + 0xD65FF8514D7CFE4FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD3FA4BB79C20F44BULL + 0xB0575526CDA73224ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9F4E1985E99BDBADULL + 0xFB9BA35A2791BF01ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x83DAC59332DA4517ULL + 0x90F43423F696B89FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC48982AF24556FE5ULL + 0x9E57E2D43D65CCCAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x930BD5EEF9EBEBCFULL + 0xF844111B2CF4AE3CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x92A3EDBD3B2EE9F7ULL + 0xE3D537E73C4F8039ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8BAE0DF4224A10E3ULL + 0x9EFC5A6659E2DAE3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCE313ECA35972413ULL + 0x805C950538901586ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA47C8AB671B1F5C3ULL + 0xA8230F6B25831147ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9B54F4A77F130ED1ULL + 0x864FE1EE015C0F36ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 879U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 3631U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1168U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2137U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 2180U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 20U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + 15652862298542575895U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 16925323928418184554U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 19U)) + 4413861484961668394U) + aPhaseAOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 2215946422098155969U) + aNonceWordL;
            aOrbiterC = ((aWandererI + RotL64(aCross, 35U)) + 14975185533513111110U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9711613814905834552U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13154957291850149471U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17049677190793844477U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5058313016418534840U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15011423472941211620U;
            aOrbiterB = RotL64((aOrbiterB * 6125316151731105673U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2030053257469580168U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 150530795186791193U;
            aOrbiterC = RotL64((aOrbiterC * 11106050063717096073U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10878237472104183427U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11724672539469573109U;
            aOrbiterH = RotL64((aOrbiterH * 16158741837357985395U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9589700906445846956U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1367381624958248949U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8459515089081211977U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aNonceWordK) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 58U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 38U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7577U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 9756U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8675U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7064U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 7671U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + 3684295017013759987U) + aPhaseAOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 13U)) + 6740408842457292881U) + aNonceWordN;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 4563975890702399441U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 797804144825287940U;
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 21U)) + 2763779540450101303U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 13211846164102089685U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15214578447281401982U;
            aOrbiterE = RotL64((aOrbiterE * 12107189619131483661U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13745208628754232427U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17358621225969190747U;
            aOrbiterG = RotL64((aOrbiterG * 5325024317338823061U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 779739369960480023U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4370963533701407813U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 3123135216876641039U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6061333005507739975U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3589705340762734456U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16499293983611196967U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10607697666369230567U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9356757995305239271U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10945513661439954731U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aNonceWordC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 60U)) + aOrbiterA) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13026U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 15167U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11847U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13922U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14168U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12765U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 47U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 12849591986267890852U) + aNonceWordP;
            aOrbiterK = (aWandererF + RotL64(aScatter, 3U)) + 8232614804696815750U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 12141567259210877281U;
            aOrbiterC = ((((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 2928641981037885644U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 14U)) + 980733350554783938U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2683985177993350746U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14532148403815527355U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15985362037094864225U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7736296629433884203U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10428437770166310549U;
            aOrbiterC = RotL64((aOrbiterC * 326634742742373401U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 18327174144859461029U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6810436935194432002U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2715987179577753597U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12606153309690753435U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 17123256945895150555U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 13469111258504672565U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9057777759026189541U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16478485918911194442U;
            aOrbiterH = RotL64((aOrbiterH * 11054247078884894131U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterG, 48U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 23U)) + aNonceWordO);
            aWandererE = aWandererE + (((((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 57U)) + aNonceWordC) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21604U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 17445U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 21640U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18552U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20770U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20548U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 7825479804710770560U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 11U)) + 5298124167101358123U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 17774541024369233726U;
            aOrbiterC = ((((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 7679371833537454082U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 48U)) + 5385914900748772224U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3879781930908486531U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 659110346638873236U;
            aOrbiterH = RotL64((aOrbiterH * 17439162088869824407U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10749021728538539749U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3631252455767429457U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8552825360915119613U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2271978810960685021U) + aNonceWordI;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 5963558780692551176U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 4772055335210781149U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 974909966119198104U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9296998242911152296U;
            aOrbiterA = RotL64((aOrbiterA * 2613629915877957661U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2245318466901521959U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13391076374843288568U;
            aOrbiterB = RotL64((aOrbiterB * 18094558036982107419U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 34U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordH) + aPhaseAWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 3U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26701U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 24591U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26540U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26120U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26729U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 26763U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 20U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 5U)) + 2177539223979303669U) + aNonceWordK;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 3962004686551521471U) + aNonceWordH;
            aOrbiterD = (((aWandererI + RotL64(aCross, 39U)) + 8457602312617147662U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 18011802451816510632U) + aNonceWordI;
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + 9046101759168876832U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11135620637431969597U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15913029940697999701U;
            aOrbiterD = RotL64((aOrbiterD * 646524659942693491U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16304193109948135982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13208892298820080981U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15093751072618884859U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4182377898949419225U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13970137023071326151U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9075061559681739865U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8402396284835248583U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8859190834060657829U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13552418608113716117U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9760005337757990392U) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14108277760135744897U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 4474681104256093885U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + aNonceWordC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + aNonceWordD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 28U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32027U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27652U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31488U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29699U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32695U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 31289U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 54U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 9041099828460168106U) + aPhaseAOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 37U)) + 12883711604096848454U) + aNonceWordH;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 17420968786226443079U) + aNonceWordI;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 3448213891716125104U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 46U)) + 11866455977445336560U) + aNonceWordP;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4119356835384495905U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2186212599698637068U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6756888950976735707U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6506144898969301620U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12556800923644051626U;
            aOrbiterJ = RotL64((aOrbiterJ * 15961043406612913121U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4075551535185182945U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17877694808492008749U;
            aOrbiterF = RotL64((aOrbiterF * 901315308379887473U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5553428900598223316U) + aNonceWordK;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 14362304852277160675U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 11415103199856419303U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9174200302876075831U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16110739511917638547U;
            aOrbiterH = RotL64((aOrbiterH * 7004356839428657949U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordO) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aNonceWordE);
            aWandererE = aWandererE + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 50U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 3U);
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

void TwistExpander_BaseBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF474E3A85BD6A5D3ULL + 0x95D5021BBAD7487AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC26545DA81994BEFULL + 0x87D3DF66E9026CCAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE3380BBF365FA3B9ULL + 0xFB2E9D80B4757BB1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDAAEE2CEE6A4DD4BULL + 0x9D22E4BC897C471AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x88164AC3DF5ABD75ULL + 0xEFE6ABE367002607ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD4AD49DF415BEBE7ULL + 0xCB6CDCFE8D44432DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x83C926A5115B17CDULL + 0xFEBCD312AE678F16ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE09A1B9C57E031F9ULL + 0xF84E3FD65DFD3EF9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9ED29B4A933A91A7ULL + 0xE5954857896BAD7AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x805C4F68A80A0981ULL + 0x955CF4E18E225A0EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCFB4ADDB4AB95CDFULL + 0xA10C2E382CCECD78ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF4E69E4B8680D553ULL + 0xA5827FA63AC7B890ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFCA17A2475648A3FULL + 0x985E56037DBDF67FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFD3EE6BA2F7AFF49ULL + 0xBB7D1A795970F970ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCF36062AB4CA584DULL + 0x8C726752B9DB7165ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x92B2F33D8B6741EBULL + 0xF419DFE38ED9E67DULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneA, aInvestLaneC, aExpandLaneD, aExpandLaneC, aInvestLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneD, aWorkLaneC, aExpandLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 193U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 385U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2316U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3940U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4736U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 1492U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 34U)) + 1708250618750199233U) + aNonceWordO;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 29U)) + 12009147777553691142U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 13U)) + 8393982703399156592U) + aPhaseBOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 3247327098356831221U) + aNonceWordG;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 3403590155376353737U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 19U)) + 18197244558104735044U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 3096253642040701606U;
            aOrbiterC = (aWandererA + RotL64(aCross, 24U)) + 8012692688785412179U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 57U)) + 17531946907545680745U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17687695944270225817U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16147773866007628769U;
            aOrbiterK = RotL64((aOrbiterK * 16926442582711557877U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18244641303026196497U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8839160526348897457U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14268021129087663397U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10599266240854068246U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2056723540756216155U;
            aOrbiterA = RotL64((aOrbiterA * 13311591601230386375U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4629354220460621284U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9505955649473204942U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17775391885312236187U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17078153810088721310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9470436761716263000U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5431855497250357229U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 3305863413630104742U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14377172434239576161U;
            aOrbiterF = RotL64((aOrbiterF * 6880176890091033423U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 415687827894226513U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16975319836893760993U;
            aOrbiterG = RotL64((aOrbiterG * 6597144958013976445U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12707054129431596074U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8974182792497231239U;
            aOrbiterJ = RotL64((aOrbiterJ * 7874658957269462717U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10826131924322955095U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4168545139712703154U;
            aOrbiterC = RotL64((aOrbiterC * 10305904857550051705U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 22U)) + aOrbiterE) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + aPhaseBWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 52U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 18U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 40U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6143U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 6226U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9099U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7944U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10041U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10011U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6351U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 28U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 16451272412693907816U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 10099485419723255462U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 28U)) + 17668900099534923192U) + aNonceWordO;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 5497093724143181753U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 41U)) + 10354044773550071706U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 37U)) + 12728258851198019099U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 3U)) + 4144050505314242618U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 23U)) + 14133805325480076530U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 50U)) + 308863673210602899U) + aNonceWordB;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11741180130160569753U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12926863156769180448U;
            aOrbiterJ = RotL64((aOrbiterJ * 9726030996091054939U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 211920854786494259U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 13234608842479411078U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 2556747209733759467U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9164711974854618892U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6667377062281954219U;
            aOrbiterE = RotL64((aOrbiterE * 2603737166987437649U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4559040002406721850U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1749875480850675109U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15822640067349481089U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9555365165561936366U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 18289733999504213574U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 14156217554673229429U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8727162691639622461U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 291406782452963706U;
            aOrbiterI = RotL64((aOrbiterI * 8413500075082350243U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8294911802626492257U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15853578397277298548U;
            aOrbiterC = RotL64((aOrbiterC * 13256191781365357747U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11535146194939658681U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2177540476748375661U;
            aOrbiterA = RotL64((aOrbiterA * 15791341922007841029U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2705306323728084136U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17617871830709148043U;
            aOrbiterK = RotL64((aOrbiterK * 3449981219502809255U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 58U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 54U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12901U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 13450U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 16062U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12496U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 14666U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 39U)) + 16519040829220310189U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6888002778416941825U) + aPhaseBOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 19U)) + 1310832187746534025U;
            aOrbiterG = (aWandererI + RotL64(aCross, 26U)) + 5890888009051281674U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 5143864838362464857U) + aNonceWordB;
            aOrbiterE = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 15591534069452660003U) + aPhaseBOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 35U)) + 1466867671765325096U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 4U)) + 13931443680107902488U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 43U)) + 15400747367673245552U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2836975369734495759U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2370720358274970117U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4615571902817575375U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3470677184188006133U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7175584278499266723U;
            aOrbiterE = RotL64((aOrbiterE * 10067096593682482345U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6095078817776863055U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2176637999243513070U;
            aOrbiterG = RotL64((aOrbiterG * 12215701810843975501U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5580391239754903129U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15196125567953871184U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 12686361960729564519U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12787014151503209931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1523153207064063495U;
            aOrbiterB = RotL64((aOrbiterB * 3113907543551927561U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12973289026485937829U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9087439766232078173U;
            aOrbiterJ = RotL64((aOrbiterJ * 5817029335999350327U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16318022893068674015U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 11089160685103562409U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 17087834321385147603U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8680037953925067235U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3112588943274158119U;
            aOrbiterI = RotL64((aOrbiterI * 9214011370307670371U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16749015684369649821U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9419550535891334966U;
            aOrbiterF = RotL64((aOrbiterF * 5421312787569114811U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 20U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 52U)) + aOrbiterF) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterG, 26U)) + aOrbiterB) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19311U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneC[((aIndex + 20737U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19043U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19220U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((aIndex + 21042U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 13U)) + 13915875634607599122U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 1695770381382411673U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 3709105579778295511U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 37U)) + 7673376335333251804U) + aNonceWordP;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 43U)) + 8814147709738503518U) + aPhaseBOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 57U)) + 13451412605350381172U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 39U)) + 6447870234069609538U) + aNonceWordF;
            aOrbiterK = (aWandererF + RotL64(aCross, 48U)) + 13419487997946496825U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 35U)) + 5478309847615220345U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3635184969215610049U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12527903812035294828U;
            aOrbiterI = RotL64((aOrbiterI * 12540800512035534967U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1684685110885338814U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12860354576326835090U;
            aOrbiterD = RotL64((aOrbiterD * 12743745087733307255U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9081823570147481835U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 14369321778210049109U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 17865953349448767035U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11518132079084873250U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11893535026126957389U;
            aOrbiterJ = RotL64((aOrbiterJ * 15751374986135615095U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7084079180579206226U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2999676609847603277U;
            aOrbiterE = RotL64((aOrbiterE * 14602698397511266403U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17683445810614029153U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11576460512964896969U;
            aOrbiterC = RotL64((aOrbiterC * 5243651036457051155U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13429800604736567949U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14661785761747367546U;
            aOrbiterH = RotL64((aOrbiterH * 4765843989277333421U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12837164345582888950U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6222666313184669392U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17402483466567712319U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5358647039491079457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12459911673401497180U;
            aOrbiterK = RotL64((aOrbiterK * 13605465035256188065U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 36U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterG, 52U)) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterI, 6U)) + aNonceWordH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23763U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneD[((aIndex + 24619U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 26880U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23196U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25696U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 19U)) + 826930775230515406U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 4U)) + 5137814617363250861U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 43U)) + 14761561947426681616U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 12773023438753662590U;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 7331345852207096322U) + aPhaseBOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererG + RotL64(aIngress, 60U)) + 3899381212671247460U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 35U)) + 10072004147620068599U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 39U)) + 3424585039401897560U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 8246760141625966321U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3655992860610853290U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11154618022505863898U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4791494171286145231U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15629361991059709973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10842068502278489664U;
            aOrbiterI = RotL64((aOrbiterI * 17223002513104960799U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5571312349016336686U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 589313823745748879U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1356685926549786027U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13633457935771935260U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12684602052812183096U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4689206269919806711U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5711307583717354204U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7181854170553728211U;
            aOrbiterK = RotL64((aOrbiterK * 9835601115561325911U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1884620014396115821U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1471516373272364262U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 5126319375714848029U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 742739371092077733U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8075893317715227838U;
            aOrbiterF = RotL64((aOrbiterF * 11208274111743259795U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8179547722249281263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15305282712174742323U;
            aOrbiterA = RotL64((aOrbiterA * 7951986906055462929U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1430543231751281079U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14585341768267283387U;
            aOrbiterJ = RotL64((aOrbiterJ * 313213844964269133U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterK, 22U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 58U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31065U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 27857U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31515U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28028U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 29655U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 29U)) + 16124889768301047791U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 11912338587186717280U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 43U)) + 8594012868813114354U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 39U)) + 18281043566156682815U) + aPhaseBOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 48U)) + 16853106130200942302U) + aNonceWordO;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 2611212958619673086U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 23U)) + 18039472325066855180U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 14495785571345122046U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 60U)) + 4556063793412832418U) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14896419970271244358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 880028529183500036U;
            aOrbiterJ = RotL64((aOrbiterJ * 14228281807461251361U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2379557167489415783U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 11854373946064529806U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 150755294320438887U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1487252775956449964U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 12777924204511625545U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15998631485222477969U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8864212892296191613U;
            aOrbiterB = RotL64((aOrbiterB * 579242788050369815U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17069347835763226743U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7443008171694679791U;
            aOrbiterA = RotL64((aOrbiterA * 748894368884566607U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17334256152350782002U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 8986626119086556393U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 2258172145924120235U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8528180968228358674U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12702290928064582589U;
            aOrbiterK = RotL64((aOrbiterK * 15673603224146737631U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7742438100860023610U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3729687240959702198U;
            aOrbiterE = RotL64((aOrbiterE * 3756794766163746783U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 426129097367382096U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16782175452274911213U;
            aOrbiterG = RotL64((aOrbiterG * 1041477289638333659U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 42U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordK) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterB, 6U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BaseBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x82888CDE1A839B89ULL + 0xADE76F5499D8A9C6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xACE7A0CDFFADC2E9ULL + 0x853976DF0A384F4CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA6472A2D74F4F57DULL + 0x9DB821F5EE0FE772ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x893C603AAB5D67DFULL + 0xC4F2517D01E56EB2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAE2FA9D71E0E9003ULL + 0xD20EE69CC0A2DFE4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x93BBEC91ACB5B65FULL + 0xADC4EB0776C791B0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA1854820D4ECA4A3ULL + 0xD2E4D627E34EB1A9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF711D5291EF56EBBULL + 0xA14D0FEDC70980A4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF94B1F297DAD03A7ULL + 0xB7B617E7C8EC4EAAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9E43E0ED54B3CCDDULL + 0x89C63046F2899128ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDC108362ACABB0E9ULL + 0xB96ADB08D4D2D27FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA0BD1BFE678B72EFULL + 0x87BA77825D22155BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x908C8535CBCF26F1ULL + 0x985C25EC2E6125E3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x90DA4A76EF7AA37DULL + 0xA1637A2844AE0960ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x83D1EC83B1CCBD5BULL + 0xE3BF8B36CE4A6217ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAFBBB6CA1FCA4FBDULL + 0x9EFAEBF8BC5C9C52ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2652U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 249U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4898U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 508U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 136U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5194U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 41U)) + 2571116506511057880U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 27U)) + 13112435411509707292U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 10403251762787357256U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 8461951095541400405U) + aNonceWordM;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 9890793478557463815U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + 3030229465991783707U) + aNonceWordP;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 7273848154043719247U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10681774862516028276U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7105082755586853104U;
            aOrbiterJ = RotL64((aOrbiterJ * 12217705329504230357U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6588579345319551129U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14616333550242386092U;
            aOrbiterB = RotL64((aOrbiterB * 2934574715879306337U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15439666290229654921U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3360304356760164799U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14438730801970761889U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14515616787452085729U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4167853822635132419U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8950982233003320239U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12391327853728029953U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7100871010552394421U;
            aOrbiterE = RotL64((aOrbiterE * 16552349374101955967U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15381697462381887944U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6801677551341079401U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13325954438427340703U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 39U)) + aNonceWordA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 12U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8379U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 9763U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8862U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 8558U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6976U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8987U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 10276U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 12U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + 13296600294247799698U) + aPhaseDOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 5818503518080877515U) + aNonceWordH;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 23U)) + 6735784238734173597U) + aNonceWordJ;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 11U)) + 7368398209488856201U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 56U)) + 961734029066455638U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 797011946660892011U) + aNonceWordA;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 12841876018396622350U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16213253970483895623U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15186950557113470375U;
            aOrbiterD = RotL64((aOrbiterD * 4647470430467908107U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5117930310827477341U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12265429373166094162U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1522823535151532249U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13920531346698601568U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14695405206998211456U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13950964363414164279U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7851960904825938443U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9501511171732550190U;
            aOrbiterI = RotL64((aOrbiterI * 5614164120361489613U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5663365182245722077U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9607860124321315555U;
            aOrbiterB = RotL64((aOrbiterB * 3461820361914280601U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18171052650586819280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3442698321538580861U;
            aOrbiterA = RotL64((aOrbiterA * 6317525514963824829U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1491052813469258970U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3956599824067616133U;
            aOrbiterH = RotL64((aOrbiterH * 2928600779267623085U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + aNonceWordO);
            aWandererF = aWandererF + (((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 50U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13795U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 11643U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13735U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11029U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 13766U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 57U)) + 14686411261024919129U) + aNonceWordH;
            aOrbiterB = ((((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 7514582233957632005U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererK + RotL64(aCross, 5U)) + 6520710480103365552U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 1983621978676188036U) + aNonceWordN;
            aOrbiterC = ((((aWandererA + RotL64(aCross, 50U)) + RotL64(aCarry, 23U)) + 9003524602590749672U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aWandererE + RotL64(aScatter, 13U)) + 6428568234045228995U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 27U)) + 8656552687136446989U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16916248288415922490U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9740237548002535784U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7970729853948983849U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 907561000814618339U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4751108900841197631U;
            aOrbiterC = RotL64((aOrbiterC * 4545395964730641957U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 167774899400732287U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11907484918310854962U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 7213139491146402985U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14910318613649863924U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14882888155751455276U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16175942562693781908U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11022373758481651102U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6836331461393816027U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12548405399045031548U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10850926364556828443U;
            aOrbiterF = RotL64((aOrbiterF * 16231561687709867431U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13391684887911141790U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14648937281264822988U;
            aOrbiterG = RotL64((aOrbiterG * 6533299316940026059U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + aNonceWordB) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 50U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterE) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + aNonceWordA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20615U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((aIndex + 19925U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17670U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17895U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 20303U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 44U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 47U)) + 16519040829220310189U) + aNonceWordL;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 6888002778416941825U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + 1310832187746534025U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 5890888009051281674U) + aNonceWordK;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 21U)) + 5143864838362464857U) + aNonceWordO;
            aOrbiterF = (aWandererG + RotL64(aScatter, 35U)) + 15591534069452660003U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 1466867671765325096U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13931443680107902488U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15400747367673245552U;
            aOrbiterB = RotL64((aOrbiterB * 7011651369456453127U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2836975369734495759U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2370720358274970117U;
            aOrbiterJ = RotL64((aOrbiterJ * 4615571902817575375U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3470677184188006133U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7175584278499266723U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 10067096593682482345U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6095078817776863055U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2176637999243513070U;
            aOrbiterG = RotL64((aOrbiterG * 12215701810843975501U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5580391239754903129U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15196125567953871184U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12686361960729564519U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12787014151503209931U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 1523153207064063495U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 3113907543551927561U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12973289026485937829U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9087439766232078173U;
            aOrbiterF = RotL64((aOrbiterF * 5817029335999350327U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 11U)) + aNonceWordM) + aPhaseDWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aNonceWordN) + aPhaseDWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 48U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25430U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 25757U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23024U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26864U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 25588U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 2617613537256538553U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 27U)) + 16642868916835132715U) + aNonceWordJ;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 10860291124337073254U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 57U)) + 6432511273906902472U) + aNonceWordI;
            aOrbiterI = (aWandererJ + RotL64(aCross, 37U)) + 7505375005848241910U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 50U)) + RotL64(aCarry, 5U)) + 11086616004678821329U) + aNonceWordB;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + 3298830587569881951U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9775143140064220979U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4147601326580823120U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13462244678782260871U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12245920269898100415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8391940489176734499U;
            aOrbiterI = RotL64((aOrbiterI * 9119606167674098007U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17876893379544668477U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18301882058180370541U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 16680384667098921309U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6869225862715140102U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15404118372589259800U;
            aOrbiterB = RotL64((aOrbiterB * 5766851935950389915U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17757381020518233814U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17677969146092374455U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3469432916562405063U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15783378556632870114U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 5792858258663697864U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 12008981883482080427U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11737803388202260296U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16001927091970715330U;
            aOrbiterC = RotL64((aOrbiterC * 3062030309852922061U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterD, 14U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29434U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneA[((aIndex + 29611U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30719U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30055U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30210U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 8767379393098711499U;
            aOrbiterI = (aWandererG + RotL64(aCross, 3U)) + 7168159491580816433U;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 44U)) + RotL64(aCarry, 35U)) + 9879279829061883406U) + aPhaseDOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererC + RotL64(aIngress, 27U)) + 10537167136053399303U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 57U)) + 2839070018069188936U) + aPhaseDOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 13844278063968429732U) + aNonceWordN;
            aOrbiterF = (aWandererE + RotL64(aScatter, 11U)) + 11278946626186474646U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 11798425216660557799U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7618446090703335192U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7168757300685156779U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 695423597006983660U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14344728202803488813U;
            aOrbiterG = RotL64((aOrbiterG * 5168825904902285909U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11656100506575697086U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10384358779985773937U;
            aOrbiterE = RotL64((aOrbiterE * 247494692039140973U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17585001605131977341U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9964478171465522911U;
            aOrbiterA = RotL64((aOrbiterA * 13484044854790175315U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2710943171829692624U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17809072853457153057U;
            aOrbiterF = RotL64((aOrbiterF * 16341884203303271365U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12814092033910687774U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1743186323268668740U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11150822630624332557U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10750472346626754704U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15925901217078035356U;
            aOrbiterH = RotL64((aOrbiterH * 9276504171291801637U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterE, 46U)) + aNonceWordL);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 39U)) + aNonceWordC) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_BaseBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x932A976797F66465ULL + 0xFB2C556872F944E9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x86403E9CBB5B057DULL + 0xBE2837905C3248D7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC8031E88EFEB4E53ULL + 0xC30F650698F921E6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFBE4D8242FD99275ULL + 0xA28FEF632EA38CEBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA5B0E85E5D0760D5ULL + 0xCF7FCAB02761FADBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCA25BF258A840605ULL + 0xD18A0EA7AE0CD69EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDB1E2E1A060A4E2BULL + 0x90EF1CAE4492D104ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8A2A49592EE76FC7ULL + 0xD6A11F0790DE15E9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB66B0C62586CC3AFULL + 0xA8CFC7A1B7702945ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x89E13D0375E1B65DULL + 0xD83E1CD63EC970F1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE20C1D35ADF5B7A1ULL + 0xD1A8676F020AD517ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCAB4A6BCFCA372CFULL + 0xEDCC0CCAB3DF23DEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB8E36E135D251167ULL + 0x9189BD84E573E960ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDA87B9CF9239EDC1ULL + 0xEC5358243ECC1C6DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF73E8849900DBA01ULL + 0xB3DD26EB3A080CA2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF51E0C34C7AB0EE1ULL + 0xE3C30F296652E6E4ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3932U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 722U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2346U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4102U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4402U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 867U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (aWandererD + RotL64(aIngress, 35U)) + 826930775230515406U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 5137814617363250861U;
            aOrbiterK = ((((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 14761561947426681616U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 29U)) + 12773023438753662590U;
            aOrbiterD = (aWandererB + RotL64(aCross, 13U)) + 7331345852207096322U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 41U)) + 3899381212671247460U) + aNonceWordM;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 37U)) + 10072004147620068599U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 23U)) + 3424585039401897560U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 8246760141625966321U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 20U)) + 3655992860610853290U) + aNonceWordN;
            aOrbiterJ = (aWandererE + RotL64(aCross, 51U)) + 11154618022505863898U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15629361991059709973U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10842068502278489664U;
            aOrbiterK = RotL64((aOrbiterK * 17223002513104960799U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5571312349016336686U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 589313823745748879U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1356685926549786027U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13633457935771935260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12684602052812183096U;
            aOrbiterA = RotL64((aOrbiterA * 4689206269919806711U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 5711307583717354204U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7181854170553728211U;
            aOrbiterG = RotL64((aOrbiterG * 9835601115561325911U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1884620014396115821U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1471516373272364262U;
            aOrbiterH = RotL64((aOrbiterH * 5126319375714848029U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 742739371092077733U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8075893317715227838U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11208274111743259795U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8179547722249281263U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15305282712174742323U;
            aOrbiterD = RotL64((aOrbiterD * 7951986906055462929U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1430543231751281079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14585341768267283387U;
            aOrbiterJ = RotL64((aOrbiterJ * 313213844964269133U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8123889986027932297U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2081696191347150910U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4869653441012615053U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10166788886199265936U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15927074835525735601U;
            aOrbiterF = RotL64((aOrbiterF * 6747650218540675523U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6997764816848988590U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 826930775230515406U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 9943232461538279601U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordC) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterE, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9994U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 6849U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8234U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9045U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6879U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8720U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5493U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 26U)) + 1457104756581596530U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 6127240317844622874U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 35U)) + 16492290056044189421U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 3U)) + 10963676850938416468U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 47U)) + 4872917367399752405U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 53U)) + 15218882377875616148U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 51U)) + 5934166612122118251U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 22U)) + RotL64(aCarry, 43U)) + 14215280930872003003U) + aNonceWordG;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 11428034799044600979U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 5U)) + 5453003654321728726U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 13U)) + 14273775120265649389U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 328723770018440271U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13032190719588211088U;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2386881543033598494U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1649501123340887116U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16462401546754210583U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1510579201823042227U;
            aOrbiterI = RotL64((aOrbiterI * 16287912400104043275U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6889066000014251983U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11324594596597724357U;
            aOrbiterJ = RotL64((aOrbiterJ * 15344987814648586023U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12237796033168436537U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17306069670330000343U;
            aOrbiterG = RotL64((aOrbiterG * 3167451351403385259U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14197284538008811658U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4754134852883071927U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 3484427259538998699U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17201907781639753736U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8318419319239859855U;
            aOrbiterB = RotL64((aOrbiterB * 10320390501983802091U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16012488623961565780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15583721012865354925U;
            aOrbiterA = RotL64((aOrbiterA * 10656414363201743961U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14680351201973315018U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14483973292275372321U;
            aOrbiterK = RotL64((aOrbiterK * 9279222721410811027U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16324317860030681248U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7038506963317910910U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2960451734542956767U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12767672960346001218U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1457104756581596530U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1560375242310194691U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 26U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 50U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aNonceWordA) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14601U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 11088U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14902U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11078U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12385U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 37U)) + 15904465836916519864U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 47U)) + 17725629806317789307U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 3U)) + 13794170125914914828U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 2149055907476874332U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 5342047776745074649U) + aNonceWordA;
            aOrbiterF = (aWandererH + RotL64(aScatter, 35U)) + 8268148484060546838U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 10U)) + 10821151364028563719U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 13U)) + 4294213820894407378U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 53U)) + 10884726101307943090U) + aNonceWordO;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 16432210042202444824U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 56U)) + 15196602644336228055U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14117787670220328165U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 219833877949480215U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10736293047771972173U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3326396981881473962U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14918513066311426279U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14269763278564574663U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11795234681370163206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3068267285352664813U;
            aOrbiterH = RotL64((aOrbiterH * 15746255933920904619U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 245233356957999496U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 709926406353796673U;
            aOrbiterI = RotL64((aOrbiterI * 13627039596842073595U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5378105439430271038U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10114555061122044430U;
            aOrbiterD = RotL64((aOrbiterD * 5351295043424885549U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13233010815716769713U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8231291294833548389U;
            aOrbiterC = RotL64((aOrbiterC * 10840516135212753869U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7160760224172419829U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14767926435411546785U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 1643485739468851073U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4464245330038080103U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15778166658285494712U;
            aOrbiterJ = RotL64((aOrbiterJ * 13980891936095282989U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2426340576450960905U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6030631392508241438U;
            aOrbiterA = RotL64((aOrbiterA * 13921288910299408423U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15990180955119402476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8707879851984546959U;
            aOrbiterB = RotL64((aOrbiterB * 13794027045755532979U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11665969506971636052U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15904465836916519864U;
            aOrbiterE = RotL64((aOrbiterE * 17042355185093585101U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 48U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 34U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 58U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 26U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17755U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((aIndex + 20467U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21175U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20914U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneD[((aIndex + 17549U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 60U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 9023059520606551446U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 662441755115638133U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 13U)) + 16957253361196144712U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 48U)) + 7840955025765308605U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 29U)) + 346855809270395799U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 21U)) + 16099139781586668343U;
            aOrbiterK = (aWandererG + RotL64(aCross, 5U)) + 3706457327118322098U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 12166825885547622870U) + aNonceWordN;
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + 7792658665720344200U) + aNonceWordC;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 3U)) + 7128477606152986326U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 36U)) + 11116533962780290084U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 10443889548568288532U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13002706161178447654U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 13929727277530310708U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 7005639090871200285U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10949073760696935106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15405923432006783533U;
            aOrbiterK = RotL64((aOrbiterK * 17989565878445202495U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18096057968822208905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3032155040484574973U;
            aOrbiterG = RotL64((aOrbiterG * 448597307502544605U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17462076466907467134U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15471015427013701406U;
            aOrbiterD = RotL64((aOrbiterD * 6113474000571976139U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3549031751266594344U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14243218483842508113U;
            aOrbiterF = RotL64((aOrbiterF * 9041601306479302047U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5803147589312920032U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5549470512227427855U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 12592362489263862879U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10076661824293832189U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3196799148974716550U;
            aOrbiterH = RotL64((aOrbiterH * 8183276968961467775U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5245559903456662243U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5907555542861339984U;
            aOrbiterA = RotL64((aOrbiterA * 10224549416454347583U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12670710096595941569U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 655047039452620836U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9717552134857988153U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2654837870443908572U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9023059520606551446U;
            aOrbiterC = RotL64((aOrbiterC * 170905364378771841U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 4U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 44U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterI, 39U));
            aWandererF = aWandererF + ((RotL64(aScatter, 14U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + aNonceWordF) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 12U)) + aOrbiterG) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aScatter, 36U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25000U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 22733U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24962U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26649U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24029U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 22444U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 3248574644570178787U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 39U)) + 4506961512959200024U;
            aOrbiterK = (aWandererC + RotL64(aCross, 43U)) + 8423739774540738590U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 22U)) + 6593975869641735337U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 16441716090557369103U) + aNonceWordC;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 41U)) + 7936601450453207914U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 13333752583560167065U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 48U)) + 8013703284795432973U) + aNonceWordP;
            aOrbiterF = ((aWandererI + RotL64(aCross, 51U)) + 2349852779887439236U) + aNonceWordJ;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + 5318539364763284138U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 3U)) + 11450957608502944376U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9058992558327552687U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 632095686920230926U;
            aOrbiterK = RotL64((aOrbiterK * 12460364388358520799U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14734218428913777098U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16344357661370784442U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15049472842002138369U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2981145363531184308U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14176472085175714494U;
            aOrbiterI = RotL64((aOrbiterI * 2584623327412130939U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11198457590069700889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4311591763498985972U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16194341833989936369U;
            aOrbiterE = RotL64((aOrbiterE * 9997934560195932575U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7560794022401107431U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10683789740265711603U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 15637823045351977883U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11614366395125937178U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10750771385100564416U;
            aOrbiterG = RotL64((aOrbiterG * 4987921274272444283U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2934697034132204529U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4646873794658020363U;
            aOrbiterH = RotL64((aOrbiterH * 10555456865641580175U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7913681837683568905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17603563535330106340U;
            aOrbiterC = RotL64((aOrbiterC * 17882943067522319671U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15375641415139193079U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17059712718085411887U;
            aOrbiterB = RotL64((aOrbiterB * 13722089235751208215U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14022558453716067200U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3248574644570178787U;
            aOrbiterJ = RotL64((aOrbiterJ * 15249135451439374621U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 48U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 56U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aNonceWordN);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterB, 52U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterD) + aNonceWordF) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29128U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 27736U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29073U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30231U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29510U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 34U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 23U)) + 11450949896247900941U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 3U)) + 3905542253538116335U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 27U)) + 9529740545977785305U) + aPhaseEOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 57U)) + 1856876631533143492U) + aNonceWordG;
            aOrbiterF = (aWandererE + RotL64(aCross, 43U)) + 84253466320181686U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 12577480918745432444U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 21U)) + 5625703170397704029U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 694608607323629282U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 46U)) + 3993981243536262204U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererC + RotL64(aCross, 41U)) + 4119215953484892051U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 8785040118556157146U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16234403619456882890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10398727475672860610U;
            aOrbiterG = RotL64((aOrbiterG * 5086871400049644715U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18327987141759096769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2645964788056875452U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2859452497983106129U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7196557924940881076U;
            aOrbiterE = RotL64((aOrbiterE * 14415389907490256711U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 930127943984174668U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15673596916054795749U;
            aOrbiterD = RotL64((aOrbiterD * 7505660488733199479U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16673140529110941163U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2258448294877833760U;
            aOrbiterA = RotL64((aOrbiterA * 1821550319748977445U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6870209259643931219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12749790107942194104U;
            aOrbiterH = RotL64((aOrbiterH * 4871407285968611725U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17131374134617173866U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6426448390733751612U;
            aOrbiterF = RotL64((aOrbiterF * 12490559588384058417U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15592826434339731146U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14182944418026376183U;
            aOrbiterI = RotL64((aOrbiterI * 7218860482893476233U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17447476498234456596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 972861017466618022U;
            aOrbiterC = RotL64((aOrbiterC * 9610670431280153921U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 13185309156950240549U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14442284480744008537U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 2907844852105175837U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7816745313858811117U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11450949896247900941U;
            aOrbiterB = RotL64((aOrbiterB * 18317765298694454463U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 48U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 37U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 50U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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

void TwistExpander_BaseBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD719F2F27EFCE4DBULL + 0xC86D52A156382F36ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEEB97A3CF86BBA75ULL + 0xF166F55893808825ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF8DC4A7202281781ULL + 0xBD6A214DE5AF497DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBFF4F7163EB3056FULL + 0xAE1E4811B07D1AB6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE759422317E68715ULL + 0xA27B0646907C401FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB82C310478B22DC9ULL + 0xAACD349FE27748B8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA2299B19F1F31693ULL + 0xB97941F3B77ECF59ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD52A3190DDFFE4ABULL + 0xE7864E5041E7E09DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD13425762D824CD5ULL + 0xB0503BFE544C4ECEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF054AA6942235E59ULL + 0xBA76E5336EBD3409ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE8E6C2804B6B0F0FULL + 0xF1B18940FDDEDC04ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDA2D9011302FB2B3ULL + 0xD589BB3337B528FCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB5BFFB7B9EEC5859ULL + 0xF0D44F6176F03EB2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDD862FE4D1851123ULL + 0x868C69BFEF2C2285ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8533F61B5F6101D9ULL + 0xF3C0D6D5A4C5B924ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE6B5895F08C55401ULL + 0x9B6D90BFB484678FULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneC, aWorkLaneD, aInvestLaneB, aSnowLaneD, aInvestLaneA, aExpandLaneA, aSnowLaneA, aExpandLaneB, aSnowLaneB, aExpandLaneC, aWorkLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4558U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 1014U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 3339U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3492U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1191U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3606U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 36U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 60U)) + 5171470532667965920U) + aNonceWordP;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 750549462358682403U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 41U)) + 3325689257577120525U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 51U)) + 18031575461559790826U) + aNonceWordH;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 23U)) + 13874739537012288677U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 37U)) + 4250029868785016865U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 3U)) + 8211158803112611161U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 1083939790236786027U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 19U)) + 3446525462376962464U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6973817815000417325U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15230876489676945543U;
            aOrbiterD = RotL64((aOrbiterD * 7737039082964537651U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9359727659738755880U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8775170107816327654U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 6910680458261008653U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11958941755525038545U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16966819714283167348U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16363457661846050749U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14556087985619763243U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17915047508377045221U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6727635453185130109U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8578745677485367222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7002181668717618866U;
            aOrbiterB = RotL64((aOrbiterB * 12329703532414955235U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3569939503066735457U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2956247934282522184U;
            aOrbiterF = RotL64((aOrbiterF * 9946650822131152531U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4285180013402474041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5976239869535619811U;
            aOrbiterH = RotL64((aOrbiterH * 3458095419039067465U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2424524955161695463U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6849595426583763537U;
            aOrbiterK = RotL64((aOrbiterK * 12727902040238318101U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11414890686374886716U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5668287266836153445U;
            aOrbiterE = RotL64((aOrbiterE * 8011885266143066285U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 42U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aNonceWordJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 19U)) + aNonceWordE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterE, 14U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneC[((aIndex + 8746U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 10356U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7892U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8728U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7116U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9987U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 5509U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 9041099828460168106U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 3U)) + 12883711604096848454U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 17420968786226443079U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 18U)) + 3448213891716125104U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + 11866455977445336560U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 13U)) + 4119356835384495905U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 41U)) + 2186212599698637068U) + aNonceWordI;
            aOrbiterK = ((aWandererK + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 6506144898969301620U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 51U)) + 12556800923644051626U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4075551535185182945U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17877694808492008749U;
            aOrbiterF = RotL64((aOrbiterF * 901315308379887473U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5553428900598223316U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14362304852277160675U;
            aOrbiterC = RotL64((aOrbiterC * 11415103199856419303U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9174200302876075831U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16110739511917638547U;
            aOrbiterB = RotL64((aOrbiterB * 7004356839428657949U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 10189881974519849402U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2128076632642616677U;
            aOrbiterK = RotL64((aOrbiterK * 8860453653433114929U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18133523799074400083U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9916472958834153766U;
            aOrbiterJ = RotL64((aOrbiterJ * 3454601168808001733U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10274457562795569227U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14134814273275356425U;
            aOrbiterD = RotL64((aOrbiterD * 15912501063665343159U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6394306369514735480U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4825761192736485643U;
            aOrbiterH = RotL64((aOrbiterH * 12534544147331805643U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5672807934779206275U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3881953574159390421U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 7448770570912161095U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12012232712634303203U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14176392925893052596U;
            aOrbiterA = RotL64((aOrbiterA * 11288668529893084583U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 51U)) + aNonceWordO) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 56U));
            aWandererC = aWandererC + ((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 34U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15043U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 11093U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15114U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12349U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 13726U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 43U)) + 4752759164691497960U) + aNonceWordD;
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 12088872623537639782U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 3734943577379734227U) + aNonceWordA;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 30U)) + 8854778183012444234U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 16948373492893967275U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 19U)) + 7962415690046184385U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 1872682375669714454U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 34U)) + 7776801806943853566U) + aNonceWordJ;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 53U)) + 16665439117257230732U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 11088186766134265676U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10850237991780969350U;
            aOrbiterE = RotL64((aOrbiterE * 7547414856143095121U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6464817712131305812U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13261563971157415841U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2323811103717827362U;
            aOrbiterG = RotL64((aOrbiterG * 11483723582415081925U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12338803568475493422U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2811342930111104982U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 5020981755203607757U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5554497011738996057U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12712169745460598698U;
            aOrbiterF = RotL64((aOrbiterF * 1985586486150377769U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17415058661427002973U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9430421222715343818U;
            aOrbiterB = RotL64((aOrbiterB * 10321140659099470811U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3926618548181233180U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6172453297026957838U;
            aOrbiterD = RotL64((aOrbiterD * 1161551082037835233U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8633288765997226004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17270881130844274342U;
            aOrbiterI = RotL64((aOrbiterI * 8888559940161770791U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12232950994807835262U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15352600312956742750U;
            aOrbiterJ = RotL64((aOrbiterJ * 6140396356904933003U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 38U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 18U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererG, 6U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20639U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 19415U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16728U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20031U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16927U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 18U)) + 16651241552253078315U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 47U)) + 4558144676982478003U) + aNonceWordA;
            aOrbiterK = (aWandererI + RotL64(aScatter, 23U)) + 8814884320080367550U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 29U)) + 16011579668555672117U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 3U)) + 4738918668759862438U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 47U)) + 12526083125540985108U) + aNonceWordP;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 8048723561746000552U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 41U)) + 1082218464034639039U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 8432043246965946816U) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9982080524048636852U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6720069955755215919U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1019035028070247757U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7360619079463870467U;
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10893918488381348474U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1390297670907738019U;
            aOrbiterJ = RotL64((aOrbiterJ * 11909657437658597735U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12512200589031203480U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14741471280748399540U;
            aOrbiterE = RotL64((aOrbiterE * 3012135242889901095U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8543897248359826770U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8545972622733791272U;
            aOrbiterI = RotL64((aOrbiterI * 11793879362775346821U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7049384618581928664U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14730773807906925408U;
            aOrbiterA = RotL64((aOrbiterA * 10711566871536755073U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11480717275652449986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1135397594974536859U;
            aOrbiterC = RotL64((aOrbiterC * 6347492892938856497U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6897207625849516702U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10920630712550287148U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 4140705091806993359U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1094056478999931332U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6784487144549717207U;
            aOrbiterG = RotL64((aOrbiterG * 6295177724167067891U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 12U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterF, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterK, 6U));
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + aNonceWordI) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 30U)) + aOrbiterI) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22778U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneD[((aIndex + 24111U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 27026U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24483U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneC[((aIndex + 24736U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 4259993311776766595U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + 2857813330021126753U) + aNonceWordF;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 1345396841329442896U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + 320992148982301024U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 12U)) + 5619109532065293074U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 10380157329426706345U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 47U)) + 12449831150625409695U) + aNonceWordO;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + 7847096607042268396U) + aNonceWordA;
            aOrbiterA = (aWandererG + RotL64(aCross, 19U)) + 11707184096803214678U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9893643746186827088U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 333687403830908774U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17911256836121454271U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13837360705077441580U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4367119682175710689U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 10295744669174603401U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1193493435041306784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15062951612027370606U;
            aOrbiterC = RotL64((aOrbiterC * 2509383510565136549U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16000173839235429105U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15294482444605409961U;
            aOrbiterG = RotL64((aOrbiterG * 1031800997944302665U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5720749055549773527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17248674962996093668U;
            aOrbiterK = RotL64((aOrbiterK * 15730637462755795591U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16956840483882091059U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9637715107943515594U;
            aOrbiterF = RotL64((aOrbiterF * 8878362378343603463U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7147495779349862274U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7508890985889484275U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 17728368447504622035U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4407738164617959366U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17027017782352660454U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 417183060881259295U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3174658601748235285U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9779053567370714831U;
            aOrbiterJ = RotL64((aOrbiterJ * 6383245776181968033U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterK, 46U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aNonceWordM) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterB, 56U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31559U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 31653U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32447U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31984U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 32684U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 54U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 27U)) + 15045917390223766480U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 37U)) + 10763054007033668758U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 13U)) + 13190170142593666607U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 4U)) + 9657025731441167065U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 57U)) + 11433367178975954211U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 17904920143996810366U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 23U)) + 3244383020512113283U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererC + RotL64(aCross, 50U)) + RotL64(aCarry, 13U)) + 6538815775171139091U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 7195368312757976343U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18134430713910279374U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6571776588427107976U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11830778129647517758U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9793702760907767365U;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2287235876793192036U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8951959188326141794U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9968356718110753845U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7583061790273240157U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3571364625022806085U;
            aOrbiterC = RotL64((aOrbiterC * 6238360922735480669U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13869345563551689212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 277480328952975002U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1057564597096163085U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4983735092494677578U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9490022869381030928U;
            aOrbiterG = RotL64((aOrbiterG * 12926352917961703123U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7928039573014765566U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6504190875809407084U;
            aOrbiterB = RotL64((aOrbiterB * 14648214826494826711U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2787985600176307413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16308785053443116826U;
            aOrbiterH = RotL64((aOrbiterH * 17867565986311256691U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12788128335006767824U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1187040019537798339U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 10834905007658184183U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 34U) + RotL64(aOrbiterI, 34U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 28U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aCross, 48U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + aNonceWordO) + aPhaseFWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
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

void TwistExpander_BaseBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8DF1C7158C20A65FULL + 0xEB521AB38C248DA2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCD356A3BD27B9187ULL + 0x845E8001D1362F60ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE0A6FC397A83AD39ULL + 0xD9CAC45E09EF97F8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCEE56D52621624EBULL + 0x90F40A4CDA0A7DB2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC533B182B648810FULL + 0x9617252C3A1AEAF1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCC1609558C8105FDULL + 0xE33577914E28BCB9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB950C81AC52FEFA1ULL + 0x8EDFC02AF49E8A00ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB1891A7C86986BD5ULL + 0x80632BA054029AAEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x90FBEFC9C5B47611ULL + 0xDC964FF39BA7D0A6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x86D915C7981486F9ULL + 0xB3CBA6EBCF827A38ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA203850D9595C4A7ULL + 0xB452D84C237F8FF8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFC7C3195D87C988FULL + 0xEE45EC86E6237D33ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDB4B5D6527296683ULL + 0xDF3247ACB96DDAC2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE0BE0B40AB63E457ULL + 0xE190804753CF433FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC3E28AEB89ACDA83ULL + 0xF9791569C8CE7220ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAD754FFC36A29D83ULL + 0xA951C3EF6435945EULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneB, aSnowLaneC, aSnowLaneD, aInvestLaneA, aWorkLaneA, aFireLaneA, aInvestLaneD, aWorkLaneB, aInvestLaneC, aExpandLaneA, aInvestLaneB, aExpandLaneB, aFireLaneD, aExpandLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1735U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 714U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4403U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2233U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3503U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 8375305456876489425U) + aNonceWordJ;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 37U)) + 16193562952772453047U) + aPhaseHOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 57U)) + 18088652458594816223U) + aNonceWordF;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 767344788620249944U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 7705194930396368752U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 27U)) + 3829736891311272834U) + aNonceWordG;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 44U)) + 9881681671347640061U) + aNonceWordA;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1721196560190164264U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3002652618388454213U;
            aOrbiterK = RotL64((aOrbiterK * 15289749311593032657U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9811621464004005202U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5652598941069986530U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 4797973356708091621U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6250499348327316328U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16025054277615264530U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16446892258704281903U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13800298546867243172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12256104592865905782U;
            aOrbiterD = RotL64((aOrbiterD * 16983140179497142713U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17817225416918329229U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17738671327352776217U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 393488251327705063U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6816031224188400541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16989563985059237014U;
            aOrbiterG = RotL64((aOrbiterG * 8677884225771717797U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16891524847268207549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1833508573940405571U;
            aOrbiterC = RotL64((aOrbiterC * 9709196587703979539U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 26U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + aNonceWordK) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9589U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneC[((aIndex + 9236U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10186U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8939U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8155U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9826U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6715U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 12426357877879529292U) + aNonceWordI;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 12604900366173639176U) + aNonceWordE;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 28U)) + 13511119007338929401U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 11U)) + 9878720081166788060U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 15463195409806395076U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + 6407922778852833423U) + aNonceWordM;
            aOrbiterK = (aWandererC + RotL64(aCross, 51U)) + 7690427254160734016U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18030974031722143619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17983938038322737041U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12479365337221685413U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16605512170117753884U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 681802273302348322U;
            aOrbiterF = RotL64((aOrbiterF * 14608920184802647123U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15550312921312083819U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17824154101711884508U;
            aOrbiterA = RotL64((aOrbiterA * 7358612830654795357U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1939207786756735430U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3132864634777826569U;
            aOrbiterG = RotL64((aOrbiterG * 13606281919426730325U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12822929773923954849U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16576106045887115660U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16370914370769903051U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2398825881649235260U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 13700821892926092479U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 10830623703416956043U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2439833784883391606U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterJ = RotL64((aOrbiterJ * 3797380922767479287U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 12U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 6U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordP);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + aNonceWordK) + aPhaseHWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13551U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneA[((aIndex + 15914U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 15878U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15523U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11969U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 48U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 35U)) + 3255291173184001106U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 15308468160116255528U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 18186972408589866656U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 27U)) + 4439324265978331914U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 35U)) + 13099263173016322486U) + aPhaseHOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 5U)) + 7041561081767500660U) + aNonceWordL;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 57U)) + 6196422612687812971U) + aNonceWordH;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7664260932541281413U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17802347823020441056U;
            aOrbiterE = RotL64((aOrbiterE * 2220679459017369255U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4253107484061190446U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13799496534030645312U;
            aOrbiterI = RotL64((aOrbiterI * 9167675060053848207U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14252892847595951926U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5663527578664291422U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18314294235895182465U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11148755959699137661U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterJ = RotL64((aOrbiterJ * 16041243617369003291U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2403828181385259549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17813580350434928194U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5623611126885414523U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7293224381174846969U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 7032561584670788117U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10602620906929686163U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 18015916257203385982U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10684090189688871993U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 58U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 40U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16821U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 17798U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18179U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18085U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18647U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 7825479804710770560U;
            aOrbiterC = (aWandererA + RotL64(aCross, 19U)) + 5298124167101358123U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 17774541024369233726U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 35U)) + 7679371833537454082U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aWandererB + RotL64(aIngress, 11U)) + 5385914900748772224U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 53U)) + 3879781930908486531U;
            aOrbiterK = ((((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 659110346638873236U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10749021728538539749U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3631252455767429457U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8552825360915119613U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2271978810960685021U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5963558780692551176U;
            aOrbiterC = RotL64((aOrbiterC * 4772055335210781149U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 974909966119198104U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9296998242911152296U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2613629915877957661U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2245318466901521959U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13391076374843288568U;
            aOrbiterD = RotL64((aOrbiterD * 18094558036982107419U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6184487746594236737U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1563385912137291418U;
            aOrbiterF = RotL64((aOrbiterF * 4805455299959232321U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1744840092006498629U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2100927276837188416U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3541788262067077997U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9998911862807246338U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12239948725635220096U;
            aOrbiterI = RotL64((aOrbiterI * 7098620484129489129U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 28U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterF, 57U)) + aPhaseHWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 36U)) + aOrbiterF) + aNonceWordI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25072U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 26969U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 25522U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22896U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24854U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 36U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 5160910997561396461U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 13U)) + 14920764751058512062U) + aNonceWordD;
            aOrbiterB = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 6080952401749660022U) + aNonceWordL;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 17667234330526298627U) + aNonceWordM;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 37U)) + 760630072638686756U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 19U)) + 3504157162816997476U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 60U)) + 9489022223422585882U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1149898536879968964U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10492284328940025310U;
            aOrbiterB = RotL64((aOrbiterB * 7893416766300156495U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13213275606286399312U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10557118912847180413U;
            aOrbiterK = RotL64((aOrbiterK * 10077877991284587845U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15618980209023994776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5268600749854045564U;
            aOrbiterE = RotL64((aOrbiterE * 3849660559223919613U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8011552687609649990U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3148133096349525066U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5245156554959620007U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12032847944237867285U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14999005703490824673U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 6631584955208646049U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5426735969392906710U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3593177531650386729U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 12997284886192717043U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1701444719333347373U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15928731228196894960U;
            aOrbiterD = RotL64((aOrbiterD * 1919318226904213433U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterF, 5U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 12U)) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + aNonceWordJ) + aPhaseHWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29501U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27988U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 27781U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28434U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30953U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 24U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 15726877954695761686U) + aNonceWordF;
            aOrbiterG = (aWandererI + RotL64(aCross, 13U)) + 14187652171881943587U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 13U)) + 8420423151313882782U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 14942322692433259283U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 43U)) + 7272331475919796255U) + aNonceWordC;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 29U)) + 154504365041805840U) + aPhaseHOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 35U)) + 17475491222554948786U) + aPhaseHOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5759181483165339605U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5993060214499322845U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 10799489831896153301U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10901786237875941844U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17135786595614068473U;
            aOrbiterB = RotL64((aOrbiterB * 15923538730142047043U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5208202073886811165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6821452921018900631U;
            aOrbiterI = RotL64((aOrbiterI * 13119330055184115669U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13348064837402206969U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8967943922403445136U;
            aOrbiterG = RotL64((aOrbiterG * 300168481725373093U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8130283784171430891U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6351113882502502876U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15960622823993072903U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6894708729226455769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12065058511247133944U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 5432601727436935831U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17138279326229372741U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12987698199066890628U;
            aOrbiterA = RotL64((aOrbiterA * 12665716655177320977U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 37U));
            aWandererH = aWandererH + (((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterA, 14U)) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + aNonceWordG);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + aNonceWordB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 51U);
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

void TwistExpander_BaseBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1572U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 1555U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1610U)) & W_KEY1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2514U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 15920462086654025436U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 19U)) + 487844076858004017U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 14502883786442630566U;
            aOrbiterE = (aWandererA + RotL64(aCross, 30U)) + 3787107318658233674U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + 12548777544693755491U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 39U)) + 4907309444075181683U;
            aOrbiterC = (aWandererD + RotL64(aCross, 35U)) + 18342396700266492072U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 13503051997624242670U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 17845742460521374571U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8640887211877858169U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5273913123709097537U;
            aOrbiterG = RotL64((aOrbiterG * 1661149444148461791U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17756844173695563883U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6713055830729302951U;
            aOrbiterA = RotL64((aOrbiterA * 2832836748513174311U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5106468334224035972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10228769728713526172U;
            aOrbiterF = RotL64((aOrbiterF * 9760310686414358435U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7687649520668883142U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7757480627354711605U;
            aOrbiterJ = RotL64((aOrbiterJ * 7222553727737349209U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10876291698508634557U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8149278085586014186U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8577133863470695381U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15592893988925610485U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8639028256640537165U;
            aOrbiterB = RotL64((aOrbiterB * 1880655276432963955U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 475660347892196219U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1903736092401853832U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8486318978769094799U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12463250192809450953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7253918448601703982U;
            aOrbiterC = RotL64((aOrbiterC * 3821034106528009129U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5171661020093804486U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11627344933828324146U;
            aOrbiterE = RotL64((aOrbiterE * 5388047063152043277U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + aPhaseAWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterH, 4U));
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterH, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 48U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5240U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 4506U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4077U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4015U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aCross, 35U)) + 13687218104610230596U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 58U)) + 6841550124960692709U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 17418968668458764131U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 8303537912696948204U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 47U)) + 12376614417285936537U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 14215749063579232654U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 41U)) + 4111736931433665347U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 11250375934571631522U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 28U)) + 5367367837773331275U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15514089192382674434U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1475991716685034960U;
            aOrbiterG = RotL64((aOrbiterG * 17720681295551650891U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5531622777788629748U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8363822215908303335U;
            aOrbiterH = RotL64((aOrbiterH * 17850203366840994883U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3741256932685720414U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11634667238062155772U;
            aOrbiterC = RotL64((aOrbiterC * 15925089729784547403U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 18180546911210417155U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5123234656838556335U;
            aOrbiterD = RotL64((aOrbiterD * 15362857462853398025U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11215734271189250284U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16863747802158398092U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1828035970246160023U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9859050606636646323U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9331300036643654675U;
            aOrbiterA = RotL64((aOrbiterA * 2502263410556166281U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15028845665427209759U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8916444839488901676U;
            aOrbiterE = RotL64((aOrbiterE * 6646561894156038791U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8024631140949068570U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1116378858490660031U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4247798531910227367U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5066486214537899212U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9346312092322423057U;
            aOrbiterB = RotL64((aOrbiterB * 13443190089768875191U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 36U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD + ((RotL64(aCross, 22U) + RotL64(aOrbiterB, 4U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6228U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7261U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5801U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6284U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5987U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 15549114274303128055U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 46U)) + 16466750056388063241U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 12209449840836787142U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 14551496099734294336U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 3U)) + 6266576428679808622U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 52U)) + 16892841575635668152U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 41U)) + 7375966221423362125U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 11926105302821753530U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 23U)) + 16219253791550461124U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7299056065319248160U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15234001484933728439U;
            aOrbiterB = RotL64((aOrbiterB * 8182244796017018911U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6615802589932632120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5481176858895819247U;
            aOrbiterD = RotL64((aOrbiterD * 3604590158551984877U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17220507586542139380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14137921473739415340U;
            aOrbiterK = RotL64((aOrbiterK * 10634645686035907603U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16981960446540932787U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10897565927079518588U;
            aOrbiterJ = RotL64((aOrbiterJ * 418843936329303571U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2746889569299593263U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4894117146736361379U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2656750612042673191U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18294823016957137777U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 86828501068883383U;
            aOrbiterF = RotL64((aOrbiterF * 11432686669235402365U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6322053762209547826U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6754524552483363820U;
            aOrbiterH = RotL64((aOrbiterH * 1746163087826694641U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7306452650619361017U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12717201204443785828U;
            aOrbiterC = RotL64((aOrbiterC * 6121251603905574991U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10422327053543898585U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14786413282036348183U;
            aOrbiterE = RotL64((aOrbiterE * 8713024293107068275U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterG, 44U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH + (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 48U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 57U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10052U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 8862U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(mSource[((aIndex + 9577U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8250U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9224U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10249U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 36U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 35U)) + 14008824488073394623U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 24U)) + 13317978415866411468U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 57U)) + 13209180141897453900U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 11870521586865233578U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 13U)) + 8052156380448047385U) + aPhaseBOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 39U)) + 12158131176743680605U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 19U)) + 14674467487607719347U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 18055496790566231147U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 46U)) + RotL64(aCarry, 35U)) + 3838105585041578784U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2839568255183054418U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11933612922864258179U;
            aOrbiterC = RotL64((aOrbiterC * 7571964469321160347U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6289849094151630580U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2640344350528492271U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16197726750829369365U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16306175266267657791U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3339898380394883600U;
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15017076663742800002U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8973064296077602496U;
            aOrbiterF = RotL64((aOrbiterF * 9309462227233615761U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17580319233338139859U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14063208878807603874U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16601475239075164585U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13326130855721009942U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12843186026737544416U;
            aOrbiterE = RotL64((aOrbiterE * 4975848122837321619U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14102887715772847499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14495942314329085733U;
            aOrbiterA = RotL64((aOrbiterA * 4236795312917583565U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11564857125101669667U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17435970784822000464U;
            aOrbiterB = RotL64((aOrbiterB * 1472691848852381173U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16561390130356833062U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9952805588514363872U;
            aOrbiterJ = RotL64((aOrbiterJ * 3720874990001086597U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 10U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterD, 6U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE + (((RotL64(aCross, 30U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterK, 36U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11406U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[((aIndex + 12622U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12644U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 12549U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13642U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11505U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneA[((aIndex + 11268U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 28U)) + 18255347001097480328U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 11U)) + 13679246790311505735U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 23U)) + 10565839529765027116U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 57U)) + 14327172566224769901U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 16239024612038195174U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 13800012174212131890U;
            aOrbiterE = (aWandererF + RotL64(aCross, 50U)) + 13900288860157577583U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 4144386119777112740U;
            aOrbiterC = (aWandererB + RotL64(aCross, 39U)) + 3154558262670631372U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7456728543137614001U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11709519851158935384U;
            aOrbiterA = RotL64((aOrbiterA * 7016689518570071587U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15607438907832240304U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9276575329661725624U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8879744070762412745U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6459435969129449226U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6442382118416542275U;
            aOrbiterJ = RotL64((aOrbiterJ * 2921027306686588233U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12117432107282150865U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6831279293184793243U;
            aOrbiterB = RotL64((aOrbiterB * 2435360641135249073U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9520022957804572889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8322178689474588679U;
            aOrbiterF = RotL64((aOrbiterF * 1627707191467537115U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4162401591586869316U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8994015844714895961U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10038095909727959633U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17756404450592957616U;
            aOrbiterK = RotL64((aOrbiterK * 14255952184627347295U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3379089265413427719U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11341713098678108441U;
            aOrbiterC = RotL64((aOrbiterC * 2500587373161411961U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4030296130743454165U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6332387792111212064U;
            aOrbiterH = RotL64((aOrbiterH * 16490982218150897861U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterK, 10U));
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterB, 21U)) + aPhaseBWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + ((RotL64(aIngress, 24U) + RotL64(aOrbiterJ, 14U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14059U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15762U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15449U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14305U)) & W_KEY1], 43U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13914U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15529U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15052U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 14U)) + 6243113109470883144U;
            aOrbiterD = (aWandererK + RotL64(aCross, 3U)) + 3891552123999605832U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 8758797898587019128U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 1005891374086408851U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 3713426782180050764U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 41U)) + 18358143862391573534U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 53U)) + 17504394029693712404U;
            aOrbiterF = (aWandererC + RotL64(aCross, 47U)) + 5312729289027417014U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 30U)) + 2560873623431186029U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16309322822806704211U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10195513918020652600U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14569219741824123715U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2552116263258744287U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7732784879810980089U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15041929399477790999U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16499127570665381507U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10890036715535519036U;
            aOrbiterI = RotL64((aOrbiterI * 9065115450010475187U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16288944603478791554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14542766121469312846U;
            aOrbiterK = RotL64((aOrbiterK * 8435383464425875209U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5973595239494084696U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1820492719977197097U;
            aOrbiterF = RotL64((aOrbiterF * 16164917159141304405U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10489529555776381736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6392552206958240484U;
            aOrbiterA = RotL64((aOrbiterA * 11761477994533503307U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10163241948999404556U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16054678853554707148U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10570418210789350091U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3606021702108590330U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16920568417324295852U;
            aOrbiterG = RotL64((aOrbiterG * 5222656554577625385U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13889995689147406315U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7908387312354285092U;
            aOrbiterJ = RotL64((aOrbiterJ * 7995682580514280949U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 42U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 42U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + ((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterD, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18846U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 17373U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 17216U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 18601U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16739U)) & W_KEY1], 50U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17181U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18627U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 41U)) + 8604208734152026945U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 19U)) + 1374329953253889829U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 47U)) + 5779278910548228339U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 58U)) + 17670451230882805140U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 8193848740764866860U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 27U)) + 15801168428145650104U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 2584718176087499066U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 14950366247822737997U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 14U)) + 9779293225265670135U) + aPhaseCOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8688968319288372383U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13665723186950342601U;
            aOrbiterK = RotL64((aOrbiterK * 292035540396910837U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9395428688359973510U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2152719218018108418U;
            aOrbiterH = RotL64((aOrbiterH * 15271961483518392671U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1350324137411377992U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8729317951386057921U;
            aOrbiterA = RotL64((aOrbiterA * 6008790836417785083U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6317310451893678411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10175620379041384281U;
            aOrbiterC = RotL64((aOrbiterC * 14079679617394330781U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1203082119358827708U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 523869107818193101U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4629501113595689157U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4028324959540432983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15447631947468213912U;
            aOrbiterI = RotL64((aOrbiterI * 6037306615787729185U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14225888694733041031U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11925000696281947629U;
            aOrbiterJ = RotL64((aOrbiterJ * 4337022940520411253U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15015531024930608745U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16752579225076943550U;
            aOrbiterD = RotL64((aOrbiterD * 15551083683579981439U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2432733494869267901U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10103430321388601485U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18372919379972432569U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterC, 40U));
            aWandererK = aWandererK + (((RotL64(aCross, 34U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 36U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19165U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 19611U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20547U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21238U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20954U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21399U)) & W_KEY1], 39U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21355U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 21003U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 10U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 47U)) + 10881271196314989997U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 6406461249988567558U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 10U)) + 17255067918280095959U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 43U)) + 16690850682497718411U;
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 5576201059361086866U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 11991259685693687554U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 56U)) + 14652535244217836909U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 1701789037170782122U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 3U)) + 953429054903473833U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12064513610469714211U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7993881398822002424U;
            aOrbiterG = RotL64((aOrbiterG * 11572884842788918377U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14421313768013320050U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11112386845630998889U;
            aOrbiterB = RotL64((aOrbiterB * 11771526352030371669U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17069630896535699015U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3308240081138623373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10449509484417835159U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17615529807112933619U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11782807146851563541U;
            aOrbiterF = RotL64((aOrbiterF * 12992075832343669221U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14401645829607611983U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6736397344219993532U;
            aOrbiterC = RotL64((aOrbiterC * 1667287547938175641U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6446974060524700550U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7840991992443308254U;
            aOrbiterH = RotL64((aOrbiterH * 6891023544882740107U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10362169906019794305U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4503700997923168911U;
            aOrbiterE = RotL64((aOrbiterE * 15066164494038852559U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13492041134973259041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14337899277551397976U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5966740718899290915U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13693100781608180748U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16177545026405910052U;
            aOrbiterK = RotL64((aOrbiterK * 6019231448444020563U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterE, 39U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 18U));
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterK, 30U)) + aPhaseCWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 6U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22322U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 21856U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23742U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((aIndex + 21908U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22337U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22509U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24356U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneB[((aIndex + 24398U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aScatter, 11U)) + 7270044678408187242U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 48U)) + 10192278965379756766U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 17568666746676060748U) + aPhaseCOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 29U)) + 14312927531124963037U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 9825825726152087706U) + aPhaseCOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 39U)) + 9696778570255265896U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 19U)) + 17657841352013417228U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 52U)) + 16207815085909628439U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 1752979206374514227U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10456310689643905854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16127830548663742550U;
            aOrbiterF = RotL64((aOrbiterF * 4355938404839045417U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2940917376003930842U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7353596864777649953U;
            aOrbiterE = RotL64((aOrbiterE * 7499468723171042005U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12725092740446150705U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5791296650856037010U;
            aOrbiterK = RotL64((aOrbiterK * 760379251950502133U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1200130368046206150U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16689604428598558547U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13815324235939996623U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14359561591103730856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3975025843599045263U;
            aOrbiterI = RotL64((aOrbiterI * 5025047888533298617U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14017901732955607601U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10431526786489555196U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10181915874476132407U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7320527073559849223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15333411223710709907U;
            aOrbiterG = RotL64((aOrbiterG * 3488684905528068775U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14302474063321663801U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2104154521019935187U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12944382959742278055U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5167600586916325228U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4566823109447208716U;
            aOrbiterA = RotL64((aOrbiterA * 9997799807454267443U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 54U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterI, 44U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 10U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25720U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 26785U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26408U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 25175U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27108U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25482U)) & S_BLOCK1], 26U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24690U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((aIndex + 26323U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 51U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 11450949896247900941U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 24U)) + 3905542253538116335U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 9529740545977785305U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 37U)) + 1856876631533143492U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 41U)) + 84253466320181686U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 5U)) + 12577480918745432444U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 51U)) + 5625703170397704029U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 694608607323629282U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 29U)) + 3993981243536262204U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4119215953484892051U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8785040118556157146U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17113521266125471625U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16234403619456882890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10398727475672860610U;
            aOrbiterJ = RotL64((aOrbiterJ * 5086871400049644715U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18327987141759096769U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2645964788056875452U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8778681366114628045U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2859452497983106129U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7196557924940881076U;
            aOrbiterK = RotL64((aOrbiterK * 14415389907490256711U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 930127943984174668U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15673596916054795749U;
            aOrbiterC = RotL64((aOrbiterC * 7505660488733199479U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16673140529110941163U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2258448294877833760U;
            aOrbiterE = RotL64((aOrbiterE * 1821550319748977445U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6870209259643931219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12749790107942194104U;
            aOrbiterF = RotL64((aOrbiterF * 4871407285968611725U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17131374134617173866U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6426448390733751612U;
            aOrbiterD = RotL64((aOrbiterD * 12490559588384058417U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15592826434339731146U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14182944418026376183U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7218860482893476233U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 24U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 28U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterB, 37U));
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 23U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 56U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29101U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneD[((aIndex + 27587U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29580U)) & W_KEY1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 30008U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27624U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28937U)) & S_BLOCK1], 48U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28097U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 28274U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 18U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 3917730204724097072U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 19U)) + 1874642340716212824U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 14U)) + 6900165757434854160U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 12750946097023807161U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 43U)) + 6563216048479513594U;
            aOrbiterH = (aWandererB + RotL64(aCross, 5U)) + 14960240191349450795U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 28U)) + 16306180275951788289U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 6502066618271045547U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 37U)) + 6219852857850888738U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2272931312452845850U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3028929882263199463U;
            aOrbiterD = RotL64((aOrbiterD * 11005324285856805069U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6067393030073568112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10094809900437037258U;
            aOrbiterF = RotL64((aOrbiterF * 18095564940730322769U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5962414178157074575U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15755563045799129417U;
            aOrbiterC = RotL64((aOrbiterC * 3692603590609922031U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6321455513889880590U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1197435601998121700U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17693996266260557625U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12496949381666299968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8423760160877540210U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8090246492554850768U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2949407491181921633U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11436635942985063755U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17086363141014359856U;
            aOrbiterA = RotL64((aOrbiterA * 10504127577318206801U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10734017887545474935U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 375515325165740779U;
            aOrbiterB = RotL64((aOrbiterB * 9980486695448151709U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5217148491945389821U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14696058217023530058U;
            aOrbiterG = RotL64((aOrbiterG * 11026674782236654799U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterK, 36U));
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 41U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 50U));
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32527U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadA[((aIndex + 31929U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31035U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30188U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31592U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 31143U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 18U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 23U)) + 17936518874386450467U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 48U)) + 13722737841589910344U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 39U)) + 11774969167948715796U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 53U)) + 3640101505680493777U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 1369495382725650822U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 12U)) + 11827310354654653345U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 186037671377175394U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 11428829344234627340U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 2275016369870029068U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15471646673734798328U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12172082573115640145U;
            aOrbiterF = RotL64((aOrbiterF * 9629417882787847753U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6626736341348283154U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12220614992483863623U;
            aOrbiterK = RotL64((aOrbiterK * 8137086205714097487U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13157102324253760215U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4143587482368093601U;
            aOrbiterJ = RotL64((aOrbiterJ * 5060677690991506895U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11007575246013796426U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11721585930088637162U;
            aOrbiterD = RotL64((aOrbiterD * 15009627907125738519U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5720789204450196217U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3094696226821431648U;
            aOrbiterA = RotL64((aOrbiterA * 4412033981712165541U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14675830108100986773U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9444071495289719645U;
            aOrbiterB = RotL64((aOrbiterB * 10983136361953366557U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5106753847015199956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7585421898593510010U;
            aOrbiterE = RotL64((aOrbiterE * 140996914192351011U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11746948407655524690U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16336323220286344483U;
            aOrbiterC = RotL64((aOrbiterC * 6590417628835864497U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8030445186765781136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 276034088015165891U;
            aOrbiterI = RotL64((aOrbiterI * 7626025612710225099U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 42U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 38U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 38U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 34U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BaseBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 626U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 1843U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 1733U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4992U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 4577U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 11U)) + 15920462086654025436U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 487844076858004017U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 14502883786442630566U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 3787107318658233674U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 44U)) + 12548777544693755491U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 27U)) + 4907309444075181683U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 35U)) + 18342396700266492072U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13503051997624242670U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17845742460521374571U;
            aOrbiterC = RotL64((aOrbiterC * 1366356786138085155U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8640887211877858169U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5273913123709097537U;
            aOrbiterJ = RotL64((aOrbiterJ * 1661149444148461791U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17756844173695563883U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6713055830729302951U;
            aOrbiterE = RotL64((aOrbiterE * 2832836748513174311U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5106468334224035972U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10228769728713526172U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9760310686414358435U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7687649520668883142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7757480627354711605U;
            aOrbiterA = RotL64((aOrbiterA * 7222553727737349209U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10876291698508634557U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8149278085586014186U;
            aOrbiterK = RotL64((aOrbiterK * 8577133863470695381U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15592893988925610485U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8639028256640537165U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterF, 13U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 60U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + aPhaseEWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8895U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 9307U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 6951U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5958U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7432U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 16462052553719977502U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 11U)) + 12337064059566619581U;
            aOrbiterE = (aWandererK + RotL64(aCross, 19U)) + 15801005007094515447U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 53U)) + 8228706742665081656U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 29U)) + 11006723027845190869U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 18173765337829177450U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 19U)) + 530215083653542558U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6608611827035564511U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2246051826221626809U;
            aOrbiterE = RotL64((aOrbiterE * 6333352641495253539U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5228575308895381421U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10999213210689606857U;
            aOrbiterD = RotL64((aOrbiterD * 5467601259546342925U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3773371037240485696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8887985779436152504U;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11150566414723818350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8336366151003049546U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13233968794237090787U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8172558473508478819U;
            aOrbiterK = RotL64((aOrbiterK * 17837070423649268435U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 133564480283347997U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15104810248883567064U;
            aOrbiterA = RotL64((aOrbiterA * 706802420642303533U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9138629520201127075U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13993086066341664080U;
            aOrbiterB = RotL64((aOrbiterB * 4875046427147105077U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 46U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererI = aWandererI + (((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15870U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 12585U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14307U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11786U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15076U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12835U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 16124889768301047791U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 54U)) + 11912338587186717280U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 8594012868813114354U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 47U)) + 18281043566156682815U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 11U)) + 16853106130200942302U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 19U)) + 2611212958619673086U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 18039472325066855180U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14495785571345122046U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4556063793412832418U;
            aOrbiterF = RotL64((aOrbiterF * 13166927543135467627U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14896419970271244358U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 880028529183500036U;
            aOrbiterA = RotL64((aOrbiterA * 14228281807461251361U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2379557167489415783U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11854373946064529806U;
            aOrbiterK = RotL64((aOrbiterK * 150755294320438887U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1487252775956449964U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12777924204511625545U;
            aOrbiterE = RotL64((aOrbiterE * 1366019527386994789U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15998631485222477969U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8864212892296191613U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 579242788050369815U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17069347835763226743U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7443008171694679791U;
            aOrbiterI = RotL64((aOrbiterI * 748894368884566607U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17334256152350782002U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8986626119086556393U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2258172145924120235U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 34U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17673U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 21092U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19386U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18311U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17654U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17414U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aScatter, 37U)) + 11450949896247900941U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 3905542253538116335U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 26U)) + RotL64(aCarry, 3U)) + 9529740545977785305U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 1856876631533143492U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 5U)) + 84253466320181686U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 19U)) + 12577480918745432444U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 13U)) + 5625703170397704029U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 694608607323629282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3993981243536262204U;
            aOrbiterH = RotL64((aOrbiterH * 2502835860198146381U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4119215953484892051U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8785040118556157146U;
            aOrbiterB = RotL64((aOrbiterB * 17113521266125471625U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16234403619456882890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10398727475672860610U;
            aOrbiterD = RotL64((aOrbiterD * 5086871400049644715U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 18327987141759096769U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2645964788056875452U;
            aOrbiterE = RotL64((aOrbiterE * 8778681366114628045U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2859452497983106129U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7196557924940881076U;
            aOrbiterC = RotL64((aOrbiterC * 14415389907490256711U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 930127943984174668U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15673596916054795749U;
            aOrbiterI = RotL64((aOrbiterI * 7505660488733199479U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16673140529110941163U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2258448294877833760U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1821550319748977445U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 12U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27138U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 27268U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22630U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24971U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22362U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 22811U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 11410829607777684449U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 39U)) + 7502698839700975347U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 13267685058252106173U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 47U)) + 238242706996630625U;
            aOrbiterF = (aWandererH + RotL64(aCross, 11U)) + 8184695499511454281U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 41U)) + 12767823220461985403U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 53U)) + 12293198423143850330U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11149495229952495939U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7556992689338382800U;
            aOrbiterJ = RotL64((aOrbiterJ * 18232398462716803063U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3431338808774134649U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16863099140844995099U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 752376661101787919U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17872458049880677604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16760153457252546974U;
            aOrbiterB = RotL64((aOrbiterB * 11225037229069712805U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3115544493537438408U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4359882942759752958U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 561477566995575801U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13387113067202396536U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12955690074544490161U;
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15614054443728226807U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1939441328066616114U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4484917074808974359U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4599016263007782537U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9962305629016158048U;
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 20U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30775U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 29417U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28820U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28038U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27496U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31418U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 39U)) + 6916817163240024692U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 47U)) + 14554930751292077817U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 1098305064484336101U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 54U)) + RotL64(aCarry, 35U)) + 12192821172420471527U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 11U)) + 2435134991707318845U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 21U)) + 1896745368738512624U) + aPhaseEOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 1114996424222923873U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9839135798371512656U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8037967239603177043U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7848951103759663025U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15185468738487237432U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4912098316394854543U;
            aOrbiterK = RotL64((aOrbiterK * 3072785550384399929U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13142688607850380888U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4507379759608945839U;
            aOrbiterF = RotL64((aOrbiterF * 2989332387754215967U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7299006009652289342U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5390655277207053627U;
            aOrbiterE = RotL64((aOrbiterE * 10973744708856143715U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6744737023577785725U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15539737698867067285U;
            aOrbiterD = RotL64((aOrbiterD * 4686092035261336911U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13329866734681377952U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13284937458969166257U;
            aOrbiterB = RotL64((aOrbiterB * 3965985432462699445U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8695002088915702168U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3858059421620839286U;
            aOrbiterI = RotL64((aOrbiterI * 9559783727301092937U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 56U) + RotL64(aOrbiterF, 42U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_BaseBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneA, aExpandLaneA, aExpandLaneC, aSnowLaneB, aInvestLaneA, aWorkLaneA, aExpandLaneD, aWorkLaneB, aInvestLaneC, aWorkLaneC, aExpandLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4439U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 931U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1550U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1894U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4253U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 4918U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 50U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 1210605127156905516U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 11964595428173569519U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 53U)) + 16277319029916258482U;
            aOrbiterF = (aWandererF + RotL64(aCross, 56U)) + 12369497463101824572U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 29U)) + 6201248574067068202U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 11U)) + 1727477025667206661U) + aPhaseFOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 35U)) + 1404510627789806851U;
            aOrbiterK = (aWandererK + RotL64(aCross, 19U)) + 6948213591282018925U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 48U)) + 6688865181284421478U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 3351130769402360855U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 21U)) + 12681032488906270823U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3591412591193726763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16153817571210878589U;
            aOrbiterG = RotL64((aOrbiterG * 4165137036092246349U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3808228354421006630U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1427373776207504205U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4534374093769595531U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1831554180932501132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1114853085120949215U;
            aOrbiterK = RotL64((aOrbiterK * 4264176108298812905U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2080935638828366835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16104777999646489828U;
            aOrbiterF = RotL64((aOrbiterF * 15205199362011777473U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9782806013673440791U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3721620299829386454U;
            aOrbiterA = RotL64((aOrbiterA * 6286765834910272409U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4013706412064296527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5751022780695158579U;
            aOrbiterC = RotL64((aOrbiterC * 13766736471646116397U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17684546333240329338U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1106947111128020920U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3158839453318658951U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11564229705849500598U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1585817314460274286U;
            aOrbiterB = RotL64((aOrbiterB * 12687162159791577431U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13549147977354138518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5148731385622182707U;
            aOrbiterH = RotL64((aOrbiterH * 11016443961557395981U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17048442399822433365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13772472534194030098U;
            aOrbiterJ = RotL64((aOrbiterJ * 13155895389652826889U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9982971300679888388U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1210605127156905516U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9183351854400012949U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 40U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 18U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 30U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10217U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 5895U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7548U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5863U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8627U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7502U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 8442U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 58U)) + 4179952823252098240U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 3745613452332101749U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aIngress, 27U)) + 2955689793395307176U;
            aOrbiterK = (aWandererK + RotL64(aCross, 41U)) + 5639060180251322019U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 7901969163853586463U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 2242166787816318119U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 37U)) + 5239936443960750064U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 13939136954732185558U;
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 17058884136712717463U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 60U)) + 18148618660054585941U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 43U)) + 7022023484530327814U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7722084537340095637U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11764151879690934182U;
            aOrbiterF = RotL64((aOrbiterF * 12264384877711365655U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16412785901758144708U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9666718667728274824U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10865799822751771795U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4307127540152109364U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2457646804702647606U;
            aOrbiterG = RotL64((aOrbiterG * 6340030928007058595U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3179394870088602208U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 504977947273774249U;
            aOrbiterB = RotL64((aOrbiterB * 16190282058883481551U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16182729401018310837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7110817020445860609U;
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12960656706837391973U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7103806893724395904U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14365984439655979791U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1248300178080633527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7195473175424961337U;
            aOrbiterC = RotL64((aOrbiterC * 4633558992739305045U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13007951568242991449U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10296811247653636372U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16469682651380549395U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13922797949001028335U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16773545425463040155U;
            aOrbiterI = RotL64((aOrbiterI * 10639282630227832397U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2888887140296117803U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10279517418046269817U;
            aOrbiterE = RotL64((aOrbiterE * 8600355360339461535U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17303373436784809093U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4179952823252098240U;
            aOrbiterK = RotL64((aOrbiterK * 3675754609699406437U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 34U)) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 38U) + RotL64(aOrbiterH, 26U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16358U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 12961U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 15478U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15422U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 13694U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 38U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 35U)) + 1364174714924216027U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 13561796874229506613U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 13U)) + 11845572344206238305U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 21U)) + 15762708240326773763U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 1157119665207900473U;
            aOrbiterK = (aWandererD + RotL64(aCross, 4U)) + 6823546624372055260U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 39U)) + 14465564210523945121U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 10667464548080807531U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 37U)) + 13445737493224316575U;
            aOrbiterH = (aWandererH + RotL64(aCross, 58U)) + 3009837893785957665U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 19U)) + 2886920524111083752U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10886177449328249656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15067759884678100433U;
            aOrbiterG = RotL64((aOrbiterG * 5724566815989860041U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18307930462682331536U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8791864377579255801U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9265158882471421767U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 805797468642992351U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5743305867058244964U;
            aOrbiterF = RotL64((aOrbiterF * 16263000753351131717U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17102025528234481273U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1841579177327486899U;
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2189493507896508972U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18209567010094914374U;
            aOrbiterH = RotL64((aOrbiterH * 3737080408976852351U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6697069234216868330U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 927471474577415372U;
            aOrbiterB = RotL64((aOrbiterB * 10680760991009199309U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13155854301197725408U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1014625081915435892U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11592754232949990435U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12697209921410914931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11555096613655648647U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4598821388864997089U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9335308231651271690U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3160859883353473444U;
            aOrbiterA = RotL64((aOrbiterA * 4753600703924906409U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15681189182414315768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3147692210581710663U;
            aOrbiterI = RotL64((aOrbiterI * 6271949093080510861U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5373388632562432117U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1364174714924216027U;
            aOrbiterJ = RotL64((aOrbiterJ * 4694926665965807945U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 26U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterA, 60U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 29U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterE, 42U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16944U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneA[((aIndex + 21600U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21138U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18739U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 21384U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 27U)) + 6771552164800695068U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 12131763371571322040U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 54U)) + 3326182381395522013U;
            aOrbiterI = (aWandererB + RotL64(aCross, 29U)) + 12288775097697156383U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 51U)) + 5195948373449796741U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 21U)) + 14404044002250137144U;
            aOrbiterE = (aWandererF + RotL64(aCross, 44U)) + 11142382920035825426U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 47U)) + 2967149520256475485U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 35U)) + 1470907369577818097U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 9231668148004163910U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 13078929163913892386U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9485274692075657877U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12216951187543631673U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6571066246507310805U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6933334652581744234U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17260276102423580920U;
            aOrbiterK = RotL64((aOrbiterK * 7796879893790990605U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 387767848169714392U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8597538259308082638U;
            aOrbiterE = RotL64((aOrbiterE * 4888054690557707241U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7996708724489146033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15357384191688149939U;
            aOrbiterC = RotL64((aOrbiterC * 9827691726832491373U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17739222908739454637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1614322333281471170U;
            aOrbiterA = RotL64((aOrbiterA * 7063116837752240891U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4531604274893197209U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3453280714992341288U;
            aOrbiterJ = RotL64((aOrbiterJ * 8390029711127907805U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 116623650872661533U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6565636510115095988U;
            aOrbiterH = RotL64((aOrbiterH * 9691897067492501177U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10303258439817808058U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10917642773040237611U;
            aOrbiterF = RotL64((aOrbiterF * 10232856828372963363U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2087058228468680821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3691125545393861889U;
            aOrbiterG = RotL64((aOrbiterG * 1768745056298937903U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9240209357066002219U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7645250700232422804U;
            aOrbiterI = RotL64((aOrbiterI * 6762116797395687607U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9859862257084218280U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6771552164800695068U;
            aOrbiterD = RotL64((aOrbiterD * 11063630807191661109U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 26U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterF, 18U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 46U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 51U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23037U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 22083U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 26425U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26558U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneA[((aIndex + 25644U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 54U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 51U)) + 5510690816044082200U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 13U)) + 15967820875033940530U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 19U)) + 539348720848176221U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 29U)) + 15779318183635560817U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 34U)) + 14511058534424187469U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 57U)) + 5811130556873428391U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 1085928476499444025U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 51U)) + 6973335316600768130U;
            aOrbiterA = (aWandererK + RotL64(aCross, 39U)) + 10747243745475009744U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 47U)) + 1072260008981349754U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 2018772405352495753U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1092091597048996547U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15103140149542167197U;
            aOrbiterK = RotL64((aOrbiterK * 621856991658027989U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13194619321108681542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16749188603268621850U;
            aOrbiterD = RotL64((aOrbiterD * 9575408950550922039U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7427959503086895166U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9895804051379551393U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2701997336201570715U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4526020800679774259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4484850928870048176U;
            aOrbiterC = RotL64((aOrbiterC * 17556987520625677313U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1837404844299040155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15213208978489570694U;
            aOrbiterJ = RotL64((aOrbiterJ * 7062740584650274133U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9615231781751396800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15872192167825648096U;
            aOrbiterI = RotL64((aOrbiterI * 2900526493682580729U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12530672039655918903U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10617836782870315804U;
            aOrbiterG = RotL64((aOrbiterG * 9716778004909794973U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 550750725406860977U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3498554352021622907U;
            aOrbiterF = RotL64((aOrbiterF * 9846933294851238495U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4059346317776216057U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14161853870874499023U;
            aOrbiterA = RotL64((aOrbiterA * 8601560894939097781U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4088411647683253905U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9321241420172776158U;
            aOrbiterH = RotL64((aOrbiterH * 4167888281125330225U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8527337525861632945U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5510690816044082200U;
            aOrbiterB = RotL64((aOrbiterB * 12464836001483233379U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 50U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterK, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterG, 46U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28485U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 30989U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29325U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31933U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31628U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 19U)) + 12775735908960052604U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 44U)) + 11791373812080296887U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 23U)) + 5537362877706057303U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 39U)) + 2023912048504189380U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 17668828109963766893U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 51U)) + 558908629933941224U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 53U)) + 1479633119685446888U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 26U)) + 15460320397843364063U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 3U)) + 10059749397555469054U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 9987633811929693924U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 10087337844580228269U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4446204415503364254U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15106063243302192717U;
            aOrbiterI = RotL64((aOrbiterI * 13273756657334709803U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9430197906134676162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10611580584157624739U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3137391249289641509U;
            aOrbiterD = RotL64((aOrbiterD * 5462682413239873181U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9327201928815412810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10675114832750356941U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8804440385852327267U;
            aOrbiterA = RotL64((aOrbiterA * 8520671775587260601U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12871947817782057116U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11015991745792051390U;
            aOrbiterE = RotL64((aOrbiterE * 17152451500505815031U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6320437975845673731U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 702457937087191287U;
            aOrbiterH = RotL64((aOrbiterH * 17491257114676739589U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16629064896250312921U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6054107387816339103U;
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13274874838094190290U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12211422735294360321U;
            aOrbiterK = RotL64((aOrbiterK * 5113738196151089817U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15338616110718583619U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1475787183754511373U;
            aOrbiterC = RotL64((aOrbiterC * 10904607643785840003U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15486810401396777742U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12775735908960052604U;
            aOrbiterF = RotL64((aOrbiterF * 7478156942468930207U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 38U) + RotL64(aOrbiterB, 34U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 37U));
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 22U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_BaseBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3288U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 6740U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 664U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7706U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1841U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 3734U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 58U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererG + RotL64(aIngress, 24U)) + RotL64(aCarry, 57U)) + 6381335981879993247U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 11U)) + 15595429101600023172U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 5449234297249826461U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 43U)) + 11213734849329731168U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 16438473952464514248U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7357872882115186976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 394402075160738643U;
            aOrbiterF = RotL64((aOrbiterF * 11961225338735982661U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11112941985410283532U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14955125011182736212U;
            aOrbiterH = RotL64((aOrbiterH * 10711684773326395603U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14770727009821304070U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11286366598129204910U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15884310771003021989U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7358400908565425780U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15635109923749114761U;
            aOrbiterI = RotL64((aOrbiterI * 12415152149408700329U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13826842523738623579U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1072811298828325231U;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterJ, 56U)) + aPhaseGWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16344U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 15750U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 8770U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11923U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11254U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12502U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 12027839670755583592U) + aPhaseGOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 15380130703509859843U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 44U)) + RotL64(aCarry, 23U)) + 4590907433867798074U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + 1754574023602519724U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 9832756659564903767U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5035088494491470403U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14199170923323644638U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4518257134117207121U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8325619421264440438U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 969534320779067977U;
            aOrbiterE = RotL64((aOrbiterE * 17767548306355264705U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 270575869402913847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13344806516599578910U;
            aOrbiterK = RotL64((aOrbiterK * 10193544126281901579U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15143147951139409101U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14425582489214169238U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16893787086337916355U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13951127523239064584U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14177925225918293579U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13079514031864998485U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 26U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 10U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20730U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 16778U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 21514U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19296U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20249U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22453U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 6521330037475130256U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 47U)) + 12611880456055428940U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 13U)) + 12061611078130934708U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 1558112410801116984U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 37U)) + 10509115227850160786U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4045915960688792066U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1196541286513243082U;
            aOrbiterJ = RotL64((aOrbiterJ * 5454309408259753479U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15564991032722373702U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4897765238703641798U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9693901276712946763U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12327429514907752733U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6189189797708711636U;
            aOrbiterE = RotL64((aOrbiterE * 9017615866338877651U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6374267075282018852U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1888758503831341439U;
            aOrbiterK = RotL64((aOrbiterK * 74387714918264257U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14956857689299491800U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14879361107223331957U;
            aOrbiterC = RotL64((aOrbiterC * 9166712966729591953U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 24U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 44U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29444U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 28027U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25342U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29756U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26450U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31410U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 17074147006464019918U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 10559516626129419928U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 60U)) + 13280363679503946221U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 17657115422132457413U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 27U)) + 13325837013304973008U) + aPhaseGOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3059707750486106037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4529045702503050852U;
            aOrbiterJ = RotL64((aOrbiterJ * 12889277842182219673U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10726578475550904292U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14832537837996659885U;
            aOrbiterE = RotL64((aOrbiterE * 808060368961520519U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 220094417441809246U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15343130035105342194U;
            aOrbiterA = RotL64((aOrbiterA * 7984652435043810845U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16592263353426409884U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15649290906447931918U;
            aOrbiterH = RotL64((aOrbiterH * 8405875177836650731U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11437410545843708269U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5859769136073011444U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1065016088086441107U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH + ((((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 10U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
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

void TwistExpander_BaseBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5862U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 188U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 1032U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 200U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7728U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 192U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 47U)) + 1042610313571524121U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 3505725321008825582U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 26U)) + RotL64(aCarry, 39U)) + 12584654563843782991U) + aPhaseHOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 6645399144515770935U;
            aOrbiterK = (aWandererI + RotL64(aCross, 39U)) + 3608978423753715584U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8089198857670370983U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15207251813516399879U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7596841660069752069U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9579268660105824516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16055044469473802812U;
            aOrbiterB = RotL64((aOrbiterB * 2269649280637188723U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 583811872609805949U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7027491967970873942U;
            aOrbiterF = RotL64((aOrbiterF * 12686754713465826139U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 18256061823189677508U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12708429127816136937U;
            aOrbiterE = RotL64((aOrbiterE * 12593886633108075321U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12169216645156306078U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12694325407567795065U;
            aOrbiterK = RotL64((aOrbiterK * 3711789483877261899U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 20U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterB, 56U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13825U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 9338U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13148U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10128U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13737U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11388U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 9914837590440975587U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 54U)) + RotL64(aCarry, 51U)) + 6706125076401958051U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 16570817772679258409U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 6843705658115186948U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 3U)) + 16099930446791572351U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5420550009556030459U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5729549069420177477U;
            aOrbiterB = RotL64((aOrbiterB * 7842192631021712569U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15590601126188675834U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13044027390998620029U;
            aOrbiterG = RotL64((aOrbiterG * 16845199115313444123U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11068338135659636772U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6584988841809544332U;
            aOrbiterD = RotL64((aOrbiterD * 1683336180438945439U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8516813219883915404U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10647314042912492785U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15559481057047148785U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 201691689889605304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15512161798401184003U;
            aOrbiterF = RotL64((aOrbiterF * 11473219183982564709U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 48U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20776U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 19478U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 24508U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21550U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23539U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21485U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 3U)) + 15904465836916519864U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 17725629806317789307U) + aPhaseHOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 13794170125914914828U) + aPhaseHOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 2149055907476874332U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 12U)) + 5342047776745074649U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8268148484060546838U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10821151364028563719U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13626634259250509711U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4294213820894407378U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10884726101307943090U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1116128870387229159U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16432210042202444824U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15196602644336228055U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12680438355124070237U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14117787670220328165U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 219833877949480215U;
            aOrbiterB = RotL64((aOrbiterB * 10736293047771972173U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3326396981881473962U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14918513066311426279U;
            aOrbiterK = RotL64((aOrbiterK * 14269763278564574663U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 4U)) + aOrbiterG) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27447U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 26607U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25434U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28215U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27690U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32566U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 17668251151213543491U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 41U)) + 16101602509895104517U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 35U)) + 9083915270773304935U) + aPhaseHOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 12810720730318214811U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 18113428002071925621U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1582208899354109878U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4180688104819188154U;
            aOrbiterF = RotL64((aOrbiterF * 3391785441902730815U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8954598189262820611U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15360094153175355879U;
            aOrbiterC = RotL64((aOrbiterC * 8177798855402983685U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8383954114668216260U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15626783326234049197U;
            aOrbiterG = RotL64((aOrbiterG * 15058420415480073793U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10609978564404958066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17656516608997517984U;
            aOrbiterK = RotL64((aOrbiterK * 4590620354119899777U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 760077259110786536U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3597338735888033063U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6548831472863517621U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 56U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
