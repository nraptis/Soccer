#include "TwistExpander_PickleBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_PickleBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB6998A36F5E53ACDULL + 0xDB478A3F156E5E70ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAA9950951E376307ULL + 0xABC0E662EF0891A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB7AE914A7686F42DULL + 0xB487BAE83336F4FCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8A40EECCBD8EC539ULL + 0x9D3C144FE2A281D3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9040D3397806F893ULL + 0xD8501032021F73D8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9A4E6ED62DAD2D9DULL + 0xF4C8B5FA9C1B5B77ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAED02BAAC3EAE95FULL + 0xA96EEA5FD02F8015ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDBD2B0C14654A36BULL + 0xE33592EDD822D837ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD08854F2837D83A1ULL + 0xD73A2644B9B124EDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA82F65715E5F2DD9ULL + 0x84A10E9BF44F7127ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF5CBC212EE01A803ULL + 0xFE50EC57A4FE6598ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE2A4A5556F78C953ULL + 0x897550EB61152723ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC91ACC70853AF345ULL + 0xFE4C58CD0D26B458ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA907480247DA46EFULL + 0xEA889565FA9C8F35ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9ADD373FE8DA6E41ULL + 0xA5BF6C5BFCC26485ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCDEC6B5E8052F493ULL + 0xE82D3654B24E0CEBULL);
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
        // read from: mSource, pSnow, aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // ingress from: mSource, pSnow
        // ingress directions: mSource forward forced, pSnow forward/backward random
        // cross from: pSnow, mSource
        // cross directions: pSnow backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(mSource[((aIndex + 2661U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 39U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1869U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 3056U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 56U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 37U)) + 14686411261024919129U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 23U)) + 7514582233957632005U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + 6520710480103365552U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 11U)) + 1983621978676188036U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 21U)) + 9003524602590749672U;
            aOrbiterD = ((((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 6428568234045228995U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 43U)) + 8656552687136446989U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 16916248288415922490U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 54U)) + 9740237548002535784U) + aNonceWordP;
            aOrbiterB = (aWandererK + RotL64(aScatter, 51U)) + 907561000814618339U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 27U)) + 4751108900841197631U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 167774899400732287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11907484918310854962U;
            aOrbiterI = RotL64((aOrbiterI * 7213139491146402985U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14910318613649863924U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14882888155751455276U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11394136445442060201U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16175942562693781908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11022373758481651102U;
            aOrbiterK = RotL64((aOrbiterK * 6836331461393816027U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12548405399045031548U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10850926364556828443U;
            aOrbiterG = RotL64((aOrbiterG * 16231561687709867431U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13391684887911141790U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14648937281264822988U;
            aOrbiterA = RotL64((aOrbiterA * 6533299316940026059U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8298658887198526821U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13822977698661348891U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 17769262972278410937U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7505646847564645719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3238749538197209166U;
            aOrbiterH = RotL64((aOrbiterH * 15394286542600778567U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15853506915123709257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8426329899401071248U;
            aOrbiterF = RotL64((aOrbiterF * 1330397096577715113U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14848635392815613098U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3549927798350175044U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1899044682313056949U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1798973117197750802U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13056711228618953977U;
            aOrbiterC = RotL64((aOrbiterC * 9102877396419306689U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1395893547965799281U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14686411261024919129U;
            aOrbiterD = RotL64((aOrbiterD * 17075377081365066067U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterK, 50U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 44U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 42U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // ingress from: aFireLaneA, pSnow
        // ingress directions: aFireLaneA forward forced, pSnow forward/backward random
        // cross from: aFireLaneA, mSource
        // cross directions: aFireLaneA backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 8049U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((aIndex + 6516U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7188U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9734U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 14U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 35U)) + 8367680518550579791U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 11491674725611181241U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 39U)) + 16673861720782164214U) + aNonceWordI;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 19U)) + 9786610124108350855U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 11U)) + 5745080601557577637U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 1959402215131684684U) + aNonceWordC;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 28U)) + 6121650036079196522U) + aNonceWordG;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 12016309761037342392U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 3U)) + 5986936646177049603U) + aNonceWordD;
            aOrbiterA = (aWandererA + RotL64(aIngress, 23U)) + 1000367700904043468U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 43U)) + 17425288243569101032U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4856917474950325209U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16312111093223166419U;
            aOrbiterJ = RotL64((aOrbiterJ * 11046477664487805241U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 456110002032422270U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11393724374787795662U;
            aOrbiterH = RotL64((aOrbiterH * 1176984359123668389U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8378176867715697176U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8086186452345234815U;
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8470349167474173245U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2528229938740192694U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 8717790851266520943U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13247168811545753141U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8745293957516815264U;
            aOrbiterG = RotL64((aOrbiterG * 14270617180621072619U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6165915500564961987U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12015407798844173213U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 3913451986559154153U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 545006684939922156U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16366753936267185001U;
            aOrbiterK = RotL64((aOrbiterK * 6495185976430013201U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3097605623436091728U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15950167830259022926U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 4415538963984293323U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8356327899232213426U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10183421678251169945U;
            aOrbiterI = RotL64((aOrbiterI * 9474380650337109299U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16327340177970834683U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7086901180933495535U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1276521829484494857U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13421211370092080006U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8367680518550579791U;
            aOrbiterD = RotL64((aOrbiterD * 12256662446176946163U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 34U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // ingress from: aFireLaneB, mSource
        // ingress directions: aFireLaneB forward forced, mSource forward/backward random
        // cross from: aFireLaneA, pSnow
        // cross directions: aFireLaneA backward forced, pSnow backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 15923U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14980U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16091U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13268U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererB + RotL64(aScatter, 3U)) + 15726877954695761686U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 53U)) + 14187652171881943587U) + aNonceWordJ;
            aOrbiterD = (aWandererD + RotL64(aCross, 50U)) + 8420423151313882782U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 23U)) + 14942322692433259283U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 29U)) + 7272331475919796255U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 154504365041805840U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 5U)) + 17475491222554948786U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 35U)) + 5759181483165339605U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 5993060214499322845U) + aNonceWordI;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 10901786237875941844U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 44U)) + 17135786595614068473U) + aNonceWordG;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5208202073886811165U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6821452921018900631U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13119330055184115669U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13348064837402206969U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8967943922403445136U;
            aOrbiterJ = RotL64((aOrbiterJ * 300168481725373093U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8130283784171430891U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6351113882502502876U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15960622823993072903U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6894708729226455769U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12065058511247133944U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 5432601727436935831U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17138279326229372741U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12987698199066890628U;
            aOrbiterA = RotL64((aOrbiterA * 12665716655177320977U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13688833537574196675U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4211971980434000618U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1374411763361518851U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10376917117582537592U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4807742522197923516U;
            aOrbiterF = RotL64((aOrbiterF * 15257251453302090961U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18038296468177121243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6879666349379745258U;
            aOrbiterK = RotL64((aOrbiterK * 15819475269715810555U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5193656664432659624U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 680899397323387963U;
            aOrbiterG = RotL64((aOrbiterG * 9857476056194621321U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1851929589073547860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13093101559415170218U;
            aOrbiterH = RotL64((aOrbiterH * 13950928576652143737U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13695333301427028607U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15726877954695761686U;
            aOrbiterI = RotL64((aOrbiterI * 960063676226172027U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterD, 18U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // ingress from: aExpandLaneA, pSnow, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: mSource, aFireLaneB
        // cross directions: mSource backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21802U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 20669U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20449U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 18210U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21359U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 13U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 7270044678408187242U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 53U)) + 10192278965379756766U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 17568666746676060748U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 46U)) + 14312927531124963037U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 13U)) + 9825825726152087706U) + aNonceWordA;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 51U)) + 9696778570255265896U) + aNonceWordL;
            aOrbiterA = (aWandererK + RotL64(aCross, 39U)) + 17657841352013417228U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 27U)) + 16207815085909628439U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 1752979206374514227U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 35U)) + 10456310689643905854U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 24U)) + 16127830548663742550U) + aNonceWordN;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 2940917376003930842U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7353596864777649953U;
            aOrbiterH = RotL64((aOrbiterH * 7499468723171042005U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12725092740446150705U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5791296650856037010U;
            aOrbiterD = RotL64((aOrbiterD * 760379251950502133U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1200130368046206150U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16689604428598558547U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13815324235939996623U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14359561591103730856U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3975025843599045263U;
            aOrbiterB = RotL64((aOrbiterB * 5025047888533298617U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14017901732955607601U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10431526786489555196U;
            aOrbiterG = RotL64((aOrbiterG * 10181915874476132407U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7320527073559849223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15333411223710709907U;
            aOrbiterC = RotL64((aOrbiterC * 3488684905528068775U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14302474063321663801U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2104154521019935187U;
            aOrbiterA = RotL64((aOrbiterA * 12944382959742278055U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5167600586916325228U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4566823109447208716U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 9997799807454267443U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12475580453805083495U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15461491763911887974U;
            aOrbiterJ = RotL64((aOrbiterJ * 13548865386159287481U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11000532703581114393U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7815822789941347770U;
            aOrbiterK = RotL64((aOrbiterK * 1476638214324946775U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2166336159928211562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7270044678408187242U;
            aOrbiterE = RotL64((aOrbiterE * 10648564933168714815U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 46U)) + aOrbiterG) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 44U));
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // ingress from: aExpandLaneB, mSource, pSnow, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, mSource forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24755U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((aIndex + 24448U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25417U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24495U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26544U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24606U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 4U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 37U)) + 5573188770530340913U) + aNonceWordN;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 52U)) + 1431772230889897111U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 21U)) + 4809192776429682319U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 5576603692574369341U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 19U)) + 2720143226007220386U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 17220328778565331629U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 41U)) + 9629485808442089423U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 1136998437010390983U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 11893390497814523841U) + aNonceWordP;
            aOrbiterB = (aWandererD + RotL64(aScatter, 13U)) + 1764986431917532370U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 43U)) + 1741014798007010376U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12221368453236547044U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7694538641172350430U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 8439120733670016501U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17472344518811560603U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3308740700728172984U;
            aOrbiterF = RotL64((aOrbiterF * 15290400462887712083U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9535358833412446771U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11192312491731312451U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17405609148475445743U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14850451970047190039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11932493299452443256U;
            aOrbiterJ = RotL64((aOrbiterJ * 7964808728820467795U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5972619895614731870U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17174497535809891690U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15471084511364572533U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17412894714378898351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14675615208706549810U;
            aOrbiterE = RotL64((aOrbiterE * 7864845089606499769U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16116792108013658523U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9702262005960966336U;
            aOrbiterK = RotL64((aOrbiterK * 970452849653781703U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17337264966818542841U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7004462033775827275U;
            aOrbiterB = RotL64((aOrbiterB * 11943575980344402681U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17499850384482055438U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1839357713256560566U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 12943750650487416281U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8144238113917577524U) + aNonceWordD;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 888195876227325908U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 7941506708630993709U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5081763359501717653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5573188770530340913U;
            aOrbiterA = RotL64((aOrbiterA * 9699901099898698965U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 54U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aNonceWordO);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, mSource, pSnow, aFireLaneB
        // cross directions: aExpandLaneB backward forced, mSource backward forced, pSnow backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32300U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 30933U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31169U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27681U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30964U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 31423U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31619U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 37U)) + 1866656689936219099U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 48U)) + 2312314528139448289U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 57U)) + 3554037526469185237U) + aNonceWordL;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 405707755060974111U) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 1862976326004007697U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 29U)) + 12992483065443288263U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 11U)) + 3793854946371595197U) + aNonceWordJ;
            aOrbiterI = ((aWandererI + RotL64(aCross, 6U)) + 4244007978867369382U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 27U)) + 10280867500312580308U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 472563452959164242U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 51U)) + 12041770406895816553U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6118634015704900486U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13637107920449233307U;
            aOrbiterF = RotL64((aOrbiterF * 17712028184714868053U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16673735670669318830U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8602681273646630496U;
            aOrbiterK = RotL64((aOrbiterK * 6995213887710749241U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7683264695930369476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9146674871199188218U;
            aOrbiterI = RotL64((aOrbiterI * 7403427067419261981U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3012935612827493084U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1259789268731661945U;
            aOrbiterJ = RotL64((aOrbiterJ * 2372843620327050137U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5623690455471160780U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 18355567776031865462U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 9553862670107886679U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7705134893833304792U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4435192506444773834U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 5249651218395299501U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6204683785806409075U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17886971535016484255U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6047216474762933535U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4430578901091376829U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 607557685798141547U;
            aOrbiterA = RotL64((aOrbiterA * 12342665567201483107U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 18258994761911545002U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 634391404805006992U;
            aOrbiterC = RotL64((aOrbiterC * 5761143438450180463U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8528044138264666860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3867692060293315964U;
            aOrbiterE = RotL64((aOrbiterE * 8285164562893231087U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8333438209201978886U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1866656689936219099U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3935928308329865425U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterH, 6U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 30U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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

void TwistExpander_PickleBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8B8F00539E5BB3DDULL + 0x9039A4E41C68DFDAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF07C2FAD8EB4F4F1ULL + 0xAD59D241EEF05522ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAEA00A553C491CB5ULL + 0xC20DCF17C2B445CAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8C20F1995FA480C9ULL + 0xB3F03FB55E7E4D26ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC576080EB6063FC7ULL + 0x9BC1AA87A6F98A38ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDA43663F087046CBULL + 0xA1F4D2035B19C03BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDE16362BA8EBE16DULL + 0xB75E0BB33954AE03ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF0398CC87BF69665ULL + 0xDCFA5AD79A9ADA3DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA6776A572FFDB81DULL + 0xC23A2327C3605BD1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA2C834A4B195B18BULL + 0xBE5CAFCF9E29166DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x84A7578A26C0C09DULL + 0xB0EBD3866CC7C550ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9496EFC403721343ULL + 0xBD2757067083C2B5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBC028513CC7BB7BFULL + 0xBCFACAF90BACA0A5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEE4C320349331DAFULL + 0x96147E7A985E0CC5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCFB272E09A231175ULL + 0xA5B6E9B50844BFF0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC9E5D81EADC9723BULL + 0xA135573FC450361BULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneA[((aIndex + 1959U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5300U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 692U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3695U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 479672811032092393U) + aNonceWordH;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 43U)) + 18061121631394564425U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 14237400452740566065U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 18U)) + 6723123812257706134U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 4247997188026499248U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 57U)) + 1939107415066134869U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 13U)) + 3912640123546395979U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 22U)) + 8295478436553964298U) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 3218960600711526885U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5874096203353388890U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10294536533673023358U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 15561710414949058923U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11268561953904130747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16693201256788898423U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7550969634681894654U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9501647424602245869U;
            aOrbiterH = RotL64((aOrbiterH * 11265865222096866605U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8881869255994319423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16770136406906800016U;
            aOrbiterE = RotL64((aOrbiterE * 1782039587385512923U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16185384746435761363U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13841034186650721627U;
            aOrbiterC = RotL64((aOrbiterC * 12000155593277035447U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15229062695864608309U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3576122704615303733U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 2433987493885779279U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13898167174453181224U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12878032061609524049U;
            aOrbiterK = RotL64((aOrbiterK * 18104665741338251495U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12719156051299028649U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8640980843376950769U;
            aOrbiterI = RotL64((aOrbiterI * 10242616778390983333U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12133332160916004365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8743563985229104484U;
            aOrbiterA = RotL64((aOrbiterA * 4575129690615054691U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 10U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // ingress from: aFireLaneC, aExpandLaneB, aExpandLaneC
        // ingress directions: aFireLaneC forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 9289U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 5908U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6068U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10607U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 8760U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 58U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 28U)) + 380024772508948442U) + aNonceWordM;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 35U)) + 7649029098162567210U) + aNonceWordH;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 5329304598870421851U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 12306118665045151326U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 960751560457324256U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 3244070254386191876U;
            aOrbiterD = (aWandererK + RotL64(aCross, 4U)) + 15733408571609521746U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 11U)) + 17623448932647018544U) + aNonceWordE;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 57U)) + 8787759896149035829U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14741681792348288162U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8801731213568307302U;
            aOrbiterH = RotL64((aOrbiterH * 12127126999570616489U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9872248187499779222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15407371518644528235U;
            aOrbiterJ = RotL64((aOrbiterJ * 1245102406469471673U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4242060317152943062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9942784962409917541U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7296348796484458631U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15061417216070157797U;
            aOrbiterA = RotL64((aOrbiterA * 10349554676953256231U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3233185810644297433U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9241229457641024287U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2728237515724597517U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8464051359381554575U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3307872165699029375U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4859663401033023433U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5482617843966711997U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4442149210462943872U;
            aOrbiterC = RotL64((aOrbiterC * 8979352218576515647U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10591636597580147381U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14925122230279312217U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 15038171961638724013U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9772367878232735350U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15800661165607190092U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 10493976952980533589U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 28U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 30U)) + aOrbiterH);
            aWandererK = aWandererK + (((((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 36U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 10U)) + aOrbiterG) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // ingress from: aFireLaneD, aExpandLaneD, aExpandLaneC
        // ingress directions: aFireLaneD forward forced, aExpandLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 12084U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 12045U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 12817U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11009U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((aIndex + 13733U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 13333509828310369865U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 41U)) + 7645352517103840797U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 5310766306660062655U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 47U)) + 5165635069832352932U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 36U)) + 15684141764734281849U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 53U)) + 3327963374225061738U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 19U)) + 8625811794878848871U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 7598657468430485291U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 13U)) + 2881171216276746485U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10237691227222918101U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6419254255884834497U;
            aOrbiterA = RotL64((aOrbiterA * 3816625473642865305U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4238455444646479956U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14936613353493061492U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 3544216916806292273U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15324699725208372627U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9506640480601832011U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12819564111348390227U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3709149613660215641U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1724290199312754307U;
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13191172833570139194U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3686087945377837886U;
            aOrbiterD = RotL64((aOrbiterD * 10883609557429936283U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10418330386245397022U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5383531313632347245U;
            aOrbiterB = RotL64((aOrbiterB * 2987755379396160073U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7414716553072652212U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11301761123966206201U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1546727321088592187U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8570229732236388847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8773754460060264773U;
            aOrbiterC = RotL64((aOrbiterC * 3251360788932563495U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13636929800504199371U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5486599841558573720U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 2867914211589815153U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterB, 18U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 56U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21077U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 19388U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17177U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17502U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16562U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 23U)) + 18319689184146942855U;
            aOrbiterG = ((((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 8041304130090501019U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 12U)) + 11347064191990897738U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 3U)) + 15242243470024447468U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 19U)) + 10619749107163611105U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererK + RotL64(aCross, 51U)) + 14795614276221947128U) + aNonceWordJ;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 1578095288886372393U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 13593906305770501684U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 43U)) + 8919815528334599172U) + aNonceWordF;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17425548324720065145U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11125018338392347335U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4377887040461528587U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3779189180734244399U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10958224663276134041U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 6206963519509783781U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4317305352561612995U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4891139433808505355U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5166074784835930965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4501071771615514619U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6486573807774431753U;
            aOrbiterE = RotL64((aOrbiterE * 324029625116648669U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15714881857668975753U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3506619392820235900U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5707033870161224499U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5295711072762443783U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11192836530396570648U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4361810118382207039U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7993389678399774574U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12551394763541226695U;
            aOrbiterK = RotL64((aOrbiterK * 11903486656172026403U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11553674370322129668U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4459881583199320245U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2805857426321555685U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + aNonceWordL);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 56U)) + aOrbiterK) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 5
        // ingress from: aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneB[((aIndex + 22953U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneD[((aIndex + 23700U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25906U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 27098U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 22U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 7790166497945719700U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + 7136208896846119188U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 47U)) + 12123156943355100886U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 5095546037880875199U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 29U)) + 17642705393916765992U) + aNonceWordP;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 39U)) + 9918479837334416990U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 4890009823843176466U) + aNonceWordJ;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 17652590786213674124U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 24U)) + 870002527644696135U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12545429703552643682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5310272867406182581U;
            aOrbiterG = RotL64((aOrbiterG * 10420003334833925011U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3264719049050179440U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1967241238180278937U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13004319774269457957U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 773883832927040736U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12766817190261232485U;
            aOrbiterH = RotL64((aOrbiterH * 7448864556802318431U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 260069382395598265U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15462103891287350123U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5029268763635635753U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4072032867513289827U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17153061419083897076U;
            aOrbiterA = RotL64((aOrbiterA * 11934532169271718913U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6207264270332656966U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 18048064697837314947U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 13632594619404208489U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14484617445340272026U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16160443600497652026U;
            aOrbiterF = RotL64((aOrbiterF * 1988599349457831597U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5873314228291583482U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16418290052752166515U;
            aOrbiterI = RotL64((aOrbiterI * 18270363452003213317U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9158414409987627714U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8205937960146492168U;
            aOrbiterK = RotL64((aOrbiterK * 14008398661393344261U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 52U) + aOrbiterG) + RotL64(aOrbiterA, 14U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 40U)) + aOrbiterA) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 6
        // ingress from: aOperationLaneC, aOperationLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneC[((aIndex + 31314U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31327U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30799U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27819U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 34U)) + 785861751704720606U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 3U)) + 15968088718435606299U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 51U)) + 1393976526590347151U) + aNonceWordJ;
            aOrbiterF = ((aWandererA + RotL64(aCross, 13U)) + 17240750947292745884U) + aNonceWordA;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 4921576136163183137U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 3334047873553153032U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 30U)) + 15086509978458408698U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 892391205397581998U) + aNonceWordF;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + 2965686403183767521U) + aNonceWordL;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14632215393655706170U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15740589515342377322U;
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11131164813943086445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6988080581278900960U;
            aOrbiterD = RotL64((aOrbiterD * 6412189142344044255U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16021254613117657178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6183615599897921154U;
            aOrbiterK = RotL64((aOrbiterK * 9976411093264211033U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12533992547026652747U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3104325358982904219U;
            aOrbiterC = RotL64((aOrbiterC * 14977348108778147265U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3878525937957474644U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2120435259884368445U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15964718652193073177U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14928658302694194856U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9121310461310309348U;
            aOrbiterH = RotL64((aOrbiterH * 17304439784647477491U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3715693239100476493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7336577492932262490U;
            aOrbiterE = RotL64((aOrbiterE * 11074754160002665253U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2312452827448455675U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4322756069651934618U;
            aOrbiterB = RotL64((aOrbiterB * 6908893297397073539U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4962079617577705818U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5072727464750706525U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4947670001221089155U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 40U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterF, 30U));
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 37U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterB, 18U)) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_PickleBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE288998DABCC9E43ULL + 0xFFDBE5ECFB3E3908ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBC6B769EE0A135D3ULL + 0xB5E98811A02D6585ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87D1CC315F31B20FULL + 0xEFA10F7E44F265A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCB8ABE66C02EB8E1ULL + 0xFEDE17760B1D67E7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB9675288F850E625ULL + 0xF9355804E55A4759ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF1C6F986C27B00DFULL + 0x9BFD4801C26C6451ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD4228469B1329EA3ULL + 0xCC88F376D2B6C635ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8ABAA1F9A2B334A9ULL + 0xEF3F4A99C513021FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA44BA27E9E0D6507ULL + 0xB9CB511D2D07C051ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA66873057C1E4355ULL + 0xAD0CCAA40E6D4F08ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEE8D91078EBD1CC9ULL + 0x8C907429558EEC59ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF38D91A8B65DCDDFULL + 0xEF7CC320E8752C93ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCA6199B22D8D3D2FULL + 0xA44C4AFBFD118F1FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB2B2FEC79A145ECDULL + 0xA6917C48D2DF225CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD73539167857C521ULL + 0xB2D4AC7D5F8C41C2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xED0B8ECF32890143ULL + 0xE9CC1AE1DCBF0786ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7786U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 7618U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 945U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5249U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7731U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3172U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 6361545377408870615U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 35U)) + 2967245486744774933U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 3836634268482850139U) + aNonceWordK;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 7691642115360086297U) + aNonceWordI;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 24U)) + 16479280384178279281U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2901468732552539249U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2600353867755647475U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1140827276372862433U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5666596904781510956U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16108791609267427553U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8904649663479834199U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8389926875737312112U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1689501721163024426U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6517194895779049139U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11721701506949917719U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3963842745030140473U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6692473494944919373U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8510538243472109368U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18281865214102080387U;
            aOrbiterD = RotL64((aOrbiterD * 1351546966368884609U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 22U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 52U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterH, 26U)) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10923U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 12517U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15482U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13672U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10340U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15931U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11563U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 37U)) + 1142447269198373880U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 10581460640040336191U) + aNonceWordN;
            aOrbiterG = ((aWandererF + RotL64(aCross, 27U)) + 14703062773878202900U) + aNonceWordC;
            aOrbiterC = ((((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 15737525756286914746U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 16178774478273186999U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2514897053906809160U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13702496607592508464U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16540143680974064057U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18030885275418337965U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 5241783876161655984U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 10970981186787227937U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2807052676283587925U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8022804576763271327U;
            aOrbiterE = RotL64((aOrbiterE * 11727096043219370577U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15597099852232205860U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1538435607932096400U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7900752511710516981U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11147868774413615365U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9325213746830411568U;
            aOrbiterA = RotL64((aOrbiterA * 561819005818948769U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + aNonceWordA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aCross, 44U) + RotL64(aOrbiterA, 26U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21284U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 18011U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17013U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 22330U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19754U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22596U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19276U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 37U)) + 3650233661228036955U) + aNonceWordB;
            aOrbiterC = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 11607036400067735729U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 3899614406903883035U) + aNonceWordL;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 8159156925629965143U) + aNonceWordN;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 48U)) + 7148903913967261270U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9161665622287517848U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2981535013474059469U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 4434815231517266013U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 15812469008200319549U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14687469489893270300U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14142363399696670451U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6025209349511417063U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 12964750392311112676U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 12955480283032701843U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6572355895765394340U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3542300121890027981U;
            aOrbiterG = RotL64((aOrbiterG * 11201491178181273935U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6477175684045398359U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1081388388827929314U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8752188637514143529U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterF, 21U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterF, 36U)) + aNonceWordI);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25130U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 27123U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 25501U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 32066U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28011U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27602U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31007U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 11698283336767769359U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 13297826354831483872U) + aNonceWordK;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 15254999058287530795U) + aNonceWordC;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 51U)) + 17474166585085346567U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (((aWandererA + RotL64(aCross, 12U)) + 15684783498452840289U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 5061229733465216486U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15370981279168377944U;
            aOrbiterG = RotL64((aOrbiterG * 15893028157665379361U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17966672773619554092U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14685092893994491068U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1627758964162892429U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12798804186209406389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2848444181474221574U;
            aOrbiterK = RotL64((aOrbiterK * 13730480364920876877U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8551142075919636146U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8833198159158950723U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 7650289040764974737U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7351473160893666232U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14204899612487622222U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 6U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 12U)) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_PickleBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB27FC265108FFFF5ULL + 0xE9E1A6BF57D68B71ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x88CED9E953997995ULL + 0x8B2AE4DCD9258BA4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8B0AC57E108867CBULL + 0xD8212EA35B4754C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD8FFC05376131B23ULL + 0x99C261E4A7A574D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA555B9A769E10CAFULL + 0xF43A0732A1DC2611ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD0C65374F06E245FULL + 0xADBC49D188999664ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCE5BCC64F3DFBB23ULL + 0xADC3D10B9C7118C8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE89CCB440CF45725ULL + 0xA8C9DC6DE133A5DDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB7250A2161C18C91ULL + 0x83A3B9270FF8B602ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB05C286547E011DBULL + 0x8085226295F92C32ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9BEB784DC8E9D4AFULL + 0xFD04D06E8223731BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCE52DE7CFE4296EBULL + 0xB407D4C99E107395ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA4077B693ED4866FULL + 0xDBAAFD6EEE9FBC15ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8EB60C6E7F981593ULL + 0xE640253FB0E9448AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC5EB03921E213E87ULL + 0xD3B801B503B4C2F7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFB208FFE39594E31ULL + 0x881137CA37E3FD4DULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2678U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 6126U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1048U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6233U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7855U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5573U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 56U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 12849591986267890852U) + aNonceWordI;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 53U)) + 8232614804696815750U) + aNonceWordE;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 12141567259210877281U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 13U)) + 2928641981037885644U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 39U)) + 980733350554783938U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 60U)) + 2683985177993350746U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 14532148403815527355U) + aNonceWordO;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7736296629433884203U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10428437770166310549U;
            aOrbiterJ = RotL64((aOrbiterJ * 326634742742373401U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18327174144859461029U) + aNonceWordJ;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 2715987179577753597U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12606153309690753435U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17123256945895150555U;
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9057777759026189541U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16478485918911194442U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11054247078884894131U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18064460487552100483U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11477276762421684083U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 3886501230380184395U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18318375441973295081U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13849305985380030986U;
            aOrbiterB = RotL64((aOrbiterB * 12962140243967824959U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10240409420338313641U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18360586077779529086U;
            aOrbiterF = RotL64((aOrbiterF * 18196875422391501927U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 50U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15744U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 9481U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9979U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11513U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14425U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16307U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11661U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 28U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 10038936806177516123U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 1773168435195292638U) + aNonceWordB;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 35U)) + 10655711161526628072U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 53U)) + 14422295664639740437U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 60U)) + 4125228715513159576U) + aNonceWordN;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 27U)) + 3670449653158650845U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 17553727567180813057U) + aNonceWordJ;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 5111401772713882743U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7688573124662314413U;
            aOrbiterA = RotL64((aOrbiterA * 10846442063022821393U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9438375825507814395U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14177477039902118886U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6467406626985022537U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 16329942595859623928U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3990536794006836672U;
            aOrbiterG = RotL64((aOrbiterG * 579024714339065373U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 5072881436583180756U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16789727877867289997U;
            aOrbiterJ = RotL64((aOrbiterJ * 8766246302636197905U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17313956922306689438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11530878396329822041U;
            aOrbiterB = RotL64((aOrbiterB * 11356860047841383129U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3612616532321160196U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4172189825359187763U;
            aOrbiterE = RotL64((aOrbiterE * 12938945495299393177U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8677279703778052804U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1912172980909479362U;
            aOrbiterC = RotL64((aOrbiterC * 10053289257955474143U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 58U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19843U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 23655U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17824U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 23336U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21043U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19755U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21210U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 29U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 6318740973868639425U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 5U)) + 5487840061430920881U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 10258706763248072672U) + aNonceWordH;
            aOrbiterB = ((((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 18356875269730338208U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 60U)) + 12883160282903147010U) + aNonceWordJ;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 53U)) + 1010140474942697730U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererK + RotL64(aScatter, 47U)) + 17733939421700898293U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13693055887924981201U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14574732452793385269U;
            aOrbiterJ = RotL64((aOrbiterJ * 9373765929885750185U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10832873941223609012U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8212600587135328040U;
            aOrbiterH = RotL64((aOrbiterH * 5334613996794796145U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5312744319781971178U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12854414066390848249U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3693249147883790810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18365859989736602556U;
            aOrbiterB = RotL64((aOrbiterB * 3348463719324104997U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 10645056678337549771U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1175668356822251045U;
            aOrbiterD = RotL64((aOrbiterD * 6579675292775345579U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13556844570541823717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4790355739411849736U;
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14905575502272644116U) + aNonceWordL;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 17047244574558476634U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + aNonceWordB) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 14U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28400U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 30216U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 32319U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26046U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26352U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30802U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 31951U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (aWandererH + RotL64(aCross, 4U)) + 7896237440058555694U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 47U)) + 11870529476037558635U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 13U)) + 9158983227801569448U) + aNonceWordB;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 4710172270996950329U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 23U)) + 14634482800356647630U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 8822207952170610891U) + aNonceWordG;
            aOrbiterC = ((((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 13755891414028982553U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4555293067488040719U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2816805148093762081U;
            aOrbiterA = RotL64((aOrbiterA * 16838149138341713943U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2122631477965135190U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4592922416380416071U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 11644507904538573165U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7102471666524164715U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17274623547879474204U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5443572270546181789U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 938587316977094680U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18258015823797023523U;
            aOrbiterC = RotL64((aOrbiterC * 6068819567674605919U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5809987756043471595U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5083075160112581620U;
            aOrbiterG = RotL64((aOrbiterG * 3313957222154937503U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5960021727750946496U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5967477320950630150U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 330964768256424655U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6578428711689296132U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5601728218197771276U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 9552559022315971847U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 6U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_PickleBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB0236CFC47405347ULL + 0x8640222F188DF387ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFFDC574B4702D4D7ULL + 0x917CCF335BA397C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x871196696C86B307ULL + 0xB5C484FEF1C21EAEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDCE5411D916F52AFULL + 0xB929930C2896BF97ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8F4095EBAAA061CDULL + 0xDEFFAA56EEA5DFD0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD921339FF51C25D5ULL + 0xF445C2D34B6516C6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEED84692B195005FULL + 0xC86B3CD57A45BEACULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB69ED9870AF584E9ULL + 0x8366A19BB3A15648ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA587028511F096B1ULL + 0x950A9E6102C9C00DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9F113070925E201BULL + 0xFBDC0E7A40CDC4D1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8AE6BA0784D5EC73ULL + 0xB43D1623D67CA585ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDCD4B850804B4237ULL + 0x9A6158EE49BEB4D1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9F1079F776614DFBULL + 0xAFB0AE0D8A356EE1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE1B12ED01E504C2BULL + 0xCA96580CBEB65960ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8D077926E7C613A3ULL + 0xFBFACD6C92D52791ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD47A90D697D3177DULL + 0xA84AAE49A2117758ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aExpandLaneA, aOperationLaneD, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2298U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 958U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 2064U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2447U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2554U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 26U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 13481227414590594621U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 47U)) + 17425964381118918026U) + aNonceWordI;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 41U)) + 4792004356135956581U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 11926849936000639098U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 990697329347742142U) + aNonceWordH;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 60U)) + 9307721505373076588U) + aNonceWordL;
            aOrbiterD = (aWandererK + RotL64(aScatter, 53U)) + 17605732738841908719U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13110764518634187439U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 17970109897810645911U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 10395095143998920213U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10273133817644703654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11239046688920468137U;
            aOrbiterI = RotL64((aOrbiterI * 5197802934333553327U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8355821483275763145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15522151127786049345U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 4844278537850520413U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5381663179722418112U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9551368011768104906U;
            aOrbiterC = RotL64((aOrbiterC * 14202470972121732997U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16264476585232221270U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7721417776432288282U;
            aOrbiterE = RotL64((aOrbiterE * 10267770327791051869U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 339418090653475277U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3390560045236418590U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3894024951542543635U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10599637790900418767U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 50U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aFireLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aFireLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aWorkLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 8013U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 10353U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9975U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5629U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7856U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8334U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 37U)) + 5480870806135400132U) + aNonceWordH;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 8034874599430768743U) + aNonceWordM;
            aOrbiterH = ((aWandererC + RotL64(aCross, 5U)) + 4006919843736863767U) + aNonceWordA;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 3U)) + 2988069748674633718U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 12347295651973135786U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 14152683894431568192U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 11U)) + 15765143815254196598U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10473067082331244233U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1089466925383677249U;
            aOrbiterH = RotL64((aOrbiterH * 17334888609179149753U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13215039929873682230U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3957997712247961479U;
            aOrbiterB = RotL64((aOrbiterB * 7631186240013784703U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10023907397941685546U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14593012591254614353U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13353797968154036726U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9259966668512102858U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 8326732574268308221U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10757861831070349321U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10530223113483866178U;
            aOrbiterC = RotL64((aOrbiterC * 11269177745265396583U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7554320926405521865U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 6978052067277966996U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 18020134738536217801U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1053695861967171420U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15980734683539854451U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3208466640010555357U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 52U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aFireLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aFireLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aFireLaneA
        // cross directions: aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 15457U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 12874U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15727U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12026U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((aIndex + 13886U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 60U)) + 18087125778766689269U;
            aOrbiterB = (aWandererF + RotL64(aCross, 5U)) + 13710545066503235196U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 1701939704736254645U;
            aOrbiterD = ((((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 8064093611384019909U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 16623332751533885431U) + aNonceWordD;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 15590129153794910109U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 35U)) + 7413312683079107383U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4186064478651458810U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5501191643940735954U;
            aOrbiterC = RotL64((aOrbiterC * 14254804649177125269U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11064645242200570835U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 13825922087298055833U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 7529317892716108867U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5944980709887369970U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8181136916070569646U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 395183021205661827U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15442336949157292482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11580554435240641337U;
            aOrbiterK = RotL64((aOrbiterK * 6654637892858767739U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11240018128174598322U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2027565596050777471U;
            aOrbiterH = RotL64((aOrbiterH * 18048186560314431815U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 16425887196883725233U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16828683527588834095U;
            aOrbiterD = RotL64((aOrbiterD * 17746289103235902485U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9923829146479008804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6669171007279929454U;
            aOrbiterB = RotL64((aOrbiterB * 681823450939955099U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 28U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 12U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aFireLaneB, aWorkLaneD
        // cross directions: aFireLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16589U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 16815U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 21076U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18216U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21711U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 701291026547470433U) + aNonceWordN;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 5U)) + 17283292650462111643U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 27U)) + 9969124091931303406U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 889176772718046988U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 58U)) + 6054541844643748084U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 19U)) + 14703226235143028132U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 7977975878522921062U) + aNonceWordH;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16894322614172266274U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12160451749345900570U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18055355572903901749U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10870847008043897470U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8159920947172520247U;
            aOrbiterB = RotL64((aOrbiterB * 4833194641611011805U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2440099120969517932U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 2428396147731468007U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2213226274394673479U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7079731443427765333U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16918930776877030559U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 958896789550478970U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10788682955708075458U;
            aOrbiterE = RotL64((aOrbiterE * 913321215613559729U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2003386579317564870U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8419686358774204999U;
            aOrbiterC = RotL64((aOrbiterC * 6547052526438697621U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6989167615157578904U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17636634003643824148U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11038576417283732937U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterC, 24U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 5
        // ingress from: aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneB[((aIndex + 26551U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 22729U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23524U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 27170U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 53U)) + 4980738603982643969U) + aNonceWordE;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 60U)) + 17660278413018470020U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererK + RotL64(aCross, 13U)) + 17598114429859543466U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 10993929335279994739U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 17967203122976322481U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 21U)) + 1872290205549034384U) + aNonceWordF;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 16607778671782810797U) + aNonceWordN;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4895226930754394376U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 14960359005982301383U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 8546231310054433721U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9921642352377700630U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 893281964367208693U;
            aOrbiterD = RotL64((aOrbiterD * 2345509157333444217U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8232519988397858732U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4433022122758913407U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 834240393225479419U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12689609831247168353U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 404535388957472176U;
            aOrbiterI = RotL64((aOrbiterI * 14534020545479806593U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3349108201964013155U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4386449511297371730U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9596273264321140229U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14314587717949070586U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10923886625271054985U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7838969002623486809U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17634909585329833520U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2021301459918350372U;
            aOrbiterA = RotL64((aOrbiterA * 1388242915918642741U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 18U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 44U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + aNonceWordB);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 28539U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31803U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32461U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 32528U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 20U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 53U)) + 12535417189990029950U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 6204401443676390273U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 869613505613154672U) + aNonceWordJ;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 44U)) + 15053590879563855802U) + aNonceWordH;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 35U)) + 13338989605204591428U) + aNonceWordF;
            aOrbiterC = ((((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 18306470022403825392U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 13U)) + 1150696349434090218U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13549541786420596437U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14302878430259588461U;
            aOrbiterE = RotL64((aOrbiterE * 16813606782134305513U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4660437084477165225U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1653628537860912069U;
            aOrbiterG = RotL64((aOrbiterG * 2624835201155303123U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5594199757006711631U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11008472193138708891U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13645764762027798301U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3668516817279364310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 128159531749679984U;
            aOrbiterC = RotL64((aOrbiterC * 4523246859249826987U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6378674346113979108U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11438762460659123362U;
            aOrbiterB = RotL64((aOrbiterB * 2733309638158283953U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10624263004446482910U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12546839706919241411U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11468326687628079347U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 8466639576503293921U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5828694979857951504U;
            aOrbiterD = RotL64((aOrbiterD * 7835487310289634515U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 4U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterG, 37U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 44U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_PickleBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x81E67325B3BDF6EBULL + 0xFE9851A3A4AAF13BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCC74EF339A6E1D67ULL + 0x9DBEAE33503006B7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC37D330A221905C5ULL + 0xC4E1D0528B477792ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x935ECB2FFCC66F67ULL + 0xC8954203F4CB848CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFA61C5363DCF08E5ULL + 0xB43A335D829856C7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB95641986EA9C147ULL + 0xAA6EB350471241F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCBC4FB3EDB5EAC63ULL + 0x89679B4D937A470EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE702BC15B2D89E1DULL + 0xA93FB7AF01B85DF8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x88C10626AECE2BE3ULL + 0xA2C8B9A97F73BE71ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD133AFABCA5D93C7ULL + 0xA4EBEDE6ED905BDAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB74F10AC02CAF5E5ULL + 0xE16563057E0694FDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xECA2E4BBC409F2ADULL + 0xC8FC6649839CFF4FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x83D117C897C64ED1ULL + 0x881CA8CC93D1A2E2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBA30EEE88FA2D86FULL + 0xED457802192F2C94ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x843F5AF9C502B537ULL + 0x876A7A610914D57BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBCA0354F1626D7DBULL + 0xDA9844551EAA564BULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4744U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 2749U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7627U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5562U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5203U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 8152U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 6U)) + 15036852811491820366U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 29U)) + 305637140752898475U) + aNonceWordB;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 11948631574496129610U) + aNonceWordL;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 27U)) + 5321623592482991426U) + aNonceWordD;
            aOrbiterE = (aWandererB + RotL64(aScatter, 41U)) + 4075270159062690728U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 24U)) + 15111580500356908928U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 7244150695504160363U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 13U)) + 5131563519577488862U) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 5881954992088651371U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 57U)) + 12780935808751507998U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 37U)) + 12599159643925470226U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9466589929741834066U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6093158735705189789U;
            aOrbiterA = RotL64((aOrbiterA * 7453778295800853653U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17461243886150519249U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15456408913739900718U;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11260643903290392780U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7870342756041882616U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 134484990005888936U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10626896209992890407U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 12034131076645285597U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14031164129515132292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1771835705730244212U;
            aOrbiterB = RotL64((aOrbiterB * 186981668443596623U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16395472745067254664U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1455944290845294254U;
            aOrbiterE = RotL64((aOrbiterE * 6757824754363319079U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17866422769075350837U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10226884082632410805U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 206035536985843815U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14474587247775371703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8501763445324525303U;
            aOrbiterD = RotL64((aOrbiterD * 5298694643596784007U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 222650368553738561U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3901452368735982094U;
            aOrbiterI = RotL64((aOrbiterI * 18347115513126660483U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3063093906728331146U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9026710562384443411U;
            aOrbiterJ = RotL64((aOrbiterJ * 8411243802199203035U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11282041925238364080U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15036852811491820366U;
            aOrbiterK = RotL64((aOrbiterK * 18185121326941087841U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterD, 60U)) + aNonceWordC) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterE, 20U)) + RotL64(aCarry, 21U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 36U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12547U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 8402U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9871U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12809U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9005U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13622U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11380U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 4980738603982643969U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 60U)) + 17660278413018470020U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 13U)) + 17598114429859543466U) + aNonceWordA;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 10993929335279994739U) + aNonceWordL;
            aOrbiterE = ((aWandererK + RotL64(aCross, 35U)) + 17967203122976322481U) + aNonceWordP;
            aOrbiterD = (aWandererF + RotL64(aScatter, 29U)) + 1872290205549034384U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 47U)) + 16607778671782810797U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 4895226930754394376U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 53U)) + 14960359005982301383U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 42U)) + 9921642352377700630U;
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 893281964367208693U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8232519988397858732U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4433022122758913407U;
            aOrbiterF = RotL64((aOrbiterF * 834240393225479419U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12689609831247168353U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 404535388957472176U;
            aOrbiterE = RotL64((aOrbiterE * 14534020545479806593U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3349108201964013155U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4386449511297371730U;
            aOrbiterG = RotL64((aOrbiterG * 9596273264321140229U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14314587717949070586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10923886625271054985U;
            aOrbiterD = RotL64((aOrbiterD * 7838969002623486809U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17634909585329833520U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2021301459918350372U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 1388242915918642741U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5219599112498224367U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 10641339455385046206U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 1022283727595400719U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 5003342156562330058U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10951027475628404336U;
            aOrbiterA = RotL64((aOrbiterA * 17836928292555158461U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13040991872592235460U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11149099984302782267U;
            aOrbiterB = RotL64((aOrbiterB * 4248667283139686251U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2202253777854402763U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16679038924474862612U;
            aOrbiterH = RotL64((aOrbiterH * 2624443661523083597U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1959650241410955571U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8415989510614674816U;
            aOrbiterK = RotL64((aOrbiterK * 16340289102832732519U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2344501711730399821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4980738603982643969U;
            aOrbiterC = RotL64((aOrbiterC * 6419275275477478723U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 6U)) + aOrbiterC) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 44U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + aNonceWordG);
            aWandererB = aWandererB + (((RotL64(aCross, 24U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17690U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 21412U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 23983U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17926U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24390U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19738U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24570U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 1866656689936219099U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 41U)) + 2312314528139448289U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 46U)) + 3554037526469185237U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 53U)) + 405707755060974111U;
            aOrbiterB = (aWandererC + RotL64(aCross, 21U)) + 1862976326004007697U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 12992483065443288263U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 28U)) + 3793854946371595197U) + aNonceWordI;
            aOrbiterH = (aWandererK + RotL64(aScatter, 3U)) + 4244007978867369382U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 10280867500312580308U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 39U)) + 472563452959164242U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 12041770406895816553U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6118634015704900486U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13637107920449233307U;
            aOrbiterC = RotL64((aOrbiterC * 17712028184714868053U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16673735670669318830U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8602681273646630496U;
            aOrbiterG = RotL64((aOrbiterG * 6995213887710749241U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7683264695930369476U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9146674871199188218U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 7403427067419261981U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3012935612827493084U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1259789268731661945U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2372843620327050137U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5623690455471160780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18355567776031865462U;
            aOrbiterJ = RotL64((aOrbiterJ * 9553862670107886679U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7705134893833304792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4435192506444773834U;
            aOrbiterD = RotL64((aOrbiterD * 5249651218395299501U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6204683785806409075U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17886971535016484255U;
            aOrbiterI = RotL64((aOrbiterI * 6047216474762933535U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4430578901091376829U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 607557685798141547U;
            aOrbiterK = RotL64((aOrbiterK * 12342665567201483107U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18258994761911545002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 634391404805006992U;
            aOrbiterH = RotL64((aOrbiterH * 5761143438450180463U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8528044138264666860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3867692060293315964U;
            aOrbiterE = RotL64((aOrbiterE * 8285164562893231087U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8333438209201978886U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1866656689936219099U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 3935928308329865425U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 22U) + RotL64(aOrbiterK, 60U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31286U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 24763U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25674U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 30496U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27492U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29252U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 30973U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 57U)) + 13053031069776604052U) + aNonceWordO;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 36U)) + RotL64(aCarry, 57U)) + 1331396630251085122U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 15879286043343942393U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 13590365633321406830U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 51U)) + 14569235423040242618U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 11U)) + 11397370636618371560U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 34U)) + 3455933494593971847U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererI + RotL64(aIngress, 29U)) + 1307153376443784593U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 13U)) + 10688618762584786871U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 47U)) + 17746248451153600096U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererJ + RotL64(aCross, 19U)) + 8512568600755410158U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8950230550112591092U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterA = RotL64((aOrbiterA * 5104988920132008913U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12583323865381967534U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11243927099685293887U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 12867003042486433971U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9690268715525781389U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7466066217365074653U;
            aOrbiterE = RotL64((aOrbiterE * 17565696765505320889U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3673528673209875118U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14079103852360952255U;
            aOrbiterJ = RotL64((aOrbiterJ * 17449228863409999629U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6747836856132250630U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5027692924422297153U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2492421273167124437U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11370341866003395776U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14013204893442579282U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6602239957997240785U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3436953430697936790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6399073534839993637U;
            aOrbiterD = RotL64((aOrbiterD * 14186050072610021241U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7054057507823631422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5752085719673338095U;
            aOrbiterK = RotL64((aOrbiterK * 13252660162476029593U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10628323020010327594U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5029617362660411790U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7230663968894173433U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6816547880074551571U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6683840259024813282U;
            aOrbiterC = RotL64((aOrbiterC * 13145224557159574541U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5952768353050729617U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13053031069776604052U;
            aOrbiterI = RotL64((aOrbiterI * 13710064584055068065U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 4U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 6U)) + aOrbiterA) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 60U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 40U) + aOrbiterJ) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_PickleBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD07B8600432CF287ULL + 0xF2393FC753A0EAABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF8202ACBF1B1973BULL + 0xA0C367E39C49DD95ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCEF8E6B1F27E6191ULL + 0x835EF40DE8AEDAA1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xED8572AA7971B4D3ULL + 0xDF1D134FBB1165A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE91F8DD0F7F483BFULL + 0xBEAFDD8753DC979BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCF401499346668A9ULL + 0x9D25AEEEA6B8D1B7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8EC4E884822FED4DULL + 0xEBC0326ED94AC83EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB5361A1364CB8BB5ULL + 0xA09233E32200F5CFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBE8329E9F766AB0DULL + 0xA9CA491F1285A4ECULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA0AFAC528FB39D8DULL + 0xBF3B9DD48F1354E0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDE575D5520D6561BULL + 0x97F92FF4A6CED11CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFC638F9F5FDAF94FULL + 0xFA4D40AC96B4D603ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEB16AD5D9128F643ULL + 0x860BAC245773E93EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8482C432352A5D3BULL + 0x9C8676DEC94CE7B5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x84A2FB8E180BFCB1ULL + 0xAE662FCAF691FA8BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEB45105036650C7FULL + 0xAEB9CF62B3871B06ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aWorkLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4262U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 2278U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7512U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5144U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3871U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 8111U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 7893287783892523139U) + aNonceWordP;
            aOrbiterC = (aWandererK + RotL64(aIngress, 27U)) + 10257331997383491153U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 35U)) + 14562226733652231753U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 41U)) + 14320342577110737851U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 11U)) + 9816717579822880756U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 5U)) + 9558926960095881953U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 19U)) + 9230371862654338324U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 57U)) + 6414274291252913420U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 46U)) + RotL64(aCarry, 23U)) + 13868546184398350849U) + aNonceWordO;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16940736952569949038U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2866957764814864371U;
            aOrbiterK = RotL64((aOrbiterK * 3554702178644797003U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7916721976073979724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1602444214978842275U;
            aOrbiterJ = RotL64((aOrbiterJ * 11072503711308122385U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9529061385251008037U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8402775110887376588U;
            aOrbiterD = RotL64((aOrbiterD * 13980225144628227381U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15003592180290390713U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14195681406520825751U;
            aOrbiterE = RotL64((aOrbiterE * 11455000833788877217U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3263577002367714202U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12019422062655581928U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5002313835338447799U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8508638054582582917U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6536618106353552880U;
            aOrbiterG = RotL64((aOrbiterG * 6233964121117511885U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9654542989321430868U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7019594782797863244U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1234877854354279981U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8256061220727519919U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9232754129467036130U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 17556001874302369781U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5608829951337740378U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12632120498473345701U;
            aOrbiterF = RotL64((aOrbiterF * 6994794653605831925U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 34U)) + aOrbiterJ) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 60U)) + aOrbiterD) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aScatter, 12U) + RotL64(aOrbiterF, 27U)) + aOrbiterI) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13414U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 15195U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9953U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 14266U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13330U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12430U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8691U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 10U)) + 18144572925667544139U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 5659758077574059728U) + aNonceWordA;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 6343330616999166392U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 27U)) + 17754639838410839447U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 9451843819849581729U;
            aOrbiterI = (aWandererA + RotL64(aCross, 3U)) + 7957854457197462212U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 51U)) + 1461994799722205010U) + aNonceWordI;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 40U)) + RotL64(aCarry, 35U)) + 18002214276252170177U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 14689869073147027164U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3978104368003440293U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8512135845221335386U;
            aOrbiterA = RotL64((aOrbiterA * 10506667163729414667U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1477533446382953439U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2166717790929947990U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6538884492418324461U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8082437060686606995U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4363687722464700362U;
            aOrbiterF = RotL64((aOrbiterF * 7199165810993478887U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15782763348014924206U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8572509150015960728U;
            aOrbiterI = RotL64((aOrbiterI * 3340528604891897779U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12248271773316742521U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9602078627638561949U;
            aOrbiterK = RotL64((aOrbiterK * 1860631869877427405U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17244849374768558859U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1030743048280579012U;
            aOrbiterB = RotL64((aOrbiterB * 10858949914285817051U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17722342363541914280U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15667504059789880034U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 15872269872168533709U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12645332941998550794U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9938135244509986497U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16548185968987392957U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4024609904162105979U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6732064218696157303U;
            aOrbiterE = RotL64((aOrbiterE * 3815409766145891393U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 30U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 14U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 20U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16795U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 17790U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21089U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23069U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21210U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18269U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18283U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 22U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererC + RotL64(aScatter, 19U)) + 15813325389431304548U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 34U)) + RotL64(aCarry, 41U)) + 2223874171125403602U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 5510483568496824130U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 23U)) + 15474152493495661876U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 16846339705130829195U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 5U)) + 1289670576865739669U) + aNonceWordF;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 38U)) + 18017354919647006944U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 43U)) + 8539685539928984921U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 53U)) + 3333721400836704048U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2261560416623815491U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4377786131746816567U;
            aOrbiterA = RotL64((aOrbiterA * 9164777834392621157U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 18047393176583722719U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8184724021940434631U;
            aOrbiterI = RotL64((aOrbiterI * 9800116157750921119U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10469895939183324807U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14543391765109879223U;
            aOrbiterF = RotL64((aOrbiterF * 4817987697437667225U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5757225781746158178U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3539000495894022869U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1032298408884695925U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11288971092707065923U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 2761384065186568294U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 3323838837427471051U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7120580145300417101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6977246291769372866U;
            aOrbiterK = RotL64((aOrbiterK * 15170353875184253779U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17625434527765525937U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 3299714663631376190U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6532628892760776767U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10331889953489885250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8550932256881727932U;
            aOrbiterG = RotL64((aOrbiterG * 13085531621192583719U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11151195711186126257U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2552002192824926483U;
            aOrbiterE = RotL64((aOrbiterE * 9754056316698523849U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 46U)) + aOrbiterE) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterB, 30U));
            aWandererD = aWandererD + ((((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28698U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 32667U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 24628U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 25788U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25084U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29997U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28079U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 36U)) + 5721224134332887360U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 6892749729775049095U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 3884839462099556836U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 19U)) + 4365431706830216193U) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aScatter, 56U)) + 15501528746571578773U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 5U)) + 4505911326320650606U) + aNonceWordC;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 1865129050927879580U) + aNonceWordN;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 47U)) + 2011737665969640369U) + aNonceWordP;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + 611672935827062688U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 663547038310431047U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5468932264754299556U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11968657455484578525U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17920294117231191705U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 486058453837528110U;
            aOrbiterK = RotL64((aOrbiterK * 8851102552244026737U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2789178451938129313U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 420772587981211184U;
            aOrbiterA = RotL64((aOrbiterA * 17402987842294006667U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16196774774442181825U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16264169656793713547U;
            aOrbiterE = RotL64((aOrbiterE * 6900221986041638783U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10207659833859860796U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8593749091183323678U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10696776033512404927U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7224922076047787384U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15366267474865172373U;
            aOrbiterH = RotL64((aOrbiterH * 10134187073321814217U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4235342515820080294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5239480080426950612U;
            aOrbiterB = RotL64((aOrbiterB * 12077621553561927079U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10891752830598395582U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7797358829694471108U;
            aOrbiterJ = RotL64((aOrbiterJ * 7621206775460997431U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3755715857903753416U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3172069024987421726U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16048490837178650865U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 30U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterK, 14U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_PickleBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF6D35A3794A44C53ULL + 0x97D36CD66F54ED7EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF3E3155BC9574875ULL + 0xC959C5E91EBCF125ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB8A917B619B7EED3ULL + 0xC06D846D279DFD38ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE8CF14C359C292FFULL + 0xE0317F4508791DAAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xED270920E0F733B3ULL + 0xB99C3FF92B554C33ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE7A9997497D185FBULL + 0xEE55FC4C23D37F50ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x850BBF9F24118F5FULL + 0xD53A21D609B207E2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x98C16FD6CDC5119BULL + 0xA6235E2BD635A832ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFABB594940433771ULL + 0xCCBB05A24B753505ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA4AD997816960CBBULL + 0xC414A4FF1269F313ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8B67F66CB850DAC3ULL + 0xCB8FFD83CD3A93C1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE6A4F2B77F220C4DULL + 0xCCA647B29E42173FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBBF1A0AE6F9A98DBULL + 0xA463C5CC50C4B5E0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA07A7B9DF2A90DF3ULL + 0xB2AA161C54239824ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9D0DC2EC47700B0DULL + 0xE949FBD8E794B530ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x81DF8CA89F806683ULL + 0xFAC93DFB40AE8F2CULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1325U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 8108U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3446U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6129U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7916U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5721U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 77518479758428414U) + aNonceWordC;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 51U)) + 4832061802166300011U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 5U)) + 11695291171006574112U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 13U)) + 7467412817843260094U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 17801484124471154757U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 21U)) + 5555455638503958639U) + aNonceWordH;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 29U)) + 5669470540733721606U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3042388456327784163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2236734925228156691U;
            aOrbiterA = RotL64((aOrbiterA * 10076582424701705531U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14459720401528685450U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4814967631216658856U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 18288097536171386643U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16950679344449075945U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6262238639302011050U;
            aOrbiterD = RotL64((aOrbiterD * 9942659897425088183U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3522256359074996724U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12524717897707074242U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13891759914865623828U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11910250571469028666U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 12311343917878428995U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2240189915640314069U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5365912986308810837U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15133972552032469957U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9323732721344489753U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 13087326560957916553U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 14659491687401151733U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterD, 10U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11275U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 8230U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 14961U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 13696U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14596U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13116U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14971U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 57U)) ^ (RotL64(aIngress, 18U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 9041099828460168106U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 3U)) + 12883711604096848454U;
            aOrbiterA = ((((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 17420968786226443079U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + 3448213891716125104U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 22U)) + 11866455977445336560U) + aNonceWordL;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 4119356835384495905U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 43U)) + 2186212599698637068U) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6506144898969301620U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12556800923644051626U;
            aOrbiterA = RotL64((aOrbiterA * 15961043406612913121U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4075551535185182945U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17877694808492008749U;
            aOrbiterC = RotL64((aOrbiterC * 901315308379887473U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5553428900598223316U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14362304852277160675U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11415103199856419303U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9174200302876075831U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16110739511917638547U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7004356839428657949U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10189881974519849402U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 2128076632642616677U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 8860453653433114929U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18133523799074400083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9916472958834153766U;
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10274457562795569227U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14134814273275356425U;
            aOrbiterH = RotL64((aOrbiterH * 15912501063665343159U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 39U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 12U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22035U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 22175U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 20154U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 23012U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16844U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17184U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22395U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 47U)) + 5171470532667965920U) + aNonceWordF;
            aOrbiterB = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 750549462358682403U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 13U)) + 3325689257577120525U) + aNonceWordM;
            aOrbiterF = ((((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 18031575461559790826U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererC + RotL64(aCross, 5U)) + 13874739537012288677U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 23U)) + 4250029868785016865U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 8211158803112611161U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1083939790236786027U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3446525462376962464U;
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6973817815000417325U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15230876489676945543U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7737039082964537651U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9359727659738755880U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8775170107816327654U;
            aOrbiterC = RotL64((aOrbiterC * 6910680458261008653U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11958941755525038545U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16966819714283167348U;
            aOrbiterK = RotL64((aOrbiterK * 16363457661846050749U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14556087985619763243U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17915047508377045221U;
            aOrbiterG = RotL64((aOrbiterG * 6727635453185130109U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8578745677485367222U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7002181668717618866U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 12329703532414955235U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3569939503066735457U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2956247934282522184U;
            aOrbiterF = RotL64((aOrbiterF * 9946650822131152531U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterG, 20U)) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28653U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 27138U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25203U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28063U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29357U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24883U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26363U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 56U)) + 2974056819475622600U) + aNonceWordJ;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 7345051759236356098U) + aNonceWordA;
            aOrbiterH = (((aWandererF + RotL64(aCross, 3U)) + 12738468816846628882U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 7694520596043297922U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 35U)) + 5530753590015084774U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 19U)) + 3776309161718383105U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 784780304358106404U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 8999942326995036509U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5194986506064092779U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15070787038006135963U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7920040007459652762U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11311997270710107937U;
            aOrbiterK = RotL64((aOrbiterK * 6227571709361790209U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5365231114813547251U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8630110234623825263U;
            aOrbiterD = RotL64((aOrbiterD * 2735881715888325759U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2358235238039571072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18059414891616491807U;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14526050556461782864U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6937282036603272474U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 14954512365270028029U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10105832250694931310U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3884223553012098137U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16340956813003906195U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10385284339549648087U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1257633893341505930U;
            aOrbiterB = RotL64((aOrbiterB * 2669950791270500977U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aIngress, 20U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 60U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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

void TwistExpander_PickleBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9AD0AE55E709D731ULL + 0xF7E08C2D17B8838BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCEA1F22063A05265ULL + 0xBFD5979E8764C889ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE183D9ACA2A31BA5ULL + 0xE6BC0A218AFC2784ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF5F0D5E0F6E8C287ULL + 0x8A10D468F3BD384FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA9B4D19BC3555251ULL + 0xF5EFBB5B0129D7A5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE13E3E4C9C96B087ULL + 0x821C07C115280421ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9F5F5648386C1317ULL + 0xFEB263C3F88E6E01ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB33BE8D100213679ULL + 0x8D56BB9F82907A7EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFA5C98801B9824B1ULL + 0x943C51E17A9266BDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBDB7C70AB226A35DULL + 0xAC2B156AD5EC8E82ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x979F368D213E626FULL + 0xD84CEB22490B92EDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB5EE129A678F5C05ULL + 0xD5C49AF139946CC5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB167793EB741B403ULL + 0xCD3CE9D6D17E09DAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x93D4E1B821A7588FULL + 0x99624E7BA0694366ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF9311410B9776D9FULL + 0xC3AE73AD7CA83377ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9652F58778ADE153ULL + 0xA47E19D38FB09680ULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2090U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[((aIndex + 2448U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1979U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 862U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 12046647397183218524U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 21U)) + 2760779375026461991U) + aNonceWordN;
            aOrbiterE = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 13735454443176855650U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 50U)) + RotL64(aCarry, 51U)) + 4370377000586647724U) + aNonceWordE;
            aOrbiterI = (aWandererA + RotL64(aScatter, 43U)) + 14566322384189969094U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 11U)) + 5056565959818422786U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 57U)) + 8795403810686579209U) + aNonceWordI;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9625947666256011567U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 1703669290934254701U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 5763881345676123583U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6664070663184147951U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2104148316797553431U;
            aOrbiterI = RotL64((aOrbiterI * 12887842067180975983U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1197910004222596145U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9922977170060903197U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13047828062605568603U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2048376210852567829U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12568990647075931409U;
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15026894775772902751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3439447160137900629U;
            aOrbiterC = RotL64((aOrbiterC * 1813754963043785165U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6532671388552829796U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17261098369835997661U;
            aOrbiterG = RotL64((aOrbiterG * 568292591215203521U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3171300991007459947U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 5935563269327662024U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 11271790283157765003U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + aPhaseEWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 12U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 4277U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 5445U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3900U)) & W_KEY1], 10U) ^ RotL64(mSource[((aIndex + 3211U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 2225397913940961213U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 8342544893601343643U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 11U)) + 162922186381417187U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 11660218373710972210U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 5U)) + 14909034764605802354U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + 16776955237009701511U) + aNonceWordD;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 58U)) + 5834487809188925253U) + aNonceWordI;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1498492772767040320U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4161765458781579617U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15535994410289065281U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10511923076962447765U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 8575954471692620021U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 12526744988828982731U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6536325446331340573U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1790628986900286346U;
            aOrbiterF = RotL64((aOrbiterF * 5262997114200816715U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2623814807619278590U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11676970995834706612U;
            aOrbiterE = RotL64((aOrbiterE * 10057461115132434901U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13836786354224256591U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6293096163612129260U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8977954126326217153U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4271144764978661248U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15938494256992560202U;
            aOrbiterJ = RotL64((aOrbiterJ * 10004841288382726739U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11038155227307702976U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12408749795071243930U;
            aOrbiterD = RotL64((aOrbiterD * 5527720475032868855U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 4U)) + aOrbiterE) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterE, 41U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 5621U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8007U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5546U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5592U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 7758U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 43U)) + (RotL64(aCross, 60U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 47U)) + 7722279280863371124U) + aNonceWordE;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 3U)) + 11584220561732385598U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 57U)) + 7834679350105534657U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 22U)) + RotL64(aCarry, 11U)) + 11347994382444180879U) + aNonceWordA;
            aOrbiterD = ((((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 9449903188047063431U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererA + RotL64(aIngress, 35U)) + 6516243976652795170U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 8420815253991184777U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9081386852515170937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14375955191735286867U;
            aOrbiterH = RotL64((aOrbiterH * 2772840314542262283U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 880757589768436072U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3349856625725164229U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 681514212582331781U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7826309957607577207U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8057435761214313635U;
            aOrbiterF = RotL64((aOrbiterF * 4718430712767038607U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9565237500443303103U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterC = RotL64((aOrbiterC * 8457633439171452397U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3276844534476430842U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6828644383891274120U;
            aOrbiterD = RotL64((aOrbiterD * 979580351653410157U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 2815676923011504251U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5030251870850928417U;
            aOrbiterK = RotL64((aOrbiterK * 7075653570570819253U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13464083008377887034U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8994560761846897590U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9892839554658865143U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterA, 41U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 50U)) + aOrbiterA) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 10796U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 8377U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 9757U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneA[((aIndex + 9886U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8815U)) & W_KEY1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9024U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 29U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 57U)) + 18319689184146942855U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 43U)) + 8041304130090501019U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 11347064191990897738U) + aNonceWordN;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 15242243470024447468U) + aNonceWordI;
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + 10619749107163611105U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 13U)) + 14795614276221947128U) + aNonceWordH;
            aOrbiterI = (aWandererF + RotL64(aScatter, 23U)) + 1578095288886372393U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13593906305770501684U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8919815528334599172U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2033810402808238127U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17425548324720065145U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11125018338392347335U;
            aOrbiterK = RotL64((aOrbiterK * 4377887040461528587U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3779189180734244399U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10958224663276134041U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4317305352561612995U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4891139433808505355U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11507024985663120317U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5166074784835930965U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10080890270621589202U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13170894418184288695U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4501071771615514619U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6486573807774431753U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 324029625116648669U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15714881857668975753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3506619392820235900U;
            aOrbiterI = RotL64((aOrbiterI * 5707033870161224499U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 42U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 11464U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[((aIndex + 11029U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 10958U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 11051U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11396U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13366U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneC[((aIndex + 12390U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 14U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 21U)) + 12775735908960052604U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 11791373812080296887U) + aNonceWordL;
            aOrbiterF = ((((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 5537362877706057303U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + 2023912048504189380U) + aNonceWordP;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 5U)) + 17668828109963766893U;
            aOrbiterD = (aWandererD + RotL64(aCross, 53U)) + 558908629933941224U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 1479633119685446888U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15460320397843364063U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10059749397555469054U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8671817118586065469U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9987633811929693924U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10087337844580228269U;
            aOrbiterH = RotL64((aOrbiterH * 13817142288940843815U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9430197906134676162U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1226048679997253363U;
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10611580584157624739U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 3137391249289641509U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 5462682413239873181U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9327201928815412810U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7890659377013147073U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 10675114832750356941U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8804440385852327267U;
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 52U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + aNonceWordE) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 4U)) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aScatter, 36U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 15024U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14864U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14933U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15380U)) & W_KEY1], 35U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13911U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15766U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15749U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 42U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 60U)) + 8604208734152026945U) + aNonceWordB;
            aOrbiterA = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 1374329953253889829U) + aNonceWordC;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 19U)) + 5779278910548228339U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 17670451230882805140U) + aNonceWordO;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 8193848740764866860U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 43U)) + 15801168428145650104U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 3U)) + 2584718176087499066U) + aNonceWordP;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14950366247822737997U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9779293225265670135U;
            aOrbiterH = RotL64((aOrbiterH * 11625969538497982117U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8688968319288372383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13665723186950342601U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 292035540396910837U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 9395428688359973510U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2152719218018108418U;
            aOrbiterI = RotL64((aOrbiterI * 15271961483518392671U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1350324137411377992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8729317951386057921U;
            aOrbiterG = RotL64((aOrbiterG * 6008790836417785083U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6317310451893678411U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10175620379041384281U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 14079679617394330781U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1203082119358827708U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 523869107818193101U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4629501113595689157U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4028324959540432983U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15447631947468213912U;
            aOrbiterJ = RotL64((aOrbiterJ * 6037306615787729185U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 53U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 18U)) + aOrbiterD) + aNonceWordJ) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18462U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 17866U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(mSource[((aIndex + 19034U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17324U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18158U)) & W_KEY1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16764U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19034U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 9471546960258473684U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 57U)) + 18050235435948942244U) + aPhaseGOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 3005107102671544641U) + aNonceWordF;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 48U)) + RotL64(aCarry, 23U)) + 17898396434573801850U) + aNonceWordA;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 3U)) + 15071602525497771648U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 21U)) + 5780119462702672108U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 39U)) + 13301326224151025687U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18129323022260575961U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1199228670638790709U;
            aOrbiterH = RotL64((aOrbiterH * 1780426336211781025U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1839199978088021020U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4999517042246790165U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4585813675677234577U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8788607633376516299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15143903839930468749U;
            aOrbiterB = RotL64((aOrbiterB * 12735914889325422675U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16674732686428431869U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15908873150953195581U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18049755517524334107U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11204775359756474667U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2525984309543939465U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3988529812023791571U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4566345170476825512U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14876612901557406267U;
            aOrbiterK = RotL64((aOrbiterK * 9047956948845135339U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14926290877038883931U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 12710203178186614846U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 14841163494801662515U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aIngress, 46U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterH, 50U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20703U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 19267U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19432U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((aIndex + 20246U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21152U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19358U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21274U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 19580U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 8375305456876489425U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 16193562952772453047U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 54U)) + 18088652458594816223U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 37U)) + 767344788620249944U) + aNonceWordH;
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + 7705194930396368752U) + aNonceWordD;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 3829736891311272834U) + aNonceWordC;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 21U)) + 9881681671347640061U) + aPhaseGOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1721196560190164264U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3002652618388454213U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15289749311593032657U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9811621464004005202U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5652598941069986530U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 4797973356708091621U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6250499348327316328U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16025054277615264530U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 16446892258704281903U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13800298546867243172U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12256104592865905782U;
            aOrbiterJ = RotL64((aOrbiterJ * 16983140179497142713U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17817225416918329229U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17738671327352776217U;
            aOrbiterF = RotL64((aOrbiterF * 393488251327705063U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6816031224188400541U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16989563985059237014U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8677884225771717797U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16891524847268207549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1833508573940405571U;
            aOrbiterK = RotL64((aOrbiterK * 9709196587703979539U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + aPhaseGWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 4U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 14U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22788U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 24270U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21953U)) & W_KEY1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23406U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23391U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24292U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21910U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21997U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererK + RotL64(aScatter, 28U)) + RotL64(aCarry, 5U)) + 14008824488073394623U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 51U)) + 13317978415866411468U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 13209180141897453900U;
            aOrbiterF = (aWandererF + RotL64(aCross, 35U)) + 11870521586865233578U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 43U)) + 8052156380448047385U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 12158131176743680605U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 14674467487607719347U) + aNonceWordD;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18055496790566231147U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3838105585041578784U;
            aOrbiterA = RotL64((aOrbiterA * 1075709247574580091U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2839568255183054418U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11933612922864258179U;
            aOrbiterE = RotL64((aOrbiterE * 7571964469321160347U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6289849094151630580U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2640344350528492271U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16197726750829369365U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16306175266267657791U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3339898380394883600U;
            aOrbiterI = RotL64((aOrbiterI * 7105436590182982373U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 15017076663742800002U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 8973064296077602496U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 9309462227233615761U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17580319233338139859U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 14063208878807603874U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 16601475239075164585U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13326130855721009942U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12843186026737544416U;
            aOrbiterH = RotL64((aOrbiterH * 4975848122837321619U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterF, 39U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + aPhaseGWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26396U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 25427U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26446U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27162U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24586U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26722U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25977U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26526U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 41U)) + 3248574644570178787U) + aNonceWordF;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 3U)) + 4506961512959200024U) + aNonceWordJ;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 11U)) + 8423739774540738590U) + aPhaseHOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 6593975869641735337U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 16441716090557369103U) + aPhaseHOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 43U)) + 7936601450453207914U) + aNonceWordO;
            aOrbiterD = (aWandererH + RotL64(aCross, 21U)) + 13333752583560167065U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8013703284795432973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2349852779887439236U;
            aOrbiterC = RotL64((aOrbiterC * 2422888500648100783U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5318539364763284138U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11450957608502944376U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1957880366707810635U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9058992558327552687U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 632095686920230926U;
            aOrbiterJ = RotL64((aOrbiterJ * 12460364388358520799U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14734218428913777098U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16344357661370784442U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 15049472842002138369U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2981145363531184308U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 14176472085175714494U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2584623327412130939U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11198457590069700889U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 952584436750426828U;
            aOrbiterI = RotL64((aOrbiterI * 1165713888651280355U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4311591763498985972U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16194341833989936369U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 9997934560195932575U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 12U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 6U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + aNonceWordL) + aPhaseHWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 28U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28552U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 28491U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28001U)) & W_KEY1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27980U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29468U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28971U)) & S_BLOCK1], 42U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28306U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 27307U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 10805654776556844351U) + aNonceWordP;
            aOrbiterD = (aWandererF + RotL64(aCross, 51U)) + 582794182442795335U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 2858343650974681068U) + aNonceWordE;
            aOrbiterH = ((((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 8189584049022064284U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aWandererG + RotL64(aCross, 43U)) + 1565100751996962893U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 4U)) + 8062028016947611891U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 37U)) + 8280504280578451745U) + aPhaseHOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11326869194491655350U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1671695656567777163U;
            aOrbiterA = RotL64((aOrbiterA * 7511554500524257921U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2349843105293943452U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13015545152052004254U;
            aOrbiterG = RotL64((aOrbiterG * 1316662811685429983U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16703354404749291869U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8713231044374305801U;
            aOrbiterH = RotL64((aOrbiterH * 9242480982197688625U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11118401674497783533U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14857556493734710364U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3452566050389715195U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 12953419670951660965U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12666121730825089017U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 14049925256934142519U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11075249639473053423U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9374217688244187867U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 5261156325627117877U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17608340953291367867U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13159437499327086340U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4882100944453534805U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aNonceWordA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 42U));
            aWandererH = aWandererH + (((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 30777U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31976U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32272U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30059U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30741U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30440U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererB + RotL64(aIngress, 3U)) + 6771552164800695068U) + aNonceWordF;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 27U)) + 12131763371571322040U) + aNonceWordL;
            aOrbiterB = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 3326182381395522013U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 12288775097697156383U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 5195948373449796741U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 21U)) + 14404044002250137144U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 58U)) + 11142382920035825426U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2967149520256475485U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1470907369577818097U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9398653295177725883U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9231668148004163910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13078929163913892386U;
            aOrbiterA = RotL64((aOrbiterA * 7509829068700523627U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9485274692075657877U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12216951187543631673U;
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6933334652581744234U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17260276102423580920U;
            aOrbiterC = RotL64((aOrbiterC * 7796879893790990605U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 387767848169714392U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8597538259308082638U;
            aOrbiterD = RotL64((aOrbiterD * 4888054690557707241U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7996708724489146033U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15357384191688149939U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9827691726832491373U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17739222908739454637U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1614322333281471170U;
            aOrbiterH = RotL64((aOrbiterH * 7063116837752240891U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 21U)) + aOrbiterD) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_PickleBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFC3ECA28E3DDEE33ULL + 0xB43D837F7EAF50FDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD87156BC04ADD28DULL + 0xE2D808BCE011B4E7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC232FB7C802D7DD1ULL + 0xBB91625E64F2A2F2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF95B887A28815771ULL + 0xA0DB14C0FA8106E7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8EFE0B1F4B034983ULL + 0xDE26DB0FC9998CE9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB0035A321BDC3D1BULL + 0xF597D50C8DDEA5BDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCEA0FC79079A1447ULL + 0xEB714233599AB9AEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD371169E55C2F349ULL + 0x915AE004F4BDDDA9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9BE2077D0310EB99ULL + 0xAD48A0A5954040D9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x812FF4DFD16ED31BULL + 0xA90984FAB4463C35ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE3C36D6A943B0B31ULL + 0xB1DFEE0AA9B98F2BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFF49C6632558BB9DULL + 0xB0D94888DFA75D08ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9A5ACAC0C760C8A1ULL + 0xDD88E0A2626166FAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA7878C0968CDD9D5ULL + 0xFBA94D780B579AB8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD9EEFED240E10A87ULL + 0xB016941DEB1DB8D0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDF56258DF3873C6DULL + 0xA33B1B27C94D5021ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aInvestLaneA, aFireLaneC, aFireLaneD, aInvestLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2777U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 997U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2905U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 172U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1593U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4082U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 60U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererF + RotL64(aIngress, 26U)) + 13481227414590594621U) + aNonceWordO;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 17425964381118918026U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 4792004356135956581U) + aPhaseAOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 11926849936000639098U) + aNonceWordJ;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 35U)) + 990697329347742142U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9307721505373076588U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17605732738841908719U;
            aOrbiterH = RotL64((aOrbiterH * 13123627214143336281U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13110764518634187439U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17970109897810645911U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10395095143998920213U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10273133817644703654U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11239046688920468137U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 5197802934333553327U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8355821483275763145U) + aNonceWordH;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 15522151127786049345U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4844278537850520413U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5381663179722418112U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9551368011768104906U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14202470972121732997U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordG) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterG, 4U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8958U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 6539U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6981U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8642U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8451U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9050U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7911U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 13U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + 8402620908307642697U) + aNonceWordJ;
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 11347672014525086047U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 2816462912503401876U) + aNonceWordH;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 48U)) + RotL64(aCarry, 23U)) + 6940159795470696093U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aCross, 57U)) + 9134692490095883851U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4999455497008026526U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5992451460350651332U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12796550245322491401U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3417087346651371924U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3612773820086198270U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 5519856345435871169U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 463398077083428570U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11249391303705089012U;
            aOrbiterE = RotL64((aOrbiterE * 7106735772303292983U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17027535139825739501U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 568131384979596481U;
            aOrbiterI = RotL64((aOrbiterI * 5683451044852895957U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4793712537158004047U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 10415170179135963622U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 13729564030210361415U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + aNonceWordF);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + aNonceWordA) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 52U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 46U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 57U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneA, aWorkLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneC
        // cross directions: aInvestLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14338U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 12191U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15394U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13279U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 14959U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 9630214189402543339U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 4072576573737526819U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 15994787452709618869U) + aNonceWordB;
            aOrbiterC = ((aWandererK + RotL64(aCross, 39U)) + 6403240137132259482U) + aNonceWordK;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 18U)) + 10229266900170507720U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5025294577989748989U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16696461238217956883U;
            aOrbiterG = RotL64((aOrbiterG * 15993828976234917577U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9878318855341719119U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16086635438116177346U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12295437783084203730U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7681150419912842402U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 7289497379725191451U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2639104034287637448U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12298170009332243573U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3485932317267669626U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16569551670038752475U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aPrevious, 38U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 47U)) + aNonceWordG) + aPhaseAWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21114U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((aIndex + 21489U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20013U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20242U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 20275U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 12046647397183218524U) + aNonceWordA;
            aOrbiterJ = ((((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 2760779375026461991U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (((aWandererF + RotL64(aCross, 56U)) + 13735454443176855650U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 4370377000586647724U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 3U)) + 14566322384189969094U) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5056565959818422786U) + aNonceWordD;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 8795403810686579209U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 11205867337479457471U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 9625947666256011567U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1703669290934254701U;
            aOrbiterJ = RotL64((aOrbiterJ * 5763881345676123583U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6664070663184147951U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2104148316797553431U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 12887842067180975983U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1197910004222596145U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9922977170060903197U;
            aOrbiterI = RotL64((aOrbiterI * 13047828062605568603U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2048376210852567829U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12568990647075931409U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9860242601194210927U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 58U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aNonceWordP) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aOperationLaneB, aInvestLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aInvestLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23455U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 23820U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25167U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26190U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22640U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 6361545377408870615U) + aNonceWordI;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 42U)) + RotL64(aCarry, 27U)) + 2967245486744774933U) + aPhaseAOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 3836634268482850139U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 3U)) + 7691642115360086297U) + aPhaseAOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aIngress, 21U)) + 16479280384178279281U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2901468732552539249U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2600353867755647475U;
            aOrbiterI = RotL64((aOrbiterI * 1140827276372862433U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5666596904781510956U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16108791609267427553U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8904649663479834199U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 8389926875737312112U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1689501721163024426U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6517194895779049139U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11721701506949917719U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3963842745030140473U;
            aOrbiterC = RotL64((aOrbiterC * 6692473494944919373U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8510538243472109368U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 18281865214102080387U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 1351546966368884609U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 43U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + aNonceWordE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 43U)) + aOrbiterH) + aNonceWordP) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 21U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28294U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 27934U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 30618U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27444U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29906U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererB + RotL64(aIngress, 37U)) + 6381335981879993247U) + aNonceWordB;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 51U)) + 15595429101600023172U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 5449234297249826461U) + aNonceWordL;
            aOrbiterI = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 11213734849329731168U) + aNonceWordP;
            aOrbiterH = ((((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 53U)) + 16438473952464514248U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7357872882115186976U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 394402075160738643U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11961225338735982661U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11112941985410283532U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14955125011182736212U;
            aOrbiterH = RotL64((aOrbiterH * 10711684773326395603U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14770727009821304070U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11286366598129204910U;
            aOrbiterI = RotL64((aOrbiterI * 15884310771003021989U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7358400908565425780U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15635109923749114761U;
            aOrbiterE = RotL64((aOrbiterE * 12415152149408700329U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13826842523738623579U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1072811298828325231U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 9662800288646215083U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterH, 56U)) + aOrbiterE) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 47U)) + aNonceWordD) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_PickleBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDD0E502D24EFA489ULL + 0x8C1D5D3A47964F70ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC867D13B93A79D3DULL + 0x847A4309B23684C0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x948A63BA50ED8145ULL + 0xEF69DE71E96F8AD6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB4A2980981D5D587ULL + 0xE1DD16B69CBE6F44ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDE4AA3D56D72EE65ULL + 0x8F44B199739ABC2CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA954FF47A95A7BE1ULL + 0xD74F98A7A8A312A3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD69579C16FC7C783ULL + 0xC0DD09419A92EED0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD93D57EB25D4470DULL + 0x8240FAAAA190FD04ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCDF6C00170496C6FULL + 0xBD100F961C40DAB0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB7C66244D05269F3ULL + 0x8E7ADF8635B03603ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x82D487E1CB7D0933ULL + 0xF3D560FC73EFF064ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9EE74CA56510545FULL + 0xC9647059EF6362E4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x93DFAD9EA324C469ULL + 0xF4A08402116666D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB3CE5FBA89437E4BULL + 0xA034D534357A8E65ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB70869028B06058FULL + 0xE994D354B1346080ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x814F096328BE18C7ULL + 0x9719BC3AB910FBE1ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6267U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 4409U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4800U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2064U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6176U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6329U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererG + RotL64(aScatter, 43U)) + 11177787645248006236U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 5U)) + 3808340254579817169U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 57U)) + 828030667598518279U) + aNonceWordL;
            aOrbiterE = (aWandererJ + RotL64(aCross, 37U)) + 16177835921238398371U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 28U)) + 5518747735458708741U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 17346319082399995165U) + aPhaseBOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 6397156921893030937U) + aNonceWordG;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 15559381654710713582U) + aNonceWordB;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 19U)) + 940404446491415088U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8047166032048732645U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4688468645859470491U;
            aOrbiterB = RotL64((aOrbiterB * 14383536431614496369U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3710878044770337260U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 116343189456629220U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 883908030159391659U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18058691521694880482U;
            aOrbiterD = RotL64((aOrbiterD * 3132200449123497619U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17521015077103586117U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3668332225435714918U;
            aOrbiterE = RotL64((aOrbiterE * 12658899101297839881U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12229480388278883300U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16206524049491531816U;
            aOrbiterG = RotL64((aOrbiterG * 11122340196620859805U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5743265849441077466U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2812293020719282236U;
            aOrbiterK = RotL64((aOrbiterK * 8903956475200417109U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13718364781538837074U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 861529717259766236U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17019744777211266685U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4862687502126693872U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7722024283321020761U;
            aOrbiterF = RotL64((aOrbiterF * 18086944039541060829U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8205803118233399853U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15130160926615050422U;
            aOrbiterH = RotL64((aOrbiterH * 1454552751453996765U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 14U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 47U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 37U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI + (((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 35U)) + aNonceWordC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 10U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15933U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 9737U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11184U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13722U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11209U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15840U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12416U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 35U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (aWandererC + RotL64(aPrevious, 42U)) + 16922357079016918108U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 27U)) + 11771749797137599131U) + aNonceWordF;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 4635668433708036077U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 15827952719230577008U) + aNonceWordA;
            aOrbiterF = (aWandererI + RotL64(aIngress, 56U)) + 1495675306110023086U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 35U)) + 7294835466949728365U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 51U)) + 179122461212041978U) + aNonceWordK;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 545981421632236251U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 11U)) + 15338259639814630535U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12924313840290895215U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17846785921286020610U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 18309347016029917133U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5721472794107057875U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16359630793856870319U;
            aOrbiterF = RotL64((aOrbiterF * 14186771515526698907U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10614102110239037308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16421992251278236531U;
            aOrbiterA = RotL64((aOrbiterA * 2561232904676068089U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8668149834861244963U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12699331834360948734U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2249360824172616357U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4470693178142950471U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 526000656022724741U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 16688501462334673493U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6880246132270094141U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7126466778855297013U;
            aOrbiterC = RotL64((aOrbiterC * 5692237926830293205U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6436404501390442054U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 1213633065612242699U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17604454985534439259U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8186529105901185854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10607460957358250935U;
            aOrbiterI = RotL64((aOrbiterI * 17172191011625677861U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9743278964993305169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14007577681873418075U;
            aOrbiterB = RotL64((aOrbiterB * 4231122580398039133U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 56U)) + aOrbiterE) + aNonceWordH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 18U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aPhaseBWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 24U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18316U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 22902U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18105U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 17232U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18132U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24517U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24541U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 13854738573712660276U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 3U)) + 16835460633412286294U) + aNonceWordE;
            aOrbiterH = (aWandererC + RotL64(aIngress, 37U)) + 6785859293758091931U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 126317283127992659U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 7568963536291415413U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 21U)) + 12294016745653004819U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 46U)) + 18269588932920281147U) + aNonceWordN;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 5872406424994751026U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 53U)) + 7764434758831474129U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4804168969415573371U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 959601763507651280U;
            aOrbiterH = RotL64((aOrbiterH * 4647396592804833217U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9257644462479293048U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14332699366894494579U;
            aOrbiterA = RotL64((aOrbiterA * 8829304078930625541U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10487012596470786004U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 612729229562321440U;
            aOrbiterB = RotL64((aOrbiterB * 11380387280507726003U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7845523921295625315U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12742115479740024747U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15578543510683986421U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10294667720904610944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14369711143154904567U;
            aOrbiterF = RotL64((aOrbiterF * 13753005602288309379U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10918344717497681894U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18136794828308636957U;
            aOrbiterJ = RotL64((aOrbiterJ * 17899418637978002409U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14378638206724886404U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7077588188450008059U;
            aOrbiterD = RotL64((aOrbiterD * 485375960462924335U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 8941870012851971932U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15242087859620352399U;
            aOrbiterK = RotL64((aOrbiterK * 4963002810455992839U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10395280254030875387U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6826595516076975980U;
            aOrbiterE = RotL64((aOrbiterE * 6198886240333178001U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 38U) + aOrbiterI) + RotL64(aOrbiterB, 60U));
            aWandererK = aWandererK + (((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 39U));
            aWandererG = aWandererG + ((RotL64(aIngress, 28U) + aOrbiterK) + RotL64(aOrbiterD, 48U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterH) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25614U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 27508U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32069U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29813U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24607U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27637U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30874U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 34U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 10726035965553989335U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 52U)) + 967354339530195662U) + aNonceWordF;
            aOrbiterE = ((aWandererK + RotL64(aCross, 39U)) + 10834593005478605624U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 13U)) + 1012888282838656933U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aIngress, 5U)) + 15283530351725183253U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 29U)) + 11724495956731703750U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 4288330117317505776U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 19U)) + 10894778070022873473U) + aNonceWordK;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 15563886747621617467U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11182488628562891937U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10420140066310588580U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 13898299782819948719U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11775138062167543111U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16545391898578161683U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14588306527161321535U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1550144656312299266U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14903504853138279883U;
            aOrbiterC = RotL64((aOrbiterC * 8003033561266164387U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 309935535526750396U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13991265868040011411U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 2887531132228588441U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1755976294857114222U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2259275858478396846U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7416165760067878161U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4838175912944552936U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12307900457200936013U;
            aOrbiterH = RotL64((aOrbiterH * 14719363144850838805U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18025411832912225805U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 981375022769564523U;
            aOrbiterG = RotL64((aOrbiterG * 15869361544011831483U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3174014054982742562U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8119692378748963609U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 3072354179707448489U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14502863160788675807U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1207582534593709516U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3045412087535529357U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 54U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 60U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + aNonceWordN) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterC, 13U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 46U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_PickleBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD8AEF4E847BFE9F3ULL + 0xBF790759BDBC7E85ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x97AF84365DE3AFFBULL + 0xF2D07629CC6714CFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCD7DF2F5DF5DEBEBULL + 0x8BEC01B3D6498405ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDB48D3B132033B25ULL + 0xBF80F5B07BF9668AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFF3FDED63B8ABFA1ULL + 0xFEA94A04B49F0FCBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE4A0C04A4B357F95ULL + 0xF7FA3B5254CA47FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCCF939966678E5D3ULL + 0x8EEAB227614D0379ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDBAE3926F8C66D29ULL + 0x9D88E90732A55EFBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x99A04E8027561257ULL + 0xFC2FE746EECA760AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEBF0F20E1DF70473ULL + 0xEA36920FFF5E4CCCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF516777C877C7AD7ULL + 0xB6D4144DA418F574ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x91571E05F6AF607DULL + 0xDFB872E344550C46ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAC3919EFFABFFF5FULL + 0xA04833E6B078777EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC072DFAFC62D4657ULL + 0xEBAE1D855A5325F8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD106178C03F7A32BULL + 0xE04B4AA9F298E648ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAA10F864958A3703ULL + 0xDFF06C4348F92B48ULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aInvestLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aInvestLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aInvestLaneC, aInvestLaneD
    
        // seed_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3125U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 4227U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4655U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 816U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5296U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4280U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 20U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 58U)) + 16451272412693907816U) + aNonceWordL;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 10099485419723255462U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 17668900099534923192U) + aNonceWordI;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 5497093724143181753U) + aNonceWordO;
            aOrbiterK = (aWandererK + RotL64(aScatter, 35U)) + 10354044773550071706U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + 12728258851198019099U) + aNonceWordM;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 11U)) + 4144050505314242618U) + aPhaseDOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14133805325480076530U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 308863673210602899U;
            aOrbiterD = RotL64((aOrbiterD * 2672613556981540433U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11741180130160569753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12926863156769180448U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9726030996091054939U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 211920854786494259U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13234608842479411078U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2556747209733759467U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9164711974854618892U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6667377062281954219U;
            aOrbiterH = RotL64((aOrbiterH * 2603737166987437649U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4559040002406721850U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1749875480850675109U;
            aOrbiterC = RotL64((aOrbiterC * 15822640067349481089U), 53U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 9555365165561936366U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8727162691639622461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 291406782452963706U;
            aOrbiterE = RotL64((aOrbiterE * 8413500075082350243U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + aNonceWordN) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 60U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 11U)) + aNonceWordB);
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7792U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 7568U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6203U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 6887U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7475U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9046U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8935U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 51U)) + 6318740973868639425U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 57U)) + 5487840061430920881U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 44U)) + RotL64(aCarry, 11U)) + 10258706763248072672U) + aPhaseDOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 11U)) + 18356875269730338208U) + aNonceWordF;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 21U)) + 12883160282903147010U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 1010140474942697730U) + aNonceWordJ;
            aOrbiterK = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 17733939421700898293U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13693055887924981201U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14574732452793385269U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 9373765929885750185U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10832873941223609012U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8212600587135328040U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5334613996794796145U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5312744319781971178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6173741211706546923U;
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3693249147883790810U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 18365859989736602556U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3348463719324104997U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10645056678337549771U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1175668356822251045U;
            aOrbiterC = RotL64((aOrbiterC * 6579675292775345579U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13556844570541823717U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4790355739411849736U;
            aOrbiterA = RotL64((aOrbiterA * 4083544011788850307U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14905575502272644116U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17047244574558476634U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2356386971503880047U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 4U)) + aOrbiterB) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12901U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 11449U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 13929U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12315U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16054U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 41U)) + 785861751704720606U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 15968088718435606299U) + aNonceWordP;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 1393976526590347151U) + aPhaseDOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 21U)) + 17240750947292745884U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 4921576136163183137U) + aNonceWordM;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 35U)) + 3334047873553153032U) + aNonceWordO;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 47U)) + 15086509978458408698U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 892391205397581998U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2965686403183767521U;
            aOrbiterB = RotL64((aOrbiterB * 709160942482770225U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14632215393655706170U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15740589515342377322U;
            aOrbiterF = RotL64((aOrbiterF * 15677716942904794913U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11131164813943086445U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6988080581278900960U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6412189142344044255U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16021254613117657178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6183615599897921154U;
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12533992547026652747U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3104325358982904219U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14977348108778147265U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3878525937957474644U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2120435259884368445U;
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14928658302694194856U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9121310461310309348U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17304439784647477491U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 26U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterI, 4U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // ingress from: aInvestLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aInvestLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18658U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 21393U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 19103U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17335U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16647U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 39U)) + 16922357079016918108U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 11771749797137599131U;
            aOrbiterK = (aWandererH + RotL64(aCross, 29U)) + 4635668433708036077U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 15827952719230577008U) + aNonceWordO;
            aOrbiterF = (aWandererK + RotL64(aScatter, 3U)) + 1495675306110023086U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 53U)) + 7294835466949728365U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 179122461212041978U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 545981421632236251U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15338259639814630535U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14895421566334357871U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12924313840290895215U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 17846785921286020610U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 18309347016029917133U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5721472794107057875U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16359630793856870319U;
            aOrbiterF = RotL64((aOrbiterF * 14186771515526698907U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10614102110239037308U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 16421992251278236531U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 2561232904676068089U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8668149834861244963U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12699331834360948734U;
            aOrbiterD = RotL64((aOrbiterD * 2249360824172616357U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4470693178142950471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 526000656022724741U;
            aOrbiterE = RotL64((aOrbiterE * 16688501462334673493U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6880246132270094141U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7126466778855297013U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5692237926830293205U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 44U)) + aOrbiterE) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // ingress from: aInvestLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aInvestLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aInvestLaneA, aWorkLaneA
        // cross directions: aInvestLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22450U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 22566U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26895U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25690U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 22221U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererK + RotL64(aScatter, 13U)) + 898812731947995389U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 8677347622525527167U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 770321564027567654U) + aNonceWordE;
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 11020474858081526395U;
            aOrbiterI = (aWandererE + RotL64(aCross, 21U)) + 17289793580414993470U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 10111912559295118444U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 36U)) + 8083622125544542011U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7149858558922988240U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5919683821379905699U;
            aOrbiterB = RotL64((aOrbiterB * 16705119888884231567U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6860902846079238714U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15083517836867542075U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14852868368708376381U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9860233289028878323U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 772406119079116272U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7971141501337627589U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8478568022896691911U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4027604850785607101U;
            aOrbiterC = RotL64((aOrbiterC * 4826627523578901467U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17199331557841535430U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7515957656979776361U;
            aOrbiterD = RotL64((aOrbiterD * 5468950152869656599U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17138249294921502391U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16236812863923234668U;
            aOrbiterJ = RotL64((aOrbiterJ * 2925542836624164807U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 22U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + aNonceWordK) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 4U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // ingress from: aInvestLaneC, aInvestLaneA, aOperationLaneD
        // ingress directions: aInvestLaneC forward forced, aInvestLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneB
        // cross directions: aInvestLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29024U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 31280U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28748U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27719U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32264U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 40U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 18319689184146942855U) + aNonceWordE;
            aOrbiterF = (aWandererB + RotL64(aIngress, 51U)) + 8041304130090501019U;
            aOrbiterH = ((((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 11347064191990897738U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 29U)) + 15242243470024447468U) + aNonceWordO;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 22U)) + 10619749107163611105U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 14795614276221947128U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 1578095288886372393U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13593906305770501684U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8919815528334599172U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 2033810402808238127U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17425548324720065145U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11125018338392347335U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 4377887040461528587U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3779189180734244399U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10958224663276134041U;
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4317305352561612995U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4891139433808505355U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 11507024985663120317U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5166074784835930965U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10080890270621589202U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13170894418184288695U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4501071771615514619U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6486573807774431753U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 324029625116648669U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15714881857668975753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3506619392820235900U;
            aOrbiterC = RotL64((aOrbiterC * 5707033870161224499U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 53U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 18U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordD) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_PickleBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCECA4F204B8E5A13ULL + 0x98464841FE558E7FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC147A37C4CDAD915ULL + 0x912FB308D6F21AFEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x862D2F2730F80471ULL + 0xE46CA862D13B752FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9A1BC22C831FD6B7ULL + 0xB451C38A7E3AE549ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC55ADE30E2382DE1ULL + 0xEBB94B5B63086887ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD125E2D37EF59B0BULL + 0xC5F750BF93068440ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED77997FC3E7481BULL + 0x8F9600C282F8CB68ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE9FF307A8D27F7A7ULL + 0xA10950D42D447CF7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC2D41824219EB3BFULL + 0x8092571698D843CAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC96C39EF9D36D443ULL + 0xDA1C237166FBD260ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9CF1418B257BC53BULL + 0xEDA3583851D8D0FCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9896DDF333E944F7ULL + 0xD1E838BADF8D3AB3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEE7DAB6EAC456E8FULL + 0x92C10B28F61E36A9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAC68E50A86CAD57BULL + 0xBEF48BFEF6609724ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE8A6B7068F080E3BULL + 0xE9380E820B78245EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEF09A9635EB57C7FULL + 0x94B85241F86BAD35ULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aInvestLaneA, aInvestLaneB, aFireLaneA, aInvestLaneC, aInvestLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aSnowLaneA, aSnowLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // ingress from: aInvestLaneA, aInvestLaneB, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aInvestLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aInvestLaneD, aFireLaneB
        // cross directions: aInvestLaneC backward forced, aInvestLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3707U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 2932U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 786U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2834U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 5325U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3742U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 6024062041314952357U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 18340757093658015585U) + aNonceWordJ;
            aOrbiterF = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 11911120493880346751U) + aNonceWordF;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 13U)) + 17428074353884654439U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 56U)) + 12790849760814795936U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 23U)) + 12633397052172117800U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 21U)) + 11946150433665237945U) + aNonceWordE;
            aOrbiterA = (aWandererH + RotL64(aIngress, 41U)) + 16842157900909419285U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 11U)) + 14186235783224155962U) + aNonceWordA;
            aOrbiterH = ((aWandererD + RotL64(aCross, 19U)) + 13284904542579767591U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 28U)) + 11609181965078844357U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9628562297095374984U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7850281529011259759U;
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 257458718073794527U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10693404545773519306U;
            aOrbiterB = RotL64((aOrbiterB * 14821443722828498323U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3430519236533871460U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6183054506953198055U;
            aOrbiterJ = RotL64((aOrbiterJ * 6121082743789970911U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2905610989884221654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterA = RotL64((aOrbiterA * 7770678426310856745U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16870142883133769663U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterH = RotL64((aOrbiterH * 9740854430251597879U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16904169913507057108U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4773518591580333357U;
            aOrbiterG = RotL64((aOrbiterG * 5306070307776061267U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6528141733853494275U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11254806909313951442U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6316669786405548827U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6857506858448143407U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2855763534355983644U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 16881334940165182415U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12328391751024624740U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16475072086109949522U;
            aOrbiterI = RotL64((aOrbiterI * 15218626930666825883U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15505670341076785424U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6972128419331939330U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12206069109180246067U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7151546362283646210U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6024062041314952357U;
            aOrbiterE = RotL64((aOrbiterE * 10243806128059850493U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 22U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 24U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + aNonceWordL) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterC, 44U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 22U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // ingress from: aSnowLaneA, aInvestLaneC, aInvestLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aInvestLaneC forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aInvestLaneB, aFireLaneD
        // cross directions: aInvestLaneA backward forced, aInvestLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9334U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((aIndex + 8462U)) & S_BLOCK1], 44U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8113U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7387U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9792U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5810U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9601U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCarry, 29U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 13U)) + 8604208734152026945U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 26U)) + 1374329953253889829U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 3U)) + 5779278910548228339U) + aNonceWordN;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 21U)) + 17670451230882805140U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 8193848740764866860U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 15801168428145650104U) + aNonceWordP;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 2584718176087499066U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 41U)) + 14950366247822737997U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 6U)) + 9779293225265670135U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aWandererA + RotL64(aIngress, 53U)) + 8688968319288372383U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 43U)) + 13665723186950342601U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9395428688359973510U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2152719218018108418U;
            aOrbiterD = RotL64((aOrbiterD * 15271961483518392671U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1350324137411377992U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8729317951386057921U;
            aOrbiterH = RotL64((aOrbiterH * 6008790836417785083U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6317310451893678411U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10175620379041384281U;
            aOrbiterJ = RotL64((aOrbiterJ * 14079679617394330781U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1203082119358827708U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 523869107818193101U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 4629501113595689157U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4028324959540432983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15447631947468213912U;
            aOrbiterC = RotL64((aOrbiterC * 6037306615787729185U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14225888694733041031U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11925000696281947629U;
            aOrbiterI = RotL64((aOrbiterI * 4337022940520411253U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15015531024930608745U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16752579225076943550U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 15551083683579981439U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2432733494869267901U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10103430321388601485U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18372919379972432569U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15943360147468638325U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9782703760233558733U;
            aOrbiterB = RotL64((aOrbiterB * 685056980418243879U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18345087852012669037U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8897505040792027675U;
            aOrbiterG = RotL64((aOrbiterG * 14333687539092412967U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7402581293947129667U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8604208734152026945U;
            aOrbiterA = RotL64((aOrbiterA * 9965525485538037673U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 52U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterD, 60U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 44U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 11U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // ingress from: aSnowLaneB, aInvestLaneA, aWorkLaneA
        // ingress directions: aSnowLaneB forward forced, aInvestLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aSnowLaneA, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14024U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 15437U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15361U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13736U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 14027U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 51U)) + 1142447269198373880U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 10581460640040336191U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + 14703062773878202900U) + aNonceWordN;
            aOrbiterF = (aWandererK + RotL64(aCross, 19U)) + 15737525756286914746U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 47U)) + 16178774478273186999U) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 57U)) + 2514897053906809160U) + aNonceWordM;
            aOrbiterA = ((aWandererB + RotL64(aCross, 23U)) + 13702496607592508464U) + aNonceWordD;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 18030885275418337965U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 5241783876161655984U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 14U)) + 2807052676283587925U;
            aOrbiterD = (aWandererE + RotL64(aCross, 35U)) + 8022804576763271327U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15597099852232205860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1538435607932096400U;
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11147868774413615365U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9325213746830411568U;
            aOrbiterB = RotL64((aOrbiterB * 561819005818948769U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13792300423550555634U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3134856508983945719U;
            aOrbiterA = RotL64((aOrbiterA * 4271845067763664863U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8654966018053784882U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 8937113935476779267U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 7386875687217705855U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4135676350355234788U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11407912615743682678U;
            aOrbiterH = RotL64((aOrbiterH * 2773506587480714695U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 10966950663872392059U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6686634993700944582U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2509459942163678241U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14154407529749257990U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 18054640398549782388U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 7830759861389060149U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14623473030642960240U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1857945571104460086U;
            aOrbiterG = RotL64((aOrbiterG * 18039903315045620079U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17650774450811065797U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9458168381246672881U;
            aOrbiterI = RotL64((aOrbiterI * 3452665113988737563U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16604923466236483242U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12447748535184711684U;
            aOrbiterJ = RotL64((aOrbiterJ * 5982708155382249061U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9589720286549780720U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1142447269198373880U;
            aOrbiterD = RotL64((aOrbiterD * 8176719948031280789U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aNonceWordK) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 14U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterH, 34U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // ingress from: aOperationLaneA, aSnowLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aSnowLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21557U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 21656U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 17563U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18013U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneD[((aIndex + 17646U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 5U)) + 7651355040951791298U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 38U)) + RotL64(aCarry, 39U)) + 13988210277931659312U) + aNonceWordF;
            aOrbiterE = (((aWandererB + RotL64(aCross, 21U)) + 9846849412579537783U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 19U)) + 12746719939495876158U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 11U)) + 11498066185182895284U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 11101058955193080232U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 43U)) + 15513734459555672046U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 41U)) + 15711108675349394643U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 35U)) + 4771231759949468556U) + aNonceWordJ;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 11449258010811305256U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 24U)) + RotL64(aCarry, 53U)) + 17036938391509986723U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6999245666776654250U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2106819066263369528U;
            aOrbiterE = RotL64((aOrbiterE * 13005885810757743129U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12716183358903477216U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16752724547046059889U;
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17623077680983093163U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6726003022297274986U;
            aOrbiterD = RotL64((aOrbiterD * 14709385877103232653U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2842410225096524740U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9235178377537910514U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11813751114775673845U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2619888019860844610U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6295481948199619613U;
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9724921158061115570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4070976180958458679U;
            aOrbiterB = RotL64((aOrbiterB * 6080566609081811453U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5864247978960125554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7771249710071026757U;
            aOrbiterJ = RotL64((aOrbiterJ * 4787660062590737657U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15006900854988166845U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2755659268987119046U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8043939381186802359U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1922321482806966418U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13910818219761929659U;
            aOrbiterC = RotL64((aOrbiterC * 8895973123729951173U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7540972911473176026U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5419023469522423893U;
            aOrbiterF = RotL64((aOrbiterF * 1380429266266313945U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2349651834739320824U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7651355040951791298U;
            aOrbiterA = RotL64((aOrbiterA * 3713776056028698433U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 50U) + aOrbiterG) + RotL64(aOrbiterH, 42U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // ingress from: aOperationLaneB, aSnowLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aSnowLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aSnowLaneA
        // cross directions: aOperationLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27240U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 23230U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26077U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23896U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24979U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 4848316479321533394U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 6919360256662636195U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 11U)) + 9897013582181108544U;
            aOrbiterH = (aWandererB + RotL64(aCross, 21U)) + 7319353809896158678U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 43U)) + 2848175435514849859U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aIngress, 60U)) + 6967780718720437934U;
            aOrbiterD = (aWandererC + RotL64(aCross, 51U)) + 10143884766603388136U;
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 8675965006150972051U) + aPhaseEOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + 16350117755560994281U) + aPhaseEOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 41U)) + 17976597517118423760U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 23U)) + 1399631141355370237U) + aNonceWordD;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3590613762034716792U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5134624314245932157U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13077589037975283371U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10082236952942943654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4015535035905433450U;
            aOrbiterK = RotL64((aOrbiterK * 4961808568701908559U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 611474103801573800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5786708483794098001U;
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5201943497363274455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9282160506938328489U;
            aOrbiterC = RotL64((aOrbiterC * 5368182164239021367U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4932320527498940158U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11576526341731392916U;
            aOrbiterE = RotL64((aOrbiterE * 1712051774729439363U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10790691517638887125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16280649213607464422U;
            aOrbiterI = RotL64((aOrbiterI * 10756733801499471873U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9553716940667712810U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11827518270964003341U;
            aOrbiterA = RotL64((aOrbiterA * 1322489827908132831U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16777463701235809321U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 3375489084588454149U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 3335010977457647307U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8129898095524287632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14496406641486541929U;
            aOrbiterD = RotL64((aOrbiterD * 10077246205532940301U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17968163292907132345U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2431407778543471402U;
            aOrbiterJ = RotL64((aOrbiterJ * 407105842057624537U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 18330313613898211889U) + aNonceWordK;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 4848316479321533394U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 3462735144109152811U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 60U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordL) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aNonceWordA) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 18U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31423U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 30393U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27537U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30419U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30248U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 38U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (((aWandererI + RotL64(aCross, 13U)) + 9630214189402543339U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 21U)) + 4072576573737526819U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 39U)) + 15994787452709618869U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 36U)) + 6403240137132259482U) + aNonceWordB;
            aOrbiterB = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 10229266900170507720U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 5025294577989748989U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 27U)) + 16696461238217956883U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 11U)) + 9878318855341719119U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 43U)) + 16086635438116177346U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 48U)) + 12295437783084203730U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 7681150419912842402U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 2639104034287637448U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12298170009332243573U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9397919591171238575U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 3485932317267669626U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16569551670038752475U;
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4448490103784103954U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14510534073046885941U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7777192047386438305U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4286195398675733451U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15790355933840266463U;
            aOrbiterK = RotL64((aOrbiterK * 13342257823027075501U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6362891510370156055U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15121822034579983174U;
            aOrbiterF = RotL64((aOrbiterF * 7268045994574844937U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13817341015719915628U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14113474087906143783U;
            aOrbiterH = RotL64((aOrbiterH * 12838910141533126059U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9988301252236121106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11287477288382171758U;
            aOrbiterE = RotL64((aOrbiterE * 4979297247881426383U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9491727010910328644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7961202721830514030U;
            aOrbiterA = RotL64((aOrbiterA * 16300364540313620767U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10058066852293995222U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 541563830282750968U;
            aOrbiterJ = RotL64((aOrbiterJ * 1516823517052019845U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7791201128863372861U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8334318157449352359U;
            aOrbiterD = RotL64((aOrbiterD * 2924838607279239375U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6861081455774799715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9630214189402543339U;
            aOrbiterC = RotL64((aOrbiterC * 10837610668580336781U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 40U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 24U)) + aOrbiterA) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 34U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 6U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

void TwistExpander_PickleBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA375CEA5FB502373ULL + 0x91A75FFC93FF4BDEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x931EA558512D5E51ULL + 0x92872D005C087FD0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCD048880F40941A7ULL + 0xEF7949B51EE68252ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEF9E239EEAF21A5BULL + 0xB1C4172CFEF4730CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC54A3528AF3BC91BULL + 0xA0B0C1B9061DB630ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC9F652EBC1B01A97ULL + 0xC7AAFAC1C90F8103ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x894C0A7AC641CAB3ULL + 0x8DDA41A0CF0090B1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFD870472DFF3923BULL + 0xCF0D402BBB08A65DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB5AA07619BC84AE9ULL + 0x9C9B7ABDEE17AF42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA2CC65C8F5118101ULL + 0xBC4E290D2E9E84ABULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF71D96D3787680F3ULL + 0xA2363369402D6E68ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9CD393DB075A635DULL + 0xEF82ADDAB9D1884EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBE951FB9D7C560E1ULL + 0x9582DB407D60D109ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA5328B14CA1BC17FULL + 0x9743419D96670E6BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x80831239DC3A4AF1ULL + 0xFE327A730EA201BDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB285F3FA3C8735C1ULL + 0xE41A9EFBA27880A7ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aInvestLaneA, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4744U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 1459U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 168U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 555U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2376U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3026U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 56U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 42U)) + 10336802574069791273U) + aNonceWordN;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 169025388197058936U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 27U)) + 6541354188379168846U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 53U)) + 16223920526599306104U) + aPhaseFOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 57U)) + 12756613707692514808U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 5082475548176484035U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 4907435526952698526U) + aNonceWordO;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 22U)) + RotL64(aCarry, 3U)) + 14236627073831834337U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 3U)) + 11502511046130497584U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3679044835550219497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11254838916686736746U;
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 10582608424233200966U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10449735026385340313U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 4628253464169957835U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17664454668473204465U;
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3798386391743884889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1379331161819246587U;
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9816600392407327227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16781971616348376878U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4807797577690520554U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2492057261148595922U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9453302540675483005U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7909676419643119585U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 256053568910383007U;
            aOrbiterE = RotL64((aOrbiterE * 11965085163352053161U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16179914439220412472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3968867762761955845U;
            aOrbiterF = RotL64((aOrbiterF * 7473632378251893139U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7474832923901283742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4736994731050735779U;
            aOrbiterK = RotL64((aOrbiterK * 9839654409121414047U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 12U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aNonceWordP) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 36U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererA = aWandererA + ((((RotL64(aCross, 52U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 13U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6126U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 8577U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6056U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7799U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8138U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5579U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9086U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 3U)) + 13960289014350612206U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 35U)) + 3483331015269589730U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 6873299241002444518U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 60U)) + 3562094007125534229U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 11422367439932782705U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 532453428514259816U) + aNonceWordC;
            aOrbiterI = (aWandererJ + RotL64(aCross, 39U)) + 17810941465810193088U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 30U)) + 11869759058631106331U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 8837581071876177566U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17185378327053837778U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7578253375676981500U;
            aOrbiterB = RotL64((aOrbiterB * 13371647568758721729U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17112646434432814442U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14949096407295697881U;
            aOrbiterA = RotL64((aOrbiterA * 14770977858283051753U), 39U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 4259590620758467836U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6534899413644542303U;
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2637407498893694243U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15819295597921425711U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 5202015597375051399U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6373559542002699718U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11694562937392022505U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9311557972331218597U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3308736483775453062U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12749929710650475901U;
            aOrbiterI = RotL64((aOrbiterI * 248428400724560945U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1569528215675579656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1044077933631689572U;
            aOrbiterF = RotL64((aOrbiterF * 6443796233912755143U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8393422728124537471U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2002732612516530754U;
            aOrbiterJ = RotL64((aOrbiterJ * 13702146823622364279U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13469191942843147943U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7633171368709520560U;
            aOrbiterG = RotL64((aOrbiterG * 9713514012478203047U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 34U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordF) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 58U)) + aNonceWordN) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14776U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 15087U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15611U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12221U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11035U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 10U)) + 6733949564325516029U) + aNonceWordO;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 19U)) + 7304098437143918796U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aPrevious, 3U)) + 3923949518391777800U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 43U)) + 14243591003388927124U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 35U)) + 18329498724605410406U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 37U)) + 13118172167747037249U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 5272025143849174212U) + aNonceWordM;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 16075917179214318424U;
            aOrbiterK = (aWandererE + RotL64(aCross, 27U)) + 15263590648674658399U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13730046728289525921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7703141464499623408U;
            aOrbiterB = RotL64((aOrbiterB * 5886009900621521987U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1382279753822135359U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2973369221699098292U;
            aOrbiterG = RotL64((aOrbiterG * 7440242040663550631U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11578274119583013219U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3419411247737896674U;
            aOrbiterI = RotL64((aOrbiterI * 17814942652262802991U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2582783513078999303U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3959762790273529677U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 383974377372162751U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 465795011576934604U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17880826624185821135U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 4445949147592860913U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10819659185349413173U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17298208553586835030U;
            aOrbiterH = RotL64((aOrbiterH * 1965860510614222093U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12585880006661489402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16650193903267408586U;
            aOrbiterE = RotL64((aOrbiterE * 5781132589396936615U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 885882046325991589U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 869560078374809974U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 13440973563438747181U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11871305571797951851U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12137095015607196226U;
            aOrbiterK = RotL64((aOrbiterK * 7618152256560808581U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 40U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterD, 38U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 58U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21725U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 20249U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 18726U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18900U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20790U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererK + RotL64(aScatter, 51U)) + 11177787645248006236U) + aNonceWordG;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 58U)) + 3808340254579817169U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 828030667598518279U;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 16177835921238398371U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererD + RotL64(aIngress, 47U)) + 5518747735458708741U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 17346319082399995165U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 39U)) + 6397156921893030937U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 28U)) + 15559381654710713582U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 5U)) + 940404446491415088U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8047166032048732645U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4688468645859470491U;
            aOrbiterI = RotL64((aOrbiterI * 14383536431614496369U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3710878044770337260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 116343189456629220U;
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 883908030159391659U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18058691521694880482U;
            aOrbiterK = RotL64((aOrbiterK * 3132200449123497619U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17521015077103586117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3668332225435714918U;
            aOrbiterH = RotL64((aOrbiterH * 12658899101297839881U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12229480388278883300U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16206524049491531816U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11122340196620859805U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 5743265849441077466U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2812293020719282236U;
            aOrbiterC = RotL64((aOrbiterC * 8903956475200417109U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13718364781538837074U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 861529717259766236U;
            aOrbiterA = RotL64((aOrbiterA * 17019744777211266685U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4862687502126693872U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7722024283321020761U;
            aOrbiterG = RotL64((aOrbiterG * 18086944039541060829U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8205803118233399853U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15130160926615050422U;
            aOrbiterJ = RotL64((aOrbiterJ * 1454552751453996765U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 14U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 28U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + aNonceWordB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 28U) + RotL64(aOrbiterA, 6U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneB, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneA
        // cross directions: aExpandLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24750U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 24167U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 27254U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24378U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneA[((aIndex + 22067U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 51U)) + (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 51U)) + 5906639480605353429U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 11U)) + 5293518570213287605U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 39U)) + 15383185501428521377U) + aNonceWordL;
            aOrbiterB = (aWandererI + RotL64(aIngress, 58U)) + 15364072512743978902U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 4525473357144014271U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 29U)) + 10400911938125603074U) + aNonceWordP;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 16417506293824627550U;
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 2419329331753341815U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aWandererC + RotL64(aCross, 18U)) + 14929222427923332069U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16771573504983922586U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1863466450051787622U;
            aOrbiterD = RotL64((aOrbiterD * 2585626547126027053U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12895350137096692415U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3700979086526298327U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10279730254867618193U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1977099106211282426U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6144698304096915742U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 5039822990560519609U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3858895556659724975U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1283646340363435327U;
            aOrbiterE = RotL64((aOrbiterE * 11622421841377018069U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6240532051889108891U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 757364889381634634U;
            aOrbiterI = RotL64((aOrbiterI * 943852137901972945U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5272945693977418174U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6850528198786172283U;
            aOrbiterF = RotL64((aOrbiterF * 1966383079897679953U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14431587733859573714U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16124590257870999553U;
            aOrbiterA = RotL64((aOrbiterA * 7755796211433191143U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14912695018110241411U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11098623474413346520U;
            aOrbiterC = RotL64((aOrbiterC * 15167688959990872051U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3484847683376368686U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2295388097292719800U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1240808318176106909U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 58U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 6U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 3U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 40U));
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aNonceWordM) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 53U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31158U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 31325U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 30857U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27444U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 31015U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 43U)) + 7651355040951791298U) + aNonceWordG;
            aOrbiterC = (aWandererI + RotL64(aScatter, 57U)) + 13988210277931659312U;
            aOrbiterF = (aWandererC + RotL64(aCross, 47U)) + 9846849412579537783U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 12746719939495876158U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 4U)) + 11498066185182895284U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 39U)) + 11101058955193080232U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 15513734459555672046U) + aNonceWordL;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 15711108675349394643U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 12U)) + 4771231759949468556U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11449258010811305256U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17036938391509986723U;
            aOrbiterF = RotL64((aOrbiterF * 7411466953205347639U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6999245666776654250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2106819066263369528U;
            aOrbiterD = RotL64((aOrbiterD * 13005885810757743129U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12716183358903477216U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16752724547046059889U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 11475905692393034141U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17623077680983093163U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 6726003022297274986U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 14709385877103232653U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2842410225096524740U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9235178377537910514U;
            aOrbiterA = RotL64((aOrbiterA * 11813751114775673845U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2619888019860844610U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6295481948199619613U;
            aOrbiterI = RotL64((aOrbiterI * 15429161806953951205U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9724921158061115570U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4070976180958458679U;
            aOrbiterG = RotL64((aOrbiterG * 6080566609081811453U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5864247978960125554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7771249710071026757U;
            aOrbiterE = RotL64((aOrbiterE * 4787660062590737657U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15006900854988166845U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2755659268987119046U;
            aOrbiterJ = RotL64((aOrbiterJ * 8043939381186802359U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 40U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + aNonceWordP) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterA, 18U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_PickleBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x841FEA5B4CF24057ULL + 0xF98A5F7677D0A03BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE32969A9C219FEA9ULL + 0xD661E1DE3D541F97ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEAC0781C318639ADULL + 0x89A614F0121218D0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCD5B5BEFFA501009ULL + 0x9C3B75E7D9B6CA5FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAB66507D4A2EF4B9ULL + 0x888CA848B7027BBDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB87FEB1C11D14499ULL + 0xBD2D39BEB61715FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9586ED093B3386AFULL + 0xB31EEB5A0C517DFAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA21BDE0680A3E225ULL + 0xB1C56D572D49BFD3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x88A4716F6730D795ULL + 0x9027D1557A3956C2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA247051FEFF0C5DFULL + 0xF81879759A221C0DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x80463007E3BE4A33ULL + 0xFD687BFA0822AB8EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8BC1DFB03788826BULL + 0x97DEDDF805B67FB4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE774FB87F901AA71ULL + 0xA36D03E9C23BE762ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8923C4F0DE48983BULL + 0xCD6976CA7FD48A0BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC2E30F23E8E94F9FULL + 0xC8851843E25B76BFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xABD038FC5D449E81ULL + 0xDA8831A79639431FULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aExpandLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aExpandLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4303U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 4847U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 866U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3058U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2960U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2382U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 43U)) ^ (RotL64(aIngress, 56U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 13481227414590594621U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 47U)) + 17425964381118918026U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererK + RotL64(aScatter, 21U)) + 4792004356135956581U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 54U)) + RotL64(aCarry, 23U)) + 11926849936000639098U) + aPhaseHOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 27U)) + 990697329347742142U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 5U)) + 9307721505373076588U) + aNonceWordE;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 17605732738841908719U) + aNonceWordJ;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13110764518634187439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17970109897810645911U;
            aOrbiterI = RotL64((aOrbiterI * 10395095143998920213U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 10273133817644703654U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11239046688920468137U;
            aOrbiterK = RotL64((aOrbiterK * 5197802934333553327U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8355821483275763145U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15522151127786049345U;
            aOrbiterB = RotL64((aOrbiterB * 4844278537850520413U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5381663179722418112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9551368011768104906U;
            aOrbiterC = RotL64((aOrbiterC * 14202470972121732997U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16264476585232221270U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7721417776432288282U;
            aOrbiterJ = RotL64((aOrbiterJ * 10267770327791051869U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 339418090653475277U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3390560045236418590U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3894024951542543635U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10599637790900418767U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 42U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aNonceWordM) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 42U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10385U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneC[((aIndex + 8374U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6278U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 5559U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8403U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6092U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7756U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 35U)) + 12615321415808640429U;
            aOrbiterI = (aWandererH + RotL64(aCross, 43U)) + 15712784676459931207U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 47U)) + 11013335427004930046U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 57U)) + 8298733856304768806U) + aPhaseHOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 6207732959150824216U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 9769864876127544038U) + aNonceWordO;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + 10782181918651152563U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5790454015845620939U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15606578025386733803U;
            aOrbiterA = RotL64((aOrbiterA * 7079287329365566355U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5522352539991175304U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5993355818572869649U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15221467311057431139U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10864534396947622047U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 12090053126235913528U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 7250801471645972261U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14191181677234981396U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2258570108233924592U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 8307541155393855209U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8448114811381534603U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2702389315763499817U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 6710443836432274393U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17202184076718780200U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 150549910056015002U;
            aOrbiterD = RotL64((aOrbiterD * 195034681254956335U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4910512055808124967U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4783477997418403079U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 861977492146512865U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 23U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 14U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15972U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((aIndex + 11613U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 14750U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11734U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((aIndex + 12934U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 41U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 7722279280863371124U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 35U)) + 11584220561732385598U) + aPhaseHOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 7834679350105534657U) + aNonceWordG;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 20U)) + 11347994382444180879U) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 43U)) + 9449903188047063431U) + aNonceWordI;
            aOrbiterG = (aWandererF + RotL64(aScatter, 3U)) + 6516243976652795170U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 8420815253991184777U) + aPhaseHOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9081386852515170937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14375955191735286867U;
            aOrbiterB = RotL64((aOrbiterB * 2772840314542262283U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 880757589768436072U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3349856625725164229U;
            aOrbiterG = RotL64((aOrbiterG * 681514212582331781U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7826309957607577207U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8057435761214313635U;
            aOrbiterD = RotL64((aOrbiterD * 4718430712767038607U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9565237500443303103U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15893066735310588501U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8457633439171452397U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 3276844534476430842U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6828644383891274120U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 979580351653410157U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2815676923011504251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5030251870850928417U;
            aOrbiterI = RotL64((aOrbiterI * 7075653570570819253U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13464083008377887034U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8994560761846897590U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9892839554658865143U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterD, 26U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20136U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 21577U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17498U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16844U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((aIndex + 18277U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 10812151398716051703U;
            aOrbiterE = (aWandererB + RotL64(aCross, 51U)) + 18202551453336003710U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 13U)) + 9434410809101973752U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + 12955829998028534045U) + aNonceWordC;
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 12271740641929640181U) + aPhaseHOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererJ + RotL64(aCross, 60U)) + 14009351527014534752U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 4316296955679133450U) + aNonceWordM;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 16473324966997442872U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15735123324965019802U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5624078184997601019U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 17656375090484080236U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16066325053456055298U;
            aOrbiterJ = RotL64((aOrbiterJ * 17912970706985130327U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12908968778503516903U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12761433987676836197U;
            aOrbiterF = RotL64((aOrbiterF * 1023329467480907925U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12737513138040664509U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14535795767570998392U;
            aOrbiterC = RotL64((aOrbiterC * 15560519667062222269U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14370908061811284364U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 7001358781208669795U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 11641248025734015835U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7298578161120090849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10498302152357484629U;
            aOrbiterD = RotL64((aOrbiterD * 13144110412179037175U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11447343228638006767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18284143620422655675U;
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + aNonceWordD) + aPhaseHWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 12U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26298U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 24382U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 22213U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23484U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23408U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 39U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 15904465836916519864U) + aNonceWordM;
            aOrbiterC = ((aWandererD + RotL64(aCross, 51U)) + 17725629806317789307U) + aNonceWordN;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 38U)) + RotL64(aCarry, 57U)) + 13794170125914914828U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 2149055907476874332U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 27U)) + 5342047776745074649U) + aPhaseHOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 11U)) + 8268148484060546838U) + aNonceWordO;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 10821151364028563719U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4294213820894407378U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10884726101307943090U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1116128870387229159U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16432210042202444824U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15196602644336228055U;
            aOrbiterC = RotL64((aOrbiterC * 12680438355124070237U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14117787670220328165U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 219833877949480215U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10736293047771972173U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3326396981881473962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14918513066311426279U;
            aOrbiterD = RotL64((aOrbiterD * 14269763278564574663U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11795234681370163206U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3068267285352664813U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 15746255933920904619U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 245233356957999496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 709926406353796673U;
            aOrbiterK = RotL64((aOrbiterK * 13627039596842073595U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5378105439430271038U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10114555061122044430U;
            aOrbiterE = RotL64((aOrbiterE * 5351295043424885549U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 4U)) + aOrbiterD) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + aPhaseHWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordE) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28847U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 29589U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 31195U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28567U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 29162U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 58U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 28U)) + 1297415699043177788U) + aPhaseHOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 11U)) + 17583786534509260153U) + aNonceWordL;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 643197858925708798U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 5062653766915694874U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 7034273638367180511U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 21U)) + 2026909726972916996U;
            aOrbiterI = ((((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 2785690475553211646U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2910341716302991892U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2834181605200829791U;
            aOrbiterB = RotL64((aOrbiterB * 1510617068750957651U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 13323052600571281928U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10434901530315760460U;
            aOrbiterD = RotL64((aOrbiterD * 2042210188346767033U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 247903955625194782U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5196515747387257163U;
            aOrbiterI = RotL64((aOrbiterI * 1799024689023272275U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7196305682377987476U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14777739876892587484U;
            aOrbiterG = RotL64((aOrbiterG * 95220583948241581U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10609060796540136671U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8386027207212484155U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4855610536246556893U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 729659744301903424U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2350564261412606157U;
            aOrbiterE = RotL64((aOrbiterE * 16713856782349084977U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16611987556673864177U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aNonceWordG) + aPhaseHWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + aNonceWordF);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterB, 60U));
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_PickleBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
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
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1193U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 2256U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 586U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 522U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 42U)) + 439898681482066326U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 23U)) + 17362083676671776094U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 3U)) + 6418499837265155024U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 11U)) + 17262244253027454972U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 51U)) + 2382066162993139503U) + aPhaseAOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 14345808395587174135U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 57U)) + 7534743166385552851U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 16994453324688523966U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 28U)) + RotL64(aCarry, 3U)) + 7079553728544045092U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3562822704508440641U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13990892681975857821U;
            aOrbiterH = RotL64((aOrbiterH * 8352929306654078795U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1796728922368577238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6605161260520067178U;
            aOrbiterJ = RotL64((aOrbiterJ * 8147537646591674091U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13994083795942328918U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6144523182899107711U;
            aOrbiterD = RotL64((aOrbiterD * 4153879991344611283U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12247462325297436642U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1065809332002012789U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5496601177032953251U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10147919864511540753U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17138553441127273354U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5773875596275267871U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2653924016109573974U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6254416952351699582U;
            aOrbiterE = RotL64((aOrbiterE * 12756861659704947257U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 813046408080197079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9624466135414123483U;
            aOrbiterB = RotL64((aOrbiterB * 6960320253124395015U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 972586705850825744U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 155283774901960223U;
            aOrbiterA = RotL64((aOrbiterA * 9928051687724257041U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18200100644751360406U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1168426822045686004U;
            aOrbiterI = RotL64((aOrbiterI * 5867027156069481313U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH + ((RotL64(aCross, 30U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterC, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 4726U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 5280U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3160U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 3766U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 12311607308490066301U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 56U)) + 13100864684740679846U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 13697304189274329704U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 47U)) + 9047976902871216732U) + aPhaseAOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 3U)) + 2147897579538537888U) + aPhaseAOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 23U)) + 2072444829390996142U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 2129307836981020908U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 19U)) + 10663145333751112064U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 60U)) + 15019844390503785459U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5460865577557928142U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15806522559993224197U;
            aOrbiterG = RotL64((aOrbiterG * 8722932687972240099U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6361113778657833389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8306013884615042570U;
            aOrbiterB = RotL64((aOrbiterB * 8234258702656728667U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4038420580499706912U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11908091484457158973U;
            aOrbiterF = RotL64((aOrbiterF * 3964111175645156719U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11133912466611921250U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2469227904206936928U;
            aOrbiterC = RotL64((aOrbiterC * 2704438771198001599U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13234017916788297295U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9061117693840451988U;
            aOrbiterE = RotL64((aOrbiterE * 3637440416741459419U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12013423690843812324U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14371779015144617412U;
            aOrbiterK = RotL64((aOrbiterK * 3359568073302062667U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10044883414565441442U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14334898081890462218U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4878939077928220019U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13788962593988366125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8377887372059713516U;
            aOrbiterI = RotL64((aOrbiterI * 1925913354197206851U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4584439257847749371U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13335592911357756498U;
            aOrbiterH = RotL64((aOrbiterH * 6515028218115896375U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 50U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 46U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 7011U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7684U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7532U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6437U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6136U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 27U)) + 3199575576585871314U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 2533378188975571824U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + 6819782112558312658U) + aPhaseAOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 18U)) + RotL64(aCarry, 41U)) + 12690060987724798497U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 7088375139715629606U;
            aOrbiterH = (aWandererG + RotL64(aCross, 3U)) + 17785618677423695666U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 41U)) + 1714999280296491277U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 23U)) + 17611338506932491624U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 36U)) + 6475727359297421201U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2347744591204119530U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2739317903351401068U;
            aOrbiterI = RotL64((aOrbiterI * 15435029315209475631U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8663535261373274338U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8205245127823536479U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13857005110466856439U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8916510616749754516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3944805940148512932U;
            aOrbiterH = RotL64((aOrbiterH * 18082271583211389701U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14094751253118853302U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14094299829196076311U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6370012560657108493U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3940673811518673802U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3015106523254484839U;
            aOrbiterK = RotL64((aOrbiterK * 9655401190755573379U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15404103131982599922U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1828655763233900875U;
            aOrbiterB = RotL64((aOrbiterB * 13024358077740310049U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1236981890899916502U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18208975564570342697U;
            aOrbiterA = RotL64((aOrbiterA * 4577109989465876801U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17882273895471449661U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16196010765612713713U;
            aOrbiterC = RotL64((aOrbiterC * 15624856645134182005U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14639250100311162559U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9139027997336903273U;
            aOrbiterG = RotL64((aOrbiterG * 1853126389565574293U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterA, 10U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 36U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 10508U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadB[((aIndex + 8414U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 9327U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 10142U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8935U)) & W_KEY1], 13U) ^ RotL64(aFireLaneB[((aIndex + 8388U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 3U)) + 6973892330986118220U) + aPhaseBOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 21U)) + 9886813896272094864U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 27U)) + 10996306582517553173U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 38U)) + 8490648283899856223U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 105141713530704655U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + 3114337422810562588U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 53U)) + 980857684690886131U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 29U)) + 6562042345807072665U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 15665371138706353619U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18113013571374375028U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17405346422601997299U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11162604605443005253U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5130876096426182506U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1813821672299154629U;
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15793814882743306728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9924458846049579438U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7810034662781768090U;
            aOrbiterF = RotL64((aOrbiterF * 10310594595026622513U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12812586478656872854U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5709576448057435237U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9101555233909853025U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7839807649914541516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4717944526755429647U;
            aOrbiterA = RotL64((aOrbiterA * 8515229146471335721U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3933911971504256022U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4814079680865379831U;
            aOrbiterE = RotL64((aOrbiterE * 15100740696230557391U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18352577312212175569U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9670612998448920742U;
            aOrbiterJ = RotL64((aOrbiterJ * 5743579439303300553U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 72737302703035726U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10032869372369626210U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7449905669249993731U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 41U) + RotL64(aOrbiterB, 10U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 58U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 11648U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 12779U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12165U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 11376U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12212U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12111U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12162U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 8767379393098711499U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 37U)) + 7168159491580816433U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 9879279829061883406U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 47U)) + 10537167136053399303U) + aPhaseBOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 12U)) + 2839070018069188936U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 3U)) + 13844278063968429732U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 11278946626186474646U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 11798425216660557799U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 30U)) + 7618446090703335192U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 695423597006983660U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14344728202803488813U;
            aOrbiterC = RotL64((aOrbiterC * 5168825904902285909U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11656100506575697086U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10384358779985773937U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 247494692039140973U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17585001605131977341U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9964478171465522911U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13484044854790175315U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2710943171829692624U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17809072853457153057U;
            aOrbiterA = RotL64((aOrbiterA * 16341884203303271365U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12814092033910687774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1743186323268668740U;
            aOrbiterF = RotL64((aOrbiterF * 11150822630624332557U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10750472346626754704U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15925901217078035356U;
            aOrbiterJ = RotL64((aOrbiterJ * 9276504171291801637U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2569102106359362359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8868261301410769739U;
            aOrbiterG = RotL64((aOrbiterG * 3662495603133918101U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2143691008373582476U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10606616796243205921U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15794414817813485643U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16258070651850746855U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11720192793689633315U;
            aOrbiterD = RotL64((aOrbiterD * 14475623219460678021U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterD, 56U)) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 52U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterB, 12U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 15799U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15073U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15322U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15013U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13736U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15372U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13939U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 2783898056762489197U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 57U)) + 7177192902873343053U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 42U)) + RotL64(aCarry, 5U)) + 12254703232691980774U) + aPhaseBOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 47U)) + 15446547245691219559U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 888475203006174856U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 3649183529366307877U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 10U)) + 4642631047518805167U;
            aOrbiterF = (aWandererF + RotL64(aCross, 53U)) + 6108329730724782250U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 3U)) + 8334054653023816636U) + aPhaseBOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5891895375031474350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3176720746238477862U;
            aOrbiterJ = RotL64((aOrbiterJ * 1869961473768307911U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6111038696865301675U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11914998302228682704U;
            aOrbiterC = RotL64((aOrbiterC * 11738924766359642853U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17005063057791320948U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18333780598768130670U;
            aOrbiterF = RotL64((aOrbiterF * 5416759844884107303U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2056115016443263153U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10245512728872962677U;
            aOrbiterB = RotL64((aOrbiterB * 707106795383284903U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4810366069422162351U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3051442983125942469U;
            aOrbiterI = RotL64((aOrbiterI * 13558537578054436423U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9285068547223654308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13067251130180968842U;
            aOrbiterG = RotL64((aOrbiterG * 7000687697769766605U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3203670242792002165U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1770881716916463461U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13870229847371882171U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16286823712870537410U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13067191141829694202U;
            aOrbiterD = RotL64((aOrbiterD * 15629974528467350445U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3414576315085336932U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8979691827341555245U;
            aOrbiterH = RotL64((aOrbiterH * 15971594804040295757U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterF, 5U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterD, 36U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterF, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 34U) + aOrbiterJ) + RotL64(aOrbiterC, 28U)) + aPhaseBWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17237U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[((aIndex + 18744U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(mSource[((aIndex + 17668U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17039U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16474U)) & W_KEY1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17167U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 18540U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 30U)) + 9107326720193244489U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 23U)) + 10868585484401664145U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 37U)) + 13637736741437846622U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 6130725216183918844U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 2063834478521338187U;
            aOrbiterK = (aWandererH + RotL64(aCross, 19U)) + 8564870627911949158U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 11U)) + 6524015751064086390U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 9874937766875388236U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 3U)) + 14723718409522680894U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13767059954741528279U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6387608251033722169U;
            aOrbiterC = RotL64((aOrbiterC * 6601902195707980693U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5391425980008431000U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11524218415655093779U;
            aOrbiterF = RotL64((aOrbiterF * 12508457981779189389U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 155510463350385905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10554591788433641311U;
            aOrbiterE = RotL64((aOrbiterE * 5412084824127934293U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8662160162966241542U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5092555636369853727U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 433807340167635499U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7163345798448796101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 695089002178413267U;
            aOrbiterB = RotL64((aOrbiterB * 17302689458565434475U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5409173939213468972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15349690077393827541U;
            aOrbiterG = RotL64((aOrbiterG * 10984681254001609841U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12376011890751302027U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7809614158898158383U;
            aOrbiterK = RotL64((aOrbiterK * 13845113198736843629U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13031938699536449576U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3983178190194056516U;
            aOrbiterA = RotL64((aOrbiterA * 1341678482929213405U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5567935037909671790U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17137042627663349797U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13535586899620672373U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 36U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 52U) + aOrbiterA) + RotL64(aOrbiterE, 58U));
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aPhaseCWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 24U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21440U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 21153U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21323U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((aIndex + 20636U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19857U)) & W_KEY1], 42U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20198U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21427U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 20588U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 47U)) + 14823268998003220191U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 10U)) + 15295237288788213847U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 53U)) + 16434853402001133899U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 5U)) + 7555911304407871631U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 14977248264994834620U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 18U)) + 9707764144919392380U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 1277304385464681529U) + aPhaseCOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 35U)) + 3089786220465849395U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 3700503853358695085U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3240054112993517371U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16897532076915366859U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4120874717534309035U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18167359289798364307U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8870819278575769863U;
            aOrbiterG = RotL64((aOrbiterG * 9334066154398059075U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15363069206212330251U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14858164441499725158U;
            aOrbiterD = RotL64((aOrbiterD * 14931933411393847915U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5357144808788707522U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2910681277417754860U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13170868582159347059U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9824408699018165151U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 368370224788793300U;
            aOrbiterB = RotL64((aOrbiterB * 14358982366258729959U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7095398304588825115U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11418879758164313554U;
            aOrbiterA = RotL64((aOrbiterA * 5983520332639771791U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2171599720681913272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17593730219647495033U;
            aOrbiterI = RotL64((aOrbiterI * 12926053208918563087U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17755947635188715523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14565740605227022106U;
            aOrbiterH = RotL64((aOrbiterH * 15866418354612945335U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14538017880915584414U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6174566474851449123U;
            aOrbiterJ = RotL64((aOrbiterJ * 179569008593475683U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterB, 4U)) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23376U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 23700U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22493U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 24498U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22966U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22389U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22686U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24151U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 53U)) + 6068543441070417854U) + aPhaseCOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aScatter, 18U)) + RotL64(aCarry, 57U)) + 2995980468193441856U) + aPhaseCOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 18020277482171594003U;
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 4293807434721230702U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 7980599111583893156U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 10U)) + 8593141111851052016U;
            aOrbiterE = (aWandererI + RotL64(aCross, 57U)) + 5903487523900084325U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 3U)) + 15112035513447930209U;
            aOrbiterI = (aWandererA + RotL64(aCross, 37U)) + 9854037263057006439U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16759760289688823193U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12622628933030601390U;
            aOrbiterJ = RotL64((aOrbiterJ * 2151912984825538321U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1264668857268123425U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16302812053619101593U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16087995784896123610U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7970269262800468363U;
            aOrbiterF = RotL64((aOrbiterF * 14924752223305807461U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5331477046030959632U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16534913204255550893U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1013433634373673565U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11042821902537871209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8069677512345031660U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13622218526054132397U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5737130058129936372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1076627182956662997U;
            aOrbiterE = RotL64((aOrbiterE * 14342191224014199929U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13911061091801078190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15397603151098990373U;
            aOrbiterA = RotL64((aOrbiterA * 1802890451633592245U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15137326716738637972U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11248737008959896786U;
            aOrbiterB = RotL64((aOrbiterB * 90789374131547005U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1847847987633923657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10560748778679145431U;
            aOrbiterG = RotL64((aOrbiterG * 2919333327817231099U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterE, 42U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterI, 36U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26942U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[((aIndex + 26262U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26193U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24591U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26670U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27214U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25868U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26017U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 14249093584376402677U) + aPhaseDOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 56U)) + 8756965951816492264U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 11221139480258176330U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 17218894445564194851U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 29U)) + 8064642692524949490U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 51U)) + 5822093203710704646U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 21U)) + 3217799620158102238U;
            aOrbiterE = (aWandererK + RotL64(aCross, 10U)) + 2613757677892120843U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 13647481499551657237U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3545714196663685016U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9735422670576621521U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7276207208162697249U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3911046580637583767U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9315984027042049203U;
            aOrbiterC = RotL64((aOrbiterC * 12568550776487242469U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8926367674641729058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11035347490524961446U;
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10748158733051120339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2467801787989056455U;
            aOrbiterB = RotL64((aOrbiterB * 12621934274702358977U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9244415080474351390U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8517784887959492079U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17022899813765884147U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8409307332803038455U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11043806021873232950U;
            aOrbiterH = RotL64((aOrbiterH * 8294888329708842989U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17512395828450251457U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16849067939795823992U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9361991804481514337U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17541946638063238056U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11430501673960586718U;
            aOrbiterF = RotL64((aOrbiterF * 15074409630605450091U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 78307505705383302U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4834528975263832983U;
            aOrbiterE = RotL64((aOrbiterE * 17245673681686752861U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 46U)) + aOrbiterK) + aPhaseDWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterH, 6U));
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27892U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 28876U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29535U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28409U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29387U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28256U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29810U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 28113U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 11U)) + 2101601659597850213U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 53U)) + 2759794072560720121U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 9443562552411269339U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 10801360546699857975U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 8020716394829332019U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 35U)) + 1021894212367773801U) + aPhaseDOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 56U)) + 13346855534622490176U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 27U)) + 16359309548462953836U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 39U)) + 12642446944680783519U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8197424982767553380U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14346334610901859094U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16982899923227935679U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14171304260534233539U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 334531601308283605U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10707856298471572695U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 18364775750091914766U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8531394793118363836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15352876929406908882U;
            aOrbiterC = RotL64((aOrbiterC * 475199047053777179U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 567682016232278157U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2068146551757663119U;
            aOrbiterB = RotL64((aOrbiterB * 1557877740957797555U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7776122587613256525U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16430938890724272256U;
            aOrbiterF = RotL64((aOrbiterF * 4540270493783593257U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11912000645055436094U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16800749242578741498U;
            aOrbiterG = RotL64((aOrbiterG * 17804584625034241737U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5909199180260499150U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5751089915336865588U;
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3478216857728853008U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18007567146937338241U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6620498877303917855U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterD, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 24U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 34U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 30556U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31927U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30425U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30984U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32257U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadB[((aIndex + 30482U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 24U)) + 3917730204724097072U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 57U)) + 1874642340716212824U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 6900165757434854160U;
            aOrbiterH = (aWandererI + RotL64(aCross, 29U)) + 12750946097023807161U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 52U)) + 6563216048479513594U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 14960240191349450795U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 11U)) + 16306180275951788289U) + aPhaseDOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 6502066618271045547U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 41U)) + 6219852857850888738U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2272931312452845850U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3028929882263199463U;
            aOrbiterK = RotL64((aOrbiterK * 11005324285856805069U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6067393030073568112U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10094809900437037258U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18095564940730322769U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5962414178157074575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15755563045799129417U;
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6321455513889880590U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1197435601998121700U;
            aOrbiterI = RotL64((aOrbiterI * 17693996266260557625U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12496949381666299968U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6357070235648527030U;
            aOrbiterG = RotL64((aOrbiterG * 2931486644220862433U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8423760160877540210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8090246492554850768U;
            aOrbiterJ = RotL64((aOrbiterJ * 2949407491181921633U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11436635942985063755U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17086363141014359856U;
            aOrbiterF = RotL64((aOrbiterF * 10504127577318206801U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10734017887545474935U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 375515325165740779U;
            aOrbiterB = RotL64((aOrbiterB * 9980486695448151709U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5217148491945389821U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14696058217023530058U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11026674782236654799U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterK, 48U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererE = aWandererE + ((RotL64(aScatter, 36U) + aOrbiterI) + RotL64(aOrbiterD, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_PickleBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7779U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 3320U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 678U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1058U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1171U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2915U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 11700815697312060726U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 13U)) + 11808423452327465441U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 29U)) + 8670503858631730886U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 2400061067991988544U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 23U)) + 16163118178366229686U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3280178595904941068U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 36U)) + 3298683600817047727U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16321624053445183574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6730229877611375225U;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10162830636713641322U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15646771327759599256U;
            aOrbiterH = RotL64((aOrbiterH * 15333053762177144775U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14841751262270544102U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9545541117228834895U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14676615635857599982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1231768638470558855U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1945905595345404833U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1406171421638586846U;
            aOrbiterE = RotL64((aOrbiterE * 4577864352425476233U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1970292335806697198U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12309719390375013297U;
            aOrbiterK = RotL64((aOrbiterK * 16540660957923687327U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5352135521358954576U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15465675376193501658U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16385761112921041387U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 30U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10847U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 10960U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9631U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11023U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10103U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15649U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15758U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 37U)) + 5171470532667965920U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 6U)) + 750549462358682403U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 3325689257577120525U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 18031575461559790826U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 13U)) + 13874739537012288677U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 4250029868785016865U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 29U)) + 8211158803112611161U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1083939790236786027U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3446525462376962464U;
            aOrbiterD = RotL64((aOrbiterD * 13603702473750888213U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6973817815000417325U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15230876489676945543U;
            aOrbiterC = RotL64((aOrbiterC * 7737039082964537651U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9359727659738755880U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8775170107816327654U;
            aOrbiterF = RotL64((aOrbiterF * 6910680458261008653U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11958941755525038545U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16966819714283167348U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16363457661846050749U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14556087985619763243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17915047508377045221U;
            aOrbiterK = RotL64((aOrbiterK * 6727635453185130109U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8578745677485367222U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7002181668717618866U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12329703532414955235U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3569939503066735457U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2956247934282522184U;
            aOrbiterG = RotL64((aOrbiterG * 9946650822131152531U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 28U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterC, 39U));
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19770U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 17701U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17377U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 22441U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20233U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18096U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24479U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 38U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 27U)) + 17711946802293254150U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 4U)) + 16652362590489569378U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 6972810344198183097U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 13117100889782940546U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 13199305696782626591U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 43U)) + 992156184392760945U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 57U)) + 13791265442074543880U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17057087245252294859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13444195995883541046U;
            aOrbiterE = RotL64((aOrbiterE * 13067044288608808777U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6723678233676059420U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7913379431208430475U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2295062944289127123U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4481887195529300665U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11892724101424384078U;
            aOrbiterA = RotL64((aOrbiterA * 3468639499716604111U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7700902083270424194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1888001433557140271U;
            aOrbiterJ = RotL64((aOrbiterJ * 8975562955027025349U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14996753906788986929U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 939004845422123765U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2507090308972292313U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11922230289291941807U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15681187459741147199U;
            aOrbiterF = RotL64((aOrbiterF * 10124947739653819101U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9119043713532718155U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8327697433992362166U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11157657162184304567U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25846U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 32483U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 28353U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28842U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26063U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26282U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25001U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 58U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 41U)) + 12692813903177772178U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 7112496446691277899U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 53U)) + 2112247138290568813U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 3699421080882855947U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 29U)) + 13761832028354380922U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 9243822514887600214U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 21U)) + 6863833516853046129U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8863897995943098018U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13346785686701467520U;
            aOrbiterF = RotL64((aOrbiterF * 18074843497158380703U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15309543066305531619U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17515530938817919111U;
            aOrbiterH = RotL64((aOrbiterH * 16625193986319048245U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 760493237816424254U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7282586354117620860U;
            aOrbiterC = RotL64((aOrbiterC * 2327153408185290635U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4129706068526969105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7020175432730888755U;
            aOrbiterK = RotL64((aOrbiterK * 10095158356907592239U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9102258982216515596U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10822031305361453690U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2036205056490578491U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12571477440964330246U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8436347026653095199U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17930734781213681573U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14214789872073941940U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12915911919403385001U;
            aOrbiterD = RotL64((aOrbiterD * 13161681603528031511U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterH, 56U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 36U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_PickleBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2620U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((aIndex + 2984U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4424U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1236U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2931U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7909U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 23U)) + 10812151398716051703U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 18202551453336003710U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 19U)) + 9434410809101973752U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 12955829998028534045U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 12271740641929640181U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 30U)) + 14009351527014534752U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 4316296955679133450U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 16473324966997442872U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 27U)) + 15735123324965019802U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 48U)) + 17656375090484080236U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 57U)) + 16066325053456055298U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12908968778503516903U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12761433987676836197U;
            aOrbiterH = RotL64((aOrbiterH * 1023329467480907925U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12737513138040664509U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14535795767570998392U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15560519667062222269U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14370908061811284364U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7001358781208669795U;
            aOrbiterK = RotL64((aOrbiterK * 11641248025734015835U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7298578161120090849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10498302152357484629U;
            aOrbiterI = RotL64((aOrbiterI * 13144110412179037175U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11447343228638006767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18284143620422655675U;
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5918253208127360199U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3910541329178205943U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4550654545328228103U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10357053096941367910U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5610891501128498748U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8676370811772047449U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9049881176058575811U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6307599924966452216U;
            aOrbiterB = RotL64((aOrbiterB * 5551444450572055895U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17109966783467892046U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11563095828344462249U;
            aOrbiterC = RotL64((aOrbiterC * 15463753739272001875U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3739147427725509014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5324449517615050698U;
            aOrbiterJ = RotL64((aOrbiterJ * 5926079615575226853U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5706251076252597592U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10812151398716051703U;
            aOrbiterF = RotL64((aOrbiterF * 5666491216813197045U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterK, 10U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11047U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((aIndex + 13931U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12493U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 9703U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9806U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14076U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13060U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 12222235191147985484U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 11U)) + 16367317014523328414U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 19U)) + 3511378091284703789U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 30U)) + RotL64(aCarry, 23U)) + 15247492830966725949U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 35U)) + 7745995913390407897U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 6463593307540108810U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 21U)) + 1101669311005268630U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 23U)) + 12988052764067518580U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 17717179747434679772U;
            aOrbiterD = (aWandererF + RotL64(aCross, 54U)) + 11662190906682400416U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 5U)) + 6563014073547628748U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13099094932059419219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16342730862261868847U;
            aOrbiterF = RotL64((aOrbiterF * 10988124108686164829U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16855346813127524624U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6570063128502306944U;
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11328352033809240501U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11640986648833160901U;
            aOrbiterK = RotL64((aOrbiterK * 2895830492089678919U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2675226158571501666U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17700531248266458165U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2231403813970188657U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7729597396731910874U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15172374484412053756U;
            aOrbiterD = RotL64((aOrbiterD * 149009041406406517U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9178769489257842683U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9020154972097834926U;
            aOrbiterA = RotL64((aOrbiterA * 8910504667566521429U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1317403761217790562U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17151528554929201571U;
            aOrbiterG = RotL64((aOrbiterG * 3735945655450625203U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11621882033959669977U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10289504450815075623U;
            aOrbiterH = RotL64((aOrbiterH * 13365982786836243195U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16178772981106335703U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16896130772325866910U;
            aOrbiterI = RotL64((aOrbiterI * 6993524735412868965U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9573223644675562575U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17552463713786507189U;
            aOrbiterJ = RotL64((aOrbiterJ * 16103431656424881779U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4801852246698369631U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12222235191147985484U;
            aOrbiterC = RotL64((aOrbiterC * 2835204872125428065U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 12U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 34U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterB, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23813U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 24314U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23797U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 19917U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21290U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21103U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 18866U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 29U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 19U)) + 1297415699043177788U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 17583786534509260153U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 22U)) + 643197858925708798U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 5062653766915694874U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 11U)) + 7034273638367180511U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 57U)) + 2026909726972916996U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 2785690475553211646U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 41U)) + 2910341716302991892U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 29U)) + 2834181605200829791U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 54U)) + 13323052600571281928U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 27U)) + 10434901530315760460U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 247903955625194782U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5196515747387257163U;
            aOrbiterA = RotL64((aOrbiterA * 1799024689023272275U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7196305682377987476U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14777739876892587484U;
            aOrbiterI = RotL64((aOrbiterI * 95220583948241581U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10609060796540136671U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8386027207212484155U;
            aOrbiterG = RotL64((aOrbiterG * 4855610536246556893U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 729659744301903424U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2350564261412606157U;
            aOrbiterC = RotL64((aOrbiterC * 16713856782349084977U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16611987556673864177U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4654808490980989596U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8189569777087686263U;
            aOrbiterF = RotL64((aOrbiterF * 17278657566389299577U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10932857495004451792U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1833880112534916813U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8004341577533825681U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13100236350175516423U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2773759534195186313U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3194954066097323161U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13963126688973399221U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1464529855671190406U;
            aOrbiterD = RotL64((aOrbiterD * 6129954747502059213U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9489842625026216815U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17806120432918490594U;
            aOrbiterJ = RotL64((aOrbiterJ * 349307975773661379U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13833297268854563081U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1297415699043177788U;
            aOrbiterE = RotL64((aOrbiterE * 4818542043777342249U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 46U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 50U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 30U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 14U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27399U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 28225U)) & S_BLOCK1], 22U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 31144U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27541U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27893U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32575U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 24666U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 30U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 18144572925667544139U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 5U)) + 5659758077574059728U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 29U)) + 6343330616999166392U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 51U)) + 17754639838410839447U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 60U)) + 9451843819849581729U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 7957854457197462212U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 21U)) + 1461994799722205010U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 18002214276252170177U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 27U)) + 14689869073147027164U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 13U)) + 3978104368003440293U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 38U)) + 8512135845221335386U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1477533446382953439U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2166717790929947990U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8082437060686606995U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4363687722464700362U;
            aOrbiterB = RotL64((aOrbiterB * 7199165810993478887U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15782763348014924206U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12248271773316742521U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9602078627638561949U;
            aOrbiterE = RotL64((aOrbiterE * 1860631869877427405U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17244849374768558859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1030743048280579012U;
            aOrbiterC = RotL64((aOrbiterC * 10858949914285817051U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17722342363541914280U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15667504059789880034U;
            aOrbiterJ = RotL64((aOrbiterJ * 15872269872168533709U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12645332941998550794U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9938135244509986497U;
            aOrbiterG = RotL64((aOrbiterG * 16548185968987392957U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4024609904162105979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6732064218696157303U;
            aOrbiterK = RotL64((aOrbiterK * 3815409766145891393U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14314117137220703583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15244765904057473814U;
            aOrbiterH = RotL64((aOrbiterH * 4034571710808047959U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17441241682018169245U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11958974379114644873U;
            aOrbiterA = RotL64((aOrbiterA * 11315689206845170303U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8310839846793796473U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18144572925667544139U;
            aOrbiterD = RotL64((aOrbiterD * 11668203295511168011U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 42U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 4U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 60U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 53U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 34U);
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

void TwistExpander_PickleBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4340U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 6896U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5784U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 706U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 722U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 510U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 13U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 17019646486641172469U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 12276141179299971572U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 3617241694029841555U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 42U)) + 6967963401259371737U) + aPhaseGOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 13U)) + 6340709284279891017U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 456065368903896482U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17686765719908116203U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4451942512173336609U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1322045955429785736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5163772703302372887U;
            aOrbiterA = RotL64((aOrbiterA * 3193272189179082313U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13268431135020363252U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6538789950366849332U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5352960308459065837U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10390344544314544893U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5087084271300584267U;
            aOrbiterJ = RotL64((aOrbiterJ * 15149302947570776165U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13423071121590981727U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18324443012024134729U;
            aOrbiterD = RotL64((aOrbiterD * 15814349432207734533U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aPhaseGWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterA, 30U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 12U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12960U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 12174U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13511U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10065U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13472U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11884U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 19U)) + 12535417189990029950U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 6204401443676390273U;
            aOrbiterH = (aWandererI + RotL64(aCross, 42U)) + 869613505613154672U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 15053590879563855802U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 13338989605204591428U) + aPhaseGOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18306470022403825392U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1150696349434090218U;
            aOrbiterH = RotL64((aOrbiterH * 1099447646821052165U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13549541786420596437U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14302878430259588461U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16813606782134305513U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4660437084477165225U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5594199757006711631U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11008472193138708891U;
            aOrbiterJ = RotL64((aOrbiterJ * 13645764762027798301U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3668516817279364310U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 128159531749679984U;
            aOrbiterA = RotL64((aOrbiterA * 4523246859249826987U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterI, 24U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 6U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19394U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 23600U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22110U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20955U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18557U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 20842U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 19U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 16922357079016918108U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 11771749797137599131U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 42U)) + 4635668433708036077U) + aPhaseGOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 15827952719230577008U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + 1495675306110023086U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7294835466949728365U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 179122461212041978U;
            aOrbiterF = RotL64((aOrbiterF * 14467072888722097971U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 545981421632236251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15338259639814630535U;
            aOrbiterH = RotL64((aOrbiterH * 14895421566334357871U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12924313840290895215U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17846785921286020610U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18309347016029917133U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5721472794107057875U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16359630793856870319U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14186771515526698907U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10614102110239037308U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16421992251278236531U;
            aOrbiterI = RotL64((aOrbiterI * 2561232904676068089U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + aPhaseGWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aPhaseGWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29040U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 26070U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32590U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25268U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31935U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 25413U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 36U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 19U)) + 1708250618750199233U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 12009147777553691142U) + aPhaseGOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 8393982703399156592U) + aPhaseGOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 35U)) + 3247327098356831221U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 11U)) + 3403590155376353737U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18197244558104735044U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3096253642040701606U;
            aOrbiterG = RotL64((aOrbiterG * 6656168712438620783U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8012692688785412179U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17531946907545680745U;
            aOrbiterD = RotL64((aOrbiterD * 16510602981731506381U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17687695944270225817U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16147773866007628769U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16926442582711557877U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 18244641303026196497U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8839160526348897457U;
            aOrbiterK = RotL64((aOrbiterK * 14268021129087663397U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10599266240854068246U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2056723540756216155U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 14U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_PickleBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4278U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 3197U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 6207U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6107U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6023U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1270U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 16200278595895089008U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 35U)) + 1029614154810465897U) + aPhaseHOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 7129562468705441295U) + aPhaseHOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 48U)) + RotL64(aCarry, 51U)) + 14388903902433951274U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 57U)) + 1013568949315967455U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3128823373497815651U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14525694606889470589U;
            aOrbiterF = RotL64((aOrbiterF * 12053226114431679195U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14443983602196782887U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12244220415328641190U;
            aOrbiterE = RotL64((aOrbiterE * 15052949098014803181U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10477159225338766614U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2842870123078131566U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11522265477555954071U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8621138818955849917U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5038396344400303181U;
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2768613802894372496U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterK, 40U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15421U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 12193U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9266U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15108U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13496U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15989U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 13481227414590594621U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 17425964381118918026U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 28U)) + RotL64(aCarry, 35U)) + 4792004356135956581U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 41U)) + 11926849936000639098U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 53U)) + 990697329347742142U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9307721505373076588U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17605732738841908719U;
            aOrbiterF = RotL64((aOrbiterF * 13123627214143336281U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13110764518634187439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17970109897810645911U;
            aOrbiterC = RotL64((aOrbiterC * 10395095143998920213U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10273133817644703654U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11239046688920468137U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5197802934333553327U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8355821483275763145U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15522151127786049345U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4844278537850520413U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5381663179722418112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9551368011768104906U;
            aOrbiterH = RotL64((aOrbiterH * 14202470972121732997U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19316U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 20232U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24072U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19358U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24303U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17067U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 6U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 18319689184146942855U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 35U)) + 8041304130090501019U) + aPhaseHOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 11U)) + 11347064191990897738U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 41U)) + 15242243470024447468U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 10619749107163611105U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14795614276221947128U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1578095288886372393U;
            aOrbiterD = RotL64((aOrbiterD * 9953192041564147241U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13593906305770501684U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8919815528334599172U;
            aOrbiterK = RotL64((aOrbiterK * 2033810402808238127U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17425548324720065145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11125018338392347335U;
            aOrbiterJ = RotL64((aOrbiterJ * 4377887040461528587U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3779189180734244399U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10958224663276134041U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6206963519509783781U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4317305352561612995U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4891139433808505355U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11507024985663120317U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 24U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 20U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30349U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 25179U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 30187U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26890U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27435U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 27259U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 12311607308490066301U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 13100864684740679846U) + aPhaseHOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 23U)) + 13697304189274329704U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 9047976902871216732U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 13U)) + 2147897579538537888U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2072444829390996142U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2129307836981020908U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8065769537670939667U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10663145333751112064U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15019844390503785459U;
            aOrbiterB = RotL64((aOrbiterB * 7442321463110790449U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5460865577557928142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15806522559993224197U;
            aOrbiterK = RotL64((aOrbiterK * 8722932687972240099U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6361113778657833389U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8306013884615042570U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8234258702656728667U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4038420580499706912U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11908091484457158973U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3964111175645156719U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererG = aWandererG + ((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterK, 38U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
