#include "TwistExpander_Badminton_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Badminton_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
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
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEDD617B019DA6135ULL + 0x8019C6DF47F9D34AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB890D0FFCE0E5EC7ULL + 0xA9EF58A9F2D8984CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD49D958F05234323ULL + 0xE8A7FA76A773C6A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8223A19B805ED5A7ULL + 0xB1E9FB26020CBB29ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8E1B4216C9639791ULL + 0x9F514A09537B3F2DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x86142DED30A9BA5DULL + 0x8FDE823541B89CE9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x82263C70AA0D375BULL + 0xA4047FF8170370B1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9A09504F42BD74AFULL + 0xF3F659B83242040EULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    [[maybe_unused]] std::uint8_t *mSnow = pSnow;
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
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, mSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 26U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5390U)) & S_BLOCK1], 47U) ^ RotL64(mSnow[((aIndex + 4754U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 34U) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 272U)) & S_BLOCK1], 13U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2428U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 51U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 47U)) + 15813325389431304548U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 53U)) + 2223874171125403602U) + RotL64(aNonceWordB, 30U);
            aOrbiterA = (aWandererK + RotL64(aCross, 58U)) + 5510483568496824130U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 23U)) + 15474152493495661876U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 16846339705130829195U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 41U)) + 1289670576865739669U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 27U)) + 18017354919647006944U) + RotL64(aNonceWordD, 39U);
            aOrbiterI = (aWandererD + RotL64(aScatter, 39U)) + 8539685539928984921U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 14U)) + 3333721400836704048U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 2261560416623815491U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 4377786131746816567U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18047393176583722719U) + RotL64(aNonceWordG, 41U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8184724021940434631U;
            aOrbiterA = RotL64((aOrbiterA * 9800116157750921119U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10469895939183324807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14543391765109879223U;
            aOrbiterJ = RotL64((aOrbiterJ * 4817987697437667225U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5757225781746158178U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3539000495894022869U;
            aOrbiterH = RotL64((aOrbiterH * 1032298408884695925U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11288971092707065923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2761384065186568294U;
            aOrbiterD = RotL64((aOrbiterD * 3323838837427471051U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7120580145300417101U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6977246291769372866U;
            aOrbiterK = RotL64((aOrbiterK * 15170353875184253779U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17625434527765525937U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3299714663631376190U;
            aOrbiterF = RotL64((aOrbiterF * 6532628892760776767U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10331889953489885250U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8550932256881727932U;
            aOrbiterE = RotL64((aOrbiterE * 13085531621192583719U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11151195711186126257U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2552002192824926483U;
            aOrbiterG = RotL64((aOrbiterG * 9754056316698523849U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8038115194286715268U) + RotL64(aNonceWordC, 7U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16594489591573505305U;
            aOrbiterB = RotL64((aOrbiterB * 1241387574663818247U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13476964484361081681U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2136330439951908303U;
            aOrbiterI = RotL64((aOrbiterI * 12728359054660550527U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 231990686776499700U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15813325389431304548U;
            aOrbiterC = RotL64((aOrbiterC * 9155088985405261637U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 34U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 53U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterD, 39U)) + RotL64(aNonceWordA, 49U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 48U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 22U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordF, 55U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: mSource, mSnow, aWorkLaneA
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7514U)) & S_BLOCK1], 44U) ^ RotL64(mSnow[((aIndex + 6879U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 54U) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8256U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 5745U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 1042610313571524121U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 40U)) + 3505725321008825582U) + RotL64(aNonceWordE, 45U);
            aOrbiterC = (aWandererK + RotL64(aScatter, 53U)) + 12584654563843782991U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + 6645399144515770935U) + RotL64(aNonceWordH, 43U);
            aOrbiterK = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 3608978423753715584U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 37U)) + 8089198857670370983U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 47U)) + 15207251813516399879U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 9579268660105824516U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 29U)) + 16055044469473802812U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 44U)) + 583811872609805949U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 3U)) + 7027491967970873942U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18256061823189677508U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12708429127816136937U;
            aOrbiterC = RotL64((aOrbiterC * 12593886633108075321U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12169216645156306078U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12694325407567795065U;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16109994660203297503U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4234704064165718913U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 730085881474787681U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14119541943554602878U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8777769004811352951U;
            aOrbiterE = RotL64((aOrbiterE * 2556957257736134223U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15642663488392549609U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11594468530833278624U;
            aOrbiterD = RotL64((aOrbiterD * 6639306656361601143U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7365350535791499871U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5965170981970155956U;
            aOrbiterH = RotL64((aOrbiterH * 1898702752753066851U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9115232101451815522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9433983580038990072U;
            aOrbiterJ = RotL64((aOrbiterJ * 1951249217843992179U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8810565477444156140U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12081286530401844859U) ^ RotL64(aNonceWordG, 14U);
            aOrbiterB = RotL64((aOrbiterB * 1991383259486140229U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7498045374283306625U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13095973566401200720U;
            aOrbiterA = RotL64((aOrbiterA * 2657451581036351987U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18205793828042507364U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3339020890428651569U;
            aOrbiterG = RotL64((aOrbiterG * 10195916881103252701U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16957913958369950483U) + RotL64(aNonceWordD, 61U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1042610313571524121U;
            aOrbiterI = RotL64((aOrbiterI * 11206619213970727629U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 30U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterG, 60U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordA, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + RotL64(aNonceWordB, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 14634U)) & S_BLOCK1], 46U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 13050U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12060U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 13358U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 54U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + 12583180859826261500U) + RotL64(aNonceWordE, 47U);
            aOrbiterH = (aWandererE + RotL64(aCross, 37U)) + 9067093488553721468U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 12173106198862881754U) + RotL64(aNonceWordD, 49U);
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 6U)) + RotL64(aCarry, 23U)) + 11333491014394592654U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 3511883526940919554U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 7416810692106273044U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + 8341174972619784110U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 29U)) + 2220852854836962979U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 27U)) + 8090781422229383825U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 60U)) + 2338801236599102223U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 35U)) + 12484514711848308104U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13684861340589131816U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12796636819991873058U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5533508014234835669U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7634198650894837690U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 10240326122201201762U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ RotL64(aNonceWordB, 59U);
            aOrbiterD = RotL64((aOrbiterD * 8758703497719125901U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4162814763739453934U) + RotL64(aNonceWordC, 57U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2766504649149048469U;
            aOrbiterH = RotL64((aOrbiterH * 16731843453895178671U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11051393030148769655U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17687055068651386665U;
            aOrbiterG = RotL64((aOrbiterG * 1042927176246229537U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3353615315436983420U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5971640796220306310U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15804313508835034807U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12299773092762384765U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7435804907797063411U;
            aOrbiterF = RotL64((aOrbiterF * 9848139805288165965U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8735783937125735699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11903126115475835615U;
            aOrbiterK = RotL64((aOrbiterK * 16942088822124940265U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4427166023462475475U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6011733469446008137U;
            aOrbiterC = RotL64((aOrbiterC * 17298067225913923517U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18341473946127677319U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5423774915753911947U;
            aOrbiterB = RotL64((aOrbiterB * 14985099502923458523U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2384393657884193014U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2650593524388493958U;
            aOrbiterE = RotL64((aOrbiterE * 892985816665547945U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15991261431384033176U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12583180859826261500U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14394838775646875599U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 6U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aNonceWordH, 50U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 46U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aNonceWordF, 27U));
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 19825U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 18854U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordD, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18608U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21180U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 53U)) + 2974056819475622600U;
            aOrbiterB = (aWandererA + RotL64(aCross, 35U)) + 7345051759236356098U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 37U)) + 12738468816846628882U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 7694520596043297922U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 5530753590015084774U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 60U)) + 3776309161718383105U) + RotL64(aNonceWordG, 25U);
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + 784780304358106404U) + RotL64(aNonceWordC, 31U);
            aOrbiterE = ((aWandererG + RotL64(aCross, 21U)) + 8999942326995036509U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 5194986506064092779U;
            aOrbiterI = (aWandererC + RotL64(aCross, 39U)) + 7920040007459652762U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 48U)) + 11311997270710107937U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 5365231114813547251U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 36U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8630110234623825263U;
            aOrbiterG = RotL64((aOrbiterG * 2735881715888325759U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2358235238039571072U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18059414891616491807U;
            aOrbiterD = RotL64((aOrbiterD * 17150786106857185467U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14526050556461782864U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6937282036603272474U;
            aOrbiterC = RotL64((aOrbiterC * 14954512365270028029U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10105832250694931310U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3884223553012098137U;
            aOrbiterJ = RotL64((aOrbiterJ * 16340956813003906195U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10385284339549648087U) + RotL64(aNonceWordD, 39U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1257633893341505930U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2669950791270500977U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5528890519572824318U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15664241747527713256U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16670884497088220497U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14264122979415331887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17985061405540198036U;
            aOrbiterI = RotL64((aOrbiterI * 2729487440173395133U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1663986734997903415U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3706166884286400587U;
            aOrbiterF = RotL64((aOrbiterF * 10549736618301955745U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12736963182099961466U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 95411267612114381U;
            aOrbiterH = RotL64((aOrbiterH * 8011937916302325057U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4966620136499917388U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8478316876240452401U;
            aOrbiterB = RotL64((aOrbiterB * 13297718919105366563U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11123814701411614557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2974056819475622600U;
            aOrbiterA = RotL64((aOrbiterA * 5913569942407618997U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF) + RotL64(aNonceWordA, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 22U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterC, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + RotL64(aNonceWordH, 53U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 22U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 60U));
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordB, 51U)) ^ RotL64(aNonceWordD, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 25697U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25184U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23281U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 26573U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 12U)) + 3238389262925516513U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 12381787182611386995U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 39U)) + 7883885539305181549U) + RotL64(aNonceWordG, 23U);
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 1185413044597727092U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 54U)) + 15219353497204773135U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 5U)) + 7533774715626734082U) + RotL64(aNonceWordF, 17U);
            aOrbiterD = (aWandererB + RotL64(aScatter, 41U)) + 2599930450937763464U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 47U)) + 16074720663961214284U;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 15483613196360051221U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 9396557867081376268U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 27U)) + 9668459976852660245U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9037269914643207212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16936742640861088240U) ^ RotL64(aNonceWordD, 35U);
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16481274825758546398U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 481851372837611166U;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13608921517203544108U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 16930740723286214636U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) ^ RotL64(aNonceWordH, 9U);
            aOrbiterI = RotL64((aOrbiterI * 2605108503821980865U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 902242902582149908U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1510861213079342977U;
            aOrbiterC = RotL64((aOrbiterC * 3309753895727400707U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7116243600304980310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6631412278359709602U;
            aOrbiterG = RotL64((aOrbiterG * 11452627691392637463U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9246698682265275165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8594373032014031450U;
            aOrbiterJ = RotL64((aOrbiterJ * 2550138341089957033U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15912837963877821048U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11404583513022627609U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17715204726760125357U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17295214920690244319U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18315664494984189344U;
            aOrbiterA = RotL64((aOrbiterA * 17398893532076312945U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2474825506593695564U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4400473621592150441U;
            aOrbiterE = RotL64((aOrbiterE * 7098832854166953839U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15270166373215060119U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4331232225067306139U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2299883590703870703U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2176207815544347316U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3238389262925516513U;
            aOrbiterK = RotL64((aOrbiterK * 13104597690682251231U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 53U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterF, 60U));
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordE, 61U));
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 26U) + aOrbiterA) + RotL64(aOrbiterC, 26U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aNonceWordB, 44U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordF, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 29496U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31064U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 42U) ^ RotL64(aNonceWordE, 51U)) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31421U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 32328U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 50U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 21U)) + 15652862298542575895U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 16925323928418184554U) + RotL64(aNonceWordH, 43U);
            aOrbiterH = (aWandererD + RotL64(aCross, 3U)) + 4413861484961668394U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 2215946422098155969U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 36U)) + 14975185533513111110U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 9711613814905834552U;
            aOrbiterA = (aWandererB + RotL64(aCross, 57U)) + 13154957291850149471U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 19U)) + 5058313016418534840U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 15011423472941211620U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 60U)) + 2030053257469580168U) + RotL64(aNonceWordF, 29U);
            aOrbiterD = (aWandererA + RotL64(aIngress, 23U)) + 150530795186791193U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10878237472104183427U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11724672539469573109U;
            aOrbiterH = RotL64((aOrbiterH * 16158741837357985395U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 9589700906445846956U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1367381624958248949U;
            aOrbiterC = RotL64((aOrbiterC * 8459515089081211977U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12003215666757518106U) + RotL64(aNonceWordC, 23U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11232479330848006729U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10993290955464593033U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13013910456628561621U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6092509838924105265U;
            aOrbiterA = RotL64((aOrbiterA * 805601154718006061U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11999225836250312801U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14421271973875748413U;
            aOrbiterE = RotL64((aOrbiterE * 9529010940887430157U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15536288285741825272U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2071793889925436679U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1526376970151714589U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5622386476463436967U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16147972771639168516U;
            aOrbiterF = RotL64((aOrbiterF * 11826916832825159095U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4519892856053952290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12059500374938843538U;
            aOrbiterD = RotL64((aOrbiterD * 14987533625537956299U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4547335128847992282U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15378473334472216418U;
            aOrbiterK = RotL64((aOrbiterK * 13907560285280544037U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14644123269581735633U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6434315615480805381U;
            aOrbiterJ = RotL64((aOrbiterJ * 4335857173941645355U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14241680137158382296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15652862298542575895U;
            aOrbiterG = RotL64((aOrbiterG * 4190840063924551519U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterF, 58U)) + RotL64(aNonceWordG, 52U));
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + RotL64(aNonceWordD, 47U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 10U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererD, 20U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
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

void TwistExpander_Badminton_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8743B7EA4902AD1BULL + 0xA38D63F4589FB9C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF579CBBD1F5D78F7ULL + 0xFA11149BE933E0A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEBD43DDCC45497ADULL + 0xF5B2D58810FF2A03ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC3E90563D35F950DULL + 0x8F0127B15D07633DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC8677D235DCF64BULL + 0xBB0DE98A11F95B1FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8C4D51AFAFD88059ULL + 0xECD1CC93E70A6AC1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x81CC8FE2232CBDF7ULL + 0xE5EF157B568773BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9E41400E43FDF255ULL + 0xF12B1946D3A99329ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
    // KDF_A_B kdf_a_loop_b (start)
    {
        // KDF_A_B kdf_a_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordC, 57U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6423U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 7145U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordF, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4723U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4445U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 43U)) + 701291026547470433U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 60U)) + 17283292650462111643U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 9969124091931303406U) + RotL64(aNonceWordB, 45U);
            aOrbiterH = (aWandererK + RotL64(aCross, 53U)) + 889176772718046988U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 6054541844643748084U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 11U)) + 14703226235143028132U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 48U)) + RotL64(aCarry, 29U)) + 7977975878522921062U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 21U)) + 16894322614172266274U) + RotL64(aNonceWordA, 55U);
            aOrbiterA = (aWandererA + RotL64(aCross, 27U)) + 12160451749345900570U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10870847008043897470U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8159920947172520247U;
            aOrbiterD = RotL64((aOrbiterD * 4833194641611011805U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2440099120969517932U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2428396147731468007U;
            aOrbiterB = RotL64((aOrbiterB * 9363073341539598441U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2213226274394673479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7079731443427765333U;
            aOrbiterC = RotL64((aOrbiterC * 16918930776877030559U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 958896789550478970U) + RotL64(aNonceWordF, 21U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10788682955708075458U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 913321215613559729U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2003386579317564870U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8419686358774204999U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6547052526438697621U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6989167615157578904U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17636634003643824148U) ^ RotL64(aNonceWordD, 56U);
            aOrbiterH = RotL64((aOrbiterH * 11038576417283732937U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13824962118933907859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9543912892587859646U;
            aOrbiterF = RotL64((aOrbiterF * 14736710162285997415U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15729878041027706114U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9542137475454825463U;
            aOrbiterJ = RotL64((aOrbiterJ * 11420547128115090491U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5327302277575009955U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2707383132257428583U;
            aOrbiterK = RotL64((aOrbiterK * 6120763309390182129U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterG, 34U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aNonceWordH, 47U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + RotL64(aNonceWordE, 31U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 10U));
            aWandererA = aWandererA + ((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordA, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10830U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 14531U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordD, 18U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10160U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 9216U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 10404808878585437255U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterA = (aWandererK + RotL64(aCross, 14U)) + 10587858736301591439U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 47U)) + 1430530909801644435U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 9090938022430118902U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 12936604311751121235U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 60U)) + 1000583006020232032U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 41U)) + 12352532088997042232U) + RotL64(aNonceWordA, 31U);
            aOrbiterD = (aWandererE + RotL64(aIngress, 53U)) + 16723410947058502564U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 23U)) + 16614089235313154270U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4245553025593349277U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3353146318549477494U;
            aOrbiterJ = RotL64((aOrbiterJ * 14246377408238318091U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5935727336135635196U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10312187090293319667U;
            aOrbiterG = RotL64((aOrbiterG * 1395964500396711899U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12192843181244744484U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2542570124502586365U;
            aOrbiterH = RotL64((aOrbiterH * 17222847847573534963U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3315472769469002444U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17512858811783071174U) ^ RotL64(aNonceWordH, 37U);
            aOrbiterD = RotL64((aOrbiterD * 9070400454074283765U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16633218007427888082U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2502077714838858460U;
            aOrbiterK = RotL64((aOrbiterK * 970762420815997725U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14792910273226469214U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15739513291150783151U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterB = RotL64((aOrbiterB * 11896279674116906915U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2192903544350345992U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 844428341223009295U;
            aOrbiterI = RotL64((aOrbiterI * 4768368713974002539U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2998511458298901402U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7790789639864783373U;
            aOrbiterF = RotL64((aOrbiterF * 9173097618440495497U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4540735375055164995U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13700342877362633034U;
            aOrbiterA = RotL64((aOrbiterA * 14730797752841670505U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 18U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + RotL64(aNonceWordC, 28U));
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + RotL64(aNonceWordD, 59U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordA, 10U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22316U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17387U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23664U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 23130U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 30U)) + 826930775230515406U) + RotL64(aNonceWordA, 13U);
            aOrbiterD = (aWandererA + RotL64(aPrevious, 19U)) + 5137814617363250861U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 14761561947426681616U) + RotL64(aNonceWordE, 48U);
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 43U)) + 12773023438753662590U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 57U)) + 7331345852207096322U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 51U)) + 3899381212671247460U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 5U)) + 10072004147620068599U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 10U)) + RotL64(aCarry, 35U)) + 3424585039401897560U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 8246760141625966321U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 3655992860610853290U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordH, 45U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11154618022505863898U;
            aOrbiterH = RotL64((aOrbiterH * 4791494171286145231U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15629361991059709973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10842068502278489664U;
            aOrbiterG = RotL64((aOrbiterG * 17223002513104960799U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5571312349016336686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 589313823745748879U;
            aOrbiterJ = RotL64((aOrbiterJ * 1356685926549786027U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13633457935771935260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12684602052812183096U;
            aOrbiterD = RotL64((aOrbiterD * 4689206269919806711U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5711307583717354204U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7181854170553728211U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9835601115561325911U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1884620014396115821U) + RotL64(aNonceWordC, 57U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1471516373272364262U;
            aOrbiterE = RotL64((aOrbiterE * 5126319375714848029U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 742739371092077733U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8075893317715227838U;
            aOrbiterI = RotL64((aOrbiterI * 11208274111743259795U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8179547722249281263U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15305282712174742323U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7951986906055462929U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1430543231751281079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14585341768267283387U;
            aOrbiterF = RotL64((aOrbiterF * 313213844964269133U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 42U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aNonceWordG, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + RotL64(aNonceWordB, 51U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterA, 54U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordH, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30956U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 27851U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordD, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31471U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31685U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 34U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 6467297102954816305U) + RotL64(aNonceWordE, 13U);
            aOrbiterB = (aWandererB + RotL64(aCross, 18U)) + 7921154109831114952U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 35U)) + 5701131763215638919U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 10022999076719002684U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 27U)) + 4367135243038982316U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 14445846824810383592U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 14U)) + 7683697954545773253U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 43U)) + 17517006750428030899U) + RotL64(aNonceWordD, 60U);
            aOrbiterG = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 2052484792684025476U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6279463052085808926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 679280153651813684U;
            aOrbiterF = RotL64((aOrbiterF * 3047031560593583881U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2939516520188460569U) + RotL64(aNonceWordH, 51U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1960616434964712325U;
            aOrbiterH = RotL64((aOrbiterH * 15145998415466343039U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12273819390719947361U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5685033154709449397U;
            aOrbiterI = RotL64((aOrbiterI * 9845666295874714959U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9314494172199500653U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15757631834636427621U;
            aOrbiterC = RotL64((aOrbiterC * 15483543888965744529U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10878078046389399574U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3583495913766365232U) ^ RotL64(aNonceWordG, 43U);
            aOrbiterA = RotL64((aOrbiterA * 2913540984990155225U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7385544065754622301U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16839599460207922881U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 240651605910592561U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13038163804940349251U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2587538594933924000U;
            aOrbiterK = RotL64((aOrbiterK * 3091149760401278671U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13109518583364738004U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2447689055742474261U;
            aOrbiterG = RotL64((aOrbiterG * 12100180201235703193U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5752044906692668618U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6637725371036522120U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6021986525167161115U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterK, 42U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + RotL64(aNonceWordB, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 18U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordC, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 51U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Badminton_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAA723E5F76D054A5ULL + 0x8C102540754C1CB6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCC61A5DE3EA58D09ULL + 0xB7A644A9E39E097CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF5B86B0BB64CD62BULL + 0xFD5CF879EFFB5D2AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB460F6AD362975D3ULL + 0x83D2964BD9FC284BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD22BEDDEF3D4A479ULL + 0xE0310DF8B7DF0996ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDA6BCA4D9B023C63ULL + 0xC2001333F2CC57B3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE2A064EC49D40ACFULL + 0xC8BFCC9E15E78FDAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF28840080C33B737ULL + 0x9E8E405FAA6CE3FBULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
    // KDF_A_C kdf_a_loop_c (start)
    {
        // KDF_A_C kdf_a_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4646U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((aIndex + 6654U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6176U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 161U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 50U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 4U)) + 16651241552253078315U) + RotL64(aNonceWordF, 55U);
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 4558144676982478003U;
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 8814884320080367550U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordC, 31U);
            aOrbiterK = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 16011579668555672117U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 35U)) + 4738918668759862438U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12526083125540985108U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8048723561746000552U;
            aOrbiterA = RotL64((aOrbiterA * 11914807994597963481U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1082218464034639039U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8432043246965946816U;
            aOrbiterB = RotL64((aOrbiterB * 7801965585991025451U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 9982080524048636852U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordE, 35U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6720069955755215919U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1019035028070247757U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 7360619079463870467U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordD, 11U);
            aOrbiterI = RotL64((aOrbiterI * 6623074813047915863U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10893918488381348474U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1390297670907738019U;
            aOrbiterG = RotL64((aOrbiterG * 11909657437658597735U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 22U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + RotL64(aNonceWordB, 26U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterG, 30U)) + RotL64(aNonceWordH, 45U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10139U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11662U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordA, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8883U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((aIndex + 11815U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 39U)) + 12222235191147985484U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 47U)) + 16367317014523328414U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 3511378091284703789U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordG, 47U);
            aOrbiterK = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 15247492830966725949U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 7745995913390407897U) + RotL64(aNonceWordF, 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 6463593307540108810U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1101669311005268630U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10550146460887359369U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12988052764067518580U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17717179747434679772U;
            aOrbiterA = RotL64((aOrbiterA * 10820310705487638793U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 11662190906682400416U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordA, 19U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6563014073547628748U;
            aOrbiterG = RotL64((aOrbiterG * 16967910471722117761U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13099094932059419219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16342730862261868847U;
            aOrbiterI = RotL64((aOrbiterI * 10988124108686164829U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16855346813127524624U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6570063128502306944U;
            aOrbiterK = RotL64((aOrbiterK * 4571570049463124831U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + RotL64(aNonceWordB, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 56U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + RotL64(aNonceWordC, 20U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 30U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20428U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 18488U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordE, 42U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20028U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24551U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 11039986441331892533U) + RotL64(aNonceWordA, 59U);
            aOrbiterA = ((((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 6256024955965426119U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordH, 53U);
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 5U)) + 9857443189988995666U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 27U)) + 11900944813380998208U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 37U)) + 8422577734978875541U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3100835100713928724U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11871553509810206993U;
            aOrbiterJ = RotL64((aOrbiterJ * 15501681886909921677U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17614749493763417027U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3638372131856199916U) ^ RotL64(aNonceWordD, 48U);
            aOrbiterA = RotL64((aOrbiterA * 480683274898147025U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6582275259281025770U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17016882418498941958U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4269869255230867823U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1747214688658984715U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9356088987044015278U) ^ RotL64(aNonceWordC, 11U);
            aOrbiterB = RotL64((aOrbiterB * 16221733545319753695U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4056238112133473456U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16013150119949532998U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12913648646318115315U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordE, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + RotL64(aNonceWordG, 51U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 42U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterB, 38U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordA, 54U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25659U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 28128U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordH, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31300U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 31161U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 52U)) + 9446153639709651566U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 10550762260670758167U) + RotL64(aNonceWordD, 27U);
            aOrbiterH = (aWandererE + RotL64(aCross, 37U)) + 7062634922142578383U;
            aOrbiterE = ((((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 9178499097812764515U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordC, 7U);
            aOrbiterG = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 6887103379773525538U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6239750312052010257U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17645022614523287959U;
            aOrbiterH = RotL64((aOrbiterH * 14448140327044053545U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3639618183259408272U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 3131737117548745095U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ RotL64(aNonceWordG, 43U);
            aOrbiterC = RotL64((aOrbiterC * 6585057380704940395U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7253994382396406554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15217993711938379561U;
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12594152227603630033U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11250170200489647869U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 546800378327864723U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12936942656624279424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10990736056052106149U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterG = RotL64((aOrbiterG * 7123916809953459187U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aNonceWordB, 12U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterH, 14U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordE, 49U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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

void TwistExpander_Badminton_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBDAD446AD37A5235ULL + 0xB0CB18364833B729ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF9F3FF0C6E519EB3ULL + 0xAC160FB2F6D8CEC4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA09E30FA58587AA1ULL + 0xC2FA9E21C81CA79EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFC218C5EAB1EF851ULL + 0xFF43782175139E9BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA3B050D13CB14C03ULL + 0x923EC0C20D67B781ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBF5C4A89A6015DAFULL + 0x82C735A7E182FE60ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC4DE394AB5F4F4B1ULL + 0x9F9CBA8108A95AFBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB22C77D7EE888C6FULL + 0xFE5A6A3A22F92A5FULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
    // KDF_A_D kdf_a_loop_d (start)
    {
        // KDF_A_D kdf_a_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2191U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2110U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordG, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3403U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 570U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 42U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 12136097566601676613U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 19U)) + 7969431322248040056U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aIngress, 30U)) + RotL64(aCarry, 51U)) + 10530676021510553889U) + RotL64(aNonceWordE, 40U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 8740777303075445264U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 13U)) + 13249434169895564739U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 47U)) + 15529577005925628472U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 31U);
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 344627093687331562U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8824277416519988893U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5636276438449709875U;
            aOrbiterA = RotL64((aOrbiterA * 222817930773618893U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2079413361031851552U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7807998179168655561U) ^ RotL64(aNonceWordB, 19U);
            aOrbiterB = RotL64((aOrbiterB * 961456853699784753U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13589392896232029112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10733011474804473996U;
            aOrbiterH = RotL64((aOrbiterH * 361749145931578805U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15934162328347805968U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7573511217796245232U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10694563909931636155U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4828475187337891975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13284974329890393113U;
            aOrbiterJ = RotL64((aOrbiterJ * 10831075817642374287U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 13173869918669643112U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 51U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15841507674783398167U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15632933198136963277U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14168272451055700516U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11134471485501999898U;
            aOrbiterI = RotL64((aOrbiterI * 8019507184494591705U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordD, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterE, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterB, 34U)) + RotL64(aNonceWordH, 59U));
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 20U) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14542U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10540U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12752U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 9695U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 46U)) + 7960325128608297381U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 12773836012104052042U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 29U)) + 3173972621347773016U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + 3708401356314308171U) + RotL64(aNonceWordH, 56U);
            aOrbiterA = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 950774285720019449U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 4170092315705438265U) + RotL64(aNonceWordB, 43U);
            aOrbiterF = ((aWandererF + RotL64(aIngress, 3U)) + 17000449130864980747U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 8793910540062893860U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordC, 35U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 520277969543516469U;
            aOrbiterG = RotL64((aOrbiterG * 4150613128885828229U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12762214857389827271U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2932451184340207695U;
            aOrbiterE = RotL64((aOrbiterE * 7513337346940091655U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11062179998786293839U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7919119215271524178U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1774988449597115155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3799792889466518953U;
            aOrbiterC = RotL64((aOrbiterC * 17512791286490623455U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1815062051307896589U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15260373951371654483U;
            aOrbiterA = RotL64((aOrbiterA * 2208604434669491625U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12867546628945676853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7772820973895846946U;
            aOrbiterB = RotL64((aOrbiterB * 7581704643538761985U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14213957831821966834U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16561105721170419454U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterF = RotL64((aOrbiterF * 2540533987337175367U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 13U)) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 58U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aNonceWordD, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 40U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23916U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 23647U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 23U) ^ RotL64(aNonceWordF, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19487U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 23744U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 3U)) + 5480870806135400132U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 8034874599430768743U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 29U)) + 4006919843736863767U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 2988069748674633718U) + RotL64(aNonceWordD, 5U);
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 12347295651973135786U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 58U)) + 14152683894431568192U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordF, 53U);
            aOrbiterB = (aWandererC + RotL64(aIngress, 37U)) + 15765143815254196598U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10473067082331244233U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1089466925383677249U;
            aOrbiterI = RotL64((aOrbiterI * 17334888609179149753U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13215039929873682230U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3957997712247961479U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7631186240013784703U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10023907397941685546U) + RotL64(aNonceWordC, 29U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterK = RotL64((aOrbiterK * 17111300092082154687U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13353797968154036726U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9259966668512102858U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10757861831070349321U) + RotL64(aNonceWordB, 56U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10530223113483866178U;
            aOrbiterH = RotL64((aOrbiterH * 11269177745265396583U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7554320926405521865U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6978052067277966996U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18020134738536217801U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1053695861967171420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15980734683539854451U;
            aOrbiterB = RotL64((aOrbiterB * 3208466640010555357U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 60U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordH, 55U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordG, 17U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 28U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordA, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29547U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 27896U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordB, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24660U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27826U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 3U)) + 18087125778766689269U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 13710545066503235196U) + RotL64(aNonceWordE, 55U);
            aOrbiterC = (aWandererH + RotL64(aPrevious, 37U)) + 1701939704736254645U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 28U)) + 8064093611384019909U;
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 16623332751533885431U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordD, 5U);
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 15590129153794910109U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 43U)) + 7413312683079107383U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4186064478651458810U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5501191643940735954U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14254804649177125269U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11064645242200570835U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13825922087298055833U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7529317892716108867U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5944980709887369970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8181136916070569646U;
            aOrbiterB = RotL64((aOrbiterB * 395183021205661827U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15442336949157292482U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11580554435240641337U;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11240018128174598322U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2027565596050777471U) ^ RotL64(aNonceWordC, 29U);
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16425887196883725233U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16828683527588834095U;
            aOrbiterH = RotL64((aOrbiterH * 17746289103235902485U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 9923829146479008804U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordF, 18U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6669171007279929454U;
            aOrbiterD = RotL64((aOrbiterD * 681823450939955099U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aNonceWordH, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + RotL64(aNonceWordG, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 46U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Badminton_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEAF61ACB9670C2A7ULL + 0xF215E8365A2C6FABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD0E71FA87BED6343ULL + 0xAD1D379FF9364C31ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8DF71F79BCF4CC2BULL + 0xED9E068F0F72A051ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD4FDD73B3D44C73FULL + 0xD367DF682FE4AB08ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x86E57D7426B7ED67ULL + 0xAAFBB0F618A85851ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAFD08D2243F1AFF7ULL + 0xACDA17B78B935513ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDD5226614DE0440DULL + 0xC7FCD50C3D69B13AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEC4639D144E6F48DULL + 0xCEEDE4EF52BAECE7ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
    // KDF_B_A kdf_b_loop_a (start)
    {
        // KDF_B_A kdf_b_loop_a lane group
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 52U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5119U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 238U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 23U) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1518U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 954U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 14823268998003220191U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 39U);
            aOrbiterC = ((aWandererK + RotL64(aCross, 51U)) + 15295237288788213847U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 16434853402001133899U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 7555911304407871631U;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 14977248264994834620U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 29U)) + 9707764144919392380U) + RotL64(aNonceWordD, 23U);
            aOrbiterB = (aWandererD + RotL64(aScatter, 42U)) + 1277304385464681529U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3089786220465849395U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3700503853358695085U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2079089949442685421U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3240054112993517371U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16897532076915366859U) ^ RotL64(aNonceWordF, 17U);
            aOrbiterA = RotL64((aOrbiterA * 4120874717534309035U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18167359289798364307U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8870819278575769863U;
            aOrbiterF = RotL64((aOrbiterF * 9334066154398059075U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15363069206212330251U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14931933411393847915U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5357144808788707522U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2910681277417754860U;
            aOrbiterH = RotL64((aOrbiterH * 13170868582159347059U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9824408699018165151U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 368370224788793300U) ^ RotL64(aNonceWordG, 59U);
            aOrbiterJ = RotL64((aOrbiterJ * 14358982366258729959U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7095398304588825115U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11418879758164313554U;
            aOrbiterC = RotL64((aOrbiterC * 5983520332639771791U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 44U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aNonceWordB, 56U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + RotL64(aNonceWordC, 45U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // read from: aExpandLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13388U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 8515U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14680U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 8816U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 42U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 7825479804710770560U) + RotL64(aNonceWordH, 31U);
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 5298124167101358123U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + 17774541024369233726U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 11U)) + 7679371833537454082U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 50U)) + 5385914900748772224U) + RotL64(aNonceWordF, 11U);
            aOrbiterK = (aWandererC + RotL64(aScatter, 19U)) + 3879781930908486531U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 659110346638873236U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10749021728538539749U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3631252455767429457U;
            aOrbiterF = RotL64((aOrbiterF * 8552825360915119613U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2271978810960685021U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5963558780692551176U;
            aOrbiterI = RotL64((aOrbiterI * 4772055335210781149U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 974909966119198104U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9296998242911152296U;
            aOrbiterA = RotL64((aOrbiterA * 2613629915877957661U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2245318466901521959U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13391076374843288568U) ^ RotL64(aNonceWordC, 25U);
            aOrbiterB = RotL64((aOrbiterB * 18094558036982107419U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6184487746594236737U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1563385912137291418U) ^ RotL64(aNonceWordE, 52U);
            aOrbiterH = RotL64((aOrbiterH * 4805455299959232321U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1744840092006498629U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2100927276837188416U;
            aOrbiterK = RotL64((aOrbiterK * 3541788262067077997U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9998911862807246338U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12239948725635220096U;
            aOrbiterC = RotL64((aOrbiterC * 7098620484129489129U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 22U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 34U)) + aOrbiterB) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 45U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + RotL64(aNonceWordA, 23U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneD, aWorkLaneC
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 12U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22849U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21357U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordF, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23249U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((aIndex + 20559U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 16124889768301047791U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 3U)) + 11912338587186717280U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 44U)) + RotL64(aCarry, 57U)) + 8594012868813114354U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 18281043566156682815U) + RotL64(aNonceWordA, 11U);
            aOrbiterD = (((aWandererA + RotL64(aScatter, 29U)) + 16853106130200942302U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordC, 20U);
            aOrbiterF = (aWandererE + RotL64(aPrevious, 19U)) + 2611212958619673086U;
            aOrbiterB = (aWandererB + RotL64(aCross, 53U)) + 18039472325066855180U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14495785571345122046U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4556063793412832418U) ^ RotL64(aNonceWordG, 43U);
            aOrbiterG = RotL64((aOrbiterG * 13166927543135467627U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14896419970271244358U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 880028529183500036U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14228281807461251361U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2379557167489415783U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11854373946064529806U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1487252775956449964U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12777924204511625545U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1366019527386994789U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15998631485222477969U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8864212892296191613U;
            aOrbiterD = RotL64((aOrbiterD * 579242788050369815U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17069347835763226743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7443008171694679791U;
            aOrbiterF = RotL64((aOrbiterF * 748894368884566607U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17334256152350782002U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8986626119086556393U;
            aOrbiterB = RotL64((aOrbiterB * 2258172145924120235U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterG, 12U));
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aNonceWordH, 53U)) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneD
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordE, 24U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26384U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 32212U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28289U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 32328U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 23U)) + 13714409587461539863U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 14101156723903265839U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 7063754562895369001U) + RotL64(aNonceWordC, 3U);
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 12320578575245519386U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 13U)) + 11744826789631008424U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 35U)) + 8744816505096675597U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 51U)) + 10405435520084528645U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordG, 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 1463157688070683543U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12379603577919617703U;
            aOrbiterJ = RotL64((aOrbiterJ * 14858901470015109311U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1343439118031348146U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16118850268070235540U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11184386483735388257U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14116264435819277136U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5251698273012432109U;
            aOrbiterC = RotL64((aOrbiterC * 1495818611622063967U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14806408656041403829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11569345414052398227U;
            aOrbiterD = RotL64((aOrbiterD * 9913158908301414861U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17063874769147888574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9927420478679581917U;
            aOrbiterA = RotL64((aOrbiterA * 9042782809534196563U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2550285599827162167U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17801534123304996448U) ^ RotL64(aNonceWordA, 39U);
            aOrbiterI = RotL64((aOrbiterI * 2160836889363614721U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6456685241021762041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17064208177372969289U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13726627607233302493U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 39U)) + RotL64(aNonceWordF, 9U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + RotL64(aNonceWordE, 34U));
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 60U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 37U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Badminton_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9A772182C592FE95ULL + 0xC0B046E279E4B237ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC401C6A77348AF13ULL + 0xA563B68274E99614ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x98F9C4020D114DFBULL + 0x81AF70337E7E88FAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9C278F2A3FFDA6D1ULL + 0xA14046BEC61C2577ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE719275DF1A00D1FULL + 0xE1457002D8A45728ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFC44A494ECAE3573ULL + 0xB6C2411632EC4A2FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA49B68D0F7428B81ULL + 0xB7FC01D7A3A4D516ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x93AE049E343869A1ULL + 0xB72DBF37520A5F21ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
    // KDF_B_B kdf_b_loop_b (start)
    {
        // KDF_B_B kdf_b_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordH, 60U)) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2371U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 706U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordD, 6U)) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6801U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 8004U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 48U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 54U)) + 16519040829220310189U;
            aOrbiterG = (aWandererI + RotL64(aCross, 29U)) + 6888002778416941825U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 21U)) + 1310832187746534025U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 27U)) + 5890888009051281674U) + RotL64(aNonceWordE, 31U);
            aOrbiterB = ((aWandererA + RotL64(aCross, 48U)) + RotL64(aCarry, 11U)) + 5143864838362464857U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 13U)) + 15591534069452660003U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 1466867671765325096U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 13931443680107902488U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 23U)) + 15400747367673245552U) + RotL64(aNonceWordA, 57U);
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 39U)) + 2836975369734495759U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 3U)) + 2370720358274970117U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3470677184188006133U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7175584278499266723U;
            aOrbiterD = RotL64((aOrbiterD * 10067096593682482345U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6095078817776863055U) + RotL64(aNonceWordF, 13U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2176637999243513070U;
            aOrbiterE = RotL64((aOrbiterE * 12215701810843975501U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5580391239754903129U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15196125567953871184U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12686361960729564519U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12787014151503209931U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1523153207064063495U;
            aOrbiterF = RotL64((aOrbiterF * 3113907543551927561U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12973289026485937829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9087439766232078173U;
            aOrbiterJ = RotL64((aOrbiterJ * 5817029335999350327U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16318022893068674015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11089160685103562409U;
            aOrbiterI = RotL64((aOrbiterI * 17087834321385147603U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 8680037953925067235U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordC, 55U);
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3112588943274158119U;
            aOrbiterA = RotL64((aOrbiterA * 9214011370307670371U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16749015684369649821U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9419550535891334966U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5421312787569114811U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12309598080688360615U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12244971765096881835U;
            aOrbiterB = RotL64((aOrbiterB * 17260277357109449509U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10088685417774847648U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3241987595838650154U;
            aOrbiterH = RotL64((aOrbiterH * 14096986158958931367U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17916401586500786536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16519040829220310189U;
            aOrbiterC = RotL64((aOrbiterC * 6742024268853509861U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 54U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 16U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aNonceWordD, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterK, 46U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10621U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 9969U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordG, 19U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13823U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9653U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 29U)) + (RotL64(aCross, 43U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 13U)) + 13583136155674166402U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 41U)) + 12830472187484919497U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 57U)) + 18081197909484522509U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 8680634051297891550U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 53U)) + 13939998767458656823U) + RotL64(aNonceWordC, 43U);
            aOrbiterA = (aWandererF + RotL64(aCross, 37U)) + 1795730579103692594U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 5U)) + 17369751719734069999U) + RotL64(aNonceWordH, 61U);
            aOrbiterK = (aWandererD + RotL64(aIngress, 23U)) + 224769585901248068U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 48U)) + 4133547085925268180U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 7022512056309567391U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 10319484359046945495U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10483878349412282069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6481381149199985736U;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13721077228796934509U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9704818014314175007U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 760445624027740287U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6253040047758584339U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16890211690273641226U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6216227831265032436U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2023609047004658739U;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9201669637050388263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5106927540934338576U;
            aOrbiterB = RotL64((aOrbiterB * 6368134569042291431U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10080368957861445998U) + RotL64(aNonceWordE, 3U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10784789383436485808U;
            aOrbiterD = RotL64((aOrbiterD * 3794918350254445939U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15426339824951793026U) + RotL64(aNonceWordF, 13U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17637144549368340331U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10971293914614704441U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9941300382181962134U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8118046374121322097U;
            aOrbiterA = RotL64((aOrbiterA * 8481945819050983127U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5138086185042567633U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7279942739248982986U;
            aOrbiterK = RotL64((aOrbiterK * 12911998308338410917U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12135610639038562853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12945353426409788798U;
            aOrbiterG = RotL64((aOrbiterG * 7434977715954413699U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7534876598022096222U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13583136155674166402U;
            aOrbiterI = RotL64((aOrbiterI * 8194058098043157015U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 36U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterE) + RotL64(aNonceWordB, 60U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 39U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18897U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 18697U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19309U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 17630U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 3U)) + 8767379393098711499U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 7168159491580816433U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 9879279829061883406U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 35U)) + 10537167136053399303U) + RotL64(aNonceWordG, 19U);
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 23U)) + 2839070018069188936U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 58U)) + 13844278063968429732U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 11278946626186474646U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 53U)) + 11798425216660557799U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 47U)) + 7618446090703335192U) + RotL64(aNonceWordF, 35U);
            aOrbiterG = ((aWandererA + RotL64(aCross, 10U)) + 695423597006983660U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 14344728202803488813U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11656100506575697086U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10384358779985773937U;
            aOrbiterA = RotL64((aOrbiterA * 247494692039140973U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17585001605131977341U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9964478171465522911U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13484044854790175315U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2710943171829692624U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17809072853457153057U;
            aOrbiterE = RotL64((aOrbiterE * 16341884203303271365U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12814092033910687774U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1743186323268668740U;
            aOrbiterJ = RotL64((aOrbiterJ * 11150822630624332557U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10750472346626754704U) + RotL64(aNonceWordA, 47U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15925901217078035356U;
            aOrbiterF = RotL64((aOrbiterF * 9276504171291801637U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2569102106359362359U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8868261301410769739U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3662495603133918101U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2143691008373582476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10606616796243205921U;
            aOrbiterB = RotL64((aOrbiterB * 15794414817813485643U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16258070651850746855U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11720192793689633315U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterK = RotL64((aOrbiterK * 14475623219460678021U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8230871037292355675U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16898650748046368353U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7368697435476300255U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9071122174426904737U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4506737259011736474U;
            aOrbiterI = RotL64((aOrbiterI * 11903039808814842447U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4545409671845718259U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8767379393098711499U;
            aOrbiterH = RotL64((aOrbiterH * 1210632171306946669U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 36U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterH, 50U)) + RotL64(aNonceWordH, 27U));
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + RotL64(aNonceWordD, 10U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 14U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 44U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30082U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29910U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordF, 44U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25830U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 31148U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 54U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 41U)) + 12136097566601676613U) + RotL64(aNonceWordG, 29U);
            aOrbiterH = (aWandererA + RotL64(aScatter, 29U)) + 7969431322248040056U;
            aOrbiterK = (aWandererE + RotL64(aCross, 60U)) + 10530676021510553889U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 8740777303075445264U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 13249434169895564739U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 47U)) + 15529577005925628472U) + RotL64(aNonceWordA, 45U);
            aOrbiterI = (aWandererI + RotL64(aScatter, 23U)) + 344627093687331562U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 14U)) + 8824277416519988893U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 11U)) + 5636276438449709875U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 27U)) + 2079413361031851552U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 7807998179168655561U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13589392896232029112U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10733011474804473996U;
            aOrbiterK = RotL64((aOrbiterK * 361749145931578805U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15934162328347805968U) + RotL64(aNonceWordF, 57U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7573511217796245232U;
            aOrbiterJ = RotL64((aOrbiterJ * 10694563909931636155U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4828475187337891975U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13284974329890393113U;
            aOrbiterC = RotL64((aOrbiterC * 10831075817642374287U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13173869918669643112U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15841507674783398167U;
            aOrbiterI = RotL64((aOrbiterI * 15632933198136963277U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14168272451055700516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11134471485501999898U;
            aOrbiterB = RotL64((aOrbiterB * 8019507184494591705U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2611858916687822610U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17863271539727513641U) ^ RotL64(aNonceWordD, 10U);
            aOrbiterD = RotL64((aOrbiterD * 4987884722174985677U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8874401993454249066U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5131480593493950665U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8585874663602346121U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9366563022381918996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7890729519928340296U;
            aOrbiterF = RotL64((aOrbiterF * 11428572374057899517U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 131774386529223292U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4108356674478240148U;
            aOrbiterG = RotL64((aOrbiterG * 2492753294539081613U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7651738365157869789U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2745458108574051004U;
            aOrbiterH = RotL64((aOrbiterH * 2175955806036373729U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10492013124307434604U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12136097566601676613U;
            aOrbiterA = RotL64((aOrbiterA * 13128652803485742119U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 40U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 30U)) + aOrbiterH) + RotL64(aNonceWordE, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aNonceWordC, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Badminton_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD33ECA9B7BF0AA77ULL + 0xA33A6D14E7B943B8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x90C747027B584ABFULL + 0x9D240A0B41D70F5CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC32FEF3954FAEFF9ULL + 0x8A98F3A3F7D77EABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC218593F575A57B9ULL + 0xE86290A64B5D14F3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC9D31B82BEEC5069ULL + 0xA7DED2A148C9F565ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEA1E019C308A23ABULL + 0xE271768E97F6883EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB9C1AA326DD5CB2FULL + 0xE0817962459E79C1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x89ABB2DDA0CB93A1ULL + 0xAE91D545EF17D05AULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
    // KDF_B_C kdf_b_loop_c (start)
    {
        // KDF_B_C kdf_b_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordH, 10U)) ^ RotL64(aNonceWordG, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1645U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 693U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordD, 50U)) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 399U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3509U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 35U)) + 16200278595895089008U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 19U)) + 1029614154810465897U) + RotL64(aNonceWordB, 61U);
            aOrbiterH = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 7129562468705441295U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 14388903902433951274U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 57U)) + 1013568949315967455U) + RotL64(aNonceWordC, 47U);
            aOrbiterF = (aWandererC + RotL64(aPrevious, 29U)) + 3128823373497815651U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 44U)) + 14525694606889470589U;
            aOrbiterA = (aWandererE + RotL64(aCross, 11U)) + 14443983602196782887U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 23U)) + 12244220415328641190U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10477159225338766614U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2842870123078131566U;
            aOrbiterH = RotL64((aOrbiterH * 11522265477555954071U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8621138818955849917U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5038396344400303181U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14636756322207385447U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2768613802894372496U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2027754864051410015U;
            aOrbiterA = RotL64((aOrbiterA * 2461322540050569287U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2848088309172056399U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15017458513904884651U;
            aOrbiterI = RotL64((aOrbiterI * 9926904679902843055U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9079797279596336139U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15424866642305110811U;
            aOrbiterC = RotL64((aOrbiterC * 12912331089970158845U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13751764050290602740U) + RotL64(aNonceWordE, 51U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7694557131324740282U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14980807690491467023U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3508673897305667669U) + RotL64(aNonceWordA, 15U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3600868397311393233U;
            aOrbiterK = RotL64((aOrbiterK * 5165032044164139165U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1222655844979128996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2257342337168905875U;
            aOrbiterB = RotL64((aOrbiterB * 6198995971182272119U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6290990717563682725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15308494772443447109U;
            aOrbiterE = RotL64((aOrbiterE * 1925593111157842325U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 12U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordG, 31U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterB, 18U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterH, 11U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 56U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 52U) + aOrbiterC) + RotL64(aOrbiterI, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aNonceWordD, 42U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordB, 30U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9038U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 10845U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordG, 47U)) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6104U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 8375U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 18U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 18U)) + 964165145848253292U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 10645976767204934746U) + RotL64(aNonceWordC, 15U);
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 8241612229349212650U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 43U)) + 4159196033256913347U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 23U)) + 7194795864620233507U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 56U)) + 7638928444536778384U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 11819105916503968109U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aScatter, 13U)) + 18052213302858186237U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterB = (aWandererJ + RotL64(aCross, 51U)) + 8663575313970041570U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16644136720439299786U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16930316530442679864U;
            aOrbiterI = RotL64((aOrbiterI * 2650922074098320859U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16251107616988250593U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7171986193609401665U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17885046834432626644U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7757069274715713557U;
            aOrbiterH = RotL64((aOrbiterH * 15766885299397923879U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2212805322061155615U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6368539134638838822U;
            aOrbiterA = RotL64((aOrbiterA * 13383744883433594259U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5264326094252925613U) + RotL64(aNonceWordD, 61U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6126345334815012938U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17180934809764905307U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13826731214018407061U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6621261811613643620U) ^ RotL64(aNonceWordG, 54U);
            aOrbiterK = RotL64((aOrbiterK * 2823596473596114171U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5964406317285863781U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2167324450276308078U;
            aOrbiterJ = RotL64((aOrbiterJ * 1098346374733634905U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16740710162977859724U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8236083581048717923U;
            aOrbiterC = RotL64((aOrbiterC * 4364887787000704039U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13967473987446124012U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5136051802217149813U;
            aOrbiterE = RotL64((aOrbiterE * 13997246005108872883U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 56U)) + aOrbiterJ) + RotL64(aNonceWordE, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + RotL64(aNonceWordB, 17U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterH, 34U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 19U)) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11683U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13595U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordB, 34U)) ^ RotL64(aNonceWordC, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11740U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 12612U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 43U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 11450949896247900941U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 3905542253538116335U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 57U)) + 9529740545977785305U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordC, 14U);
            aOrbiterJ = ((aWandererE + RotL64(aCross, 35U)) + 1856876631533143492U) + RotL64(aNonceWordB, 41U);
            aOrbiterA = (aWandererA + RotL64(aPrevious, 41U)) + 84253466320181686U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 10U)) + 12577480918745432444U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 47U)) + 5625703170397704029U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 694608607323629282U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 19U)) + 3993981243536262204U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4119215953484892051U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8785040118556157146U) ^ RotL64(aNonceWordA, 21U);
            aOrbiterE = RotL64((aOrbiterE * 17113521266125471625U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16234403619456882890U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10398727475672860610U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5086871400049644715U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18327987141759096769U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 2645964788056875452U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) ^ RotL64(aNonceWordH, 7U);
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2859452497983106129U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7196557924940881076U;
            aOrbiterK = RotL64((aOrbiterK * 14415389907490256711U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 930127943984174668U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15673596916054795749U;
            aOrbiterA = RotL64((aOrbiterA * 7505660488733199479U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16673140529110941163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2258448294877833760U;
            aOrbiterG = RotL64((aOrbiterG * 1821550319748977445U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6870209259643931219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12749790107942194104U;
            aOrbiterI = RotL64((aOrbiterI * 4871407285968611725U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17131374134617173866U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6426448390733751612U;
            aOrbiterC = RotL64((aOrbiterC * 12490559588384058417U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15592826434339731146U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14182944418026376183U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7218860482893476233U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterG, 6U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aNonceWordF, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 48U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + RotL64(aNonceWordG, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 56U)) + aOrbiterE) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordB, 60U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21595U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 18831U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordF, 58U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18439U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 20737U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 58U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 12046647397183218524U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 47U)) + 2760779375026461991U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 13735454443176855650U) + RotL64(aNonceWordD, 35U);
            aOrbiterA = (aWandererH + RotL64(aScatter, 13U)) + 4370377000586647724U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 52U)) + 14566322384189969094U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 23U)) + 5056565959818422786U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 57U)) + 8795403810686579209U) + RotL64(aNonceWordC, 29U);
            aOrbiterI = (aWandererC + RotL64(aIngress, 3U)) + 9625947666256011567U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 42U)) + RotL64(aCarry, 3U)) + 1703669290934254701U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6664070663184147951U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2104148316797553431U;
            aOrbiterE = RotL64((aOrbiterE * 12887842067180975983U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1197910004222596145U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9922977170060903197U;
            aOrbiterG = RotL64((aOrbiterG * 13047828062605568603U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2048376210852567829U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12568990647075931409U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15026894775772902751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3439447160137900629U;
            aOrbiterC = RotL64((aOrbiterC * 1813754963043785165U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6532671388552829796U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 17261098369835997661U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ RotL64(aNonceWordG, 37U);
            aOrbiterA = RotL64((aOrbiterA * 568292591215203521U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3171300991007459947U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5935563269327662024U;
            aOrbiterK = RotL64((aOrbiterK * 11271790283157765003U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14290941734320455612U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12371794745736518824U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12208762336145168647U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8782840145467637373U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4067525421190366741U) ^ RotL64(aNonceWordB, 53U);
            aOrbiterH = RotL64((aOrbiterH * 6671002797916227485U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11854812920571789853U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17564890418553131451U;
            aOrbiterD = RotL64((aOrbiterD * 16657184504366731805U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 26U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 38U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aNonceWordA, 28U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterD, 42U)) + RotL64(aNonceWordE, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 10U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 52U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordG, 51U) ^ RotL64(aNonceWordA, 38U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24548U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22456U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 51U) ^ RotL64(aNonceWordB, 34U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23594U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23845U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 34U)) + 12690502671561165478U) + RotL64(aNonceWordB, 16U);
            aOrbiterH = (((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 17519943923428102801U) + RotL64(aNonceWordH, 31U);
            aOrbiterE = (aWandererH + RotL64(aCross, 13U)) + 10705515807975331385U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 16586447272278538179U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 8006560996840971798U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 51U)) + 12928600185788857701U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 57U)) + 14240723153798267172U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 18U)) + 8636219177994872072U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 23U)) + 7586790235186467512U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1103807034179512424U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7547526530239498693U;
            aOrbiterE = RotL64((aOrbiterE * 3360295583636013509U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8380239679344786397U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5690809173787433519U;
            aOrbiterF = RotL64((aOrbiterF * 5354724308093372953U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8390902801141804609U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3507306189192059486U) ^ RotL64(aNonceWordA, 29U);
            aOrbiterC = RotL64((aOrbiterC * 18336280496510253103U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6190745292098482871U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8065418693975056902U;
            aOrbiterB = RotL64((aOrbiterB * 6414621418430102589U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12111755051718111803U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7605877769709909297U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterD = RotL64((aOrbiterD * 17525248694315944599U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5969794501112646237U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5127559299360591476U;
            aOrbiterG = RotL64((aOrbiterG * 4521563633438853069U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10593847754747739786U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4401750688524310121U;
            aOrbiterI = RotL64((aOrbiterI * 14265829318976633707U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6927893132508779499U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4874009978647014479U;
            aOrbiterH = RotL64((aOrbiterH * 13340466017023540755U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13146693487138744677U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3298472134223595298U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2145005258008477281U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterC, 22U)) + RotL64(aNonceWordE, 47U));
            aWandererB = aWandererB + ((((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + RotL64(aNonceWordD, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 52U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordH, 48U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27544U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 28526U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordG, 48U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27516U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29533U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 56U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 13278949403988203974U;
            aOrbiterI = (aWandererI + RotL64(aCross, 13U)) + 9213599924054673756U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 19U)) + 1255746482932381798U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 11575321997144516122U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 27U)) + 15881587525529432437U) + RotL64(aNonceWordB, 9U);
            aOrbiterA = (aWandererJ + RotL64(aScatter, 51U)) + 9846195809864862707U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 19U)) + 12319815691858217670U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 3U)) + 16322617427294439587U) + RotL64(aNonceWordF, 43U);
            aOrbiterE = (aWandererC + RotL64(aCross, 58U)) + 16332130810525887437U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4920951156015336794U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16767126455124552329U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4440352337076842603U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12553595911087945223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1437522202135436142U;
            aOrbiterD = RotL64((aOrbiterD * 2001992794165550905U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12313100454852227143U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2761983020631055729U;
            aOrbiterB = RotL64((aOrbiterB * 3874839760378039509U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17635303588421554367U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 788212489507463763U;
            aOrbiterJ = RotL64((aOrbiterJ * 17896475584538528059U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5192552894670654434U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6784748488807738811U) ^ RotL64(aNonceWordG, 25U);
            aOrbiterE = RotL64((aOrbiterE * 8077237651953896479U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16113417046719114943U) + RotL64(aNonceWordE, 20U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1096874945215225916U;
            aOrbiterG = RotL64((aOrbiterG * 17308604412622879833U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7610274704570171595U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10466070212284342550U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6449728258497920613U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6777845928873855221U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5251515022021984126U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9018277343404261611U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13849343158824111498U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7977711210181714021U;
            aOrbiterI = RotL64((aOrbiterI * 4182053966171053577U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterD, 58U)) + RotL64(aNonceWordH, 59U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordA, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterE, 10U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
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

void TwistExpander_Badminton_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9C8B95B923B4CB9BULL + 0x99D277A89405A9B6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCF85E0CF75B3AB31ULL + 0x96E243E63EB628D0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA246B0965A8A3233ULL + 0x80648413E8F9DE8FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCD732119E0B67DD3ULL + 0x888D28B195BAE97EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8DFD21918274036FULL + 0xD6ECFE267D92A0F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE98366762A24FCE9ULL + 0xA0A464ECC532A85CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98DA8446F6A92947ULL + 0xB5EB8AB90212BE3EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCF808DF115352D1DULL + 0xEA6E1F2AA718D650ULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: mSource, aKeyRowReadA, aKeyRowReadB, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // read from: mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordH, 56U) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4500U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 3981U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordF, 41U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2134U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 1609U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 4384716820085860551U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 27U)) + 9715780315942116888U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 19U)) + 15963520052789178632U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 14346700690686392938U) + RotL64(aNonceWordD, 53U);
            aOrbiterE = ((aWandererG + RotL64(aCross, 11U)) + 6005518012489966643U) + RotL64(aNonceWordF, 41U);
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 34U)) + RotL64(aCarry, 57U)) + 2506732930310252119U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 57U)) + 16782163084851775826U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 823673076571076303U) + RotL64(aNonceWordC, 31U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1634084509064077736U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1128407326773234517U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1288134975466877686U) + RotL64(aNonceWordB, 5U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2998220403162908444U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4321412662318298283U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 220430672180734911U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10223923547068528867U;
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11696469696177647608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6545430420379636963U;
            aOrbiterK = RotL64((aOrbiterK * 8387163146257553773U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 79691451831797107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8971444023498649419U;
            aOrbiterB = RotL64((aOrbiterB * 7148919880477390009U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5624403902454498793U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9468064161002030997U;
            aOrbiterA = RotL64((aOrbiterA * 8243560528100864595U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4619361544913629805U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12682446273369750704U;
            aOrbiterJ = RotL64((aOrbiterJ * 10879074713156075641U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 38U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 6U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + RotL64(aNonceWordG, 59U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // read from: aWorkLaneA, mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9863U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8631U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordA, 41U)) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10591U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 7040U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 4751694786009671052U) + aPhaseAOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 16362725160370844224U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 43U)) + 6360885380915941057U;
            aOrbiterF = ((((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 29U)) + 5154536007972297036U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordD, 27U);
            aOrbiterB = ((aWandererH + RotL64(aIngress, 5U)) + 9362540581874808253U) + RotL64(aNonceWordB, 47U);
            aOrbiterI = (aWandererC + RotL64(aScatter, 51U)) + 13902493871525612934U;
            aOrbiterG = (aWandererF + RotL64(aCross, 13U)) + 10208452885367546542U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3117030377279160998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17286247690414027870U;
            aOrbiterC = RotL64((aOrbiterC * 4896931759653832095U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3930314320040949141U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7289525252391668404U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15452162299105112187U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3434167955466809185U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17852573095128575663U) ^ RotL64(aNonceWordC, 58U);
            aOrbiterF = RotL64((aOrbiterF * 1485660158767033425U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6137259687928853253U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13992510605237574698U;
            aOrbiterJ = RotL64((aOrbiterJ * 15346263295995333395U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6470556523400123474U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4333255670390099293U;
            aOrbiterB = RotL64((aOrbiterB * 11089933812030082647U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7700424876430257995U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16920736951239453071U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8920407493132380497U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1635071690430295730U) + RotL64(aNonceWordE, 25U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9966700845966398620U;
            aOrbiterG = RotL64((aOrbiterG * 17210048121896546867U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 52U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 53U));
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aPhaseAWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 50U) + aOrbiterJ) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordF, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aNonceWordG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // read from: aWorkLaneB, aWorkLaneA, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordH, 6U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15423U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11734U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 51U)) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11657U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 13454U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 43U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 9133751643283278896U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 8971581804375380408U) + aPhaseAOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 21U)) + 12559650383714566592U) + RotL64(aNonceWordA, 42U);
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 15753206088872859163U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + 7640756270450762350U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 35U)) + 7340073357551376125U) + RotL64(aNonceWordC, 39U);
            aOrbiterC = ((aWandererH + RotL64(aCross, 46U)) + RotL64(aCarry, 51U)) + 5270256573644196046U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3567367996479995928U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11939634537492733738U;
            aOrbiterD = RotL64((aOrbiterD * 5640541900117183639U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7051817732424527120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1730487669951837941U;
            aOrbiterE = RotL64((aOrbiterE * 15191634337956285841U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18009252467909454817U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2361024272031696442U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15902755877642960397U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12243517544704116184U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2576071074148141447U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16846181962302186187U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 636121425116506681U;
            aOrbiterH = RotL64((aOrbiterH * 17075030673338779993U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6887385655828217318U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3705834550934775862U;
            aOrbiterK = RotL64((aOrbiterK * 11275428284929594435U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11165142437077969438U) + RotL64(aNonceWordD, 7U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6426659930331618269U;
            aOrbiterC = RotL64((aOrbiterC * 17170640810530893705U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + RotL64(aNonceWordE, 19U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 49U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, mSource
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordA, 41U)) ^ RotL64(aNonceWordD, 56U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21565U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18141U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordH, 38U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17848U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 17122U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 53U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aScatter, 41U)) + 7896237440058555694U) + RotL64(aNonceWordC, 50U);
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 13U)) + 11870529476037558635U) + aPhaseAOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordG, 59U);
            aOrbiterD = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 9158983227801569448U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 20U)) + RotL64(aCarry, 37U)) + 4710172270996950329U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 35U)) + 14634482800356647630U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 8822207952170610891U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 3U)) + 13755891414028982553U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4555293067488040719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2816805148093762081U;
            aOrbiterD = RotL64((aOrbiterD * 16838149138341713943U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2122631477965135190U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4592922416380416071U) ^ RotL64(aNonceWordH, 29U);
            aOrbiterF = RotL64((aOrbiterF * 11644507904538573165U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7102471666524164715U) + RotL64(aNonceWordA, 11U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17274623547879474204U;
            aOrbiterK = RotL64((aOrbiterK * 5443572270546181789U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 938587316977094680U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18258015823797023523U;
            aOrbiterB = RotL64((aOrbiterB * 6068819567674605919U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5809987756043471595U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5083075160112581620U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3313957222154937503U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5960021727750946496U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5967477320950630150U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 330964768256424655U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6578428711689296132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5601728218197771276U;
            aOrbiterA = RotL64((aOrbiterA * 9552559022315971847U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterA, 28U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 26U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aNonceWordF, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterB) + RotL64(aNonceWordB, 17U)) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordE, 4U) ^ RotL64(aNonceWordB, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26706U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22562U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordA, 58U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27156U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26589U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 35U)) + 2617613537256538553U) + RotL64(aNonceWordC, 23U);
            aOrbiterH = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 16642868916835132715U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 10860291124337073254U) + aPhaseAOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 6432511273906902472U) + RotL64(aNonceWordB, 7U);
            aOrbiterA = (aWandererH + RotL64(aIngress, 19U)) + 7505375005848241910U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 29U)) + 11086616004678821329U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 13U)) + 3298830587569881951U) + aPhaseAOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9775143140064220979U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4147601326580823120U;
            aOrbiterE = RotL64((aOrbiterE * 13462244678782260871U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12245920269898100415U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8391940489176734499U) ^ RotL64(aNonceWordD, 54U);
            aOrbiterD = RotL64((aOrbiterD * 9119606167674098007U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17876893379544668477U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18301882058180370541U;
            aOrbiterK = RotL64((aOrbiterK * 16680384667098921309U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6869225862715140102U) + RotL64(aNonceWordA, 31U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15404118372589259800U;
            aOrbiterH = RotL64((aOrbiterH * 5766851935950389915U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17757381020518233814U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17677969146092374455U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3469432916562405063U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15783378556632870114U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5792858258663697864U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12008981883482080427U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11737803388202260296U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16001927091970715330U;
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 58U);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aNonceWordF, 11U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 20U)) + aOrbiterF) + RotL64(aNonceWordG, 59U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordE, 39U)) ^ RotL64(aNonceWordH, 14U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28361U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 30220U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 20U) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30007U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 28330U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 2571116506511057880U) + RotL64(aNonceWordA, 49U);
            aOrbiterH = ((aWandererI + RotL64(aIngress, 37U)) + 13112435411509707292U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 10403251762787357256U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 8461951095541400405U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 54U)) + 9890793478557463815U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 5U)) + 3030229465991783707U) + RotL64(aNonceWordF, 29U);
            aOrbiterK = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 7273848154043719247U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10681774862516028276U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7105082755586853104U;
            aOrbiterF = RotL64((aOrbiterF * 12217705329504230357U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6588579345319551129U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14616333550242386092U;
            aOrbiterJ = RotL64((aOrbiterJ * 2934574715879306337U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15439666290229654921U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14438730801970761889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14515616787452085729U;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4167853822635132419U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8950982233003320239U;
            aOrbiterE = RotL64((aOrbiterE * 887144270884244907U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12391327853728029953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7100871010552394421U;
            aOrbiterD = RotL64((aOrbiterD * 16552349374101955967U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15381697462381887944U) + RotL64(aNonceWordG, 16U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6801677551341079401U) ^ RotL64(aNonceWordC, 55U);
            aOrbiterH = RotL64((aOrbiterH * 13325954438427340703U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 22U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + RotL64(aNonceWordH, 9U));
            aWandererC = aWandererC + (((RotL64(aScatter, 6U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + aPhaseAWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aNonceWordB, 61U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
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

void TwistExpander_Badminton_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9E7944D32C150749ULL + 0xF1A5C11B11113C55ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9AC039BCDBE9084DULL + 0xBF66E27103DE8745ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB814E5AC98926029ULL + 0xB972F5D94B1417F0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCC036D666A63E831ULL + 0x95576280F793C982ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB0ACDDAF1BDEE53BULL + 0xD340C021959BFFFEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9EA43552020D5D4BULL + 0xCCD9DFB6A3F0E83DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFFFCC6BAFCA27103ULL + 0xF25802F88268F2DCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9B72C92EFEC4C549ULL + 0xCCDF4EC2576D2CDDULL);
    // GSeedRunSeed_B seed_loop_b (start)
    {
        // GSeedRunSeed_B seed_loop_b lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3070U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1640U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 52U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2160U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2443U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 9630214189402543339U) + aPhaseBOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 4072576573737526819U) + RotL64(aNonceWordE, 22U);
            aOrbiterH = (aWandererB + RotL64(aCross, 37U)) + 15994787452709618869U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 6403240137132259482U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 13U)) + 10229266900170507720U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordB, 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5025294577989748989U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16696461238217956883U;
            aOrbiterH = RotL64((aOrbiterH * 15993828976234917577U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9878318855341719119U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16086635438116177346U;
            aOrbiterD = RotL64((aOrbiterD * 5585682357395705671U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12295437783084203730U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7681150419912842402U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7289497379725191451U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2639104034287637448U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 12298170009332243573U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) ^ RotL64(aNonceWordH, 7U);
            aOrbiterI = RotL64((aOrbiterI * 9397919591171238575U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3485932317267669626U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 16569551670038752475U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordG, 45U);
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 14U)) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordC, 55U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererG = aWandererG + (((((RotL64(aCross, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 29U)) + RotL64(aNonceWordF, 9U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordH, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10381U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7299U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordB, 35U)) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10696U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6063U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 5697928251815176134U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 57U)) + 337587740689259575U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 20U)) + 4927686903263973950U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 3742409032569801033U) + RotL64(aNonceWordG, 19U);
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 1608092659172197650U) + aPhaseBOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15848744267145717509U) + RotL64(aNonceWordC, 18U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15300174177963339253U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5771922862677667319U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14162868453323648628U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12020167069983729869U) ^ RotL64(aNonceWordD, 45U);
            aOrbiterF = RotL64((aOrbiterF * 2071080217680099017U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16259538291658723956U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8516686212464112245U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3722184575520553132U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5663609293306386784U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15265344442454471986U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3050323350098829515U;
            aOrbiterA = RotL64((aOrbiterA * 5890624677162388135U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 46U)) + aOrbiterH) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 39U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + RotL64(aNonceWordF, 7U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11676U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11815U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordF, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11944U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12917U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 38U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 42U)) + 4752759164691497960U) + RotL64(aNonceWordC, 34U);
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 51U)) + 12088872623537639782U) + aPhaseBOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordB, 15U);
            aOrbiterF = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 3734943577379734227U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 8854778183012444234U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 16948373492893967275U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7962415690046184385U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1872682375669714454U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 959061892772099785U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7776801806943853566U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16665439117257230732U;
            aOrbiterJ = RotL64((aOrbiterJ * 6866375628213114965U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11088186766134265676U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10850237991780969350U;
            aOrbiterH = RotL64((aOrbiterH * 7547414856143095121U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6464817712131305812U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 244557182884209844U;
            aOrbiterE = RotL64((aOrbiterE * 2394270354887582889U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13261563971157415841U) + RotL64(aNonceWordD, 35U);
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 2323811103717827362U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordG, 25U);
            aOrbiterD = RotL64((aOrbiterD * 11483723582415081925U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterH, 60U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + RotL64(aNonceWordH, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + RotL64(aNonceWordA, 7U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // read from: aOperationLaneA, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordE, 34U)) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21305U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20497U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordG, 12U)) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20725U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 19179U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 24U)) + 3199575576585871314U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 47U)) + 2533378188975571824U) + RotL64(aNonceWordF, 5U);
            aOrbiterH = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 6819782112558312658U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 12690060987724798497U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 7088375139715629606U) + aPhaseBOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordE, 26U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17785618677423695666U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1714999280296491277U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7675674437417383741U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17611338506932491624U) + RotL64(aNonceWordH, 35U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6475727359297421201U;
            aOrbiterD = RotL64((aOrbiterD * 15133348244242438069U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2347744591204119530U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2739317903351401068U;
            aOrbiterF = RotL64((aOrbiterF * 15435029315209475631U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8663535261373274338U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8205245127823536479U;
            aOrbiterC = RotL64((aOrbiterC * 13857005110466856439U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8916510616749754516U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 3944805940148512932U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ RotL64(aNonceWordB, 19U);
            aOrbiterB = RotL64((aOrbiterB * 18082271583211389701U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 40U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aNonceWordC, 25U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + RotL64(aCarry, 53U)) + RotL64(aNonceWordA, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 20U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // read from: aOperationLaneB, aOperationLaneA, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22015U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 22888U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26758U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 25992U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 13U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 6243113109470883144U) + aPhaseBOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 13U);
            aOrbiterC = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 3891552123999605832U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 37U)) + 8758797898587019128U) + RotL64(aNonceWordC, 25U);
            aOrbiterF = ((aWandererD + RotL64(aIngress, 57U)) + 1005891374086408851U) + aPhaseBOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 41U)) + 3713426782180050764U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18358143862391573534U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17504394029693712404U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3391716204095092531U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 5312729289027417014U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordB, 8U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2560873623431186029U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16843728573219210173U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16309322822806704211U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10195513918020652600U) ^ RotL64(aNonceWordE, 35U);
            aOrbiterD = RotL64((aOrbiterD * 14569219741824123715U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2552116263258744287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7732784879810980089U;
            aOrbiterC = RotL64((aOrbiterC * 15041929399477790999U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16499127570665381507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10890036715535519036U;
            aOrbiterF = RotL64((aOrbiterF * 9065115450010475187U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + RotL64(aNonceWordA, 7U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 42U)) + RotL64(aNonceWordG, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneB
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordD, 22U) ^ RotL64(aNonceWordE, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30538U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 30730U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordB, 38U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29594U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 28975U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 4U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 5041131702736607991U) + RotL64(aNonceWordC, 23U);
            aOrbiterG = (aWandererI + RotL64(aCross, 3U)) + 9295010428212681446U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 6235875895358766017U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 2622227802531866918U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 9U);
            aOrbiterD = (aWandererB + RotL64(aCross, 56U)) + 3888894734834524972U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 241682012014701753U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 41U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15758000422451568079U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14719166949665416221U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2061944548396976912U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8177144990755754531U;
            aOrbiterG = RotL64((aOrbiterG * 12702392689484397947U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 554978075608818497U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8700027645880997552U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 10026130047465480902U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ RotL64(aNonceWordF, 12U);
            aOrbiterJ = RotL64((aOrbiterJ * 12417270861933696623U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9785843014096326696U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9998582683258411251U;
            aOrbiterD = RotL64((aOrbiterD * 7197956237569462269U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + RotL64(aCarry, 21U)) + RotL64(aNonceWordA, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 48U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + RotL64(aNonceWordE, 11U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_b (end)
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

void TwistExpander_Badminton_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBFEFE1DCBA65887BULL + 0xF36D001D85B3214EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAD278EBE5D025569ULL + 0xC6E090FC999C2F53ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAC957386AB633075ULL + 0xC66EDA11D19E1F9EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x952CCEDCBD6BAC45ULL + 0xCD9FA7064E2AB2EFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCC63977181EC37FFULL + 0xB5E9D622C46A5E82ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF40B5209217253E1ULL + 0xAF685ACFA576F0B8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF6759F29989C2921ULL + 0xBFB00CD05EFA6DB7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF346F13E9EE7D3ABULL + 0xE0C84FC1E8F79710ULL);
    // GSeedRunSeed_C seed_loop_c (start)
    {
        // GSeedRunSeed_C seed_loop_c lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordD, 14U)) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 8047U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 6028U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordB, 58U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5838U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1095U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 4U)) + 7722279280863371124U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 11584220561732385598U) + RotL64(aNonceWordE, 53U);
            aOrbiterH = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 7834679350105534657U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 23U)) + 11347994382444180879U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 41U)) + 9449903188047063431U) + RotL64(aNonceWordD, 57U);
            aOrbiterG = ((aWandererC + RotL64(aCross, 47U)) + 6516243976652795170U) + aPhaseCOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 13U)) + 8420815253991184777U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 9081386852515170937U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 37U)) + 14375955191735286867U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 880757589768436072U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3349856625725164229U;
            aOrbiterH = RotL64((aOrbiterH * 681514212582331781U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7826309957607577207U) + RotL64(aNonceWordC, 28U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8057435761214313635U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4718430712767038607U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9565237500443303103U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15893066735310588501U;
            aOrbiterE = RotL64((aOrbiterE * 8457633439171452397U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3276844534476430842U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6828644383891274120U;
            aOrbiterD = RotL64((aOrbiterD * 979580351653410157U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2815676923011504251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5030251870850928417U;
            aOrbiterB = RotL64((aOrbiterB * 7075653570570819253U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13464083008377887034U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8994560761846897590U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9892839554658865143U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8398813387154468736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8136429428340910892U;
            aOrbiterI = RotL64((aOrbiterI * 3348811490733577295U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 418587250696862341U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4111667833838312094U;
            aOrbiterJ = RotL64((aOrbiterJ * 860949442143849147U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6075478294190926371U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 2208124955874142264U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordA, 39U);
            aOrbiterF = RotL64((aOrbiterF * 15741988616251072075U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterB, 48U)) + RotL64(aNonceWordF, 55U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA + (((RotL64(aIngress, 38U) + aOrbiterB) + RotL64(aOrbiterH, 34U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + RotL64(aNonceWordG, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordG, 54U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12156U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 15673U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12217U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 13405U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 48U)) + 2177539223979303669U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 43U)) + 3962004686551521471U) + RotL64(aNonceWordG, 5U);
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 8457602312617147662U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 5U)) + 18011802451816510632U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 38U)) + 9046101759168876832U;
            aOrbiterH = ((((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 11135620637431969597U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 15913029940697999701U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 57U)) + 16304193109948135982U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 13208892298820080981U) + aPhaseCOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4182377898949419225U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13970137023071326151U;
            aOrbiterD = RotL64((aOrbiterD * 9075061559681739865U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8402396284835248583U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8859190834060657829U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13552418608113716117U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9760005337757990392U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14108277760135744897U;
            aOrbiterJ = RotL64((aOrbiterJ * 4474681104256093885U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12226316121949012350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3456392186754113960U;
            aOrbiterK = RotL64((aOrbiterK * 8704729827929941215U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5004087958637038973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7176881295123125567U;
            aOrbiterE = RotL64((aOrbiterE * 15272157962928021009U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10889800478505074438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13728832441482547824U;
            aOrbiterB = RotL64((aOrbiterB * 17588477761978646139U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 17345665880706866772U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordF, 14U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 301139993853297566U) ^ RotL64(aNonceWordB, 35U);
            aOrbiterI = RotL64((aOrbiterI * 5812445396758354505U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2061389844760610160U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13631862266139238355U;
            aOrbiterH = RotL64((aOrbiterH * 143613352104722701U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10767186080827509622U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4893486019456886013U;
            aOrbiterF = RotL64((aOrbiterF * 5194746459545610901U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceWordH, 37U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + RotL64(aNonceWordC, 7U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 42U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordA, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18882U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 18795U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 4U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19562U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 20666U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 35U)) + 9774364261626083532U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 41U)) + 18059001521926116420U) + RotL64(aNonceWordH, 13U);
            aOrbiterA = (aWandererG + RotL64(aPrevious, 23U)) + 10615626210406381148U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 10536484278007898620U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + 13320663045139972700U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 48U)) + RotL64(aCarry, 11U)) + 17127001787268166583U) + RotL64(aNonceWordC, 41U);
            aOrbiterF = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 16742574590844166551U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 11U)) + 8347719720758228053U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 57U)) + 13502468705946051986U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3512687886188904904U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 495660316165795934U) ^ RotL64(aNonceWordF, 22U);
            aOrbiterA = RotL64((aOrbiterA * 6724596801190194913U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 5092722552034477356U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15641128019608284015U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3621036395703527059U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15421873776811085458U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17978775513204574125U;
            aOrbiterJ = RotL64((aOrbiterJ * 18359600395119440183U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16617179197537669849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1931805387534012528U;
            aOrbiterG = RotL64((aOrbiterG * 3400139345857733775U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9544923119559308431U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12930999400470173353U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13673733276226249890U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2032263473309124738U;
            aOrbiterE = RotL64((aOrbiterE * 3088728329261360607U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14868502349358414206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10116495537187552321U;
            aOrbiterF = RotL64((aOrbiterF * 1380512121796709469U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5341113995358179244U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8415417980279705731U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8521501372683793821U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2462819265072352463U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7657062767608441931U;
            aOrbiterD = RotL64((aOrbiterD * 15554638801273540163U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aNonceWordG, 37U));
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 12U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordA, 7U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30517U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 26405U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordD, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26161U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25646U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 19U)) + 4848316479321533394U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 6919360256662636195U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + 9897013582181108544U) + RotL64(aNonceWordG, 50U);
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 7319353809896158678U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 47U)) + 2848175435514849859U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 13U)) + 6967780718720437934U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 51U)) + 10143884766603388136U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 24U)) + 8675965006150972051U) + RotL64(aNonceWordE, 53U);
            aOrbiterF = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 16350117755560994281U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17976597517118423760U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1399631141355370237U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16537788276543236833U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3590613762034716792U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5134624314245932157U) ^ RotL64(aNonceWordH, 35U);
            aOrbiterC = RotL64((aOrbiterC * 13077589037975283371U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10082236952942943654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4015535035905433450U;
            aOrbiterB = RotL64((aOrbiterB * 4961808568701908559U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 611474103801573800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5786708483794098001U;
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5201943497363274455U) + RotL64(aNonceWordF, 47U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9282160506938328489U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5368182164239021367U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4932320527498940158U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11576526341731392916U;
            aOrbiterK = RotL64((aOrbiterK * 1712051774729439363U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10790691517638887125U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16280649213607464422U;
            aOrbiterA = RotL64((aOrbiterA * 10756733801499471873U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9553716940667712810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11827518270964003341U;
            aOrbiterF = RotL64((aOrbiterF * 1322489827908132831U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16777463701235809321U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3375489084588454149U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3335010977457647307U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 40U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterC, 52U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 9U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + RotL64(aNonceWordA, 19U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 36U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_c (end)
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

void TwistExpander_Badminton_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE1A0655BC226DEA7ULL + 0x9FFE5D0D78DC2DDEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFB99368CD6B96EE3ULL + 0xA605186FCC59D04BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEC880FC5228D83A7ULL + 0xA3C9688D51E4C61CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAE692084317EF671ULL + 0x91E06279AF61442BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x91BCF5C56B82CE31ULL + 0x827E0B93FC9AD74EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8DDFB9D526692ED9ULL + 0xB0A0EC09F30E81B0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE75BAF2FF1291BB9ULL + 0xC3B1A33520912D85ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC8597F782197BADULL + 0xBB0DD1890CB53F44ULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aOperationLaneA, aOperationLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3586U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 2736U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 44U) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3056U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2595U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 6381335981879993247U;
            aOrbiterG = (aWandererI + RotL64(aCross, 37U)) + 15595429101600023172U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 21U)) + 5449234297249826461U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 60U)) + 11213734849329731168U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 16438473952464514248U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 5U)) + 7357872882115186976U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 39U)) + 394402075160738643U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 10U)) + 11112941985410283532U) + RotL64(aNonceWordH, 29U);
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + 14955125011182736212U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 14770727009821304070U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 29U)) + 11286366598129204910U) + RotL64(aNonceWordE, 50U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7358400908565425780U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15635109923749114761U;
            aOrbiterA = RotL64((aOrbiterA * 12415152149408700329U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13826842523738623579U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1072811298828325231U;
            aOrbiterE = RotL64((aOrbiterE * 9662800288646215083U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4017334196009350776U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8812213572751410831U;
            aOrbiterK = RotL64((aOrbiterK * 12744171921566782795U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6723457786170634403U) + RotL64(aNonceWordF, 61U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9785583533999417673U;
            aOrbiterF = RotL64((aOrbiterF * 7776915427605471097U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10265132640322153964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8435670887514808087U;
            aOrbiterC = RotL64((aOrbiterC * 2706263045620662131U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4303823386961718326U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4214384238167491037U;
            aOrbiterJ = RotL64((aOrbiterJ * 8490707334221154005U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8740835037840799136U) + RotL64(aNonceWordC, 3U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5988815405391206280U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17838555472135715929U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15539461383052981747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3743772525784217714U;
            aOrbiterG = RotL64((aOrbiterG * 6352086797545969187U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16283379107488103386U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2677085736169305444U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5034373635279045467U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16961352880910247821U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7475807604144212417U;
            aOrbiterD = RotL64((aOrbiterD * 5016987646810330727U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10187131329357526073U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6381335981879993247U;
            aOrbiterI = RotL64((aOrbiterI * 15277168748093112841U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterC, 53U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + RotL64(aNonceWordB, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterB, 42U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + RotL64(aNonceWordD, 47U));
            aWandererG = aWandererG + (((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 10U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10879U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 6775U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 42U) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9720U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 7755U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 29U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 9654059367478508868U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 18U);
            aOrbiterK = (aWandererH + RotL64(aIngress, 50U)) + 6473006635864677427U;
            aOrbiterB = (aWandererI + RotL64(aCross, 41U)) + 6944184481315853243U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 53U)) + 4061496421939102306U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 5U)) + 15791809275719085463U;
            aOrbiterH = (aWandererC + RotL64(aCross, 11U)) + 14050798802646323055U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 12072905924741758266U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 17639076509231343896U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 12195388285571234715U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 48U)) + 4325404419499496529U) + RotL64(aNonceWordD, 19U);
            aOrbiterJ = (aWandererD + RotL64(aIngress, 57U)) + 5910567888204238382U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13092940059929942699U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13381962590820308761U;
            aOrbiterB = RotL64((aOrbiterB * 6345904465930943295U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15622862439323440527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14027151901132249793U;
            aOrbiterK = RotL64((aOrbiterK * 2273573821630510087U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4584410023907605157U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15763755180625487157U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17023059745666559199U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5298529579288492971U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2483562793328357721U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2870152867331654736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12017191100173748848U;
            aOrbiterG = RotL64((aOrbiterG * 9958191466506480519U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15899529176182436062U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16482713846343388735U;
            aOrbiterD = RotL64((aOrbiterD * 719465695044265601U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12943393531812774449U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9881108254540483225U;
            aOrbiterA = RotL64((aOrbiterA * 8011108108007885059U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3532054586199716750U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7142230313294797435U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14154176174768868421U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 733958394016131587U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2060800099014517137U;
            aOrbiterF = RotL64((aOrbiterF * 12988885554457108631U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 2278498033811574812U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 27U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15342071118593803929U) ^ RotL64(aNonceWordE, 51U);
            aOrbiterC = RotL64((aOrbiterC * 7842196613533603835U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12987212219357101955U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9654059367478508868U;
            aOrbiterJ = RotL64((aOrbiterJ * 11796100167917742307U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 52U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 17U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 46U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aNonceWordC, 45U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 58U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererI = aWandererI + ((((RotL64(aCross, 40U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + aPhaseDWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 28U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 18U) ^ RotL64(aNonceWordB, 47U)) ^ RotL64(aNonceWordF, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16329U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 14940U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordE, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15249U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 11410U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 44U)) + 8402620908307642697U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 27U)) + 11347672014525086047U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 37U)) + 2816462912503401876U) + RotL64(aNonceWordE, 37U);
            aOrbiterA = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 6940159795470696093U) + RotL64(aNonceWordH, 4U);
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 9134692490095883851U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 19U)) + 4999455497008026526U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 4U)) + 5992451460350651332U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 29U)) + 3417087346651371924U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 57U)) + 3612773820086198270U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 463398077083428570U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 39U)) + 11249391303705089012U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17027535139825739501U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 568131384979596481U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5683451044852895957U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4793712537158004047U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10415170179135963622U) ^ RotL64(aNonceWordA, 21U);
            aOrbiterD = RotL64((aOrbiterD * 13729564030210361415U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2391473979460065630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4240058362680064261U;
            aOrbiterB = RotL64((aOrbiterB * 12375884373396400889U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9963957011090031698U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3325305624067445525U;
            aOrbiterE = RotL64((aOrbiterE * 3128542681461806309U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 2094945647665114693U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordF, 59U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10703615640774042674U;
            aOrbiterC = RotL64((aOrbiterC * 12641986098450423751U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3768738815518590289U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15021301790376706827U;
            aOrbiterF = RotL64((aOrbiterF * 14445850924223550339U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10571246886181608316U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5130325144599151793U;
            aOrbiterK = RotL64((aOrbiterK * 3185251943547657467U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8617523421720966373U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16574597770835250074U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1759209403428937799U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17474733286551120355U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17914672092861237776U;
            aOrbiterG = RotL64((aOrbiterG * 13657291990878792267U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12856557371623447773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1636296609747335898U;
            aOrbiterH = RotL64((aOrbiterH * 9286345529656087313U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12588848560509679821U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8402620908307642697U;
            aOrbiterJ = RotL64((aOrbiterJ * 2269772223506258147U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aNonceWordG, 55U));
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterE, 56U));
            aWandererC = aWandererC + (((((RotL64(aCross, 41U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + RotL64(aNonceWordC, 11U)) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 24U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // read from: aWorkLaneA, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordG, 44U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19260U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16686U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordB, 18U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19072U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19714U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 43U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 29U)) + 8506388683755208267U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 2179323259055019735U) + RotL64(aNonceWordD, 16U);
            aOrbiterB = (aWandererA + RotL64(aScatter, 39U)) + 3345902531140983016U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 5U)) + 17456139311481306584U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 3U)) + 14587864088462311164U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 19U)) + 13178947246650647057U) + RotL64(aNonceWordF, 47U);
            aOrbiterG = ((aWandererJ + RotL64(aCross, 23U)) + 12866578138946916962U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 53U)) + 13098524333655118173U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 15451329483787541982U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 21U)) + 9494299579678389385U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 50U)) + 15581954810375490643U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4487042505730624892U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2774455928791636186U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15847933919136777451U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12435319582397755819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10077180055177766823U;
            aOrbiterE = RotL64((aOrbiterE * 3924363471701748703U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10391963896910956455U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6149237416725301794U;
            aOrbiterF = RotL64((aOrbiterF * 10115917698918612823U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15673402771629639978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14729117178956592426U;
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14492001279368870240U) + RotL64(aNonceWordH, 29U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6278248084483259952U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16731228350971263873U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15727518866499740411U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8652631010810965473U;
            aOrbiterJ = RotL64((aOrbiterJ * 9508484121620912715U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13660890300188313775U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14699253534935936300U;
            aOrbiterA = RotL64((aOrbiterA * 3978135617259934869U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1621689916308271346U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5651399428852950385U;
            aOrbiterH = RotL64((aOrbiterH * 12220143634120124133U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9833573729127477238U) + RotL64(aNonceWordB, 21U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11171647423058940388U;
            aOrbiterD = RotL64((aOrbiterD * 9692915620701425697U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10346908196429120039U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11972183669378621435U;
            aOrbiterC = RotL64((aOrbiterC * 12364429258926549335U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11063215816236490488U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8506388683755208267U;
            aOrbiterI = RotL64((aOrbiterI * 11514304191652750181U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 60U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterG, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + RotL64(aNonceWordC, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 37U));
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterJ, 52U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordG, 28U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22396U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23961U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24152U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 27211U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + 8367680518550579791U) + RotL64(aNonceWordE, 38U);
            aOrbiterC = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 11491674725611181241U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 46U)) + 16673861720782164214U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 9786610124108350855U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 37U)) + 5745080601557577637U;
            aOrbiterG = (aWandererA + RotL64(aCross, 35U)) + 1959402215131684684U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 50U)) + 6121650036079196522U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 13U)) + 12016309761037342392U) + RotL64(aNonceWordH, 11U);
            aOrbiterD = ((aWandererD + RotL64(aIngress, 53U)) + 5986936646177049603U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 27U)) + 1000367700904043468U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 17425288243569101032U) + aPhaseDOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4856917474950325209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16312111093223166419U;
            aOrbiterA = RotL64((aOrbiterA * 11046477664487805241U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 456110002032422270U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11393724374787795662U;
            aOrbiterG = RotL64((aOrbiterG * 1176984359123668389U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8378176867715697176U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8086186452345234815U) ^ RotL64(aNonceWordD, 19U);
            aOrbiterB = RotL64((aOrbiterB * 8450438271765985235U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8470349167474173245U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2528229938740192694U;
            aOrbiterH = RotL64((aOrbiterH * 8717790851266520943U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13247168811545753141U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8745293957516815264U;
            aOrbiterK = RotL64((aOrbiterK * 14270617180621072619U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6165915500564961987U) + RotL64(aNonceWordF, 51U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12015407798844173213U;
            aOrbiterJ = RotL64((aOrbiterJ * 3913451986559154153U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 545006684939922156U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16366753936267185001U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6495185976430013201U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3097605623436091728U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15950167830259022926U;
            aOrbiterD = RotL64((aOrbiterD * 4415538963984293323U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8356327899232213426U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10183421678251169945U;
            aOrbiterF = RotL64((aOrbiterF * 9474380650337109299U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16327340177970834683U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7086901180933495535U;
            aOrbiterC = RotL64((aOrbiterC * 1276521829484494857U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13421211370092080006U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8367680518550579791U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12256662446176946163U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 24U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 50U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + RotL64(aNonceWordB, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 42U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aNonceWordA, 9U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterB, 38U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneB
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordC, 36U)) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29578U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 29956U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordG, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29787U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32166U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 34U)) + 9914837590440975587U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 21U)) + 6706125076401958051U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 16570817772679258409U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 6843705658115186948U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 16099930446791572351U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 47U)) + 5420550009556030459U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 41U)) + 5729549069420177477U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 27U)) + 15590601126188675834U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 12U)) + 13044027390998620029U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordF, 49U);
            aOrbiterH = (((aWandererA + RotL64(aCross, 39U)) + 11068338135659636772U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordA, 11U);
            aOrbiterJ = (aWandererB + RotL64(aScatter, 53U)) + 6584988841809544332U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8516813219883915404U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10647314042912492785U;
            aOrbiterD = RotL64((aOrbiterD * 15559481057047148785U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 201691689889605304U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15512161798401184003U;
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3883760518944464145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12019138626550801486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13030350224959652248U;
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2643807255422544248U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4127143302485631794U;
            aOrbiterF = RotL64((aOrbiterF * 5441038881111578487U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14602951930809633069U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4555737199162278494U) ^ RotL64(aNonceWordC, 24U);
            aOrbiterK = RotL64((aOrbiterK * 12415825635220991865U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6343143902997169834U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10404783711336491985U;
            aOrbiterH = RotL64((aOrbiterH * 6235474458879439079U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7406959231434835393U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6684368109277850196U;
            aOrbiterJ = RotL64((aOrbiterJ * 8760360417572331159U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4835889355927954728U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7917682889852676712U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterC = RotL64((aOrbiterC * 9045350756570117327U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10268055422944417055U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5563744562922937643U;
            aOrbiterI = RotL64((aOrbiterI * 12442484191329795173U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17244672945880141679U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9914837590440975587U;
            aOrbiterB = RotL64((aOrbiterB * 12269340309792850489U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterA, 38U)) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + RotL64(aNonceWordB, 39U));
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 30U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aNonceWordD, 15U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[aIndex] = aIngress;
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

void TwistExpander_Badminton_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9F17C6E27B28BC7BULL + 0xB7E434B1502D1DAFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBEE5DADED11BC5CDULL + 0xBF324F8CDE499DE0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAEF0451EA1CA531BULL + 0x8C9CE67BFA097B74ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8E98B64B9671FD01ULL + 0xFB0B00735C021ADEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF6DDE6B1C59E8EC1ULL + 0xB4F1ED58A8A52C09ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8C74A7D0037449A7ULL + 0xCC0609A01393C0B8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEE473E02D8FD0B81ULL + 0xFB425CA0B32DB0CCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x828D23789081D0FFULL + 0xD584EA98C4858CE9ULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneA, aExpandLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 145U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2686U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3903U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1167U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 60U)) + 12583180859826261500U;
            aOrbiterE = (aWandererI + RotL64(aCross, 3U)) + 9067093488553721468U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + 12173106198862881754U) + RotL64(aNonceWordD, 11U);
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + 11333491014394592654U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 3511883526940919554U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 36U)) + RotL64(aCarry, 27U)) + 7416810692106273044U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 41U)) + 8341174972619784110U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 57U)) + 2220852854836962979U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 21U)) + 8090781422229383825U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + 2338801236599102223U) + RotL64(aNonceWordG, 3U);
            aOrbiterI = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 12484514711848308104U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13684861340589131816U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12796636819991873058U;
            aOrbiterB = RotL64((aOrbiterB * 5533508014234835669U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7634198650894837690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10240326122201201762U;
            aOrbiterH = RotL64((aOrbiterH * 8758703497719125901U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4162814763739453934U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2766504649149048469U;
            aOrbiterD = RotL64((aOrbiterD * 16731843453895178671U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11051393030148769655U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17687055068651386665U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1042927176246229537U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3353615315436983420U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5971640796220306310U) ^ RotL64(aNonceWordC, 27U);
            aOrbiterC = RotL64((aOrbiterC * 15804313508835034807U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12299773092762384765U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7435804907797063411U;
            aOrbiterF = RotL64((aOrbiterF * 9848139805288165965U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8735783937125735699U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11903126115475835615U;
            aOrbiterI = RotL64((aOrbiterI * 16942088822124940265U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4427166023462475475U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6011733469446008137U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17298067225913923517U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18341473946127677319U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5423774915753911947U) ^ RotL64(aNonceWordF, 42U);
            aOrbiterG = RotL64((aOrbiterG * 14985099502923458523U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2384393657884193014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2650593524388493958U;
            aOrbiterJ = RotL64((aOrbiterJ * 892985816665547945U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15991261431384033176U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12583180859826261500U;
            aOrbiterK = RotL64((aOrbiterK * 14394838775646875599U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 14U) + RotL64(aOrbiterE, 26U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + RotL64(aNonceWordB, 31U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + RotL64(aNonceWordH, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 52U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // read from: aExpandLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordG, 23U)) ^ RotL64(aNonceWordB, 12U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10529U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6230U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9665U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5889U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 13U)) + 8020711767807230555U;
            aOrbiterA = (aWandererB + RotL64(aCross, 5U)) + 15368693777246341570U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 57U)) + 5117523734225562401U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 21U)) + 13155269151097507808U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 9879303753623578272U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 41U)) + 1165799257173794826U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 930641942062732091U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 29U)) + 11330571332221123153U) + RotL64(aNonceWordF, 11U);
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 3U)) + 2862963158282518899U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 42U)) + 6019186399361476659U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 23U)) + 1924419843785161958U) + RotL64(aNonceWordH, 45U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12618629043591380461U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9334176504266512405U;
            aOrbiterJ = RotL64((aOrbiterJ * 18239109235362925739U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16829692481030013551U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5604784396927022709U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2833893610883508353U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16124030106598549644U) + RotL64(aNonceWordA, 23U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16571659812830230677U;
            aOrbiterD = RotL64((aOrbiterD * 4668250364992383549U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15171089673591843703U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2826755560293849328U;
            aOrbiterG = RotL64((aOrbiterG * 9397017963457655287U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9976785768283589291U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11845100564714691809U;
            aOrbiterC = RotL64((aOrbiterC * 4935139932585319251U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7318560453127859950U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3039196878830506712U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3140508261330698717U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8850992055588337843U) + RotL64(aNonceWordB, 55U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4219373528176869146U;
            aOrbiterK = RotL64((aOrbiterK * 1310964742529956743U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1341474458715938799U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15937557372891732898U;
            aOrbiterE = RotL64((aOrbiterE * 11437307017920192915U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7512741986101399499U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4304636545688233645U;
            aOrbiterB = RotL64((aOrbiterB * 1948671766238131953U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11460886069492094055U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2019818350627642126U;
            aOrbiterF = RotL64((aOrbiterF * 9802784763505584769U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3190374588085859096U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8020711767807230555U;
            aOrbiterH = RotL64((aOrbiterH * 12055760672321414929U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aNonceWordC, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterB, 44U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aNonceWordD, 40U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneD, aWorkLaneC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordD, 14U) ^ RotL64(aNonceWordC, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11931U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 13989U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordF, 24U)) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12548U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 13801U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 17912271996338180948U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 50U)) + RotL64(aCarry, 43U)) + 13259276608841847058U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 39U)) + 16225936008657276089U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterH = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 2243058962151834071U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 47U)) + 10637439274127347861U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 23U)) + 15312219216405992627U) + RotL64(aNonceWordF, 14U);
            aOrbiterJ = (aWandererA + RotL64(aScatter, 27U)) + 2393933972129878613U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 19U)) + 4327069337247976513U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 10U)) + 8307656353434167837U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 37U)) + 17299145556933889336U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 13U)) + 14458100581172798164U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6410095654927998067U) + RotL64(aNonceWordB, 57U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6168964796264687686U;
            aOrbiterD = RotL64((aOrbiterD * 16218071040190475953U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3667999465041020730U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16021552859323602007U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6427266472526362663U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12941668202330045095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4222032891850449934U;
            aOrbiterA = RotL64((aOrbiterA * 17292856787431308097U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1346342592002730785U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16860611785008118820U;
            aOrbiterI = RotL64((aOrbiterI * 384963420804756607U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3193572711804730241U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5866881282680588589U;
            aOrbiterF = RotL64((aOrbiterF * 9226331800853634597U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17180332731328479126U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10222097519535882241U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9422887302872778795U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8863502179821584859U) + RotL64(aNonceWordC, 23U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14872318155712512999U;
            aOrbiterG = RotL64((aOrbiterG * 11830641277356873233U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16478790641892781150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8414944141232294781U;
            aOrbiterH = RotL64((aOrbiterH * 17443775794621154023U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13204056527590476037U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15084952142545813228U;
            aOrbiterJ = RotL64((aOrbiterJ * 17183888602469193015U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13051035678904490854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17565188004293304987U;
            aOrbiterB = RotL64((aOrbiterB * 12785271107667631897U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 814245676602237400U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17912271996338180948U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14557769257469623169U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + (((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 30U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aNonceWordD, 7U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + RotL64(aNonceWordG, 31U));
            aWandererF = aWandererF + ((RotL64(aCross, 54U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 20U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // read from: aOperationLaneA, aExpandLaneB, aExpandLaneA, aWorkLaneD
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19049U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 18225U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordC, 40U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21031U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20025U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 48U)) + RotL64(aCarry, 35U)) + 3973833383430652211U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 3U)) + 5760227042747169187U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 4923009065139227286U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 1477807307009107590U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + 5707194514329007301U) + RotL64(aNonceWordC, 29U);
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 35U)) + 5340439728375269724U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 43U)) + 17080457898946572387U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 27U)) + 281559150259472813U) + RotL64(aNonceWordE, 25U);
            aOrbiterK = (aWandererF + RotL64(aScatter, 54U)) + 16160633048230910560U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 11U)) + 9003989610509592121U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 39U)) + 10579322462808454333U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15059383289528723069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10417647757852880956U;
            aOrbiterB = RotL64((aOrbiterB * 1457919230286043137U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14484665027393813330U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12344463053485837974U;
            aOrbiterC = RotL64((aOrbiterC * 5762654194001525041U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5826453246659297805U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12547902286376986223U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2982850000322672789U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9637855144278126174U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2132744427444501938U;
            aOrbiterE = RotL64((aOrbiterE * 5911587798564836199U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9248933938130311231U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13274297928717090383U;
            aOrbiterG = RotL64((aOrbiterG * 2901398809555237563U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3690262236918560930U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3626005326410800344U;
            aOrbiterK = RotL64((aOrbiterK * 13030443356669355355U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10801089744186148218U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5446653082176311031U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4594267575901248321U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3205541585889107366U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 4532327942368884436U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordF, 34U);
            aOrbiterI = RotL64((aOrbiterI * 16287094987689326229U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9755333481079721632U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 722154154363571049U) ^ RotL64(aNonceWordG, 13U);
            aOrbiterA = RotL64((aOrbiterA * 11002432494248958957U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8071668483354405205U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8770466248803121315U;
            aOrbiterF = RotL64((aOrbiterF * 12780438190628717807U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1999251593502332271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3973833383430652211U;
            aOrbiterH = RotL64((aOrbiterH * 5325244982474631559U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterC, 56U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterK, 37U)) + aPhaseEWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aNonceWordH, 41U));
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 34U));
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aNonceWordB, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordE, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22674U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22694U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23441U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23261U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 16424657151168221875U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 17150123681886380361U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 16041993588694572757U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 24U)) + 9871185846434828537U) + RotL64(aNonceWordD, 51U);
            aOrbiterB = (aWandererF + RotL64(aPrevious, 41U)) + 11227236398354430757U;
            aOrbiterI = (aWandererA + RotL64(aCross, 35U)) + 5399325217402192631U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 9248828789282890454U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 11U)) + 9041370494203701062U) + RotL64(aNonceWordE, 24U);
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 3U)) + 14944424084524970764U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 52U)) + 5481938174456671041U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 39U)) + 14783648629543752715U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12355573914530445723U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9863991559011968318U;
            aOrbiterD = RotL64((aOrbiterD * 8495251211794343179U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16149688605937250965U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterI = RotL64((aOrbiterI * 12199934305374582599U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 8076098639554567792U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 5U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11155119311895580013U;
            aOrbiterK = RotL64((aOrbiterK * 1495180896564818647U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6847612160595917702U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16094377920388017367U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4875801863643206333U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13584719866672696684U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13446209321646234607U;
            aOrbiterG = RotL64((aOrbiterG * 9945349065094781529U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15829806645369560988U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12573767256739062550U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5649504278826069077U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3850030870300393809U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11857593987748189858U;
            aOrbiterJ = RotL64((aOrbiterJ * 15942863910931814193U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5505918410521728373U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12949653497121247860U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterC = RotL64((aOrbiterC * 90944913639560027U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2448323375614082955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4386059032042654583U;
            aOrbiterF = RotL64((aOrbiterF * 11730132905525317201U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 108129028178045299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18292666533864994149U;
            aOrbiterA = RotL64((aOrbiterA * 2599590507178673531U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10771402979550786312U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16424657151168221875U;
            aOrbiterB = RotL64((aOrbiterB * 6255743082177474607U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 60U));
            aWandererE = aWandererE + ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + RotL64(aNonceWordF, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + RotL64(aNonceWordG, 49U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 20U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneB
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordC, 58U)) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27495U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29944U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29600U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 28597U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 21U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 39U)) + 2571116506511057880U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 13112435411509707292U) + RotL64(aNonceWordF, 51U);
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 10403251762787357256U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 43U)) + 8461951095541400405U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 50U)) + RotL64(aCarry, 35U)) + 9890793478557463815U) + aPhaseEOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 21U)) + 3030229465991783707U) + RotL64(aNonceWordC, 48U);
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 7273848154043719247U;
            aOrbiterE = (aWandererF + RotL64(aCross, 57U)) + 10681774862516028276U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 52U)) + 7105082755586853104U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 37U)) + 6588579345319551129U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 47U)) + 14616333550242386092U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15439666290229654921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3360304356760164799U;
            aOrbiterH = RotL64((aOrbiterH * 5164191920584106237U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14438730801970761889U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14515616787452085729U;
            aOrbiterB = RotL64((aOrbiterB * 2041601927968559821U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4167853822635132419U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8950982233003320239U;
            aOrbiterC = RotL64((aOrbiterC * 887144270884244907U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12391327853728029953U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7100871010552394421U;
            aOrbiterJ = RotL64((aOrbiterJ * 16552349374101955967U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15381697462381887944U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6801677551341079401U;
            aOrbiterE = RotL64((aOrbiterE * 13325954438427340703U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 947011315719204867U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6356920162398333481U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5566721941682667419U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8910262020598577378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8778455415977526457U;
            aOrbiterG = RotL64((aOrbiterG * 4092470497616637283U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5585696961453127223U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9670655481681494412U) ^ RotL64(aNonceWordE, 29U);
            aOrbiterF = RotL64((aOrbiterF * 7863197168965036383U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10713004007087085729U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4036355047492922339U;
            aOrbiterI = RotL64((aOrbiterI * 6923922258047667173U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14580156873863533497U) + RotL64(aNonceWordG, 25U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7049502932205025182U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8665428649262370727U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12707521269341941677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2571116506511057880U;
            aOrbiterK = RotL64((aOrbiterK * 2388236789245943699U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 58U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordA, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 14U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aNonceWordH, 19U)) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 20U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 18U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneD[aIndex] = aIngress;
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

void TwistExpander_Badminton_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDC918A832F9A8BA3ULL + 0xD810CDF80FEDC83FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCFF92FAA89C13BEDULL + 0xEF2DD9186DDCC2BBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x98090309B8407DD9ULL + 0xAE546623F7B660D3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB858A874C04A0117ULL + 0xF9BE7A210301CD6FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDAB16EA8F3952BD1ULL + 0xD511D7B94FFD0076ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBA5812A7D64A505BULL + 0xCF0BE5AA600BD793ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD05B5564BF2A1135ULL + 0xB920329AF00F4952ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB66EE51CA3FF27B7ULL + 0xFF55F15F4AD1CB26ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 56U) ^ RotL64(aNonceWordF, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5275U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 4900U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordG, 52U)) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3442U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1424U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 50U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 13687218104610230596U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 6841550124960692709U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 58U)) + 17418968668458764131U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 8303537912696948204U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + 12376614417285936537U) + RotL64(aNonceWordF, 41U);
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 14215749063579232654U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 21U)) + 4111736931433665347U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 5U)) + 11250375934571631522U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 13U)) + 5367367837773331275U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + 15514089192382674434U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 44U)) + 1475991716685034960U) + RotL64(aNonceWordB, 8U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5531622777788629748U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8363822215908303335U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17850203366840994883U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3741256932685720414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11634667238062155772U;
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18180546911210417155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5123234656838556335U;
            aOrbiterH = RotL64((aOrbiterH * 15362857462853398025U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11215734271189250284U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16863747802158398092U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterI = RotL64((aOrbiterI * 1828035970246160023U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 9859050606636646323U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordD, 27U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9331300036643654675U;
            aOrbiterD = RotL64((aOrbiterD * 2502263410556166281U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15028845665427209759U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8916444839488901676U;
            aOrbiterJ = RotL64((aOrbiterJ * 6646561894156038791U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8024631140949068570U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1116378858490660031U;
            aOrbiterE = RotL64((aOrbiterE * 4247798531910227367U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5066486214537899212U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9346312092322423057U;
            aOrbiterG = RotL64((aOrbiterG * 13443190089768875191U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11651011617027950122U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11308862427412671711U;
            aOrbiterA = RotL64((aOrbiterA * 12167147966934334703U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3850136281462840708U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13461307727665667424U;
            aOrbiterB = RotL64((aOrbiterB * 10788040812090673421U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17824744996404571928U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13687218104610230596U;
            aOrbiterC = RotL64((aOrbiterC * 325803029547254631U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 54U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aScatter, 36U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + RotL64(aNonceWordG, 23U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordE, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 58U));
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordF, 26U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7573U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9683U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordB, 42U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8831U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 5785U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 5697928251815176134U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 21U)) + 337587740689259575U) + RotL64(aNonceWordG, 31U);
            aOrbiterG = (aWandererK + RotL64(aIngress, 10U)) + 4927686903263973950U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 3742409032569801033U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 1608092659172197650U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 37U)) + 15848744267145717509U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 23U)) + 15300174177963339253U) + RotL64(aNonceWordH, 41U);
            aOrbiterB = (aWandererG + RotL64(aCross, 35U)) + 14162868453323648628U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 12020167069983729869U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 5U)) + 16259538291658723956U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 54U)) + 8516686212464112245U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3722184575520553132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15265344442454471986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3050323350098829515U;
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1093356813820599238U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15167726103772238440U;
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15170797965325981472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14710892030473425181U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 397194787697553904U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14368930300818752833U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1273724124862533034U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13018397560392545616U) ^ RotL64(aNonceWordA, 4U);
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9638716186445643730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7255587739807843785U;
            aOrbiterC = RotL64((aOrbiterC * 6055682981584011189U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9272350563697399628U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1040729335295009339U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12128124729613601747U) + RotL64(aNonceWordC, 49U);
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2285238815562202219U;
            aOrbiterB = RotL64((aOrbiterB * 15398840993074390573U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6339113298619163493U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5911895708485037040U;
            aOrbiterA = RotL64((aOrbiterA * 3271006139923200439U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7601399508218901328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5697928251815176134U;
            aOrbiterE = RotL64((aOrbiterE * 8184257916861355735U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 60U)) + RotL64(aNonceWordD, 59U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererA = aWandererA + (((RotL64(aCross, 38U) + RotL64(aOrbiterG, 37U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 26U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 40U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + RotL64(aNonceWordE, 7U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15370U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 12920U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordD, 38U)) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13719U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 13308U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 1142447269198373880U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 18U)) + 10581460640040336191U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 14703062773878202900U) + RotL64(aNonceWordF, 53U);
            aOrbiterE = (aWandererJ + RotL64(aCross, 57U)) + 15737525756286914746U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 35U)) + 16178774478273186999U) + RotL64(aNonceWordA, 3U);
            aOrbiterD = (aWandererE + RotL64(aScatter, 51U)) + 2514897053906809160U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 13702496607592508464U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 37U)) + 18030885275418337965U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 13U)) + 5241783876161655984U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 11U)) + 2807052676283587925U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 60U)) + 8022804576763271327U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15597099852232205860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1538435607932096400U;
            aOrbiterH = RotL64((aOrbiterH * 7900752511710516981U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11147868774413615365U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9325213746830411568U;
            aOrbiterD = RotL64((aOrbiterD * 561819005818948769U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13792300423550555634U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3134856508983945719U;
            aOrbiterF = RotL64((aOrbiterF * 4271845067763664863U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8654966018053784882U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8937113935476779267U) ^ RotL64(aNonceWordH, 23U);
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4135676350355234788U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11407912615743682678U;
            aOrbiterK = RotL64((aOrbiterK * 2773506587480714695U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10966950663872392059U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6686634993700944582U;
            aOrbiterJ = RotL64((aOrbiterJ * 2509459942163678241U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14154407529749257990U) + RotL64(aNonceWordE, 26U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18054640398549782388U;
            aOrbiterG = RotL64((aOrbiterG * 7830759861389060149U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14623473030642960240U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1857945571104460086U;
            aOrbiterE = RotL64((aOrbiterE * 18039903315045620079U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17650774450811065797U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9458168381246672881U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3452665113988737563U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16604923466236483242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12447748535184711684U;
            aOrbiterC = RotL64((aOrbiterC * 5982708155382249061U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9589720286549780720U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1142447269198373880U;
            aOrbiterI = RotL64((aOrbiterI * 8176719948031280789U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 54U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 40U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + ((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererK = aWandererK + (((((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 41U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 38U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + RotL64(aCarry, 29U)) + RotL64(aNonceWordC, 7U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordB, 26U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16693U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 18318U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordD, 42U)) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16949U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20307U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 24U)) + RotL64(aCarry, 5U)) + 5171470532667965920U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 43U)) + 750549462358682403U) + RotL64(aNonceWordC, 45U);
            aOrbiterI = (aWandererD + RotL64(aScatter, 21U)) + 3325689257577120525U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 18031575461559790826U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 47U)) + 13874739537012288677U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 27U)) + 4250029868785016865U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 18U);
            aOrbiterC = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 8211158803112611161U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 13U)) + 1083939790236786027U;
            aOrbiterA = (aWandererG + RotL64(aCross, 11U)) + 3446525462376962464U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 5U)) + 6973817815000417325U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 18U)) + 15230876489676945543U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9359727659738755880U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 8775170107816327654U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ RotL64(aNonceWordE, 17U);
            aOrbiterI = RotL64((aOrbiterI * 6910680458261008653U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11958941755525038545U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16966819714283167348U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16363457661846050749U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14556087985619763243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17915047508377045221U;
            aOrbiterH = RotL64((aOrbiterH * 6727635453185130109U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8578745677485367222U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 7002181668717618866U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordF, 47U);
            aOrbiterC = RotL64((aOrbiterC * 12329703532414955235U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3569939503066735457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2956247934282522184U;
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4285180013402474041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5976239869535619811U;
            aOrbiterA = RotL64((aOrbiterA * 3458095419039067465U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2424524955161695463U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6849595426583763537U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12727902040238318101U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11414890686374886716U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5668287266836153445U;
            aOrbiterF = RotL64((aOrbiterF * 8011885266143066285U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9976985606260445887U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9223940029500676834U;
            aOrbiterB = RotL64((aOrbiterB * 8508023992488499955U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4480967907876921958U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5132766654502526597U;
            aOrbiterG = RotL64((aOrbiterG * 321625389942019245U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12921555132452983464U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5171470532667965920U;
            aOrbiterD = RotL64((aOrbiterD * 9710487797420618879U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 54U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 18U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + RotL64(aNonceWordA, 55U));
            aWandererC = aWandererC + ((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordD, 15U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 46U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24011U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22811U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordC, 54U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26267U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 25976U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 28U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 22U)) + 3105313968748067810U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 9977249451119627064U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 13U)) + 17941392803495349366U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 37U)) + 4279533326705471133U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 11U)) + 13983828966811580039U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 3U)) + 3983490984234810378U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 56U)) + 308786542215259956U) + RotL64(aNonceWordH, 41U);
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 29U)) + 8443607695364427037U) + RotL64(aNonceWordC, 29U);
            aOrbiterJ = (aWandererH + RotL64(aScatter, 27U)) + 14939626441464340668U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 9350693577306121110U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 1717071159396961752U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15911765265202100610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14898546272333182767U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2674900543810733067U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3560903518513465868U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5367062725726860234U;
            aOrbiterG = RotL64((aOrbiterG * 8521908836601319553U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15233321480618877327U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9288449812290126074U) ^ RotL64(aNonceWordG, 3U);
            aOrbiterK = RotL64((aOrbiterK * 6815298520404038519U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5504840529511585676U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6825598386801620046U;
            aOrbiterC = RotL64((aOrbiterC * 11666542445846250077U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6433024450721339470U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 97934156644929458U;
            aOrbiterH = RotL64((aOrbiterH * 8630530773006923215U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3260053604798744515U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16539416623243059076U;
            aOrbiterE = RotL64((aOrbiterE * 12199577351166064503U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9814290051339038920U) + RotL64(aNonceWordE, 35U);
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13280156404507444041U;
            aOrbiterD = RotL64((aOrbiterD * 15269010043398910061U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11853942590993546833U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13207869904312989977U;
            aOrbiterJ = RotL64((aOrbiterJ * 15503461937625795969U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14536032167989376750U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3693282775047432356U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5290349323647887877U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5803176485246280271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16702526675475954730U;
            aOrbiterA = RotL64((aOrbiterA * 13695676754973145769U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16454171963808313625U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3105313968748067810U;
            aOrbiterB = RotL64((aOrbiterB * 16572687178789102843U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 20U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterC, 24U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aNonceWordA, 59U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aNonceWordD, 16U));
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterG, 38U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordC, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31548U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32461U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31547U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 28819U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 4U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 1952750591494698524U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 21U)) + 4488270851303332830U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 51U)) + 2738763375328927635U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 57U)) + 6728843649480454340U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 6U)) + 10490717875258865358U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 47U)) + 1429288737812910205U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 53U)) + 2761375016998907636U) + RotL64(aNonceWordB, 37U);
            aOrbiterH = (aWandererE + RotL64(aIngress, 3U)) + 1088988605204499835U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 6829840407300289709U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 35U)) + 9267240337867690471U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 8120113021183975703U) + RotL64(aNonceWordH, 24U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1340980511302566784U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11874452169979878835U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8638486178860092537U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1872314794140971426U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6013952618696225751U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7994863587373565715U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3644011378086236002U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8501867691997891731U;
            aOrbiterK = RotL64((aOrbiterK * 7115282675461711509U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2493546555198066143U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5179240189571799179U;
            aOrbiterC = RotL64((aOrbiterC * 1267579130962756135U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11273348247858394197U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 4577476419423118925U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) ^ RotL64(aNonceWordG, 3U);
            aOrbiterH = RotL64((aOrbiterH * 8427261005061162673U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6201955123046621919U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3930651302557530185U;
            aOrbiterA = RotL64((aOrbiterA * 1563512534463027965U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7571426325227856019U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11098508505512361002U;
            aOrbiterG = RotL64((aOrbiterG * 9229352429618815089U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6154830144380484305U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4282054616147137364U;
            aOrbiterE = RotL64((aOrbiterE * 14984813139796280171U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14818120999774989697U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12174471855744785761U;
            aOrbiterI = RotL64((aOrbiterI * 3061488029278974095U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3117297607579915182U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2979217539186455309U) ^ RotL64(aNonceWordE, 61U);
            aOrbiterD = RotL64((aOrbiterD * 12235308335184626143U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 824986728082249286U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1952750591494698524U;
            aOrbiterB = RotL64((aOrbiterB * 10162288961171400541U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 14U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + RotL64(aNonceWordF, 31U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 22U)) + aOrbiterF) + RotL64(aNonceWordC, 25U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
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

void TwistExpander_Badminton_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA03E6D934EB2F3DDULL + 0xA4671AACC81240D8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x86593FB1F703F553ULL + 0xFC3FD7E445E9DF56ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA89E31AA5078BADDULL + 0xCEFFFF85AEAFDB86ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD945731AEF65C37FULL + 0xF5ACCBD2C0417CB3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB7A359D1227C58AFULL + 0x9D0E158EC782C66CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFE67B300BDA2A633ULL + 0xB85CD1090CBAD4EBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x96CBB8D7BE2EF26DULL + 0x9EDA38673355CC12ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF0A2CD6BC4857F91ULL + 0xC462C3BB8C7E17E9ULL);
    // GSeedRunSeed_G seed_loop_g (start)
    {
        // GSeedRunSeed_G seed_loop_g lane group
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneA, aOperationLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aOperationLaneA, aOperationLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_g loop 1
        // read from: aWorkLaneD, aWorkLaneC, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordC, 12U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 787U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1592U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordH, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4074U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4311U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 4U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 4384716820085860551U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 6U)) + 9715780315942116888U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 39U)) + 15963520052789178632U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 41U)) + 14346700690686392938U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 19U)) + 6005518012489966643U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 35U)) + 2506732930310252119U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 48U)) + RotL64(aCarry, 43U)) + 16782163084851775826U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 29U)) + 823673076571076303U) + RotL64(aNonceWordE, 61U);
            aOrbiterI = (aWandererI + RotL64(aCross, 43U)) + 1634084509064077736U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 1288134975466877686U) + RotL64(aNonceWordH, 29U);
            aOrbiterC = (aWandererK + RotL64(aScatter, 37U)) + 2998220403162908444U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 220430672180734911U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10223923547068528867U;
            aOrbiterJ = RotL64((aOrbiterJ * 12577370238343872139U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11696469696177647608U) + RotL64(aNonceWordA, 14U);
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6545430420379636963U;
            aOrbiterB = RotL64((aOrbiterB * 8387163146257553773U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 79691451831797107U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8971444023498649419U;
            aOrbiterK = RotL64((aOrbiterK * 7148919880477390009U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5624403902454498793U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9468064161002030997U;
            aOrbiterE = RotL64((aOrbiterE * 8243560528100864595U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4619361544913629805U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterA = RotL64((aOrbiterA * 10879074713156075641U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8728730962617599223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9099675924074253030U;
            aOrbiterI = RotL64((aOrbiterI * 5525644236954497523U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3298303921318288541U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5953276499411658358U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10565471305001292693U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6725769507592688539U) + RotL64(aNonceWordD, 57U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1057277456510215817U;
            aOrbiterD = RotL64((aOrbiterD * 8269412198279297075U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11317925732206917722U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17814749417006079067U;
            aOrbiterF = RotL64((aOrbiterF * 4369209051015735925U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9258362135343403308U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4873837345446960113U;
            aOrbiterG = RotL64((aOrbiterG * 14223381466269503273U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7863380865835889675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4384716820085860551U;
            aOrbiterH = RotL64((aOrbiterH * 2003891033298374621U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterK, 46U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + RotL64(aNonceWordF, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aNonceWordB, 37U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 21U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 2
        // read from: aOperationLaneA, aWorkLaneD, aWorkLaneC, aWorkLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 51U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordA, 12U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7764U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 6887U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordE, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7739U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9793U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 34U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 11U)) + 15036852811491820366U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + 305637140752898475U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 52U)) + 11948631574496129610U) + RotL64(aNonceWordF, 59U);
            aOrbiterJ = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 5321623592482991426U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 19U)) + 4075270159062690728U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 35U)) + 15111580500356908928U;
            aOrbiterG = (aWandererC + RotL64(aCross, 21U)) + 7244150695504160363U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 41U)) + 5131563519577488862U) + RotL64(aNonceWordA, 49U);
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 5881954992088651371U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 12780935808751507998U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 30U)) + 12599159643925470226U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9466589929741834066U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6093158735705189789U;
            aOrbiterF = RotL64((aOrbiterF * 7453778295800853653U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17461243886150519249U) + RotL64(aNonceWordE, 56U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15456408913739900718U;
            aOrbiterA = RotL64((aOrbiterA * 16093292401746174671U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11260643903290392780U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7870342756041882616U;
            aOrbiterC = RotL64((aOrbiterC * 2431528656086173419U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 134484990005888936U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10626896209992890407U;
            aOrbiterG = RotL64((aOrbiterG * 12034131076645285597U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14031164129515132292U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1771835705730244212U;
            aOrbiterK = RotL64((aOrbiterK * 186981668443596623U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16395472745067254664U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1455944290845294254U;
            aOrbiterE = RotL64((aOrbiterE * 6757824754363319079U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17866422769075350837U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10226884082632410805U;
            aOrbiterJ = RotL64((aOrbiterJ * 206035536985843815U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14474587247775371703U) + RotL64(aNonceWordB, 39U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8501763445324525303U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5298694643596784007U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 222650368553738561U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3901452368735982094U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18347115513126660483U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3063093906728331146U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9026710562384443411U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8411243802199203035U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11282041925238364080U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15036852811491820366U;
            aOrbiterD = RotL64((aOrbiterD * 18185121326941087841U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + RotL64(aNonceWordD, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + RotL64(aCarry, 39U)) + RotL64(aNonceWordH, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 54U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 44U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 3
        // read from: aOperationLaneB, aOperationLaneA, aWorkLaneD, aWorkLaneC
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordB, 51U)) ^ RotL64(aNonceWordD, 38U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15192U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 12428U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 28U) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13424U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 14631U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 54U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 60U)) + 8685374557928800912U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 43U)) + 3482312691892161229U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordG, 43U);
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 6948130297389161165U) + RotL64(aNonceWordD, 15U);
            aOrbiterE = (aWandererF + RotL64(aCross, 21U)) + 5506385663788942690U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 17859982009307397161U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 13U)) + 9178488809207094043U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 1835479501226057169U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 40U)) + 5368101733632614939U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 19U)) + 9050459666576835422U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 51U)) + 9042186993119635078U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 47U)) + 17528342580198295025U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6495418332558436882U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8834495762667327342U) ^ RotL64(aNonceWordC, 47U);
            aOrbiterH = RotL64((aOrbiterH * 10783141541937645995U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4364314196965690905U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6357485231062120459U) ^ RotL64(aNonceWordH, 34U);
            aOrbiterI = RotL64((aOrbiterI * 289429584586504995U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3321488322626415347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10817330671781848737U;
            aOrbiterA = RotL64((aOrbiterA * 15875919466358823335U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17974092279281611763U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2871472057292789157U;
            aOrbiterB = RotL64((aOrbiterB * 16104199340711015181U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15187929795092006849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13482063681546475923U;
            aOrbiterD = RotL64((aOrbiterD * 14466266308157364963U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6232152545071397380U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17488906002621373262U;
            aOrbiterC = RotL64((aOrbiterC * 4719340606442742577U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12444819880507588549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13808941689757772497U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6541360905282412317U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8049361354387692374U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7137831335606542401U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11022231291507235007U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7230759462019420058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3923744511976096944U;
            aOrbiterG = RotL64((aOrbiterG * 9953869624243563101U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15967667946023263856U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8677583624693910669U;
            aOrbiterJ = RotL64((aOrbiterJ * 10737731876339973717U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1604347321263511013U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8685374557928800912U;
            aOrbiterF = RotL64((aOrbiterF * 14103365695918844461U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 46U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 48U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + RotL64(aNonceWordE, 51U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 4
        // read from: aExpandLaneA, aOperationLaneB, aOperationLaneA, aWorkLaneD
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordE, 57U)) ^ RotL64(aNonceWordB, 36U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19665U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21730U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordH, 34U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16485U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 18950U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 24U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 12122689833405846292U;
            aOrbiterI = (aWandererB + RotL64(aCross, 56U)) + 9640400270962766788U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 19U)) + 9141937998266739071U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 41U)) + 12899395770434090537U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 13457918115408031842U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 15134784483576000943U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 54U)) + 12540961268790055438U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 23U)) + 6306886773092764230U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 51U)) + 13573343491337243121U) + RotL64(aNonceWordD, 5U);
            aOrbiterK = ((aWandererF + RotL64(aCross, 37U)) + 8545588657348974413U) + RotL64(aNonceWordG, 27U);
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 10891410570357275120U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2877137119767060151U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9178097682386595144U;
            aOrbiterG = RotL64((aOrbiterG * 3524486002084427513U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15528007881855616978U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 11368419529245281435U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ RotL64(aNonceWordA, 59U);
            aOrbiterH = RotL64((aOrbiterH * 12433207037378339309U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5932738914934356645U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5551842263864055419U;
            aOrbiterF = RotL64((aOrbiterF * 16093776759971522681U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3824433359595690603U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17184628855571662441U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterA = RotL64((aOrbiterA * 691208053136187317U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8724462245014132623U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7481349499528092352U;
            aOrbiterJ = RotL64((aOrbiterJ * 8212182934509617583U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6908362960248294718U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5354057969992655314U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16586084885820679343U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11138301629323903147U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14164180536320940750U;
            aOrbiterK = RotL64((aOrbiterK * 9099767681053390287U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 709942920176922902U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17128241237359414945U;
            aOrbiterC = RotL64((aOrbiterC * 14063385518459963529U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6760410778228957309U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15333948259759012363U;
            aOrbiterE = RotL64((aOrbiterE * 3685416414008280787U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6929136132517755104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13833415487953533365U;
            aOrbiterI = RotL64((aOrbiterI * 14860437994758579635U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16143046377679975216U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12122689833405846292U;
            aOrbiterD = RotL64((aOrbiterD * 227699085983424155U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 36U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 4U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordC, 31U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aNonceWordF, 54U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 5
        // read from: aExpandLaneB, aExpandLaneA, aOperationLaneB, aOperationLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 37U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordD, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21887U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25743U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordB, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24324U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26405U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 43U)) + 13053031069776604052U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 35U)) + 1331396630251085122U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 11U)) + 15879286043343942393U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 41U)) + 13590365633321406830U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 39U)) + 14569235423040242618U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 30U)) + RotL64(aCarry, 39U)) + 11397370636618371560U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 57U)) + 3455933494593971847U) + RotL64(aNonceWordA, 23U);
            aOrbiterI = ((aWandererI + RotL64(aCross, 53U)) + 1307153376443784593U) + RotL64(aNonceWordC, 3U);
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 10688618762584786871U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 43U)) + 17746248451153600096U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 37U)) + 8512568600755410158U) + aPhaseFOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8950230550112591092U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17790968369472845496U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5104988920132008913U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12583323865381967534U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11243927099685293887U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12867003042486433971U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9690268715525781389U) + RotL64(aNonceWordD, 35U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7466066217365074653U;
            aOrbiterI = RotL64((aOrbiterI * 17565696765505320889U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3673528673209875118U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14079103852360952255U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17449228863409999629U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6747836856132250630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5027692924422297153U;
            aOrbiterK = RotL64((aOrbiterK * 2492421273167124437U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11370341866003395776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14013204893442579282U;
            aOrbiterB = RotL64((aOrbiterB * 6602239957997240785U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3436953430697936790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6399073534839993637U;
            aOrbiterD = RotL64((aOrbiterD * 14186050072610021241U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7054057507823631422U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5752085719673338095U) ^ RotL64(aNonceWordF, 53U);
            aOrbiterJ = RotL64((aOrbiterJ * 13252660162476029593U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10628323020010327594U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5029617362660411790U;
            aOrbiterH = RotL64((aOrbiterH * 7230663968894173433U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6816547880074551571U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6683840259024813282U;
            aOrbiterF = RotL64((aOrbiterF * 13145224557159574541U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5952768353050729617U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13053031069776604052U;
            aOrbiterG = RotL64((aOrbiterG * 13710064584055068065U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 20U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 58U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 57U)) + RotL64(aNonceWordE, 46U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 18U)) + RotL64(aNonceWordG, 59U));
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_g loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 14U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28262U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 32691U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30672U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 30902U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 47U)) + 11998579547770778580U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 8409465187298704610U) + RotL64(aNonceWordC, 21U);
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 3470222286110333500U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 5704486785203069994U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 29U)) + 10334944660253279633U) + RotL64(aNonceWordF, 55U);
            aOrbiterK = (aWandererI + RotL64(aCross, 36U)) + 7626852700722567477U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 19U)) + 14631310754943209743U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 51U)) + 807160297237854120U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 5624154783624196107U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 26U)) + 4971444394698940423U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 43U)) + 6340057638461027062U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9003019862787819481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12766104026871797746U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4062118445824915939U;
            aOrbiterH = RotL64((aOrbiterH * 13130770039048080701U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5258212525426469978U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9956946981015983939U;
            aOrbiterK = RotL64((aOrbiterK * 8106382657040497669U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10837606223056473999U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13292864885504191134U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 166087925900318658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6786842221885441388U;
            aOrbiterF = RotL64((aOrbiterF * 4411147600413147773U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16888086378070246404U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5240855484445974002U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 402652898573422271U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6874866669211571608U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 732890824978127460U) ^ RotL64(aNonceWordH, 15U);
            aOrbiterI = RotL64((aOrbiterI * 3776365957702257453U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5541380495707308058U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17947326584411475765U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10920952349981652899U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15060679340045767910U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1675974028461383576U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15127962310365242819U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 226889112033170368U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4290719734244011388U;
            aOrbiterB = RotL64((aOrbiterB * 6453598182035414143U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7712233480730639084U) + RotL64(aNonceWordE, 13U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11998579547770778580U;
            aOrbiterG = RotL64((aOrbiterG * 11599893373156816375U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 34U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordD, 6U));
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + RotL64(aCarry, 27U)) + RotL64(aNonceWordB, 45U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_g (end)
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

void TwistExpander_Badminton_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
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
        // read from: mSource, aKeyRowReadA, aKeyRowReadB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // read from: mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7990U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3993U)) & W_KEY1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3646U)) & W_KEY1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6442U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 41U)) + 16451272412693907816U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 18U)) + 10099485419723255462U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 17668900099534923192U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 29U)) + 5497093724143181753U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 51U)) + 10354044773550071706U) + aPhaseCOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 12728258851198019099U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 4144050505314242618U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 56U)) + 14133805325480076530U;
            aOrbiterK = (aWandererH + RotL64(aCross, 23U)) + 308863673210602899U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11741180130160569753U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12926863156769180448U;
            aOrbiterA = RotL64((aOrbiterA * 9726030996091054939U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 211920854786494259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13234608842479411078U;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9164711974854618892U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6667377062281954219U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2603737166987437649U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4559040002406721850U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1749875480850675109U;
            aOrbiterK = RotL64((aOrbiterK * 15822640067349481089U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9555365165561936366U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18289733999504213574U;
            aOrbiterB = RotL64((aOrbiterB * 14156217554673229429U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8727162691639622461U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 291406782452963706U;
            aOrbiterG = RotL64((aOrbiterG * 8413500075082350243U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8294911802626492257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15853578397277298548U;
            aOrbiterF = RotL64((aOrbiterF * 13256191781365357747U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11535146194939658681U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2177540476748375661U;
            aOrbiterD = RotL64((aOrbiterD * 15791341922007841029U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2705306323728084136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17617871830709148043U;
            aOrbiterI = RotL64((aOrbiterI * 3449981219502809255U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 20U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 56U));
            aWandererG = aWandererG + (((RotL64(aIngress, 20U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + aPhaseCWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // read from: aExpandLaneA, mSource, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14853U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 14027U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9989U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 15597U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 12U)) + 12980104182836602177U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 3172622203188863995U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 27U)) + 1170974132219980203U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 39U)) + 6035201940965047490U;
            aOrbiterF = (aWandererK + RotL64(aCross, 19U)) + 18033907118424996722U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 14604813424800580304U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 43U)) + 13720232492851066035U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 51U)) + 3902659710585257448U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 13U)) + 8331560652661619868U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4485014147538689794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 168202636924512424U;
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16227825670092707848U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4792781933944671365U;
            aOrbiterF = RotL64((aOrbiterF * 15859849676231455283U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12636865372722601282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18198291399585556632U;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3650053185419807206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5897288963905408776U;
            aOrbiterC = RotL64((aOrbiterC * 3706949366974086151U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9922308113622901726U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13352279749091561510U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4025213180483632557U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14969461950939646117U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10231661776135056651U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11284575051455238501U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10621934544068320859U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6029116920305246887U;
            aOrbiterK = RotL64((aOrbiterK * 6087523725059376905U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12887482425168671195U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8351351557123783853U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3839381627914762245U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5405938210926464973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 385145802287899406U;
            aOrbiterE = RotL64((aOrbiterE * 8330751480464271445U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 18U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 40U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 36U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // read from: aExpandLaneB, aExpandLaneA, aKeyRowReadA, aKeyRowReadB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17244U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 17388U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21477U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 22418U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 42U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aIngress, 52U)) + 6163290588946759209U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 7342672468560105447U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 11574563167017282321U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 57U)) + 2254820206194758964U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 1469783447473099498U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 5U)) + 14174828900676165088U) + aPhaseCOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 16277954291890598132U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 18U)) + 14845750668693136766U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 39U)) + 150099699692047766U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1200784917165131703U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9469982764806754302U;
            aOrbiterE = RotL64((aOrbiterE * 17851969334511301943U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10956702761701710182U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7915506894975487807U;
            aOrbiterI = RotL64((aOrbiterI * 8874108311712727983U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17335794183733623213U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 557028996286989506U;
            aOrbiterH = RotL64((aOrbiterH * 3993359298602424281U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1597385667771002414U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4376417959915162639U;
            aOrbiterC = RotL64((aOrbiterC * 4626236858205178149U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 549770198518993876U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 756554555648070919U;
            aOrbiterF = RotL64((aOrbiterF * 16272320259614325355U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7298557532533152193U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3336802611342112013U;
            aOrbiterJ = RotL64((aOrbiterJ * 14679103452120080499U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2314938232094714365U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12215066333571149153U;
            aOrbiterK = RotL64((aOrbiterK * 10747052773052630601U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7762752719356805046U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6519429915769040078U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15548676502167938513U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7556691736109752918U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13731245903412646404U;
            aOrbiterA = RotL64((aOrbiterA * 15581965016668635409U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 5U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterC, 20U)) + aPhaseCWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterK, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterA, 56U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, mSource
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29404U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27108U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29009U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31235U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 58U)) + 16189787374324972735U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 47U)) + 17563763730956242224U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 10572803498593789385U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 7713105232072974166U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 26U)) + RotL64(aCarry, 27U)) + 10760839534772718139U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 13397069448391230253U;
            aOrbiterB = (aWandererA + RotL64(aCross, 41U)) + 4569255679998375682U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 51U)) + 9888769350817876949U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 3U)) + 11351796060878856300U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18153775071965707204U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1282846411145853435U;
            aOrbiterE = RotL64((aOrbiterE * 12294455920906257823U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16457743979262460660U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 173493260775251032U;
            aOrbiterK = RotL64((aOrbiterK * 4935807229040883505U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3927345926316409630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5158769729850853623U;
            aOrbiterB = RotL64((aOrbiterB * 2446452358663812945U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12331351600010165154U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3940794200348684050U;
            aOrbiterG = RotL64((aOrbiterG * 13248997263062075043U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11248514843822945425U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1391497323278226522U;
            aOrbiterC = RotL64((aOrbiterC * 8376841806072565005U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13265623528678787307U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2802033745265647317U;
            aOrbiterJ = RotL64((aOrbiterJ * 3437626962562016147U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6938444301018051844U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1086544666755559028U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16039728388882079889U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16156443117365816536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3619942859562697142U;
            aOrbiterA = RotL64((aOrbiterA * 7589346043159112151U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17681848914912743292U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8848238631758130416U;
            aOrbiterF = RotL64((aOrbiterF * 810402256099500607U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 44U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 58U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Badminton_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3929U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 8117U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 102U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 1524U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererH + RotL64(aIngress, 38U)) + RotL64(aCarry, 35U)) + 17225673071833726819U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 10301458382103627331U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 3960233050857362414U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 17768665685046605837U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 27U)) + 14471018461213959767U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10730597892721340453U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14863394003122760542U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17731557030589257169U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9948587274816688296U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3573569431435100993U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2303922230056523077U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8153670675740450590U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16438856577722561424U;
            aOrbiterF = RotL64((aOrbiterF * 4689247488336908827U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15765587867581925041U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1082039522061775213U;
            aOrbiterC = RotL64((aOrbiterC * 17023740047246402641U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4202521649260798876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15877659681260461141U;
            aOrbiterH = RotL64((aOrbiterH * 11369910758551088173U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 50U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // read from: aOperationLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9995U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 10753U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9747U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 8535U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 28U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 52U)) + 8793908991006073956U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 5U)) + 2932916283348441943U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 11069042087940968262U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 14369628676782894441U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 8602903272780978282U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3827036107178568820U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8905245209036772489U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5744017326197157667U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13331387530760017893U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9880107580289737823U;
            aOrbiterD = RotL64((aOrbiterD * 10302652857542703753U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10199619040626900278U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2466307560891374281U;
            aOrbiterB = RotL64((aOrbiterB * 6295342978834217571U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13973403407981259448U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2851460278409385243U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11226902976321781743U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10365453393815690776U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // read from: aOperationLaneB, aOperationLaneA, aExpandLaneD, aExpandLaneC
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18328U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19623U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17481U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 17322U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aScatter, 19U)) + 6024062041314952357U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 18340757093658015585U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 11911120493880346751U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 3U)) + 17428074353884654439U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 43U)) + 12790849760814795936U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12633397052172117800U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11946150433665237945U;
            aOrbiterK = RotL64((aOrbiterK * 10324089534873171291U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16842157900909419285U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14186235783224155962U;
            aOrbiterD = RotL64((aOrbiterD * 10521157787073684417U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13284904542579767591U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11609181965078844357U;
            aOrbiterA = RotL64((aOrbiterA * 5455780554452453513U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9628562297095374984U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7850281529011259759U;
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 257458718073794527U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10693404545773519306U;
            aOrbiterG = RotL64((aOrbiterG * 14821443722828498323U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 36U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + aPhaseDWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 24U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // read from: aOperationLaneC, aOperationLaneB, aOperationLaneA, aExpandLaneD
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32340U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27893U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26946U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30503U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 3U)) + 3199575576585871314U) + aPhaseDOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 37U)) + 2533378188975571824U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 6819782112558312658U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 12690060987724798497U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 7088375139715629606U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17785618677423695666U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1714999280296491277U;
            aOrbiterD = RotL64((aOrbiterD * 7675674437417383741U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17611338506932491624U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6475727359297421201U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15133348244242438069U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2347744591204119530U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2739317903351401068U;
            aOrbiterH = RotL64((aOrbiterH * 15435029315209475631U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8663535261373274338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8205245127823536479U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13857005110466856439U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8916510616749754516U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3944805940148512932U;
            aOrbiterI = RotL64((aOrbiterI * 18082271583211389701U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 10U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Badminton_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // read from: aOperationLaneD, aOperationLaneC, aOperationLaneB, aOperationLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2065U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 4678U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5861U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 1740U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 58U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 11U)) + 1364174714924216027U;
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 13561796874229506613U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 11845572344206238305U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 15762708240326773763U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 34U)) + 1157119665207900473U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 27U)) + 6823546624372055260U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 14465564210523945121U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10667464548080807531U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13445737493224316575U;
            aOrbiterE = RotL64((aOrbiterE * 12137295000900795711U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3009837893785957665U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2886920524111083752U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15308180928967762543U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10886177449328249656U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15067759884678100433U;
            aOrbiterK = RotL64((aOrbiterK * 5724566815989860041U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18307930462682331536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8791864377579255801U;
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 805797468642992351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5743305867058244964U;
            aOrbiterC = RotL64((aOrbiterC * 16263000753351131717U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17102025528234481273U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1841579177327486899U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3841603385577825265U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2189493507896508972U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 42U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // read from: aWorkLaneA, aOperationLaneD, aOperationLaneC, aOperationLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13744U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 9014U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13203U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10052U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 13U)) + 13481227414590594621U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 17425964381118918026U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 21U)) + 4792004356135956581U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 11926849936000639098U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 35U)) + 990697329347742142U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 3U)) + 9307721505373076588U;
            aOrbiterA = (aWandererG + RotL64(aCross, 37U)) + 17605732738841908719U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13110764518634187439U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17970109897810645911U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10395095143998920213U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10273133817644703654U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11239046688920468137U;
            aOrbiterE = RotL64((aOrbiterE * 5197802934333553327U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8355821483275763145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15522151127786049345U;
            aOrbiterC = RotL64((aOrbiterC * 4844278537850520413U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5381663179722418112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9551368011768104906U;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16264476585232221270U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7721417776432288282U;
            aOrbiterD = RotL64((aOrbiterD * 10267770327791051869U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 339418090653475277U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3247926250495935511U;
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3390560045236418590U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3894024951542543635U;
            aOrbiterA = RotL64((aOrbiterA * 10599637790900418767U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 28U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 28U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // read from: aWorkLaneB, aWorkLaneA, aOperationLaneD, aOperationLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16626U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22783U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18061U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 21505U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aPrevious, 26U)) + 13333509828310369865U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 7645352517103840797U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 5310766306660062655U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 41U)) + 5165635069832352932U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 19U)) + 15684141764734281849U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 57U)) + 3327963374225061738U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 8625811794878848871U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7598657468430485291U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2881171216276746485U;
            aOrbiterH = RotL64((aOrbiterH * 3331350584102843605U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10237691227222918101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6419254255884834497U;
            aOrbiterG = RotL64((aOrbiterG * 3816625473642865305U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4238455444646479956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14936613353493061492U;
            aOrbiterB = RotL64((aOrbiterB * 3544216916806292273U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15324699725208372627U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9506640480601832011U;
            aOrbiterC = RotL64((aOrbiterC * 12819564111348390227U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3709149613660215641U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1724290199312754307U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13191172833570139194U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3686087945377837886U;
            aOrbiterD = RotL64((aOrbiterD * 10883609557429936283U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10418330386245397022U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5383531313632347245U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2987755379396160073U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 28U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterH, 14U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 52U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aOperationLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30613U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 27801U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28311U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28538U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 20U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 4476099022490972343U;
            aOrbiterB = (aWandererG + RotL64(aCross, 3U)) + 16836423700375760429U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 43U)) + 8850577488928703557U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 7091631824560042743U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 12560498899956759494U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 20U)) + 7797973377112012161U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 57U)) + 6173820673874805794U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10805025132310245348U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7139216143268029968U;
            aOrbiterD = RotL64((aOrbiterD * 8349754682635765573U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8241544862261635722U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4735527016563596150U;
            aOrbiterG = RotL64((aOrbiterG * 6621354217673598381U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5166171126690294033U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11117641762075368393U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4980156869201219393U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6312932356458415421U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1304139291184508668U;
            aOrbiterI = RotL64((aOrbiterI * 90744653170922319U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10085025354842771067U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16745854428789531080U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1945983905747274355U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2497187958708890337U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16069701876646548995U;
            aOrbiterH = RotL64((aOrbiterH * 16606039730973709495U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17242004368025978091U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12334315722243232121U;
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 44U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Badminton_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
    // GTwistRunTwist_D twist_loop_d (start)
    {
        // GTwistRunTwist_D twist_loop_d lane group
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_d loop 1
        // read from: aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 8148U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 5649U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1585U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 221U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 42U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 826930775230515406U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 10U)) + 5137814617363250861U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 14761561947426681616U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 12773023438753662590U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 43U)) + 7331345852207096322U) + aPhaseFOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3899381212671247460U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10072004147620068599U;
            aOrbiterK = RotL64((aOrbiterK * 5663583566047763435U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3424585039401897560U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8246760141625966321U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11478879365443736383U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3655992860610853290U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11154618022505863898U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4791494171286145231U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15629361991059709973U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10842068502278489664U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17223002513104960799U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5571312349016336686U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 589313823745748879U;
            aOrbiterJ = RotL64((aOrbiterJ * 1356685926549786027U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 38U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 2
        // read from: aWorkLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12193U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9413U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9013U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16071U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 53U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 60U)) + 18191288703716505885U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 9824014524910417136U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 11953012029254917548U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 6297568011027199089U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + 2576999400457367975U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13176139160575558254U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9978408174563621810U;
            aOrbiterF = RotL64((aOrbiterF * 1399052522159751531U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16765834875061607142U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16534507305459121344U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8943988574248229067U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3114710944346151807U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 10240517868726718592U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4645691562915606463U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10721450637990777883U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16689590768796583952U;
            aOrbiterJ = RotL64((aOrbiterJ * 3046344179729901637U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2427422768928450209U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13495584061816457831U;
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 42U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_d loop 3
        // read from: aWorkLaneB, aWorkLaneA, aExpandLaneD, aExpandLaneC
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20793U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21980U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16673U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22065U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 18U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 51U)) + 3238389262925516513U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 12381787182611386995U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 37U)) + 7883885539305181549U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 1185413044597727092U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 57U)) + 15219353497204773135U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7533774715626734082U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2599930450937763464U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13207380361960949159U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16074720663961214284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15483613196360051221U;
            aOrbiterJ = RotL64((aOrbiterJ * 11717479088020532861U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9396557867081376268U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9668459976852660245U;
            aOrbiterB = RotL64((aOrbiterB * 11748505665890567063U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9037269914643207212U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 16936742640861088240U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16481274825758546398U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 481851372837611166U;
            aOrbiterE = RotL64((aOrbiterE * 2225030139210599207U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 14U) + aOrbiterF) + RotL64(aOrbiterJ, 42U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_d loop 4
        // read from: aWorkLaneC, aWorkLaneB, aWorkLaneA, aExpandLaneD
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29868U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 24807U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30814U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31637U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 57U)) + 16519040829220310189U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 6888002778416941825U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 26U)) + 1310832187746534025U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 5890888009051281674U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 5143864838362464857U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15591534069452660003U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1466867671765325096U;
            aOrbiterC = RotL64((aOrbiterC * 1277202105237572301U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13931443680107902488U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15400747367673245552U;
            aOrbiterH = RotL64((aOrbiterH * 7011651369456453127U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2836975369734495759U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2370720358274970117U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4615571902817575375U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3470677184188006133U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7175584278499266723U;
            aOrbiterK = RotL64((aOrbiterK * 10067096593682482345U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6095078817776863055U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2176637999243513070U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12215701810843975501U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 40U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + ((((RotL64(aCross, 38U) + aOrbiterJ) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)
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

void TwistExpander_Badminton_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 3983U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1813U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1146U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 5030U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 22U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 7632760812370906911U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 6007174525479723089U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 10U)) + 3362829642521821048U) + aPhaseGOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 18009548556107978286U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 57U)) + 17880909432272697327U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15961567935420752568U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10136559064656837921U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14473810261421912849U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17622019364405410277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6927494824421416306U;
            aOrbiterI = RotL64((aOrbiterI * 2686290883767829973U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7125170407794874847U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12342273503071032250U;
            aOrbiterC = RotL64((aOrbiterC * 867417849555857179U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14997696377476124836U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14874498694181230698U;
            aOrbiterF = RotL64((aOrbiterF * 4026127545746010937U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2549397729130885686U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4217995818662767955U;
            aOrbiterG = RotL64((aOrbiterG * 5525525344485251063U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterF, 48U)) + aPhaseGWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + aPhaseGWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // grow_key_a loop 2
        // read from: aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 9708U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 8366U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15221U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 14247U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 50U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 9220392006207660113U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + 11305018553489132882U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 5860373868073513684U) + aPhaseGOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 39U)) + 12319586170883987589U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 35U)) + 14072333614354649021U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9332158529453194608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3860569321145958686U;
            aOrbiterK = RotL64((aOrbiterK * 907977527866467591U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8119005668901240093U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13918259792880333239U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5441062406822088853U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6938856216758228704U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3960905839118710604U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16203746868670689793U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6043879193734253929U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15691425268831319195U;
            aOrbiterH = RotL64((aOrbiterH * 7189195135654636271U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14912209933584715274U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16180183395910618923U;
            aOrbiterI = RotL64((aOrbiterI * 3942858974766467849U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aPhaseGWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterB, 18U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_a loop 3
        // read from: aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22654U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21725U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20509U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 21181U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 56U)) + 8402620908307642697U) + aPhaseGOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 23U)) + 11347672014525086047U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 2816462912503401876U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 6940159795470696093U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 9134692490095883851U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4999455497008026526U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5992451460350651332U;
            aOrbiterG = RotL64((aOrbiterG * 12796550245322491401U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3417087346651371924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3612773820086198270U;
            aOrbiterE = RotL64((aOrbiterE * 5519856345435871169U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 463398077083428570U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11249391303705089012U;
            aOrbiterF = RotL64((aOrbiterF * 7106735772303292983U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17027535139825739501U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 568131384979596481U;
            aOrbiterA = RotL64((aOrbiterA * 5683451044852895957U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4793712537158004047U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10415170179135963622U;
            aOrbiterD = RotL64((aOrbiterD * 13729564030210361415U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // grow_key_a loop 4
        // read from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 32531U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 28242U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26380U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((aIndex + 25961U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aPrevious, 48U)) + 826930775230515406U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 5137814617363250861U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 14761561947426681616U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 12773023438753662590U) + aPhaseGOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 3U)) + 7331345852207096322U) + aPhaseGOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3899381212671247460U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10072004147620068599U;
            aOrbiterG = RotL64((aOrbiterG * 5663583566047763435U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3424585039401897560U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8246760141625966321U;
            aOrbiterI = RotL64((aOrbiterI * 11478879365443736383U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3655992860610853290U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11154618022505863898U;
            aOrbiterH = RotL64((aOrbiterH * 4791494171286145231U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15629361991059709973U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10842068502278489664U;
            aOrbiterK = RotL64((aOrbiterK * 17223002513104960799U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5571312349016336686U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 589313823745748879U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1356685926549786027U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aPhaseGWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 56U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Badminton_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2777U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7602U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5221U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2083U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 6024062041314952357U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 51U)) + 18340757093658015585U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 11911120493880346751U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 17428074353884654439U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 27U)) + 12790849760814795936U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12633397052172117800U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11946150433665237945U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10324089534873171291U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16842157900909419285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14186235783224155962U;
            aOrbiterF = RotL64((aOrbiterF * 10521157787073684417U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13284904542579767591U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11609181965078844357U;
            aOrbiterG = RotL64((aOrbiterG * 5455780554452453513U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9628562297095374984U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7850281529011259759U;
            aOrbiterA = RotL64((aOrbiterA * 17611485102925470357U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 257458718073794527U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10693404545773519306U;
            aOrbiterI = RotL64((aOrbiterI * 14821443722828498323U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 37U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 6U)) + aOrbiterF) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // grow_key_b loop 2
        // read from: aExpandLaneB, aExpandLaneC, aExpandLaneD, aWorkLaneA
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15786U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12889U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11627U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10702U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 6467297102954816305U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 38U)) + 7921154109831114952U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 21U)) + 5701131763215638919U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 10022999076719002684U) + aPhaseHOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 4367135243038982316U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14445846824810383592U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7683697954545773253U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4832124801510084629U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17517006750428030899U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2052484792684025476U;
            aOrbiterB = RotL64((aOrbiterB * 12463117571122469643U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6279463052085808926U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 679280153651813684U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3047031560593583881U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2939516520188460569U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1960616434964712325U;
            aOrbiterJ = RotL64((aOrbiterJ * 15145998415466343039U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12273819390719947361U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5685033154709449397U;
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 21U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_b loop 3
        // read from: aExpandLaneC, aExpandLaneD, aWorkLaneA, aWorkLaneB
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17257U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17117U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21707U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23062U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 2330952702412094686U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 7820188225935060799U;
            aOrbiterK = (aWandererD + RotL64(aCross, 41U)) + 9347644591709839145U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 2288624878446846870U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 3U)) + 9358977729492824128U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1858511275052455039U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13715478509322292552U;
            aOrbiterK = RotL64((aOrbiterK * 15552121744869003235U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16413396625604260455U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17714322215518432705U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1904184102419934333U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16188315436202861122U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5564445841368207813U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14125834616162835983U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13717068949900594673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5729546141908425670U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4297827922736712074U;
            aOrbiterC = RotL64((aOrbiterC * 13631630436759768885U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 30U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // grow_key_b loop 4
        // read from: aExpandLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 24734U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30324U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30113U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 27450U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 6521330037475130256U) + aPhaseHOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 29U)) + 12611880456055428940U;
            aOrbiterC = (aWandererA + RotL64(aCross, 19U)) + 12061611078130934708U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 19U)) + 1558112410801116984U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 10509115227850160786U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4045915960688792066U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1196541286513243082U;
            aOrbiterC = RotL64((aOrbiterC * 5454309408259753479U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15564991032722373702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4897765238703641798U;
            aOrbiterD = RotL64((aOrbiterD * 9693901276712946763U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12327429514907752733U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6189189797708711636U;
            aOrbiterB = RotL64((aOrbiterB * 9017615866338877651U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6374267075282018852U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1888758503831341439U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14956857689299491800U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14879361107223331957U;
            aOrbiterA = RotL64((aOrbiterA * 9166712966729591953U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 39U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 14U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
